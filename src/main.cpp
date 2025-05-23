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
    delay(1000);
    servo_cleave.TurnMax();
    delay(1000);

    servo_neck.TurnMax();
    delay(1000);
    servo_neck.TurnMin();
    delay(1000);
}

void setup()
{
    delay(200);
}

void loop()
{
    self_test();
}
