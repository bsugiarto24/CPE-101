//Bryan Sugiarto CPE 101-05 Lab 4

char letter(int row, int col){

   if (row >1 && col> 3 && row<10 && col<13)
   {      
     
      if(row<4 &&col<10)
      {
         return 'Z';
      }

      else if(row<6&&row>3)
      {
         if(col<7)
         {
            return 'Z';
         }
         else if(col<10)
         {
            return 'X';
         }
         else
         { 
            return 'B';
         }
      }
      else if (row==6 && col>6)
      {
         return 'B';
      }
      else
      {
         return 'T';
      } 
           
   }else{
         return 'T';
        }

}
