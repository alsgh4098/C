#include <stdio.h>
#include <stdlib.h>

int myStrlen(char* str);    //������� �Լ� ����.
char* myStrrev(char* str);  //myStrrev �Լ� ����.

int main()
{
    char str[] = "hello world.";    // str�� hello world ����.
    printf("%s", myStrrev(str));    // myStrrev(str) ���.

    return 0;               //return.
}

int myStrlen(char* str)     // myStrrev(str) ����.
{
    int i = 0;

    while(str[i] != '\0')   //str ������� �Լ� ����.
    {
        i++;
    }

    return i;
}

char* myStrrev(char* str)
{
    int i = 0;
    int num = 0;
    num = myStrlen(str);        // ���� ���ο� �迭�� �ϳ� ���� ��ä�� �Ű�ٰ� �ݴ�� �ٽ� �Ű���ϴ�.
    char* temp;
    for(i = 0; i<num; i++)
        temp[i] = str[num-1-i];

    for(i = 0; i<num; i++)
        str[i] = temp[i];
    return str;
}
