#include <stdint.h>

extern void SystemInit(void);
extern int main(void);

/* linker script exported symbols */
extern uint8_t __stack_top__[];
extern uint8_t __data_start__[];
extern uint8_t __data_end__[];
extern uint8_t __bss_start__[];
extern uint8_t __bss_end__[];
extern uint8_t __heap_start__[];
extern uint8_t __heap_end__[];
extern uint8_t __data_load__[];


void __attribute__((weak)) SerialInit()
{
}

/* Reset Handler */
void Reset_Handler(void)
{
    uint8_t *src = __data_load__;
    uint8_t *dst = __data_start__;

    /* 1. copy .data from FLASH to RAM */
    while (dst < __data_end__) {
        *dst++ = *src++;
    }

    /* 2. zero initialize .bss */
    for (dst = __bss_start__; dst < __bss_end__; ++dst) {
        *dst = 0;
    }

    SystemInit();
    SerialInit();
    (void)main();

    /* main should never return in bare-metal */
    while (1) {
    }
}

void Null_Handler()
{
}

void Loop_Handler()
{
    while (1)
    {
    }
}

void __attribute__((weak, alias("Loop_Handler"))) NMI_Handler(void);        //  NMI Handler
void __attribute__((weak, alias("Loop_Handler"))) HardFault_Handler(void);  //  Hard Fault Handler
void __attribute__((weak, alias("Loop_Handler"))) MemManage_Handler(void);  //  MPU Fault Handler
void __attribute__((weak, alias("Loop_Handler"))) BusFault_Handler(void);   //  Bus Fault Handler
void __attribute__((weak, alias("Loop_Handler"))) UsageFault_Handler(void); //  Usage Fault Handler
void __attribute__((weak, alias("Loop_Handler"))) SVC_Handler(void);        //  SVCall Handler
void __attribute__((weak, alias("Loop_Handler"))) DebugMon_Handler(void);   //  Debug Monitor Handler
void __attribute__((weak, alias("Loop_Handler"))) PendSV_Handler(void);     //  PendSV Handler
void __attribute__((weak, alias("Loop_Handler"))) SysTick_Handler(void);    //  SysTick Handler

