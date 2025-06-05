#pragma once

#include <stdio.h>
#include <stddef.h> //Usado para ter o size_t que é o tipo de sizeof()

typedef struct memory_block{
    void* adress; //Endereço que esse bloco aponta
    memory_block* prev; 
    memory_block* next;
    int cont_references; // Contador de referencias para esse bloco
}memory_block;

//Mostra as alocaçoes feitas por malloc2
void dump();

void atrib2(void** dest,void* src);

void* malloc2(size_t size);