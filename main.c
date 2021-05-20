#include "mytree.c"

int main(){
    Point p1,p2;
    p1.x = 0;
    p1.y = 0;
    p2.x = 10;
    p2.y = 10;
    NodeTree *raiz;
    raiz = create_tree(p1,p2);


       
    int n=6, i;
    Point p;

    for ( i = 0 ; i < n ; i++){
        printf("Cordenada x ");
        scanf ("%lf", &p.x);
        printf("\nCordenada y ");
        scanf ("%lf", &p.y);
        add_tree(raiz,p);
    }
       
}