#include <opencv2/core/core.hpp>
#include "opencv2/highgui.hpp"
#include "opencv2/objdetect.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <ctime>
#include <cstdlib>

using namespace std;
using namespace cv;

CascadeClassifier face_cascade;
String window_name = "Face Detection";
int Enc = 0;
int Ant = 0;
int Comp = 0;
int Lect = 0;
clock_t t3 = clock();
clock_t t2 = clock();
clock_t t1 = clock();

int detectFaces(Mat frame)
{
	std::vector<Rect> faces;
	Mat frame_gray;
	cvtColor(frame, frame_gray, COLOR_BGR2GRAY);  // Convert to gray scale
	equalizeHist(frame_gray, frame_gray);   	// Equalize histogram

	// Detect faces
  	face_cascade.detectMultiScale(frame_gray, faces, 1.1, 3,0|CASCADE_SCALE_IMAGE, Size(30, 30));

  	//imshow(window_name, frame);  // Display frame

	if(faces.size() > 0)
	return 1;
	else return 0;
}

int main() 
{
  	VideoCapture cap(0);        // Open default camera
  	Mat frame;

	// Load preconstructed classifier
	face_cascade.load("/home/caerrome/opencv/data/haarcascades/haarcascade_frontalface_alt.xml");
	  
	while(cap.read(frame)) 
	{
		Enc = detectFaces(frame);       // Call function to detect faces
		if (Enc == 1 && Ant == 1)
		{
			putText(frame, "Alguien", Point(10, 20), FONT_HERSHEY_SIMPLEX, 0.5, (0, 0, 255), 2);
			Ant = Enc;
			Comp = 0;
		}
		else if (Enc == 1 && Ant == 0)
		{
			putText(frame, "Alguien", Point(10, 20), FONT_HERSHEY_SIMPLEX, 0.5, (0, 0, 255), 2);
			Ant = Enc;
			Comp = 1;
		}
		else if (Enc == 0 && Ant == 1)
		{
			putText(frame, "Nadie", Point(10, 20), FONT_HERSHEY_SIMPLEX, 0.5, (0, 0, 255), 2);
			Ant = Enc;
			Comp = 0;
		}
		else
		{
			putText(frame, "Nadie", Point(10, 20), FONT_HERSHEY_SIMPLEX, 0.5, (0, 0, 255), 2);
			Ant = Enc;
			Comp = 0;
		}
		imshow(window_name, frame); //Para consumir menos recursos se documenta esta linea, no es encesario msotrar lo capturado
		if (Comp = 1)
		{

			Enc = detectFaces(frame);       // Call function to detect faces
			t1 = clock();

			if (Enc == 1 && Ant == 1)
			{
				t3 = t1;
				if (((t1-t2)/CLOCKS_PER_SEC)>5 && Lect == 1)
				{
					imwrite("Ladron.jpg", frame); //Creacion de Imagen con la foto de la persona.
					t2 = clock();
					Lect = 0;
					Comp = 0;
				}
			}
			else if (Enc == 0 && Ant == 0)
			{
				t2 = t1;
				if (((t1-t3)/CLOCKS_PER_SEC)>5)
				{
					t3 = clock();
					Lect = 1;
					Comp = 0;
				}
			}
			else if( Enc == 1 && Ant == 0)
			{
				t3 = t1;
				Comp = 0;
			}
			else
			{
				t2 = t1;
				Comp = 0;
			}
			Ant = Enc;
		} 
		else	
		{
			t1 = clock();
			t2 = t1;
			Comp = 0;
		}		

    		if( waitKey(30) >= 0)     // Pause key
    		break; 
  	}
  return 0;
}
