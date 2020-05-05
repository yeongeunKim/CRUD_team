#include<stdio.h>
#include<string.h>

typedef struct{
	char courseName[30];//과목명 저장하는 함수
	char proName[30];//교수님 성함 저장하는 변수
	char major[20];//교양인지 전공인지 구분하는 변수
	int credit;
} Course;

int creatCourse(Course *s);
void readCourse(Course *s);
void updataCourse(Course *s);
int deleteCourse(Course *s);
void listCourse(Course *s,int count);
int selectDataNo(Course *s,int count);
void saveData(Course *s, int count);
void loadData(Course *S);
void searchProfessor(Course *s, int count);
void searchMajor(Course *s , int count);
