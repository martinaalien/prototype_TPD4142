#include "GP2Y0A02YK0F.h"
#include "Maxbotix.h"

GP2Y0A02YK0F irSensor;
int distance;

Maxbotix rangeSensorPW(8, Maxbotix::PW, Maxbotix::LV);
#ifdef MAXBOTIX_WITH_SOFTWARE_SERIAL
    Maxbotix rangeSensorTX(6, Maxbotix::TX, Maxbotix::LV);
#endif
Maxbotix rangeSensorAD(A0, Maxbotix::AN, Maxbotix::LV);

void setup() 
{
    Serial.begin(9600);
    irSensor.begin(A1); // Assign A0 as sensor pin
}

void loop() 
{
    printUltrasonic();
    delay(500);
    printIR();
    delay(500);
}

/**
 * @brief Prints range from Ultrasonic sensor
 */
void printUltrasonic()
{
    unsigned long start;

    Serial.println("Reading...");
    start = millis();
    Serial.print("AD: ");
    Serial.print(rangeSensorAD.getRange());
    Serial.print("cm - ");
    Serial.print(millis() - start);
    Serial.println("ms");

    Serial.println();
}

/**
 * @brief Prints range from IR sensor
 */
void printIR()
{
    distance = irSensor.getDistanceCentimeter();
    Serial.print("\nDistance in centimeters: ");
    Serial.print(distance);  
}
