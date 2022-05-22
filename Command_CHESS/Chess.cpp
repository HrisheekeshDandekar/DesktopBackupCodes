/*								[CHESS]
* 
* Pseudo Code:
*	[Set all the values for pieces to default]
*		(Co_ordinates,numbers,first_move_status reset)
*	[Move is made]
*		(Check for illegal move)
*		(check for piece takes)
*		(check for pawn promotion)
*		(check for check) - (If found show message)
*		(check for castle)
*			(Cannot castle if king,rook has been moved before)
*			(Cannot castle if the king is under check)
*			(Cannot castle if the place the king would land is under attack)
*			(Cannot castle if pieces are in between duh)
*	[Board adjusted according to the move made]
*		(Check illegal moves count and if exceeded 3, end game)
*		(Check for check-mate) - (If found, show winner in 3 seconds)
*			(If game has ended, ask for a rematch)
*				(If rematch accepted, go to reset values)
*		(If game has not ended, rotate the board and ask for input from other player)
*	
*/

#include <iostream>
#include <vector>


struct B_King;
struct B_pawn;
struct B_bishop;
struct B_knight;
struct B_rook;
struct B_queen;

struct W_King;
struct W_pawn;
struct W_bishop;
struct W_knight;
struct W_rook;
struct W_queen;

class Pieces
{
public:
	int pieces_reset();
	int piece_dies();
	int pawn_promoted();
	int empassant_check();

private:
	struct B_King B_K;
	struct B_pawn B_p;
	struct B_bishop B_b;
	struct B_knight B_k;
	struct B_rook B_r;
	struct B_queen B_q;

	struct W_King W_K;
	struct W_pawn W_p;
	struct W_bishop W_b;
	struct W_knight W_k;
	struct W_rook W_r;
	struct W_queen W_q;
};

class Chess_board
{
public:

	int chess_board_set();
	int game_proceeds();
	int move_made();
	int illegal_checked();
	int check_mate_checked();
	int rematch_asked(bool* play_on);
	
private:
	int c_white_illegals;
	int c_black_illegals;


};

int play_chess();


int main()
{
	play_chess();
}

int play_chess()
{
	bool play_on = true;
	while (play_on == true)
	{
		chess_board_set();
		game_proceeds();
		rematch_asked(&play_on);
	}
}

		/*--------- BLACK PIECES STRUCTS ---------*/

struct B_King
{
	bool first_move_done;
	int x_pos;
	int y_pos;
};
struct B_pawn
{
	int total_alive;
	bool *first_move_done;
	int* x_pos;
	int* y_pos;
};
struct B_bishop
{
	int total_alive;
	int* x_pos;
	int* y_pos;
};
struct B_knight
{
	int total_alive;
	int* x_pos;
	int* y_pos;
};
struct B_rook
{
	int total_alive;
	bool* first_move_done;
	int* x_pos;
	int* y_pos;
};
struct B_queen
{
	int total_alive;
	int* x_pos;
	int* y_pos;
};

			/*--------- WHITE PIECES STRUCTS ---------*/

struct W_King
{
	bool first_move_done;
	int x_pos;;
	int y_pos;
};
struct W_pawn
{
	int total_alive;
	bool* first_move_done;
	int* x_pos;
	int* y_pos;
};
struct W_bishop
{
	int total_alive;
	int* x_pos;
	int* y_pos;
};
struct W_knight
{
	char c_x_pos;
	int y_pos;
};
struct W_rook
{
	int total_alive;
	bool* first_move_done;
	int* x_pos;
	int* y_pos;
};
struct W_queen
{
	int total_alive;
	int* x_pos;
	int* y_pos;
};


		/*--------- Chess_Board functions ---------*/

int Chess_board::game_proceeds()
{

	bool check_mate = false;
	while (check_mate == false)
	{
		move_made();
		illegal_checked();
		check_mate_checked();
	}
	
	
}
