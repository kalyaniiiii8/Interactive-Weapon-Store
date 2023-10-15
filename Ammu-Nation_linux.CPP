///////////////////////////////////////////////////////////////////
//                       					 //
//	A Project on Interactive Weapon Store        	 	 //
//			   By -: Kalyani Pande	 	         //
//								 //
///////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////
///////////////////////Header files used//////////////////////
////////////////////////////////////////////////////////////////////


#include <bits/stdc++.h>

using namespace std;

////////////////////////////////////////////////////////////////////
//////////////////class used for binary file//////////////////
////////////////////////////////////////////////////////////////////
class record
{	  
	char name[50], mn[15], accno[15],add[75],bank[50],email[50];
	
	int lno;
public:
	void enter();
	void display();
	void calc_lno()
	{
		srand(time(0)); 
		lno=rand()%1000;
	}
	int ret_lno()
	{
		return lno;
	}
};

//////////////////////Class functions//////////////////////
//To enter record
void record::enter()
{
	cout<<"Enter Name\n";
	scanf(" %[^\n]s",name);

	cout<<"\nEnter mobile number(10-digit)\n";
	scanf(" %[^\n]s",mn);
	
	cout<<"\nEnter address\n";
	scanf(" %[^\n]s",add);

	cout<<"\nEnter email ID\n";
	scanf(" %[^\n]s",email);

	cout<<"\n********************************************************************************\n" ;
	cout<<"	      \t		  ACCOUNT DETAILS\n"   ;

	cout<<"Enter name of the bank\n";
	scanf(" %[^\n]s",bank);

	cout<<"\nEnter Account number (12-digit)\n";
	scanf(" %[^\n]s",accno);
}

//TO display a record
void record::display()
{
	cout<<"\nLicence Details:\n";
	cout<<"Licence number :   "<<lno<<endl<<"Name :  "<<name<<endl<<"Mobile number :   " ;

	for(int i=0;i<10;i++)
		cout<<mn[i];

	cout<<endl<<"Address :   "<<add<<endl ;
	cout<<"Email :    "<<email<<endl<<"Name of Bank :   "<<bank ;
	cout<<endl<<"Account number :   ";
	for(int i=0;i<12;i++)
		cout<<accno[i];

}

////////////////////////////////////////////////////////////////////
/////////////////////Function declaration/////////////////////
////////////////////////////////////////////////////////////////////

// menu functions
void l_menu();
void ps_menu();
void p_menu();
void s_menu();

// Licence related functions
void ver_licence();
void new_licence();
void update_licence();

// weapons and accessories functions
void s_rifle();
void a_rifle();
void pistol();
void shotgun();
void muzzle();
void scope();
void clip();
void ammo();

// Other Functions
void gotoxy(int x,int y)
{
    printf("%c[%d;%df",0x1B,y,x);
}
void redirect()
{
	gotoxy(47,37);
	cout<<"Redirecting........please wait\n\n";
	int i,y,z;
	for(i=0;i<3;i++)
	{  
		gotoxy(77,37);
		for(y=0;y<4;y++)
		{	
			gotoxy(77+y,37);
			cout<<".\n";
			this_thread::sleep_for (chrono::milliseconds(300));
		}
		gotoxy(77,37);
		for(z=0;z<4;z++)
		{	gotoxy(77+z,37);
			cout<<" \n";
			this_thread::sleep_for (chrono::milliseconds(300));
		}
	}
}
////////////////////////////////////////////////////////////////////
//////////////////////////FUNCTIONS///////////////////////////
////////////////////////////////////////////////////////////////////

//// LICENCE RELATED FUNCTIONS ////
//New licence
void new_licence()
{
	
	system("clear");
	record r1;
	ofstream o1("licence.dat",ios::binary|ios::app);
	cout<<"\nYou have applied for a new licence!!!\nStart BY entering details\n(All fields are Mandatory) ";
	cout<<"\n********************************************************************************\n";
	r1.calc_lno();
	r1.ret_lno()    ;
	r1.enter();
	o1.write((char*)&r1,sizeof(r1));
	o1.close();
	cout<<"\n********************************************************************************" ;
	cout<<"\n                               CONGRATULATIONS!!!";
	cout<<"\n                             New Licence Issued!!!";
	cout<<"\n                              Licence number: "<<r1.ret_lno()<<endl;
	redirect();
	l_menu();

}

