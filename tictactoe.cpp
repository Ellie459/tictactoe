/* Ellie Goto
   10/2/2026
   This is a tictactoe game. The game starts with the X player and counts how many times each player won. */

#include <iostream>

using namespace std;

//prints out the board
int print_board(char board[3][3])
{
  int row = 3;
  int col = 3;
  
  char abcs[] = {'a', 'b', 'c'};
    
  for (int r = 0; r < row; r++)
    {
      if (r == 0)
	{
	  cout << " \t1\t2\t3" << endl;
	}
      cout << abcs[r] << "\t";
      for (int c = 0; c < col; c++)
	{
	  cout << board[r][c] << "\t";
	}
      cout << endl;
      
    }
  return 0;
}

int check_row_win(char board[3][3], char player);
int check_col_win(char board[3][3], char player);
int check_diag_win(char board[3][3], char player);
int check_win(char board[3][3], char player);
int check_tie(char board[3][3]);

//places player to the board
int place_player(char player, char board[3][3])
{
  bool asking = true;
  char r;
  int row;
  int col;
  bool playing = true;
  char again;
  int X_win = 0;
  int O_win = 0;
  while (playing == true)
    {
  while (asking == true)
    {
      cout << player << "'s turn!" << endl;
      //asks the player for the row
      cout << "Enter row (a, b, c): ";
      cin >> r;
      //asks the player for the col
      cout << "Enter col (1, 2, 3): ";
      cin >> col;

      //if the row that player entered is wrong it asks to enter again
      if ((r != 'a') &&
	  (r != 'b') &&
	  (r != 'c'))
	  {
	    cout << "You entered invalid digit for row" << endl;
	  }

      //else if the col that player entered is wrong it asks to enter again
       else if (col < 1 || col > 3)
	  {
	    cout << "You entered invalid digit for col" << endl;
	  }
      //if they enter the correct row and col
       else
	  {
	    //converts the row and col into valid numbers so that it can enter into board
            col = col - 1;
            if (r == 'a')
	      {
		row = 0;
	       }
	    else if (r == 'b')
		{
		  row = 1;
		}
	    else if (r == 'c')
		{
		  row =2;
		}
	    
       if (board[row][col] == 0)
	 {
	   asking = false;
	  }
       //if the space that they choose is already taken it asks again.
       else
	 {
           cout << "Place already taken." << endl;
	  }
	  }


    }
   //cout << "Row: " << row << endl;
   //cout << "Col: " << col << endl;
  
  // places the player on the board
  board[row][col] = player;
   print_board(board);

   asking = true;
   int row = 3;
   int col = 3;
   
   bool win_flag = false;

   //checks if either of the player won. If true....
   if (check_win(board, player) == true)
     {
       //tells which player won
       cout << player << " won!" << endl;

       //if X won, it adds the number to times that X won
       if (player == 'X')
	 {
	   X_win = X_win + 1;
	  }
       //if O won, it adds the number of times that O won
       else if (player == 'O')
	 {
	   O_win = O_win + 1;
	  }
       win_flag = true;

       cout << "Number of X won: " << X_win << endl;
       cout << "Number of O won: " << O_win << endl;

       //asks the player if they want to play again
       cout << "Play again? (y/n): ";
       cin >> again;
       // if yes, it resets the board
       if (again == 'y')
	 {
	   for (int r = 0; r < row; r++)
	     {
	       for (int c = 0; c < row; c++)
		 {
		   board[r][c] = 0;
	          }
	     }
	   print_board(board);
	 }
       
       //if no, it stops the game
       else if (again == 'n')
	 {
	   playing = false;
	 }	 
     }

   
   //checks if the board is tied
   if (check_tie(board) == true)
     {
       cout << "Game Tied!" << endl;
       //asks the player if they want to play again
       cout << "Play again? (y/n): ";
       cin >> again;

       //if yes, it resets the board
       if (again == 'y')
         {
	   for (int r = 0; r < row; r++)
	     {
	       for (int c = 0; c < col; c++)
	         {
		   board[r][c] = 0;
		     }
	   }
	   print_board(board);
	 }
       //if no, it ends the game
	 else if (again == 'n')
	 {
	   playing = false;
	 }
     }

   //if neither of the player won or tied, it changes the turns
   if (win_flag == false)
     {
   if (player == 'X')
     {
       player = 'O';
     }

   else
     {
       player = 'X';
     }
     }
    }  
   return 0;    
  
    
}
    

//checks each row if either of the player won
int check_row_win(char board[3][3], char player)
{
  if (((board[0][0] == board[0][1]) && (board[0][1] == board[0][2]) && (board[0][2] == player)) ||
      ((board[1][0] == board[1][1]) && (board[1][1] == board[1][2]) && (board[1][2] == player)) ||
      ((board[2][0] == board[2][1]) && (board[2][1] == board[2][2]) && (board[2][2] == player)))
    {
      cout << "Returned True";
      return true;
    }
  else
    {
      return false;
    }
}

//checks each col if either of the player won
int check_col_win(char board[3][3], char player)
{
  if (((board[0][0] == board[1][0]) && (board[1][0] == board[2][0]) && (board[2][0] == player)) ||
      ((board[0][1] == board[1][1]) && (board[1][1] == board[2][1]) && (board[2][1] == player)) ||
      ((board[0][2] == board[1][2]) && (board[1][2] == board[2][2]) && (board[2][2] == player)))
    {
      return true;
    }
  else
    {
      return false;
    }
}

//checks diag if either of the player won
int check_diag_win(char board[3][3], char player)
{
  if (((board[0][0] == board[1][1]) && (board[1][1] == board[2][2]) && (board[2][2] == player)) ||
      ((board[2][0] == board[1][1]) && (board[1][1] == board[0][2]) && (board[0][2] == player)))
    {
      return true;
    }
  else
    {
      return false;
    }
}

//checks if either of the player won
int check_win(char board[3][3], char player)
{
  if ((check_row_win(board, player) == true) || (check_col_win(board, player) == true) || (check_diag_win(board, player) == true))
    {
      return true;
    }
  else
    {
      return false;
    }
}

//checks tie
int check_tie(char board[3][3])
{
  int row = 3;
  int col = 3;

  for (int r = 0; r < row; r++)
    {
      for (int c = 0; c < col; c++)
	{
	  if (board[r][c] == 0)
		    {
		      return false;
		    }
	}
    }
  return true;
}

//starts the game here
int main()
{ 
  char board[3][3] = {
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0}
  };
  char player = 'X';
  print_board(board);
  place_player(player, board);
  return 0;
}
