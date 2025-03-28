# 🔹 MCU SETTINGS
MCU = atmega328p         # Target microcontroller (ATmega328P used in Arduino Uno)
F_CPU = 16000000UL       # CPU frequency (16MHz for Arduino Uno, 8MHz for internal RC oscillator)

# 🔹 FILE NAMES
TARGET = main            # Name of the program (without file extension)
SRC = $(TARGET).c        # Source file
HEX = $(TARGET).hex      # Output HEX file (flashed to the microcontroller)
ELF = $(TARGET).elf      # Intermediate ELF file (compiled binary)

# 🔹 COMPILER SETTINGS
CC = avr-gcc             # AVR GCC Compiler
OBJCOPY = avr-objcopy    # Converts ELF to HEX
CFLAGS = -mmcu=$(MCU) -Wall -Os -DF_CPU=$(F_CPU)

# 🔹 PROGRAMMER SETTINGS
PROGRAMMER = arduino        # Arduino bootloader-based programming
PORT = /dev/cu.usbmodemXXXX # Serial port (Change this to match your Arduino)
BAUD = 115200               # Baud rate for serial communication

# 🔹 COMPILATION PROCESS
all: $(HEX)

# Step 1: Compile C source code to ELF binary
$(ELF): $(SRC)
	$(CC) $(CFLAGS) -o $(ELF) $(SRC)

# Step 2: Convert ELF binary to HEX format for flashing
$(HEX): $(ELF)
	$(OBJCOPY) -O ihex $(ELF) $(HEX)

# 🔹 UPLOAD CODE TO MICROCONTROLLER
upload: $(HEX)
	avrdude -c $(PROGRAMMER) -p $(MCU) -P $(PORT) -b $(BAUD) -U flash:w:$(HEX):i

# 🔹 CLEAN UP GENERATED FILES
clean:
	rm -f $(ELF) $(HEX)

