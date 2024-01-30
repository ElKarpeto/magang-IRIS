#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

Mat inputImage, outputImage;

int main()
{
    inputImage = imread("../asset/foto2.jpeg");

    if (inputImage.empty())
    {
        cout << "Could not open or find the image." << endl;
        return -1;
    }

    inputImage.copyTo(outputImage);

    Mat gray;
    cvtColor(inputImage, gray, COLOR_BGR2GRAY);

    medianBlur(gray, gray, 3);

    vector<Vec3f> circles;
    // HoughCircles(gray, circles, HOUGH_GRADIENT, 1, 2, 300, 100, 15, 100);
    HoughCircles(gray, circles, HOUGH_GRADIENT_ALT, 1.5, 2, 100, 0.9, 1, 100);

    cout << circles.size() << endl;
    for (int i = 0; i < circles.size(); i++)
    {
        cout << circles[i] << endl;
    }

    for (int i = 0; i < circles.size(); i++)
    {
        int x = cvRound(circles[i][0]);
        int y = cvRound(circles[i][1]);
        int radius = cvRound(circles[i][2]);

        circle(outputImage, Point(x, y), 1, Scalar(200, 0, 50), 1, LINE_4);
        circle(outputImage, Point(x, y), radius, Scalar(0, 0, 200), 2, LINE_4);
    }

    string textGambar = "Jumlah Bola = " + to_string(circles.size());
    putText(outputImage, textGambar, Point(10, 30), FONT_HERSHEY_COMPLEX, 0.6, Scalar(0, 0, 200), 2);

    imshow("Gray", gray);
    imshow("Output Image", outputImage);

    waitKey(0);
    return 0;
}
