STACK_SIZE = DEFINED(STACK_SIZE) ? STACK_SIZE : 0x00000400;
RAM_SIZE = DEFINED(RAM_SIZE) ? RAM_SIZE : 448K;
FLASH_SIZE = DEFINED(FLASH_SIZE) ? FLASH_SIZE : 1M;

ENTRY(Reset_Handler)

MEMORY
{
    /* 根据器件手册定义GDF32F470ZG 片上FLASH大小1M */
    FLASH (rx): ORIGIN = 0x08000000, LENGTH = FLASH_SIZE
    RAM (rwx): ORIGIN = 0x20000000, LENGTH = RAM_SIZE
}

/* 栈顶(向下生长) */
__stack_top__ = ORIGIN(RAM) + LENGTH(RAM);

SECTIONS
{
    .text :
    {
        /* 中断向量表在0x08000000 */
        /* 使用KEEP关键字保证连接器不会将其优化掉 */
        KEEP(*(.isr_vector))
        *(.text*)
        *(.rodata*)
        . = ALIGN(4);
    } >FLASH

    .data : 
    {
        __data_start__ = .;
        *(.data*);
        . = ALIGN(4);
        __data_end__ = .;
    } >RAM AT >FLASH
    __data_load__ = LOADADDR(.data);

    /* 定义未初始化变量区 */
    .bss(NOLOAD) :
    {
        __bss_start__ = .;
        *(.bss*)
        *(COMMON)
        . = ALIGN(4);
        __bss_end__ = .;
    } >RAM

    . = ALIGN(4);

    /* 堆起始 */
    __heap_start__ = .;
    /* 堆结束 */
    __heap_end__ = __stack_top__ - STACK_SIZE;

    /* 栈底 */
    __stack_bottom__ = __heap_end__;
}