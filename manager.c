#include "manager.h"

int selectMenu(){
	int menu;
	printf("1. 메뉴 조회\n");
	printf("2. 메뉴 추가\n");
	printf("3. 메뉴 수정\n");
	printf("4. 메뉴 삭제\n");
	printf("5. 수강과목 저장\n");
	printf("6. 과목명 검색\n");
	printf("7. 교수님 성함 검색\n");
	printf("8. 학점수 검색\n");
	printf("9. 교양/전공 검색\n");
	printf("0. 종료\n");
	printf("=> 원하는 메뉴는? ");
	scanf("%d",&menu);

	return menu;
}
int loadData(Course s[]){
    int count=0;
     FILE *fp;
     fp=fopen("course.txt","rt");
     
     if(fp==NULL){
         printf("=>파일 업음\n");
         return 0;
     }
     for(;;count++){
        fscanf(fp,"%[^\n]s %c %c %d",s[count].courseName,&s[count].proName,&s[count].major,&s[count].credit);
       
     if(feof(fp))break;//파일의 끝인지 비교하기
     }
     fclose(fp);
     printf("=>로딩 성공!");
    return count;
}
void saveData(Course *s, int count)
{
    FILE *fp;
    fp = fopen("course.txt", "wt");

    for (int i = 0; i < count; i++)
    {
        if (s[i].credit != -1)
            fprintf(fp, " %s %c %c %d\n", s[i].courseName, s[i].proName,s[i].major,s[i].credit);
    }
    fclose(fp);
    printf("=>저장됨!\n");
}
int createCourse(Course *s){
	printf("과목명은?");
	getchar();
	scanf("%[^\n]s",s->courseName);
	printf("교수님 성함은?");
	scanf("%c",&s->proName);
	printf("전공 또는 교양과목? ");
	scanf("%c",&s->major);
	printf("학점수는?");
	scanf("%d",&s->credit);
	return 1;
}
void readCourse(Course s){
	printf("[ %c ] %s   %c 교수님  ( %d 학점 )",s.major,s.courseName,s.proName,s.credit);
}
void updateCourse(Course *s){
    printf("과목명은?");
    getchar();
    scanf("%[^\n]s",s->courseName);
    printf("교수님 성함은?");
    scanf("%c",&s->proName);
    printf("전공 또는 교양과목? ");
    scanf("%c",&s->major);
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

    printf("검색하고 싶은 과목명을 입력하시오.\n");
    getchar();
    scanf("%[^\n]s",search);

    printf("==============================\n");
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

    printf("검색하고 싶은 학점수를 입력하시오.\n");
    
    scanf("%d",&search);

    printf("==============================\n");
    for(int i=0; i<count;i++){
        if(s[i].credit!=-1){
            if(s[i].credit==search)
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
void searchProfessor(Course *s,int count){
	int scount = 0;
	char search;

	printf("검색하고 싶은 교수님 성함을 입력하시오.\n ");
	scanf("%c", &search);
	printf("==============================\n");
	for(int i=0;i<count;i++){
		if(s[i].credit !=-1){
			if(s[i].proName == search){
				printf("%2d",i+1);
				readCourse(s[i]);
				scount++;				
			}		
		}			
	}
    if(scount==0)printf("=>검색된 데이터 없음!");
    printf("\n");
}
void searchMajor(Course *s,int count){
	int scount = 0;
	char search;

	printf("검색하고 싶은 교수님 성함을 입력하시오.\n ");
	scanf("%c",&search);
	printf("==============================\n");
	for(int i= 0;i<count;i++){
		if(s[i].credit != -1){
			if(s[i].major == search){
				printf("%2d",i+1);
				readCourse(s[i]);
				scount++;
			}
		}
	}	
	if(scount == 0) printf("=>검색된 데이터 없음!");
	printf("\n");
}
