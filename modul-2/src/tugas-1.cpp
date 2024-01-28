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
        outputImage = image.clone();
        cvtColor(image, hsv, COLOR_BGR2HSV);

        inRange(hsv, Scalar(14, 79, 235),
                Scalar(133, 255, 255), mask);

        if (mask.empty())
        {
            cout << "Error creating mask" << endl;
            return 0;
        }

        vector<vector<Point>> contours;
        vector<Vec4i> hierarchy;

        findContours(mask, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE);

        drawContours(outputImage, contours, -1, Scalar(0, 255, 0), 2);

        string hitungBola = "Jumlah Bola = " + to_string(contours.size());
        putText(outputImage, hitungBola, Point(10, 30), FONT_HERSHEY_COMPLEX, 1.0, Scalar(0, 0, 200), 2);

        imshow("Gambar Asli", image);
        imshow("Gambar Output", outputImage);
        imshow("Mask", mask);
        // imshow("Hsv", hsv);

        // cout << "Jumlah Bola = " << contours.size() << endl;

        waitKey(1);
    }
    destroyAllWindows();

    return 0;
}