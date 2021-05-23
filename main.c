/*
 * Trabalho Prático 1 -- Estruturas de Dados 2020/1
 * Grupo:
 *	Caio Viegas de Souza Gomide -- RGA: 201911901004
 *	Geysson Guilherme Veiga viana -- RGA: 201921901004
 *	Julia Pinheiro Ribeiro -- RGA: 201621901019
 *  Kayo Leone Dias Perim -- RGA: 201911901019

 * 
 */


#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mytree.h"

int main(int argc, char **argv) {
	
	if(argc != 2) {
		fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
		exit(-1);
	}

	FILE *fp = fopen(argv[1], "r");
	if(!fp) {
		fprintf(stderr, "ERROR: %s\n", strerror(errno));
		exit(-1);
	}

	Point p1, p2;
	int __attribute__((unused)) ret;

	ret = fscanf(fp, "%lf %lf", &p1.x, &p1.y);
	ret = fscanf(fp, "%lf %lf", &p2.x, &p2.y);

	/* Função que cria a árvore com os pontos p1 e p2 */
	NodeTree *root = create_tree(p1, p2);
	if(!root) {
		fclose(fp);
		exit(-1);

	}
	int n;
	Point p;
	ret = fscanf(fp, "%d", &n);
	for(int i = 0; i < n; i++) {
		ret = fscanf(fp, "%lf %lf", &p.x, &p.y);

		/* Função que adiciona o ponto p na árvore root */
		add_tree(root, p);
	}
	int m;
	ret = fscanf(fp, "%d", &m);
	for(int i = 0; i < m; i++) {
		ret = fscanf(fp, "%lf %lf", &p.x, &p.y);
		
		/* Função que busca o ponto p na árvore root */
		find_point(root, p);
	}
	printf("--\n");

	int o;
	ret = fscanf(fp, "%d", &o);

	for(int i = 0; i < o; i++) {
		double r;
		ret = fscanf(fp, "%lf %lf %lf", &p.x, &p.y, &r);

		/* Função que busca os pontos que estão dentro da circunferência de ponto p e raio r */
		find_points_in_circle(root, p, r);
	}
	printf("--\n");
	// /* Função que imprime todos os pontos da árvore */
	print_tree(root);/*
	// fclose(fp);

	// /* Função que deleta árvore */
	delete_tree(root);
	if(root){
		printf("Ainda n excluiu");
	}
	
	return 0;
}
