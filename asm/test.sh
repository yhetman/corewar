#!/bin/bash
./asm $1
hexdump ../vm_champs/champs/*.cor > asm.out
rm ../vm_champs/champs/*.cor
./assembler $1
hexdump ../vm_champs/champs/*.cor > assembler.out
rm ../vm_champs/champs/*.cor
