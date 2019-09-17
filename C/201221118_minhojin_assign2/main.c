#include <stdio.h>

int main()
{
  double x1=0.0; // x1 값을 실수로 입력받기 위해 double형 변수로 선언한다.
  double x2=0.0; // x2 값을 실수로 입력받기 위해 double형 변수로 선언한다.
  double y1=0.0; // y1 값을 실수로 입력받기 위해 double형 변수로 선언한다.
  double y2=0.0; // y2 값을 실수로 입력받기 위해 double형 변수로 선언한다.

  printf("please enter two points on the plane(x,y)\n");  //please enter two points on the plane(x,y)를 출력 해준다.
  printf("first point: ");scanf("%lf%lf",&x1,&y1);  //first point:를 출력해주고 x1과y1 을 실수로 입력 받는다.
  printf("second point: ");scanf("%lf%lf",&x2,&y2);  //second point:를 출력해주고 x2과y2 를 실수로 입력 받는다.
  printf("slope of the two points is %.2lf",((y2-y1)/(x2-x1)));  //slope of the two points is %.2f를 출력해주고 %.2f 자리에는 (y2-y1)/(x2-x1) 결과값을 소수 둘째자리까지 나타내준다.





}

