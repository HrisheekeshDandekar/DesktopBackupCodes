#include<stdio.h>
#include<stdbool.h>

int play_chess_loop();
int chess_board_set();
bool game_proceeds();
int rematch_asked(bool* play_on);
int pieces_set();

int main()
{
	pieces_set();
	play_chess_loop();
	return 0;
}

		/*--------- BLACK PIECES STRUCTS ---------*/

struct B_King
{
	char c_x_pos;
	int y_pos;
};

struct W_King
{
	char c_x_pos;
	int y_pos;
};
struct B_pawn
{
	int total_alive;
	char* c_x_pos;
	int* y_pos;
};

struct W_pawn
{
	int total_alive;
	char* c_x_pos;
	int* y_pos;
};


struct B_bishop	
{
	int total_alive;
	char* c_x_pos;
	int* y_pos;
};

struct W_bishop
{
	int total_alive;
	char* c_x_pos;
	int* y_pos; 
};

struct B_knight
{
	int total_alive;
	char* c_x_pos;
	int* y_pos;
};

			/*--------- WHITE PIECES STRUCTS ---------*/

struct W_knight
{
	char c_x_pos;
	int y_pos;
};
struct B_rook
{
	int total_alive;
	char* c_x_pos;
	int* y_pos;
};
struct W_rook
{
	int total_alive;
	char* c_x_pos;
	int* y_pos;
};
struct B_queen
{
	int total_alive;
	char* c_x_pos;
	int* y_pos;
};
struct W_queen
{
	int total_alive;
	char* c_x_pos;
	int* y_pos;
};


struct Black_pieces
{
	struct B_King K;
	struct B_pawn p;
	struct B_bishop b;
	struct B_knight k;
	struct B_rook r;
	struct B_queen q;
};

struct White_pieces
{
	struct W_King K;
	struct W_pawn p;
	struct W_bishop b;
	struct W_knight k;
	struct W_rook r;
	struct W_queen q;
};

struct Black_pieces B;
struct White_pieces W;

int play_chess_loop()
{
	bool play_on = true;
	while (play_on == true)
	{
		chess_board_set();
		game_proceeds();
		rematch_asked(&play_on);
	}

	return 0;
}

int chess_board_set()
{
	int ac; 
}


bool game_proceeds()
{
	
}

int rematch_asked(bool* play_on)
{

}

int board_display(int black_pieces, int white_pieces)
{

}

int pieces_set()	//Resetting values for playing another game;
{
	free(B.K);
	free(B.p);
	free(B.b);
	free(B.k);
	free(B.r);
	free(B.q);

	free(W.K);
	free(W.p);
	free(W.b);
	free(W.k);
	free(W.r);
	free(W.q);

	B.K = ()

} 