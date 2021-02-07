#include <iostream>
#include <Eigen/Dense>
#include "arduino-serial-lib.h"
#include "Sensor.h"

#include <chrono>

#define now std::chrono::high_resolution_clock::now()

using namespace Eigen;
using namespace std;
 
typedef Matrix<double, 8, 8> Matrix8d;
typedef Matrix<double, 8,1> Vector8d;

int main()  {

    EncoderTrinket encoderTrinket("/dev/ttyACM0");
    auto t1 = now;
    for(int i = 0; i < 100000; ++i) {
        encoderTrinket.getMotor1Value();
    }
    auto t2 = now;
    auto t3 = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
    std::cout << float(t3)/100000 << std::endl;


    return 1;
}