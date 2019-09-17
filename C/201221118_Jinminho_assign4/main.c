#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float calculateEuclideanDisatance(float x1,float y1,float x2,float y2); //calculateEuclideanDisatance 함수를 섬언한다.
float calculateManhattanDisatance(float x1,float y1,float x2,float y2); //calculateManhattanDisatance 함수를 선언한다.

int main()
{
    float x1 = 0.0; //float 형태의 x1을 0.0으로 초기화 한다.
    float x2 = 0.0; //float 형태의 x2를 0.0으로 초기화 한다.
    float y1 = 0.0; //float 형태의 y1을 0.0으로 초기화 한다.
    float y2 = 0.0; //float 형태의 y2를 0.0으로 초기화 한다.

    printf("Input your first point<x1 y1> : ");  // Input your first point<x1 y1> :문을 출력한다.
    scanf("%f %f",&x1,&y1);                      // x1값과 y1값을 받는다.
    printf("Input your second point<x2 y2> : "); // Input your second point<x1 y1> :문을 출력한다.
    scanf("%f %f",&x2,&y2);                      // x2값과 y2값을 받는다.

    printf("Euclidean distance : %.2f\n",calculateEuclideanDisatance(x1,y1,x2,y2));   //Euclidean distance : 'calculateEuclideanDistance를 실행한 값'을 출력한다.
    printf("Manhattan distance : %.2f\n",calculateManhattanDisatance(x1,y1,x2,y2));   //Euclidean distance : 'calculateManhattanDistance를 실행한 값'을 출력한다.

}

float calculateEuclideanDisatance(float p1,float p2,float q1,float q2)  //calculateEuclideanDisatance 함수를 정의한다.
{

  return sqrt(pow(p1-q1,2)+pow(p2-q2,2));                               //sqrt(pow(p1-q1,2)+pow(p2-q2,2)) 값을 리턴한다.

}

float calculateManhattanDisatance(float p1,float p2,float q1,float q2) //calculateManhattanDisatance 함수를 정의한다.
{

 return abs(p1-q1)+abs(p2-q2);                                         //abs(p1-q1)+abs(q2-q2) 값을 리턴한다.

}
