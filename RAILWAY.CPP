#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<time.h>
#include<iomanip.h>
#include<fstream.h>

//Global variables

char f[2]="f"; //"f" for first-class
char s[2]="s"; //"s" for second-class
int addr,ad,flag=1,f1,d,m,i,amt; //amt -> amount
float tamt; //tamt -> total_amount

//First class : "login"

class login
{
public:
	 char id[20];
	 char pass[10]; //pass -> password
	 char *password;

 void getid()
 {
  cout<<"Enter ID: "; gets(id);
  password=getpass("Enter password : ");
  strcpy(pass,password);
 }
 void displayid()
 {
  cout<<"User ID Information"<<endl<<endl;
  cout<<"ID: ";puts(id);cout<<endl;
  cout<<"Password : ";puts(pass);
 }
};

//Second class : "detail" of train

class detail
{
public:
 int tno; //tno -> Train Number
 char tname[30]; //tname -> Train Name
 char bp[20]; //bp -> Boarding Point
 char dest[20]; //dest -> Destination
 int c1,c1fare; //c1 -> First class c1fare -> First class fare
 int c2,c2fare; //c2 -> Second class c2fare -> Second class fare
 int d,m,y; //d -> date , m -> month , y -> year

 void getdetail()
 {
  clrscr();
  cout<<"Enter the details as follows"<<endl<<endl;
  cout<<"Train number : ";cin>>tno;
  cout<<"Train name : ";gets(tname);
  cout<<"Boarding point : ";gets(bp);
  cout<<"Destination point : ";gets(dest);
  cout<<"No of seats in first class "<<endl;
  cout<<"and fare per ticket: ";
  cin>>c1>>c1fare;
  cout<<"No of seats in second class "<<endl;
  cout<<"and fare per ticket: ";
  cin>>c2>>c2fare;
  cout<<"Date of travel(in dd/mm/yy): ";cin>>d>>m>>y;
  datecheck();
 }

 void datecheck()
 {
  if(y>=17)
  {
	if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)
	{
	 if(d>0&&d<=31)
	 {cout<<"valid date";}
	  else
	  {cout<<"invalid date";}
	 }
	 else if(m==4|m==6|m==9|m==11)
	 {
	  if(d>0&&d<=30)
	 {cout<<"valid date";}
	  else
	  {cout<<"invalid date";}
	  }
	 else if(m==2)
	 {
	   if((y % 4 == 0) && (y % 100 == 0)&&(y % 400 == 0))
	   {
	if(d>0&&d<=29)
	 {cout<<"valid date";}
	  else
	  {cout<<"invalid date";}
	  }
	  else
	  {
	   if(d>0&&d<=30)
	 {cout<<"valid date";}
	  else
	  {cout<<"invalid date";}
	  }
   }
 }
else
   {cout<<"invalid date";}
}
 void displaydetail()
 {
  cout<<"---------------------------------";
  cout<<"-----------------------------------------------";
  cout<<"Tr_No | Tr_Name | Start | Destin. |";
  cout<<" FC_se | SC_se | Fr_FC | Fr_SC | Date of Jo.";
  cout<<"\n----------------------------------";
  cout<<"----------------------------------------------\n";
  cout<<tno<<" "<<tname<<" "<<bp<<" "<<dest<<" "<<c1<<" "<<c2;
  cout<<" "<<c1fare<<" "<<c2fare<<" "<<d<<"/"<<m<<"/"<<y<<endl<<endl;
  cout<<"----------------------------------";
  cout<<"----------------------------------------------";
 }
};

//Third class : "reser" for reservation

class reser : public detail
{
public:
 int pnr; //pnr -> Passenger Name Record
 int tno; //tno -> Train Number
 char tname[30]; //tname -> Train Name
 char bp[20];
 char dest[20];
 char pname[10][100];//pname -> Passenger Name
 int age[20];//age -> Age of passenger
 char clas[10];
 int nosr; //nosr -> No. of seats reserved
 int i; //i -> Counter variable
 int d,m,y;
 int con; //con -> Concession amount
 float amc; //amc -> Amount pay to customer

