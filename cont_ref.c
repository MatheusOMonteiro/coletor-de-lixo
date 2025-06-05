#include <stdio.h>
#include <stddef.h> //Usado para ter o size_t que é o tipo de sizeof()
#include "cont_ref.h"

node_ref* head = NULL;

//Mostra as alocaçoes Existentes e suas referencias
void print_nodes(){
    printf("\nReferencias Ativas\n");
    node_ref* node = head;
    while (node != NULL) {
        printf("Endereco: %p | Contagem: %d\n", node->adress, node->cont_references);
        node = node->next;
    }
}

/*
    Atribui um endereco a outro endereço
    Decrementa o antigo
    Incrementa o novo
*/
void atrib2(void** dest,void* src){
    // Se o destino j� aponta para algo, decrementa sua refer�ncia
    if (dest && *dest) {
        node_ref* old_node = search_node(*dest);
        if (old-node != NULL) {
            old_node->count_references--;
            if (old_node->count_references == 0) {
                remove_node(old_node);
            }
        }
    }

    // Atribui o novo valor
    *dest = src;

    // Incrementa a refer�ncia do novo ponteiro, se existir
    if (src) {
        node_ref* new_node = search_node(src);
        if (new_node != NULL) {
            new_node->count_references++;
        }
    }
}

void* malloc2(size_t size){}

node_ref* add_node(){}

node_ref* remove_node(){}




