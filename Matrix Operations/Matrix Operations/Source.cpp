/*
*		-----==========	{ 221018_HRISHEEKESH DANDEKAR } ==========-----
*		FDS Assignment 2 : Matrix operations
* 
*Problem Statement : 
*	[Accept conventional matrix and convert it into sparse matrix. 
*	 Implement simple transpose and Fast transpose algorithms on sparse matrix.]
*/

#include<iostream>

#define MAX_DIGITS 4

using namespace std;

class Normal_matrix
{
public:
	int** matrix_array;
	int rows;
	int columns;

	Normal_matrix()		//Matrix dimensions inputs
	{
		cout << "\n============[ Matrix Input ]============\n\n";
		cout << "\nEnter number of rows in the matrix : ";
		cin >> rows;	
		cout << "\nEnter number of columns in the matrix : ";
		cin >> columns;
	}

	Normal_matrix(int r, int c)		//Constructor overloaded in case rows and columns are  to be passed directly
	{
		rows = r;
		columns = c;
		
	}

	void take_inputs();
	void display_matrix();

	~Normal_matrix();
};


class Sparse_matrix : public Normal_matrix 
{
public:
	int non_zero = 0;	//Stores total non zero elements

	struct Sparse
	{
		int* sparse_row_val;
		int* sparse_col_val;
		int* sparse_value_column;
		int total_rows;
	};
	struct Sparse sparse_representation;	

	void show_total_nonzero_elements();
	void convert_to_sparse();
	void show_sparse_representation();
	void show_memory_saved_or_wasted();

};

class Normal_transpose : public Sparse_matrix
{
public:
	struct Transpose
	{
		int* transpose_rows;
		int* transpose_columns;
		int* value_column;

		int total_elements;
		int non_zero;
	};
	
	struct Transpose normal_transpose;

	void find_transpose_normal_method();
	void display_normal_transpose();
	

};

class Fast_transpose : public Normal_transpose
{
public:
	struct Fast_tranpose
	{
		int* ftranspose_row;
		int* f_tranpose_col;
		int* ftranspoe_val;
	};

	struct Fast_tranpose fast_tranpose;

		//Arrays for calculating transpose via fast tranpose method;
	int* column_occurance;
	int* starting_pos;
	
	void find_transpose_fast_method();
	void display_fast_transpose_results();
	void fill_occurance_n_startingpos_arr();
	void allocate_memory_for_transpose_struct();
};

int main()
{
	Fast_transpose matrix;
	matrix.take_inputs();
	matrix.display_matrix();
	matrix.show_total_nonzero_elements();
	matrix.convert_to_sparse();
	matrix.show_sparse_representation();
	matrix.show_memory_saved_or_wasted();
	matrix.find_transpose_normal_method();
	matrix.display_normal_transpose();
	matrix.find_transpose_fast_method();
	matrix.display_fast_transpose_results();
	return 0;
}

					/* ================== [Normal_matrix class functions] ================== */

void Normal_matrix :: take_inputs()
{

	//Dynamically allocating memory to matrix
	//matrix_array = (int**)malloc(rows * sizeof(int*));
	matrix_array = new int*[rows];
	for (int i = 0; i < rows; i++)
		matrix_array[i] = new int[columns];
	//matrix_array[i] = (int*)malloc(columns * sizeof(int));

	//Taking user Input to fill the matrix
	cout << "\nEnter row elements separated by [Space]. Elements in a row = [ " << columns << " ]\n\n";
	for (int i = 0; i < rows; i++)
	{
		cout << "\tEnter row [ " << i + 1 << " ]  :  ";
		for (int j = 0; j < columns; j++)
		{
			cin >> matrix_array[i][j];		//Filling up each element
		}

	}
}

void Normal_matrix :: display_matrix()
{
	cout << "\n\nEntered Matrix dimensions [ " << rows << " ] x [ " << columns << " ] \n\n\t";
	for (int i = 0; i < rows; i++)
	{
		cout << "|";
		for (int j = 0; j < columns; j++)
		{
			cout.width(MAX_DIGITS);			//Sets width for automatic padding 
									//matrix layout will not break for numbers of 4 digits or less
			cout << left << matrix_array[i][j] << "|";		//Left specifies the padding should be at right
		}
		cout << "\n\t";
	}
	cout << "\n\t";
}

Normal_matrix::~Normal_matrix()
{
	//Freeing Dynamically allocated memory
	for (int i = 0; i < rows; i++)
		delete[] matrix_array[i];

	delete[] matrix_array;
}

		/* ================== [Sparse_matrix class functions] ================== */


