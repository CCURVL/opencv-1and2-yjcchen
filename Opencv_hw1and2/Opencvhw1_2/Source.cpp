#include <opencv2/opencv.hpp>
#include <vector>
using namespace cv;
using namespace std;

int HW01_TestFunction();
int HW02_ReadAndShowData(int numberOfImgs);

int main() {
	HW01_TestFunction();
	waitKey(0);
	destroyAllWindows();

	//HW02_ReadAndShowData(8);

	waitKey(0);
	return 0;
}


int HW01_TestFunction() {
	
	Mat grayImg, binaryImg;
	Mat img = imread("lena.jpg");
	imshow("InputImage", img);
	grayImg =  imread("lena.jpg", CV_LOAD_IMAGE_GRAYSCALE); //轉灰階
	imshow("GrayImage", grayImg);
	threshold(grayImg, binaryImg, 100.0, 255.0, THRESH_BINARY); //二值化
	imshow("BinaryImage", binaryImg);

	return 0;
}

int HW02_ReadAndShowData(int numberOfImgs) {
	vector <Mat> img;
	vector <Mat> grayImg;
	vector <Mat> binaryImg;
	String imgName;
	Mat tmpImg;
	for (int i = 0; i < numberOfImgs; i++) {
		imgName = to_string(i + 1) + ".jpg";
		img.push_back(imread(imgName));
		grayImg.push_back(imread(imgName, CV_LOAD_IMAGE_GRAYSCALE));
		threshold(grayImg[i], tmpImg, 100.0, 255.0, THRESH_BINARY); 
		binaryImg.push_back(tmpImg);

		imshow("InputImage", img[i]);
		imshow("GrayImage", grayImg[i]);
		imshow("BinaryImage", binaryImg[i]);

		//調整視窗位置
		moveWindow("InputImage", 0, 20);
		moveWindow("GrayImage", 300, 20);
		moveWindow("BinaryImage", 600, 20);

		waitKey(0);
		destroyAllWindows();
	}
	return 0;
}





