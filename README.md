#include<iostream>
#include<stdio.h>
#include<conio.h>
 
using namespace std;
int main()
{  
int espera[10], consome[10], roda[10],num,quantum,total;
cout<<"Numero de processos: "; 
cin>>num;
 
cout<<"Tempo de consumo: ";
for(int i=0;i<num;i++)
{  cout<<"\nP["<<i+1<<"]: "; cin>>consome[i];
   roda[i] = consome[i];
   espera[i]=0;
}
cout<<"\n\nInsira o quantum: "; cin>>quantum;
int rp = num;
int i=0;
int time=0;
cout<<"0"; 
espera[0]=0; 
while(rp!=0) { 
 if(roda[i]>quantum)
 {
   roda[i]=roda[i]-quantum;
   cout<<" | P["<<i+1<<"] | ";
   time+=quantum;
   cout<<time;
   }
 else if(roda[i]<=quantum && roda[i]>0)
 {time+=roda[i];
  roda[i]=roda[i]-roda[i];
  cout<<" | P["<<i+1<<"] | ";
  rp--;
  cout<<time;
 }
 
i++;
if(i==num)
{
i=0;
}
 
}
 
getch();
}
