# MCU name
MCU = STM32F103
BOOTLOADER = stm32duino

EXTRAFLAGS += -flto

# Enter lower-power sleep mode when on the ChibiOS idle thread
OPT_DEFS += -DCORTEX_ENABLE_WFI_IDLE=TRUE

# Flash too small for virtual EEPROM
EEPROM_DRIVER = transient
