//Bryan Sugiarto CPE 101-05 Lab 4

char letter(int row, int col)
   {
      if (row == col||row+col==6 )
      {
         return 'X';
      }
      else
      {
         return 'O';
      }
   }


