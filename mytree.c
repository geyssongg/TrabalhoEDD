#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "mytree.h"

/*Função que cria a raiz da arvore*/
NodeTree* create_tree(Point p1, Point p2){
    NodeTree *raizArvore = (NodeTree*) malloc(sizeof(NodeTree));
    HeadList *cabecaLista = (HeadList*) malloc(sizeof(HeadList));
    cabecaLista->tamanho = 0;
    cabecaLista->primeiro = NULL;
    //raizArvore->caminho = -1;
    raizArvore->lista = cabecaLista;
    raizArvore->p1 = p1;
    raizArvore->p2 = p2;
    return raizArvore;
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
    node->NE->p1.x = (node->p2.x + node->p1.x)/2;
    node->NE->p1.y = (node->p2.y + node->p1.y)/2;
    node->NE->p2.x = (node->p2.x);
    node->NE->p2.y = (node->p2.y);
    //Apontando a lista de pontos de NE para NULL
    node->NE->lista = (HeadList*) malloc(sizeof(HeadList));
    node->NE->lista->primeiro = NULL;
    //Tamanho da lista é 0
    node->NE->lista->tamanho = 0;
    //Apontando os filhos de NE para NULL
    node->NE->NE = NULL;
    node->NE->NO = NULL;
    node->NE->SE = NULL;
    node->NE->SO = NULL;
}

/* Essa função cria o novo quadrante NO */
void criaFilhoNO (NodeTree *node){
    //Alocação do filho NO
    node->NO = (NodeTree*) malloc(sizeof(NodeTree));
    //Escrevendo coordenadas de divisão do bloco NO
    node->NO->p1.x = node->p1.x;
    node->NO->p1.y = (node->p2.y + node->p1.y)/2;
    node->NO->p2.x = (node->p2.x + node->p1.x)/2;
    node->NO->p2.y = (node->p2.y);
    //Apontando a lista de pontos de NE para NULL
    node->NO->lista = (HeadList*) malloc(sizeof(HeadList));
    node->NO->lista->primeiro = NULL;
    //Tamanho da lista agora é 0
    node->NO->lista->tamanho = 0;
    //Apontando os filhos de NE para NULL
    node->NO->NE = NULL;
    node->NO->NO = NULL;
    node->NO->SE = NULL;
    node->NO->SO = NULL;
}

/* Essa função cria o novo quadrante SO */
void criaFilhoSO (NodeTree *node){
    //Alocação do filho SO
    node->SO = (NodeTree*) malloc (sizeof(NodeTree));
    node->SO->p1.x = node->p1.x;
    node->SO->p1.y = node->p1.y;
    node->SO->p2.x = (node->p2.x + node->p1.x) / 2;
    node->SO->p2.y = (node->p2.y + node->p1.y) / 2;
    //Apontando a lista de pontos de NE para NULL
    node->SO->lista = (HeadList*) malloc(sizeof(HeadList));
    node->SO->lista->primeiro = NULL;
     //Tamanho da lista agora é 0
    node->NO->lista->tamanho = 0;
    //Apontando os filhos de NE para NULL
    node->SO->NE = NULL;
    node->SO->NO = NULL;
    node->SO->SE = NULL;
    node->SO->SO = NULL;
}


/* Essa função cria o novo quadrante SE */
void criaFilhoSE (NodeTree *node){
    //Alocação do filho SE
    node->SE = (NodeTree*) malloc (sizeof(NodeTree));
    node->SE->p1.x = (node->p2.x + node->p1.x) / 2;
    node->SE->p1.y = node->p1.y;
    node->SE->p2.x = node->p2.x;
    node->SE->p2.y = (node->p2.y + node->p1.y) / 2;
    //Apontando a lista de pontos de NE para NULL
    node->SE->lista = (HeadList*) malloc(sizeof(HeadList));
    node->SE->lista->primeiro = NULL;
     //Tamanho da lista agora é 0
    node->SE->lista->tamanho = 0;
    //Apontando os filhos de NE para NULL
    node->SE->NE = NULL;
    node->SE->NO = NULL;
    node->SE->SE = NULL;
    node->SE->SO = NULL;
}

/* Função que quebra o nó alvo em quatro filhos*/
void quebraNo (NodeTree *node){
    //Colocando o tamanho da lista pra -1, que indica que o nó já foi quebrado
    node->lista->tamanho = -1; 
    criaFilhoNE(node);
    criaFilhoNO(node);
    criaFilhoSE(node);
    criaFilhoSO(node);
}