//update licence
void update()
{
	system("clear");
	int i,y,z,lno,flag=0,pos;
	record r1;
	fstream i1("licence.dat",ios::binary|ios::in|ios::out)   ;
	cout<<"\n\n********************************************************************************\n" ;
	cout<<"Please Enter your Licence number  \n"   ;

	cin>>lno;
	cout<<"\nScanning for records........please wait";

// dot loop
	for(i=0;i<3;i++)
	{  
		gotoxy(40,7);
		for(y=0;y<4;y++)
		{	
			gotoxy(40+y,7);
			cout<<".\n";
			this_thread::sleep_for (chrono::milliseconds(300));
		}
		gotoxy(40,7);
		for(z=0;z<4;z++)
		{	gotoxy(40+z,7);
			cout<<" \n";
			this_thread::sleep_for (chrono::milliseconds(300));
		}
	}


	cout<<"\nScanning complete!!!";
	
	while(i1.read((char*)&r1,sizeof(r1)))
	{
		if(r1.ret_lno()==lno)
		{
			cout<<"Match found!!!\n";
			cout<<"\n********************************************************************************\n" ;
			r1.display();
			cout<<"\n\n********************************************************************************\n" ;
			cout<<"\n                                 ENTER NEW VALUES\n\n";
			pos = (int)i1.tellg()-(int)sizeof(r1);
			i1.seekp(pos,ios::beg);
			r1.enter();
			cout<<"\n\n********************************************************************************\n" ;
			i1.write((char*)&r1,sizeof(r1));
			flag=1;
			break;
		}
	}
	if(flag!=1)
		cout<<"No record found!!!\n";
	else
		cout<<"\nModification successful!!!\n";
	redirect();
	i1.close();
	l_menu();
}

//verify licence
void ver_licence()
{
	system("clear");
	int lno,i,y,z,flag=0;
	record r1;
	ifstream i1("licence.dat",ios::binary|ios::in)   ;
	cout<<"\n********************************************************************************\n" ;
	cout<<" \nPlease Enter your Licence number  \n"   ;
	cin>>lno;
	cout<<"\nScanning for records........please wait";

// dot loop
	for(i=0;i<3;i++)
	{  
		gotoxy(40,7);
		for(y=0;y<4;y++)
		{	
			gotoxy(40+y,7);
			cout<<".\n";
			this_thread::sleep_for (chrono::milliseconds(300));
		}
		gotoxy(40,7);
		for(z=0;z<4;z++)
		{	gotoxy(40+z,7);
			cout<<" \n";
			this_thread::sleep_for (chrono::milliseconds(300));
		}
	}

	cout<<"\nscanning complete!!!";
	
	while(i1.read((char*)&r1,sizeof(r1)))
	{
		if(r1.ret_lno()==lno)
		{	
			cout<<"Match found!!!\n";
			cout<<"\n********************************************************************************\n" ;
			r1.display();
			cout<<"\n\n********************************************************************************\n" ; 
			 
			flag=1;

			break;
		}
	}
	if(flag!=1)
	{	
		cout<<"No record found!!!\n";
	}
	redirect();
	i1.close();
	if(flag==1)
		p_menu();
	else
		l_menu();
}


////////////////////////////////////////////////////////////////////
//////////////////////////MENU FUNCTIONS////////////////////////////
////////////////////////////////////////////////////////////////////

//// LICENCE MENU ////
void l_menu()
{
	system("clear");
	int n=0;
	cout<<" **************************  Welcome To Ammu-Nation *************************** \n";
	cout<<" Let's Begin by Verifying Your Licence !!!\n";
	while(n!=5)
	{
	    cout<<"1.Verify Licence\n";
		cout<<"2.New Licence\n";
		cout<<"3.Update Licence\n";
		cout<<"4.Exit Shop";
		cout<<"\nEnter Choice(1-4)\n";
		cin>>n;
		switch(n)
		{
			case 1: ver_licence();
			break;
			case 2: new_licence();
			break;
			case 3: update();
			break;
			case 4: exit(0);
			break;
			default: cout<<"\n Invalid choice\n\n";
		}
	}

}


