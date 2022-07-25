#include <stdio.h>
#include <stdlib.h>

typedef struct lec {
    int start;
    int end;
    struct lec* prev;
    struct lec* next;
} LECTURE;

typedef struct {
    LECTURE* begin;
} ROOM;

ROOM* CreateRoom(int*);
void AddLecture_back(ROOM*, int*);
void AddLecture_front(ROOM*, LECTURE*, int*);

int main() {
    int n;
    scanf("%d", &n);
    int cnt = 0;
    ROOM** arr = (ROOM**)malloc(sizeof(ROOM*) * cnt);
    int time[2] = {0};

    for(int i = 0; i < n; ++i) {
        scanf("%d %d", time, time + 1);

        for(int i = 0; i < n; ++i) {

        }

        ++cnt;
        realloc(arr, sizeof(ROOM*) * cnt);
        arr[cnt - 1] = CreateRoom();
        AddLecture_front(arr[cnt - 1], time);
    }

    return 0;
}

ROOM* CreateRoom(int* time) {
    ROOM* p_room = (ROOM*)malloc(sizeof(ROOM));
    p_room->begin = NULL;

    LECTURE* p_lecture = (LECTURE*)malloc(sizeof(LECTURE));
    p_lecture->start = time[0];
    p_lecture->end = time[1];
    p_lecture->prev = NULL;
    p_lecture->next = NULL;
    p_room->begin = p_lecture;

    return p_room;
}

void AddLecture_front(ROOM* r, LECTURE* l, int* time) {
    LECTURE* p_lec = (LECTURE*)malloc(sizeof(LECTURE));
    LECTURE* p_prev = l->prev;

    p_lec->start = time[0];
    p_lec->end = time[1];
    p_lec->prev = l->prev;
    p_lec->next = l;
    l->prev = p_lec;

    if(p_prev == NULL) {
        r->begin = p_lec;
        return;
    }

    p_prev->next = p_lec;
}