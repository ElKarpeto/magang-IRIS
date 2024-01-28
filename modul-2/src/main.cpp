#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
    Mat img = imread("../asset/foto2.jpeg");

    if (img.empty())
    {
        cout << "Error opening image file" << endl;
        return 0;
    }

    Mat gaussianImage, medianImage, bilateralImage;

    bilateralFilter(img, bilateralImage, 2, 5, 3);
    GaussianBlur(img, gaussianImage, Size(3, 3), 0);
    medianBlur(img, medianImage, 3);

    imshow("Gambar Awal", img);
    imshow("Bilateral Filter", bilateralImage);
    imshow("Gaussian Blur", gaussianImage);
    imshow("Median Blur", medianImage);

    waitKey(0);

    return 0;
}