//// PURCHASE MENU ////
void p_menu()
{	
	system("clear"); 
	int n;
	cout<<"\n **************************  Welcome To The Arsenal *************************** \n";

	while(n!=10)
	{
        cout<<"Weapons:\n\t";
		cout<<"1.Sniper Rifles\n\t";
		cout<<"2.Assault Rifles\n\t";
		cout<<"3.Shotguns\n\t";
		cout<<"4.Pistols\n";
		cout<<"Accessories:\n\t";
		cout<<"5.Muzzle\n\t";
		cout<<"6.Ammo\n\t";
		cout<<"7.Scope\n\t";
		cout<<"8.Clip\n";
		cout<<"Press 9 to Exit";
		cout<<"\nEnter Choice(1-9)\n";
		cin>>n;
		switch(n)
		{ 
			case 1:s_rifle();
			break;
			case 2:a_rifle();
			break;
			case 3:shotgun();
			break;
			case 4:pistol();
			break;
			case 5:muzzle();
			break;
			case 6:ammo();
			break;
			case 7:scope();
			break;
			case 8:clip();
			break;
			case 9: exit(0);
			break;
			default: cout<<"\n Invalid choice\n\n";
		}
	}
}

////////////////////////////////////////////////////////////////////
//FUNCTIONS FOR TRANSACTIONS
void purchase(long price)
{
	system("clear");
	char n[12], p[4];
	int i,y,z;

	cout<<"********************************************************************************\n"     ;
	cout<<"Enter your account number\n";
	scanf("%12s",n);

	cout<<"\nEnter your 4-digit pin\n";

	scanf("%4s",p);
	gotoxy(1,6);
	for(i=0;i<4;i++)
	{	
		gotoxy(1+i,6);
		cout<<"*\n";
		this_thread::sleep_for (chrono::milliseconds(500));
	}

	gotoxy(1,7);
	cout<<"Please wait while transaction is in process";
	for(i=0;i<3;i++)
	{
		gotoxy(44,7);
		for(y=0;y<4;y++)
		{
			gotoxy(44+y,7);
			cout<<".\n";
			this_thread::sleep_for (chrono::milliseconds(300));
		}
		gotoxy(44,7);
		for(z=0;z<4;z++)
		{
			gotoxy(44+z,7);
			cout<<" \n";
			this_thread::sleep_for (chrono::milliseconds(300));
		}
	}
	cout<<endl;
	cout<<"Transaction successful !!!\n";
	cout<<"********************************************************************************\n$";
	cout<<price<<" will be deducted from your account\nYour equipment will be delivered shortly !!!\n\nNice doing business with you!\n";
	cout<<"********************************************************************************\n";
	redirect();
	p_menu();
}

void trans(long cost)
{
	long q,c;
	char t;
	cout<<"\nEnter Quantity:\n";
	cin>>q;
	c=cost*q ;
	cout<<"________________________________________________________________________________\n"     ;
	cout<<"Total Cost :\t$ "<<c<<endl;
	cout<<"________________________________________________________________________________\n"      ;
	cout<<"Do you want to confirm your order? (Y/N)\n";
	cin>>t;
	redirect();
	if(t=='y'||t=='Y')
		purchase(c);
	else
		p_menu();

}





////////////////////////////////////////////////////////////////////
///////////////////////WEAPON FUNCTIONS/////////////////////////
////////////////////////////////////////////////////////////////////

//SNIPER RIFLE
void s_rifle()
{
	system("clear");
	cout<<"********************************************************************************\n\n";
	cout<<" Select your sniper rifle\n";

//code for table
	int i,y,n;
	for(i=0;i<70;i++)
	{
		gotoxy(i,4);
		cout<<"_";
		gotoxy(i,6);
		cout<<"_";
		gotoxy(i,16)    ;
		cout<<"_";
	}
	for(i=5;i<17;i++)
	{
		gotoxy(1,i) ;
		cout<<"|";
		gotoxy(6,i);
		cout<<"|";
		gotoxy(50,i);
		cout<<"|";
		gotoxy(70,i);
		cout<<"|";
	}
	y=1;
	gotoxy(2,5);
	cout<<"Sno.";
	gotoxy(20,5)  ;
	cout<<"Rifle name";
	gotoxy(58,5);
	cout<<"Cost";

	for(i=7;i<16;i=i+2)
	{ 
		for(;y<6;)
		{
			gotoxy(2,i);
			cout<<y<<".";
			y++;
			break;
		}
	}
// WEAPON NAME
	gotoxy(7,7);
	cout<<"M 82 Barret .50 cal";
	gotoxy(7,9)            ;
	cout<<"Mosin-Nagant" ;
	gotoxy(7,11) ;
	cout<<"Dragunov SVD";
	gotoxy(7,13)            ;
	cout<<"L 42 Enfield";
	gotoxy(7,15)            ;
	cout<<"L 115 A3 AWM";

// WEAPON PRICE
	gotoxy(51,7);
	cout<<"$ 8999";
	gotoxy(51,9)            ;
	cout<<"$ 439" ;
	gotoxy(51,11) ;
	cout<<"$ 5999";
	gotoxy(51,13)            ;
	cout<<"$ 550";
	gotoxy(51,15)            ;
	cout<<"$ 34999";

	gotoxy(1,17)  ;
	cout<<"\nPress 6 to go back to previous menu\n";
	cout<<"Press 7 to exit shop\n";
	while(n!=8)
	{ 
		cout<<"\nEnter choice\n";
		cin>>n;
		switch(n)
		{ 
			case 1: trans(8999);
			break;
			case 2: trans(439);
			break;
			case 3: trans(5999);
			break;
			case 4: trans(550);
			break;
			case 5: trans(34999);
			break;
			case 6: p_menu();
			break;
			case 7: exit(0);
			break;
			default: cout<<"\n Invalid choice\n\n";
		}
	}
}



