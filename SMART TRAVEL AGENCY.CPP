#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
void tour()
{
	clrscr();
	gotoxy(15,2);
	cout<<"Smart Travel Agency";
	gotoxy(1,3);
	cout<<"--------------------------------------------------------------------";
	gotoxy(1,23);
	cout<<"--------------------------------------------------------------------";
}
class travel
{
	char name[20];
	double distance,discount,price,netprice,bill;
	char place[20];
	char curloc[20];
	char vehicle[20];
	int trano;
 public:
	void enterdata();
	void show();
	void showall();
	void update();
	void show_bill();
	int get_place(char p[30])
	{
		return (strcmpi(place,p));
	}
	float get_bill()
	{
		return bill;
	}
	int get_trno()
	{
		return trano; //Retruns Traveller Number
	}

 };
 //Get the Details Of New Customer
void travel::enterdata()
{
tour();
gotoxy(20,7);
cout<<"Traveller number : ";
cin>>trano;
gotoxy(20,8);
cout<<"Name of the traveller : ";
gets(name);
gotoxy(20,9);
cout<<"Place to be travelled : ";
gets(place);
gotoxy(20,10);
cout<<"Current location : ";
gets(curloc);
gotoxy(20,11);
cout<<"Vehicle Type[Plane/Train] : ";
gets(vehicle);
if(strcmpi(vehicle,"Plane")==0)
	price=125;
else if(strcmpi(vehicle,"Train")==0)
	price=95;
else
{
	strcpy(vehicle,"Bus");
	price=65;
}
gotoxy(20,12);
cout<<"Charge/Km : "<<price;
gotoxy(20,13);
cout<<"Enter distance to be travelled : ";
cin>>distance;
netprice=price*distance;
gotoxy(20,14);
cout<<"Total Package Charge : "<<netprice;

if(netprice>100000)
	discount=netprice*0.2;
else if(netprice>75000)
	discount=netprice*0.15;
else if(netprice>50000)
	discount=netprice*0.1;
else if(netprice>25000)
	discount=netprice*0.05;
else
	discount=0;
bill=netprice-discount;
gotoxy(20,15);
cout<<"Discount On Your Package : "<<discount;
gotoxy(20,16);
cout<<"Amount To Be Paid By You : "<<bill;

}

//Change the Travel Plan
void travel::update()
{
tour();
gotoxy(20,8);
cout<<"Place to be travelled : ";
gets(place);
gotoxy(20,9);
cout<<"Current location : ";
gets(curloc);
gotoxy(20,10);
cout<<"Vehicle Type[Plane/Train] : ";
gets(vehicle);
if(strcmpi(vehicle,"Plane")==0)
	price=125;
else if(strcmpi(vehicle,"Train")==0)
	price=95;
else
{
	strcpy(vehicle,"Bus");
	price=65;
}
gotoxy(20,11);
cout<<"Charge/Km : "<<price;
gotoxy(20,12);
cout<<"Enter distance to be travelled : ";
cin>>distance;
netprice=price*distance;
gotoxy(20,13);
cout<<"Total Pacakage Charge : "<<netprice;

if(netprice>100000)
	discount=netprice*0.2;
else if(netprice>75000)
	discount=netprice*0.15;
else if(netprice>50000)
	discount=netprice*0.1;
else if(netprice>25000)
	discount=netprice*0.05;
else
	discount=0;
bill=netprice-discount;
gotoxy(20,14);
cout<<"Discount On Your Package : "<<discount;
gotoxy(20,15);
cout<<"Amount To Be Paid By You : "<<bill;

}
//Display Individual Traveller Details
void travel::show()
{
 gotoxy(20,8);
 cout<<"Traveller Number  = "<<trano;
 gotoxy(20,9);
 cout<<"Name of Traveller = "<<name;
 gotoxy(20,10);
 cout<<"Distance travelled = "<<distance;
 gotoxy(20,11);
 cout<<"The Place Travelled = "<<place;
 gotoxy(20,12);
 cout<<"Current Location = "<<curloc;
 gotoxy(20,13);
 cout<<"Vehicle = "<<vehicle;
 }
