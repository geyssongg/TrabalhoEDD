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
    p2.x = 10;
    p2.y = 10;
    NodeTree *raiz;
    raiz = create_tree(p1,p2);


       
    int n=8, i;
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

    /*percorrerArvore(raiz);*/
    
    find_point(root, p);
    

    /*printf("\nPontos da raiz: ");
    printList(raiz);
    printf("\nPontos do no NE: ");
    printList(raiz->NE);
    printf("\nPontos do no NO: ");
    printList(raiz->NO);
    printf("\nPontos do no SO: ");
    printList(raiz->SO);
    printf("\nPontos do no SE: ");
    printList(raiz->SE);*/

}