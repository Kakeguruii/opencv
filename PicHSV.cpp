#include "opencv2/opencv.hpp"
#include <iostream>
#include <unistd.h>
#include <chrono>
#include <thread>
#include <stdlib.h>
#include <stdio.h>

using namespace std;
using namespace cv;
 


int main() {

    Mat image;
    Mat image2;
    namedWindow("Display window");
    VideoCapture cap(0);
    int centW = cap.get(CAP_PROP_FRAME_WIDTH);
    int centH = cap.get(CAP_PROP_FRAME_HEIGHT);
    cout << centW << endl << centH;
    //Rect r2 = Rect(centW/2, centH/2, 30 , 30); //640 × 480
    Rect rr = Rect(centW/2, (centH/2), 5 , 5); 
    Rect r2 = Rect((centW/2), (centH/2)-10, 5 , 25); //640 × 480
    Rect r3 = Rect((centW/2-10), (centH/2), 25, 5);

    Vec3b vec;
    
    while (true) {
        cap >> image;
        cvtColor(image, image2, COLOR_BGR2HSV);

        vec = image.at<Vec3b>(centH/2, centW/2);
        Vec3b vec2;
        int sec = 180 / 3;
        int sec2 = sec / 2;
        if ((vec[0] > sec2) && (vec[0] < (sec2 + sec))) {
            vec2[0] = 0;
            vec2[1] = 0;
            vec2[2] = 255;
        } else if ((vec[0] > sec2 + sec) && (vec[0] < 180 - sec2)) {
            vec2[0] = 255;
            vec2[1] = 0;
            vec2[2] = 0;
        } else {
            vec2[0] = 0;
            vec2[1] = 255;
            vec2[2] = 0;
        }

        //rectangle(image, r2, Scalar(vec2), 2, 8, 0);
        rectangle(image, rr, Scalar(vec2), 2, 8, 0);
        rectangle(image, r2, Scalar(vec2), 2, 8, 0);
        rectangle(image, r3, Scalar(vec2), 2, 8, 0);
        imshow("Display window2", image2);
        imshow("Display window", image);
       
        char c = (char)waitKey(1);
        if( c == 27 ) break;
    }
    return 0;
}

