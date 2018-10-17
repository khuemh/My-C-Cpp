#include <opencv2/highgui.hpp>
#include <iostream>

int main(void)
{
  cv::Mat image;
  image = cv::imread("lena.jpg" , CV_LOAD_IMAGE_COLOR);
  if(! image.data ) {
      return -1;
    }

  cv::namedWindow( "Display window", cv::WINDOW_AUTOSIZE );
  cv::imshow( "Display window", image );

  cv::waitKey(0);
  return 0;
}

