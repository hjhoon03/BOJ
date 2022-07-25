#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int data;
    struct node* next;
} NODE;

typedef struct stack {
    int cnt;
    NODE* top
} STACK;

void push(STACK*);
int pop(STACK*);
int size(STACK*);
int empty(STACK*);
int top(STACK*);


int main() {
    int n;

    STACK* s = (STACK*)malloc(sizeof(STACK));
    s->cnt = 0;
    s -> top = NULL;

    scanf("%d", &n);
    char buffer[6] = "";

    for(int i = 0; i < n; ++i) {
        scanf("%s", buffer);
        if(strcmp(buffer, "push") == 0)
            push(s);
        else if(strcmp(buffer, "pop") == 0)
            printf("%d\n", pop(s));
        else if(strcmp(buffer, "size") == 0)
            printf("%d\n", size(s));
        else if(strcmp(buffer, "empty") == 0)
            printf("%d\n", empty(s));
        else if(strcmp(buffer, "top") == 0)
            printf("%d\n", top(s));
    }

    while(s->top != NULL) {
        NODE* p = s->top->next;
        free(s->top);
        s->top = p;
    }
    free(s);

    return 0;
}

void push(STACK* s) {
    int data;
    scanf("%d", &data);

    NODE* n = (NODE*)malloc(sizeof(NODE));
    if(n == NULL) {
        printf("Allocation Error\n");
        return;
    }
    ++(s->cnt);
    n->data = data;
    n->next = s->top;
    s->top = n;
}

int pop(STACK* s) {
    int return_value = top(s);

    if(return_value == -1)
        return -1;

    NODE* p = s->top->next;
    free(s->top);
    s->top = p;
    --(s->cnt);

    return return_value;
}

int size(STACK* s) {
    return s->cnt;
}

int empty(STACK* s) {
    if(s->top == NULL)
        return 1;
    else
        return 0;
}

int top(STACK* s) {
    if(s->top == NULL)
        return -1;

    return s->top->data;
}

