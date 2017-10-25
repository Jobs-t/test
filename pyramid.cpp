#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

enum pyrType{PYR_GUASS,PYR_LAPLACE};

void genPyr(const Mat& imgSrc ,vector<Mat>&outPutArray,int TYPE,int level)
{
	outPutArray.assign(level + 1, Mat());
	outPutArray[0] = imgSrc.clone();
	for(int i = 0; i !=level; i++){
		pyrDown(outPutArray[i],outPutArray[i + 1]);

	}

	if(PYR_GUASS == TYPE){
		return;
	}
	for(int i = 0; i !=level; i++){
		Mat UpSampleImag;
		pyUp(outPutArray[i],outPutArray[i + 1]);

	}

}

