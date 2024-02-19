#include "gd32f4xx_gpio.h"
#include "gd32f4xx_rcu.h"
#include "systick.h"
#include <stdio.h>

/// @brief 初始化串口
/// @ref start.c:Reset_Handler()
/// @note 在SystemInit之后，main之前调用
void SerialInit()
{
    rcu_periph_clock_enable(RCU_GPIOA);

    gpio_af_set(GPIOA, GPIO_AF_7, GPIO_PIN_9);
    gpio_af_set(GPIOA, GPIO_AF_7, GPIO_PIN_10);

    gpio_mode_set(GPIOA, GPIO_MODE_AF, GPIO_PUPD_PULLUP, GPIO_PIN_9);
    gpio_output_options_set(GPIOA, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_9);

    gpio_mode_set(GPIOA, GPIO_MODE_AF, GPIO_PUPD_PULLUP, GPIO_PIN_10);
    gpio_output_options_set(GPIOA, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_10);

    rcu_periph_clock_enable(RCU_USART0);
    usart_deinit(USART0);

    usart_baudrate_set(USART0, 115200U);
    usart_parity_config(USART0, USART_PM_NONE);
    usart_word_length_set(USART0, 8);
    usart_stop_bit_set(USART0, 1);

    usart_receive_config(USART0, USART_RECEIVE_ENABLE);
    usart_transmit_config(USART0, USART_TRANSMIT_ENABLE);
    usart_enable(USART0);
}

/// @brief stdio中的printf，putchar，puts等等一系列stdout/stderr相关的输出回调
/// @param ch 要输出的字符
void _putchar(char ch)
{
    usart_data_transmit(USART0, (uint16_t)ch);
    while (!usart_flag_get(USART0, USART_FLAG_TBE)) {
    }
}

/// @brief scanf，getchar等等底层回调
/// @return 读取到的字符
char _getchar()
{
    while (!usart_flag_get(USART0, USART_FLAG_RBNE)) {
    }
    return (char)usart_data_receive(USART0);
}

int main()
{
    systick_config();
    while (1) {
        delay_1ms(1000);
        printf("GD32F470ZG >> SystemCoreClock: %u\r\n", SystemCoreClock);
    }
    return 0;
}