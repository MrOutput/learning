/*
step motor 28byj-48

step	org	ylw	pnk	blu
0		1	0	0	0
1		1	1	0	0
2		0	1	0	0
3		0	1	1	0
4		0	0	1	0
5		0	0	1	1
6		0	0	0	1
7		1	0	0	1

code    num	pin
ORG     0x08 11
YLW     0x04 10
PNK     0x02 9
BLU     0x01 8
*/
#define ORG 0x08
#define STEPS 8
#define WIRES 4

void step(char);

void setup() {
    for (int i = WIRES - 1; i > -1; i--) {
        pinMode(i + ORG, OUTPUT);
    }
}

void loop() {
    char state = ORG;
    char mask = ORG;

    for (int i = 0; i < STEPS; i++) {
        if (i % 2 == 0) {//single wire powered
            state &= mask;
        } else {//two wires powered
            state |= state >> 1;
            mask >>= 1;
        }
        step(state);
    }
}

void step(char s) {
    char mask = ORG;

    for (int i = WIRES - 1; i > -1; i--) {
        digitalWrite(i + ORG, (s & mask) ? HIGH : LOW);
        mask >>= 1;
    }
    delay(2);
}
