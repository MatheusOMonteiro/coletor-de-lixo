#include <stdio.h>
#include <stddef.h> //Usado para ter o size_t que é o tipo de sizeof()
#include "cont_ref.h"

node_ref* head = NULL;

//Mostra as alocaçoes Existentes e suas referencias
void print_nodes(){
    printf("\nReferencias Ativas\n");
    node_ref* node = head;
    while (node != NULL) {
        printf("Endereço: %p | Contagem: %d\n", node->adress, node->cont_references);
        node = node->next;
    }
}

/*
    Atribui um endereço a outro endereço
    Decrementa o antigo
    Incrementa o novo
*/
void atrib2(void** dest,void* src){}

void* malloc2(size_t size){}

node_ref* add_node(){}

node_ref* remove_node(){}