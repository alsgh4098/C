#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>


int main()
{
  int range;    // ����� ������ ������ ������ range ����

  int min = 99; // �ּڰ��� ���ϱ� ���� min�� 99�� �ʱ�ȭ

  int max = 50; // �ִ밪�� ���ϱ� ���� max�� 50���� �ʱ�ȭ

  int i;        // �ݺ����� ����� i ����

  int minnum;   // �ּҰ��� ������ ��Ÿ�� minnum ����

  int maxnum;    // �ִ밪�� ������ ��Ÿ�� maxnum ����

  srand(time(NULL));  //������ �� ���� �ٸ� ������ ������ rand �� ����ϱ� ���� ����

  for(i=1;i<=50;i++){       // 50ȸ �ݺ��Ѵ�.
    range = rand()%50+50;   //������ ������ ������ 50~99�� ���Ѵ�.

    printf("%d  ",range);   //������ ����Ѵ�.
    if((i%10)==0){          // 10���� ������ ����ɶ� ���� �� �ٲ�
        printf("\n");
    }

    if(range<min){          //��µǴ� �������� �� �ּҰ��� ���ϴ� ����
        min = range;
        minnum = i;
    }

    if(max<range){          //��µǴ� �������� �� �ִ밪�� ���ϴ� ����
        max = range;
        maxnum = i;

    }

  }
    printf("\n�ּҰ�%d  ����%d",min,minnum);
    printf("\n�ִ밪%d ����%d",max,maxnum);
}


