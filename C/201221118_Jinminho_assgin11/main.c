#include <stdio.h>
#include <stdlib.h>

int myStrlen(char* str);    //길이재는 함수 선언.
char* myStrrev(char* str);  //myStrrev 함수 선언.

int main()
{
    char str[] = "hello world.";    // str에 hello world 저장.
    printf("%s", myStrrev(str));    // myStrrev(str) 출력.

    return 0;               //return.
}

int myStrlen(char* str)     // myStrrev(str) 선언.
{
    int i = 0;

    while(str[i] != '\0')   //str 길이재는 함수 선언.
    {
        i++;
    }

    return i;
}

char* myStrrev(char* str)
{
    int i = 0;
    int num = 0;
    num = myStrlen(str);        // 저는 새로운 배열을 하나 만들어서 통채로 옮겼다가 반대로 다시 옮겼습니다.
    char* temp;
    for(i = 0; i<num; i++)
        temp[i] = str[num-1-i];

    for(i = 0; i<num; i++)
        str[i] = temp[i];
    return str;
}
