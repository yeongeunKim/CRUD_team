#include "manager.h"

int main(){
    Course s[100];
    int count=0;
    int num;
    count=loadData(s);

    while(1){
        int menu=selectMenu();
        if(menu==0) break;

        if(menu==1)
        {
            if(count>0)
            listCourse(s,count);
            else 
            printf("데이터가 없습니다.");
            }
        else if(menu==2){
            count+=createCourse(&s[count++]);
        }
        else if(menu==3){
            int no=selectCourseNo(s,count);
            if(no==0){
                printf("취소됨!\n");
                continue;
            }
            updateCourse(&s[count-1]);
        }
        else if(menu==4){
            int no=selectCourseNo(s,count);
            if(no==0){
                printf("취소됨!\n");
                continue;
            }
            int dok;
            printf("정말로 삭제하시겠습니까?(삭제:1)");
            scanf("%d",&dok);
            if(dok==1){
            if (deleteCourse(&s[no-1])){
                count--;
            }
            }
        }
        else if(menu==5){
            if(count==0)printf("데이터가 없습니다 !");
            else{
            saveData(s,count);
            }
        }
        else if(menu==6){
            searchName(s,count);
        }
        else if(menu==7){
            searchProfessor(s,count);
        }
         else if(menu==8){
            searchCredit(s,count);
        }
	else if(menu == 9){
		searchMajor(s,count);
	}
        

    }

    printf("종료됨!\n");
    return 0;
}
