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

int place_player(char player, char board[3][3])
{
  bool asking = true;
  char r;
  int row;
  int col;
  bool playing = true;
  char again;
  
  while (playing == true)
    {
  while (asking == true)
    {
      cout << "Enter row (a, b, c): ";
      cin >> r;

      cout << "Enter col (1, 2, 3): ";
      cin >> col;

      if ((r != 'a') &&
	  (r != 'b') &&
	  (r != 'c'))
	  {
	    cout << "You entered invalid digit for row" << endl;
	  }
       else if (col < 1 || col > 3)
	  {
	    cout << "You entered invalid digit for col" << endl;
	  }
       else
	  {
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
       else
	 {
           cout << "Place already taken." << endl;
	  }
	  }


    }
   //cout << "Row: " << row << endl;
   //cout << "Col: " << col << endl;

  board[row][col] = player;
   print_board(board);

   asking = true;
   int row = 3;
   int col = 3;
   int X_win = 0;
   int Y_win = 0;
   bool win_flag = false;
   if (check_win(board, player) == true)
     {
       cout << player << " won!" << endl;
       if (player == 'X')
	 {
	   X_win = X_win + 1;
	  }
       else if (player == 'Y')
	 {
	   Y_win = Y_win + 1;
	  }
       win_flag = true;
       
       cout << "Play again? (y/n): ";
       cin >> again;
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
     
       else if (again == 'n')
	 {
	   playing = false;
	 }	 
     }

   if (check_tie(board) == true)
     {
       cout << "Game Tied!" << endl;

       cout << "Play again? (y/n): ";
       cin >> again;
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
	 else if (again == 'n')
	 {
	   playing = false;
	 }
     }

     
   if (win_flag == false)
     {
   if (player == 'X')
     {
       player = 'O';
       cout << "O's Turn!" << endl;
     }

   else
     {
       player = 'X';
       cout << "X's Turn!" << endl;
     }
     }
    }  
   return 0;    
  
    
}
    


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
int main()
{ 
  char board[3][3] = {
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0}
  };
  char player = 'X';
  print_board(board);
  cout << "X's Turn!" << endl;
  place_player(player, board);
  return 0;
}
