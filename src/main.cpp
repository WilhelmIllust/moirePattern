#include"gradient.h"
int main(){
	//createGradient();
	/*Mat input=imread("Lenna.png");
	cvtColor(input, input, CV_BGR2BGRA);
	input.convertTo(input, CV_64F, 1);
	input /= 255;
	//imshow("aa", input);
	//createGradient();
	//createPattern(input);
	createPattern(input);*/

	//as
	createGradient();
	vector<string> inputsNames = { "giphy-1_frame_0001.jpg",
		"giphy-1_frame_0002.jpg",
		"giphy-1_frame_0003.jpg",
		"giphy-1_frame_0004.jpg",
		"giphy-1_frame_0005.jpg",
		"giphy-1_frame_0006.jpg",
		"giphy-1_frame_0007.jpg"
	};
	/*vector<string> inputsNames = { "test1.jpg",
		"test2.jpg",
		"test3.jpg",
		"test4.jpg"
	};*/
	vector<Mat> inputs;
	for (int i = 0; i < inputsNames.size(); i++){
		Mat inputTmp = imread(inputsNames[i]);
		cvtColor(inputTmp, inputTmp, CV_BGR2BGRA);
		inputTmp.convertTo(inputTmp, CV_64F, 1);
		inputTmp /= 255;
		inputs.push_back(inputTmp);
	}
	createPattern(inputs);
	
	//waitKey(0);
	//system("pause");
}