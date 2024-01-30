#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

Mat image, mask, hsv, outputImage;

int main()
{
    while (true)
    {
        image = imread("../asset/foto1.jpg");

        if (image.empty())
        {
            cout << "Error opening image file" << endl;
            return 0;
        }
        outputImage = Mat::zeros(image.size(), image.type());
        cvtColor(image, hsv, COLOR_BGR2HSV);

        inRange(hsv, Scalar(14, 79, 235), Scalar(133, 255, 255), mask);

        if (mask.empty())
        {
            cout << "Error creating mask" << endl;
            return 0;
        }

        vector<vector<Point>> contours;
        vector<Vec4i> hierarchy;

        findContours(mask, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE);

        for (int n = 0; n < image.rows; n++)
        {
            for (int m = 0; m < image.cols; m++)
            {
                if (mask.at<uchar>(n, m) != 0)
                {
                    outputImage.at<Vec3b>(n, m) = image.at<Vec3b>(n, m);
                }
            }
        }

        Point2f center;
        float radius;

        for (int i = 0; i < contours.size(); i++)
        {
            minEnclosingCircle(contours[i], center, radius);

            circle(outputImage, center, radius, Scalar(20, 200, 10), 2, 4);
        }

        string hitungBola = "Jumlah Bola = " + to_string(contours.size());
        putText(outputImage, hitungBola, Point(10, 30), FONT_HERSHEY_COMPLEX, 1.0, Scalar(0, 0, 200), 2);

        imshow("Gambar Asli", image);
        imshow("Gambar Output", outputImage);

        waitKey(1);
    }
    destroyAllWindows();

    return 0;
}
