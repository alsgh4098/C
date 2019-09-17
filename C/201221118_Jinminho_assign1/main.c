#include <stdio.h>
#include <stdlib.h>

int main()
{
 int num1;  //num1~num6까지 숫자를 입력받기 위한 int형 변수로 선언 한다.
 int num2;
 int num3;
 int num4;
 int num5;
 int num6;

 printf("please enter six numbers:");  // please enter six numbers: 를 출력 해준다.
 scanf("%4d %4d %4d %4d %4d %4d",&num1,&num2,&num3,&num4,&num5,&num6); // num1~num6까지 숫자를 입력 받는다. (최대 4자리수)
 printf("\nYour numbers forward:\n"); //Your numbers forward: 를 출력 해준다.
 printf("  %4d\n  %4d\n  %4d\n  %4d\n  %4d\n  %4d\n",num1,num2,num3,num4,num5,num6); //num1~num6까지 순서대로 한줄씩 띄우고 출력해준다.
 printf("Your numbers reversed:\n"); //Your numbers reversed: 를 출력 해준다.
 printf("  %4d\n  %4d\n  %4d\n  %4d\n  %4d\n  %4d\n",num6,num5,num4,num3,num2,num1); //num6~num1 역순서대로 한줄씩 띄우고 출력 해준다.

 return 0;
 }

