#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
//#include "trace.h"

typedef struct ChildList ChildList;
typedef struct Node {
    ChildList *list;
} Node;

struct ChildList {
    Node *node;
    ChildList *next;
};

typedef struct Answer {
    int InternalNode;
    int Leaf;
    int MaxBranchFactor;
    int Depth;
} Answer;

void myTrace(Node *root, Answer *ans, int depth){
    if( depth > ans->Depth )
        ans->Depth = depth;

    if( root->list == NULL )
        ans->Leaf++;
    else{
        ans->InternalNode++;
        ChildList *ptr = root->list;
        int cnt;

        for(cnt = 0;ptr != NULL;cnt++){
            myTrace(ptr->node, ans, depth+1);
            ptr = ptr->next;
        }

        if(cnt > ans->MaxBranchFactor)
            ans->MaxBranchFactor = cnt;
    }

    return;
}
void trace(Node *root, Answer *ans){
    myTrace(root, ans, 0);
    return;
}

// functions provided for testing
Node *newNode()
{
    Node *ret = malloc(sizeof(Node));
    ret->list = NULL;
    return ret;
}

ChildList *newList(Node *node, ChildList *next)
{
    ChildList *ret = malloc(sizeof(ChildList));
    ret->node = node;
    ret->next = next;
    return ret;
}

int main()
{
    //sample input
    Node *root = newNode();
    Node *n1= newNode(), *n2 = newNode(), *n3 = newNode(), *n4 = newNode(), *n5 = newNode(), *n6 = newNode();
    ChildList *l3 = newList(n3, NULL), *l2 = newList(n2, l3), *l1 = newList(n1, l2);
    ChildList *l5 = newList(n5, NULL), *l4 = newList(n4, l5), *l6 = newList(n6, NULL);
    root->list = l1;
    n2->list = l4;
    n4->list = l6;
    //end
    Answer *ans = calloc(1, sizeof(Answer));
    trace(root, ans);
    printf("%d %d %d %d\n", ans->InternalNode, ans->Leaf, ans->MaxBranchFactor, ans->Depth);
    return 0;
}