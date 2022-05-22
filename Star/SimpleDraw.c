
/*-------- STAR-FIELD CODE ---------------------------*/

#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>	// OpenGL Graphics Utility Library
#include "SimpleDraw.h"
#include <math.h>
#include<time.h>
#include<stdbool.h>

#define UPPPER_BOUND 1000
#define LOWER_BOUND 0


struct star
{
	int x;
	int y;
	bool alive;
	int size;
	int speed;
	int time_alive;
	int red, green, blue;
};

int get_new_co_ordinates(int pos);
int star_size(int pos);
bool star_move(int pos);
int dist_from_centre(int pos);
void hide_star(int pos);
void show_star(int pos);
int star_dies(int pos);


struct universe
{
	int maximum_stars;
	int boundry;
	int max_stars_born;
	struct star star_list[10];
	bool big_bang;
};
int initialize();
int new_star_born();
int stars_move();
int kill_after_reaching();


//Temp function
void show_cordinates();

struct universe vishwa;

//int main()
//{
//	 	initialize();
//
//		
//
//	while (true)	//Universe moves forever	-------		ADD DELAY-------
//	{
//		stars_move();	//universe moves
//		
//	}
//
//}


int stars_move()
{
	int stars_alive = 0;
	for (int i = 0; i < 10; i++)		//changes needed when random number of stars are 
	{
		if (vishwa.star_list[i].alive == true)
		{
			bool star_move_success = star_move(i);
			if (star_move_success == true)
			{
				stars_alive++;
			}
		}
	}


	if (stars_alive < vishwa.maximum_stars)
	{
		int stars_to_create = vishwa.maximum_stars - stars_alive;
		if (stars_to_create > vishwa.max_stars_born)
		{
			stars_to_create = vishwa.max_stars_born;
		}
		for (int j = 0; j < stars_to_create; j++)
		{
			new_star_born();
		}
	}
	return 0;
}

int new_star_born()		//Star dies as soon as this fun returns 0 (Is it being)
{
	for (int i = 0; i < 10; i++)
	{
		if (vishwa.star_list[i].alive == false)
		{
			vishwa.star_list[i].alive = true;
			//Other properties innitialized

			int slowest_speed = 2, fastest_speed = 10;

			int decide_sign;
			int seed = time(0) + i * i;

			srand(seed);		//Setting seed
			vishwa.star_list[i].x = (rand() % (UPPPER_BOUND - LOWER_BOUND + 1)) + 1;	//Set x


			srand(seed + vishwa.star_list[i].x);		//Changing seed
			vishwa.star_list[i].y = (rand() % (UPPPER_BOUND - LOWER_BOUND + 1)) + 1;	//Set y

			srand(seed + vishwa.star_list[i].y);		//Changing seed
			decide_sign = rand();
			if (decide_sign % 2 == 0)
			{
				vishwa.star_list[i].x = vishwa.star_list[i].x * (-1);	//Correct sign of x
			}

			srand(seed + vishwa.star_list[i].x + vishwa.star_list[i].y);		//Correct sign of y
			decide_sign = rand();
			if (decide_sign % 2 == 0)
			{
				vishwa.star_list[i].y = vishwa.star_list[i].y * (-1);	//Set y
			}

			srand(seed + (vishwa.star_list[i].x * vishwa.star_list[i].y));
			vishwa.star_list[i].speed = rand() % (fastest_speed - slowest_speed) + slowest_speed;	//Setting speed

			vishwa.star_list[i].time_alive = 0;		//Setting time alive

			vishwa.star_list[i].size = 1;		//Setting Sizze

			//Setting colour characteristics
			srand(seed + (vishwa.star_list[i].x * vishwa.star_list[i].y));
			vishwa.star_list[i].red = rand() % 256;
			srand(seed + (vishwa.star_list[i].x + vishwa.star_list[i].y));
			vishwa.star_list[i].green = rand() % 256;
			srand(seed + (vishwa.star_list[i].x - vishwa.star_list[i].y));
			vishwa.star_list[i].blue = rand();


			//show_star(i);
			break;
		}
	}
	return 0;
}