void Sparse_matrix :: show_total_nonzero_elements()
{
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			if (matrix_array[i][j] != 0)
				non_zero++;

	cout << "\n\nEntered Matrix dimensions [ " << rows << " ] x [ " << columns << " ] \n\n\t";
	for (int i = 0; i < rows; i++)
	{
		cout << "|";
		for (int j = 0; j < columns; j++)
		{
			cout.width(MAX_DIGITS);			//Sets width for automatic padding 
									//matrix layout will not break for numbers of 4 digits or less
			if (matrix_array[i][j] != 0)
			{
				cout << "\033[1m\033[34m";
				cout.width(MAX_DIGITS);
			}
			cout << left << matrix_array[i][j] << "\033[0m|";		//Left specifies the padding should be after content to be padded
		}
		cout << "\n\t";
	}
	cout << "\n\t";

	cout << "Total Non-Zero elements = " << non_zero << endl;
	
	if (non_zero > (rows * columns) / 2)	//Displaying a warning if the entered matrix is not a sparse matrix
		cout << "\n\n\t\033[1m\033[35mThe entered matrix is NOT a sparse matrix\033[0m\n";
	

}

void Sparse_matrix :: convert_to_sparse()
{
	int tot_rows = non_zero + 1;				//0th row for storing the number of rows, 
	sparse_representation.total_rows = tot_rows;		//columns and non zero elements in normal matrix

				//Allocating memory for sparse matrix
	sparse_representation.sparse_row_val = new int[non_zero + 1];
	sparse_representation.sparse_col_val = new int[non_zero + 1];
	sparse_representation.sparse_value_column = new int[non_zero + 1];


	//Setting the first row
	sparse_representation.sparse_row_val[0] = rows;		//Rows in normal matrix
	sparse_representation.sparse_col_val[0] = columns;	//Columns in normal matrix
	sparse_representation.sparse_value_column[0] = non_zero;	//Total non zero elements

	int sparse_counter = 1;

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			if (matrix_array[i][j] != 0)
			{
				sparse_representation.sparse_row_val[sparse_counter] = i;
				sparse_representation.sparse_col_val[sparse_counter] = j;
				sparse_representation.sparse_value_column[sparse_counter] = matrix_array[i][j];

				sparse_counter++;
			}

}

void Sparse_matrix :: show_sparse_representation()
{
	cout << "\n\n\t-------- Sparse Representation --------\n\n";

	cout << "\n\t\033[1m\033[32m Row  \033[1m\033[34mCol  \033[1m\033[33mVal\033[0m\n\t";
	for (int i = 0; i < sparse_representation.total_rows; i++)
	{
		cout << "|\033[1m\033[32m";
		cout.width(MAX_DIGITS);
		cout << sparse_representation.sparse_row_val[i] << "\033[0m|";
				
		cout << "\033[1m\033[34m";
		cout.width(MAX_DIGITS);
		cout << sparse_representation.sparse_col_val[i] << "\033[0m|";

		cout << "\033[1m\033[33m"; 
		cout.width(MAX_DIGITS);
		cout << sparse_representation.sparse_value_column[i] << "\033[0m|";

		cout << "\n\t";
	}
}

void Sparse_matrix::show_memory_saved_or_wasted()
{
	int matrix_size;
	int sparse_size;

	matrix_size = rows * columns * sizeof(int);
	sparse_size = (non_zero + 1) * 3 * sizeof(int);

	if (sparse_size < matrix_size)
	{
		cout << "\n\n========== Memory \033[1m\033[32mSAVED\033[0m !!! ==========\n\n";
		cout << "\nMemory saved by sparse representation = \033[1m\033[32m" << matrix_size - sparse_size << "\033[0m bytes";
	}
	else if(matrix_size < sparse_size)
	{
		cout << "\n\n========== Memory \033[1m\033[31mWASTED\033[0m !!! ==========\n\n";
		cout << "\nMemory wasted by sparse representation = \033[1m\033[31m" << sparse_size - matrix_size << "\033[0m bytes";
		cout << "\n{ Sparse matrix is only useful if number of zero elements exceed non-zeros by \033[1m\033[36mmore than 3 times\033[0m ! }\n";
	}
	else
	{
		cout << "\n\n========== \033[1m\033[33mSame Size Required\033[0m ==========\n\n";
		cout << "\nMemory required for normal matrix , sparse representation = \033[1m\033[33m" << matrix_size << "\033[0m bites";
	}
}
	
			/* ================== [Normal_transpose class functions] ================== */


void Normal_transpose :: find_transpose_normal_method()
{
			//Allocating memory for Transpose struct
	normal_transpose.non_zero = sparse_representation.sparse_value_column[0];
	normal_transpose.total_elements = sparse_representation.total_rows;

	normal_transpose.transpose_rows = new int[non_zero + 1];
	normal_transpose.transpose_columns = new int[non_zero + 1];
	normal_transpose.value_column = new int[non_zero + 1];

			//Setting values for first row
	normal_transpose.transpose_rows[0] = sparse_representation.sparse_col_val[0];	//Total rows are now total columns
	normal_transpose.transpose_columns[0] = sparse_representation.sparse_row_val[0];	//Total columns are now total rows
	normal_transpose.value_column[0] = sparse_representation.sparse_value_column[0];	//Total non zero elements remain same

	int nxt = 1;
	for (int i = 0; i < sparse_representation.sparse_col_val[0]; i++)
		for (int j = 1; j <= sparse_representation.sparse_value_column[0]; j++)
			if (sparse_representation.sparse_col_val[j] == i)
			{
				normal_transpose.transpose_rows[nxt] = sparse_representation.sparse_col_val[j];
				normal_transpose.transpose_columns[nxt] = sparse_representation.sparse_row_val[j];
				normal_transpose.value_column[nxt] = sparse_representation.sparse_value_column[j];
				nxt++;
			}	

}

