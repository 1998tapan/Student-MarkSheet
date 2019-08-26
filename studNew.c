#include<stdio.h>
#include<conio.h>
#define SIZE 3

struct Student{
    int id;
    char name[30];
    float fees,per;
    int sub1,sub2,sub3;
    char grade;
    int flag;
}s[SIZE];

void scanStudentDetails();
void printStudentDetails();
int searchStudentDetails(int);
void updateStudentDetails();
void deleteStudentDetails();
void reactivateRecords();


void main(){
    int choice,flag=-1;
    clrscr();
    while(1){
            printf("\n1.Scan details");
            printf("\n2.Print details");
            printf("\n3.Search by ID");
            printf("\n4.Update");
            printf("\n5.Delete record");
            printf("\n6.Reactivate record");
            printf("\nEnter your choice:\n");
            scanf("%d",&choice);    
            switch (choice)
            {
                case 0:
                    exit(0);

                case 1: 
                    flag=0;
                    printf("\nScanning details...");
                    scanStudentDetails();
                    break;
                
                case 2:
                    if(flag==-1){
                        printf("\nNo records found...Scan the records first");
                        getch();
                    }
                    else{
                        printf("\nPrinting student details");
                        printf("\nSID \t SNAME \t SFEES \t SUB1 \t SUB 2 \t SUB3 \t PER \t GRADE");
                        printStudentDetails();
                    }
                    break;

                case 3:
                         /*if(flag==-1){
                            printf("\nNo records found...Scan the records first");
                            getch();
                        }
                        else{
                            printf("\n Search by ID");
                            searchStudentDetails();
                        }*/
                        break;
                 case 4:
                         if(flag==-1){
                            printf("\nNo records found...Scan the records first");
                            getch();
                        }
                        else{
                            printf("Update record");
                            updateStudentDetails();
                        }
                        break;
                case 5:
                         if(flag==-1){
                            printf("\nNo records found...Scan the records first");
                            getch();
                        }
                        else{
                            printf("\nDelete record");
                            deleteStudentDetails();
                        }
                        break;
                case 6:
                        reactivateRecords();
                        break;
                default:
                    printf("\nWrong choice");
                    break;
            }//end of switch

    }//end of while loop

}//end of main

void scanStudentDetails(){
    float temp;
    int i;
    for(i=0;i<SIZE;i++){
        printf("\nEnter student id for %d student:",i);
        scanf("%d",&s[i].id);
        fflush(stdin);
        printf("\nEnter student name for %d student:",i);
        scanf("%s",s[i].name);
        fflush(stdin);
        printf("\nEnter student fees for %d student:",i);
        scanf("%f",&temp);
        s[i].fees=temp;
        fflush(stdin);
        s[i].flag=0;
        printf("Enter marks for first subject for %d student",i);
        scanf("%d",&s[i].sub1);
        //printf("\ns1: %d",s[i].sub1);
        //fflush(stdin);
        printf("Enter marks for second subject for %d student",i);
        scanf("%d",&s[i].sub2);
        //fflush(stdin);
        printf("Enter marks for third subject for %d student",i);
        scanf("%d",&s[i].sub3);
        //fflush(stdin);
        s[i].per=((s[i].sub1 + s[i].sub2 + s[i].sub3)/3);
        if(s[i].per >=33 && s[i].per< 45){
            s[i].grade='D';
        }
        else if(s[i].per >=45 && s[i].per< 60){
            s[i].grade='C';
        }
        else if(s[i].per >= 60 && s[i].per < 75){
            s[i].grade='B';
        }
        else{
            s[i].grade='A';
        }
    }//END OF FOR SCAN

}//end of scan method

void printStudentDetails(){
    int i;
    for(i=0;i<SIZE;i++){
        if(s[i].flag==0){
            printf("\n%d \t %s \t %.2f \t %d \t %d \t %d \t %.2f \t %c", s[i].id, s[i].name, s[i].fees, s[i].sub1, s[i].sub2, s[i].sub3, s[i].per, s[i].grade);    
        }
    }//end of for print
}//end of print method

