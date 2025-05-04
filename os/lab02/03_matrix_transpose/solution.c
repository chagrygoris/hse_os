#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    int *matrix = malloc(N * M * sizeof(int));
    for (int i = 0; i < N * M; i++) {
        scanf("%d", &matrix[i]);
    }

    int *transposed = malloc(M * N * sizeof(int));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            transposed[j * N + i] = matrix[i * M + j];
        }
    }

    free(matrix);

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d", transposed[i * N + j]);
            if (j < N - 1) {
                printf(" ");
            } else {
                printf("\n");
            }
        }
        // printf("\n");
    }

    free(transposed);
    return 0;
}