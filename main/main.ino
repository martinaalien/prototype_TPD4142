#include "Maxbotix.h"

Maxbotix rangeSensorAD0(A0, Maxbotix::AN, Maxbotix::LV);
Maxbotix rangeSensorAD1(A1, Maxbotix::AN, Maxbotix::LV);
Maxbotix rangeSensorAD2(A2, Maxbotix::AN, Maxbotix::LV);
Maxbotix rangeSensorAD3(A3, Maxbotix::AN, Maxbotix::LV);

void setup() 
{
    Serial.begin(9600);
}

void loop() 
{
    printUltrasonic(rangeSensorAD0, 0);
    printUltrasonic(rangeSensorAD1, 1);
    printUltrasonic(rangeSensorAD2, 2);
    printUltrasonic(rangeSensorAD3, 3);
    delay(500);
}

/**
 * @brief Prints range from Ultrasonic sensor
 */
void printUltrasonic(Maxbotix sensor, int sensorNumber)
{
    unsigned long start;

    Serial.println("Reading...");
    start = millis();
    Serial.print("Sensor");
    Serial.print(sensorNumber);
    Serial.print(": ");
    Serial.print(sensor.getRange());
    Serial.print("cm - ");
    Serial.print(millis() - start);
    Serial.println("ms");

    Serial.println();
}


/**
 * @brief Reads distance from sensor
 * 
 * @return distance[Float]
 */
float getDistance(Maxbotix sensor)
{
    return sensor.getRange();
}
