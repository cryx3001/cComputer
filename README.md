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
                                       (0xF000 - 0xFFFF video)


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
    - CMP and TST will store their value (1/0) into a flag.
    - Pointers can be used for instructions with *R args, such as MOV and SET. 
      eg: MOV *R0 R1, will copy the content of the memory at address R0 into R1
      The usage of pointers will be ignored for CMP and TST

    R=Register; A=Address; V=Value; L=Label; *=Pointer

    8-bits      16-bits 16-bits
    0xAB        0xABCD  0xABCD

    0x00    NOP                     // Nothing
    0x01    MOV *RA *RA             // Move
    0x02    SET V   *RA             // Set value

    0x10    ADD Rx Ry => Ry=Rx+Ry   // Add
    0x11    SUB Rx Ry => Ry=Ry-Rx   // Subtract
    0x12    MUL Rx Ry => Ry=Ry*Rx   // Multiply
    0x13    DIV Rx Ry => Ry=Ry/Rx   // Divide

    0x20    CMP R  R                // Compare Rx to Ry
    0x21    TST R                   // Test Rx

    0x30    BEQ L                   // Go to label L if equal
    0x31    BNE L                   // Go to label L if not equal
    0x32    BLT L                   // Go to label L if lesser than
    0x33    BGT L                   // Go to label L if bigger than
    0x34    JMP L                   // Go to label L

    0x40    VID                     // Refresh video output

    0xFF    HLT                     // Halt, stop the program

## Usage
- Create a `.casm` file (examples are available in `./examples/`)
- In `./compiler/` run `make` to create the compiler.
- Once the compiler is ready, run `./cryxc path_to_file.casm` to compile the file, a file `out.cout` will be created.
You can also run `./cryxc file.casm output_name` to create instead the file `output_name.cout` in the desired directory.
- Run *Logisim Evolution*, load `./circuits/main.circ` and load the `.cout` file into the ROM.
- Go into the **Simulation** tab to config the simulation and to run it.
- If you want to reset the simulation, you can click on the red button or press `Ctrl-R`.

## The circuits
<details>
    <summary>Main circuit</summary>
    <img src="./circuits/main.png"/>
</details>
<details>
    <summary>Subcircuit is_memaddr</summary>
    <img src="./circuits/is_memaddr.png"/>
</details>
<details>
    <summary>Subcircuit is_pointer</summary>
    <img src="./circuits/is_pointer.png"/>
</details>
<details>
    <summary>Subcircuit get_addr_target</summary>
    <img src="./circuits/get_addr_target.png"/>
</details>
