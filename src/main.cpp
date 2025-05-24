#include <Arduino.h>
#include "config"
#include "conponent"

void self_test()
{
    servo_tong.TurnMax();
    delay(1000);
    servo_tong.TurnMin();
    delay(1000);

    servo_cleave.TurnMin();
    delay(500);
    servo_cleave.TurnMax();
    delay(500);

    servo_neck.TurnMax();
    delay(500);
    servo_neck.TurnMin();
    delay(500);
}

void setup()
{
    delay(200);
    Serial.begin(9600);
    // motor_l.Forward();
    // motor_r.Forward();
}

void loop()
{
    // self_test();
    
}
