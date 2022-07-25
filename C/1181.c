#include <stdio.h>
#include <string.h>
int why = 0;
char words[20001][51] = {0};
int arr_len[20001] = {0};

int sort_dic(int start, int end, int arr_len);
void delete(int index);
void quick_sor(int start, int end);

int main() {
    int n;
    int index = -1;

    scanf("%d", &n);

    for(int i = 0; i < n; i ++) {
        scanf("%s", words[i]);
        arr_len[i] = strlen(words[i]);
    }

    quick_sor(0, n - 1);

//    for(int i = 0; i < n - 1; i ++) {
//        int min = arr_len[i];
//        int min_index = i;
//        for(int j = i + 1; j < n; j ++) {
//            if(arr_len[j] < min) {
//                min = arr_len[j];
//                min_index = j;
//            }
//        }
//
//        int tmp = arr_len[i];
//        arr_len[i] = min;
//        arr_len[min_index] = tmp;
//
//        for(int j = 0; words[i][j]; j ++) {
//            char temp = words[i][j];
//            words[i][j] = words[min_index][j];
//            words[min_index][j] = temp;
//        }
//    }

    for(int i = 0; arr_len[i]; i ++) {
        if((index == -1) && (arr_len[i] == arr_len[i + 1])) index = i;
        else if((index != -1) && (arr_len[i] != arr_len[i + 1])) {
            int flag = sort_dic(index, i, arr_len[index]);
            index = -1;
            i -= flag;
        }
    }
    

    for (int i = 0; words[i][0]; i ++) {
        printf("%s\n", words[i]);
    }
}

int sort_dic(int start, int end, int len) {
    int count = 0;
    for(int i = start; i <= end - 1; i ++) {
        int index = i;
        for(int j = i + 1; j <= end; j ++) {
            for (int k = 0; k < len; k ++) {
                if ((k == len - 1) && (words[index][k] == words[j][k])) {
                    delete(j);
                    count ++;
                    end --;
                    j --;
                }
                else if (words[index][k] == words[j][k])
                    continue;
                else if (words[index][k] > words[j][k]) {
                    index = j;
                    break;
                } else
                    break;
            }
        }

        if (i != index) {
            char tmp[51];
            strcpy(tmp, words[index]);
            strcpy(words[index], words[i]);
            strcpy(words[i], tmp);
        }
    }

    return count;
}

void delete(int index) {
    for(int i = index; words[i][0]; i ++) {
        for(int j = 0; words[i + 1][j] || words[i][j]; j ++) {
            words[i][j] = words[i + 1][j];
        }
        arr_len[i] = arr_len[i + 1];
    }
}

void quick_sor(int start, int end) {
    int pivot = arr_len[start];
    int i = start + 1, j = end;
    char pivot_wor[51];
    strcpy(pivot_wor, words[start]);

    while(i <= j) {
        while((i <= end) && (arr_len[i] <= pivot)) i ++;
        while((j > start) && (arr_len[j] >= pivot)) j --;

        if(i < j) {
            int tmp_num = arr_len[i];
            arr_len[i] = arr_len[j];
            arr_len[j] = tmp_num;

            char tmp_wor[51];
            strcpy(tmp_wor, words[i]);
            strcpy(words[i], words[j]);
            strcpy(words[j], tmp_wor);

        } else if (i >= j && start != j) {
            int tmp_num = arr_len[j];
            arr_len[j] = arr_len[start];
            arr_len[start] = tmp_num;

            char tmp_wor[51];
            strcpy(tmp_wor, words[j]);
            strcpy(words[j], words[start]);
            strcpy(words[start], tmp_wor);

            break;
        }
    }

    if(start < j-1) quick_sor(start, j-1);
    if(j+1 < end) quick_sor(j+1, end);
}