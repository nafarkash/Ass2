/*
 * ImgProc.cpp
 *
 *  Created on: Nov 26, 2013
 *      Author: Naor Farcas & Roei Biton
 */

#include "../include/ImgProc.h"

const vector < int > ImgProc::FindFaces(const string& pic_name, Customers& customers) {
    
	vector < int > ret;
	bool found;
	Mat curr, curr_gray;
	Mat frame = imread("/Users/naorfarkash/Desktop/workspace/Ass2/Ass2/customers/" + pic_name);
    
	vector<Rect> faces;
	/*** Change image into grayscale***
	 **********************************/
	Mat frame_gray;
	cvtColor(frame, frame_gray, CV_BGR2GRAY);
    
	CascadeClassifier cascade;
	cascade.load("/usr/local/share/opencv/haarcascades/haarcascade_frontalface_alt.xml");
	/*** Detect objects***
	 **********************/
	faces.clear();
	cascade.detectMultiScale(frame_gray, faces, 1.1, 2,
                             0|CV_HAAR_SCALE_IMAGE );
	/***Draw Rectangle outside recognized pattern***
	 ***********************************************/
	for (uint i = 0; i < faces.size(); i++) {
		rectangle(frame, cvPoint(faces[i].x, faces[i].y),
                  cvPoint(faces[i].x + faces[i].width,
                          faces[i].y + faces[i].height), Scalar(0, 0, 255));
	}
    
    
	for (uint j = 0; j < faces.size(); j++) {
		found = 0;
		int i=0;
		for (i = 0; i < customers.Quantity() && !found; i++) {
			//getting customer image for comparison
			curr = imread("/Users/naorfarkash/Desktop/workspace/Ass2/Ass2/faces/" + customers.getCust(i).getName() + "/" + customers.getCust(i).getName() + ".tiff");
			cvtColor(curr, curr_gray, CV_BGR2GRAY);
			found = face_compare(frame_gray(faces[j]), curr_gray);
            if (found){
                ret.push_back(i);
            }
        }
		
	}
    
	frame_gray.release();
	frame.release();
	curr.release();
	curr_gray.release();
    
    return ret;
}

bool ImgProc::face_compare(const cv::Mat mat1, const cv::Mat mat2){
    // treat two empty mat as identical as well
    if (mat1.empty() && mat2.empty()) {
        return true;
    }
    // if dimensions of the two mats are not identical, these two mats are not identical
    if (mat1.cols != mat2.cols || mat1.rows != mat2.rows || mat1.dims != mat2.dims) {
        return false;
    }
    Mat diff;
    compare(mat1, mat2, diff, CMP_NE);
    int nz = countNonZero(diff);
    return nz==0;
}
void ImgProc::collage (Customers& customers){
	vector<Mat> pics;
    for (int i = 0 ; i < customers.Quantity() ; i++){
        Mat tmp = imread("/Users/naorfarkash/Desktop/workspace/Ass2/Ass2/faces/" + customers.getCust(i).getName() + "/" + customers.getCust(i).getName() + ".tiff");
        pics.push_back(tmp);
    }
    //Resizing
    int size = customers.Quantity();
    Mat collage = Mat(150, size*150, CV_8UC3);
    for (uint i = 0 ; i < pics.size() ; i++){
        Mat face = pics[i];
        resize(face, face, Size(150,150));
        face.copyTo(collage(Rect(i*150,0, 150, 150)));
        
        
    }
    if (collage.data){
        imwrite("collage.tiff", collage);
    }
    
}

