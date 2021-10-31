/*                                                *************Chess Game in C++***************
                                                 Created by: Abdullah Sheikh (abdullahsh123@hotmail
                                               If you find any error must fix or improve this project
                                               
                                                   Language C++ concepts Object Oriented Programming (OOP)
Concepts which use in this program:
Classes
Polymarphism 
Programming Fundatmentals basic concepts 
Dynamic Array (1D,2D)
*/



#include <iostream>
#include <string>
#include<windows.h>
#include <conio.h>
using namespace std;
int player1score = 0;
int player2score = 0;
class piece
{
protected:
	string name;
	int num;
public:
	friend void initialize(piece *board);
	piece()
	{
		name = "  ";
		num = 0;
	}
	virtual string getname()
	{
		return name;
	}
	void setname(string s)
	{
		name = s;
	}
	char token_num()
	{
		return name[1];
	}
	virtual void move(int x1, int y1, int x2, int y2,char& i){};
	

};
piece *board[8][8];
void set_move(int x1, int y1, int x2, int y2,char &i)
{
	if (board[x2][y2]->getname() != "  ")
	{
		if (i == '1')
		{
			++ player1score ;
		}
		else if (i == '2')
		{
			++player2score;
		}
	}
	board[x2][y2] = board[x1][y1];
	board[x1][y1] = new piece();
	//delete board[x1][y1];
}
class pawn :public piece
{

public:
	friend void initialize(piece *board);
	pawn(string n)
	{
		name = n;
	}

	void move(int x1, int y1, int x2, int y2,char& i)
	{
		if (board[x1][y1]->token_num() == '1' && board[x1][y1]->token_num() == i)
		{
			if ((x2 == x1 + 2) && (x1 == 1))
			{
				set_move(x1, y1, x2, y2,i);
			}
			if (x2 == x1 + 1)
			{
				if (y2 == y1 - 1 || y2 == y1 + 1)
				{
					if (board[x1][y1]->token_num() != board[x2][y2]->token_num())
					{
						set_move(x1, y1, x2, y2,i);
					}
					else
					{
						cout << "Can't move to this index\n";
					}
				}
				else
				{
					set_move(x1, y1, x2, y2,i);
				}
			}
		}
		else
		{
			--i;
		}


		if (board[x1][y1]->token_num() == '2' && board[x1][y1]->token_num() == i)
		{
			if ((x2 == x1 - 2) && (x1 == 6))
			{
				set_move(x1, y1, x2, y2, i);
			}
			if (x2 == x1 - 1)
			{
				if (y2 == y1 - 1 || y2 == y1 + 1)
				{
					if (board[x1][y1]->token_num() != board[x2][y2]->token_num())
					{
						set_move(x1, y1, x2, y2, i);
					}
					else
					{
						cout << "Can't move to this index\n";
					}
				}
				else
				{
					set_move(x1, y1, x2, y2, i);
				}
			}
		}
		else
		{
			--i;
		}

}

	string getname()
	{
		return name;
	}
};

class rook :public piece
{
public:
	rook()
	{

	}
	rook(string n)
	{
		name = n;
	}

