#define ORG 0x8
#define YLW 0x4
#define PNK 0x2
#define BLU 0x1

void step(char);

void setup() {
    for (char pin = 11; pin > 7; pin--) {
        pinMode(pin, OUTPUT);
    }
}

void loop() {
    char state = ORG;
    char mask = ORG;

    for (int i = 0; i < 8; i++) {
        if (i % 2 == 0) {//single bit
            state &= mask;
        } else {//two bits
            state |= state >> 1;
            mask >>= 1;
        }
        step(state);
    }
}

void step(char s) {
    char offset = 8;
    char mask = ORG;

    for (int i = 0; i < 4; i++) {
        digitalWrite(i + offset, (s & mask) ? HIGH : LOW);
        mask >>= 1;
    }
    delay(2);
}
