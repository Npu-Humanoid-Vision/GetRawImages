#include <opencv2/opencv.hpp>
#include <bits/stdc++.h>
using namespace std;
using namespace cv;

#define CAMERA_INDEX 0
#define SAVE_PATH "D:/baseRelate/code/svm_trial/BackUpSource/Ball/Train/Raw/"
#define COUNTER_INIT_NUM 0

int counter = COUNTER_INIT_NUM;


string GetNextPath() {
    stringstream t_ss;
    string t_s;

    t_ss << counter++;
    t_ss >> t_s;
    t_s = SAVE_PATH + t_s;
    t_s += ".jpg";
    cout<<t_s<<endl;
    return t_s;
}

int main(int argc, char const *argv[]) {
    cv::VideoCapture cp(CAMERA_INDEX);
    cv::Mat frame;

    cp >> frame;
    while (frame.empty()) {
        cp >> frame;
        cout << "waiting camera init..." << endl;
    }

    while (1) {
        cp >> frame;
        cv::imshow("233", frame);
        char key = cv::waitKey(50);
        if (key == 's') {
            cv::imwrite(GetNextPath(), frame);
        }
        else if (key == 'q') {
            break;
        }
    }
    return 0;
}
