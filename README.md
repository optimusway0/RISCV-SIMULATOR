# RISCV-SIMULATOR
Simulador completo de un procesador con la arquitectura RISC-V en C++ utilizando System_C

## Compilar y Ejecutar
Para ejecutar el Simulador, se debe tener la version 2.3.3 de System_C instalado en el compoutador
Desde el directorio donde se encuentra el archivo main.cpp y el archivo makefile

    make
    make run

Para eliminar los archivos .o

    make clean

## Programa a ejecutar

 - Todas las instrucciones deben estar precedidas por un TAB (`'\t'`)
 - Las etiquetas no deben contener ningun espacio (`' '`) y deben terminar con dos puntos (`':'`)
 - El programa a leer debe tener por nombre `test.txt`
 
 Ejemplo: 

    	add x1, x2, x3
		beq x0, x0, loop
		bne x0, x0, jump
		beq x0, x0, exit
		sub x4, x5, x6
		and x7, x8, x9
		or x0, x0, x0
    loop:
    	xor x0, x0, x0
    	addi x1, x2, 69
    	andi x7, x8, 420
    	ori x0, x0, 24
    	xori x0, x0, 34
    	slti x6, x3, 44
    	add x1, x2, x3
    jump:
    	sub x4, x5, x6
    	lw x10, 4(x3)
    	sw x20, 8(x6)
    exit:

## Integrantes
		

 - a
 - a
 - a
 - Johan Paredes V27507388
