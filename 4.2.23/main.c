#include <stdio.h>


int main() {

    char c[1000];
    FILE *f = fopen("input.txt", "r");
    if(fgets(c, 1000, f) == NULL)printf("truble\n");

    int i, flagWord = 0, digitRes = 0, wordRes = 0;

    for(i = 0; c[i] != '\0'; i++) {

        if(c[i] >= 'a' && c[i] <= 'z' && c[i] >= 'a' && c[i] <= 'z') flagWord = 1;
        else {

            wordRes += flagWord;
            flagWord = 0;

            if(c[i] >= '0' && c[i] <='9') {

                digitRes += c[i] - '0';
            }

        }

    }
    if(wordRes == digitRes) printf("TRUE");
    else printf("FALSE");

    return 0;
}
