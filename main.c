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


       
    int n=7, i;
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
    
    p.x = 3;
    p.y = 51;
    find_point(raiz,p);
    p.x=87;
    p.y=99;
    find_point(raiz,p);
    
    printf("\n--\n");
    p.x = 50;
    p.y = 50;
    find_points_in_circle(raiz,p,30);
}