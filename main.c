nclude "manager.h"

int main(){
    Course c[100];
    int count=0;
    int num;
    count=loadData(c);

    while(1){
        int menu=selectMenu();
        if(menu==0) break;

        if(menu==1)
        {
            if(count>0)
            listCourse(c,count);
            else 
            printf("데이터가 없습니다.");
            }
        else if(menu==2){
            count+=createCourse(&c[count++]);
        }
        else if(menu==3){
            int no=selectCourseNo(c,count);
            if(no==0){
                printf("취소됨!\n");
                continue;
            }
            updateCourse(&c[count-1]);
        }
        else if(menu==4){
            int no=selectCourseNo(c,count);
            if(no==0){
                printf("취소됨!\n");
                continue;
            }
            int dok;
            printf("정말로 삭제하시겠습니까?(삭제:1)");
            scanf("%d",&dok);
            if(dok==1){
            if (deleteCourse(&c[no-1])){
                count--;
            }
            }
        }
        else if(menu==5){
            if(count==0)printf("데이터가 없습니다 !");
            else{
            saveData(c,count);
            }
        }
        else if(menu==6){
            searchName(c,count);
        }
        else if(menu==7){
            searchProfessor(c,count);
        }
         else if(menu==8){
            searchCredit(c,count);
        }
        

    }

    printf("종료됨!\n");
    return 0;
}
