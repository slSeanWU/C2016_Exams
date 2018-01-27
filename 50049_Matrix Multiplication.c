#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define MAX 1000
static int A_elements[MAX], A_rowind[MAX], A_colind[MAX];
static int B_elements[MAX], B_rowind[MAX], B_colind[MAX];

void matrix_multiplication(int N, int** ptrA, int M, int** ptrB, int S, int *result){
	int *A_ele = ptrA[0], *A_row = ptrA[1], *A_col = ptrA[2];
    int *B_ele = ptrB[0], *B_row = ptrB[1], *B_col = ptrB[2];

    memset(result, 0, sizeof(int)*S*S);
    for(int i = 0;i < N;i++)
        for(int j = 0;j < M;j++)
            if(A_col[i] == B_row[j])
                result[ A_row[i]*S + B_col[j] ] += A_ele[i]*B_ele[j];
	
	return;	
} 

// main function provided for testing
int main(int argc, char const *argv[])
{   
    int N, M, S;
    assert(scanf("%d %d %d", &N, &M, &S) == 3);
 
    int *ptrA[3];
    int *ptrB[3];
    ptrA[0] = A_elements, ptrA[1] = A_rowind, ptrA[2] = A_colind;
    ptrB[0] = B_elements, ptrB[1] = B_rowind, ptrB[2] = B_colind;
 
    for(int i = 0; i < N; ++i)
        assert(scanf("%d", &A_elements[i]) == 1);
    for(int i = 0; i < N; ++i)
        assert(scanf("%d", &A_rowind[i]) == 1);   
    for(int i = 0; i < N; ++i)
        assert(scanf("%d", &A_colind[i]) == 1);           
    for(int i = 0; i < M; ++i)
        assert(scanf("%d", &B_elements[i]) == 1);
    for(int i = 0; i < M; ++i)
        assert(scanf("%d", &B_rowind[i]) == 1);   
    for(int i = 0; i < M; ++i)
        assert(scanf("%d", &B_colind[i]) == 1);
 
    int result[S*S];
    matrix_multiplication(N, ptrA, M, ptrB, S, result);
    for (int i = 0; i < S; ++i)
        for (int j = 0; j < S; ++j)
              printf("%d%c", result[i * S + j], " \n"[j == S - 1]);
    return 0;
}

