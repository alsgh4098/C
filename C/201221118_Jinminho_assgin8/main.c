#include <stdio.h>
#include <stdlib.h>
char to_up(char lower);

int main()
{
    FILE* file1; //file1�� ���������Ϸ� ����.
    FILE* file2; //file1�� ���������Ϸ� ����.
    char lowch;  //���ڸ� �о�� lowch������ ����.

    file1 = fopen("one.txt","r");           //file1�� one.txt�� read mode�� ����.
        if(file1==NULL) return -1;          //������ �дµ� ������ �� ��� -1�� ����.
    file2 = fopen("another.txt","w");       //file2�� another.txt�� write mode�� ����.

    while(fscanf(file1,"%c",&lowch)!=EOF){  //file1���� �������� �Է¹���. EOF���� ������ ������!
      fprintf(file2,"%c",to_up(lowch));     //�׵��� file2�� �������� �빮�ڷ� �ٲ㼭 �Է���.
    }


    fclose(file1);      //file1������ ����.
    fclose(file2);      //file2������ ����.
}

char to_up(char lower)
{
    char upper;     //�빮�ڷ� �ٲ㼭 �Է¹��� ��������.
    if((97<=lower)&&(lower<=122)){ //������ �ҹ����� ��츸.
        upper = lower-32;
        return upper;
    }
    return lower;
    //�ҹ��ڸ� �빮�ڷ� �ٲ��ִ� �Լ�. �빮�ڸ� �Է¹��� ��� �״�� �빮�ڷ� ���.
}
