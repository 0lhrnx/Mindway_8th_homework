#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
char b[1000][52];
int c[1000], d[1000] = { 0 }, tmp = 0;
int main() {
    int max = 0;
    int a, i, j, sursor = 0;
    for (i = 0; i < 1000; i++)c[i] = 1;
    scanf("%d", &a);
    for (i = 0; i < a; i++)scanf("%s", b[i]);
    for (i = 0; i < a; i++) {
        if (c[i]) {
            for (j = 1; i + j < a; j++) {
                if (i + 1 == a)break;
                for (sursor = 0; b[i][sursor] != 0; sursor++) {
                    if (b[i][sursor] != b[i + j][sursor])break;
                }
                if (!b[i][sursor]) {
                    c[i + j] = 0;
                    d[i]++;
                }
            }
        }
    }
    for (i = 0; i < a; i++) {
        if (max < d[i]) {
            max = d[i];
            tmp = i;
        }
        if (max == d[i]) {
            for (j = 0; b[i][j] == b[tmp][j] && b[i][j] != 0; j++);
            tmp = b[i][j] < b[tmp][j] ? i : tmp;
        }
    }
    printf("%s", b[tmp]);
}