OLED_ENABLE = yes
OLED_DRIVER = SSD1306      # Enables the use of OLED displays
ENCODER_ENABLE = yes       # Enables the use of one or more encoders
RGB_MATRIX_ENABLE = no     # Disable keyboard RGB matrix, as it is enabled by default on rev3
RGBLIGHT_ENABLE = yes      # Enable keyboard RGB underglow
UNICODEMAP_ENABLE = yes    # Enable unicode maps
MOUSEKEY_ENABLE = yes      # Enable mouse keys

EXTRAFLAGS += -flto        # Limit Time Optimization shoud save space (?)
CONSOLE_ENABLE = no        # saving space on unused features
COMMAND_ENABLE = no        # saving space on unused features
SPACE_CADET_ENABLE = no    # saving space on unused features
GRAVE_ESC_ENABLE = no      # saving space on unused features
MAGIC_ENABLE = no          # saving space on unused features
