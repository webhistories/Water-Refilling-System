#include<iostream>
#include<cctype>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
#include <fstream>
#define ESCAPE 27

using namespace std;

void gotoxy(short x, short y) {
COORD pos = {x, y};
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

//global declarations


fstream payroll;
void mainMenu();
int col =30; //used in login
int i; //used in login
int logCase=1; //used in logIn to switch after logging in
char resp1, resps;
int resp2; //used in employee accesses
int cases; //used in viewing and inputting options
int ans; //used in cust 
string line;
int gMin=0, gAlka=0, bMin=0, bAlka=0; //business sales
int inputgMin=0, inputgAlka=0, inputbMin=0, inputbAlka=0, criticalb=-1, criticalg=-1;
int finalgMin=0, finalgAlk=0, finalbMin=0, finalbAlk=0; 
int sumgMin, sumbMin, sumgAlka, sumbAlka;
int suminputgMin, suminputbMin, suminputgAlka, suminputbAlka;
	int j= 7, k=0, x=9, ctr;
						int length;	
				    char empFn[30], empLn[30], password[30], passwordLog[30];
					
	char ownerFn[30]="Laurence";
	char ownerLn[30]="Sojuaco";
	char ownerPass[30]="123ABC";
	int  ownerRefnum = 1000;
	
	
	 int amt,amt1,amt2,amt3,amt4,amt5,amt6,amt7;
	 int amtIn,amt1In,amt2In,amt3In,amt4In,amt5In,amt6In,amt7In;
 char date[20],date1[20],date2[20],date3[20],date4[20],date5[20],date6[20],date7[20]; //used in business expenses
 

 
fstream inventory;
fstream log_in_file;
fstream busSales;
fstream busSalesindiv;
fstream ccount;
fstream record;
		//for inputs
	int refNumO;
	char pass[30];
		//to compare inputs
		int ownerPassnum, passNum;


	//int j= 7, k=0, x=9, ctr;
void logIn(){
	logbalik:
		int refNum=0; int refNumLog=0;
        int wrong=0, correct=0;
		//owner info by default
/////emil payroll


// fstream payroll;
/////
	char ans;
	 do{
			system("cls");
			gotoxy(37,1);
			cout<<"LOG IN/SIGN UP";
			gotoxy(col,3);
			cout<<"Enter Position to Log In";
			gotoxy(col,5);
			cout<<"[A] Owner"<<endl;
			gotoxy(col,6);
			cout<<"[B] Employee"<<endl;
			gotoxy(col,7);
			cout<<"[C] Exit Program"<<endl;

			gotoxy(col,9);
			cout<<"Select your Option: ";
			cin>>ans;
			ans=toupper(ans);
		}//do
		while(ans!='A' && ans!='B' && ans!='C' && ans!='D');
		system("cls");
		

		switch(ans){
        	case 'A':
        		back:
        		system("cls");

        		wrong=0;
        		do{
        		system("cls");
				gotoxy(23,1);
         	    cout<<"************ OWNER LOG IN ************";
         	    gotoxy(23,2);
         	    cout<<"Press any key to CONTINUE and ESC to EXIT: ";
         	    getch();
         	    if (GetAsyncKeyState(VK_ESCAPE))
        		goto logbalik;
         	    else {
         	    gotoxy(30,4);
        		cout<<"Reference Number	        : ";
        		gotoxy(30,6);
        		cout<<"Password (case sensitive) : ";
        		gotoxy(58,4);
        		cin>>refNumO;
        		if(refNumO!=1000)
				{gotoxy(17, 8); cout<<"Invalid REFERENCE number! Press any key to try again.";getch(); goto back;}//if
        		gotoxy(58,6);
        		cin>>pass;
        		//checking of input
        		ownerPassnum = strlen(ownerPass);
        		passNum = strlen(pass);
        		if(passNum<ownerPassnum)
        		wrong++;
        		else{
        		for(i=0; i<passNum; i++){
        		if(strcmp(ownerPass, pass)!=0)
        		wrong++;
        		else if (strcmp(ownerPass, pass)==0)
        		correct++;}//for
        		}//else
        		//evaluating checked input
        		if(refNumO==ownerRefnum && (correct)==ownerPassnum)
        		{gotoxy(25,8);cout<<ownerFn<<" "<<ownerLn<<", log in was successful!"; logCase = 1; getch(); break;}//if

        		else 
        		{gotoxy(30,8);cout<<"Reference number or password was incorrect!";getch(); }//else
        		}//else 
        		}//do
        		while(refNumO!=ownerRefnum || wrong>=1);
				break;
				
				case 'B':
					balik:
						
							log_in_file.open("supervisor.txt", ios::in);
							log_in_file.open("deliveryboy.txt", ios::in);
							log_in_file.open("filterboy.txt",ios::in);
							
					system("cls");

						log_in_file.seekg(0, ios::end); 
						if(log_in_file.fail()){
								
							log_in_file.open("supervisor.txt", ios::out | ios::app);
							log_in_file.open("deliveryboy.txt", ios::out | ios::app);
							log_in_file.open("filterboy.txt", ios::out | ios::app);
						log_in_file.close(); log_in_file.close(); log_in_file.close();
						i=0;
						}
						 
						else if (log_in_file.tellg() == 0) {   
						getch(); 
						  i=0; 
						}
						else
						i=1;
						
						
					log_in_file.close(); log_in_file.close();	log_in_file.close(); //checking
							
						gotoxy(23,1);
		         	    cout<<"************ EMPLOYEE SIGN UP/LOG IN ************";
		         	    gotoxy(23,2);
		         	    cout<<"Press any key to continue and ESC to EXIT: ";
		         	    getch();
		         	    if (GetAsyncKeyState(VK_ESCAPE))
		        		goto logbalik;
		         	    else {
		
		         	    gotoxy(30,5);
		        		cout<<"Reference Number             : ";
		        		gotoxy(65, 5); cin>>refNumLog;
		        		if(refNumLog!=1001 && refNumLog!=1002 && refNumLog!=1003)
						{gotoxy(17,7);cout<<"Invalid REFERENCE NUMBER! Press any key to retry..."; getch(); goto balik;}//if
						
						if(refNumLog==1001)
							{logCase=2; i=1;}
								else if(refNumLog==1002)
								{logCase=3; i=1;}
								else if(refNumLog==1003)
								{logCase=4; i=1;}
								
		        		if(i==1){
											switch(logCase){
						case 2:
							log_in_file.open("supervisor.txt", ios::in);
							
							break;
						case 3:
							log_in_file.open("deliveryboy.txt", ios::in);
							break;
						case 4:
							log_in_file.open("filterboy.txt", ios::in);
							break;
					}//switch
							log_in_file>>refNum>>empFn>>empLn>>password; 
							//cout<<refNumLog<<" "<<refNum;
			
							for(;;){
								
						/*	if(log_in_file.eof())
							{
							i=0;	
							break;
							}	*/	
											
				        	if(refNumLog==refNum)
							{
							baliklogin:
							system("cls");
							gotoxy(23,1);
				         	cout<<"************ EMPLOYEE LOG IN ************";
				         	gotoxy(5,2);
				         	cout<<"Welcome back "<<empFn<<" "<<empLn<<"!  "<<"Press any key to LOG IN and ESC to EXIT: ";
								gotoxy(30,5);
								
				        		cout<<"Reference Number	        : ";
				        		gotoxy(30,7);
				        		cout<<"Password (case sensitive) : ";
								gotoxy(58,5);
								cin>>refNumLog;
								gotoxy(58, 7);
								cin>>passwordLog;
								if(refNumLog==refNum && strcmp(password, passwordLog)==0 )
								{gotoxy(25,8);cout<<"Success! Accessing Records....."; 
								
								getch();
								break;
								}//if
								else
								{gotoxy(17,8); cout<<"Reference Number or Password was incorrect."; getch(); goto baliklogin;}//else
								i=1;
							}//if
							
							else if(refNumLog!=refNum)
							{
							 log_in_file.close(); goto upsign;
							}
							}//for 
								
							log_in_file.close();
								}//if 
							//}//if i==1	
				        	
					
				else if(i==0){
				upsign:
					system("cls");
					switch(logCase){
						case 2:
							log_in_file.open("supervisor.txt", ios::out | ios::app);
							
							break;
						case 3:
							log_in_file.open("deliveryboy.txt", ios::out | ios::app);
							break;
						case 4:
							log_in_file.open("filterboy.txt", ios::out | ios::app);
							break;
					}//switch
					
						gotoxy(23,1);
		         	    cout<<"************ EMPLOYEE SIGN UP ************"<<i;
		         	    gotoxy(23,2);
		         	    cout<<"Press any key to SIGN UP and ESC to EXIT: ";
		         	    getch();
		         	    if (GetAsyncKeyState(VK_ESCAPE))
		        		break;
		         	    else {
		         	    gotoxy(30,5);
		        		cout<<"First Name               : ";
		        		gotoxy(30,6);
		        		cout<<"Last Name               : ";
		         	    gotoxy(30,7);
		        		cout<<"Reference Number	        : ";
		        		gotoxy(30,8);
		        		cout<<"Password (case sensitive) : ";
		        		gotoxy(58,5);
		        		cin>>empFn;
		        		gotoxy(58,6);
		        		cin>>empLn;
		        		gotoxy(58,7);
		        		cin>>refNum; //cin.ignore();
		        		gotoxy(58,8);
		        		cin>>password; //cin.ignore();
		        		log_in_file<<refNum<<" "<<empFn<<" "<<empLn<<" "<<password<<endl;
		        	//	cout<<"write"; getch();//i=1;
		        		log_in_file.close();
		        		break;
		        		
		        	
						}
		        	}//if
				
				}//else not esc
	break;
					
		case 'C':
						gotoxy(15,12);
						system("color 8f");
						cout<<"Exiting Program. Press any key to continue...."<<endl;
						getch();
						exit(0);
					break;
		}//switch
	
}//logIn



struct node
{
	char fname[31];
	char lname[31];
	double cont;
	char address[31];
	char subd[45];
	int hnum;
	int block;
	
	node *next;
};
int custdeets()
{
	node *start=NULL,*ptr,*temp;
	ptr=(node*)malloc(sizeof(node));
	temp=(node*)malloc(sizeof(node));
	char resp,ch;
	here:
	system("cls");
	gotoxy(20,3);cout<<"[A] Add Info";
	gotoxy(20,4);cout<<"[B] Customer Info";
	gotoxy(20,5);cout<<"[C] Go Back to Main Menu";
	gotoxy(20,6);cout<<"Enter choice => "; cin>>ch;
	switch(toupper(ch))
	{
	case 'A':
	resp='Y';
	while(toupper(resp)=='Y')
	{
		system("cls");
		ptr= new node;
		gotoxy(1,1);cout<<"Enter First name: "; cin>>ptr->fname; 
		gotoxy(1,2);cout<<"Enter Last name: ";cin>>ptr->lname;
		gotoxy(1,3);cout<<"Enter Contact no.: "; cin>>ptr->cont;
		gotoxy(1,4);cout<<"Village/Subdivision ";gotoxy(2,5); cin>>ptr->address;
		gotoxy(30,4);cout<<"(Street) ";gotoxy(30,5); cin>>ptr->subd;
		gotoxy(50,4);cout<<"(House number) ";gotoxy(50,5); cin>>ptr->hnum;
		gotoxy(70,4);cout<<"(Block Lot) ";gotoxy(70,5); cin>>ptr->block;
		ptr->next=NULL;
		if(start==NULL)
		{
			start=ptr;
		}
		else
		{
			temp=start;
			while(temp->next!=NULL)
			{
				temp=temp->next;
			}
			temp->next=ptr;
		}
	    cout<<"\n\tEnter again?[y/n] "; cin>>resp;
	}
	goto here;
	break;
	case 'B':
		system("cls");
		if(start==NULL)
		{
			cout<<"\n\t\tNo info found!";
			getch();
			mainMenu();
		}
		else
		{
			int x;
			temp=start;
			x=0;
			if(temp->next==NULL)
			{
				gotoxy(1,1);cout<<"First name: "<<temp->fname; 
		        gotoxy(1,2);cout<<"Last name: "<<temp->lname;
	        	gotoxy(1,3);cout<<"Contact no.: "<<temp->cont;
	        	gotoxy(1,4+x);cout<<"Village/Subdivision"<<endl;
	        	gotoxy(30,4+x);cout<<"Street"<<endl;
	        	gotoxy(50,4+x);cout<<"House Number"<<endl;
	        	gotoxy(70,4+x);cout<<"Block Lot"<<endl;
	         	gotoxy(1,5+x);cout<<temp->address<<endl;
	        	gotoxy(30,5+x);cout<<temp->subd<<endl;
	        	gotoxy(50,5+x);cout<<temp->hnum<<endl;
	        	gotoxy(70,5+x);cout<<temp->block<<endl;
				cout<<"\n\t";
				system("pause");
			}
			else
			{
			while(temp->next!=NULL)
			{
				system("cls");
				gotoxy(1,1);cout<<"First name: "<<temp->fname; 
		        gotoxy(1,2);cout<<"Last name: "<<temp->lname;
	        	gotoxy(1,3);cout<<"Contact no.: "<<temp->cont;
	        	gotoxy(1,4+x);cout<<"Village/Subdivision"<<endl;
	        	gotoxy(30,4+x);cout<<"Street"<<endl;
	        	gotoxy(50,4+x);cout<<"House Number"<<endl;
	        	gotoxy(70,4+x);cout<<"Block Lot"<<endl;
	         	gotoxy(1,5+x);cout<<temp->address<<endl;
	        	gotoxy(30,5+x);cout<<temp->subd<<endl;
	        	gotoxy(50,5+x);cout<<temp->hnum<<endl;
	        	gotoxy(70,5+x);cout<<temp->block<<endl;
				temp=temp->next;
				cout<<"\n\t";
				system("pause");
			}
				system("cls");
				gotoxy(1,1);cout<<"First name: "<<temp->fname; 
		        gotoxy(1,2);cout<<"Last name: "<<temp->lname;
	        	gotoxy(1,3);cout<<"Contact no.: "<<temp->cont;
	        	gotoxy(1,4+x);cout<<"Village/Subdivision"<<endl;
	        	gotoxy(30,4+x);cout<<"Street"<<endl;
	        	gotoxy(50,4+x);cout<<"House Number"<<endl;
	        	gotoxy(70,4+x);cout<<"Block Lot"<<endl;
	         	gotoxy(1,5+x);cout<<temp->address<<endl;
	        	gotoxy(30,5+x);cout<<temp->subd<<endl;
	        	gotoxy(50,5+x);cout<<temp->hnum<<endl;
	        	gotoxy(70,5+x);cout<<temp->block<<endl;
				cout<<"\n\t";
				system("pause");
			}
			goto here;
		}
	break;
	case 'C':
			mainMenu();
	default: goto here;
	}
}//custdeets


void busSale(){
	char answer;
	int clientSn, btype, wtype, qty, amt;

	system("cls");	
						gotoxy(23,1);
		         	    cout<<"************ BUSINESS SALES ************";
		         	    
switch(logCase){
	
	
case 1:

	busSalesindiv.open("busSalesindiv.txt", ios::in);
	gotoxy(23,2);
	
		         	    cout<<"Press any key to VIEW DATA and ESC to GO BACK: ";
		         	    
		         	gotoxy(1,5);cout<<"Ref.Num"; gotoxy(10,5);cout<<" Alkaline in Gal."; gotoxy(27,5); cout<<"Alkaline in 1L"; 
					gotoxy(42,5);cout<<"Mineral in Gal.";gotoxy(56,5);cout<<"Mineral in 1L";gotoxy(73,5);cout<<"Amount";
		         	    getch();
		         	    if (GetAsyncKeyState(VK_ESCAPE))
		        		mainMenu();

									while(1){
	
					if(busSalesindiv.eof())
					{
					i=0;	
					break;
					}
					else if(busSalesindiv.fail())
					{
					gotoxy(30, 4);cout<<"FILE IS EMPTY!!"; break;}
		
					else
					i=1;
							
				
					if(i=1){
					busSalesindiv>>clientSn>>amt>>gAlka>>bAlka>>gMin>>bMin;
					busSalesindiv.close();
					gotoxy(4,j);cout<<clientSn; gotoxy(16,j);cout<<gAlka; gotoxy(35,j);cout<<bAlka; gotoxy(47,j);cout<<gMin; gotoxy(62,j);cout<<bMin;gotoxy(75,j);cout<<amt;
					j++; 
					
					}//if
					else if(i!=1){
					cout<<"Empty!";
					busSalesindiv.close();		}//else if
					}//for
					//busSalesindiv.close();
					break;

case 2:					 

						busSales.open("busSales.txt", ios::out | ios::trunc);
						busSalesindiv.open("busSalesindiv.txt", ios::out | ios::trunc);
		         	    gotoxy(23,2);
		         	    cout<<"Press any key to INPUT DATA and ESC to GO BACK: ";
		         	    getch();
		         	    if (GetAsyncKeyState(VK_ESCAPE))
		        		mainMenu();
		         	    else {
		         	    while(answer!='N'&& answer!='n'){
		         	    btype=0; wtype=0;
		         	    gMin=0, gAlka=0, bMin=0, bAlka=0;
		         	    gotoxy(3,5);cout<<"Client"; gotoxy(3,6);cout<<"(Ref. Num)"; gotoxy(15,5);cout<<" Container"; gotoxy(15,6);cout<<"(1 for Gallon,"; gotoxy(13,7); 
						 cout<<"  2 for 1L)"; gotoxy(32,5); cout<<"Water Type"; gotoxy(30,6); cout<<"(1 for Mineral,"; gotoxy(28,7); cout<<" 2 for Alkaline)";
						 gotoxy(46,5);cout<<"Quantity";gotoxy(57,5);cout<<"Amount";gotoxy(65,5);cout<<"Add More?";gotoxy(69,6);cout<<"[Y/N]";
		        		gotoxy(5,x);cin>>clientSn;  while(btype!=1 && btype!=2){gotoxy(19,x);cin>>btype;}
						 while(wtype!=1 && wtype!=2){gotoxy(35,x);cin>>wtype;} gotoxy(48,x);cin>>qty; gotoxy(59,x);cin>>amt; 
						gotoxy(70,x);	cin>>answer;
						
						if(btype==1 && wtype==1)
						gMin = 1*qty;
						else if(btype==2 && wtype==2)
						bAlka = 1*qty;
						else if(btype==1 && wtype==2)
						gAlka = 1*qty;
						else if(btype==2 && wtype==1)
						bMin = 1*qty;
						
						suminputbMin+=bMin;
						suminputbAlka+=bAlka;
						suminputgAlka+=gAlka;
						suminputgMin+=gMin;
						
		        		
		        		busSalesindiv<<clientSn<<" "<<amt<<" "<<gAlka<<" "<<bAlka<<" "<<gMin<<" "<<bMin<<endl;
		        		x=x+1;
		        		} 
		        		busSales<<suminputgAlka<<" "<<suminputbAlka<<" "<<" "<<suminputgMin<<" "<<suminputbMin<<endl;
		        		busSales.close();
		        		busSalesindiv.close();
						}//else
						getch();
						mainMenu();
						break;
						
	}//switch
	
			}//void busSales


void inventoryOP(){
	system("cls");	
						gotoxy(19,1);
		         	    cout<<"************ INVENTORY MANAGEMENT ************";	
		

			do{
			gotoxy(col,3);
			cout<<"[A] Re/stock inventory"<<endl;
			gotoxy(col,4);
			cout<<"[B] Check inventory"<<endl;
			gotoxy(col,5);
			cout<<"[C] Set Critical Count"<<endl;
			gotoxy(col,6);
			cout<<"[D] Go Back to Main Menu";
			gotoxy(col,8);
			cout<<"Select your Option: ";
			cin>>resp1;
			resp1=toupper(resp1);
			}while(resp1!='A' && resp1!='B' && resp1!='C' && resp1!='D');
			switch(resp1){
				
			case 'A':
				
						system("cls");
						
						inventory.open("inventory.txt", ios::out | ios::trunc);
						
						gotoxy(19,1);
		         	    cout<<"************ INVENTORY MANAGEMENT ************";	
		         	    gotoxy(15,2);
		         	    cout<<"Press any key to RESTOCK INVENTORY and ESC to GO BACK: ";
		         	    getch();
		         	    if (GetAsyncKeyState(VK_ESCAPE))
		        		mainMenu();
		         	    else {
						gotoxy (18,3);  cout<<"Type of Water";
						gotoxy(18, 5);  cout<<"Alkaline";
						gotoxy(18,7);   cout<<"Mineral";
						gotoxy (36, 5); cout<<"Gallon";
						gotoxy (36, 6); cout<<"Bottle (1L)";
						gotoxy(35, 3);  cout<<"Container";
						gotoxy (36, 7); cout<<"Gallon";
						gotoxy (36, 8); cout<<"Bottle (1L)";
						gotoxy (48, 5); cin>>inputgAlka;
						gotoxy(48,6); cin>>inputbAlka;
						gotoxy (48, 7); cin>>inputgMin;
						gotoxy (48, 8); cin>>inputbMin;
						
						sumgAlka+=inputgAlka;
						sumgMin+=inputgMin;
						sumbMin+=inputbMin;
						sumbAlka+=inputbAlka;
						//counter++;
						inventory<<sumgAlka<<" "<<sumbAlka<<" "<<sumgMin<<" "<<sumbMin<<endl;   
						
						inventory.close();
						
							}//else
						getch();	
						mainMenu();
						break;
			case 'B':
					system("cls");
						gotoxy(19,1);
		         	    cout<<"************ INVENTORY MANAGEMENT ************";	
					inventory.open("inventory.txt", ios::in);
					gotoxy(23,2);
		         	cout<<"Press any key to VIEW DATA and ESC to GO BACK: ";
		         	j=7;
		        
		         	
		         	 gotoxy(3,6);cout<<"Alkaline(Gal)"; gotoxy(3,7); cout<<"Alkaline(1L)"; 
					gotoxy(3,8);cout<<"Mineral(Gal)";gotoxy(3,9);cout<<"Mineral(1L)";
					gotoxy(40,5);cout<<"Critical?"; gotoxy(25,5); cout<<"Qty.";
		         	    getch();
				 if (GetAsyncKeyState(VK_ESCAPE))
		        		mainMenu();

					while(1){
	
					if(inventory.eof())
					{
					i=0;
					/*cout<<"FILE IS EMPTY!!!";*/ 	
					break;
					}
					 
					else if(inventory.fail()){i=-1;
					gotoxy(25, 6);cout<<"FILE IS EMPTY!!"; return; inventory.close();
					}//else
					
					
					else if(!inventory.fail()){
					busSales.open("busSales.txt", ios::in);
					ccount.open("ccount.txt", ios::in);
					inventory>>sumgAlka>>sumbAlka>>sumgMin>>sumbMin;
					busSales>>suminputgAlka>>suminputbAlka>>suminputgMin>>suminputbMin;
					ccount>>criticalg>>criticalb;
					
					finalgAlk =sumgAlka - suminputgAlka ;
					finalbAlk =sumbAlka - suminputbAlka ;
					finalgMin =sumgMin - suminputgMin;
					finalbMin =sumbMin - suminputbMin;
					
					if(criticalg==-1)
					{gotoxy(40, 6); cout<<"NO INPUT";}
					
					else{
					if(finalgAlk<=criticalg)
					
					{gotoxy(40,6); cout<<"YES";}
					else
					{gotoxy(40,6); cout<<"NO";}
					
					if(finalbAlk<=criticalb)
					{gotoxy(40,7); cout<<"YES";}
					else
					{gotoxy(40,7); cout<<"NO";}
					
					
					if(finalgMin<=criticalg)
					{gotoxy(40,8); cout<<"YES";}
					else
					{gotoxy(40,8); cout<<"NO";}
					
					if(finalbMin<=criticalb)
					{gotoxy(40,9); cout<<"YES";}
					else
					{gotoxy(40,9); cout<<"NO";}
				}//el
		gotoxy(25,6); cout<<finalgAlk; gotoxy(25,7);cout<<finalbAlk; gotoxy(25,8);cout<<finalgMin; gotoxy(25,9);cout<<finalbMin; 
					 //j++;
				
					}//else if
					busSales.close();
					inventory.close();
					ccount.close();
				
					}//for
					getch();
					mainMenu();
					break;
				
			case 'C':
				system("cls");
						
						ccount.open("ccount.txt", ios::out | ios::trunc);
						gotoxy(19,1);
		         	    cout<<"************ INVENTORY MANAGEMENT ************";	
		         	    gotoxy(13,2);
		         	    cout<<"Press any key to ADD CRITICAL COUNT and ESC to GO BACK: ";
		         	    getch();
		         	    if (GetAsyncKeyState(VK_ESCAPE))
		        		mainMenu();
		         	    else {
				gotoxy (20, 4); cout<<"Enter Critical Count for Gallons:  "; 
				gotoxy (20, 5); cout<<"Enter Critical Count for Bottles:  "; 
				gotoxy(54, 4); cin>>criticalg;
				gotoxy(54, 5); cin>>criticalb;
				ccount<<criticalg<<" "<<criticalb;
				ccount.close();
				
				
				}//else
				getch();
				mainMenu();
				break;
				case 'D':
					mainMenu();
					break;
							
						}//switch resp1
getch();
		
}//inventory

void indi()
{
	system("cls");
	gotoxy(34,3);
	cout<<"PAYROLL REPORT";
	for(int i=30; i<=50; i++)
	{
		gotoxy(i,2);
		cout<<(char)196;
		gotoxy(i,20);
		cout<<(char)196;
		gotoxy(i,4);
		cout<<(char)196;
	}// x axis outer
	
		for (int i=3;i<=19; i++)
	{
		gotoxy(30,i);
		cout<<(char)179;
		gotoxy(50,i);
		cout<<(char)179;
	}// y axis outer
}


void table()
{
	gotoxy(10,2);
	cout<<(char)218;
	gotoxy(70,20);		
	cout<<(char)217;
	gotoxy(70,2); 
	cout<<(char)191;
	gotoxy(10,20);
	cout<<(char)192;
	gotoxy(33,3);
	cout<<"PAYROLL REPORT";
	gotoxy(16,5);
	cout<<"POSITION";
	gotoxy(15,7);
	cout<<"SUPERVISOR";
	gotoxy(14,8);
	cout<<"DELIVERY GUY";
	gotoxy(14,9);
	cout<<"FILTERING GUY";
	gotoxy(31,5);
	cout<<"HOURS";
	gotoxy(39,5);
	cout<<"GALLONS";
	gotoxy(49,5);
	cout<<"TIMES";
	gotoxy(59,5);
	cout<<"SALARY";
	
	for (int i=11; i<=69; i++)
	{
		gotoxy(i,2);
		cout<<(char)196;
		gotoxy(i,20);
		cout<<(char)196;
		gotoxy(i,4);
		cout<<(char)196;
		gotoxy(i,6);
		cout<<(char)196;
	}// x axis outer
	
	for (int i=3;i<=19; i++)
	{
		gotoxy(10,i);
		cout<<(char)179;
		gotoxy(70,i);
		cout<<(char)179;
	}// y axis outer
	
	for (int i=5; i<=19; i++)
	{
		gotoxy(29,i);
		cout<<(char)179;
		gotoxy(37,i);
		cout<<(char)179;
		gotoxy(47,i);
		cout<<(char)179;
		gotoxy(55,i);
		cout<<(char)179;
	}// y axis inner
}


//////EXPENSES


void busExpRet(){
			
	system("cls");
			
			int col=5;
			gotoxy(37,1);
			cout<<"********EXPENSES REPORT********";
			record.open("elecB.txt", ios::in);
			record>>amt>>date;
			record.close();
			record.open("teleB.txt", ios::in);
			record>>amt1>>date1;
			record.close();
			record.open("fuelB.txt", ios::in);
			record>>amt2>>date2;
			record.close();
			record.open("vehiB.txt", ios::in);
			record>>amt3>>date3;
			record.close();
			record.open("waterB.txt", ios::in);
			record>>amt4>>date4;
			record.close();
			record.open("filtB.txt", ios::in);
			record>>amt5>>date5;
			record.close();
			record.open("minB.txt", ios::in);
			record>>amt6>>date6;
			record.close();
			record.open("alkaB.txt", ios::in);
			record>>amt7>>date7;
			record.close();
			
			
			
			
			
			gotoxy(col+28, 3);
			cout<<"Amount Spent";
			gotoxy(col+50, 3);
			cout<<"Date of Last Purchase";
			
			gotoxy(col+30, 4);
			cout<<amt;
			gotoxy(col+50,4);
			cout<<date;
			gotoxy(col+30, 5);
			cout<<amt1;
			gotoxy(col+50,5);
			cout<<date1;
			gotoxy(col+30, 6);
			cout<<amt2;
			gotoxy(col+50,6);
			cout<<date2;
			gotoxy(col+30, 7);
			cout<<amt3;
			gotoxy(col+50,7);
			cout<<date3;
			gotoxy(col+30, 8);
			cout<<amt4;
			gotoxy(col+50,8);
			cout<<date4;
			gotoxy(col+30, 9);
			cout<<amt5;
			gotoxy(col+50,9);
			cout<<date5;
			gotoxy(col+30, 10);
			cout<<amt6;
			gotoxy(col+50,10);
			cout<<date6;
			gotoxy(col+30, 11);
			cout<<amt7;
			gotoxy(col+50,11);
			cout<<date7;
			
		
			gotoxy(col,4);
			cout<<"Electric Bill"<<endl;
			gotoxy(col,5);
			cout<<"Telephone Bill"<<endl;
			gotoxy(col,6);
			cout<<"Fuel"<<endl;
			gotoxy(col,7);
			cout<<"Vehicle Maintenance"<<endl;
			gotoxy(col,8);
			cout<<"Watertank Maintenance"<<endl;
			gotoxy(col,9);
			cout<<"Filter Replacement"<<endl;
			gotoxy(col,10);
			cout<<"Mineral Water"<<endl;
			gotoxy(col,11);
			cout<<"Alkaline Water"<<endl;

			
	
}//busExpRet


void busExp()
{
	
	char cho;
 int resp2,ch,ans;
							do
						   	{
						   	here:
						   		
						   		
						system("cls");
							gotoxy(37,1);
			cout<<"********ADD EXPENSES********";
			gotoxy(col,4);
			cout<<"[1] Electric Bill"<<endl;
			gotoxy(col,5);
			cout<<"[2] Telephone Bill"<<endl;
			gotoxy(col,6);
			cout<<"[3] Fuel"<<endl;
			gotoxy(col,7);
			cout<<"[4] Vehicle Maintenance"<<endl;
			gotoxy(col,8);
			cout<<"[5] Watertank Maintenance"<<endl;
			gotoxy(col,9);
			cout<<"[6] Filter Replacement"<<endl;
			gotoxy(col,10);
			cout<<"[7] Mineral Water"<<endl;
			gotoxy(col,11);
			cout<<"[8] Alkaline Water"<<endl;
			gotoxy(col,12);
			gotoxy(col,14);
			cout<<"Select your Option: ";
			cin>>ans;
				}while(ans!=1 && ans!=2 && ans!=3 && ans!=4 && ans!=5 && ans!=6 && ans!=7 && ans!=8);
		system("cls");
						
							
							
							switch (ans)
							{
							 case 1: 
							 record.open("elecB.txt", ios::out | ios::trunc);
							 cout<<"Enter amount:"<<endl; 
							 cin>>amtIn; //cin.ignore();
							 cout<<"Enter date(MM/DD/YYYY):"<<endl;
							 cin>>date; cin.ignore();
							  amt= amt+amtIn;
							 record<<amt<<" "<<date<<endl;
							record.close();
						      balik: gotoxy(1,45); cout<<"ADD MORE?[Y/N]"<<endl;
				             cin>>cho; 
				             if(cho=='Y' || cho=='y')
				             	goto here;
				            else if(cho=='n' || cho=='N'){
							record.close();	mainMenu();	}//else if
							else
							{gotoxy(1,47); cout<<"INVALID INPUT!!!"<<endl; getch(); system("cls");goto balik;}  break; 
									  
							 case 2:record.open("teleB.txt", ios::out | ios::trunc);
						   	 cout<<"Enter amount:"<<endl;
							 cin>>amt1In; cin.ignore();
							 cout<<"Enter date (MM/DD/YYYY):"<<endl;
							 cin>>date1; cin.ignore();
							 amt1+=amt1In;
							 record<<amt1<<" "<<date1<<endl;
							 goto balik;
							 break;
							 
							 case 3: record.open("fuelB.txt", ios::out | ios::trunc);
							 cout<<"Enter amount:"<<endl;
							 cin>>amt2In; cin.ignore();
							 cout<<"Enter date(MM/DD/YYYY):"<<endl;
							 cin>>date2; cin.ignore();
							 amt2+=amt2In;
							 record<<amt2<<" "<<date2<<endl;
							 record.close();
							 goto balik;
							 break;
							 
							  case 4: record.open("vehiB.txt", ios::out | ios::trunc);
							 cout<<"Enter amount:"<<endl;
							 cin>>amt3In; cin.ignore();
							 cout<<"Enter date (MM/DD/YYYY):"<<endl;
							 cin>>date3; cin.ignore();
							 amt3+=amt3In;
							 record<<amt3<<" "<<date3<<endl;
							 record.close();
							 goto balik;
							 break;
							
							 case 5: record.open("waterB.txt", ios::out | ios::trunc);
							 cout<<"Enter amount:"<<endl;
							 cin>>amt4In; cin.ignore();
							 cout<<"Enter date (MM/DD/YYYY):"<<endl;
							 cin>>date4; cin.ignore();
							 amt4+=amt4In;
							 record<<amt4<<" "<<date4<<endl;
							 record.close();
							 goto balik;
							 break;
							
							 case 6: record.open("filtB.txt", ios::out | ios::trunc); 
							 cout<<"Enter amount:"<<endl;
							 cin>>amt5In; cin.ignore();
							 cout<<"Enter date(MM/DD/YYYY):"<<endl;
							 cin>>date5; cin.ignore();
							 amt5+=amt5In;
							 record<<amt5<<" "<<date5<<endl;
							 record.close();
							 goto balik;
							 break;
							
							 case 7: record.open("minB.txt", ios::out | ios::trunc);
							 cout<<"Enter amount:"<<endl;
							 cin>>amt6In; cin.ignore();
							 cout<<"Enter date (MM/DD/YYYY):"<<endl;
							 cin>>date6; cin.ignore();
							 amt6+=amt6In;
							 record<<amt6<<" "<<date6<<endl;
							 record.close();
							 goto balik;
							 break;
							
							 case 8:record.open("alkaB.txt", ios::out | ios::trunc);
							 cout<<"Enter amount:"<<endl;
							 cin>>amt7In;
							 cout<<"Enter date(MM/DD/YYYY):"<<endl;
							 cin>>date7;
							 amt7+=amt7In;
							 record<<amt7<<" "<<date7<<endl;
							 record.close();
							 goto balik;
							 break;
							 }
							 
}//end of exp


void mainMenu(){
	
char resp3;
 int hrs=0,gal=0,times=0;
 float supsal=0, dpsal=0, filsal=0;
 int ans;
 
do{
system("cls");
gotoxy(37,1);
cout<<"MAIN MENU";


if(logCase==1 || logCase==2){
gotoxy(col,3);
cout<<"[A] Business Transactions"<<endl;}
else if(logCase==3 || logCase==4){
gotoxy(col,3);
cout<<"[A] Check Salary"<<endl;	
gotoxy(col,4);
cout<<"[B] Logout"<<endl;

}
//////////////SWITCH CASE TO DETERMINE EMPLOYEE AND OWNER SPECIFIC SUB MENU////////////////////
switch(logCase){
case 1:
gotoxy(col,4);
cout<<"[B] Payroll Management"<<endl;
break;
case 2:
gotoxy(col,4);
cout<<"[B] Check Salary"<<endl;
break;
}//switch
//////////////END OF SWITCH////////////////////////////////////////////////////
if(logCase==1 || logCase==2){
gotoxy(col,5);
cout<<"[C] Inventory"<<endl;
gotoxy(col,6);
cout<<"[D] Logout"<<endl;}//if
gotoxy(col,8);
cout<<"Select your Option: ";
cin>>resps;
resps=toupper(resps);
}while(resps!='A' && resps!='B' && resps!='C' && resps!='D');
switch(resps){
case 'A':
	
	if(logCase==3){
						 indi();
				 		   payroll.open ("dp.txt", ios::in);
						   gotoxy(34,5);
						   cout<<"POSITION: "<<endl;
					       gotoxy(34,9);
						   cout<<"GALLONS:    "<<endl;
						   gotoxy(34,12);
						   cout<<"SALARY:   "<<endl;
				 		   gotoxy(34,6);
				 		   cout<<"DELIVERY";
						   gotoxy(34,7);
						   cout<<"PERSONNEL"<<endl;
				 		   payroll>>dpsal>>gal;
						   gotoxy(34,10);
						   cout<<gal;						   
						   gotoxy(34,13);
						   cout<<dpsal;
						   gotoxy(10,23);
						   cout<<endl<<endl<<"Press Any Key to Continue";
				 		   getch();
				 		   payroll.close();
				 		  mainMenu();
		
	}
	
	else if (logCase==4){
				 		indi();
				 		   payroll.open ("fil.txt", ios::in);
						   gotoxy(34,5);
						   cout<<"POSITION: "<<endl;
					       gotoxy(34,9);
						   cout<<"TIMES:    "<<endl;
						   gotoxy(34,12);
						   cout<<"SALARY:   "<<endl;
				 		   gotoxy(34,6);
				 		   cout<<"FILTERING";
						   gotoxy(34,7);
						   cout<<"PERSONNEL";
				 		   payroll>>filsal>>times;
						   gotoxy(34,10);
						   cout<<times;						   
						   gotoxy(34,13);
						   cout<<filsal;
						   gotoxy(10,23);
						   cout<<endl<<endl<<"Press Any Key to Continue";
				 		   getch();
				 		   payroll.close();
				 		   mainMenu();
				 		   
	}
	
	else{
	
			do{
			system("cls");
			gotoxy(37,1);
			cout<<"MAIN MENU";
			
			if(logCase==2){
			gotoxy(col,3);
			cout<<"[1] Customer Details"<<endl;
			gotoxy(col,4);
			cout<<"[2] Business Sales"<<endl;
			gotoxy(col,5);
			cout<<"[3] Business Expenses"<<endl;
			gotoxy(col,6);
			cout<<"[4] Go Back To Main Menu"<<endl;}
			else if (logCase==1)
			{
			gotoxy(col,4);
			cout<<"[1] Business Sales"<<endl;
			gotoxy(col,5);
			cout<<"[2] Business Expenses"<<endl;
			gotoxy(col,6);
			cout<<"[3] Go Back To Main Menu"<<endl;
			}
			gotoxy(col,8);
			cout<<"Select your Option: ";
			cin>>resp2;
		}while(resp2!=1 && resp2!=2 && resp2!=3 && resp2!=4);
		
		switch(logCase){
			
		case 1:
			if(resp2==2){
			switch(logCase){
			
			case 1:
				busExpRet();
				getch();
				mainMenu();
				break;
			case 2:
			busExp();
			getch();
			mainMenu();
			break;
			}}// if
			else if (resp2==1)
			busSale();

			else if (resp2==3)
			mainMenu();
			break;
		case 2:
			if(resp2==1)
			custdeets();
			else if(resp2==3){
			switch(logCase){
			
			case 1:
				busExpRet();
				getch();
				break;
			case 2:
			busExp();
			getch();
			mainMenu();
			break;
			}}// if
			else if (resp2==2)
			busSale();
			else if (resp2==4)
			mainMenu();
		break;
		}//switch
		}//else
break;

case 'B':
	system("cls");
	switch(logCase){
		case 1: //owner
			do
				{
					gotoxy(col,6);
					cout<<"[A] Payroll Management"<<endl;
					gotoxy(col,7);
					cout<<"[B] Check Salary"<<endl;
					gotoxy(col,9);
					cout<<"Select your Option: ";
					cin>>resp1;
					resp1=toupper(resp1);
				} while (resp1!='A' && resp1!='B');
				
				system("cls");
				
				switch(resp1)
				{
					case  'A': // input of data in payroll
							do
						   	{
						   	 gotoxy(col,5);
							 cout<<"[A] Supervisor"<<endl;
							 gotoxy(col,6);
							 cout<<"[B] Delivery Personnel"<<endl;
							 gotoxy(col,7);
							 cout<<"[C] Filtering Personnel"<<endl;
						 	 gotoxy(col,9);
							 cout<<"Select your Option: ";
							 cin>>resp3;
							 resp3=toupper(resp3);
							} while (resp3!='A' && resp3!='B' && resp3!='C');
							// end of while loop
							
							system("cls");
							
							switch (resp3)
							{
							 case 'A': payroll.open ("sup.txt", ios::out | ios::trunc);
							 		   system("cls");
							 		   gotoxy(10,20);
									   cout<<"Maximum of 120 hours and Minimum of 60 hours";
									   gotoxy(1,5);
									   cout<<"Supervisor"<<endl;
									   getback: 
									   cout<<"Enter Number of Hours Worked: ";
									   cin>>hrs;
									   if(hrs>120 && hrs <60)
									   	goto getback;
									   supsal=(hrs*50);
									   payroll<<supsal<<" "<<hrs<<endl;
									   payroll.close();
									   cout<<endl<<endl<<"Press Any Key to Continue";
									   system("cls");
									   mainMenu();
									   break;
									   // end of case for supervisor
							 case 'B': payroll.open ("dp.txt", ios::out | ios::trunc);
							 		   system("cls");
							 		   cout<<"Delivery Personnel"<<endl;
							 		   cout<<"Enter Number of Gallons Delivered: ";
							 		   cin>>gal;
							 		   dpsal=(gal*3);
							 		   payroll<<dpsal<<" "<<gal<<endl;
							 		   payroll.close();
									   cout<<endl<<endl<<"Press Any Key to Continue";
									   system("cls");
									   mainMenu();
							 		   break;
							 		   // end of case for delivery personnel
							 case 'C': payroll.open ("fil.txt", ios::out | ios::trunc);
							 		   system("cls");
							 		   cout<<"Filtering Personnel"<<endl;
							 		   cout<<"Enter Number of Times Filtered: ";
							 		   cin>>times;
							 		   filsal=(times*45);
							 		   payroll<<filsal<<" "<<times<<endl;
							 		   payroll.close();
									   cout<<endl<<endl<<"Press Any Key to Continue";
									   system("cls");
									   mainMenu();
							 		   break;
							 		   // end of case for filtering personnel
							}
							break;
							
							
					case 'B':  // display output of data in payroll - general payroll 
								system("cls");
								table();
								payroll.open("sup.txt", ios::in);
								payroll>>supsal>>hrs;
								gotoxy(59,7);
								cout<<supsal;
								gotoxy(31,7);
								cout<<hrs;								
								payroll.close();
								payroll.open("dp.txt", ios::in);
								payroll>>dpsal>>gal;
								gotoxy(39,8);
								cout<<gal;
								gotoxy(59,8);
								cout<<dpsal;
								payroll.close();
								payroll.open("fil.txt", ios::in);
								payroll>>filsal>>times;
								gotoxy(49,9);
								cout<<times;
								gotoxy(59,9);
								cout<<filsal;
								payroll.close();
								getch();
								mainMenu();
								break;			
				}
				break; // case 1
	
			case 2: // employee
			
				switch (logCase)
				{
				 case 2: indi();
				 		   payroll.open ("sup.txt", ios::in);
						   gotoxy(34,5);
						   cout<<"POSITION: "<<endl;
					       gotoxy(34,8);
						   cout<<"HOURS:    "<<endl;
						   gotoxy(34,11);
						   cout<<"SALARY:   "<<endl;
				 		   gotoxy(34,6);
						   cout<<"Supervisor";
						   payroll>>supsal>>hrs;
						   gotoxy(34,9);
						   cout<<hrs;						   
						   gotoxy(34,12);
						   cout<<supsal;
						   gotoxy(10,23);						   
						   cout<<endl<<endl<<"Press Any Key to Continue";
						   getch();
						   payroll.close();
						   //system("cls");
						   mainMenu();
						   break;
						   // end of case for supervisor
						
				 		   // end of case for filtering personnel
				}
			break; //CASE 2
			case 3:
				logIn();
				break;
			case 4:
				logIn();
				break;
				
		
	}//switch

	break; //CASE B
case 'C':
	inventoryOP();
	break;
	
case 'D':
logIn();
	break;			
		}//switch resps
	getch();
}



	

main (){



	gotoxy(15,12);
		system("color 8f");
	cout<<"Welcome to Angelique's Water Refilling Station System!!"<<endl;
	getch();
while(1){
	
//	logIn();
	switch(logCase)
	{
		case 1:
			mainMenu();
			break;
			
		case 2: 
			mainMenu();
			break;
			
		case 3:
			mainMenu();
		case 4:
			mainMenu();
		
	}//switch
	

	getch();
}//while
	getch();
	
//	}//while
}//main
