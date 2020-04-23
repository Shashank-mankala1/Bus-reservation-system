#include <conio.h>
#include <iostream>
#include <string.h>
#include <cstdlib>        // Header files.
using namespace std;
static int p = 0;         // Static int p is declared.
class brs
{
  char busn[5], driver[10], arrival[5], depart[5], from[10], to[10], seat[8][4][10],mob[10];        // Data Members declarations
public:
  void install();
  void allotment();
  void empty();
  void show();
  void avail();
  void position(int i);          //Member functions declarations.
}bus[10];




void fillingch(char ch)
{
  for (int i=80;i>0;i--)
  cout<<ch;
}






void brs::install()             //install  member function defination 
{
  system("color c7");
  cout<<"Enter bus no: ";
  cin>>bus[p].busn;
  cout<<"\nEnter Driver's name: ";
  cin>>bus[p].driver;
  cout<<"\nEnter your phone number: ";
  cin>>bus[p].mob;
  cout<<"\nArrival time: ";
  cin>>bus[p].arrival;
  cout<<"\nDeparture: ";
  cin>>bus[p].depart;
  cout<<"\nFrom: \t\t\t";
  cin>>bus[p].from;
  cout<<"\nTo: \t\t\t";
  cin>>bus[p].to;
  
  bus[p].empty();
  p++;
}






void brs::allotment()                  //allotment  member function defination
{
  system("color A4");

  int seat;
  char number[5];
  top:
  cout<<"Bus no: ";
  cin>>number;
  int n;
  for(n=0;n<=p;n++)
  {
    if(strcmp(bus[n].busn, number)==0)
    break;
  }
  while(n<=p)
  {
    cout<<"\nSeat Number: ";
    cin>>seat;
    if(seat>32)
    {
      cout<<"\nThere are only 32 seats available in this bus.";
    }
    else
    {
    if (strcmp(bus[n].seat[seat/4][(seat%4)-1], "Empty")==0)
      {
        cout<<"Enter passanger's name: ";
        cin>>bus[n].seat[seat/4][(seat%4)-1];
        cout<<"Enter your number";
        cin>>bus[n].mob;
        break;
      }
    else
      cout<<"The seat no. is already reserved.\n";
      }
      }
    if(n>p)
    {
      cout<<"Enter correct bus no.\n";
      goto top;
    }
  }
  
  
  
  
void brs::empty()                     //empty member function defination
{
		system("color e1");

  for(int i=0; i<8;i++)
  {
    for(int j=0;j<4;j++)
    {
      strcpy(bus[p].seat[i][j], "Empty");
    }
  }
}



void brs::show()             //show member function defination
{
		system("color e4");

  int n;
  char number[5];
  cout<<"Enter bus no: ";
  cin>>number;
  for(n=0;n<=p;n++)
  {
    if(strcmp(bus[n].busn, number)==0)
    break;
  }
while(n<=p)
{
  fillingch('*');
  cout<<"\n\t\t\tBus no: \t"<<bus[n].busn
  <<"\nDriver: \t"<<bus[n].driver<<"\t\tArrival time: "
  <<bus[n].arrival<<"\tDeparture time:"<<bus[n].depart
  <<"\nFrom: \t\t"<<bus[n].from<<"\t\tTo: \t\t"<<
  bus[n].to<<"\n";
  fillingch('*');
  bus[0].position(n);
  int a=1;
  for (int i=0; i<8; i++)
  {
    for(int j=0;j<4;j++)
    {
      a++;
      if(strcmp(bus[n].seat[i][j],"Empty")!=0)
      cout<<"\nThe seat no "<<(a-1)<<" is reserved for "<<bus[n].seat[i][j]<<".";
    }
  }
  break;
  }
  if(n>p)
    cout<<"Enter correct bus no: ";
}



void brs::position(int l)              //position member function defination
{
  int s=0;p=0;
  for (int i =0; i<8;i++)
  {
    cout<<"\n";
    for (int j = 0;j<4; j++)
    {
      s++;
      if(strcmp(bus[l].seat[i][j], "Empty")==0)
        {
          cout.width(5);
          cout.fill(' ');
          cout<<s<<".";
          cout.width(10);
          cout.fill(' ');
          cout<<bus[l].seat[i][j];
          p++;
        }
        else
        {
        cout.width(5);
        cout.fill(' ');
        cout<<s<<".";
        cout.width(10);
        cout.fill(' ');
        cout<<bus[l].seat[i][j];
        }
      }
    }
  cout<<"\n\nThere are "<<p<<" seats empty in Bus No: "<<bus[l].busn;
  }
  
  
  
void brs::avail()                   //avail member function defination
{

  for(int n=0;n<p;n++)
  {
    fillingch('*');
    cout<<"\nBus no:"<<bus[n].busn<<"\nDriver: \t"<<bus[n].driver
    <<"\t\tArrival time: \t"<<bus[n].arrival<<"\tDeparture Time: \t"
    <<bus[n].depart<<"\nFrom: \t\t"<<bus[n].from<<"\t\tTo: \t\t\t"
    <<bus[n].to<<"\n";
    fillingch('*');
    cout<<"\n";
    fillingch('_');
  //  cout<<"\n";
  }
}




main()
{
system("cls");
system("color b0");
int w;
while(1)
{
    //system("cls");
    cout<<"\n\t\t\t\t  BUS RESERVATION SYSTEM\n";
    cout<<"\t\t\t=========================================";
  cout<<"\n\n\n";
  cout<<"\t\t\t1.Install/Setup Buses \n\t\t\t"
  <<"2.Seat Reservation\n\t\t\t"
  <<"3.Show all buses\n\t\t\t"
  <<"4.Buses Available. \n\t\t\t"
  <<"5.Exit";
  cout<<"\n\t\t\tEnter your choice:-> ";
  cin>>w;
  switch(w)
  {
    case 1:  system("cls");
	bus[p].install();
      break;
    case 2:  system("cls");
	bus[p].allotment();
      break;
    case 3:  system("cls");
	bus[0].show();
      break;
    case 4:  system("cls");
	bus[0].avail();
      break;
    case 5:  system("cls");
	exit(0);
      break;
  }
}
return 0;
}
