#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Students_data {
    char name[10];
    char title[4];
    int hakbun;
    char hakjum[3];
    int jumsu[3];
    int sum_grade;
    double average;
    int rank;
};

typedef struct Students_data data;

char* str[] = {
    "성적순 성적출력",
    "이름순 성적출력",
    "학번순 성적출력",
    "학점별 그래프화",
    "검색하기 <학번 or 이름>",
    "종료"
};

void showmenu();
int input_data(data*);
int output_data(data*);
int calculator(data*);
int sort(int, data*);
int cal_rank(data*);
void searching(char*, data*);
void graphing(data*);

int main() {
    data S_info[5];

    input_data(S_info);
    calculator(S_info);
    cal_rank(S_info);
    while (1) {
        int num = 0;
        showmenu();
        printf("원하는 번호를 선택하세요 : ");
        scanf("%d", &num);

        if (num == 6) {
            printf("프로그램 종료 \a");
            break;
        }

        if (num == 4) {
            graphing(S_info);
        }
        else if (num == 5) {
            char keyword[20];
            printf("검색할 학번 또는 이름을 입력하세요: ");
            scanf("%s", keyword);
            searching(keyword, S_info);
            printf("\n\n");
        }
        else {
            sort(num, S_info);
            output_data(num, S_info);
            printf("\n\n");
        }
    
    }

    return 0;
}

void showmenu() {
    printf("======================================\n");
    printf("메뉴\n");
    printf("======================================\n");
    for (int i = 0; i < 6; ++i) {
        printf("%d. %s\n\n", i + 1, str[i]);
    }
}

int input_data(data* S_info) {
    strcpy(S_info[0].name, "김채연");
    S_info[0].hakbun = 200602001;
    S_info[0].jumsu[0] = 100;
    S_info[0].jumsu[1] = 90;
    S_info[0].jumsu[2] = 100;

    strcpy(S_info[1].name, "김삼순");
    S_info[1].hakbun = 200602002;
    S_info[1].jumsu[0] = 90;
    S_info[1].jumsu[1] = 80;
    S_info[1].jumsu[2] = 100;

    strcpy(S_info[2].name, "정준하");
    S_info[2].hakbun = 200602004;
    S_info[2].jumsu[0] = 100;
    S_info[2].jumsu[1] = 80;
    S_info[2].jumsu[2] = 80;

    strcpy(S_info[3].name, "박채림");
    S_info[3].hakbun = 200602005;
    S_info[3].jumsu[0] = 90;
    S_info[3].jumsu[1] = 90;
    S_info[3].jumsu[2] = 30;

    strcpy(S_info[4].name, "조상실");
    S_info[4].hakbun = 200602003;
    S_info[4].jumsu[0] = 80;
    S_info[4].jumsu[1] = 30;
    S_info[4].jumsu[2] = 40;

    return 0;
}

int output_data(int n, data* S_info) {
    printf("============================================================\n");
    printf("학번       이름     c언어    전자공학   컴퓨터  총점   평균       학점    등수\n");
    for (int i = 0; i < 5; ++i) {
        printf("%d  %s    %3d         %3d       %3d   %d    %.1lf         %s       %d\n", S_info[i].hakbun, S_info[i].name, S_info[i].jumsu[0], S_info[i].jumsu[1], S_info[i].jumsu[2], S_info[i].sum_grade, S_info[i].average, S_info[i].hakjum, S_info[i].rank);
    }

    return 0;
}

int calculator(data* S_info) {
    for (int i = 0; i < 5; ++i) {
        int sum = 0;
        for (int j = 0; j < 3; ++j) {
            sum += S_info[i].jumsu[j];
        }
        S_info[i].sum_grade = sum;
        S_info[i].average = sum / 3.0;

        // 학점 부여
        if (S_info[i].average >= 90) {
            strcpy(S_info[i].hakjum, "A");
        }
        else if (S_info[i].average >= 80) {
            strcpy(S_info[i].hakjum, "B");
        }
        else if (S_info[i].average >= 70) {
            strcpy(S_info[i].hakjum, "C");
        }
        else if (S_info[i].average >= 60) {
            strcpy(S_info[i].hakjum, "D");
        }
        else {
            strcpy(S_info[i].hakjum, "F");
        }
    }

    return 0;
}