int searchStudentDetails(int searchid){
    int i,index=-1;
    for (i=0;i<SIZE;i++){
        if(s[i].id==searchid){
            index=i;
            break;
        }
    }
    return index;
   /* int searchid;
    printf("\nEnter the search id");
    scanf("%d",&searchid);
    searchid-=1;
    printf("\nSID \t SNAME \t SFEES \t SUB1 \t SUB 2 \t SUB3 \t PER \t GRADE");
    printf("\n%d \t %s \t %.2f \t %d \t %d \t %d \t %.2f \t %c", s[searchid].id, s[searchid].name, s[searchid].fees, s[searchid].sub1, s[searchid].sub2, s[searchid].sub3, s[searchid].per, s[searchid].grade);8*/
}

void updateStudentDetails(){
    int upid;
    float temp;
    printf("\nEnter the id to be updated");
    scanf("%d",&upid);
    upid=searchStudentDetails(upid);
    if(upid==-1){
        printf("The record doesn't exist...");
    }
    else
    {
        printf("\nEnter student name for %d student:",upid);
        scanf("%s",s[upid].name);
        fflush(stdin);
        printf("\nEnter student fees for %d student:",upid);
        scanf("%f",&temp);
        s[upid].fees=temp;
        fflush(stdin);
        printf("Enter marks for first subject for %d student",upid);
        scanf("%d",&s[upid].sub1);
        printf("Enter marks for second subject for %d student",upid);
        scanf("%d",&s[upid].sub2);
        printf("Enter marks for third subject for %d student",upid);
        scanf("%d",&s[upid].sub3);
        s[upid].per=((s[upid].sub1 + s[upid].sub2 + s[upid].sub3)/3);
        if(s[upid].per >=33 && s[upid].per< 45){
            s[upid].grade='D';
        }
        else if(s[upid].per >=45 && s[upid].per< 60){
            s[upid].grade='C';
        }
        else if(s[upid].per >= 60 && s[upid].per < 75){
            s[upid].grade='B';
        }
        else{
            s[upid].grade='A';
        }
        printf("\nRecord updated!");
    }
    
    /*int upid;
    float temp;
    printf("\nEnter the update id");
    scanf("%d",&upid);
    upid-=1;
    printf("\nEnter student name for %d student:",upid);
    scanf("%s",s[upid].name);
    fflush(stdin);
    printf("\nEnter student fees for %d student:",upid);
    scanf("%f",&temp);
    s[upid].fees=temp;
    fflush(stdin);
    printf("Enter marks for first subject for %d student",upid);
    scanf("%d",&s[upid].sub1);
    //printf("\ns1: %d",s[i].sub1);
    //fflush(stdin);
    printf("Enter marks for second subject for %d student",upid);
    scanf("%d",&s[upid].sub2);
    //fflush(stdin);
    printf("Enter marks for third subject for %d student",upid);
    scanf("%d",&s[upid].sub3);
    //fflush(stdin);
    s[upid].per=((s[upid].sub1 + s[upid].sub2 + s[upid].sub3)/3);
    if(s[upid].per >=33 && s[upid].per< 45){
        s[upid].grade='D';
    }
    else if(s[upid].per >=45 && s[upid].per< 60){
        s[upid].grade='C';
    }
    else if(s[upid].per >= 60 && s[upid].per < 75){
        s[upid].grade='B';
    }
    else{
        s[upid].grade='A';
    }
    printf("\nRecord updated!");*/
}

void deleteStudentDetails(){
    int delid;
    printf("\nEnter the delete id");
    scanf("%d",&delid);
    delid=searchStudentDetails(delid);
    if(delid==-1){
        printf("\nThe record doesn't exist...");
    }
    //delid-=1;
    s[delid].flag=-1;
    printf("\nRecord Deleted!");
}

void reactivateRecords(){
    int reid;
    printf("\nEnter the deleted record you wish to reinstate");
    scanf("%d",&reid);
    reid=searchStudentDetails(reid);
    if(reid==-1){
        printf("\nRecord doesn't exist...");
    }
    if(s[reid].flag==0){
        printf("\nRecord is already active...");
    }
    else{
        s[reid].flag=0;
        printf("\nReactivation successfull !");
    }
}