#include <opencv2/opencv.hpp>

int main() {
    cv::Mat image = cv::imread("/home/sharmi/Downloads/Filters/images/Envelope2.png", cv::IMREAD_GRAYSCALE);

    if (image.empty()) {
        std::cerr << "Error: Unable to load image." << std::endl;
        return -1;
    }

    // Define a kernel for morphological operations
    cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(5, 5));

    // Perform dilation
    cv::Mat dilated;
    cv::dilate(image, dilated, kernel);

    // Perform erosion
    cv::Mat eroded;
    cv::erode(image, eroded, kernel);

    // Perform opening
    cv::Mat opened;
    cv::morphologyEx(image, opened, cv::MORPH_OPEN, kernel);

    // Perform closing
    cv::Mat closed;
    cv::morphologyEx(image, closed, cv::MORPH_CLOSE, kernel);

    // Perform top hat
    cv::Mat topHat;
    cv::morphologyEx(image, topHat, cv::MORPH_TOPHAT, kernel);

    // Perform black hat
    cv::Mat blackHat;
    cv::morphologyEx(image, blackHat, cv::MORPH_BLACKHAT, kernel);

    // Perform hit-or-miss transformation
    cv::Mat hitOrMiss;
    cv::morphologyEx(image, hitOrMiss, cv::MORPH_HITMISS, kernel);

    // Display the results
    cv::imshow("Original Image", image);
    cv::imshow("Dilation", dilated);
    cv::imshow("Erosion", eroded);
    cv::imshow("Opening", opened);
    cv::imshow("Closing", closed);
    cv::imshow("Top Hat", topHat);
    cv::imshow("Black Hat", blackHat);
    cv::imshow("Hit or Miss", hitOrMiss);

    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;
}
