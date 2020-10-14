#include <iostream>
//#include <unistd.h>
#include "slic.h"
#include <opencv2/imgcodecs.hpp>

int main(int argc, char *argv[])
{
    extern char *optarg;
    extern int optopt;
    bool errorOpt = false;
    
    cv::Mat inputMatrix = cv::imread(inputFile);
    if (inputMatrix.empty())
    {
        std::cout << "\ninvalid path";
        return 1;
    }

    std::cout << "the image size "<< inputMatrix.size() << ", channels " << inputMatrix.dims << std::endl;

    const int numberOfSupperpixels = 400;
    const int compactness = 20;
    const double treshold = 30.0;
    superpixel::SLIC slic;
    slic.getSupperpixels(inputMatrix, numberOfSupperpixels, compactness, treshold);
    return 0;
}
