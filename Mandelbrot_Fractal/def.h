#pragma once


#define WIDTH 600
#define HEIGHT 600 
#define TITLE "Mandelbrot Set" //of the window
#define MAX_ITER 60 //max number of iterations 
#define ZOOM_CHANGEMENT 5  
#define MOVE_CHANGEMENT 0.5

//complex numbers
typedef struct COMPLEX {
	float r;   //real 
	float i;   //imaginary
}cmplx;


//view of the fractal and complex plane
typedef struct VIEW {
	float x_move; //change of x (Re)
	float y_move; //change of y (Im)
	float zoom; //of actual 
	float fractalMaxI; //precision - actual max of iteration
}VIEW;

