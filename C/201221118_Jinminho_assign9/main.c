#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print(int arr[], int size);
int bubble(int arr[], int size);
void swapp(int* a, int* b);


int main()
{
    int arr[50];        //50���� ��� ����
    int i;              //�ݺ������� ����� ���� ����
    srand(time(NULL));  //���� ���ϰų� ����Ҷ� ���� �ٸ� �̰��� ������ ���� ����

    for(i = 0; i<50; i++)    //�ݺ��� ���
        arr[i] = rand()%20+1;//��̿� 1~20������ ���� �ݺ��ؼ� �ִ´�.

    bubble(arr,50);      //���� ��Ʈ�Լ�

    print(arr,50);       //���ĵ� ������ ����ϴ� �Լ�

    printf("minum : %d\n",arr[0]);          //�ּҰ� arr[0] ���
    printf("middle point : %d\n",arr[24]);  //�߰��� arr[24] ���
    printf("maximun : %d\n",arr[49]);       //�ִ밪 arr[49] ���

    return 0;
}

void print(int arr[], int size)
{
    int i;                      //�ݺ������� ����� ���� ����
    for(i = 0; i<size; i++)     //�ݺ��� ���
    {
        printf("%4d",arr[i]);   //��̾ȿ� �ִ� ������ �������
        if((i+1)%10 == 0)       //10���� ������ ��� ������ �ٲ���
            printf("\n");
    }
    printf("\n");               //�������� �߰��� ������ �ٲ���
}

int bubble(int arr[], int size)
{
    int i,j;                        //�ݺ������� ����� ���� ����
    for(i = 0; i<size-1; i++){      //���� ��Ʈ �ݺ���
        for(j = 0; j<size-i-1; j++)
        {
            if(arr[j] > arr[j+1])
            swapp(&arr[j], &arr[j+1]);//���� �Լ� ���. ��� �ȿ� ���� ������ ����� ó�������� ������������ �������ش�.
        }
    }
    return 0;
}

void swapp(int* a, int* b)
{
    int temp = 0;   // ���� �ӽ÷� ������ ������ ����
    temp = *a;      // temp�� a���� ������
    *a = *b;        // a�� b���� ������
    *b = temp;      // b�� temp���� ������ ��������� ���� a�� ���� b�� �ִ� ���� �ٲ�.
}