	void move(int x1, int y1, int x2, int y2,char& i)
	{
		bool check = true;
		if (board[x1][y1]->token_num() == i)
		{
			if (y1 == y2)
			{
				for (int k = x1 + 1; k <= x2; k++)
				{
					if (board[k][y1]->getname() != "  ")
					{
						cout << "Invalid Move\n";
						check = false;
					}
				}
				if (check == true)
				{
					set_move(x1, y1, x2, y2,i);
				}
			}
			else if (x1 == x2)
			{
				for (int k = y1; k <= y2; k++)
				{
					if (board[k][y1] == new piece())
					{
						cout << "Invalid Move\n";
						check = false;
					}
				}
				if (check == true)
				{
					set_move(x1, y1, x2, y2,i);
				}
			}
			else
				cout << "Invalid Move\n";
		}
		else
		{
			--i;
		}
	}
	};
	class  bishop :public piece
	{
	public:
		bishop(string n)
		{
			name = n;
		}
		void move(int x1, int y1, int x2, int y2,char& i)
		{
			if (board[x1][y1]->token_num() == i)
			{
				if (x2 > x1 &&y2 > y1)
				{
					int k, j;
					bool check = true;
					for (k = x1 + 1, j = y1 + 1; k< x2, j < y2; k++, j++)
					{
						if (board[k][j]->getname() != "  ")
						{
							check = false;
							break;
						}
					}
					if (check == false)
					{
						set_move(x1, y1, k- 1, j - 1,i);
					}
					if (check == true)
					{
						set_move(x1, y1, x2, y2,i);
					}
				}
				else if (x2 < x1 &&y2 > y1)
				{
					int k, j;
					bool check = true;
					for (k = x2 - 1, j = y1 + 1; k < x1, j < y2; k--, j++)
					{
						if (board[k][j]->getname() != "  ")
						{
							check = false;
							break;
						}
					}
					if (check == false)
					{
						set_move(x1, y1, k + 1, j - 1,i);
					}
					if (check == true)
					{
						set_move(x1, y1, x2, y2,i);
					}
				}
				else if (x2 < x1 &&y2 < y1)
				{
					int k, j;
					bool check = true;
					for (k = x2 - 1, j = y2 - 1; k < x1, j < y2; k--, j--)
					{
						if (board[k][j]->getname() != "  ")
						{
							check = false;
							break;
						}
					}
					if (check == false)
					{
						set_move(x1, y1, k + 1, j + 1,i);
					}
					if (check == true)
					{
						set_move(x1, y1, x2, y2,i);
					}
				}
				else if (x2 > x1 &&y2 < y1)
				{
					int k, j;
					bool check = true;
				for (k = x1 + 1, j = y1 - 1; k < x2, j < y1; k++, j--)
					{
						if (board[k][j]->getname() != "  ")
						{
							check = false;
							break;
						}
					}
					if (check == false)
					{
						set_move(x1, y1, k - 1, j + 1,i);
					}
					if (check == true)
					{
						set_move(x1, y1, x2, y2,i);
					}
				}
			}
			else
			{
				--i;
			}
		}

	};
	class king :public piece
	{
	public:
		king(string n)
		{
			name = n;
		}
		void move()
		{

		}
		void move(int x1, int y1, int x2, int y2,char& i)
		{
			if (board[x1][y1]->token_num() == i)
			{
				if ((x2 == x1 + 1 && y2 == y1) || (x2 == x1 - 1 && y2 == y1) || (x2 == x1&& y2 == y1 + 1) || (x2 == x1&& y2 == y1 - 1) ||
					(x2 == x1 + 1 && y2 == y1 + 1) || (x2 == x1 - 1 && y2 == y1 + 1) || (x2 == x1 + 1 && y2 == y1 - 1) || (x2 == x1 - 1 && y2 == y1 - 1))
				{
					if (board[x1][y1]->token_num() != board[x2][y2]->token_num())
					{
						set_move(x1, y1, x2, y2,i);
					}
				}
			}
			else
			{
				--i;
			}
		}
	};
	class queen :public piece
	{
	public:
		queen(string n)
		{
			name = n;
		}

		void move(int x1, int y1, int x2, int y2, char & i)
		{
			bool check = true;
			if (board[x1][y1]->token_num() == i)
			{
				if (y1 == y2)
				{
					for (int k= x1 + 1; k<= x2; i++)
					{
						if (board[i][y1]->getname() != "  ")
						{
							cout << "Invalid Move\n";
							check = false;
						}
					}
					if (check == true)
					{
						set_move(x1, y1, x2, y2, i);
					}
				}
				else if (x1 == x2)
				{
					for (int k= y1; k<= y2; k++)
					{
						if (board[k][y1] == new piece())
						{
							cout << "Invalid Move\n";
							check = false;
						}
					}
					if (check == true)
					{
						set_move(x1, y1, x2, y2, i);
					}
				}
				else
					cout << "Invalid Move\n";

				if (x2 > x1 &&y2 > y1)
				{
					int k, j;
					bool check = true;
					for (k= x1 + 1, j = y1 + 1; k< x2, j < y2; k++, j++)
					{
						if (board[k][j]->getname() != "  ")
						{
							check = false;
							break;
						}
					}
					if (check == false)
					{
						set_move(x1, y1, k- 1, j - 1, i);
					}
					if (check == true)
					{
						set_move(x1, y1, x2, y2, i);
					}
				}
				else if (x2 < x1 &&y2 > y1)
				{
					int k, j;
					bool check = true;
					for (k= x2 - 1, j = y1 + 1; k< x1, j < y2; k--, j++)
					{
						if (board[k][j]->getname() != "  ")
						{
							check = false;
							break;
						}
					}
					if (check == false)
					{
						set_move(x1, y1, k+ 1, j - 1, i);
					}
					if (check == true)
					{
						set_move(x1, y1, x2, y2, i);
					}
				}
				else if (x2 < x1 &&y2 < y1)
				{
					int k, j;
					bool check = true;
					for (k = x2 - 1, j = y2 - 1; k < x1, j < y2; k--, j--)
					{
						if (board[k][j]->getname() != "  ")
						{
							check = false;
							break;
						}
					}
					if (check == false)
					{
						set_move(x1, y1, k + 1, j + 1, i);
					}
					if (check == true)
					{
						set_move(x1, y1, x2, y2, i);
					}
				}
				else if (x2 > x1 &&y2 < y1)
				{
					int k, j;
					bool check = true;
					for (k = x1 + 1, j = y1 - 1; k < x2, j < y1; k++, j--)
					{
						if (board[k][j]->getname() != "  ")
						{
							check = false;
							break;
						}
					}
					if (check == false)
					{
						set_move(x1, y1, k - 1, j + 1, i);
					}
					if (check == true)
					{
						set_move(x1, y1, x2, y2, i);
					}
				}
			}
			else
			{
				--i;
			}
		}
	};
	class knight :public piece
	{
	public:
		knight(string n)
		{
			name = n;
		}
		void move(int x1, int y1, int x2, int y2,char & i)
		{
			if (board[x1][y1]->token_num() == i)
			{
				if (board[x1][y1]->token_num() != board[x2][y2]->token_num())
				{
					if (((x2 == x1 - 2 || x2 == x1 + 2) && (y2 == y1 + 1 || y2 == y1 - 1)) ||
						((y2 == y1 - 2 || y2 == y1 + 2) && (x2 == x1 + 1 || x2 == x1 - 1)))
					{
						set_move(x1, y1, x2, y2,i);
					}
				}
			}
			else
			{
				--i;
			}
		}
	};
	bool turn_P1[8], turn_P2[8];

	void printboard()
	{
		
		for (int i= 0; i< 8; i++)
		{
			if (i == 0)
			{
				for (int j = 0; j < 8; j++) 
				{
					cout << "    "<<j<<"   ";
				}
				cout << endl;
				for (int j = 0; j < 8; j++)
				{
					cout << " _______";
				}
				cout << endl;
			}
			for (int j = 0; j < 8; j++)
			{
				cout << "|\t";
			}
			cout << "|";
			cout << endl;
			for (int j = 0; j < 8; j++)
			{
				cout << "|   " << board[i][j]->getname() << "  ";
			}
			cout << "|   "<<i;
			cout << endl;
			for (int j = 0; j < 8; j++)
			{
				cout << "|_______";
			}
			cout << "|";
			cout << endl;
		}

	}
	void loadingprint()
	{
		     cout << "\n\n\n\n";
			 cout << "\t\t" << "****              " << " " << "      *********        " << "        **                " << " " << " ***        ***  " << " " << "    *     " << "  **   **          *** " << "       **                 " << endl;
		    cout << "\t\t" << "****              " << " " << "   ***          ***     " << "     ***   ***            " << " " << " ***        ***  " << " " << "          " << "  ***  ***         *** " << "      ***                 " << endl;
			cout << "\t\t" << "****              " << " " << " ***              ***   " << "    ***     ***           " << " " << " ***        ***  " << " " << "   ***    " << "  ***    ***       *** " << "     ***                  " << endl;
			cout << "\t\t" << "****              " << " " << " ***               ***  " << "   **************         " << " " << " ***        ***  " << " " << "   ***    " << "  ***     ***      *** " << "    ***      ************ " << endl;
			cout << "\t\t" << "****        ****  " << " " << " ***               ***  " << "  ***           ***       " << " " << " ***        ***  " << " " << "   ***    " << "  ***       ***    *** " << "     ***     ***      *** " << endl;
			cout << "\t\t" << "****        ****  " << " " << "   ***           ***    " << " ***              ***     " << " " << " ***        ***  " << " " << "   ***    " << "  ***         ***  *** " << "       ***   ***      ***" << endl;
			cout << "\t\t" << "****************  " << " " << "     ************       " << "******           ******   " << " " << " *************   " << " " << "   ***    " << "  ***           ****** " << "         *********    ***";
			
			cout << endl << endl << endl;
			cout << "\t\t\t\t   ********     ****       ****   ***************    ********      ********\n";
			cout << "\t\t\t\t  **********    ****       ****   ************      **********    **********\n";
			cout << "\t\t\t\t *****   ****   ****       ****   ***              *****   ****  *****   ****\n";
			cout << "\t\t\t\t*****           ****       ****   ***               *****         *****\n";
			cout << "\t\t\t\t*****           ****       ****   ***                *****         *****\n";
			cout << "\t\t\t\t*****           ***************   ***                 *****         *****\n";
			cout << "\t\t\t\t*****           ***************   ********             *****         *****\n";
			cout << "\t\t\t\t*****           ***************   ***                   *****         *****\n";
			cout << "\t\t\t\t*****           ****       ****   ***                    *****         *****\n";
			cout << "\t\t\t\t*****           ****       ****   ***                     *****         *****\n";
			cout << "\t\t\t\t *****   ****   ****       ****   ***               ****   *****  ****   *****\n";
			cout << "\t\t\t\t  **********    ****       ****   ************       **********    **********\n";
			cout << "\t\t\t\t   ********     ****       ****   ***************     ********      ******** "; 
			cout << endl << endl << endl << "\t\t \t\tPress any key to continue :";
		char x;
			cin >> x;

	}

	void initialize()
	{
		for (int i = 0; i < 8; i++)
		{
			board[1][i] = new pawn("P1");
			board[6][i] = new pawn("P2");
		}
		board[0][0] = new rook("R1");
		board[0][7] = new rook("R1");
		board[0][1] = new knight("k1");
		board[0][6] = new knight("k1");
		board[0][2] = new bishop("B1");
		board[0][5] = new bishop("B1");
		board[0][3] = new king("K1");
		board[0][4] = new queen("Q1");

		board[7][0] = new rook("R2");
		board[7][7] = new rook("R2");
		board[7][1] = new knight("k2");
		board[7][6] = new knight("k2");
		board[7][2] = new bishop("B2");
		board[7][5] = new bishop("B2");
		board[7][3] = new king("K2");
		board[7][4] = new queen("Q2");
		for (int i = 2; i < 6; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				board[i][j] = new piece();
			}
		}
	}

	int main()
	{
		system("color 70");
		
		//system("color 7");
		int x1, y1, x2, y2;
		initialize();
		loadingprint();
		system("cls");
		while (true)
		{
			for (char i='1' ; i <= '2'; i++)
			{
				cout << "Player 1 score :" << player1score << endl;
				cout << "Player 2 score :" << player2score << endl;
				if (i == '1')
				{
					cout << "Player 1 \n";
				}
				else
				{
					cout << "Player 2 \n";
				}
				printboard();
				cout << "Enter the indexes of token: ";
				cin >> x1 >> y1;
				cout << "Enter the indexes of where you want to move token: ";
				cin >> x2 >> y2;
				system("cls");
				board[x1][y1]->move(x1, y1, x2, y2,i);
			}
		}
		system("pause");

	}