 void getresdet();
 void displayresdet();
};
void reser::getresdet() //getresdet -> get reservation details
 {
  clrscr();
  cout<<"Enter the details as follows"<<endl<<endl;
  cout<<"Train number: ";cin>>tno;
  cout<<"Train name: ";gets(tname);
  cout<<"Boarding point: ";gets(bp);
  cout<<"Destination point: ";gets(dest);
  cout<<"No of seats required: ";cin>>nosr;
  for(i=0;i<nosr;i++)
  {
  cout<<"Passenger ("<<i+1<<") name: ";gets(pname[i]);
  cout<<"Passenger ("<<i+1<<") age : ";cin>>age[i];
  }
  cout<<"Enter the class"<<endl;
  cout<<"'f' for first class "<<endl;
  cout<<"'s' for second class: ";gets(clas);
  cout<<"Date of travel: ";cin>>d>>m>>y;
  cout<<"\n\nEnter the concession category from below\n";
  cout<<"1.Military\n2.Senior citizen\n";
  cout<<"3.Children(below 5 yrs)\n4.None\n";
  cout<<"Enter your choice: ";cin>>con;
 }
void reser::displayresdet() // Display reservation details
 {
  int sno;//={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72}; //sno -> Passenger Seat Number
  int a=1;
  cout<<endl;
  cout<<"-----------------------------------------------------\n";
  cout<<"  RESERVATION STATUS  \n";
  cout<<"-----------------------------------------------------\n";
  cout<<"PNR number : "<<pnr<<endl;
  for(int j=0;j<nosr;j++)
  {
	sno=a;
	cout<<sno<<" ";
	a++;
  }

  cout<<"Seat number : "<<sno<<endl;
  cout<<"Train number : "<<tno<<endl;
  cout<<"Train name : ";puts(tname);
  cout<<"Boarding point : ";puts(bp);
  cout<<"Destination point : ";puts(dest);
  cout<<"Number of seats reserved : "<<nosr<<endl;
  for(i=0;i<nosr;i++)
  {
  cout<<"Passenger "<<i+1<<" name : ";puts(pname[i]);
  cout<<"Passenger "<<i+1<<" age : "<<age[i]<<endl;
  }
  cout<<"Your class : ";puts(clas);
  cout<<"Date of reservation : "<<d<<"/"<<m<<"/"<<y;
  cout<<"\nYour concession category : "<<con;
  cout<<"\nYou must pay : "<<amc<<endl;
  cout<<"------------------------------------------------------\n";
  cout<<"  END OF RESERVATION DETAILS OF PASSENGER \n";
  cout<<"------------------------------------------------------\n";
}

//Fourth class : "canc" - cancellation of reserved ticket

class canc : public detail
{
 public:
 int pnr;
 int tno;
 char tname[100];
 char bp[20];
 char dest[20];
 char pname[10][100];
 int age[20];
 int i;
 char clas[10];
 int nosc;
 int d,m,y;
 float amr;
 void getcancdet()
 {
  cout<<"\n\nEnter the details as follows\n";
  cout<<"\nPNR number : ";cin>>pnr;
  cout<<"\nDate of cancellation : ";cin>>d>>m>>y;
  //datecheck();
 }
 void displaycancdet();
};
void canc::displaycancdet()
{
  cout<<"---------------------------------------------\n";
  cout<<"  DISPLAY OF CANCELLATION  \n";
  cout<<"---------------------------------------------\n";
  cout<<"PNR number  : "<<pnr<<endl;
  cout<<"Train number   : "<<tno<<endl;
  cout<<"Train name  : ";puts(tname);
  cout<<"Boarding point  : ";puts(bp);
  cout<<"Destination point : ";puts(dest);
  cout<<"Your class  : ";puts(clas);
  cout<<"No of seats has been cancelled : "<<nosc<<endl;
  for(i=0;i<nosc;i++)
  {
  cout<<"Passenger name : ";puts(pname[i]);
  cout<<"Passenger age : "<<age[i]<<endl;
  }
  cout<<"Date of cancellation : "<<d<<"/"<<m<<"/"<<y<<endl;
  cout<<"You can collect : Rs."<<amr<<endl;
  cout<<"---------------------------------------------\n";
  cout<<"  END OF CANCELLATION  \n";
  cout<<"---------------------------------------------\n";
}

//User-Defined Function(UDF) declaration part

void manage();
void can();
void user();
void database();
void res();
void reserve();
void displaypassdetail();
void cancell();
void enquiry();

//main function starts

void main()
{
int ch;
do
{
 clrscr();
 cout<<"-----------------------------------------------------------\n";
 cout<<" WELCOME TO ONLINE RAILWAY RESERVATION SYSTEM  \n";
 cout<<"-----------------------------------------------------------\n";
 cout<<"\n\n-----------------------------------------------------------\n";
 cout<<"    MAIN MENU \n";
 cout<<"-----------------------------------------------------------\n";
 cout<<"\n\n1. Admin mode \n\n2. User mode \n\n3. Exit\n";
 cout<<"\nEnter your choice : ";
 cin>>ch;
 cout<<endl;
 switch(ch)
 {
  case 1:
  database();
  break;

  case 2:
  user();
  break;

  case 3:
  exit(0);
 }
}while(ch<=3);
getch();
}

