---
id: cb2bf013-e105-461c-81cf-44dc79b06bab
---
graph
subgraph Main[HeraCross程序架构]
    subgraph Cfg[配置config]
        subgraph DebugCfg[调试配置]
            IsTrace[是否开启日志]
        end
        subgraph PinCfg[引脚配置]
            subgraph MotorPin
                MotorLN
                MotorLP
                MotorRN
                MotorRP
            end
            subgraph ServoPin
                ServoTongP
                ServoCleaveP
                ServoNeckP
            end
            subgraph ScanPin
                ScanRx
                ScanTx
            end
        end
        subgraph MotorCfg
            MLPulse
            MRPulse
        end
        subgraph ServoCfg
            ServoCount
            subgraph TongCfg
                TongMin
                TongMax
                TongGrab
            end
            subgraph CleaveCfg
                CleaveMin
                CleaveMax
                CleaveClimb
            end
            subgraph NeckCfg
                NeckgMin
                NeckgMax
                NeckgMid
            end
        end
        CommandCfg --> CmdDef
        CommandCfg --> ActDef
        subgraph ColorCfg
            subgraph ColorEnum
                ColorNone
                ColorRed
                ColorGreen
                ColorBlue
            end
            subgraph ColorNames
                ColorNoneName <-->               ColorNone
                ColorRedName <-->                 ColorRed
                ColorGreenName <-->                 ColorGreen
                ColorBlueName <-->                 ColorBlue
            end
            ColorSeqCount
            ColorBufSize
            ColorSampleSize
        end
        subgraph UtilsCfg
            UtilsInfo[详见代码]
        end
    end
    subgraph Comp[组件Conponent]
        subgraph Motor
            subgraph MotorInstance
                motor_l
                motor_r
            end
        end
        subgraph Servo
            subgraph ServoInstance
                servo_tong
                servo_cleave
                servo_neck
            end
        end
        subgraph Scan
            subgraph ScanInstance
                scan
            end
        end
        subgraph Screen
            subgraph ScreenInstance
                screen
            end
        end
    end
    subgraph Command[命令Command&Act]
        subgraph Commands
            subgraph CommandsClass
                CommandsConstruct[构造函数:注册所有Command,Act]
                TryRun[方法:执行命令]
            end
            subgraph CommandsInstance
                commands
            end
        end
        subgraph CmdDef
            CMD_TEST
            CMD_MOTOR_L_F
            CMD_MOTOR_L_B
            CMD_MOTOR_L_HALT
            CMD_MOTOR_R_F
            CMD_MOTOR_R_B
            CMD_MOTOR_R_HALT
            CMD_TONG_OFF
            CMD_TONG_ON
            CMD_NECK_OFF
            CMD_NECK_ON
            CMD_NECK_MID
            CMD_CLEAVE_OFF
            CMD_CLEAVE_ON
            CMD_STEP_F
            CMD_STEP_B
            CMD_STEP_HALT
            CMD_SCAN
            ACT_GRAB
            ACT_CLIMB
            ACT_SAFE_CLEAVE_UP
            ACT_DONT_DIE
        end
    end
end

Comp --"依赖"--> Cfg