void show_star(int pos)
{
	//Logic to draw
	printf("\nStar no [%d]	|x : %d|	|y : %d|  ", pos, vishwa.star_list[pos].x, vishwa.star_list[pos].y);
	printf("\nAlive status : ");
	printf(vishwa.star_list[pos].alive == 1 ? "Alive\n" : "Dead\n");
}

void hide_star(int pos)
{
	//Logic to hide
}

int dist_from_centre(int pos)
{
	return vishwa.star_list[pos].time_alive * vishwa.star_list[pos].speed;;
}

int star_size(int pos)
{
	vishwa.star_list[pos].size = vishwa.star_list[pos].time_alive * vishwa.star_list[pos].speed;
	return 0;
}

bool star_move(int pos)
{
	hide_star(pos);

	int current_len = dist_from_centre(pos);

	//Code for moving star in a frame
	get_new_co_ordinates(pos);
	//Get new new_len
	int new_len = dist_from_centre(pos);

	//if (new_len > current_len)			//	Sure kill everything why not ?	-_- 
	//{
	//	//star_dies
	//	star_dies(vishwa.star_list[pos]);
	//}

	if (new_len > kill_after_reaching())
	{
		//printf("\n------------------\nStar Killed  : %d\n------------------\n", pos);
		star_dies(pos);
	}
	else
	{
		//show_star(pos);
	}
	return 0;
}

int star_dies(int pos)
{
	vishwa.star_list[pos].alive = false;
	vishwa.star_list[pos].speed = 0;
	vishwa.star_list[pos].x = 0;
	vishwa.star_list[pos].y = 0;
	vishwa.star_list[pos].size = 0;
	vishwa.star_list[pos].time_alive = 0;
	vishwa.star_list[pos].red = 0;
	vishwa.star_list[pos].green = 0;
	vishwa.star_list[pos].blue = 0;
	return 0;
}

int get_new_co_ordinates(int pos)
{
	long double old_x = vishwa.star_list[pos].x;
	long double old_y = vishwa.star_list[pos].y;
	int d = vishwa.star_list[pos].speed;

	long double new_x, new_y;
	long double temp = (old_x * old_x) + (old_y * old_y);

	temp = sqrt(temp);
	new_x = old_x * d;
	new_x = (new_x / temp) + old_x;
	new_y = (old_y / old_x) * new_x;

	vishwa.star_list[pos].x = new_x;
	vishwa.star_list[pos].y = new_y;

	vishwa.star_list[pos].time_alive++;

	star_size(pos);
	return 0;
}


int initialize()	//Make diff randomize funcitons
{
	vishwa.big_bang = true;
	vishwa.boundry = 1000;		//Rez
	vishwa.maximum_stars = 10;	//Ransdomize later
	vishwa.max_stars_born = 3;	//Ransdomize later (upperbound less than max stars)

	for (int i = 0; i < 10; i++)
	{
		vishwa.star_list[i].alive = false;
		vishwa.star_list[i].speed = 0;
		vishwa.star_list[i].x = 0;
		vishwa.star_list[i].y = 0;
		vishwa.star_list[i].size = 0;
		vishwa.star_list[i].time_alive = 0;
		vishwa.star_list[i].red = 0;
		vishwa.star_list[i].green = 0;
		vishwa.star_list[i].blue = 0;
	}
	return 0;
}

//temp function : display co_ordinaltes
void show_cordinates()
{
	for (int i = 0; i < vishwa.maximum_stars; i++)
	{
		printf("\nStar no [%d]	|x : %d|	|y : %d|  ", i, vishwa.star_list[i].x, vishwa.star_list[i].y);
		printf("\nAlive status : ");
		printf(vishwa.star_list[i].alive == 1 ? "Alive\n" : "Dead\n");
	}
}