void travel::show_bill()
{
 gotoxy(20,8);
 cout<<"Traveller Number  = "<<trano;
 gotoxy(20,9);
 cout<<"Name of Traveller = "<<name;
 gotoxy(20,10);
 cout<<"Distance travelled = "<<distance;
 gotoxy(20,11);
 cout<<"The Place Travelled = "<<place;
 gotoxy(20,12);
 cout<<"Current Location = "<<curloc;
 gotoxy(20,13);
 cout<<"Vehicle = "<<vehicle;
 gotoxy(20,14);
 cout<<"Distance : "<<distance;
 gotoxy(20,15);
 cout<<"Charge/KM : "<<price;
 gotoxy(20,16);
 cout<<"Net Bill Amount : "<<netprice;
 gotoxy(20,17);
 cout<<"Discount On Bill : "<<discount;
 gotoxy(20,18);
 cout<<"Amount To Pay : "<<bill;
 }
//Display Details of All Travellers.
int r=7;
void travel::showall()
{
 gotoxy(5,r++);
 cout<<trano<<"\t"<<name<<"\t\t"<<curloc<<"\t"<<place<<"\t"<<distance<<"\t"<<bill;
 if(r==20)
 r=3;
}

void add_new_record() //Add New Record In Database
{       clrscr();
	tour();
	int tno;
	ofstream fin;
	fin.open("tour.dat",ios::app|ios::binary);
	if(!fin)
	{
		gotoxy(20,20);
		cout<<"Can not open file...!";
		getch();
		return;
	}
	travel t;
	t.enterdata();
	fin.write((char*)&t,sizeof(t));
	fin.close();
	gotoxy(20,20);
	cout<<"New Record Added Successfully....!";
	getch();
}
void search() //Find any Specific Traveller Details
{ clrscr();
  tour();
  int found=0;
  ifstream fin("tour.dat",ios::binary);
  travel t;
  int b;
  gotoxy(20,5);
  cout<<"Enter traveller number : ";
  cin>>b;
  fin.seekg(0);
  while(fin.read((char*)&t,sizeof(t)))
  {
	if(t.get_trno()==b)
	{
		t.show();
		found=1;
		getch();
		break;
	}
  }
  fin.close();
  if(found==0)
  {
	gotoxy(20,20);
	cout<<"Record Not Found ";
  }
}

void modify() //Modify in Database of Traveller
{       clrscr();
	tour();
	ifstream fin;
	fin.open("tour.dat",ios::binary);
	ofstream temp("temp.dat",ios::binary);
	if(!fin)
	{
		cout<<"can not open file\n";
		return;
	}
	travel t;
	int s,found=-1;
	gotoxy(20,5);
	cout<<"Enter Traveller Number : ";
	cin>>s;
	fin.seekg(0);//Place file Pointer At Begining Of File
	while(fin.read((char*)&t,sizeof(t)))
	{
		if(t.get_trno()==s)
		{
			t.update();
			fin.seekg(-sizeof(t),ios::cur);
			temp.write((char *)&t,sizeof(t));
			found++;
		}
		else
			temp.write((char *)&t,sizeof(t));
	}
	fin.close();
	temp.close();
	gotoxy(20,20);
	if(found==-1)
		cout<<"Record Not Found";
	else
	{
		cout<<"Record Found ";
		remove("tour.dat");
		rename("temp.dat","tour.dat");
	}
   }
