#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;


void img_dis(char img_name[])
{
    Mat img = imread(img_name);
    namedWindow("Example", WINDOW_AUTOSIZE);
    imshow("Example", img);
    waitKey(0);
    destroyWindow("Example");
}


int main(void)
{
    namedWindow( "Example3", cv::WINDOW_AUTOSIZE );
    VideoCapture cap;
    cap.open( string(argv[1]) );
    Mat frame;
    for(;;) {
    cap >> frame;
    if( frame.empty() ) break;
    imshow( "Example3", frame );
    if(waitKey(33) >= 0) break;
    }
    // Ran out of film
    return 0;
}
