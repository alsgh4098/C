#include <stdio.h>
#include <stdlib.h>
void reverse_print(int num);

int main()
{
    int number;                                       //number를 변수로 선언한다.
    printf("숫자를입력하세요. 거꾸로 출력합니다.\n"); //프로그램 안내 멘트
    scanf("%d",&number);                              //number를 입력받는다.
    reverse_print(number);                            //number를 함수에 입력받는다.
    return 0;
}

void reverse_print(int num)                           //reverse_print함수를 선언한다.
{
    if(num==0)                                        //함수의 멈춤 조건을 정한다.
      return 0;

    else{                                             //함수가 조건을 만족하면 반복되는 설정을 정한다.
    printf("%d",num%10);                              //num%10을 출력한다.
    num = num/10;
    return reverse_print(num);
    }

 return 0;
}
