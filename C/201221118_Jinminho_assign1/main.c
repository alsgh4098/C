#include <stdio.h>
#include <stdlib.h>

int main()
{
 int num1;  //num1~num6���� ���ڸ� �Է¹ޱ� ���� int�� ������ ���� �Ѵ�.
 int num2;
 int num3;
 int num4;
 int num5;
 int num6;

 printf("please enter six numbers:");  // please enter six numbers: �� ��� ���ش�.
 scanf("%4d %4d %4d %4d %4d %4d",&num1,&num2,&num3,&num4,&num5,&num6); // num1~num6���� ���ڸ� �Է� �޴´�. (�ִ� 4�ڸ���)
 printf("\nYour numbers forward:\n"); //Your numbers forward: �� ��� ���ش�.
 printf("  %4d\n  %4d\n  %4d\n  %4d\n  %4d\n  %4d\n",num1,num2,num3,num4,num5,num6); //num1~num6���� ������� ���پ� ���� ������ش�.
 printf("Your numbers reversed:\n"); //Your numbers reversed: �� ��� ���ش�.
 printf("  %4d\n  %4d\n  %4d\n  %4d\n  %4d\n  %4d\n",num6,num5,num4,num3,num2,num1); //num6~num1 ��������� ���پ� ���� ��� ���ش�.

 return 0;
 }

