#include "manager.h"

int creatCourse(Course *s){
	printf("과목명은?");
	getchar();
	scanf("%[^\n]s",s->courseName);
	printf("교수님 성함은?");
	scanf("%[^\n]s",s->proName);
	printf("전공 또는 교양과목? ");
	scanf("%[^\n]s",s->major);
	printf("학점수는?");
	scanf("%d",&s->credit);
	return 1;
}
void readCourse(Course *s){
	printf("[ %s ] %s   %s 교수님  ( %d 학점 )",major,courseName,proName,&credit);
}
void updateCourse(Course *s){
    printf("과목명은?");
    getchar();
    scanf("%[^\n]s",s->courseName);
    printf("교수님 성함은?");
    scanf("%[^\n]s",s->proName);
    printf("전공 또는 교양과목? ");
    scanf("%[^\n]s",s->major);
    printf("학점수는?");
    scanf("%d",&s->credit);
}

int deleteCourse(Course *s){
    s->credit=-1;
    printf("=>삭제됨!\n");
    return 1;
}
void listCourse(Course *s,int count){
	printf("==============================\n");
	for(int i=0; i<count; i++){
		if(s[i].credit == -1) continue;
		printf("%d ",i+1);
		readCourse(s[i]);
		}
	printf("\n");
	}	

int selectCourseNo(Course *s,int count){
	int no;
	listCourse(s,count);
	printf("번호는 ? (취소 : 0)");
	scanf("%d",&no);
	return no;
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
void searchCredit(Course s[], int count){
    int scount=0;
    int search;

    printf("검색할 학점?");
    
    scanf("%d",search);

    for(int i=0; i<count;i++){
        if(s[i].credit!=-1){
            if(strstr(s[i].credit,search))
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