// ASSAULT RIFLE
void a_rifle()
{
	system("clear");
	cout<<"********************************************************************************\n\n";
	cout<<" Select your assault rifle\n";

//code for table
	int i,y,n;
	for(i=0;i<70;i++)
	{
		gotoxy(i,4);
		cout<<"_";
		gotoxy(i,6);
		cout<<"_";
		gotoxy(i,16)    ;
		cout<<"_";
	}
	for(i=5;i<17;i++)
	{
		gotoxy(1,i) ;
		cout<<"|";
		gotoxy(6,i);
		cout<<"|";
		gotoxy(50,i);
		cout<<"|";
		gotoxy(70,i);
		cout<<"|";
	}
	y=1;
	gotoxy(2,5);
	cout<<"Sno.";
	gotoxy(20,5)  ;
	cout<<"Rifle name";
	gotoxy(58,5);
	cout<<"Cost";

	for(i=7;i<16;i=i+2)
	{ 
		for(;y<6;)
		{
			gotoxy(2,i);
			cout<<y<<".";
			y++;
			break;
		}
	}
// WEAPON NAME
	gotoxy(7,7);
	cout<<"AK-47";
	gotoxy(7,9)            ;
	cout<<"M4 A1" ;
	gotoxy(7,11) ;
	cout<<"Steyr AUG";
	gotoxy(7,13)            ;
	cout<<"FN scar";
	gotoxy(7,15)            ;
	cout<<"Famas";

// WEAPON PRICE

	gotoxy(51,7);
	cout<<"$ 3399";
	gotoxy(51,9)            ;
	cout<<"$ 2199" ;
	gotoxy(51,11) ;
	cout<<"$ 1799";
	gotoxy(51,13)            ;
	cout<<"$ 2899";
	gotoxy(51,15)            ;
	cout<<"$ 2250";

	gotoxy(1,17)  ;
	cout<<"\nPress 6 to go back to previous menu\n";
	cout<<"Press 7 to exit shop\n";
	while(n!=8)
	{
		cout<<"\nEnter choice\n";
		cin>>n;
		switch(n)
		{
			case 1: trans(3399);
			break;
			case 2: trans(2199);
			break;
			case 3: trans(1799);
			break;
			case 4: trans(2899);
			break;
			case 5: trans(2250);
			break;
			case 6: p_menu();
			break;
			case 7: exit(0);
			break;
			default: cout<<"\n Invalid choice\n\n";
		}
	}
}

// PISTOL

