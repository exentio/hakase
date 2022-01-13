BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite
MOUSEKEY_ENABLE = no        # Mouse keys
EXTRAKEY_ENABLE = no        # Audio control and System control
CONSOLE_ENABLE = yes        # Console for debug
COMMAND_ENABLE = yes        # Commands for debug and configuration
NKRO_ENABLE = yes           # Enable N-Key Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
UNICODE_ENABLE   = no       # Unicode
SWAP_HANDS_ENABLE= no       # Allow swapping hands of keyboard
TAP_DANCE_ENABLE = yes

SERIAL_DRIVER = usart
QUANTUM_LIB_SRC += uart.c

DEFAULT_FOLDER = exentio/hakase/boards/bluepill_ld
