#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "mytree.h"

/*Função que cria a raiz da arvore*/
NodeTree* create_tree(Point p1, Point p2){
    NodeTree* node = malloc(sizeof(NodeTree));
    NodeList* list =  malloc(sizeof(NodeList));
    list->headList = malloc(sizeof(HeadList));
    strcpy(node->caminho,"0");
    list->headList->tamanho = 0;
    list->headList->primeiro = NULL;
    //raizArvore->caminho = -1;
    node->lista = list;
    node->p1 = p1;
    node->p2 = p2;
    node->NE = NULL;
    node->NO = NULL;
    node->SO = NULL;
    node->SE = NULL;
    return node;
}

/*Função que recebe um nó e verifica se o ponto está dentro dos limites do retangulo
    Retorna 1 caso esteja dentro dos limites
    Retorna 0 caso não esteja dentro dos limites*/
int verificaLimiteRetangulo (NodeTree *node, Point ponto){
    Point p1 = node->p1,p2 = node->p2;
    if ((ponto.x >= p1.x && ponto.x <= p2.x) && (ponto.y >= p1.y && ponto.y <= p2.y)){
        return 1;
    }
    else
        return 0;
}

/* Essa função cria o novo quadrante NE */
void criaFilhoNE (NodeTree *node){

    //Alocação do filho NE
    node->NE = (NodeTree*) malloc(sizeof(NodeTree));

    //Escrevendo coordenadas de divisão do bloco NE
    Point p1 = {.x = (node->p2.x + node->p1.x)/2, .y = (node->p2.y + node->p1.y)/2};
    Point p2 = {.x = (node->p2.x), .y = node->p2.y};
    
    // Criação NE
    NodeTree* nodeNE = create_tree(p1, p2);

    // Apontamento do filho do no atual no lado NE
    node->NE = nodeNE;

    //Pegando o caminho do elemento pai e adicionando ao elemento filho
    char aux[20];

    if(strcmp(node->caminho, "0") != 0){
        strcpy(aux,node->caminho);
    }
    strcat(aux,"00");
    strcpy(node->NE->caminho, aux);


}

/* Essa função cria o novo quadrante NO */
void criaFilhoNO (NodeTree *node){

    //Alocação do filho NO
    node->NO = malloc(sizeof(NodeTree));

    //Escrevendo coordenadas de divisão do bloco NO
    Point p1 = {.x = node->p1.x, .y = (node->p2.y + node->p1.y)/2};
    Point p2 = {.x = (node->p2.x + node->p1.x)/2 , .y = (node->p2.y)};

    //Criação NO
    NodeTree* nodeNO = create_tree(p1, p2);

    //Apontamento do filho do nó atual no lado NO
    node->NO = nodeNO;

   //Pegando o caminho do elemento pai e adicionando ao elemento filho
    char aux[20];
    if(strcmp(node->caminho, "0") != 0){
        strcpy(aux,node->caminho);
    }
    strcat(aux,"01");
    strcpy(node->NO->caminho, aux);




}

/* Essa função cria o novo quadrante SO */
void criaFilhoSO (NodeTree *node){

    //Alocação do filho SO
    node->SO = malloc (sizeof(NodeTree));

    //Escrevendo coordenadas de divisão do bloco SO
    Point p1 = {.x = (node->p1.x), .y = (node->p1.y)};
    Point p2 = {.x = (node->p2.x + node->p1.x) /2, .y = (node->p2.y + node->p1.y) /2};

    //Criação nó SO
    NodeTree* nodeSO = create_tree(p1, p2);

    //Apontamento do filho do nó atual no lado SO
    node->SO = nodeSO;

    //Pegando o caminho do elemento pai e adicionando ao elemento filho
    char aux[20];
    if(strcmp(node->caminho, "0") != 0){
        strcpy(aux,node->caminho);
    }
    strcat(aux,"10");
    strcpy(node->SO->caminho, aux);


}


/* Essa função cria o novo quadrante SE */
void criaFilhoSE (NodeTree *node){

    //Alocação do filho SE
    node->SE =  malloc (sizeof(NodeTree));

    //Escrevendo coordenadas de divisão do bloco SE
    Point p1 = {.x =  (node->p2.x + node->p1.x) / 2, .y=node->p1.y};
    Point p2 = {.x = node->p2.x, .y = (node->p2.y + node->p1.y) / 2};

    //Criação Nó SE
    NodeTree* nodeSE = create_tree(p1, p2);


    //Apontamento do filho do nó atual no lado SE
    node->SE = nodeSE;

    //Pegando o caminho do elemento pai e adicionando ao elemento filho
    char aux[20];
    if(strcmp(node->caminho, "0") != 0){
        strcpy(aux,node->caminho);
    }
    strcat(aux,"11");
    strcpy(node->SE->caminho, aux);

}

