#include <opencv2/opencv.hpp>

int main() {
    cv::Mat image = cv::imread("/home/sharmi/Downloads/Filters/images/Envelope.png");

    if (image.empty()) {
        std::cerr << "Error: Unable to load image." << std::endl;
        return -1;
    }

    // Apply Gaussian filter
    cv::Mat gaussianFiltered;
    cv::GaussianBlur(image, gaussianFiltered, cv::Size(5, 5), 0);

    // Apply median filter
    cv::Mat medianFiltered;
    cv::medianBlur(image, medianFiltered, 5);

    // Apply box (average) filter
    cv::Mat boxFiltered;
    cv::blur(image, boxFiltered, cv::Size(5, 5));

    // Apply bilateral filter
    cv::Mat bilateralFiltered;
    cv::bilateralFilter(image, bilateralFiltered, 9, 75, 75);

    // Display the results
    cv::imshow("Original Image", image);
    cv::imshow("Gaussian Filtered", gaussianFiltered);
    cv::imshow("Median Filtered", medianFiltered);
    cv::imshow("Box Filtered", boxFiltered);
    cv::imshow("Bilateral Filtered", bilateralFiltered);

    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;
}
