# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

---

## Dependencies

* cmake >= 3.5
 * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1(mac, linux), 3.81(Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools]((https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* [uWebSockets](https://github.com/uWebSockets/uWebSockets)
  * Run either `./install-mac.sh` or `./install-ubuntu.sh`.
  * If you install from source, checkout to commit `e94b6e1`, i.e.
    ```
    git clone https://github.com/uWebSockets/uWebSockets 
    cd uWebSockets
    git checkout e94b6e1
    ```
    Some function signatures have changed in v0.14.x. See [this PR](https://github.com/udacity/CarND-MPC-Project/pull/3) for more details.
* Simulator. You can download these from the [project intro page](https://github.com/udacity/self-driving-car-sim/releases) in the classroom.

Fellow students have put together a guide to Windows set-up for the project [here](https://s3-us-west-1.amazonaws.com/udacity-selfdrivingcar/files/Kidnapped_Vehicle_Windows_Setup.pdf) if the environment you have set up for the Sensor Fusion projects does not work for this project. There's also an experimental patch for windows in this [PR](https://github.com/udacity/CarND-PID-Control-Project/pull/3).

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid`. 

## Rubric

The PID procedure follows what was taught in the lessons.
The PID implementation is done on the ./src/PID.cpp. The PID::UpdateError method calculates proportional, integral and derivative errors and the PID::TotalError calculates the total error using the appropriate coefficients.

1. Proportional (P):
The proportional parameter in the controller determines to which extent should the direction change respective to the cross-track-error (CTE). Given the direct relationship, it has the potential for agressive behaviour if the parameter is set too high.

2. Integral
The integral parameter in the controller adjusts in proportion to the running sum of cross-track-error during all iterations. It's purpose is to ensure that the CTE is decreasing in the long term and stabilizes.

3. Differential (D):
The differential parameter in the controller adjusts in proportion to changes in CTE. Given that the rate of change is smaller than the error after the initial iteration, this parameter is a lot more useful in decreasing oscillations.

I finally tuning :

KP = 0.2
KI = 0.004
KD = 3.0

