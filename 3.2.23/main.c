#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, j, m;
    int** a;

    scanf("%d%d", &n, &m);

    a = (int**) malloc(n * sizeof(int*));

    for(i = 0; i < n; i++){

        a[i] = (int*) malloc(m * sizeof(int));

    }

    for(i = 0; i < n; i++){

        for(j = 0; j < m; j++){
            a[i][j] = 1 + j % 2 + (i % 2) * 2;
        }

    }

    for(i = 0; i < n; i++){

        for(j = 0; j < m; j++){
            printf("%d ", a[i][j]);
        }

        printf("\n");
    }
    return 0;
}