// readimage.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;
int main()
{
    //std::cout << "Hello World!\n";
	Mat grayim(600,800,CV_8UC1);
	Mat colorim(600, 800, CV_8UC3);
	/*方法1at（）函数*/
	//uchar value = grayim.at<char>(int i,int j);
	/*
	for (int i = 0; i < grayim.rows; ++i) {
		for (int j = 0; j < grayim.cols; ++j)
		{
			grayim.at<char>(i, j) = (i + j) % 255;
		}
	}
	for (int i = 0; i < colorim.rows; ++i) {
		for (int j = 0; j < colorim.cols; ++j)
		{
			Vec3b pixel;
			pixel[0] = i % 255;
			pixel[1] = j % 255;
			pixel[2] = 0;
			colorim.at<Vec3b>(i, j) = pixel;
		}
	}
	*/
	/*方法2 迭代器*/
	/*
	MatIterator_<uchar>grayit, grayend;
	for (grayit = grayim.begin<uchar>(), grayend=grayim.end<uchar>(); grayit != grayend; grayit++) {
		*grayit = rand() % 255;
	}
	MatIterator_<Vec3b>colorit, colorend;
	for (colorit = colorim.begin<Vec3b>(), colorend = colorim.end<Vec3b>(); colorit != colorend; colorit++) {
		(*colorit)[0] = rand() % 255;//B
		(*colorit)[1] = rand() % 255;//G
		(*colorit)[2] = rand() % 255;//R
	}
	*/
	/*方法3 指针操作*/
	///*
	for (int i = 0; i < grayim.rows; ++i)
	{
		uchar* p = grayim.ptr<uchar>(i);
		for (int j = 0; j < grayim.cols; ++j)
			p[j] = (i + j) % 255;
	}
	for (int i = 0; i < colorim.rows; ++i)
	{
		Vec3b* p = colorim.ptr<Vec3b>(i);
		for (int j = 0; j < colorim.cols; ++j) {
			p[j][0] = i % 255;
			p[j][1] = j % 255;
			p[j][2] = 0;
		}
			
	}
	//*/
	imshow("grayim", grayim);
	imshow("colorim", colorim);
	waitKey(0);
	return 0;
			//colorim.at<char>(i, j) = (i + j) % 255;

}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
