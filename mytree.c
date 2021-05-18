#include <stdio.h>
#include <stdlib.h>
#include "mytree.h"

// Função que cria a raiz da arvore
NodeTree* create_tree(Point p1, Point p2){
    NodeTree *raizArvore = (NodeTree*) malloc(sizeof(NodeTree));
    raizArvore->list = NULL;
    raizArvore->p1 = p1;
    raizArvore->p2 = p2;
    return raizArvore;
}

//Função que adiciona pontos nas listas do nó, caso chegue ao máximo de pontos chama a função
//Que quebra a arvore e adiciona novos nós
void add_tree(NodeTree *node, Point ponto) {
    //Verificando se o ponto cabe no retangulo envolvente
    Point p1 = node->p1,p2 = node->p2;
    if ((ponto.x >= p1.x && ponto.x <= p2.x)){
        printf("O ponto está dentro do X");
    }
    //verificando se a lista que o nó da raiz carrega já tem algum elemento
    if (node->list == NULL){
        //Criando o primeiro elemento da lista e adicionando o ponto a ela
        NodeList *primeiroElemento = (NodeList*) malloc (sizeof(NodeList));
        primeiroElemento->p = ponto;
        node->list = primeiroElemento;
    }

    //Caso já tenha algum elemento, percorre a lista até o ultimo elemento
    else{
        NodeList *aux;
        for (aux = node->list; aux != NULL ; aux = aux->next){
            //Verificando se o proximo elemento é NULL (se o atual é o último)
            if (aux->next == NULL){
                //Criando nó da lista e adicionando o ponto a lista
                NodeList *novoNo = (NodeList*) malloc(sizeof(NodeList));
                novoNo->next = NULL;
                novoNo->p = ponto;
                aux->next = novoNo;
                return;
            }
        }
    }
}

void printList(NodeTree *raiz){
    NodeList *aux;

    //Percorrendo a lista
    for (aux = raiz->list; aux != NULL; aux = aux->next){
		printf("%.2lf    %.2lf \n", aux->p.x, aux->p.y);
    }
}