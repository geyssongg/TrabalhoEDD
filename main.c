#include "mytree.c"

int main(){
    Point p1,p2;
    /*printf("X do p1 da raiz:");
    fflush(stdin);
    scanf("%i", &p1.x);
    printf("Y do p1 da raiz:");
    fflush(stdin);
    scanf("%i", &p1.y);    
    printf("X do p2 da raiz:");
    fflush(stdin);
    scanf("%i", &p2.x);
    printf("Y do p1 da raiz:");
    fflush(stdin);
    scanf("%i", &p2.y);*/
    p1.x = 0;
    p1.y = 0;
    p2.x = 100;
    p2.y = 100;
    NodeTree *raiz;
    raiz = create_tree(p1,p2);


       
    int n=6, i;
    Point p;

    for ( i = 0 ; i < n ; i++){
        printf("Adicione um ponto\n");
        printf("Cordenada x \n");
        fflush(stdin);
        scanf ("%lf", &p.x);
        printf("Cordenada y\n ");
        fflush(stdin);
        scanf ("%lf", &p.y);
        add_tree(raiz,p);
    }
    
    
    
    printf("\n Coordenada NE ");
    printf("%.2lf  %.2lf %.2lf  %.2lf", raiz->NE->p1.x, raiz->NE->p1.y , raiz->NE->p2.x, raiz->NE->p2.y);
    printf("\n Coordenada NO ");
    printf("%.2lf  %.2lf %.2lf  %.2lf", raiz->NO->p1.x, raiz->NO->p1.y , raiz->NO->p2.x, raiz->NO->p2.y);    
    printf("\n Coordenada SO ");
    printf("%.2lf  %.2lf %.2lf  %.2lf", raiz->SO->p1.x, raiz->SO->p1.y , raiz->SO->p2.x, raiz->SO->p2.y);
    printf("\n Coordenada SE ");
    printf("%.2lf  %.2lf %.2lf  %.2lf", raiz->SE->p1.x, raiz->SE->p1.y , raiz->SE->p2.x, raiz->SE->p2.y);

    printf("\nPontos da raiz: ");
    printList(raiz);
    printf("\nPontos do no NE: ");
    printList(raiz->NE);
    printf("\nPontos do no NO: ");
    printList(raiz->NO);
    printf("\nPontos do no SO: ");
    printList(raiz->SO);
    printf("\nPontos do no SE: ");
    printList(raiz->SE);

}