/* external interrupts handler */
void __attribute__((weak, alias("Null_Handler"))) WWDGT_IRQHandler(void);                  //  16:Window Watchdog Timer
void __attribute__((weak, alias("Null_Handler"))) LVD_IRQHandler(void);                    //  17:LVD through EXTI Line detect
void __attribute__((weak, alias("Null_Handler"))) TAMPER_STAMP_IRQHandler(void);           //  18:Tamper and TimeStamp through EXTI Line detect
void __attribute__((weak, alias("Null_Handler"))) RTC_WKUP_IRQHandler(void);               //  19:RTC Wakeup through EXTI Line
void __attribute__((weak, alias("Null_Handler"))) FMC_IRQHandler(void);                    //  20:FMC
void __attribute__((weak, alias("Null_Handler"))) RCU_CTC_IRQHandler(void);                //  21:RCU and CTC
void __attribute__((weak, alias("Null_Handler"))) EXTI0_IRQHandler(void);                  //  22:EXTI Line 0
void __attribute__((weak, alias("Null_Handler"))) EXTI1_IRQHandler(void);                  //  23:EXTI Line 1
void __attribute__((weak, alias("Null_Handler"))) EXTI2_IRQHandler(void);                  //  24:EXTI Line 2
void __attribute__((weak, alias("Null_Handler"))) EXTI3_IRQHandler(void);                  //  25:EXTI Line 3
void __attribute__((weak, alias("Null_Handler"))) EXTI4_IRQHandler(void);                  //  26:EXTI Line 4
void __attribute__((weak, alias("Null_Handler"))) DMA0_Channel0_IRQHandler(void);          //  27:DMA0 Channel0
void __attribute__((weak, alias("Null_Handler"))) DMA0_Channel1_IRQHandler(void);          //  28:DMA0 Channel1
void __attribute__((weak, alias("Null_Handler"))) DMA0_Channel2_IRQHandler(void);          //  29:DMA0 Channel2
void __attribute__((weak, alias("Null_Handler"))) DMA0_Channel3_IRQHandler(void);          //  30:DMA0 Channel3
void __attribute__((weak, alias("Null_Handler"))) DMA0_Channel4_IRQHandler(void);          //  31:DMA0 Channel4
void __attribute__((weak, alias("Null_Handler"))) DMA0_Channel5_IRQHandler(void);          //  32:DMA0 Channel5
void __attribute__((weak, alias("Null_Handler"))) DMA0_Channel6_IRQHandler(void);          //  33:DMA0 Channel6
void __attribute__((weak, alias("Null_Handler"))) ADC_IRQHandler(void);                    //  34:ADC
void __attribute__((weak, alias("Null_Handler"))) CAN0_TX_IRQHandler(void);                //  35:CAN0 TX
void __attribute__((weak, alias("Null_Handler"))) CAN0_RX0_IRQHandler(void);               //  36:CAN0 RX0
void __attribute__((weak, alias("Null_Handler"))) CAN0_RX1_IRQHandler(void);               //  37:CAN0 RX1
void __attribute__((weak, alias("Null_Handler"))) CAN0_EWMC_IRQHandler(void);              //  38:CAN0 EWMC
void __attribute__((weak, alias("Null_Handler"))) EXTI5_9_IRQHandler(void);                //  39:EXTI5 to EXTI9
void __attribute__((weak, alias("Null_Handler"))) TIMER0_BRK_TIMER8_IRQHandler(void);      //  40:TIMER0 Break and TIMER8
void __attribute__((weak, alias("Null_Handler"))) TIMER0_UP_TIMER9_IRQHandler(void);       //  41:TIMER0 Update and TIMER9
void __attribute__((weak, alias("Null_Handler"))) TIMER0_TRG_CMT_TIMER10_IRQHandler(void); //  42:TIMER0 Trigger and Commutation and TIMER10
void __attribute__((weak, alias("Null_Handler"))) TIMER0_Channel_IRQHandler(void);         //  43:TIMER0 Capture Compare
void __attribute__((weak, alias("Null_Handler"))) TIMER1_IRQHandler(void);                 //  44:TIMER1
void __attribute__((weak, alias("Null_Handler"))) TIMER2_IRQHandler(void);                 //  45:TIMER2
void __attribute__((weak, alias("Null_Handler"))) TIMER3_IRQHandler(void);                 //  46:TIMER3
void __attribute__((weak, alias("Null_Handler"))) I2C0_EV_IRQHandler(void);                //  47:I2C0 Event
void __attribute__((weak, alias("Null_Handler"))) I2C0_ER_IRQHandler(void);                //  48:I2C0 Error
void __attribute__((weak, alias("Null_Handler"))) I2C1_EV_IRQHandler(void);                //  49:I2C1 Event
void __attribute__((weak, alias("Null_Handler"))) I2C1_ER_IRQHandler(void);                //  50:I2C1 Error
void __attribute__((weak, alias("Null_Handler"))) SPI0_IRQHandler(void);                   //  51:SPI0
void __attribute__((weak, alias("Null_Handler"))) SPI1_IRQHandler(void);                   //  52:SPI1
void __attribute__((weak, alias("Null_Handler"))) USART0_IRQHandler(void);                 //  53:USART0
void __attribute__((weak, alias("Null_Handler"))) USART1_IRQHandler(void);                 //  54:USART1
void __attribute__((weak, alias("Null_Handler"))) USART2_IRQHandler(void);                 //  55:USART2
void __attribute__((weak, alias("Null_Handler"))) EXTI10_15_IRQHandler(void);              //  56:EXTI10 to EXTI15
void __attribute__((weak, alias("Null_Handler"))) RTC_Alarm_IRQHandler(void);              //  57:RTC Alarm
void __attribute__((weak, alias("Null_Handler"))) USBFS_WKUP_IRQHandler(void);             //  58:USBFS Wakeup
void __attribute__((weak, alias("Null_Handler"))) TIMER7_BRK_TIMER11_IRQHandler(void);     //  59:TIMER7 Break and TIMER11
void __attribute__((weak, alias("Null_Handler"))) TIMER7_UP_TIMER12_IRQHandler(void);      //  60:TIMER7 Update and TIMER12
void __attribute__((weak, alias("Null_Handler"))) TIMER7_TRG_CMT_TIMER13_IRQHandler(void); //  61:TIMER7 Trigger and Commutation and TIMER13
void __attribute__((weak, alias("Null_Handler"))) TIMER7_Channel_IRQHandler(void);         //  62:TIMER7 Channel Capture Compare
void __attribute__((weak, alias("Null_Handler"))) DMA0_Channel7_IRQHandler(void);          //  63:DMA0 Channel7
void __attribute__((weak, alias("Null_Handler"))) EXMC_IRQHandler(void);                   //  64:EXMC
void __attribute__((weak, alias("Null_Handler"))) SDIO_IRQHandler(void);                   //  65:SDIO
void __attribute__((weak, alias("Null_Handler"))) TIMER4_IRQHandler(void);                 //  66:TIMER4
void __attribute__((weak, alias("Null_Handler"))) SPI2_IRQHandler(void);                   //  67:SPI2
void __attribute__((weak, alias("Null_Handler"))) UART3_IRQHandler(void);                  //  68:UART3
void __attribute__((weak, alias("Null_Handler"))) UART4_IRQHandler(void);                  //  69:UART4
void __attribute__((weak, alias("Null_Handler"))) TIMER5_DAC_IRQHandler(void);             //  70:TIMER5 and DAC0 DAC1 Underrun error
void __attribute__((weak, alias("Null_Handler"))) TIMER6_IRQHandler(void);                 //  71:TIMER6
void __attribute__((weak, alias("Null_Handler"))) DMA1_Channel0_IRQHandler(void);          //  72:DMA1 Channel0
void __attribute__((weak, alias("Null_Handler"))) DMA1_Channel1_IRQHandler(void);          //  73:DMA1 Channel1
void __attribute__((weak, alias("Null_Handler"))) DMA1_Channel2_IRQHandler(void);          //  74:DMA1 Channel2
void __attribute__((weak, alias("Null_Handler"))) DMA1_Channel3_IRQHandler(void);          //  75:DMA1 Channel3
void __attribute__((weak, alias("Null_Handler"))) DMA1_Channel4_IRQHandler(void);          //  76:DMA1 Channel4
void __attribute__((weak, alias("Null_Handler"))) ENET_IRQHandler(void);                   //  77:Ethernet
void __attribute__((weak, alias("Null_Handler"))) ENET_WKUP_IRQHandler(void);              //  78:Ethernet Wakeup through EXTI Line
void __attribute__((weak, alias("Null_Handler"))) CAN1_TX_IRQHandler(void);                //  79:CAN1 TX
void __attribute__((weak, alias("Null_Handler"))) CAN1_RX0_IRQHandler(void);               //  80:CAN1 RX0
void __attribute__((weak, alias("Null_Handler"))) CAN1_RX1_IRQHandler(void);               //  81:CAN1 RX1
void __attribute__((weak, alias("Null_Handler"))) CAN1_EWMC_IRQHandler(void);              //  82:CAN1 EWMC
void __attribute__((weak, alias("Null_Handler"))) USBFS_IRQHandler(void);                  //  83:USBFS
void __attribute__((weak, alias("Null_Handler"))) DMA1_Channel5_IRQHandler(void);          //  84:DMA1 Channel5
void __attribute__((weak, alias("Null_Handler"))) DMA1_Channel6_IRQHandler(void);          //  85:DMA1 Channel6
void __attribute__((weak, alias("Null_Handler"))) DMA1_Channel7_IRQHandler(void);          //  86:DMA1 Channel7
void __attribute__((weak, alias("Null_Handler"))) USART5_IRQHandler(void);                 //  87:USART5
void __attribute__((weak, alias("Null_Handler"))) I2C2_EV_IRQHandler(void);                //  88:I2C2 Event
void __attribute__((weak, alias("Null_Handler"))) I2C2_ER_IRQHandler(void);                //  89:I2C2 Error
void __attribute__((weak, alias("Null_Handler"))) USBHS_EP1_Out_IRQHandler(void);          //  90:USBHS Endpoint 1 Out
void __attribute__((weak, alias("Null_Handler"))) USBHS_EP1_In_IRQHandler(void);           //  91:USBHS Endpoint 1 in
void __attribute__((weak, alias("Null_Handler"))) USBHS_WKUP_IRQHandler(void);             //  92:USBHS Wakeup through EXTI Line
void __attribute__((weak, alias("Null_Handler"))) USBHS_IRQHandler(void);                  //  93:USBHS
void __attribute__((weak, alias("Null_Handler"))) DCI_IRQHandler(void);                    //  94:DCI
void __attribute__((weak, alias("Null_Handler"))) TRNG_IRQHandler(void);                   //  96:TRNG
void __attribute__((weak, alias("Null_Handler"))) FPU_IRQHandler(void);                    //  97:FPU
void __attribute__((weak, alias("Null_Handler"))) UART6_IRQHandler(void);                  //  98:UART6
void __attribute__((weak, alias("Null_Handler"))) UART7_IRQHandler(void);                  //  99:UART7
void __attribute__((weak, alias("Null_Handler"))) SPI3_IRQHandler(void);                   //  100:SPI3
void __attribute__((weak, alias("Null_Handler"))) SPI4_IRQHandler(void);                   //  101:SPI4
void __attribute__((weak, alias("Null_Handler"))) SPI5_IRQHandler(void);                   //  102:SPI5
void __attribute__((weak, alias("Null_Handler"))) TLI_IRQHandler(void);                    //  104:TLI
void __attribute__((weak, alias("Null_Handler"))) TLI_ER_IRQHandler(void);                 //  105:TLI Error
void __attribute__((weak, alias("Null_Handler"))) IPA_IRQHandler(void);                    //  106:IPA

