// Bryan Sugiarto CPE101-05 Lab8

#include <stdio.h>

void read_example(void){
   int x, y, c;

   printf("Enter two integers: ");
   c=scanf("%d%d", &x, &y); 
   
   if(c!=2)
      printf("Invalid Input\n");
   else if(x>y)
      printf("\n%d\n",x);
   else
      printf("\n%d\n",y);

  
   double x1, y1;
   printf("Enter two doubles: ");
   c = scanf("%lf%lf", &x1, &y1); 

   if(c!=2)
      printf("Invalid Input\n");
   else if(x1>y1)
      printf("\n%lf\n",x1);
   else
      printf("\n%lf\n",y1);

}  


int main(int argc, char **argv){
   read_example();
   return 1;
}
