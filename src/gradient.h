#ifndef GRADIENT_H
#define GRADIENT_H

#define WINVER 0x600
#undef UNICODE
#undef _UNICODE

#define regular 1
#define myPi 3.14159265359
#define picWidth 400
#define picHeight 400

//range:[0,1]
//periods:2*pi
//#define functionPhi (sqrt(x*x*100+y))
//#define functionPhi (sqrt(x*x+y*y))
//#define functionPhi (sqrt(x*x/2+y*y))
//#define functionPhi (x*x*x)//�_�Ǫ��ϧ�
//#define functionPhi (acos(y/sqrt(x*x+y*y)))*64//�祴�ͻH���Pı
//#define functionPhi (cos(x)*cos(x)+sin(x)*sin(x))//�_�Ǫ��ϧ�
//#define functionPhi (128*asin(x/sqrt(x*x+y*y)))//�������F
//#define functionPhi (64*x/(sqrt(x*x+y*y))+64*y/sqrt(x*x+y*y))
//#define functionPhi (x-y)//�ת�s
#define functionPhi (x)
//#define functionPhi (128*atan(y/x))  //��g�A�]���OX�MY����ҡA�Ψ�L��k��W��
//#define functionPhi (y/x)  //��g�A�]���OX�MY����ҡA�Ψ�L��k��W��
//#define functionPhi (atan(y/(x*x))*32)  //�_�Ǫ��ϧ�
//#define functionPhi (atan((y*y)/(x*x))*32)  //�_�Ǫ���g
//#define functionPhi (atan(y/(x+sin(sqrt(x*x+y*y))))*32)  //�i����g
//#define functionPhi (1/asin(x/32)) //�_�Ǫ��ϧ�
//#define functionPhi (atan(x*x+y*y)*16) //�P�߶�
//#define functionPhi (atan(sqrt(x*x+y*y))*16) //�P�߶�
//#define functionPhi  (asin(y/x))

#define function_r(x) (cos(x) / 2+0.5)

#include<stdio.h>
#include<direct.h>
#include<iostream>
#include<string>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "math.h"

using namespace std;
using namespace cv;


double phiOfXAndY(double y, double x);

double rOfX(double phi);

void createGradient();
void createGradientAnime();
void createPattern(Mat&input);
void createPattern(vector<Mat>&inputs);
void createPatternAnime(Mat&input);

#endif