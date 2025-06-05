#include <stdio.h>
#include <stddef.h> //Usado para ter o size_t que é o tipo de sizeof()
#include "cont_ref.h"

//Criando Cabeca da lista
node_ref* head = NULL;

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
    Atribui um endereço a outro endereço
    Decrementa o antigo
    Incrementa o novo
*/
void atrib2(void** dest,void* src){}

//Aloca memoria necessaria, chama add_node para definir o no
void* malloc2(size_t size){
    void* ptr = malloc(size);
    add_node(ptr);
    return ptr;
}

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