void Normal_transpose :: display_normal_transpose()
{
	cout << "\n\n\t-------- Normal transpose of Sparse Representation --------\n\n";

	cout << "\n\t\033[1m\033[32m Row  \033[1m\033[34mCol  \033[1m\033[33mVal\033[0m\n\t";
	for (int i = 0; i < normal_transpose.total_elements; i++)
	{
		cout << "|\033[1m\033[32m";
		cout.width(MAX_DIGITS);
		cout << normal_transpose.transpose_rows[i] << "\033[0m|";

		cout << "\033[1m\033[34m";
		cout.width(MAX_DIGITS);
		cout << normal_transpose.transpose_columns[i] << "\033[0m|";

		cout << "\033[1m\033[33m";
		cout.width(MAX_DIGITS);
		cout << normal_transpose.value_column[i] << "\033[0m|";

		cout << "\n\t";
	}
}


			/* ================== [Fast_transpose class functions] ================== */


void Fast_transpose :: find_transpose_fast_method()
{


	allocate_memory_for_transpose_struct();
	fill_occurance_n_startingpos_arr();
	
	fast_tranpose.ftranspose_row[0] = sparse_representation.sparse_col_val[0];
	fast_tranpose.f_tranpose_col[0] = sparse_representation.sparse_row_val[0];
	fast_tranpose.ftranspoe_val[0] = sparse_representation.sparse_value_column[0];

	for (int i = 1; i < non_zero + 1; i++)
	{
		fast_tranpose.ftranspose_row[starting_pos[sparse_representation.sparse_col_val[i]]] = sparse_representation.sparse_col_val[i];
		fast_tranpose.f_tranpose_col[starting_pos[sparse_representation.sparse_col_val[i]]] = sparse_representation.sparse_row_val[i];
		fast_tranpose.ftranspoe_val[starting_pos[sparse_representation.sparse_col_val[i]]] = sparse_representation.sparse_value_column[i];

		starting_pos[sparse_representation.sparse_col_val[i]]++;
	}


}

void Fast_transpose ::fill_occurance_n_startingpos_arr()
{

	/*
	* For this method, 3 arrays needed
	*		1 } non_zero_in_col
	*				(array stores no of non zero values in that column)
	*
	*		2 } index_pos
	*				(Contains the index at which the column should be placed in transpose array)
	*				[rule to be noted -- Index of 0th col has to be 1 (first non-zero element of the matrix)]
	*				[ Formula for other elements -- index_pos[i] = index_pos[i-1] + non_zero_total[i-1] ]
	*				(Size of index_pos is total_number of column values)
	*/

	//column_occurance = (int*)malloc(sparse_representation.sparse_col_val[0] * sizeof(int));	//Arr size eq to no of columns
	column_occurance = new int[columns];
	//starting_pos = (int*)malloc(sparse_representation.sparse_col_val[0] * sizeof(int));	//Arr size eq to no of columns 
	starting_pos = new int[columns];

	//Initializing column occurance terms to 0
	for (int i = 0; i < columns; i++)
		column_occurance[i] = 0;


	//Filling out row_terms which contain number of non-zero elements occuring at that column
	for (int i = 1; i < non_zero + 1; i++)
		column_occurance[sparse_representation.sparse_col_val[i]]++;


	//Starting pos of the column values has its 0th element set to 1 as 0th row in sparse representation is occupied by its details
	starting_pos[0] = 1;


	//Rest of the elements are filled by using formula starting_pos[i] = starting_pos[i-1] + row_terms[i-1] 
	for (int i = 1; i < sparse_representation.sparse_col_val[0]; i++)
		starting_pos[i] = starting_pos[i - 1] + column_occurance[i - 1];

}										


void Fast_transpose::allocate_memory_for_transpose_struct()
{
	fast_tranpose.ftranspose_row = new int[non_zero + 1];
	fast_tranpose.f_tranpose_col= new int[non_zero + 1];
	fast_tranpose.ftranspoe_val = new int[non_zero + 1];
}

void Fast_transpose::display_fast_transpose_results()
{
	cout << "\n\n\t-------- FAST transpose of Sparse Representation --------\n\n";

	cout << "\n\t\033[1m\033[32m Row  \033[1m\033[34mCol  \033[1m\033[33mVal\033[0m\n\t";
	for (int i = 0; i < non_zero + 1; i++)
	{
		cout << "|\033[1m\033[32m";
		cout.width(MAX_DIGITS);
		cout << fast_tranpose.ftranspose_row[i] << "\033[0m|";

		cout << "\033[1m\033[34m";
		cout.width(MAX_DIGITS);
		cout << fast_tranpose.f_tranpose_col[i] << "\033[0m|";

		cout << "\033[1m\033[33m";
		cout.width(MAX_DIGITS);
		cout << fast_tranpose.ftranspoe_val[i] << "\033[0m|";

		cout << "\n\t";
	}
}