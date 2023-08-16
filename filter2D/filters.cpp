#include <opencv2/opencv.hpp>

int main() {
    cv::Mat image = cv::imread("/home/sharmi/Downloads/Filters/images/Envelope2.png", cv::IMREAD_GRAYSCALE);

    if (image.empty()) {
        std::cerr << "Error: Unable to load image." << std::endl;
        return -1;
    }

    // Define the kernel for the filter
    cv::Mat kernel = (cv::Mat_<float>(3, 3) << -1, -1, -1,
                                              -1,  8, -1,
                                              -1, -1, -1);

    // Apply filter2D
    cv::Mat filteredImage;
    cv::filter2D(image, filteredImage, CV_8U, kernel);

    // Display the original and filtered images
    cv::imshow("Original Image", image);
    cv::imshow("Filtered Image", filteredImage);

    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;
}
