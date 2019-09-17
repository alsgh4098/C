#include <stdio.h>
#include <stdlib.h>

int main()
{
    int score = 0; // score 값을 0으로 정해 준다.
    printf("Input your score : ",score); // 점수를 입력해주세요(범위 99~60)
    scanf("%d",&score); // 점수를 입력 받는다.
    score ='A'+(9-score/10); // 'A'에 1씩 더해주면 'B' 'C' 'D'가 나오는 원리
    printf("\nYour grade is %c",score); // A (99~90) B (89~80) C (79~70)  D(69~60)



}
