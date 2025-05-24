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
    delay(100);
    self_test();
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
        switch (cmd)
        {
        case CMD_NECK_OFF:
            servo_neck.TurnMin();
            break;
        case CMD_NECK_MID:
            servo_neck.SetAngle(SERVO_NECK_MID);
            break;
        case CMD_NECK_ON:
            servo_neck.TurnMax();
            break;
        case CMD_CLEAVE_OFF:
            servo_cleave.TurnMin();
            break;
        case CMD_CLEAVE_ON:
            servo_cleave.TurnMax();
        case CMD_TONG_OFF:
            servo_tong.TurnMin();
            break;
        case CMD_TONG_ON:
            servo_tong.TurnMax();
            break;

        case CMD_MOTOR_L_F:
            motor_l.Forward();
            break;
        case CMD_MOTOR_L_B:
            motor_l.Backward();
        case CMD_MOTOR_R_F:
            motor_r.Forward();
            break;
        case CMD_MOTOR_R_B:
            motor_r.Backward();
            break;
        case CMD_MOTOR_L_HALT:
            motor_l.Off();
            break;
        case CMD_MOTOR_R_HALT:
            motor_r.Off();
            break;
        case CMD_STEP_HALT:
            motor_l.Off();
            motor_r.Off();
            break;
        case CMD_STEP_F:
            motor_l.Forward();
            motor_r.Forward();
            break;
        case CMD_STEP_B:
            motor_l.Backward();
            motor_r.Backward();
            break;
        default:
            break;
        }
    }
    cmd=0;
}
