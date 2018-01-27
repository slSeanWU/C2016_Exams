#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#define MAX 1000 

typedef struct Node {
    int label;
    struct Node *left, *right;
} Node;

void traversal(Node *root, int N, int command[]){
    int depth = 0, terminate = 0;

    Node *rec[128];
    int direction[128];
    rec[0] = root;

    for(int i = 0;i < N && !terminate;i++){
        switch(command[i]){
            case 0:
                printf("%d\n", rec[depth]->label);
                terminate = 1;
                break;
            case 1:
                printf("%d\n", rec[depth]->label);
                break;
            case 2:
                if(depth > 0)
                    depth--;
                else{
                    printf("%d\n", rec[depth]->label);
                    terminate = 1;
                }
                break;
            case 3:
                if(rec[depth]->left != NULL){
                    rec[depth+1] = rec[depth]->left;
                    direction[depth+1] = 0;
                    depth++;
                }
                else{
                    printf("%d\n", rec[depth]->label);
                    terminate = 1;
                }
                break;
            case 4:
                if(rec[depth]->right != NULL){
                    rec[depth+1] = rec[depth]->right;
                    direction[depth+1] = 1;
                    depth++;
                }
                else{
                    printf("%d\n", rec[depth]->label);
                    terminate = 1;
                }
                break;
            case 5:
                if(rec[depth-1]->left != NULL && rec[depth-1]->right != NULL){
                    if(direction[depth] == 0){
                        rec[depth] = rec[depth-1]->right;
                        direction[depth] = 1;
                    }
                    else{
                        rec[depth] = rec[depth-1]->left;
                        direction[depth] = 0;
                    }
                }
                else{
                    printf("%d\n", rec[depth]->label);
                    terminate = 1;
                }
        }
    }

    return;
}

Node* newNode(int label, Node *l, Node *r) {
    Node *u = (Node *) malloc(sizeof(Node));
    u->label = label, u->left = l, u->right = r;
    return u;
}
 
int main() {
    Node *root = newNode(
            6,
            newNode(
                3,
                newNode(1, 
                        NULL, 
                        newNode(2, NULL, NULL)
                        ),
                newNode(5, 
                        newNode(4, NULL, NULL), 
                        NULL
                        )                
            ),
            newNode(
                7,
                NULL,
                NULL                
            )
    );
 
    int N, command[MAX];
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf("%d", &command[i]);        
    }
    traversal(root, N, command);
    return 0;
}