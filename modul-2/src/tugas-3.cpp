#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

VideoCapture cap("modul-2/asset/video3.mp4");
Mat video;

int main()
{

    if (!cap.isOpened())
    {
        cout << "path video salah" << endl;

        return 0;
    }

    while (true)
    {
        cap >> video;

        if (video.empty())
        {
            cout << "video ga ada" << endl;
            return 0;
        }

        imshow("Video", video);

        waitKey(1);
    }

    destroyAllWindows();

    return 0;
}