#include <stdio.h>

int main() {
    int count = 0;
    int student = 0;
    int grade[1000] = {};
    int high_grade_student;
    int i, j;
    int sum_grade = 0;
    double middle_grade = 0;
    double result;
    
    scanf("%d", &count);
    
    while(count --) {
        
        scanf("%d", &student);
        
        i = student;
        high_grade_student = 0;
        sum_grade = 0;
        
        while(i --) {
            scanf("%d", &j);
            grade[i] = j;
            sum_grade += grade[i];
        }
        
        middle_grade = sum_grade / student;
        
        i = student;
        
        while(i --) {
            if(grade[i] > middle_grade)
                high_grade_student ++;
        }
        
        result = (double)high_grade_student / (double)student * 100;
        
        printf("%.3lf%%\n", result);
    }
    
    return 0;
}

