/*
 * ImgProc.h
 *
 *  Created on: Nov 26, 2013
 *      Author: Naor Farcas & Roei Biton
 */

#ifndef IMGPROC_H_
#define IMGPROC_H_

#include<iostream>
#include "/usr/local/include/opencv/cv.h"
#include "/usr/local/include/opencv/highgui.h"
#include <vector>
#include "Customers.h"

using namespace cv;
using namespace std;

class ImgProc {
public:
	const vector< int > FindFaces(const string& pic_path, Customers& customers);
	void collage(Customers& customers);
private:
	bool face_compare(const Mat mat1, const Mat mat2);
    
};
#endif /* IMGPROC_H_ */
