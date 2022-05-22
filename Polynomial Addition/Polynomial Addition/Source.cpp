						#include<iostream>
						#include<vector>

						int polynomial_inputs();
						int add_polynomials(int tot_terms_1, int tot_terms_2, struct Polynomial first_input[], struct Polynomial second_input[]);

						using namespace std;

						struct Polynomial
						{
							int coefficient;
							int exponant;
						};


						int main()
						{
							polynomial_inputs();
						}

						int polynomial_inputs()
						{
							int tot_terms_1, tot_terms_2;

							cout << "Enter number of terms in first polynomail : ";
							cin >> tot_terms_1;

							Polynomial* first_input;
							first_input = (Polynomial*)malloc(tot_terms_1 * sizeof(Polynomial));

							cout << "\n\n---------=========   { Expression 1 }   =========---------\n\n";
							for (int i = 0; i < tot_terms_1; i++)
							{



								cout << "Enter Coefficient of term ( " << i + 1 << " ) {with sign} : ";
								cin >> first_input[i].coefficient;

								cout << "Enter Exponant of of the first term ( " << i + 1 << " ) {with sign} : ";
								cin >> first_input[i].exponant;
							}

							cout << "\n\n Your First Expression : ";		//Displaying Expression
							for (int i = 0; i < tot_terms_1; i++)
							{
								cout << first_input[i].coefficient << "x^" << first_input[i].exponant << " ";
							}

							cout << "\n\n---------=========   { Expression 2 }   =========---------\n\n";

							cout << "Enter number of terms in second polynomail : ";
							cin >> tot_terms_2;

							Polynomial* second_input;
							second_input = (Polynomial*)malloc(tot_terms_2 * sizeof(Polynomial));

							for (int i = 0; i < tot_terms_2; i++)
							{

								cout << "Enter Coefficient of term ( " << i + 1 << " ) {with sign} : ";
								cin >> second_input[i].coefficient;

								cout << "Enter Exponant of of the first term ( " << i + 1 << " ) {with sign} : ";
								cin >> second_input[i].exponant;
							}

							cout << "\n\n Your Secoond Expression : ";		//Displaying Expression
							for (int i = 0; i < tot_terms_2; i++)
							{
								cout << second_input[i].coefficient << "x^" << second_input[i].exponant << " ";
							}
							add_polynomials(tot_terms_1, tot_terms_2, first_input, second_input);
							return 0;
						}

						int add_polynomials(int tot_terms_1, int tot_terms_2, struct Polynomial first_input[], struct Polynomial second_input[])
						{

							int answer_terms = tot_terms_1 + tot_terms_2;
							int same_exp_flag = 0;
							int answer_pos = 0;
							int temp_coeff = 0;
							int check_exponant = 0;

							/*for (int i = 0; i < tot_terms_1; i++)
							{
								for (int j = 0; j < tot_terms_2; j++)
								{
									if (first_input[i].exponant == second_input->exponant)
									{
										same_exp_flag++;
									}
								}
							}*/


							Polynomial* answer;
							answer = (Polynomial*)malloc(answer_terms * sizeof(Polynomial));



/*Comments much?*/			for (int i = 0; i < tot_terms_1; i++)
							{
								temp_coeff = first_input[i].coefficient;

								for (int j = 0; j < tot_terms_2; j++)
								{

									if (first_input[i].exponant == second_input[i].exponant)
									{
										temp_coeff += second_input[i].coefficient;
									}
								}
								answer[answer_pos].coefficient = temp_coeff;
								answer[answer_pos].exponant = first_input[i].exponant;
								answer_pos++;
							}	


							for (int i = 0; i < tot_terms_2; i++)
							{
								check_exponant = second_input[i].exponant;
								for (int j = 0; j < answer_terms; j++)
								{

								}
							}


							return 0;
						}
