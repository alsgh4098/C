#include <stdio.h>
#include <stdlib.h>
void reverse_print(int num);

int main()
{
    int number;                                       //number�� ������ �����Ѵ�.
    printf("���ڸ��Է��ϼ���. �Ųٷ� ����մϴ�.\n"); //���α׷� �ȳ� ��Ʈ
    scanf("%d",&number);                              //number�� �Է¹޴´�.
    reverse_print(number);                            //number�� �Լ��� �Է¹޴´�.
    return 0;
}

void reverse_print(int num)                           //reverse_print�Լ��� �����Ѵ�.
{
    if(num==0)                                        //�Լ��� ���� ������ ���Ѵ�.
      return 0;

    else{                                             //�Լ��� ������ �����ϸ� �ݺ��Ǵ� ������ ���Ѵ�.
    printf("%d",num%10);                              //num%10�� ����Ѵ�.
    num = num/10;
    return reverse_print(num);
    }

 return 0;
}