void pistol()
{
	system("clear");
	cout<<"********************************************************************************\n\n";
	cout<<" Select your pistol\n";

	//code for table
	int i,y,n;
	for(i=0;i<70;i++)
	{
		gotoxy(i,4);
		cout<<"_";
		gotoxy(i,6);
		cout<<"_";
		gotoxy(i,16)    ;
		cout<<"_";
	}
	for(i=5;i<17;i++)
	{
		gotoxy(1,i) ;
		cout<<"|";
		gotoxy(6,i);
		cout<<"|";
		gotoxy(50,i);
		cout<<"|";
		gotoxy(70,i);
		cout<<"|";
	}
	y=1;
	gotoxy(2,5);
	cout<<"Sno.";
	gotoxy(20,5)  ;
	cout<<"Pistol name";
	gotoxy(58,5);
	cout<<"Cost";

	for(i=7;i<16;i=i+2)
	{ 
		for(;y<6;)
		{
			gotoxy(2,i);
			cout<<y<<".";
			y++;
			break;
		}
	}
	// WEAPON NAME
	gotoxy(7,7);
	cout<<"CZ 75 SP-01";
	gotoxy(7,9)            ;
	cout<<"Walther PPQ" ;
	gotoxy(7,11) ;
	cout<<"Beretta 92FS";
	gotoxy(7,13)            ;
	cout<<"Taurus PT 92";
	gotoxy(7,15)            ;
	cout<<"Glock 17 Gen 4";

	// WEAPON COST

	gotoxy(51,7);
	cout<<"$ 599";
	gotoxy(51,9)            ;
	cout<<"$ 549" ;
	gotoxy(51,11) ;
	cout<<"$ 599";
	gotoxy(51,13)            ;
	cout<<"$ 499";
	gotoxy(51,15)            ;
	cout<<"$ 569";

	gotoxy(1,17)  ;
	cout<<"\nPress 6 to go back to previous menu\n";
	cout<<"Press 7 to exit shop\n";
	while(n!=8)
	{
		cout<<"\nEnter choice\n";
		cin>>n;
		switch(n)
		{ 
			case 1: trans(599);
			break;
			case 2: trans(549);
			break;
			case 3: trans(599);
			break;
			case 4: trans(499);
			break;
			case 5: trans(569);
			break;
			case 6: p_menu();
			break;
			case 7: exit(0);
			break;
			default: cout<<"\n Invalid choice\n\n";
		}
	}
}

// SHOTGUN
void shotgun()
{
	system("clear");
	cout<<"********************************************************************************\n\n";
	cout<<" Select your shotgun\n";

//code for table
	int i,y,n;
	for(i=0;i<70;i++)
	{
		gotoxy(i,4);
		cout<<"_";
		gotoxy(i,6);
		cout<<"_";
		gotoxy(i,16)    ;
		cout<<"_";
	}
	for(i=5;i<17;i++)
	{
		gotoxy(1,i) ;
		cout<<"|";
		gotoxy(6,i);
		cout<<"|";
		gotoxy(50,i);
		cout<<"|";
		gotoxy(70,i);
		cout<<"|";
	}
	y=1;
	gotoxy(2,5);
	cout<<"Sno.";
	gotoxy(20,5)  ;
	cout<<"Shotgun name";
	gotoxy(58,5);
	cout<<"Cost";

	for(i=7;i<16;i=i+2)
	{ 
		for(;y<6;)
		{
			gotoxy(2,i);
			cout<<y<<".";
			y++;
			break;
		}
	}
// WEAPON NAME
	gotoxy(7,7);
	cout<<"Remington 870";
	gotoxy(7,9)            ;
	cout<<"Browning BPS" ;
	gotoxy(7,11) ;
	cout<<"Perazzi MX8";
	gotoxy(7,13)            ;
	cout<<"Beretta DT 11";
	gotoxy(7,15)            ;
	cout<<"Blaser F3";

// WEAPON PRICE

	gotoxy(51,7);
	cout<<"$ 411";
	gotoxy(51,9)            ;
	cout<<"$ 569" ;
	gotoxy(51,11) ;
	cout<<"$ 9861";
	gotoxy(51,13)            ;
	cout<<"$ 8050";
	gotoxy(51,15)            ;
	cout<<"$ 7250";

	gotoxy(1,17)  ;
	cout<<"\nPress 6 to go back to previous menu\n";
	cout<<"Press 7 to exit shop\n";
	while(n!=8)
	{ 
		cout<<"\nEnter choice\n";
		cin>>n;
		switch(n)
		{ 
			case 1: trans(8999);
			break;
			case 2: trans(439);
			break;
			case 3: trans(5999);
			break;
			case 4: trans(550);
			break;
			case 5: trans(34999);
			break;
			case 6: p_menu();
			break;
			case 7: exit(0);
			break;
			default: cout<<"\n Invalid choice\n\n";
		}
	}
}

/////////////////////////////////////////////////////////////////
///////////////////////ACCESSORY FUNCTIONS///////////////////////
/////////////////////////////////////////////////////////////////

