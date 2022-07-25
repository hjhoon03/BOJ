#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int data;
    struct node* next;
} NODE;

typedef struct queue {
    int cnt;
    NODE* top;
    NODE* tail;
} QUEUE;

void push(QUEUE*);
int pop(QUEUE*);
int size(QUEUE*);
int empty(QUEUE*);
int front(QUEUE*);
int back(QUEUE*);

int main() {
    int n;
    QUEUE* q = (QUEUE*)malloc(sizeof(QUEUE));
    q->cnt = 0;
    q->top = NULL;
    q->tail = NULL;
    scanf("%d", &n);
    char buffer[6] = "";

    for(int i = 0; i < n; ++i) {
        scanf("%s", buffer);

        if(strcmp(buffer, "push") == 0)
            push(q);
        else if(strcmp(buffer, "pop") == 0)
            printf("%d\n", pop(q));
        else if(strcmp(buffer, "size") == 0)
            printf("%d\n", size(q));
        else if(strcmp(buffer, "empty") == 0)
            printf("%d\n", empty(q));
        else if(strcmp(buffer, "front") == 0)
            printf("%d\n", front(q));
        else if(strcmp(buffer, "back") == 0)
            printf("%d\n", back(q));
    }

    while(q->top != NULL) {
        NODE* p = q->top->next;
        free(q->top);
        q->top = p;
    }
    free(q);

    return 0;
}

void push(QUEUE* q) {
    int data;
    scanf("%d", &data);

    NODE* n = (NODE*)malloc(sizeof(NODE));

    if(n == NULL) {
        printf("Allocation Error\n");
        return;
    }

    n->next = NULL;
    n->data = data;
    ++(q->cnt);

    if(q->top == NULL) {
        q->top = n;
        q->tail = n;
    } else {
        q->tail->next = n;
        q->tail = n;
    }
}

int pop(QUEUE* q) {
    int return_value = front(q);

    if(return_value == -1)
        return -1;

    NODE* p = q->top;
    q->top = p->next;

    --(q->cnt);

    if(q->top == NULL)
        q->tail = NULL;

    free(p);

    return return_value;
}

int size(QUEUE* q) {
    return q->cnt;
}

int empty(QUEUE* q) {
    if(q->top == NULL)
        return 1;

    return 0;
}

int front(QUEUE* q) {
    if(q->top == NULL)
        return -1;

    return q->top->data;
}

int back(QUEUE* q) {
    if(q->tail == NULL)
        return -1;

    return q->tail->data;
}