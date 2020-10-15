#ifndef SLIC_H
#define SLIC_H
#include <opencv2/core.hpp>
#include <array>

#include <iostream>

// REMEMBER TO FILL UP THE RIGHT PATHS
static std::string inputFile = "C:\\Users\\sharique\\Desktop\\Test-Bild-Cork\\rsz_002.jpg";
static std::string outputFile_mean = "C:\\Users\\sharique\\Desktop\\Test-Bild-Cork\\SLIC_mean.png";
static std::string outputFile_redLine = "C:\\Users\\sharique\\Desktop\\Test-Bild-Cork\\SLIC_redLine.png";

namespace superpixel {
    struct PixelFeature {
        //Constructor, {} is for list, () is for direct values intializations
        PixelFeature() : labValue{}, xy(0, 0) { }
        //Public variables
        std::array<double, 3> labValue;
        cv::Point xy;
    };

    class SLIC {
    public:
        void getSupperpixels(cv::Mat input, const int numOfSuperpixels, const int compactness, const double treshold);
    private:
        double distance(PixelFeature f1, PixelFeature f2, const int compactness, const int S);
        cv::Mat enforceConnectivity(cv::Mat labels, const int numOfSuperpixels);
        cv::Point getLocalMinimum(cv::Mat input, const int x, const int y, const int n);
    };
}
#endif // SLIC_H