#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include <string.h>
//#include "City_Grid.h"

typedef struct City {
    int label;
    struct City *east, *north;
}City;
bool visited[10000];
int grids;

void completeGrid(City *c1, City *c2){
    if( c1->north != NULL && c2->east != NULL )
        grids++;
    return;
}

void traverse(City *root){
    visited[ root->label ] = true;

    if( root->east != NULL && root->north != NULL )
        completeGrid(root->east, root->north);

    if( root->east != NULL && !visited[ root->east->label ] )
        traverse(root->east);
    if( root->north != NULL && !visited[ root->north->label ] )
        traverse(root->north);

    return;
}

int City_Grid(City *capital){
    grids = 0;
    memset(visited, false, sizeof(visited));
    traverse(capital);

    int ret = grids;
    return ret;
}

// functions provided for testing
City* newNode(int label, City *E, City *N) {
    City *u = (City *) malloc(sizeof(City));
    u->label = label, u->east = E, u->north = N;
    return u;
}
 
int main() {
    City *capital = newNode(0, NULL, NULL);
    capital->east = newNode(1, newNode(3, NULL, NULL), NULL);
    capital->north = newNode(2, NULL, newNode(5, NULL, NULL));
    capital->east->north = capital->north->east = newNode(4, NULL, NULL);
 
    City *temp = capital->east->north;
    temp->east = newNode(6, NULL, NULL);
    temp->north = newNode(7, NULL, NULL);
    temp->east->north = temp->north->east = newNode(8, NULL, NULL);
 
    printf("%d\n", City_Grid(capital));
    return 0;
}