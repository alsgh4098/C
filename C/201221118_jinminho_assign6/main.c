#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>


int main()
{
  int range;    // 선언될 난수의 범위를 설정할 range 선언

  int min = 99; // 최솟값을 구하기 위한 min를 99로 초기화

  int max = 50; // 최대값을 구하기 위한 max를 50으로 초기화

  int i;        // 반복문에 사용할 i 선언

  int minnum;   // 최소값의 순서를 나타낼 minnum 선언

  int maxnum;    // 최대값의 순서를 나타낼 maxnum 선언

  srand(time(NULL));  //실행할 때 마다 다른 난수가 나오는 rand 를 사용하기 위해 선언

  for(i=1;i<=50;i++){       // 50회 반복한다.
    range = rand()%50+50;   //나오는 난수의 범위를 50~99로 정한다.

    printf("%d  ",range);   //난수를 출력한다.
    if((i%10)==0){          // 10개의 난수가 선언될때 마다 줄 바꿈
        printf("\n");
    }

    if(range<min){          //출력되는 난수값들 중 최소값을 구하는 문장
        min = range;
        minnum = i;
    }

    if(max<range){          //출력되는 난수값들 중 최대값을 구하는 문장
        max = range;
        maxnum = i;

    }

  }
    printf("\n최소값%d  순서%d",min,minnum);
    printf("\n최대값%d 순서%d",max,maxnum);
}


