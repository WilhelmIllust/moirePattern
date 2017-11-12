#include"gradient.h"

/*In order to match the function of rOfX, it's a function to generate a scale from 0 to 1.
*/

int sliderValue(0);
double shifter(1);
double Offset(0);

double phiOfXAndY(double y,double x)
{
	x = (x - picWidth / 2) / regular;
	y = (y - picHeight / 2) / regular;
	return functionPhi;
}
/*It's a function to generate a scale from 0 to 1.
*/
double rOfX(double phi){
	//double tmp = cos(0);
	return function_r(phi);
}

void createGradient(){
	Mat thisIsAGradient(picHeight, picWidth, CV_64FC1);
	Mat converted2CV_8U;
	for (int y = 0; y < thisIsAGradient.rows; y++){
		for (int x = 0; x < thisIsAGradient.cols; x++){
			thisIsAGradient.at<double>(y, x) = rOfX(phiOfXAndY(y, x));
		}
	}
	thisIsAGradient.convertTo(converted2CV_8U, CV_8U,255);
	imwrite("thisIsAGradient1.png", converted2CV_8U);
	//imshow("Gradient", thisIsAGradient);

	//waitKey(0);
}

void createPattern(Mat&input){
	//Mat thisIsAGradient(picHeight, picWidth, CV_64FC1);

	//imshow("BB", input);
	resize(input, input, Size(picWidth, picHeight));
	Mat converted2CV_8U;
	for (int y = 0; y < input.rows; y++){
		for (int x = 0; x < input.cols; x++){
			double tmp = rOfX(phiOfXAndY(y, x));
			input.at<Vec4d>(y, x)[0] *= tmp;
			input.at<Vec4d>(y, x)[1] *= tmp;
			input.at<Vec4d>(y, x)[2] *= tmp;
			input.at<Vec4d>(y, x)[3] = tmp;
		}
	}
	input.convertTo(converted2CV_8U, CV_8U, 255);
	imwrite("outputPattern.png", converted2CV_8U);
	imshow("Gradient", input);

	waitKey(0);
}

void createPattern(vector<Mat>&inputs){
	for (int i = 0; i < inputs.size(); i++){
		resize(inputs[i], inputs[i], Size(picWidth, picHeight));
	}


	Mat canvas(picHeight, picWidth, CV_64FC4);
	Mat converted2CV_8U;


	int frameCounter = 0;
	bool flipFlop = true;


	for (int y = 0; y < canvas.rows; y++){
		for (int x = 0; x < canvas.cols; x++){

			double direct = phiOfXAndY(y, x);
			double tmp = rOfX(2*direct);//底圖更換的週期恰好是柵格的的一半

			frameCounter = inputs.size()*direct / (2*myPi);//frameCounter=direct/每張圖的週期Tn。
			//光柵週期T，有N張圖，則每張圖的週期是Tn=T/N。
			//又T=2*myPi，則Tn=2*myPi/N
			//若N=4，frameCounter=2*direct / myPi
			frameCounter %= inputs.size();
			
			/*比照柵格，原本的寫法是:
			canvas.at<Vec4d>(y, x)[0] = tmp*inputs[frameCounter].at<Vec4d>(y, x)[0];
			但是這樣子會有"太暗"的部分，所以直接改用以下的
			*/
			canvas.at<Vec4d>(y, x)[0] = inputs[frameCounter].at<Vec4d>(y, x)[0];
			canvas.at<Vec4d>(y, x)[1] = inputs[frameCounter].at<Vec4d>(y, x)[1];
			canvas.at<Vec4d>(y, x)[2] = inputs[frameCounter].at<Vec4d>(y, x)[2];
			canvas.at<Vec4d>(y, x)[3] = 1;//底圖不該是透明的
		}
	}


	canvas.convertTo(converted2CV_8U, CV_8U, 255);
	imwrite("outputPattern.png", converted2CV_8U);
	//imshow("Gradient", canvas);
	//waitKey(0);*/

	createPatternAnime(canvas);
}
void createGradientAnime(){
	char stop;

	int timer(0);
	VideoWriter videoout;
	videoout.open("line.avi", VideoWriter::fourcc('X', 'V', 'I', 'D'), 29, Size(picWidth, picHeight), true);

	if (!videoout.isOpened()) {
		return;
	}

	cvNamedWindow("Video Player", CV_WINDOW_AUTOSIZE);
	cvCreateTrackbar("Exp", "Video Player", &sliderValue, 10, [](int){
		shifter = pow(10, sliderValue);
		Offset = 0;
	});

	cout << "輸入q以正確關閉" << endl;

	while (true){
		Mat thisIsAGradient(picHeight, picWidth, CV_64FC1);
		Mat converted2CV_8U;
		for (int y = 0; y < thisIsAGradient.rows; y++){
			for (int x = 0; x < thisIsAGradient.cols; x++){
				thisIsAGradient.at<double>(y, x) = rOfX(phiOfXAndY(y, x) + Offset);
			}
		}
		Offset += shifter;
		thisIsAGradient.convertTo(converted2CV_8U, CV_8U, 255);
		cvtColor(converted2CV_8U, converted2CV_8U, CV_GRAY2BGR);
		stop = cvWaitKey(1000);
		if (timer < 300 && stop != 'Q' &&stop != 'q'){
			timer++;
			cout << "----" << timer << "----" ;
			videoout << converted2CV_8U;
		}
		else{
			cout << "已正確關閉" << endl;
			videoout.release();
			break;
		}
		imshow("Video Player", thisIsAGradient);

		waitKey(30);
	}
}

void createPatternAnime(Mat&input){//需要input是64FC4
	resize(input, input, Size(picWidth, picHeight));
	char stop;
	int timer(0);
	VideoWriter videoout;
	videoout.open("line.avi", VideoWriter::fourcc('X', 'V', 'I', 'D'), 29, Size(picWidth, picHeight), true);


	if (!videoout.isOpened()) {
		return;
	}


	cvNamedWindow("Video Player", CV_WINDOW_AUTOSIZE);
	cvCreateTrackbar("Exp", "Video Player", &sliderValue, 10, [](int){
		shifter = pow(10, sliderValue);
		Offset = 0;
	});


	cout << "輸入q以正確關閉" << endl;

	while (true){
		Mat thisIsAGradient=input.clone();
		Mat converted2CV_8U;
		for (int y = 0; y < thisIsAGradient.rows; y++){
			for (int x = 0; x < thisIsAGradient.cols; x++){
				double tmp = rOfX(phiOfXAndY(y, x) + Offset);
				thisIsAGradient.at<Vec4d>(y, x)[0] *= tmp;
				thisIsAGradient.at<Vec4d>(y, x)[1] *= tmp;
				thisIsAGradient.at<Vec4d>(y, x)[2] *= tmp;
				thisIsAGradient.at<Vec4d>(y, x)[3] = tmp;
			}
		}
		Offset += shifter;
		thisIsAGradient.convertTo(converted2CV_8U, CV_8U, 255);
		cvtColor(converted2CV_8U, converted2CV_8U, CV_BGRA2BGR);
		stop = cvWaitKey(1000);
		if (timer < 300 && stop != 'Q' &&stop != 'q'){
			timer++;
			cout << "----" << timer << "----";
			videoout << converted2CV_8U;
		}
		else{

			cout << "已正確關閉" << endl;

			videoout.release();
			break;
		}
		imshow("Video Player", thisIsAGradient);

		waitKey(30);
	}
}