//Bryan Sugiarto CPE 101-05 Lab 9

#include <stdio.h>
#include <stdlib.h>

char convert_char(char const input[]){
   char d = 0;
   int x = sscanf(input,"%c", &d);
   
   if (x==0)
      return 0;
   else 
      return d;
} 

void translate(int argc, char **argv){
   FILE *fp;
   FILE *fout;
   
   if(argc<3){
      fprintf(stderr, "usage: %s <file> <char search> <char replace>\n"
                       ,argv[0]); 
      exit(1);
   }
   fp= fopen(argv[1],"r");
   fout= fopen("translation","w");
    
   char search = convert_char(argv[2]);
   char replace = convert_char(argv[3]);
  
   if (fp == NULL) {
         perror("Can't open input file!\n");
   }
   if (fout == NULL) {
         perror("Can't open output file!\n");
   }
   
   char in;
   while (fscanf(fp, " %c", &in) != EOF) {
      if(in==search)
         in = replace;
      fprintf(fout,"%c",in);
   }
   fclose(fout);
   fclose(fp);
  
}


int main(int argc, char **argv){
   translate(argc,argv);

}
