#include <stdio.h>
#include <string.h>

int main() {

    int n, i, j, k;
    scanf("%d", &n);
    char c[1000];
    gets(c);

    for(i = 0; i < n; i++) {

        for(j = 0; j < n; j++) {

            int firstLeter = -1;
            gets(c);

            for(k = 0; c[k] != '\0'; k++) {

                if(c[k] == ' ' || c[k] == '\n' || c[k] == '\0') {

                    int x = firstLeter, it = 0, flagOutWord = 0;

                    while(x + it <= k - 1 && x >= 0) {

                        if(c[x + it] != c[k - 1 - it]) flagOutWord = 1;
                        it++;
                    }
                    int ij;

                    if(flagOutWord == 1) {

                        for(ij = firstLeter; ij < k; ij++) printf("%c", c[ij]);
                    }
                    firstLeter = -1;

                } else if(firstLeter == -1) firstLeter = k;
            }
            int x = firstLeter, it = 0, flagOutWord = 0;

            while(x + it <= k - 1 && x >= 0) {

                if(c[x + it] != c[k - 1 - it]) flagOutWord = 1;
                it++;
            }
            int ij;

            if(flagOutWord == 1) {

                for(ij = firstLeter; ij < k; ij++) printf("%c", c[ij]);
            }
        }
    }
    return 0;
}