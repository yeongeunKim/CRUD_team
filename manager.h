#include<stdio.h>
#include<string.h>

typedef struct{
	char courseName[30];
	char proName[30];
	int credit;
} Course;

int creatCourse(Course *s);
void readCourse(Course *s);
void listCourse(Course *s,int count);
int selectDataNo(Course *s,int count);
void saveData(Course *s, int count);
void searchExchange(Course *s,int count);
void searchProfessor(Course *s, int count);
