#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include<iostream>

using namespace cv;
using namespace std;
int main()
{
    // Read the input image
    Mat inputImage = imread("/home/sharmi/Desktop/C++_codes/girl.png", IMREAD_COLOR);

    if (inputImage.empty())
    {
        cout << "Error: Could not open or find the image." << std::endl;
        return -1;
    }

    // Create a window to display the original and filtered images
    namedWindow("Original Image", WINDOW_AUTOSIZE);
    namedWindow("Filtered Image", WINDOW_AUTOSIZE);

    // Show the original image
    imshow("Original Image", inputImage);

    // Apply the bilateral filter to the input image
    Mat filteredImage;
    bilateralFilter(inputImage, filteredImage, 9, 75, 75);

    // Show the filtered image
    imshow("Filtered Image", filteredImage);

    // Wait for a key press and then close the windows
    waitKey(0);
    destroyAllWindows();

    return 0;
}