const uintptr_t __attribute__((used, section(".isr_vector"), aligned(256))) __isr_vector[] = {
    (uintptr_t)__stack_top__,
    (uintptr_t)Reset_Handler,
    (uintptr_t)NMI_Handler,
    (uintptr_t)HardFault_Handler,
    (uintptr_t)MemManage_Handler,
    (uintptr_t)BusFault_Handler,
    (uintptr_t)UsageFault_Handler,
    (uintptr_t)0,
    (uintptr_t)0,
    (uintptr_t)0,
    (uintptr_t)0,
    (uintptr_t)SVC_Handler,
    (uintptr_t)DebugMon_Handler,
    (uintptr_t)0,
    (uintptr_t)PendSV_Handler,
    (uintptr_t)SysTick_Handler,

    /* external interrupts */
    (uintptr_t)WWDGT_IRQHandler,                  /* 16 */
    (uintptr_t)LVD_IRQHandler,                    /* 17 */
    (uintptr_t)TAMPER_STAMP_IRQHandler,           /* 18 */
    (uintptr_t)RTC_WKUP_IRQHandler,               /* 19 */
    (uintptr_t)FMC_IRQHandler,                    /* 20 */
    (uintptr_t)RCU_CTC_IRQHandler,                /* 21 */
    (uintptr_t)EXTI0_IRQHandler,                  /* 22 */
    (uintptr_t)EXTI1_IRQHandler,                  /* 23 */
    (uintptr_t)EXTI2_IRQHandler,                  /* 24 */
    (uintptr_t)EXTI3_IRQHandler,                  /* 25 */
    (uintptr_t)EXTI4_IRQHandler,                  /* 26 */
    (uintptr_t)DMA0_Channel0_IRQHandler,          /* 27 */
    (uintptr_t)DMA0_Channel1_IRQHandler,          /* 28 */
    (uintptr_t)DMA0_Channel2_IRQHandler,          /* 29 */
    (uintptr_t)DMA0_Channel3_IRQHandler,          /* 30 */
    (uintptr_t)DMA0_Channel4_IRQHandler,          /* 31 */
    (uintptr_t)DMA0_Channel5_IRQHandler,          /* 32 */
    (uintptr_t)DMA0_Channel6_IRQHandler,          /* 33 */
    (uintptr_t)ADC_IRQHandler,                    /* 34 */
    (uintptr_t)CAN0_TX_IRQHandler,                /* 35 */
    (uintptr_t)CAN0_RX0_IRQHandler,               /* 36 */
    (uintptr_t)CAN0_RX1_IRQHandler,               /* 37 */
    (uintptr_t)CAN0_EWMC_IRQHandler,              /* 38 */
    (uintptr_t)EXTI5_9_IRQHandler,                /* 39 */
    (uintptr_t)TIMER0_BRK_TIMER8_IRQHandler,      /* 40 */
    (uintptr_t)TIMER0_UP_TIMER9_IRQHandler,       /* 41 */
    (uintptr_t)TIMER0_TRG_CMT_TIMER10_IRQHandler, /* 42 */
    (uintptr_t)TIMER0_Channel_IRQHandler,         /* 43 */
    (uintptr_t)TIMER1_IRQHandler,                 /* 44 */
    (uintptr_t)TIMER2_IRQHandler,                 /* 45 */
    (uintptr_t)TIMER3_IRQHandler,                 /* 46 */
    (uintptr_t)I2C0_EV_IRQHandler,                /* 47 */
    (uintptr_t)I2C0_ER_IRQHandler,                /* 48 */
    (uintptr_t)I2C1_EV_IRQHandler,                /* 49 */
    (uintptr_t)I2C1_ER_IRQHandler,                /* 50 */
    (uintptr_t)SPI0_IRQHandler,                   /* 51 */
    (uintptr_t)SPI1_IRQHandler,                   /* 52 */
    (uintptr_t)USART0_IRQHandler,                 /* 53 */
    (uintptr_t)USART1_IRQHandler,                 /* 54 */
    (uintptr_t)USART2_IRQHandler,                 /* 55 */
    (uintptr_t)EXTI10_15_IRQHandler,              /* 56 */
    (uintptr_t)RTC_Alarm_IRQHandler,              /* 57 */
    (uintptr_t)USBFS_WKUP_IRQHandler,             /* 58 */
    (uintptr_t)TIMER7_BRK_TIMER11_IRQHandler,     /* 59 */
    (uintptr_t)TIMER7_UP_TIMER12_IRQHandler,      /* 60 */
    (uintptr_t)TIMER7_TRG_CMT_TIMER13_IRQHandler, /* 61 */
    (uintptr_t)TIMER7_Channel_IRQHandler,         /* 62 */
    (uintptr_t)DMA0_Channel7_IRQHandler,          /* 63 */
    (uintptr_t)EXMC_IRQHandler,                   /* 64 */
    (uintptr_t)SDIO_IRQHandler,                   /* 65 */
    (uintptr_t)TIMER4_IRQHandler,                 /* 66 */
    (uintptr_t)SPI2_IRQHandler,                   /* 67 */
    (uintptr_t)UART3_IRQHandler,                  /* 68 */
    (uintptr_t)UART4_IRQHandler,                  /* 69 */
    (uintptr_t)TIMER5_DAC_IRQHandler,             /* 70 */
    (uintptr_t)TIMER6_IRQHandler,                 /* 71 */
    (uintptr_t)DMA1_Channel0_IRQHandler,          /* 72 */
    (uintptr_t)DMA1_Channel1_IRQHandler,          /* 73 */
    (uintptr_t)DMA1_Channel2_IRQHandler,          /* 74 */
    (uintptr_t)DMA1_Channel3_IRQHandler,          /* 75 */
    (uintptr_t)DMA1_Channel4_IRQHandler,          /* 76 */
    (uintptr_t)ENET_IRQHandler,                   /* 77 */
    (uintptr_t)ENET_WKUP_IRQHandler,              /* 78 */
    (uintptr_t)CAN1_TX_IRQHandler,                /* 79 */
    (uintptr_t)CAN1_RX0_IRQHandler,               /* 80 */
    (uintptr_t)CAN1_RX1_IRQHandler,               /* 81 */
    (uintptr_t)CAN1_EWMC_IRQHandler,              /* 82 */
    (uintptr_t)USBFS_IRQHandler,                  /* 83 */
    (uintptr_t)DMA1_Channel5_IRQHandler,          /* 84 */
    (uintptr_t)DMA1_Channel6_IRQHandler,          /* 85 */
    (uintptr_t)DMA1_Channel7_IRQHandler,          /* 86 */
    (uintptr_t)USART5_IRQHandler,                 /* 87 */
    (uintptr_t)I2C2_EV_IRQHandler,                /* 88 */
    (uintptr_t)I2C2_ER_IRQHandler,                /* 89 */
    (uintptr_t)USBHS_EP1_Out_IRQHandler,          /* 90 */
    (uintptr_t)USBHS_EP1_In_IRQHandler,           /* 91 */
    (uintptr_t)USBHS_WKUP_IRQHandler,             /* 92 */
    (uintptr_t)USBHS_IRQHandler,                  /* 93 */
    (uintptr_t)DCI_IRQHandler,                    /* 94 */
    (uintptr_t)0,                                 /* 95 Reserved */
    (uintptr_t)TRNG_IRQHandler,                   /* 96 */
    (uintptr_t)FPU_IRQHandler,                    /* 97 */
    (uintptr_t)UART6_IRQHandler,                  /* 98 */
    (uintptr_t)UART7_IRQHandler,                  /* 99 */
    (uintptr_t)SPI3_IRQHandler,                   /* 100 */
    (uintptr_t)SPI4_IRQHandler,                   /* 101 */
    (uintptr_t)SPI5_IRQHandler,                   /* 102 */
    (uintptr_t)0,                                 /* 103 Reserved */
    (uintptr_t)TLI_IRQHandler,                    /* 104 */
    (uintptr_t)TLI_ER_IRQHandler,                 /* 105 */
    (uintptr_t)IPA_IRQHandler                     /* 106 */
};