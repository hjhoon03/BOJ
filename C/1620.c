#include <stdio.h>

int compare(char**, char**);

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    char** pokemon = (char**)malloc(sizeof(char*) * n);

    for(int i = 0; i < n; ++i) scanf("%d")
}