/* Função que quebra o nó alvo em quatro filhos*/
void quebraNo (NodeTree *node){
    //Colocando o tamanho da lista pra -1, que indica que o nó já foi quebrado

    node->lista->headList->tamanho = -1; 
    criaFilhoNE(node);
    criaFilhoNO(node);
    criaFilhoSE(node);
    criaFilhoSO(node);

}

/* Essa função deleta uma lista recebendo como parametro um nó*/
void delete_list (NodeList *list){
    NodeList *temp;
    NodeList *cur = list->headList->primeiro;

    while(cur!=NULL){
        temp = cur;
        cur = cur->next;
        free(temp);
    }
    list->headList->primeiro = NULL;
}

/* Essa função deleta uma lista encadeada recebendo uma cabeça de lista como parametro*/
void delList (HeadList *cabeca){
    NodeList *temp;
    NodeList *cur = cabeca->primeiro;

    while(cur!=NULL){
        temp = cur;
        cur = cur->next;
        free(temp);
    }
}
/*Essa funcao retorna em um inteiro qual o quadrante que o ponto pertence 
    1 = pertence ao quadrante NE
    2 = pertence ao quadrante NO
    3 = pertence ao quadrante SO
    4 = pertence ao quadrante SE */
int retornaQuadrante(NodeTree *node, Point p){
    int codigo_quadrante;
    if (verificaLimiteRetangulo(node->SE,p)){
        codigo_quadrante = 4;
    }
    if (verificaLimiteRetangulo(node->SO,p)){
        codigo_quadrante = 3;
    }
    if (verificaLimiteRetangulo(node->NO,p)){
        codigo_quadrante = 2;
    }
    if (verificaLimiteRetangulo(node->NE,p)){
        codigo_quadrante = 1;
    }
    return codigo_quadrante;
}

/* Função que adiciona um ponto a uma lista*/
void adicionaPontoLista (NodeTree *node, Point ponto){
    //Verificando se o primeiro nó é nulo;
    if (node->lista->headList->primeiro == NULL){
        NodeList *new = (NodeList*) malloc (sizeof(NodeList));
        new->p = ponto;
        new->next = NULL;
        node->lista->headList->primeiro = new;
        node->lista->headList->tamanho +=  1;
        return;
    }
    //Caso não for, percorre a lista
    else{
        NodeList *aux;
        for(aux = node->lista->headList->primeiro ; aux != NULL; aux = aux->next){
            //Se esse if for valido, foi encontrado o ultimo nó
            if(aux->next == NULL){
                NodeList *new = (NodeList*) malloc (sizeof(NodeList));
                new->p = ponto;
                new->next = NULL;
                aux->next = new;
                node->lista->headList->tamanho += 1;
                return;
            }
        }
    }
} 
/*Função que distribui os pontos de uma lista prestes a ser quebrada*/ 
void distribuirPontos(NodeTree *node){
    NodeList *aux;
    int escolhaNo;
    for (aux = node->lista->headList->primeiro; aux != NULL ; aux = aux->next){
        escolhaNo = retornaQuadrante(node,aux->p);
        switch (escolhaNo){
            //Caso 1: o ponto é direcionado para a lista do nó NE
            case 1:
                adicionaPontoLista(node->NE,aux->p);
            break;
            //Caso 2: o ponto é direcionado para a lista do nó NO
            case 2:
                adicionaPontoLista(node->NO, aux->p);
            break;
            //Caso 3: o ponto é direcionado para a lista do nó SO
            case 3:
                adicionaPontoLista(node->SO, aux->p);
            break;
            //Caso 4: o ponto é direcionado para a lista do nó SE
            case 4:
                adicionaPontoLista(node->SE,aux->p);
            break;

            default:
                break;
        }    
    }
}
/*Função que adiciona pontos nas listas do nó, caso chegue ao máximo de pontos chama a função
Que quebra o quadrante alvo em 4 quadrantes filhos e separa os elementos da lista em */
void add_tree(NodeTree *node, Point p) {
 
    //Caso entre no primeiro if o nó já foi quebrado, chamando a função retornaQuadrante
    //Para saber qual o nó destino do ponto e chama função add_tree novamente
    if(node->lista->headList->tamanho == -1){

        int escolhaNo = retornaQuadrante(node,p);    
        switch (escolhaNo){
            //Caso 1: O ponto é direcionado para a arvore NE do nó atual
            case 1:
                add_tree(node->NE,p);
            break;

            //Caso 2: O ponto é direcionado para a arvore NO do nó atual
            case 2:
                add_tree(node->NO, p);
            break;

            //Caso 3: O ponto é direcionado para a arvore SO do nó atual
            case 3:
                add_tree(node->SO,p);
            break;
            
            //Caso 4: O ponto é direcionado para a arvore SE do nó atual
            case 4:
                add_tree(node->SE,p);
            break;
            
            default:
                break;
        }
    }
    else if (node->lista->headList->tamanho >= 0 && node->lista->headList->tamanho < 5){

        if(node->lista->headList->tamanho == 4){
            quebraNo(node);
            distribuirPontos(node);
            delete_list(node->lista);
            add_tree(node,p);
        }
        else{
            adicionaPontoLista(node,p);
        }
    }
    
}

