#pragma once

#include <stdio.h>
#include <stddef.h> //Usado para ter o size_t que é o tipo de sizeof()

typedef struct node_ref{
    void* adress; //Endereço que esse bloco aponta
    node_ref* prev; 
    node_ref* next;
    int cont_references; // Contador de referencias para esse bloco
}node_ref;

//Mostra as alocaçoes feitas por malloc2
void print_nodes();

void atrib2(void** dest,void* src);

void* malloc2(size_t size);