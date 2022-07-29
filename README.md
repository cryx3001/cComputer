# cComputer (WIP)
cComputer stands for `Cryx's computer`</br>
This is an attempt to make a very basic CPU with its own assembly language and compiler without any prior important knowledge. This repository is more an experiment that anything else. Therefore it SHOULD NOT be used in any of your projects or even has a relevant example. Logisim Evolution will be used to create the different needed circuits for the CPU.


`16-bits` CPU </br>
`40-bits` Instructions wide

### Display
    64x64 Screen
    256 Colors

### Memory
    Program:            ROM 512   x 40
    General + Video:    RAM 32K   x 16 (0x0000 - 0x0010 reserved)



### Instructions

#### Syntax
    '#1234'  => decimal format
    '#$ABCD' => hexadecimal format
    '#%1011' => binary format

    'xxxx:' => Create a label named xxxx

#### Register codes
    R0: 0x0000 => General purpose
    R1: 0x0001 => General purpose
    R2: 0x0002 => General purpose
    R3: 0x0003 => General purpose
    R4: 0x0004 => Stack pointer

#### Instructions set
    R=Register; A=Address; V=Value; L=Label

    8-bits      16-bits 16-bits
    0xAB        0xABCD  0xABCD

    0x00    NOP
    0x01    MOV RA  RA
    0x02    SET V   RA

    0x10    ADD RA  RA
    0x11    SUB RA  RA
    0x12    MUL RA  RA
    0x13    DIV RA  RA

    0x20    CMP RA  RA
    0x21    TST RA

    0x30    BEQ L
    0x31    BNE L
    0x32    BLT L
    0x33    BGT L
    0x34    JMP L
    0x35    RET


    0x40    PSH RA
    0x41    POP RA
