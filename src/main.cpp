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
void loop()
{
    auto cmd=Serial.readString();
    if(cmd.length()>0)
        commands.TryRun(cmd);
}