int kill_after_reaching()
{
	int max_boundrey = sqrt((vishwa.boundry / 2) * (vishwa.boundry / 2));
	return max_boundrey;
}




/*
 * SimpleDraw.c
 *
 * Example program illustrating a simple use
 * of OpenGL to draw straight lines in 2D, and
 * to draw overlapping triangles in 3D.
 *
 * Author: Samuel R. Buss
 *
 * Software accompanying the book
 *		3D Computer Graphics: A Mathematical Introduction with OpenGL,
 *		by S. Buss, Cambridge University Press, 2003.
 *
 * Software is "as-is" and carries no warranty.  It may be used without
 *   restriction, but if you modify it, please change the filenames to
 *   prevent confusion between different versions.
 * Bug reports: Sam Buss, sbuss@ucsd.edu.
 * Web page: http://math.ucsd.edu/~sbuss/MathCG
 *
 * Version 1.1.  Updated September 28, 2003.
 *   1.1. 9/28/30: Added glEnable(GL_DEPTH_TEST).  Thanks to Rob Wilkens.
 *   1.0. Original version released Spring 2003.
 *
 */



void drawFilledCircle(GLfloat x, GLfloat y, GLfloat radius);

// These variables control the current mode
int CurrentMode = 0;
const int NumModes = 5;

// These variables set the dimensions of the rectanglar region we wish to view.
const double Xmin = 0.0, Xmax = 1000.0;
const double Ymin = 0.0, Ymax = 1000.0;

// glutKeyboardFunc is called below to set this function to handle
//		all "normal" ascii key presses.
// Only space bar and escape key have an effect.
void myKeyboardFunc(unsigned char key, int x, int y)
{
	switch (key) {

	case ' ':									// Space bar
		// Increment the current mode, and tell operating system screen needs redrawing
		CurrentMode = (CurrentMode + 1) % NumModes;
		CurrentMode = 1;

		glutPostRedisplay();
		break;

	case 27:									// "27" is theEscape key
		exit(1);

	}
}


/*
 * drawScene() handles the animation and the redrawing of the
 *		graphics window contents.
 */
void drawScene(void)
{
	// Clear the rendering window
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Set drawing color to white


	//glVertex2f(500.0, 500.0);
	//glVertex2f(500 + 100.0, 500 + 100.0);
	//glVertex2f(500 + 200.0, 500 + 0100.0);
	//glVertex2f(500 + 200.0, 500 + 200.0);
	glColor3f(0.0, 0, 10);

	for (int i = 0; i < 10; i++)
	{
		glVertex2f(500 + vishwa.star_list[i].x,500 + vishwa.star_list[i].y);
	}

	glVertex2f(500 + 100.0, 500 + 0.50);
	glEnd();


	//drawFilledCircle(500, 500, 100);

	// Flush the pipeline.  (Not usually necessary.)
	glFlush();

}

// Initialize OpenGL's rendering modes
void initRendering()
{

	glEnable(GL_DEPTH_TEST);

	// Uncomment out the first block of code below, and then the second block,
	//		to see how they affect line and point drawing.
/*
	// The following commands should cause points and line to be drawn larger
	//	than a single pixel width.
	glPointSize(8);
	glLineWidth(5);
*/

/*
	// The following commands should induce OpenGL to create round points and
	//	antialias points and lines.  (This is implementation dependent unfortunately).
	glEnable(GL_POINT_SMOOTH);
	glEnable(GL_LINE_SMOOTH);
	glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);	// Make round points, not square points
	glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);		// Antialias the lines
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
*/

}

