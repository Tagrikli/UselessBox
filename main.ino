#include "Servo.h"

Servo servo; // create servo object to control a servo
uint8_t val, pos, size = 11, prevInd = random(size);

int moveBuffer[][35] = {{3, 3, 3, 3, 3, 3, 599, 599, 599, 599, 599, 599, 599, 599, 599, 599, 599, 599, 599, 599, 599, 599, 599, 599, 599, 599, 599, 599, 599, 599, 599, 599, 599, 599, 599},
                        {3, 3, 3, 3, 121, 417, 438, 438, 438, 438, 303, 160, 155, 155, 155, 155, 155, 155, 599, 599, 599, 599, 599, 599, 599, 599, 599, 599, 599, 599, 599, 599, 599, 599, 599},
                        {5, 5, 5, 117, 422, 566, 597, 597, 597, 597, 597, 597, 597, 597, 597, 597, 597, 597, 597, 597, 597, 597, 597, 597, 597, 597, 597, 597, 597, 597, 597, 597, 597, 597, 597},
                        {4, 413, 480, 405, 37, 37, 367, 427, 432, 83, 77, 404, 417, 91, 90, 599, 599, 599, 599, 599, 599, 599, 599, 599, 599, 599, 599, 599, 599, 599, 599, 599, 599, 599, 599},
                        {2, 421, 426, 426, 426, 426, 419, 408, 400, 391, 381, 373, 362, 355, 341, 332, 319, 301, 287, 272, 260, 248, 237, 226, 217, 215, 599, 599, 599, 599, 599, 599, 599, 599, 599},
                        {17, 55, 106, 150, 199, 235, 281, 333, 391, 445, 449, 431, 389, 351, 317, 268, 227, 181, 154, 159, 202, 242, 312, 599, 599, 599, 599, 599, 599, 599, 599, 599, 599, 599, 599},
                        {36, 47, 390, 527, 506, 489, 464, 442, 415, 381, 347, 313, 285, 259, 399, 520, 507, 469, 430, 393, 357, 322, 284, 236, 256, 599, 599, 599, 599, 599, 599, 599, 599, 599, 599},
                        {13, 18, 31, 45, 60, 67, 78, 98, 118, 134, 148, 165, 188, 213, 231, 254, 277, 291, 313, 335, 355, 367, 377, 384, 384, 384, 384, 371, 321, 599, 599, 599, 599, 599, 599},
                        {9, 55, 78, 64, 57, 77, 123, 52, 27, 80, 117, 60, 23, 54, 116, 62, 24, 83, 164, 351, 452, 456, 385, 442, 294, 164, 98, 391, 599, 599, 599, 599, 599, 599, 599},
                        {5, 5, 5, 117, 422, 566, 597, 597, 597, 597, 597, 597, 597, 597, 597, 597, 597, 597, 597, 597, 597, 597, 597, 597, 597, 597, 597, 597, 597, 597, 597, 597, 597, 597, 597},
                        {5, 5, 5, 117, 422, 566, 597, 597, 597, 597, 597, 597, 597, 597, 597, 597, 597, 597, 597, 597, 597, 597, 597, 597, 597, 597, 597, 597, 597, 597, 597, 597, 597, 597, 597}}; 

struct Arm
{
    uint8_t defPos = 170;
    uint8_t initPos = defPos;

    void go(uint8_t val)
    {
        servo.write(val);
        initPos = val;
    }

} arm;

void setup()
{
    servo.attach(10);
    pinMode(11, INPUT);
    Serial.begin(9600);
    arm.go(arm.defPos);
}

void loop()
{
    val = digitalRead(11);

    if (val == HIGH)
    {
        //delay(50);
        uint8_t ind = random(size);
        while (ind == prevInd)
        {
            ind = random(size);
        }
        prevInd = ind;
        ;

        for (int pos : moveBuffer[ind])//ind
        {
            pos = map(pos, 0, 600, 170, 85);
            arm.go(pos);
            delay(150);

            if (digitalRead(11) == LOW)
            {
                arm.go(arm.defPos);
                break;
            }
        }
    }
}