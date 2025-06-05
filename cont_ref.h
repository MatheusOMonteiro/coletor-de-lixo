#pragma once

#include <stdio.h>
#include <stddef.h> //Usado para ter o size_t que é o tipo de sizeof()

//Macro usada para corrigir assinatura de funcao e tornar mais facil a usabilidade do usuario
#define atrib2(dest, src) atrib2_interno((void**)&(dest), (void*)(src)) 

typedef struct node_ref{
    void* adress; //Endereço que esse bloco aponta
    struct node_ref* prev; 
    struct node_ref* next;
    int count_references; // Contador de referencias para esse bloco
}node_ref;

//Mostra as alocaçoes feitas por malloc2
void print_nodes();

void atrib2_interno(void** dest,void* src);

void* malloc2(size_t size);