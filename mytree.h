#ifndef __MYTREE_H_
#define __MYTREE_H_



#define MAXPOINTS 4
#define MAX(a,b) ((a) > (b) ? (a) : (b))

typedef struct Point {
	double x;
	double y;
	//TODO
} Point;

typedef struct NodeList {
	Point p;

	struct NodeList *next;
	//TODO
} NodeList;

typedef struct NodeTree {
	NodeList *list;
	
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