#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME 100
#define NAME_LEN 50

typedef struct {
    char name[NAME_LEN]; // 이름
    int stu_id; // 학번
    int score; // 점수
} Student;

int main() {
    int N;

    printf("학생 배열의 크기(N)를 입력하세요: ");
    scanf("%d", &N);

    // 학생 배열 동적 할당
    Student* arr = (Student*)malloc(sizeof(Student) * N);

    // 파일 입출력
    FILE* fp;
    fp = fopen("/Users/yesol/DataStructure/assignment7/name_list.txt", "r");

    if (fp == NULL) {
        printf("Fail to open\n");
        return 0;
    }

    char file_buff[50];
    char name_list[MAX_NAME][NAME_LEN];
    int name_count = 0;

    while (fgets(file_buff, sizeof(file_buff), fp) != NULL) {
        file_buff[strcspn(file_buff, "\r\n")] = 0;

        strcpy(name_list[name_count], file_buff);  // 파일에서 읽은 이름을 배열에 저장하여 이름 리스트 생성
        name_count++;

        memset(file_buff, 0, sizeof(file_buff));
    }

    fclose(fp);

    // 이름 / 학번 / 성적 
    srand(time(NULL));

    for (int i = 0; i < N; i++) {
        int rand_idx = rand() % name_count;

        strcpy((*(arr + i)).name, name_list[rand_idx]);
        (*(arr + i)).stu_id = i + 1;
        (*(arr + i)).score = rand() % 100 + 1;
    }

    // 최저점 / 최고점 / 평균 계산
    int min_idx = 0;
    int max_idx = 0;
    int sum = 0;

    for (int i = 0; i < N; i++) {
        
        if ((*(arr + i)).score < (*(arr + min_idx)).score)
            min_idx = i;

        if ((*(arr + i)).score > (*(arr + max_idx)).score)
            max_idx = i;

        sum += (*(arr + i)).score;
    }

    double avg = (double)sum / N;

    printf("\n최저점 학생의 정보\n");
    printf("이름: %s, 학번: %d, 성적: %d점\n",
        (*(arr + min_idx)).name, 
        (*(arr + min_idx)).stu_id,
        (*(arr + min_idx)).score);
    
    printf("\n최고점 학생의 정보\n");
    printf("이름: %s, 학번: %d, 성적: %d점\n",
        (*(arr + max_idx)).name, 
        (*(arr + max_idx)).stu_id,
        (*(arr + max_idx)).score);

    printf("\n평균 점수: %.2f점\n", avg);

    free(arr);

    return 0;
}