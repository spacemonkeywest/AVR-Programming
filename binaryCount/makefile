# MCU & Programmer
MCU = atmega328p
PROGRAMMER = arduino
PORT = /dev/cu.usbmodem101  # Change this to your actual port
BAUD = 115200

# Compiler & Flags
CC = avr-gcc
OBJCOPY = avr-objcopy
CFLAGS = -mmcu=$(MCU) -Wall -Os -DF_CPU=1000000UL

# Files
TARGET = count
SRC = $(TARGET).c
HEX = $(TARGET).hex
ELF = $(TARGET).elf

# Compile
all: $(HEX)

$(ELF): $(SRC)
	$(CC) $(CFLAGS) -o $(ELF) $(SRC)

$(HEX): $(ELF)
	$(OBJCOPY) -O ihex $(ELF) $(HEX)

# Upload using avrdude
upload: $(HEX)
	avrdude -c $(PROGRAMMER) -p $(MCU) -P $(PORT) -b $(BAUD) -U flash:w:$(HEX):i

# Clean files
clean:
	rm -f $(ELF) $(HEX)
