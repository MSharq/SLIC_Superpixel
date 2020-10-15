#include <iostream>
//#include <unistd.h>
#include "slic.h"
#include <opencv2/imgcodecs.hpp>

#include <chrono>

int main(int argc, char *argv[])
{
    extern char *optarg;
    extern int optopt;
    bool errorOpt = false;
    
    // Get starting timepoint 
    auto start = std::chrono::high_resolution_clock::now();

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
    // Get ending timepoint 
    auto stop = std::chrono::high_resolution_clock::now();

    // Get duration. Substart timepoints to  
    // get durarion. To cast it to proper unit 
    // use duration cast method 
    auto duration = std::chrono::duration_cast<std::chrono::seconds>(stop - start);

    std::cout << "Time taken by function: "
        << duration.count() << " seconds" << std::endl;
    return 0;
}