//User-Defined Function(UDF) definition

void database() //Database function for administrator
{
char *password;
char *pass="abc";
password=getpass("\nEnter the admininistrator password : ");
detail a;
fstream f;
int ch;
char c;
if(strcmp(pass,password)!=0)
{
cout<<"\nEnter the password correctly\n";
cout<<"You are not permitted to login this mode\n";
getch();
goto h;
}
if(strcmp(pass,password)==0)
{
char c;
do
{
  clrscr();
  cout<<"\n-----------------------------------------------------\n";
  cout<<"  ADMINISTRATOR MENU   \n";
  cout<<"-----------------------------------------------------\n";
  cout<<"\n\n1. Add details\n";
  cout<<"\n2. Display details\n\n3. User management\n";
  cout<<"\n4. Display passenger details\n\n5. Delete files\n\n6. Return to Main menu";
  cout<<"\nEnter your choice : ";
  cin>>ch;
  cout<<endl;
  switch(ch)
  {
  case 1:
  f.open("t.txt",ios::in|ios::out|ios::binary|ios::app);
  do
  {
  a.getdetail();
  f.write((char *) & a,sizeof(a));
  cout<<"\n\nDo you want to add one more record?\n";
  cout<<"y-for Yes\nn-for No\n";
  cout<<"Your answer : ";
  cin>>c;
  }while(c=='y');
  f.close();
  break;

  case 2:
  f.open("t.txt",ios::in|ios::out|ios::binary|ios::app);
  f.seekg(0);
  while(f.read((char *) & a,sizeof(a)))
  {
   a.displaydetail();
  }
  getch();
  f.close();
  break;

  case 3:
  manage();
  break;

  case 4:
  displaypassdetail();
  break;

  case 5:
  remove("p.txt");
  remove("t.txt");
  remove("cn.txt");
 }
}while(ch<=5);
f.close();
}
h:
}