//// MUZZLE ////
void muzzle()
{
	system("clear");
	cout<<"********************************************************************************\n\n";
	cout<<" Select your muzzle type\n";

//code for table
	int i,y,n;
	for(i=0;i<70;i++)
	{
		gotoxy(i,4);
		cout<<"_";
		gotoxy(i,6);
		cout<<"_";
		gotoxy(i,14)    ;
		cout<<"_";
	}
	for(i=5;i<15;i++)
	{
		gotoxy(1,i) ;
		cout<<"|";
		gotoxy(6,i);
		cout<<"|";
		gotoxy(50,i);
		cout<<"|";
		gotoxy(70,i);
		cout<<"|";
	}
	y=1;
	gotoxy(2,5);
	cout<<"Sno.";
	gotoxy(20,5)  ;
	cout<<" type";
	gotoxy(58,5);
	cout<<"Cost";

	for(i=7;i<16;i=i+2)
	{
		for(;y<5;)
		{
			gotoxy(2,i);
			cout<<y<<".";
			y++;
			break;
		}
	}
// NAME
	gotoxy(7,7);
	cout<<"Sniper rifle muzzle ";
	gotoxy(7,9)            ;
	cout<<"Assault rifle muzzle";
	gotoxy(7,11) ;
	cout<<"Pistol muzzle";
	gotoxy(7,13)            ;
	cout<<"Shotgun muzzle";

// PRICE
	gotoxy(51,7);
	cout<<"$ 400";
	gotoxy(51,9)            ;
	cout<<"$ 350" ;
	gotoxy(51,11) ;
	cout<<"$ 149";
	gotoxy(51,13)            ;
	cout<<"$ 225";

	gotoxy(1,17)  ;
	cout<<"\nPress 6 to go back to previous menu\n";
	cout<<"Press 7 to exit shop\n";
	while(n!=8)
	{ 
		cout<<"\nEnter choice\n";
		cin>>n;
		switch(n)
		{ 
			case 1: trans(400);
			break;
			case 2: trans(350);
			break;
			case 3: trans(149);
			break;
			case 4: trans(225);
			break;
			case 6: p_menu();
			break;
			case 7: exit(0);
			break;
			default: cout<<"\n Invalid choice\n\n";
		}
	}
}

//// SCOPE ////
void scope()
{
	system("clear");
	cout<<"********************************************************************************\n\n";
	cout<<" Select your scope type\n";

//code for table
	int i,y,n;
	for(i=0;i<70;i++)
	{
		gotoxy(i,4);
		cout<<"_";
		gotoxy(i,6);
		cout<<"_";
		gotoxy(i,14)    ;
		cout<<"_";
	}
	for(i=5;i<15;i++)
	{
		gotoxy(1,i) ;
		cout<<"|";
		gotoxy(6,i);
		cout<<"|";
		gotoxy(50,i);
		cout<<"|";
		gotoxy(70,i);
		cout<<"|";
	}
	y=1;
	gotoxy(2,5);
	cout<<"Sno.";
	gotoxy(20,5)  ;
	cout<<"Scope type";
	gotoxy(58,5);
	cout<<"Cost";

	for(i=7;i<16;i=i+2)
	{
		for(;y<5;)
		{
			gotoxy(2,i);
			cout<<y<<".";
			y++;
			break;
		}
	}

// NAME
	gotoxy(7,7);
	cout<<"Sniper rifle scope";
	gotoxy(7,9)            ;
	cout<<"Assault rifle scope";
	gotoxy(7,11) ;
	cout<<"Pistol scope";
	gotoxy(7,13)            ;
	cout<<"Shotgun scope";


// COST

	gotoxy(51,7);
	cout<<"$ 250";
	gotoxy(51,9)            ;
	cout<<"$ 200" ;
	gotoxy(51,11) ;
	cout<<"$ 125";
	gotoxy(51,13)            ;
	cout<<"$ 180";

	gotoxy(1,17)  ;
	cout<<"\nPress 6 to go back to previous menu\n";
	cout<<"Press 7 to exit shop\n";
	while(n!=8)
	{
		cout<<"\nEnter choice\n";
		cin>>n;
		switch(n)
		{ 
			case 1: trans(250);
			break;
			case 2: trans(200);
			break;
			case 3: trans(125);
			break;
			case 4: trans(180);
			break;
			case 6: p_menu();
			break;
			case 7: exit(0);
			break;
			default: cout<<"\n Invalid choice\n\n";
		}
	}
}

