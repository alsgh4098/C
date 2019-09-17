#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print(int arr[], int size);
int bubble(int arr[], int size);
void swapp(int* a, int* b);


int main()
{
    int arr[50];        //50개의 어레이 선언
    int i;              //반복문에서 사용할 변수 선언
    srand(time(NULL));  //값을 정하거나 출력할때 마다 다른 ㅜ값이 나오는 난수 선언

    for(i = 0; i<50; i++)    //반복문 사용
        arr[i] = rand()%20+1;//어레이에 1~20사이의 수를 반복해서 넣는다.

    bubble(arr,50);      //버블 소트함수

    print(arr,50);       //정렬된 난수를 출력하는 함수

    printf("minum : %d\n",arr[0]);          //최소값 arr[0] 출력
    printf("middle point : %d\n",arr[24]);  //중간값 arr[24] 출력
    printf("maximun : %d\n",arr[49]);       //최대값 arr[49] 출력

    return 0;
}

void print(int arr[], int size)
{
    int i;                      //반복문에서 사용할 변수 선언
    for(i = 0; i<size; i++)     //반복문 사용
    {
        printf("%4d",arr[i]);   //어레이안에 있는 변수를 출력해줌
        if((i+1)%10 == 0)       //10개의 난수를 끊어서 라인을 바꿔줌
            printf("\n");
    }
    printf("\n");               //마지막에 추가로 라인을 바꿔줌
}

int bubble(int arr[], int size)
{
    int i,j;                        //반복문에서 사용할 변수 선언
    for(i = 0; i<size-1; i++){      //버블 소트 반복문
        for(j = 0; j<size-i-1; j++)
        {
            if(arr[j] > arr[j+1])
            swapp(&arr[j], &arr[j+1]);//스왑 함수 사용. 어레이 안에 작은 값부터 어레이의 처음값에서 마지막값으로 정렬해준다.
        }
    }
    return 0;
}

void swapp(int* a, int* b)
{
    int temp = 0;   // 값을 임시로 저장할 변수를 선언
    temp = *a;      // temp에 a값을 저장함
    *a = *b;        // a에 b값을 저장함
    *b = temp;      // b에 temp값을 저장함 결과적으로 변수 a와 변수 b에 있는 값이 바뀜.
}