void reserve()
{
int ch;
do
{
 clrscr();
 cout<<"1. Reserve\n\n2. Return to the main menu\n";
 cout<<"\nEnter your choice : ";
 cin>>ch;
 cout<<endl;
 switch(ch)
 {
  case 1:
  res();
  break;
 }
}while(ch==1);
getch();
}
void res()
{
detail a;
reser b;
fstream f1,f2;
time_t t;
f1.open("t.txt",ios::in|ios::out|ios::binary);
f2.open("p.txt",ios::in|ios::out|ios::binary|ios::app);
int ch;
b.getresdet();
while(f1.read((char *) &a,sizeof(a)))
{
 if(a.tno==b.tno)
 {
  if(strcmp(b.clas,f)==0)
  {
  if(a.c1>=b.nosr)
  {
  amt=a.c1fare;
  addr=f1.tellg();
  ad=sizeof(a.c1);
  f1.seekp(addr-(7*ad));
  a.c1=a.c1-b.nosr;
  f1.write((char *) & a.c1,sizeof(a.c1));
  if(b.con==1)
  {
  cout<<"\nConcession category : MILITARY PERSONNEL\n";
  b.amc=b.nosr*((amt*50)/100);
  }
  else if(b.con==2)
  {
  cout<<"\nConcession category : SENIOR CITIZEN\n";
  b.amc=b.nosr*((amt*60)/100);
  }
  else if(b.con==3)
  {
  cout<<"\nConcession category : CHILDERN BELOW FIVE\n";
  b.amc=0.0;
  }
  else if(b.con==4)
  {
  cout<<"\nYou cannot get any concession\n";
  b.amc=b.nosr*amt;
  }
  srand((unsigned) time(&t));
  b.pnr=rand();
  f2.write((char *) & b,sizeof(b));
  b.displayresdet();
  cout<<"------------------------------------------------------\n";
  cout<<" YOUR TICKET HAS BEEN RESERVED \n";
  cout<<"------------------------------------------------------\n";
  }
  else
  {
  cout<<"-----------------------------------------------------\n";
  cout<<" SORRY REQUESTED SEATS ARE NOT AVAILABLE \n";
  cout<<"-----------------------------------------------------\n";
  }
 }
 else if(strcmp(b.clas,s)==0)
 {
  if(a.c2>=b.nosr)
  {
  amt=a.c2fare;
  addr=f1.tellg();
  ad=sizeof(a.c2);
  f1.seekp(addr-(5*ad));
  a.c2=a.c2-b.nosr;
  f1.write((char *) & a.c2,sizeof(a.c2));
  if(b.con==1)
  {
  cout<<"\nConcession category : MILITARY PRESONNEL\n";
  b.amc=b.nosr*((amt*50)/100);
  }
  else if(b.con==2)
  {
  cout<<"\nConcession category : SENIOR CITIZEN\n";
  b.amc=b.nosr*((amt*60)/100);
  }
  else if(b.con==3)
  {
  cout<<"\nConcession category : CHILDERN BELOW FIVE\n";
  b.amc=0.0;
  }
  else if(b.con==4)
  {
  cout<<"\nYou can not get any concession\n";
  b.amc=b.nosr*amt;
  }
  f2.write((char *) & b,sizeof(b));
  b.displayresdet();
  cout<<"-----------------------------------------------------\n";
  cout<<"   YOUR TICKET HAS BEEN RESERVED  \n";
  cout<<"-----------------------------------------------------\n";
  displaypassdetail();
  }
  else
  {
  cout<<"--------------------------------------------------------\n";
  cout<<" SORRY REQIRED SEATS ARE NOT AVAILABLE   \n";
  cout<<"--------------------------------------------------------\n";
  }
 }
 getch();
 goto h;
}
else
{
 flag=0;
}
}
if(flag==0)
{
 cout<<"\n-------------------------------------------------------\n";
 cout<<"   WRONG TRAIN NUMBER   \n";
 cout<<"-------------------------------------------------------\n";
 cout<<"  ENTER THE TRAIN NO. FROM DATABASE  \n";
 cout<<"-------------------------------------------------------\n";
}
f1.close();
f2.close();
getch();
h:
}
void displaypassdetail()
{
fstream f;
reser b;
f.open("p.txt",ios::in|ios::out|ios::binary);
f.seekg(0);
while(f.read((char *) & b,sizeof(b)))
{
b.displayresdet();
}
f.close();
getch();
}
void enquiry()
{
fstream f;
f.open("t.txt",ios::in|ios::out|ios::binary);
detail a;
while(f.read((char *) & a,sizeof(a)))
{
 a.displaydetail();
}
getch();
}
void cancell()
{
detail a;
reser b;
canc c;
fstream f1,f2,f3;
f1.open("t.txt",ios::in|ios::out|ios::binary);
f2.open("p.txt",ios::in|ios::out|ios::binary);
f3.open("cn.txt",ios::in|ios::out|ios::binary);
clrscr();
cout<<"\n-----------------------------------------------------\n";
cout<<"   CANCELLATION MENU  \n";
cout<<"-----------------------------------------------------\n";
c.getcancdet();
while(f2.read((char *) & b,sizeof(b)))
{
 if(b.pnr==c.pnr)
 {
  c.tno=b.tno;
  strcpy(c.tname,b.tname);
  strcpy(c.bp,b.bp);
  strcpy(c.dest,b.dest);
  c.nosc=b.nosr;
  for(int j=0;j<c.nosc;j++)
  {
  strcpy(c.pname[j],b.pname[j]);
  c.age[j]=b.age[j];
  }
 strcpy(c.clas,b.clas);
 if(strcmp(c.clas,f)==0)
  {
  while(f1.read((char *) & a,sizeof(a)))
  {
  if(a.tno==c.tno)
   {
   a.c1=a.c1+c.nosc;
   d=a.d;
   m=a.m;
   addr=f1.tellg();
   ad=sizeof(a.c1);
   f1.seekp(addr-(7*ad));
   f1.write((char *) & a.c1,sizeof(a.c1));
   tamt=b.amc;
   if((c.d==d)&&(c.m==m))
   {
   cout<<"You are cancelling at the date of departure."<<endl;
   c.amr=tamt-(tamt*0.6);
   }
   else if((c.m==m) && (c.d<d))
   {
   cout<<"You are cancelling at the month of departure."<<endl;
   c.amr=tamt-(tamt*0.5);
   }
   else if(m>c.m)
   {
   cout<<"You are cancelling "<<m-c.m<<" month before the date of departure."<<endl;
   c.amr=tamt-(tamt*0.2);
   }
   else
   {
   cout<<"You are cancelling after the departure."<<endl;
   cout<<"Your request cannot be completed."<<endl;
   }
   fstream fp2;
   fp2.open("Temp.dat",ios::out);
   f2.seekg(0,ios::beg);
   while(f2.read((char*)&b,sizeof(b)))
   {
   if(b.pnr!=c.pnr)
   {
	fp2.write((char*)&b,sizeof(b));
   }
   }
   fp2.close();
   remove("p.txt");
   rename("Temp.dat","p.txt");
   c.displaycancdet();
   goto h;
  }
 }
  }
else if(strcmp(c.clas,s)==0)
{
 while(f1.read((char *) & a,sizeof(a)))
 {
  if(a.tno==c.tno)
  {
  a.c2=a.c2+c.nosc;
  d=a.d;
  m=a.m;
  addr=f1.tellg();
  ad=sizeof(a.c2);
  f1.seekp(addr-(5*ad));
  f1.write((char *) & a.c2,sizeof(a.c2));
  tamt=b.amc;
  if((c.d==d)&&(c.m==m))
   {
   cout<<"You are cancelling at the date of departure."<<endl;
   c.amr=tamt-(tamt*0.6);
   }
   else if((c.m==m) && (c.d<d))
   {
   cout<<"You are cancelling at the month of departure."<<endl;
   c.amr=tamt-(tamt*0.5);
   }
  else if(m>c.m)
   {
   cout<<"You are cancelling "<<m-c.m<<" month before the date of departure."<<endl;
   c.amr=tamt-(tamt*0.2);
   }
  else
   {
   cout<<"You are cancelling after the departure."<<endl;
   cout<<"Your request cannot be completed."<<endl;
   }
  fstream fp2;
  fp2.open("Temp.dat",ios::out);
  f2.seekg(0,ios::beg);
  while(f2.read((char*)&b,sizeof(b)))
   {
   if(b.pnr!=c.pnr)
	{
	fp2.write((char*)&b,sizeof(b));
	}
   }
  fp2.close();
  remove("p.txt");
  rename("Temp.dat","p.txt");
  c.displaycancdet();
  goto h;
  }
 }
}
}
else
{
 flag=0;
}
}
h:
if(flag==0)
{
cout<<"\nEnter the correct PNR number.\n";
}
f1.close();
f2.close();
f3.close();
getch();
}

