default:
	avr-gcc -mmcu=atmega328 -O2 -o main.o main.c
	avr-objcopy -S -j .text -j .data -O ihex main.o main.hex
	avrdude -p m328 -c dragon_isp -U flash:w:main.hex -B 5 Hz -b 100
clean:
	rm main.o main.hex
