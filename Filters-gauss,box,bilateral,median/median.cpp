
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
    // Read the input image
    Mat image = imread("/home/sharmi/Desktop/C++_codes/median-blu.webp", IMREAD_COLOR);

    if (image.empty())
    {
        cout << "Error: Could not read the image." << endl;
        return -1;
    }

    // Convert the image to grayscale
    Mat grayImage;
    cvtColor(image, grayImage, COLOR_BGR2GRAY);

    // Apply Gaussian blur with a specified kernel size and standard deviation
    int kernelSize = 11; // You can change this to the desired kernel size (e.g., 5, 7, etc.)

    // Apply median filtering
    medianBlur(image, grayImage, kernelSize);
    // Display the original and blurred images
    imshow("Original Image", image);
    imshow("Blurred Image", grayImage);

    waitKey(0);
    return 0;
}

