#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <vector>
#include <cmath>
using namespace cv;
using namespace std;

int n = 7;
int center = (n - 1) / 2;
double sigma = 3.2;

double gauss(int x, int y, int a, int b) {
    return 
    1.0 / (2 * M_PI * sigma * sigma) * 
    exp(-((x - a) * (x - a) + (y - b) * (y - b)) / 
    (2 * sigma * sigma));
}

vector<vector<double>> getMatrix() {
    vector<vector<double>> _matrix = vector<vector<double>>();
    for (int i = 0; i < n; i++) {
        vector<double> _vector = vector<double>();
        for (int j = 0; j < n; j++) {
            _vector.push_back(gauss(i, j, center, center));
        }
        _matrix.push_back(_vector);
 
    }
    return _matrix;
}

double getSum(vector<vector<double>> &matrix) {
    double _sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            _sum += matrix[i][j];
        }
    }
    return _sum;
}

vector<vector<double>> getNormMatrix(vector<vector<double>> &matrix, double sum) {
    vector<vector<double>> _matrix = vector<vector<double>>();
    for (int i = 0; i < n; i++) {
        vector<double> _vector = vector<double>();
        for (int j = 0; j < n; j++) {
            _vector.push_back(matrix[i][j] / sum);
        }
        _matrix.push_back(_vector);
    }
    return _matrix;
}

Mat getBlurPicture(vector<vector<double>> &matrix, Mat &img) {
    Mat imgNew = img.clone();
    int len1 = img.rows;
    int len2 = img.cols;
    
    for (int i = center; i < len1 - center; i++) {
        for (int j = center; j < len2 - center; j++) {
            int sum1 = 0, sum2 = 0, sum3 = 0;
            for (int q = 0; q < n; q++) {
                for (int w = 0; w < n; w++) {
	                auto _img = img.at<Vec3b>(q + i - center, w + j - center);
	                sum1 += matrix[q][w] * _img[0];
	                sum2 += matrix[q][w] * _img[1];
	                sum3 += matrix[q][w] * _img[2];
                }
            }
            imgNew.at<Vec3b>(i, j)[0] = sum1;
            imgNew.at<Vec3b>(i, j)[1] = sum2;
            imgNew.at<Vec3b>(i, j)[2] = sum3;
        }
    }
    return imgNew;
}

int main(int argc, char** argv )
{
    }*/
    Mat image2;
    Mat image;
    image2 = imread( "./kit.jpg" );
    if ( !image2.data )
    {
        printf("No image data \n");
        return -1;
    }
    cvtColor(image2, image, COLOR_BGR2GRAY);
    
    vector<vector<double>> matrix = getMatrix();
    double sum = getSum(matrix);
    vector<vector<double>> matrix1 = getNormMatrix(matrix, sum);
    namedWindow("run", WINDOW_NORMAL );
    imshow("run", image1);
    waitKey(0);
    return 0;
}
