#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include<opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>

#include <iostream>

using namespace cv;


// Only esc closes the windows
int main() 
{
    // Initialize the windows
    namedWindow("Original", WINDOW_AUTOSIZE); // Original camera window
    namedWindow("Greyscale", WINDOW_AUTOSIZE); // Greyscale camera window
    namedWindow("Canny", WINDOW_AUTOSIZE); // Canny (edge finder) camera window
    namedWindow("Blur", WINDOW_AUTOSIZE); // Blurred camera window
    namedWindow("Threshold", WINDOW_AUTOSIZE); // Threshold camera window


    // Initialize the needed variables
    Mat frame;
    Mat grey;
    Mat edges;
    Mat blur;
    Mat thresholdVar;


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



        // Get the variables set
        cvtColor(frame, grey, COLOR_RGB2GRAY); // Change the original camrea to a grey one
        Canny(grey, edges, 80, 90, 3); // Get the Edges from the greyscale camera
        GaussianBlur(grey, blur, Size(19, 19), 0.0, 0.0); // Add a blur to the greyscale camera
        threshold(grey, thresholdVar, 0.0, 200.0, THRESH_BINARY_INV + THRESH_OTSU); // Set a threshold on the greyscale camera


        // Show the windows
        imshow("Original", frame);//  With the Original camera
        imshow("Greyscale", grey);//  With the Greyscale camera
        imshow("Canny", edges);//  With the Canny(edge find) camera
        imshow("Blur", blur);//  With the Blurred camera
        imshow("Threshold", thresholdVar);//  With the Threshold camera

 


        if (waitKey(30) >= 0)
            break;
    }




    camera.release();
    return 0;
}