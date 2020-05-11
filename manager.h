#include<stdio.h>
#include<string.h>

typedef struct{
	char courseName[30];//과목명 저장하는 함수
	char proName[30];//교수님 성함 저장하는 변수
	char major[20];//교양인지 전공인지 구분하는 변수
	int credit;
} Course;

int selectMenu();
int createCourse(Course *s);
void readCourse(Course s);
void updateCourse(Course *s);
int deleteCourse(Course *s);
void listCourse(Course *s,int count);
int selectCourseNo(Course *s,int count);
void saveData(Course *s, int count);
int loadData(Course *s);
void searchProfessor(Course *s, int count);
void searchMajor(Course *s , int count);
void searchName(Course *s,int count);
void searchCredit(Course *s,int count);