/* Essa função deleta uma lista recebendo como parametro um nó*/
void deletaLista (NodeTree *node){
    NodeList *temp;
    NodeList *cur = node->lista->primeiro;

    while(cur!=NULL){
        temp = cur;
        cur = cur->next;
        free(temp);
    }
    node->lista->primeiro = NULL;
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
    if (verificaLimiteRetangulo(node->NE,p)){
        return 1;
    }
    else if (verificaLimiteRetangulo(node->NO,p)){
        return 2;
    }
    else if (verificaLimiteRetangulo(node->SO,p)){
        return 3;
    }
    else if (verificaLimiteRetangulo(node->SE,p)){
        return 4;
    }
}

/* Função que adiciona um ponto a uma lista*/
void adicionaPontoLista (NodeTree *node, Point ponto){
    //Verificando se o primeiro nó é nulo;
    if (node->lista->primeiro == NULL){
        NodeList *new = (NodeList*) malloc (sizeof(NodeList));
        new->p = ponto;
        new->next = NULL;
        node->lista->primeiro = new;
        node->lista->tamanho = node->lista->tamanho + 1;
        return;
    }
    //Caso não for, percorre a lista
    else{
        NodeList *aux;
        for(aux = node->lista->primeiro ; aux != NULL; aux = aux->next){
            //Se esse if for valido, foi encontrado o ultimo nó
            if(aux->next == NULL){
                NodeList *new = (NodeList*) malloc (sizeof(NodeList));
                new->p = ponto;
                new->next = NULL;
                aux->next = new;
                node->lista->tamanho = node->lista->tamanho + 1;
                return;
            }
        }
    }
} 
/*Função que distribui os pontos de uma lista prestes a ser quebrada*/ 
void distribuirPontos(NodeTree *node){
    NodeList *aux;
    int escolhaNo;
    for (aux = node->lista->primeiro; aux != NULL ; aux = aux->next){
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
    if(node->lista->tamanho == -1){
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
    else if (node->lista->tamanho >= 0 && node->lista->tamanho < 5){
        if(node->lista->tamanho == 4){
            quebraNo(node);
            distribuirPontos(node);
            deletaLista(node);
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
void preencheListaArvore(NodeTree *node, HeadList *head){
    if(node->lista->tamanho == -1){
        preencheListaArvore(node->NE,head);
        preencheListaArvore(node->NO,head);
        preencheListaArvore(node->SO,head);
        preencheListaArvore(node->SE,head);
    }
    else{
        NodeList *aux;
        if(node->lista->primeiro == NULL){
            return;
        }
        else{
            for(aux = node->lista->primeiro ; aux != NULL ; aux = aux->next){
                NodeList *new = (NodeList*) malloc(sizeof(NodeList));
                new->p = aux->p;
                new->next = head->primeiro;
                head->primeiro = new;
            }
            return;
        }
    }
}

//Função auxiliar a função find_point (cria uma lista com todos os pontos da arvore)
void find_point_aux (NodeTree *node,Point p){
    HeadList *lista;
    lista = (HeadList*) malloc(sizeof(HeadList));
    lista->primeiro = NULL;
    lista->tamanho = 0;
    //Chama a função que preenche a lista
    preencheListaArvore(node,lista);
    NodeList *aux ;
    int achou = 0;
    for(aux = lista->primeiro ; aux != NULL ; aux = aux->next){
        if(aux->p.x == p.x && aux->p.y == p.y){
            printf("(%.2lf , %.2lf): Caminho\n", p.x, p.y);
            return;
        }
        achou = -1;
    }
    if (achou = -1){
        printf("(%.2lf , %.2lf): -1", p.x, p.y);
    }

    deletaLista(lista);
}
//Função que procura um ponto na arvore
void find_point(NodeTree *node, Point p){
    find_point_aux(node,p);
}

double distance(Point p1, Point p2) {
	int c1 = (p2.x - p1.x) * (p2.x - p1.x);
	int c2 = (p2.y - p1.y) * (p2.y - p1.y);

	return sqrt(c1 + c2);
}

/* Função auxiliar a função find_points_in_circle*/
void find_points_in_circle_aux(NodeTree *node,Point p, int r){
    HeadList *lista;
    lista = (HeadList*) malloc(sizeof(HeadList));
    lista->primeiro = NULL;
    lista->tamanho = 0;
    //Chama a função que preenche a lista
    preencheListaArvore(node,lista);
    NodeList *aux;
    for (aux = lista->primeiro; aux != NULL ; aux = aux->next){
        if(distance(p,aux->p) <= r){
            printf("(%.2lf,  %.2lf): %.2lf\n", p.x,p.y,distance(p,aux->p));
        }
    }
}


/*Função que procura pontos dentro do raio*/
void find_points_in_circle(NodeTree *node,Point p, int r){
    find_points_in_circle_aux(node, p, r);
} 

void printList(NodeTree *node){
    NodeList *aux;

    //Percorrendo a lista
    
    for (aux = node->lista->primeiro; aux != NULL; aux = aux->next){
        
		printf("%.2lf    %.2lf \n", aux->p.x, aux->p.y);
    }
}