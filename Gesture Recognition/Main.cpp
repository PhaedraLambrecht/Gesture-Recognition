#include<opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/core.hpp>
#include <iostream>
using namespace cv;


// Only esc closes the windows
int main() 
{
    // Initialize the frame variable
    Mat frame;


    //Initialize videocapture (Camera) and open it
    VideoCapture camera;
    camera.open(0);

    if (!camera.isOpened())
    {
        std::cout << "Camera not found\n";
        return 0;
    }




    while (1)
    {
        // Read the frames in the camera to the frame variable
        camera >> frame;
        if (frame.empty())
        {
            std::cout << "Blank framew added \n";
            return 0;
        }


        // Show the window with the camera
        imshow("Original", frame);



        if (waitKey(30) >= 0)
            break;
    }




    camera.release();
    destroyAllWindows();
    return 0;
}