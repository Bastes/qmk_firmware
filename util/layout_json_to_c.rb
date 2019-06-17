#!/usr/bin/env ruby

PLAN =
  [
    [7, [0, 0]],
    [7, [0, 0]],
    [6, [0, 1]],
    [7, [0, 0]],
    [5, [0, 2]],
    [2, [5, 0]],
    [3, [4, 0]],
    [3, [4, 0]]
  ]

COLUMNS_NUMBER =
  PLAN.map(&:first).max

COLUMN_SIZES_TEMPLATE =
  Array.new(COLUMNS_NUMBER, 0)

path = ARGV.first

content = File.read(path)

def column_sizes hand
  hand.inject(COLUMN_SIZES_TEMPLATE) do |sizes, (padding, line)|
    sizes.zip(Array.new(padding) + line).map do |size, key|
      [size, key&.length].compact.max
    end
  end
end

def printable_hand hand, sizes
  hand
    .map do |(padding, line)|
      '  ' +
      [
        sizes
          .take(padding)
          .map { |size| ' ' * (size + 2) }
          .join,
        sizes
          .drop(padding)
          .zip(line)
          .map do |(size, key)|
            next unless key
            key.rjust(size)
          end
          .compact
          .join(', ')
      ].join
    end
    .join(",\n")
end

layouts = content[/"layers":\[\[((".*?")+)\]\]/, 1]
  .split(/\],\[/)
  .map do |layout|
    keys = layout
      .split(/(?<="),(?=")/)
      .map { |key| key[/\A"(.*)"\Z/, 1] }

    left_hand, right_hand, _ = PLAN.inject([[], [], keys]) do |(left, right, remaining), (number, (pad_left, pad_right))|
      [
        left + [[pad_left, remaining.take(number)]],
        right + [[pad_right, remaining.drop(number).take(number)]],
        remaining.drop(number * 2)
      ]
    end
    [
      [column_sizes(left_hand), left_hand],
      [column_sizes(right_hand), right_hand]
    ]
  end

printable_layouts = layouts.map do |((left_sizes, left_hand), (right_sizes, right_hand))|
  %[(\n  // left hand\n#{printable_hand(left_hand, left_sizes)},\n  // right hand\n#{printable_hand(right_hand, right_sizes)}\n)]
end

puts printable_layouts
