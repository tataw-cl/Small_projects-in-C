//C program to create and implement a digital clock..
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
int main(){
    int hour,minute,second=0;
    system("cls");
    printf("Enter a time format to start from in hour:minute:seconds\n");

    scanf("%d%d%d", &hour,&minute,&second);
    start:
        if(second==60){
            minute+=1;
             second=0;
        }
        if(minute==60){
            hour+=1;
            minute=0;
            second=0;
        }
        if (hour==24)
        {
             hour=0;
            minute=0;
            second=0;
        }
        char d[20];
        if (hour<13){
            strcpy(d, "AM");
        }
        else{
            strcpy(d,"PM");
        }
        
        
   second++;
   system("cls");
   printf("\t\t\t %d:%d:%d %s",hour,minute,second,d);
   sleep(1);
   goto start;
    return 0;
}