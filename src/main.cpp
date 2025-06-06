#include <Arduino.h>
#include "config"
#include "conponent"
#include "commands"


void setup()
{
    delay(100);
    Serial.begin(9600);
    delay(100);
    screen.Init();
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
