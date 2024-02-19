STACK_SIZE = DEFINED(STACK_SIZE) ? STACK_SIZE : 0x00000400;

ENTRY(Reset_Handler)

MEMORY
{
    /* 根据器件手册定义GDF32F470ZG 片上FLASH大小1M */
    FLASH (rx): ORIGIN = 0x08000000, LENGTH = 1M
    RAM (rwx): ORIGIN = 0x20000000, LENGTH = 448K
}

SECTIONS
{
    .text :
    {
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
    _rdata = LOADADDR(.data);

    /* 定义未初始化变量区 */
    .bss(NOLOAD) :
    {
        __bss_start__ = .;
        *(.bss*)
        *(COMMON)
        . = ALIGN(4);
        __bss_end__ = .;
    } >RAM

    /* 定义栈空间 */
    .stack(NOLOAD) :
    {
        __stack_start__ = .;
        . = ALIGN(8);
        . = . + STACK_SIZE;
        . = ALIGN(8);
        __stack_end__ = .;
    } >RAM

    /* 堆结束地址 */
    __heap_end__ = ORIGIN(RAM) + LENGTH(RAM);
}