int sort(int n, data* S_info) {
    if (n == 1) {
        // 성적 순으로 정렬
        int sub_n = 0;
        printf("성적순 정렬\n\n1. 오름차순\n2. 내림차순\n선택 : ");
        scanf("%d", &sub_n);

        if (sub_n == 1) {
            // 오름차순
            for (int i = 0; i < 4; ++i) {
                int least = i;
                for (int j = i + 1; j < 5; ++j) {
                    if (S_info[least].average > S_info[j].average) {
                        least = j;
                    }
                }
                data temp = S_info[least];
                S_info[least] = S_info[i];
                S_info[i] = temp;
            }
        }
        else if (sub_n == 2) {
            // 내림차순
            for (int i = 0; i < 4; ++i) {
                int max = i;
                for (int j = i + 1; j < 5; ++j) {
                    if (S_info[max].average < S_info[j].average) {
                        max = j;
                    }
                }
                data temp = S_info[max];
                S_info[max] = S_info[i];
                S_info[i] = temp;
            }
        }
    }
    else if (n == 2) {
        // 이름 순으로 정렬
        for (int i = 0; i < 4; ++i) {
            int least = i;
            for (int j = i + 1; j < 5; ++j) {
                if (strcmp(S_info[least].name, S_info[j].name) > 0) {
                    least = j;
                }
            }
            data temp = S_info[least];
            S_info[least] = S_info[i];
            S_info[i] = temp;
        }
    }
    else if (n == 3) {
        // 학번 순으로 정렬 (오름차순)
        for (int i = 0; i < 4; ++i) {
            int least = i;
            for (int j = i + 1; j < 5; ++j) {
                if (S_info[least].hakbun > S_info[j].hakbun) {
                    least = j;
                }
            }
            data temp = S_info[least];
            S_info[least] = S_info[i];
            S_info[i] = temp;
        }
    }

    return 0;
}

int cal_rank(data* S_info) {
    int num[5] = { 1, 1, 1, 1, 1 };
    for (int i = 0; i < 5; ++i) {
        for (int j = i + 1; j < 5; ++j) {
            if (S_info[i].average < S_info[j].average) {
                ++num[i];
            }
            else if (S_info[i].average > S_info[j].average) {
                ++num[j];
            }
        }
        S_info[i].rank = num[i];
    }

    return 0;
}


void searching(char* keyword, data* S_info) {//이름 혹은 학번을 통한 검색
    for (int i = 0; i < 5; ++i) {
        if (strcmp(keyword, S_info[i].name)== 0 || S_info[i].hakbun == atoi(keyword)) {//atoi를 활용하여 문자열을 정수로 변환
            printf("============================================================\n");
            printf("학번       이름     c언어    전자공학   컴퓨터  총점   평균       학점    등수\n");
            printf("%d  %s    %3d         %3d       %3d   %d   %.1lf         %s       %d\n", S_info[i].hakbun, S_info[i].name, S_info[i].jumsu[0], S_info[i].jumsu[1], S_info[i].jumsu[2], S_info[i].sum_grade, S_info[i].average, S_info[i].hakjum, S_info[i].rank);
        }
        
    }
}
void graphing(data* S_info) { //그래핑 기능, 학점별 인원수를 *의 갯수로 표현
    int count[5] = { 0 };
    for (int i = 0; i < 5; ++i) {
        if (strcmp(S_info[i].hakjum, "A") == 0) {
            ++count[0];
        }
        else if (strcmp(S_info[i].hakjum, "B") == 0) {
            ++count[1];
        }
        else if (strcmp(S_info[i].hakjum, "C") == 0) {
            ++count[2];
        }
        else if (strcmp(S_info[i].hakjum, "D") == 0) {
            ++count[3];
        }
        else if (strcmp(S_info[i].hakjum, "F") == 0) {
            ++count[4];
        }
    }
    
        printf("A : ");
        for (int j = 0; j < count[0]; ++j) {
            printf("*");
        }
        printf("\nB : ");
        for (int j = 0; j < count[1]; ++j) {
            printf("*");
        }
        printf("\nC : ");
        for (int j = 0; j < count[2]; ++j) {
            printf("*");
        }
        printf("\nD : ");
        for (int j = 0; j < count[3]; ++j) {
            printf("*");
        }
        printf("\nF : ");
        for (int j = 0; j < count[4]; ++j) {
            printf("*");
        }
        printf("\n\n");
}
