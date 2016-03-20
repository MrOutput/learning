#define TEMP_PIN A0
#define POWER 4.78
#define ADC_MAX 1024

#define G_LED 2
#define R_LED 4

#define SAFE_RANGE(n) ((n) <= 75) ? 1 : 0

void setup()
{
    Serial.begin(9600);
    pinMode(G_LED, OUTPUT);
    pinMode(R_LED, OUTPUT);
}


void loop()
{
    unsigned int temp_a0 = analogRead(TEMP_PIN);
    float temp_mv = temp_a0 * (POWER*1000 / ADC_MAX);
    float c_temp = temp_mv / 10;
    float f_temp = c_temp * 1.8 + 32;

    unsigned char isSafe = (SAFE_RANGE(f_temp));
    digitalWrite(G_LED, (isSafe) ? HIGH : LOW);
    digitalWrite(R_LED, (!isSafe) ? HIGH : LOW);

    Serial.println(f_temp);
    delay(500);
}
