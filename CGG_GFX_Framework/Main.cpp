
#include <cmath>
#include <GLM/glm.hpp>
#include <GLM/gtc/matrix_transform.hpp> // This one lets us use matrix transformations
#include "Sphere.h"
#include "CGG_Main.h"
#include "Camera.h"
#include "RayTracer.h"

int main(int argc, char *argv[])
{
	// Variables for storing window dimensions
	int windowWidth = 640;
	int windowHeight = 480;

	// Call CGG::Init to initialise and create your window
	// Tell it what size you want the window to be
	if( !CGG::Init( windowWidth, windowHeight ) )
	{
		// We must check if something went wrong
		// (this is very unlikely)
		return -1;
	}

	// Sets every pixel to the same colour
	// parameters are RGBA, numbers are from 0 to 255
	CGG::SetBackground( 0,0,0 );

	// Preparing a position to draw a pixel
	int pixelX = windowWidth / 2;
	int pixelY = windowHeight / 2;

	// Preparing a colour to draw
	int red = 255;
	int green = 0;
	int blue = 0;

	
	// Draws a single pixel at the specified coordinates in the specified colour!
	CGG::DrawPixel( pixelX, pixelY, red, green, blue );
	Camera *myCam = new Camera();
	Tracer *myTrace = new Tracer();


	for (int x = 0; x<=640; x++)
	{
		for (int y = 0; y <= 480; y++)
		{
			ray currentRay = myCam->GenerateRay(x, y);
			glm::vec3 colour = myTrace->TraceRay(currentRay) * 255.0f;
			CGG::DrawPixel(x, y, colour.r,colour.g,colour.b);
			//generate ray, once got ray, send to ray tracer, get/draw colour
		}
	}

	// Do any other DrawPixel calls here
	// ...

	// Displays drawing to screen and holds until user closes window
	// You must call this after all your drawing calls
	// Program will exit after this line
	return CGG::ShowAndHold();
	
	/*
	understand background theory, design of multithreading, discuss planning
	array to store all the pixels
	use mutex
	*/
	
	// Advanced access - comment out the above DrawPixel and CGG::ShowAndHold lines, then uncomment the following:

	/*
	// Variable to keep track of time
	float timer = 0.0f;

	// This is our game loop
	// It will run until the user presses 'escape' or closes the window
	while( CGG::ProcessFrame() )
	{
		// Set every pixel to the same colour
		CGG::SetBackground( 0,0,0 );
		
		// Change our pixel's X coordinate according to time
		pixelX = (windowWidth / 2) + (int)(sin(timer) * 100.0f);
		// Update our time variable
		timer += 1.0f / 60.0f;

		// Draw the pixel to the screen
		CGG::DrawPixel( pixelX, pixelY, red, green, blue );

	}
	
	return 0;
	*/
	
}
