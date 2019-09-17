#include <stdio.h>
#include <stdlib.h>

//육질과 고기의 양으로 고기의 등급을 매기는 프로그램
int main()
{
    int Quantity = 0; // Quantity 을 0으로 초기화
    int Quality = 0;  // Quality 을 0으로 초기화

    printf("input Quality\n");
        scanf("%d",&Quality);  // Quality 를 입력받음
    printf("input Quantity\n");
        scanf("%d",&Quantity); // Quantity 를 입력받음

    Quality = Quality/10;   //Quality 를 10으로 나눈 몫으로 초기화
    Quantity = Quantity/10; //Quantiy 를 10으로 나눈 몫으로 초기화

    if( (Quantity>=7)&&(Quality>=5) )  // Quantity와 Quality의 초기 조건을 정해준다.
    {
        if(Quality>=9)                 //  Quality>=9일경우
        {
        printf("1++%c",('A'+9-Quantity));
        }
        else if(Quality>=8)            // Quality>=8일 경우
        {
        printf("1+%c",('A'+9-Quantity));
        }
        else if(Quality>=7)            // Quality>=7일 경우
        {
        printf("1%c",('A'+9-Quantity));
        }
        else if(Quality>=6)            // Quality>=6일 경우
        {
        printf("2%c",('A'+9-Quantity));
        }
        else if(Quality>=5)            // Quality>=5일 경우
        {
        printf("2%c",('A'+9-Quantity));
        }
    }
    else                               //Quality의 값과 Quantitiy의 값이 처음 조건을 만족하지않은
    {                                  // 경우에 4를 출력 해준다.
    printf("4");
    }

}
