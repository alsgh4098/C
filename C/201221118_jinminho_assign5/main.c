#include <stdio.h>
#include <stdlib.h>

//������ ����� ������ ����� ����� �ű�� ���α׷�
int main()
{
    int Quantity = 0; // Quantity �� 0���� �ʱ�ȭ
    int Quality = 0;  // Quality �� 0���� �ʱ�ȭ

    printf("input Quality\n");
        scanf("%d",&Quality);  // Quality �� �Է¹���
    printf("input Quantity\n");
        scanf("%d",&Quantity); // Quantity �� �Է¹���

    Quality = Quality/10;   //Quality �� 10���� ���� ������ �ʱ�ȭ
    Quantity = Quantity/10; //Quantiy �� 10���� ���� ������ �ʱ�ȭ

    if( (Quantity>=7)&&(Quality>=5) )  // Quantity�� Quality�� �ʱ� ������ �����ش�.
    {
        if(Quality>=9)                 //  Quality>=9�ϰ��
        {
        printf("1++%c",('A'+9-Quantity));
        }
        else if(Quality>=8)            // Quality>=8�� ���
        {
        printf("1+%c",('A'+9-Quantity));
        }
        else if(Quality>=7)            // Quality>=7�� ���
        {
        printf("1%c",('A'+9-Quantity));
        }
        else if(Quality>=6)            // Quality>=6�� ���
        {
        printf("2%c",('A'+9-Quantity));
        }
        else if(Quality>=5)            // Quality>=5�� ���
        {
        printf("2%c",('A'+9-Quantity));
        }
    }
    else                               //Quality�� ���� Quantitiy�� ���� ó�� ������ ������������
    {                                  // ��쿡 4�� ��� ���ش�.
    printf("4");
    }

}
