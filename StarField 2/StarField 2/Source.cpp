/*
* Psudo Code:
*	{Universe Contains stars}
*	{We view the universe as a starfield}
*		[Stars are born and destroyed]
*		[Stars are moving at speed X]
*		[Maximum stars that can exist is Y]
*		[Maximum stars born at a time is Z	(Z<=Y) ]
*		[Stars are destroyed after they reach a certain boundry]	//Universe is finite and has boundries
*		[Star is visible till it crosses universe boundries]
*		
*	{Star properties}
*		[Star has position x,y , size z ,  speed s, alive status t||f]
*		[Star is born when there is space for it]
*		[Star dies after crossing the boundries]
*		
*/
#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<math.h>


#define UPPPER_BOUND 400
#define LOWER_BOUND 0

using namespace std;

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

int main()
{
// 	initialize(vishwa);

	//Innitializing
	vishwa.big_bang = true;
	vishwa.boundry = 400;
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


	while (true)	//Universe moves forever	-------		ADD DELAY-------
	{
		stars_move();	//universe moves
		//show_cordinates(vishwa);
		//break if inturrupt bigbang
	}

}


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
		for (int j = 0; j < stars_to_create ; j++)
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
			int seed = time(0)+i*i;

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

			
			show_star(i);
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
		printf("\n------------------\nStar Killed  : %d\n------------------\n", pos);
		star_dies(pos);
	}
	else
	{
		show_star(pos);
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
	vishwa.boundry = 400;	
	vishwa.maximum_stars = 10;	//Ransdomize later
	vishwa.max_stars_born = 3;	//Ransdomize later (upperbound less than max stars)

	for (int i = 0; i < 10; i++)
	{
		vishwa.star_list[i].alive = false;
		vishwa.star_list[i].speed= 0;		
		vishwa.star_list[i].x = 0;
		vishwa.star_list[i].y = 0;
		vishwa.star_list[i].size = 0;
		vishwa.star_list[i].time_alive = 0;
		vishwa.star_list[i].red = 0;
		vishwa.star_list[i].green = 0;
		vishwa.star_list[i].blue= 0; 
	}
	return 0;
}

//temp function : display co_ordinaltes
void show_cordinates()
{
	for (int i = 0; i < vishwa.maximum_stars; i++)
	{
		printf("\nStar no [%d]	|x : %d|	|y : %d|  " , i,vishwa.star_list[i].x , vishwa.star_list[i].y);
		printf("\nAlive status : ");
		printf(vishwa.star_list[i].alive==1?"Alive\n":"Dead\n");
	}
}

int kill_after_reaching()
{
	int max_boundrey = sqrt((vishwa.boundry / 2) * (vishwa.boundry / 2));
	return max_boundrey;
}

