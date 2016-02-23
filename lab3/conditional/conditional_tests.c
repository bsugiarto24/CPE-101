//Bryan Sugiarto CPE 101-05 Lab 3 

#include <stdio.h>
#include "checkit.h"
#include "conditional.h"

void test_min(void){
   checkit_double(min(323.2,43.2),43.2);
   checkit_double(min(44,46.4),44);
   checkit_double(min(43.2,43.2),43.2);
}

void test_max(void){
   checkit_double(max(32.2,46.2),46.2);
   checkit_double(max(4.45,2.4),4.45);
   checkit_double(max(432,432),432);
}

void test_max_of_three(void){
   checkit_double(max_of_three(323.2,43.2,10),323.2);
   checkit_double(max_of_three(33.2,4.2,10),33.2); 
   checkit_double(max_of_three(40,43.4,32),43.4);
   checkit_double(max_of_three(4.3,63.4,32.3),63.4);
   checkit_double(max_of_three(53.2,53.2,12),53.2);
   checkit_double(max_of_three(32.2,43.2,10),43.2);
   checkit_double(max_of_three(3.4,1.7,12.1),12.1);
   checkit_double(max_of_three(1.6,3.4,4.6),4.6);
   checkit_double(max_of_three(5,5,5),5);

}

void test_rental_late_fee(void){
   checkit_int(rental_late_fee(0),0); 
   checkit_int(rental_late_fee(1),5);
   checkit_int(rental_late_fee(9),5);
   checkit_int(rental_late_fee(10),7);           
   checkit_int(rental_late_fee(15),7);          
   checkit_int(rental_late_fee(18),19);  
   checkit_int(rental_late_fee(24),19);           
   checkit_int(rental_late_fee(130),100);       
}



void test_cases(void)
{
   test_min();
   test_max();
   test_max_of_three();
   test_rental_late_fee();
}

int main(int argc, char **argv)
{
   test_cases();

   return 0;
}
