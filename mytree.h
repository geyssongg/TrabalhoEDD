#ifndef __MYTREE_H_
#define __MYTREE_H_



#define MAXPOINTS 4
#define MAX(a,b) ((a) > (b) ? (a) : (b))

typedef struct Point {
	double x;
	double y;
	//TODO
} Point;

/*	A variavel *primeira aponta para o primeiro elemento da lista 
	A variavel tamanho tem o valor de -1 até 5 
	Sendo -1: a arvore tem filhos e o ponto não pode ser inserido naquela lista
	0: o nó acabou de ser criado e não tem filhos
 	1 a 4: a lista não esta cheia
 	5: o nó será quebrado e terá filhos assim que inserir o 5º elemento, mudando para -1
*/
typedef struct headList {
	struct NodeList *primeiro;
	int tamanho;
} HeadList;

typedef struct NodeList {
	Point p;

	struct NodeList *next;
	//TODO
} NodeList;

typedef struct NodeTree {
	HeadList *lista;
	int filhos;
	Point p1;
	Point p2;
    struct NodeTree *SE;
    struct NodeTree *NE;
    struct NodeTree *SO;
    struct NodeTree *NO;
	//TODO
} NodeTree;

/*double distance(Point p1, Point p2);
NodeTree *create_tree(Point p1, Point p2);
*/
#endif