//**Essa função percorre a arvore quartenária*/ /*
/*
void percorrerArvore(NodeTree *node){
    if(node->lista->tamanho == -1){
        percorrerArvore(node->NE);
        percorrerArvore(node->NO);
        percorrerArvore(node->SO);
        percorrerArvore(node->SE);
    }
    else {
        //Aqui vai o código de percorrer a lista
        //printList(node);
    }
}*/

//Essa função percorre toda a arvore de forma recursiva e coloca todos os elementos em uma única lista encadeada
void preencheListaArvore(NodeTree *node, NodeList *list){
    if(node->lista->headList->tamanho == -1){
        preencheListaArvore(node->NE,list);
        preencheListaArvore(node->NO,list);
        preencheListaArvore(node->SO,list);
        preencheListaArvore(node->SE,list);
    }
    else{
        NodeList *aux;
        if(node->lista->headList->primeiro == NULL){
            return;
        }
        else{
            for(aux = node->lista->headList->primeiro ; aux != NULL ; aux = aux->next){
                NodeList *new = malloc(sizeof(NodeList));
                new->p = aux->p;
                new->next = list->headList->primeiro;
                list->headList->primeiro = new;
                strcpy(new->caminho,node->caminho);
            }
            return;
        }
    }
}

//Função que procura um ponto na arvore
void find_point(NodeTree *node, Point p){

    NodeList* lista =  malloc(sizeof(NodeList));
    lista->headList = malloc(sizeof(HeadList));
    lista->headList->primeiro = NULL;
    lista->headList->tamanho = 0;
    //Chama a função que preenche a lista
    preencheListaArvore(node,lista);
    NodeList *aux ;
    int achou = 0;
    for(aux = lista->headList->primeiro ; aux != NULL ; aux = aux->next){
        if(aux->p.x == p.x && aux->p.y == p.y){
            printf("(%.2lf , %.2lf):  %s\n", p.x, p.y, aux->caminho);
            return;
        }
        achou = -1;
    }
    if (achou = -1){
        printf("(%.2lf , %.2lf): -1\n", p.x, p.y);
    }

    delete_list(lista);
}



double distance(Point p1, Point p2) {
	int c1 = (p2.x - p1.x) * (p2.x - p1.x);
	int c2 = (p2.y - p1.y) * (p2.y - p1.y);

	return sqrt(c1 + c2);
}


/*Função que procura pontos dentro do raio*/
void find_points_in_circle(NodeTree *node,Point p, double r){

    NodeList *lista;
    lista =  malloc(sizeof(NodeList));
    lista->headList = malloc(sizeof(HeadList));
    lista->headList->primeiro = NULL;
    lista->headList->tamanho = 0;
    //Chama a função que preenche a lista
    preencheListaArvore(node,lista);
    NodeList *aux;
    for (aux = lista->headList->primeiro; aux != NULL ; aux = aux->next){
        if(distance(p,aux->p) <= r){
            printf("(%.2lf,  %.2lf): %.2lf\n", aux->p.x,aux->p.y,distance(p,aux->p));
        }
    }
} 

void print_list(NodeTree *node){
    NodeList *aux;

    //Percorrendo a lista
    
    for (aux = node->lista->headList->primeiro; aux != NULL; aux = aux->next){
        
		printf("%.2lf    %.2lf \n", aux->p.x, aux->p.y);
    }
}