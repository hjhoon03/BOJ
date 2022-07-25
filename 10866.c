#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int data;
    struct node* prev;
    struct node* next;
} NODE;

typedef struct deque {
    int cnt;
    NODE* front;
    NODE* back;
} DEQUE;

void push_front(DEQUE*);
void push_back(DEQUE*);
int pop_front(DEQUE*);
int pop_back(DEQUE*);
int size(DEQUE*);
int empty(DEQUE*);
int front(DEQUE*);
int back(DEQUE*);

int main() {
    int n;
    scanf("%d", &n);

    DEQUE* d = (DEQUE*)malloc(sizeof(DEQUE));
    d->cnt = 0;
    d->front = NULL;
    d->back = NULL;

    char buffer[11] = "";

    for(int i = 0; i < n; ++i) {
        scanf("%s", buffer);
        
        if(strcmp(buffer, "push_front") == 0)
            push_front(d);
        else if(strcmp(buffer, "push_back") == 0)
            push_back(d);
        else if(strcmp(buffer, "pop_front") == 0)
            printf("%d\n", pop_front(d));
        else if(strcmp(buffer, "pop_back") == 0)
            printf("%d\n", pop_back(d));
        else if(strcmp(buffer, "size") == 0)
            printf("%d\n", size(d));
        else if(strcmp(buffer, "empty") == 0)
            printf("%d\n", empty(d));
        else if(strcmp(buffer, "front") == 0)
            printf("%d\n", front(d));
        else if(strcmp(buffer, "back") == 0)
            printf("%d\n", back(d));
    }

    while(d->front != NULL) {
        NODE* p = d->front->next;
        free(d->front);
        d->front = p;
    }
    free(d);

    return 0;
}

void push_front(DEQUE* d) {
    int data;
    scanf("%d", &data);

    NODE* n = (NODE*)malloc(sizeof(NODE));
    if(n == NULL) {
        printf("Allocation Error\n");
        return;
    }

    n->data = data;
    n->prev = NULL;
    n->next = d->front;
    if(d->front == NULL)
        d->back = n;
    else
        d->front->prev = n;
    d->front = n;
    ++(d->cnt);
}

void push_back(DEQUE* d) {
    int data;
    scanf("%d", &data);

    NODE* n = (NODE*)malloc(sizeof(NODE));
    if(n == NULL) {
        printf("Allocation Error\n");
        return;
    }

    n->data = data;
    n->prev = d->back;
    n->next = NULL;
    if(d->back == NULL)
        d->front = n;
    else
        d->back->next = n;
    d->back = n;
    ++(d->cnt);
}

int pop_front(DEQUE* d) {
    int return_value = front(d);

    if(return_value == -1)
        return -1;

    NODE* p = d->front;
    d->front = p->next;
    if(d->front == NULL)
        d->back = NULL;
    else
        d->front->prev = NULL;
    --(d->cnt);
    free(p);

    return return_value;
}

int pop_back(DEQUE* d) {
    int return_value = back(d);

    if(return_value == -1)
        return -1;

    NODE* p = d->back;
    d->back = p->prev;
    if(d->back == NULL)
        d->front = NULL;
    else
        d->back->next = NULL;
    --(d->cnt);
    free(p);

    return return_value;
}

int size(DEQUE* d) {
    return d->cnt;
}

int empty(DEQUE* d) {
    if(size(d) == 0)
        return 1;

    return 0;
}

int front(DEQUE* d) {
    if(d->front == NULL)
        return -1;

    return d->front->data;
}

int back(DEQUE* d) {
    if(d->back == NULL)
        return -1;

    return d->back->data;
}