// Called when the window is resized
//		w, h - width and height of the window in pixels.
void resizeWindow(int w, int h)
{
	double scale, center;
	double windowXmin, windowXmax, windowYmin, windowYmax;

	// Define the portion of the window used for OpenGL rendering.
	glViewport(0, 0, w, h);	// View port uses whole window

	// Set up the projection view matrix: orthographic projection
	// Determine the min and max values for x and y that should appear in the window.
	// The complication is that the aspect ratio of the window may not match the
	//		aspect ratio of the scene we want to view.
	w = (w == 0) ? 1 : w;
	h = (h == 0) ? 1 : h;
	if ((Xmax - Xmin) / w < (Ymax - Ymin) / h) {
		scale = ((Ymax - Ymin) / h) / ((Xmax - Xmin) / w);
		center = (Xmax + Xmin) / 2;
		windowXmin = center - (center - Xmin) * scale;
		windowXmax = center + (Xmax - center) * scale;
		windowYmin = Ymin;
		windowYmax = Ymax;
	}
	else {
		scale = ((Xmax - Xmin) / w) / ((Ymax - Ymin) / h);
		center = (Ymax + Ymin) / 2;
		windowYmin = center - (center - Ymin) * scale;
		windowYmax = center + (Ymax - center) * scale;
		windowXmin = Xmin;
		windowXmax = Xmax;
	}

	// Now that we know the max & min values for x & y that should be visible in the window,
	//		we set up the orthographic projection.
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(windowXmin, windowXmax, windowYmin, windowYmax, -1, 1);

}


// Main routine
// Set up OpenGL, define the callbacks and start the main loop
int main(int argc, char** argv)
{
	glutInit(&argc, argv);

	// The image is not animated so single buffering is OK. 
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);

	// Window position (from top corner), and size (width and hieght)
	glutInitWindowPosition(5, 5);
	glutInitWindowSize(1000, 1000);
	glutCreateWindow("SimpleDraw - Press space bar to toggle images");

	// Initialize OpenGL as we like it..
	initRendering();		

	// Set up callback functions for key presses
	glutKeyboardFunc(myKeyboardFunc);			// Handles "normal" ascii symbols
	// glutSpecialFunc( mySpecialKeyFunc );		// Handles "special" keyboard keys

	// Set up the callback function for resizing windows
	glutReshapeFunc(resizeWindow);

	// Call this for background processing
	// glutIdleFunc( myIdleFunction );

	// call this whenever window needs redrawing

	initialize();
	while (1)
	{
		stars_move();	//universe moves
		glutDisplayFunc(drawScene);
	}

	fprintf(stdout, "Press space bar to toggle images; escape button to quit.\n");

	// Start the main loop.  glutMainLoop never returns.
	glutMainLoop();

	return(0);	// This line is never reached.
}

/*
*Function that handles the drawing of a circle using the line loop
* method.This will create a hollow circle.
*
* Params:
* x(GLFloat) - the x position of the center point of the circle
* y(GLFloat) - the y position of the center point of the circle
* radius(GLFloat) - the radius that the painted circle will have
*/

void drawHollowCircle(GLfloat x, GLfloat y, GLfloat radius)
{
	int i;
	int lineAmount = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * 3.141592;

	glBegin(GL_LINE_LOOP);
	for (i = 0; i <= lineAmount; i++) {
		glVertex2f(
			x + (radius * cos(i * twicePi / lineAmount)),
			y + (radius * sin(i * twicePi / lineAmount))
		);
	}
	glEnd();
}

/*
 * 
 *	Function that handles the drawing of a circle using the triangle fan
 *	method. This will create a filled circle.
 *
 *	Params:
 *	x (GLFloat) - the x position of the center point of the circle
 *	y (GLFloat) - the y position of the center point of the circle
 *	radius (GLFloat) - the radius that the painted circle will have
 * 
 */

void drawFilledCircle(GLfloat x, GLfloat y, GLfloat radius) {
	int i;
	int triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * 3.141592;

	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(x, y); // center of circle
	for (i = 0; i <= triangleAmount; i++) {
		glVertex2f(
			x + (radius * cos(i * twicePi / triangleAmount)),
			y + (radius * sin(i * twicePi / triangleAmount))
		);
	}
	glEnd(); 
}