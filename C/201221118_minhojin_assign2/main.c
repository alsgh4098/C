#include <stdio.h>

int main()
{
  double x1=0.0; // x1 ���� �Ǽ��� �Է¹ޱ� ���� double�� ������ �����Ѵ�.
  double x2=0.0; // x2 ���� �Ǽ��� �Է¹ޱ� ���� double�� ������ �����Ѵ�.
  double y1=0.0; // y1 ���� �Ǽ��� �Է¹ޱ� ���� double�� ������ �����Ѵ�.
  double y2=0.0; // y2 ���� �Ǽ��� �Է¹ޱ� ���� double�� ������ �����Ѵ�.

  printf("please enter two points on the plane(x,y)\n");  //please enter two points on the plane(x,y)�� ��� ���ش�.
  printf("first point: ");scanf("%lf%lf",&x1,&y1);  //first point:�� ������ְ� x1��y1 �� �Ǽ��� �Է� �޴´�.
  printf("second point: ");scanf("%lf%lf",&x2,&y2);  //second point:�� ������ְ� x2��y2 �� �Ǽ��� �Է� �޴´�.
  printf("slope of the two points is %.2lf",((y2-y1)/(x2-x1)));  //slope of the two points is %.2f�� ������ְ� %.2f �ڸ����� (y2-y1)/(x2-x1) ������� �Ҽ� ��°�ڸ����� ��Ÿ���ش�.





}

