#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float calculateEuclideanDisatance(float x1,float y1,float x2,float y2); //calculateEuclideanDisatance �Լ��� �����Ѵ�.
float calculateManhattanDisatance(float x1,float y1,float x2,float y2); //calculateManhattanDisatance �Լ��� �����Ѵ�.

int main()
{
    float x1 = 0.0; //float ������ x1�� 0.0���� �ʱ�ȭ �Ѵ�.
    float x2 = 0.0; //float ������ x2�� 0.0���� �ʱ�ȭ �Ѵ�.
    float y1 = 0.0; //float ������ y1�� 0.0���� �ʱ�ȭ �Ѵ�.
    float y2 = 0.0; //float ������ y2�� 0.0���� �ʱ�ȭ �Ѵ�.

    printf("Input your first point<x1 y1> : ");  // Input your first point<x1 y1> :���� ����Ѵ�.
    scanf("%f %f",&x1,&y1);                      // x1���� y1���� �޴´�.
    printf("Input your second point<x2 y2> : "); // Input your second point<x1 y1> :���� ����Ѵ�.
    scanf("%f %f",&x2,&y2);                      // x2���� y2���� �޴´�.

    printf("Euclidean distance : %.2f\n",calculateEuclideanDisatance(x1,y1,x2,y2));   //Euclidean distance : 'calculateEuclideanDistance�� ������ ��'�� ����Ѵ�.
    printf("Manhattan distance : %.2f\n",calculateManhattanDisatance(x1,y1,x2,y2));   //Euclidean distance : 'calculateManhattanDistance�� ������ ��'�� ����Ѵ�.

}

float calculateEuclideanDisatance(float p1,float p2,float q1,float q2)  //calculateEuclideanDisatance �Լ��� �����Ѵ�.
{

  return sqrt(pow(p1-q1,2)+pow(p2-q2,2));                               //sqrt(pow(p1-q1,2)+pow(p2-q2,2)) ���� �����Ѵ�.

}

float calculateManhattanDisatance(float p1,float p2,float q1,float q2) //calculateManhattanDisatance �Լ��� �����Ѵ�.
{

 return abs(p1-q1)+abs(p2-q2);                                         //abs(p1-q1)+abs(q2-q2) ���� �����Ѵ�.

}