//// AMMO ////
void ammo()
{
	system("clear");
	cout<<"********************************************************************************\n\n";
	cout<<" Select your ammo type\n";

//code for table
	int i,y,n;
	for(i=0;i<70;i++)
	{
		gotoxy(i,4);
		cout<<"_";
		gotoxy(i,6);
		cout<<"_";
		gotoxy(i,14)    ;
		cout<<"_";
	}
	for(i=5;i<15;i++)
	{
		gotoxy(1,i) ;
		cout<<"|";
		gotoxy(6,i);
		cout<<"|";
		gotoxy(50,i);
		cout<<"|";
		gotoxy(70,i);
		cout<<"|";
	}
	y=1;
	gotoxy(2,5);
	cout<<"Sno.";
	gotoxy(20,5)  ;
	cout<<"Ammo type";
	gotoxy(58,5);
	cout<<"Cost";

	for(i=7;i<16;i=i+2)
	{
		for(;y<5;)
		{
			gotoxy(2,i);
			cout<<y<<".";
			y++;
			break;
		}
	}

// NAME
	gotoxy(7,7);
	cout<<"Sniper rifle ammo";
	gotoxy(7,9)            ;
	cout<<"Assault rifle ammo";
	gotoxy(7,11) ;
	cout<<"Pistol ammo";
	gotoxy(7,13)            ;
	cout<<"Shotgun ammo";

// COST
	gotoxy(51,7);
	cout<<"$ 125";
	gotoxy(51,9)            ;
	cout<<"$ 100" ;
	gotoxy(51,11) ;
	cout<<"$ 50";
	gotoxy(51,13)            ;
	cout<<"$ 75";

	gotoxy(1,17)  ;
	cout<<"\nPress 6 to go back to previous menu\n";
	cout<<"Press 7 to exit shop\n";
	while(n!=8)
	{ 
		cout<<"\nEnter choice\n";
		cin>>n;
		switch(n)
		{ 
			case 1: trans(125);
			break;
			case 2: trans(100);
			break;
			case 3: trans(50);
			break;
			case 4: trans(75);
			break;
			case 6: p_menu();
			break;
			case 7: exit(0);
			break;
			default: cout<<"\n Invalid choice\n\n";
		}
	}
}

//// CLIP ////
void clip()
{
	system("clear");
	cout<<"********************************************************************************\n\n";
	cout<<" Select your clip type\n";

//code for table
	int i,y,n;
	for(i=0;i<70;i++)
	{
		gotoxy(i,4);
		cout<<"_";
		gotoxy(i,6);
		cout<<"_";
		gotoxy(i,14)    ;
		cout<<"_";
	}
	for(i=5;i<15;i++)
	{
		gotoxy(1,i) ;
		cout<<"|";
		gotoxy(6,i);
		cout<<"|";
		gotoxy(50,i);
		cout<<"|";
		gotoxy(70,i);
		cout<<"|";
	}
	y=1;
	gotoxy(2,5);
	cout<<"Sno.";
	gotoxy(20,5)  ;
	cout<<"Clip type";
	gotoxy(58,5);
	cout<<"Cost";

	for(i=7;i<16;i=i+2)
	{
		for(;y<5;)
		{
			gotoxy(2,i);
			cout<<y<<".";
			y++;
			break;
		}
	}
// NAME
	gotoxy(7,7);
	cout<<"Sniper rifle clip";
	gotoxy(7,9)            ;
	cout<<"Assault rifle clip";
	gotoxy(7,11) ;
	cout<<"Pistol clip";
	gotoxy(7,13)            ;
	cout<<"Shotgun clip";

// COST
	gotoxy(51,7);
	cout<<"$ 75";
	gotoxy(51,9)            ;
	cout<<"$ 50" ;
	gotoxy(51,11) ;
	cout<<"$ 40";
	gotoxy(51,13)            ;
	cout<<"$ 30";

	gotoxy(1,17)  ;
	cout<<"\nPress 6 to go back to previous menu\n";
	cout<<"Press 7 to exit shop\n";
	while(n!=8)
	{
		cout<<"\nEnter choice\n";
		cin>>n;
		switch(n)
		{ 
			case 1: trans(75);
			break;
			case 2: trans(50);
			break;
			case 3: trans(40);
			break;
			case 4: trans(30);
			break;
			case 6: p_menu();
			break;
			case 7: exit(0);
			break;
			default: cout<<"\n Invalid choice\n\n";
		}
	}
}

//////////////////////// VOID MAIN ////////////////////////
int main()
{
	l_menu();
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