void can()
{
int ch;
do
{
clrscr();
cout<<"\n----------------------------------------------------\n";
cout<<"   CANCELLATION MENU  \n";
cout<<"----------------------------------------------------\n";
cout<<"\n\n1. Cancel\n\n2. Return to the main menu\n";
cout<<"\nEnter your choice:";
cin>>ch;
cout<<endl;
switch(ch)
{
 case 1:
 cancell();
 break;
}
}while(ch==1);
getch();
}
void user()
{
login a;
int ch;
clrscr();
cout<<"\n-----------------------------------------------------\n";
cout<<"   USER MENU    \n";
cout<<"-----------------------------------------------------\n";
char *password;
fstream f;
f.open("id.txt",ios::in|ios::out|ios::binary);
char id[100];
cout<<"\n\nEnter your ID : "; gets(id);
password=getpass("\nEnter your password : ");
while(f.read((char *) & a,sizeof(a)))
{
 if((strcmp(a.id,id)==0)&&(strcmp(a.pass,password)==0))
 {
 do
 {
  clrscr();
  cout<<"\n\n1. Reserve a ticket\n\n2. Cancel a ticket";
  cout<<"\n\n3. Enquiry\n\n4. Return to the main menu\n";
  cout<<"\nEnter your choice : ";
  cin>>ch;
  cout<<endl;
  switch(ch)
  {
  case 1:
  reserve();
  break;

  case 2:
  cancell();
  break;

  case 3:
  enquiry();
  break;
  }
 }while(ch<=3);
 goto j;
 }
 else
 {
 d=1;
 }
}
if(d==1)
{
cout<<"\nEnter user ID and password correctly\n";
}
getch();
j:
}
void manage()
{
int ch;
fstream f;
char c;
login a;
clrscr();
cout<<"---------------------------------------------------------\n";
cout<<"  WELCOME TO THE USER MANAGEMENT MENU  \n";
cout<<"---------------------------------------------------------\n";
do
{
cout<<"\n\n1. Add ID details of user \n";
cout<<"\n2. Display details of ID\n\n3. Return to the main menu\n";
cout<<"\nEnter your choice : ";
cin>>ch;
cout<<endl;
switch(ch)
{
 case 1:
 f.open("id.txt",ios::in|ios::out|ios::binary|ios::app);
 do
 {
  a.getid();
  f.write((char *) & a,sizeof(a));
  cout<<"\n\nDo you want to add one more record>?\n";
  cout<<"y-Yes\nn-No\n";
  cout<<"Your answer : ";
  cin>>c;
 }while(c=='y');
 f.close();
 break;

 case 2:
 f.open("id.txt",ios::in|ios::out|ios::binary);
 f.seekg(0);
 while(f.read((char *) & a,sizeof(a)))
 {
  a.displayid();
 }
 f.close();
 break;
}
}while(ch<=2);
getch();
}
