#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
    // Read the input image
    Mat image = imread("/home/sharmi/Desktop/C++_codes/Gaussian_noise.jpg", IMREAD_COLOR);

    if (image.empty())
    {
        cout << "Error: Could not read the image." << endl;
        return -1;
    }

    // Convert the image to grayscale
    Mat grayImage;
    cvtColor(image, grayImage, COLOR_BGR2GRAY);

    // Apply Gaussian blur with a specified kernel size and standard deviation
    int kernelSize = 5; // The kernel size (should be odd)
    double sigma = 1.5; // Standard deviation

    Mat blurredImage;
    GaussianBlur(grayImage, blurredImage, Size(kernelSize, kernelSize), sigma);
    // Display the original and blurred images
    imshow("Original Image", image);
    imshow("Blurred Image", blurredImage);

    waitKey(0);
    return 0;
}

