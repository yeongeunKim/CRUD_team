#include "manager.h"

void updateCourse(Course *s){
    printf("과목명은?");
    getchar();
    scanf("%[^\n]s",s->courseName);
    printf("교수님 성함은?");
    scanf("%[^\n]s",s->proName);
    printf("전공 또는 교양과목? ");
    scanf("%[^\n]s",s->major);
    printf("학점수?");
    scanf("%[^\n]s",s->credit);
}

int deleteCourse(Course *s){
    s->credit=-1;
    printf("=>삭제됨!\n");
    return 1;
}
void searchName(Course s[], int count){
    int scount=0;
    char search[20];

    printf("검색할 과목명?");
    getchar();
    scanf("%[^\n]s",search);

    for(int i=0; i<count;i++){
        if(s[i].credit!=-1){
            if(strstr(s[i].courseName,search))
            {
                printf("%2d",i+1 );
                readCourse(s[i]);
                scount++;
            }
        }
    }
    if(scount==0)printf("=>검색된 데이터 없음!");
    printf("\n");
}
