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
	
        fscanf(fp,"%d",&s[count].credit);
	fgets(s[count].courseName,sizeof(s[count].courseName),fp);
s[count].courseName[strlen(s[count].courseName)]='\0';
       	fgets(s[count].proName,sizeof(s[count].proName),fp);
s[count].proName[strlen(s[count].proName)]='\0';
	fgets(s[count].major,sizeof(s[count].major),fp);
s[count].major[strlen(s[count].major)]='\0';
printf("hello");
     if(feof(fp))break;//파일의 끝인지 비교하기
     }
     fclose(fp);
     printf("=>로딩 성공!\n");
    return count;
}
void saveData(Course *s, int count)
{
    FILE *fp;
    fp = fopen("course.txt", "wt");

    for (int i = 0; i < count; i++)
    {
        if (s[i].credit != -1)
            fprintf(fp, "%d %s %s %s\n",s[i].credit,s[i].courseName,s[i].proName,s[i].major);
		
    }
    fclose(fp);
    printf("=>저장됨!\n");
}
int createCourse(Course *s){//수강과목 리스트 추가하는 한수
	printf("과목명은?");
	getchar();
	scanf("%[^\n]s",s->courseName);
	printf("교수님 성함은?");
	scanf("%s",s->proName);
	printf("전공 또는 교양과목? ");
	scanf("%s",s->major);
	printf("학점수는?");
	scanf("%d",&s->credit);
	return 1;
}
void readCourse(Course s){//수강과모 리스트 조회하는 한수
	printf("[ %s ] %s %s교수님 ( %d 학점 )\n",s.major,s.courseName,s.proName,s.credit);
}
void updateCourse(Course *s){//수강 과목 리스트 중 원하는 과목을 수정하는 함수
    printf("과목명은?");
    getchar();
    scanf("%[^\n]s",s->courseName);
    printf("교수님 성함은?");
    scanf("%s",s->proName);
    printf("전공 또는 교양과목? ");
    scanf("%s",s->major);
    printf("학점수는?");
    scanf("%d",&s->credit);
}

int deleteCourse(Course *s){//수강과목 리스트 중 원하는 과목을 수정하는 함수
    s->credit=-1;
    printf("=>삭제됨!\n");
    return 1;
}
void listCourse(Course *s,int count){//수강과목리스트를 나열하여 보여주는 함수
	printf("==============================\n");
	for(int i=0; i<count; i++){
		if(s[i].credit == -1) continue;
		printf("%d ",i+1);
		readCourse(s[i]);
		}
	printf("\n");
	}	

int selectCourseNo(Course *s,int count){//수강 과목 리스트 중 번호 선택하는 함수
	int no;
	listCourse(s,count);
	printf("번호는 ? (취소 : 0)");
	scanf("%d",&no);
	return no;
	}
void searchName(Course s[], int count){//수강과목 리스트 중에서 과목명을 검색하여 찾는 함수
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

void searchCredit(Course s[], int count){//수강과목 리스트 중에서 학점을 검색하여 찾는 함수
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
void searchProfessor(Course *s,int count){//수강과목 리스트 중에서 교수님 성함을 검색하여 찾는 함수
	int scount = 0;
	char search[30];

	printf("검색하고 싶은 교수님 성함을 입력하시오.\n ");
	scanf("%s", search);
	printf("==============================\n");
	for(int i=0;i<count;i++){
		if(s[i].credit !=-1){
	            if(strstr(s[i].proName,search)){
				printf("%2d",i+1);
				readCourse(s[i]);
				scount++;				
			}		
		}			
	}
    if(scount==0)printf("=>검색된 데이터 없음!");
    printf("\n");
}
void searchMajor(Course *s,int count){//수강 과목 리스트 중에서 교양 또는 전공 과목을 찾는 함수
	int scount = 0;
	char search[10];

	printf("검색하고 싶은 교수님 성함을 입력하시오.\n ");
	scanf("%s",search);
	printf("==============================\n");
	for(int i= 0;i<count;i++){
		if(s[i].credit != -1){
	            if(strstr(s[i].major,search)){
				printf("%2d",i+1);
				readCourse(s[i]);
				scount++;
			}
		}
	}	
	if(scount == 0) printf("=>검색된 데이터 없음!");
	printf("\n");
}
