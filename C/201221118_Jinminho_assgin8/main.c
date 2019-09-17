#include <stdio.h>
#include <stdlib.h>
char to_up(char lower);

int main()
{
    FILE* file1; //file1을 포인터파일로 설정.
    FILE* file2; //file1을 포인터파일로 설정.
    char lowch;  //문자를 읽어올 lowch변수를 설정.

    file1 = fopen("one.txt","r");           //file1에 one.txt를 read mode로 설정.
        if(file1==NULL) return -1;          //파일을 읽는데 에러가 날 경우 -1을 리턴.
    file2 = fopen("another.txt","w");       //file2에 another.txt를 write mode로 설정.

    while(fscanf(file1,"%c",&lowch)!=EOF){  //file1에서 문자형을 입력받음. EOF값이 나오기 전까지!
      fprintf(file2,"%c",to_up(lowch));     //그동안 file2에 문자형을 대문자로 바꿔서 입력함.
    }


    fclose(file1);      //file1포인터 종료.
    fclose(file2);      //file2포인터 종료.
}

char to_up(char lower)
{
    char upper;     //대문자로 바꿔서 입력받을 변수설정.
    if((97<=lower)&&(lower<=122)){ //조건은 소문자일 경우만.
        upper = lower-32;
        return upper;
    }
    return lower;
    //소문자를 대문자로 바꿔주는 함수. 대문자를 입력받을 경우 그대로 대문자로 출력.
}
