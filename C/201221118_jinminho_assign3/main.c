#include <stdio.h>
#include <stdlib.h>

int main()
{
    int score = 0; // score ���� 0���� ���� �ش�.
    printf("Input your score : ",score); // ������ �Է����ּ���(���� 99~60)
    scanf("%d",&score); // ������ �Է� �޴´�.
    score ='A'+(9-score/10); // 'A'�� 1�� �����ָ� 'B' 'C' 'D'�� ������ ����
    printf("\nYour grade is %c",score); // A (99~90) B (89~80) C (79~70)  D(69~60)



}
