#include <Arduino.h>
#include "config"
#include "conponent"
#include "commands"


void setup()
{
    delay(100);
    Serial.begin(9600);
    TRACE("Hello World!");
    delay(1000);
    screen.Init();
}
long cmd;
void loop()
{
    cmd=Serial.parseInt();
    if(cmd)
    {
        commands.TryRun(cmd);
    }
    cmd=0;
}
