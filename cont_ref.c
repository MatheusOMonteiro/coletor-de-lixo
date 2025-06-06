#include <stdio.h>
#include <stdlib.h>
#include <stddef.h> //Usado para ter o size_t que é o tipo de sizeof()
#include "cont_ref.h"

//Criando Cabeca da lista
node_ref* head = NULL;

// define informacoes do no e adiciona na lista
void add_node(void* ptr) {
    node_ref* new = (node_ref*) malloc(sizeof(node_ref));

    new->adress = ptr;
    new->count_references = 1;
    new->prev = NULL;
    new->next = head;

    if (head != NULL) {
        head->prev = new;
    }
    head = new;
}

// Interliga os nos anteriores e posteriores, e por fim remove o no
void remove_node(node_ref* node) {
    if (node->prev != NULL) {
        node->prev->next = node->next;
    } else {
        head = node->next;
    }
    if (node->next != NULL) {
        node->next->prev = node->prev;
    }

    free(node->adress);  // Libera a memória alocada
    free(node);            // Libera o nó de rastreamento
}

//Encontra o no que aponta para o endereço recebido
node_ref* search_node(void* ptr) {
    node_ref* node = head;
    while (node != NULL) {
        if (node->adress == ptr) {
            return node;
        }
        node = node->next;
    }
    return NULL;
}
//Mostra as alocaçoes Existentes e suas referencias
void print_nodes(){
    printf("\nReferencias Ativas\n");
    node_ref* node = head;
    while (node != NULL) {
        printf("Endereço: %p | Contagem: %d\n", node->adress, node->count_references);
        node = node->next;
    }
}

/*
    Atribui um endereco a outro endereço
    Decrementa o antigo
    Incrementa o novo
*/
void atrib2_interno(void** dest,void* src){
    // Se o destino j� aponta para algo, decrementa sua refer�ncia
    if (dest && *dest) {
        node_ref* old_node = search_node(*dest);
        if (old_node != NULL) {
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

//Aloca memoria necessaria, chama add_node para definir o no
void* malloc2(size_t size){
    void* ptr = malloc(size);
    add_node(ptr);
    return ptr;
}


