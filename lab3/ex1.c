//collapse spaces: Write a program that reads all imput(from standart imput)and prints it transformed as follow 
 // any sequence of whitespace that dows not contain newline is replace with a single space character 
 //whitespace characters immedietly before a newline are deleted.

 #include<stdio.h>
#include<ctype.h>
 int main()
 { 
    int ok=0,c;
           while((c=getchar())!=EOF)
           {
                     if(!isspace(c))
                     {
                        if(ok!=0 && c!='\n') printf(" "); 
                             
                             
                        putchar(c);
                        ok=0;
                     }     
                   else  ok++;                                                                                                                                                                                                                                                       
            
            
           }
           return 0;
 }