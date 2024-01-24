#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int max_h = 255;
int max_s = 255;
int max_v = 255;
int min_h = 0;
int min_s = 0;
int min_v = 0;

VideoCapture cap;
Mat video;
Mat mask;
Mat hsv;

int main()
{
    namedWindow("Trackbars", WINDOW_AUTOSIZE);
    createTrackbar("H min", "Trackbars", &min_h, 255);
    createTrackbar("H max", "Trackbars", &max_h, 255);
    createTrackbar("S min", "Trackbars", &min_s, 255);
    createTrackbar("S max", "Trackbars", &max_s, 255);
    createTrackbar("V min", "Trackbars", &min_v, 255);
    createTrackbar("V max", "Trackbars", &max_v, 255);

    cap.open("/dev/v4l/by-id/usb-Generic_HP_TrueVision_HD_Camera_0001-video-index0");

    while (true)
    {
        cap >> video;

        resize(video, video, Size(640, 480));

        cvtColor(video, hsv, COLOR_BGR2HSV);

        inRange(hsv, Scalar(min_h, min_s, min_v),
                Scalar(max_h, max_s, max_v), mask);

        vector<vector<Point>> contours;
        vector<Vec4i> hierarchy;

        findContours(mask, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE);

        drawContours(video, contours, -1, Scalar(0, 255, 0), 2);

        imshow("Frame", video);
        imshow("Mask", mask);
        imshow("Hsv", hsv);
        waitKey(1);
    }

    cap.release();
    destroyAllWindows();
    return 0;
}