#include <caffe/caffe.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <algorithm>
#include <iosfwd>
#include <memory>
#include <string>
#include <utility>
#include <vector>

#include <boost/filesystem.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/format.hpp>
#include "CrowdEstimate.h"
//#include "frcnn_utils.hpp"
//#include"frcnn_param.hpp"

using namespace caffe;
using namespace  std;

int main()
{
    CrowdEstimate::ins();
    string video_path = "/data_2/crowd-predict-video/video/jianshezhe.MP4";
    //string imglist = "/home/pengshanzhen/test_new_people/data/B/imglist.txt";
    //string out_folder_path="/data_2/crowd-predict/out_img";
    string out_video = "/data_2/crowd-predict-video/video/out_video_1";


    //boost::filesystem::path tmppath(imglist);
    //string outfile = out_folder_path +"/"+tmppath.stem().string()+ ".jpg";
    //std::ofstream outfile(savepath,ios::app);


    //std::ifstream list(imglist);

    string mean_file = "";
    string img_path;
    cv::Mat densitymap;
    float headcount;
    cv::VideoCapture capture(video_path);
    int num = 0;
    while(true)
    {
        string outfile = out_video +"/"+std::to_string(num) + ".jpg";
        cv::Mat frame;
        capture >> frame;
        if (frame.empty()) break;
        cv::Mat new_img = frame.clone();
//        cv::Mat img=cv::imread(img_path);
//        if (img.data == NULL)
//        {
//            cout << endl << "read image error" << endl;
//            getchar();
//        }
        int64 t1 = cvGetTickCount();

        CrowdEstimate::ins().process(new_img,densitymap,headcount);
        //process(img,densitymap,headcount);
        int64 t2 = cvGetTickCount();
        cv::putText(new_img,std::to_string(headcount), cv::Point(new_img.cols-400, 100), cv::FONT_HERSHEY_SIMPLEX, 2.0, cv::Scalar(255, 23, 0), 5, 5);
        cout << "time cost:" << (t2-t1)/cvGetTickFrequency() / 1000000 << "s" << endl;
        cout << "per img people count:" << headcount <<endl;
        cv::imwrite(outfile,new_img);
        num++;

        //cvNamedWindow("new",CV_WINDOW_NORMAL);
        //cv::imshow("new", img);
        //cv::waitKey(10000);




    }
    return 0;


}
