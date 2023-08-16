#include<stdio.h>
#include<conio.h>
#include<strings.h>
void main() {
   int table[2][2],i,j,l,status=0,success;
   char input[100];
   printf("To implementing DFA of language (a+aa*b)* Enter Input String:”);
   table[0][0]=1;
   table[0][1]=-1;
   table[1][0]=1;
   table[1][1]=0;
   scanf("%s",input);
   l=strlen(input);
   for (i=0;i<l;i++) {
      if(input[i]!='a'&&input[i]!='b') {
         printf("The entered Value is wrong");
         getch();
         exit(0);
      }
      if(input[i]=='a')
      status=table[status][0]; else
      status=table[status][1];
      if(status==-1) {
         printf("String not Accepted");
         break;
      }
   }
   if(i==l)
      printf("String Accepted");
   getch();
}
