#include <Arduino.h>
#include "config"
#include "conponent"
#include "commands"

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
    delay(100);
    // self_test();
    Serial.begin(9600);
    // motor_l.Forward();
    // motor_r.Forward();
    delay(100);
}
int cmd;
void loop()
{
    cmd=Serial.parseInt();
    if(cmd)
    {
        commands.TryRun(cmd);
    }
    cmd=0;
}
