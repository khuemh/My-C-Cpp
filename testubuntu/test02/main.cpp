#include <opencv/cv.h>
#include <opencv/cxcore.h>
#include <opencv/highgui.h>

int main()
{
    // Initialise
    //std::string filepath = "spots.bmp";
    std::string filepath = "spots2.jpg";
    int num_blobs = 0;
    // Load grayscale version of coloured input image
    IplImage* original  = cvLoadImage( filepath.c_str() );
    IplImage* grayscale = cvLoadImage( filepath.c_str(),
                                       CV_LOAD_IMAGE_GRAYSCALE );

    // Check bitmap image exists
    assert( grayscale );

    // Create IplImage struct for a black and
    // white (binary) image
    IplImage* img_bw = cvCreateImage( cvGetSize( grayscale ),
                                      IPL_DEPTH_8U,
                                      1 );

    // Use thresholding to convert grayscale image
    // into binary
    cvThreshold( grayscale,             // source image
                 img_bw,                // destination image
                 40,                    // threhold val.
                 255,                   // max. val
                 CV_THRESH_BINARY );    // binary

    // Create IplImage struct for inverted black
    // and white image
    IplImage* img_bw_inv = cvCloneImage( img_bw );
    IplImage* img_bw_cpy = cvCloneImage( img_bw );

    // Find connected components using OpenCV
    CvSeq* seq;
    CvMemStorage* storage = cvCreateMemStorage( 0 );
    cvClearMemStorage( storage );

    // cvFindContours the 12 + 1 extra object for
    // white backgrounds and black spots, hence
    // subtract 1
    num_blobs = cvFindContours( img_bw,
                                storage,
                                &seq,
                                sizeof( CvContour ),
                                CV_RETR_LIST,
                                CV_CHAIN_APPROX_NONE,
                                cvPoint( 0, 0 ) ) - 1;

    // Display the input / output windows and images
    cvNamedWindow( "original" );
    cvShowImage( "original", original );

    cvNamedWindow( "grayscale" );
    cvShowImage( "grayscale", grayscale );

    cvNamedWindow( "black_and_white" );
    cvShowImage( "black_and_white",
                  img_bw_cpy );

    // Wait for user key press and then tidy up
    cvWaitKey(0);

    cvReleaseImage( &original );
    cvReleaseImage( &grayscale );
    cvReleaseImage( &img_bw );
    cvReleaseImage( &img_bw_inv );
    cvReleaseImage( &img_bw_cpy );

    cvDestroyWindow( "greyscale" );
    cvDestroyWindow( "black_and_white" );
    cvDestroyWindow( "inverted" );

    return 0;
}