void Delete() //Cancellation of Travelling.
{       clrscr();
	tour();
	ifstream fin;
	fin.open("tour.dat",ios::binary);
	if(!fin)
	{
		gotoxy(20,20);
		cout<<"can not open file";
		return;
	}
	ofstream fout;
	fout.open("temp.dat",ios::binary);
	if(!fout)
	{
		gotoxy(20,20);
		cout<<"Can not open file";
		return;
	}
	int a,found=0;
	gotoxy(20,5);
	cout<<"Enter traveller number : ";
	cin>>a;
	fin.seekg(0);
	travel t;
	while(fin.read((char*)&t,sizeof(t)))
	{
		if(t.get_trno()!=a)
		{
			fout.write((char*)&t,sizeof(t));
		}
		else
			found++;
	 }
	 fin.close();
	 fout.close();
	 if(found==1)
	 {
		gotoxy(20,20);
		cout<<"Your Trip Cancelled Successfully...!";
		remove("tour.dat");
		rename("temp.dat","tour.dat");
	 }
	 else
	 {
		gotoxy(20,20);
		cout<<"As Such No Traveller Exist...?";
	 }
cout<<"\n\nclick any key to continue\n";
getch();
}
void Billing() //Find any Specific Traveller Details
{ clrscr();
  tour();
  ifstream fin;
  int found=0;
  fin.open("tour.dat",ios::binary);
  if(!fin)
  {     gotoxy(20,20);
	cout<<"Can not open file";
	getch();
	return;
  }
  travel t;
  int b;
  gotoxy(20,5);
  cout<<"Enter traveller number : ";
  cin>>b;
  while(fin.read((char*)&t,sizeof(t)))
  {
	if(t.get_trno()==b)
	{
		t.show_bill();
		found=1;
		getch();
		break;
	}
  }
  fin.close();
  if(found==0)
  {
	gotoxy(20,20);
	cout<<"Record Not Found ";
  }
}
//Display Details of All Travellers by Destination Place
void show_destination()
{ clrscr();
  tour();
  ifstream fin;
  char place[30];
  int found=0;
  travel t;
  fin.open("tour.dat",ios::binary);
  if(!fin)
  {     gotoxy(20,20);
	cout<<"Can not open file";
	getch();
	return;
  }
  gotoxy(20,5);
  cout<<"Enter Destination Place : ";
  gets(place);
  while(fin.read((char*)&t,sizeof(t)))
  {
	if(t.get_place(place)==0)
	{       gotoxy(4,5);
		if(found==0)
		cout<<"Tr. No\tTr. Name\t\tFrom\tTo\tDistance\tBill";
		t.showall();
		found++;
	}
  }
  if(found==0)
  {
	gotoxy(20,20);
	cout<<"As Such No Destination Place Exist...?";
  }
  fin.close();
  cout<<"\n\nclick any key to continue\n";
  getch();
}

void show_all() //Display Details of All Travellers on Screen
{ clrscr();
  tour();
  //cout<<"working.............\n";
  ifstream fin;
  fin.open("tour.dat",ios::binary);
  if(!fin)
  {     gotoxy(20,20);
	cout<<"Can not open file";
	getch();
	return;
  }
  travel t;
  gotoxy(4,5);
  cout<<"Tr. No\tTr. Name\t\tFrom\tTo\tDistance\tBill";
  while(fin.read((char*)&t,sizeof(t)))
  {
	t.showall();
  }
  fin.close();
  cout<<"\n\nclick any key to continue\n";
  getch();
}


void Main_Menu();
void Show_Menu()
{
	int ch;
	travel t;
	do
	{       clrscr();
		tour();
		gotoxy(20,8);
		cout<<"1. Traveller Number";
		gotoxy(20,9);
		cout<<"2. Destination Place";
		gotoxy(20,10);
		cout<<"3. Details of All Traveller";
		gotoxy(20,11);
		cout<<"4. Exit";
		gotoxy(20,12);
		cout<<"Enter choice : ";
		cin>>ch;
		switch(ch)
		{
			case 1: search();
				break;
			case 2:	show_destination();
				break;
			case 3: show_all();
				break;
			default: Main_Menu();
		}
	}while(ch>=1 && ch<=3);
}
void Main_Menu()
{
	int ch;
	clrscr();
	tour();
	travel t;
do
{       clrscr();
	tour();
	gotoxy(20,8);
	cout<<"1. Booking";
	gotoxy(20,9);
	cout<<"2. Change Trip Plan";
	gotoxy(20,10);
	cout<<"3. Cancel Trip";
	gotoxy(20,11);
	cout<<"4. Details Of Traveller";
	gotoxy(20,12);
	cout<<"5. Billing";
	gotoxy(20,13);
	cout<<"Enter Choice : ";
	cin>>ch;
  switch(ch)
  {
	case 1: add_new_record();
		break;
	case 2: modify();
		break;
	case 3: Delete();
		break;
	case 4: Show_Menu();
		break;
	case 5: Billing();
		break;
  }
}while(ch>=1 && ch<=4);
}
void main()
{
clrscr();
Main_Menu();
getch();
}
