---
id: cb2bf013-e105-461c-81cf-44dc79b06bab
---
flowchart TD
subgraph Main[HeraCross程序架构]
    subgraph Cfg[配置config]
        DebugCfg[(调试配置)]
        PinCfg[(引脚配置)]
        MotorCfg[(直流电机配置)]
        ServoCfg[(舵机配置)]
        CommandCfg[(命令配置)]
        MiscCfg[(其他配置)]
    end
    subgraph Comp[组件Conponent]
        subgraph Motor[直流电机]
            motor_l((左侧电机))
            motor_r((右侧电机))
        end
        subgraph Servo[舵机]
            servo_tong((钳子))
            servo_cleave((劈刀))
            servo_neck((脖子))
        end
        subgraph Scan[扫描]
            scan((扫码模块))
        end
        subgraph Screen[屏幕]
            screen((OLED显示屏))
        end
    end
    subgraph Commands[命令Commands]
        TryRun([执行器])
        Command[直接控制各组件的Command]
        Act[各种命令的组合Act]
    end
end

Comp --"具体化"--> Cfg
Commands --"控制"-->Comp