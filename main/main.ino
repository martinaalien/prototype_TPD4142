#include "GP2Y0A02YK0F.h"

GP2Y0A02YK0F irSensor0;
GP2Y0A02YK0F irSensor1;
GP2Y0A02YK0F irSensor2;
GP2Y0A02YK0F irSensor3;

void setup() 
{
    Serial.begin(9600);
    irSensor0.begin(A0); // Assign A0 for irSensor0
    irSensor1.begin(A1); // Assign A0 for irSensor1
    irSensor2.begin(A2); // Assign A0 for irSensor2
    irSensor3.begin(A3); // Assign A0 for irSensor3
}

void loop() 
{
    printIR(irSensor0, 0);
    printIR(irSensor1, 1);
    printIR(irSensor2, 2);
    printIR(irSensor3, 3);
    Serial.println();
    delay(1000);
}

/**
 * @brief Prints range from IR sensor
 */
void printIR(GP2Y0A02YK0F sensor, int sensorNumber)
{
    Serial.print("Sensor");
    Serial.print(sensorNumber);
    Serial.print(": ");
    Serial.print(sensor.getDistanceCentimeter());
    Serial.print(" cm");
    Serial.println();
}

/**
 * @brief Calculates the distance using IR sensor
 * 
 * @return distance[cm]
 */

int getDistance(GP2Y0A02YK0F sensor)
{
    return sensor.getDistanceCentimeter();
}