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
//#define functionPhi (x*x*x)//奇怪的圖形
//#define functionPhi (acos(y/sqrt(x*x+y*y)))*64//拍打翅膀的感覺
//#define functionPhi (cos(x)*cos(x)+sin(x)*sin(x))//奇怪的圖形
//#define functionPhi (128*asin(x/sqrt(x*x+y*y)))//接近旋轉了
//#define functionPhi (64*x/(sqrt(x*x+y*y))+64*y/sqrt(x*x+y*y))
//#define functionPhi (x-y)//斜的s
#define functionPhi (x)
//#define functionPhi (128*atan(y/x))  //輻射，因為是X和Y成比例，用其他方法算規律
//#define functionPhi (y/x)  //輻射，因為是X和Y成比例，用其他方法算規律
//#define functionPhi (atan(y/(x*x))*32)  //奇怪的圖形
//#define functionPhi (atan((y*y)/(x*x))*32)  //奇怪的輻射
//#define functionPhi (atan(y/(x+sin(sqrt(x*x+y*y))))*32)  //波狀輻射
//#define functionPhi (1/asin(x/32)) //奇怪的圖形
//#define functionPhi (atan(x*x+y*y)*16) //同心圓
//#define functionPhi (atan(sqrt(x*x+y*y))*16) //同心圓
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