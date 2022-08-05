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
    General + Video:    RAM 64K   x 16 (0x0000 - 0x0020 reserved)


### Instructions

#### Syntax
    '#1234'  => decimal format
    '#$ABCD' => hexadecimal format
    '#%1011' => binary format

    'xxxx:' => Create a label named xxxx

#### Register codes
    R0: 0x0000 => Operand 1
    R1: 0x0001 => Operand 2
    R2: 0x0002 => Result
    R3: 0x0003 => General purpose
    R4: 0x0004 => General purpose
    R5: 0x0004 => General purpose
    R6: 0x0004 => General purpose
    R7: 0x0005 => General purpose

#### Instructions set
    - Instructions of type "INST RA RA" should be readen as INST SRC DEST
    - If a '=>' is visible, it means that the value will be stored into the
      concerned register.
    - Tokens between () are implicit and must not be written in .casm files.
    - CMP and TST will store their value (1/0) into a flag.
    - Pointers can be used for instructions with *R args, such as MOV and SET. 
      eg: MOV *R0 R1, will copy the content of the memory at address R0 into R1
      The usage of pointers will be ignored for CMP and TST

    R=Register; A=Address; V=Value; L=Label; *=Pointer

    8-bits      16-bits 16-bits
    0xAB        0xABCD  0xABCD

    0x00    NOP
    0x01    MOV *RA *RA
    0x02    SET V   *RA

    0x10    ADD (R0)(R1) => (R2)
    0x11    SUB (R0)(R1) => (R2)
    0x12    MUL (R0)(R1) => (R2)
    0x13    DIV (R0)(R1) => (R2)

    0x20    CMP R  R 
    0x21    TST R

    0x30    BEQ L
    0x31    BNE L
    0x32    BLT L
    0x33    BGT L
    0x34    JMP L

## Usage
- Create a .casm file (examples are available in `./examples/`)
- In `./compiler/` run `make` to create the compiler.
- Once the compiler is ready, run `./cryxc path_to_file.casm` to compile the file, a file `out.cout` will be created.
You can also run `./cryxc file.casm output_name` to create instead the file `output_name.cout` in the desired directory.
- Run Logisim Evolution, load `./circuits/main.circ` and load the `.cout` file into the ROM.
- Go into the simulation tab to config the simulation and to run it.
- If you want to reset the simulation, you can click on the red button or press `Ctrl-R`.

