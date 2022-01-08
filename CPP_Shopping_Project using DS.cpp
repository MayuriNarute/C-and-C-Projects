/*			**  CPP PROJECT	 **
			
		** Online Shopping Web Portal **  
		
	** Projected By :- 	
	
				**	1. Prasad Dhobale    9067404012		dhobaleprasad3@gmail.com
				
				**	2. Mayuri Narute     7558232254		mayurinarute2003@gmail.com
	
	** Guided By :-			
								
				Mr.Rahul Ahire Sir
			
			** Linkcode Technologies **
*/
#include <iostream>
#include <fstream>
#include <conio.h>
#include <string.h>
#include <Windows.h>
using namespace std;

class node{     //...Concept of class
	friend class Register;   //...Friend class
	friend class Host;
	friend class Admin;
	char un[15],passwd[15],cus[15],em[30];
	struct node *addr;    //...Structure
	string  m;
}*temp,*start,*curr;

class bill{
	friend class Host;
	char Pname[50];
	int Pprice,B,Pid;
	float gst,fto;
	struct bill *addr1;
}*bi,*temp1,*start1,*curr1,*prev1;

class Host;

class Register{
	//friend class Host;	
	char unm[20];
	
	public:
		int Create(char[],char[],char[],char[],string );
		int display();
		char* getname(){
			strcpy(unm,temp->un);
			cout<<unm;
			return unm;
		}		
};

int Register::Create(char fname[15],char uname[15],char pass[15],char mail[30],string  mn){         //...Scope Resoluton operator
	char nm[30];
	temp=(struct node*)malloc(sizeof(struct node));
	strcpy(temp->un,uname);
	strcpy(temp->passwd,pass);
	strcpy(temp->cus,fname);
	strcpy(temp->em,mail);
	temp->m=mn;
	temp->addr=NULL;
	if(start==NULL)
		start=temp;
	else{
		curr=start;
		while(curr->addr!=NULL){
			curr=curr->addr;
		}
		curr->addr=temp;
	}
	ofstream Cust("Customer.txt", ios::app);		      //....File handling
	Cust<<"\n\n\t\t*******************************************************";
	Cust<<"\n\t\t\tCustomer Name\t:\t"<<temp->cus;
	Cust<<"\n\n\t\t\tE-Mail ID\t:\t"<<temp->em;
	Cust<<"\n\n\t\t\tUsername\t:\t"<<temp->un;
	Cust<<"\n\n\t\t\tPassword\t:\t"<<temp->passwd;
	Cust<<"\n\n\t\t\tMobile Number\t:\t"<<temp->m;
	Cust<<"\n\n\t\t*******************************************************";
	Cust.close();
	
	ofstream Bill("Bill_Details.txt",ios::app);
	strcpy(nm,Register::getname());
	Bill<<"\n------------------------------- WELCOME TO * R A K U T E N * -------------------------------";
	Bill<<"\n\t\t\tCustomer Username : "<<nm;
	Bill<<"\n|______________________________________________________________________________________________________|";
	Bill<<"\n|    												       |\n|	Product ID\tProduct Name\t	Product Price\t G.S.T \t Prod Quantity\t Total Price   |";
	Bill<<"\n|______________________________________________________________________________________________________|";
	Bill.close();
	system("cls");
	
	cout << "\n\n\n\n\n\n\t\t\t\tPlease Wait A Seconds...";
	Sleep (2000);
	cout << "...";
	Sleep (2000);
	cout << "...";
	Sleep (2000);
	cout << "...";
	cout<<"\n\n\n\n\t\t\t\t\t ||  Account Created Successfully ||\n";	
	return 0;
}

int Register::display(){
	if(start==NULL)
		cout<<"\n\n\t\t\t** Sorry !!!Database is Empty.Because We Still Don't Have Any Customer ****";
	else{
		curr=start;
		cout<<"\n\n\t\t\t\t**** Customer Details *****";
		while(curr!=NULL){
			cout<<"\n\n\t\t*******************************************************\n";
			cout<<"\n\t\t\tCustomer Name\t:\t"<<curr->cus;
			cout<<"\n\n\t\t\tE-Mail ID\t:\t"<<curr->em;
			cout<<"\n\n\t\t\tUsername\t:\t"<<curr->un;
			cout<<"\n\n\t\t\tPassword\t:\t"<<curr->passwd;
			cout<<"\n\n\t\t\tMobile Number\t:\t"<<curr->m;
			cout<<"\n\t\t_________________________________________________________";
			curr=curr->addr;
		}
	}	
	return 0;
}

class Host:public Register{     //.....Inheritance
	friend class Admin;		
	private:
		string  mn;
		float g,fto;
		float Total,Ftotal,GST;
		int b,flag,pprice,pid,found,i,ch,r;
		char uname[20],pass[20],pname[20],mail[30],fname[15],cho;
		string nm;
	public:		
		void password(char *ar,int max){    
			int x=0;
			while(1){
				cho=getch();
				if(cho==13){
					ar[x]='\0';
					break;
				}
				if(cho==8&&x!=0){
					cout<<"\b \b";
					if(x<max && x>0)
					x--;
				}
				else if(x<max && cho!=8){
					cout<<"*";
					ar[x]=cho;
					x++;
				}
			}
		}								
		float Bill_Receipt(int);		//Function Declaration
		void Bpass(){
			Bill(ch,pname,pprice,b,g);
		}
		void quantity(){            //Function in function........
			cout<<"\n\tEnter Quantity : ";
			cin>>b;			
			padded(b);
			b=0;
		}
		float Bill_Receipt(){
			float f = 0;
			
			f = display1();			
			cout<<"\n\n\t\t\tYour Total Bill With GST Is : "<<f<<"\n";
			cout<<"\n|______________________________________________________________________________________________________|";
			Host::fto = f;
			return Host::fto;
		}
		void DProduct(int);
		void invalid(){
			cout<<"\n\n\t\t...INVALID CHOICE....";
		}
		int padded(int);		
		int Bill(int,char[],int,int,float);
		float display1();
		
		int Login(char uname[15],char pass[15]){
			int cnt=0;
			int flag=0;
			if(start==NULL)
				cout<<"\n\tDatabase Empty.......";
			else{
				curr=start;
				while(curr!=NULL){
					cnt++;
					flag=0;
					if(strcmp(curr->un,uname)==0){
						if(strcmp(curr->passwd,pass)==0){
							flag=cnt;
							break;
						}
					}
					curr=curr->addr;
				}
			}
			return flag;
		}
		void Tot(){
			float t;
			Bill_Receipt();
		}
		void user(){
			do{
				start1=NULL;
				system ("cls");
				cout<<"\n\t\t\t\t\t                      /*";
				cout<<"\n\t\t\t\t\t\t     ________/";
				cout<<"\n\t\t\t\t\t\t    |   P   /\t";
				cout<<"\n\t\t\t\t\t[ WEBSITE   |   M  /\tWISH ]";
				cout<<"\n\t\t\t\t\t\t    |_____/\t";
				cout<<"\n\t\t\t\t\t\t    *    *";
				cout<<"\n\n\t\t|--------------* WELCOME TO RAKUTEN WEB  PORTAL *---------------|";
				cout<<"\n                |                                                               |";
				cout<<"\n\t\t|\t\t\t1 : Register                            |";
				cout<<"\n\t\t|\t\t\t2 : Login                               |";		
				cout<<"\n\t\t|---------------------------------------------------------------|";	//display  Is Only for Admin......
				cout<<"\n\t\tEnter Your choice : ";
				cin>>ch;
				switch(ch){
					case 1:
						cout<<"\n\tEnter Your Name : ";
						getline(cin,nm);
						getline(cin,nm);
						strcpy(fname,nm.c_str());
						cout<<"\n\tEnter Your Username : ";
						cin>>uname;
						cout<<"\n\tCreate Your Password : ";
						password(pass,8);
						cout<<"\n\n\tEnter Your E-Mail ID : ";
						cin>>mail;
						cout<<"\n\tEnter Your Mobile Number : ";
						cin>>mn;
						Create(fname,uname,pass,mail,mn);
						cout << "\n\n\n\n\n\t\t\t___FOR Log-in ... Press [L]____ : ";
						cin>>cho;
						system("cls");							
						if(cho=='L'||cho=='l')
							goto login;
						else
							invalid();
						break;
					case 2:
						login:
						system("cls");											
						cout<<"\n\n\t\t\t********** Login Page **********\n";
						cout<<"\n\t|---------------------------------------------------------------|";
						cout<<"\n\n\t\tEnter Registered Username : ";
						cin>>uname;
						cout<<"\n\n\t\tEnter Registered Password : ";
						password(pass,8);
						cout<<"\n\t|---------------------------------------------------------------|";
						flag=Login(uname,pass);
						if(flag>0){							
							cout<<"\n\n\n\n\n\t\tLOGGGING IN SUCCESSFULLY !!!!\t";
							Sleep (2000);
							cout << "...";
							Sleep (2000);
							cout << "...";
							Sleep (2000);
							cout << "...";
							do{
								ADD:
								system("cls");
								cout<<"\n\t\t\t```````````````` MAIN CATEGORY `````````````````\n";
								cout<<"\n\t\t\t******** WEL-COME | Mr. / Mrs. : "<<curr->cus<<" **********\n";
								cout<<"\n\t\t|-------------------*O U R     P R O D U C T S*-----------------|";
								cout<<"\n\t\t|\t\t\t*1 - Books				|		\n\t\t|\t\t\t*2 - Electronics	  		|				\n\t\t|\t\t\t*3 - Groceries				|        \n\t\t|\t\t\t*4 - Cosmetics          		|";
								cout<<"\n\t\t|---------------------------------------------------------------|";
								cout<<"\n\n\tEnter the Category In Which You Want To Shopping : ";
								cin>>ch;
								switch(ch){
									case 1:
							    		do{
											system ("cls");
											cout<<"\n\t\t~~~ Books Name With Price ~~~";
											cout<<"\n\n\t|Book.ID  |\t|  Books Name |\t\t|   Book Price |";
											cout<<"\n|---------------------------------------------------------------------------|";
											cout<<"\n\t  101-\t\tThe Winter\t:\t 	200";
											cout<<"\n\t  201-\t\tHonestness\t:\t 	250";
											cout<<"\n\t  301-\t\tBelieve Me\t:\t 	300";
											cout<<"\n\t  401-\t\tThe Sniper\t:\t 	450";
											cout<<"\n\t  501-\t\tI Never..\t:\t 	500";
											cout<<"\n|---------------------------------------------------------------------------|";
											cout<<"\n\n\tEnter Book ID : ";
											cin>>ch;
											switch(ch){
												case 101:													
													strcpy(pname,"The Winter");
						 							pprice=200;
						 							g=4.4;
						 							quantity();						 					
													break;
												case 201:													
													strcpy(pname,"Honestness");
						 							pprice=250;
						 							g=4.7;
													quantity();
													break;
												case 301:													
													strcpy(pname,"Believe Me");
						 							pprice=300;
						 							g=3.4;
						 							quantity();
													break;
												case 401:													
													strcpy(pname,"The Sniper");
						 							pprice=450;
						 							g=3.8;
						 							quantity();
													break;
												case 501:
													strcpy(pname,"I Never...");
						 							pprice=500;
						 							g=2.9;
						 							quantity();
													break;	
												default:
													invalid();
											}
											Bill_Receipt();       //..Function call
											cout<<"\n\tIf You Want to Purchase More Books.. Press [B] : ";
											cin>>cho;
										}while(cho=='B'||cho=='b');
										break;	
									case 2: 								
										do{
											system("cls");
											cout<<"\n\t\t\t**** ~~~ Electronics ~~~ ****\n";
											cout<<"\n\t|----------------------------------------------------------------|";
											cout<<"\n\t\t\t| 1 - Home Appliances\n\t\t\t| 2 - Laptops\n\t\t\t| 3 - Mobiles";										
											cout<<"\n\t|----------------------------------------------------------------|";
											cout<<"\n\n\t\tEnter Your Choice : ";
											cin>>ch;
											switch(ch){
												case 1:
													do{
														system("cls");
														cout<<"\n\t\t\t\t ~~~ Home Appliances with Prices~~~\n";
														cout<<"\n\t\t| Product.ID  |\t	| Product Name |\t\t|  Price |";
														cout<<"\n\t|-----------------------------------------------------------------------------|";
														cout<<"\n\t\t 142 -\t\t\tRecorders\t\t:\t750";
														cout<<"\n\t\t 143 -\t\t\tConditioner\t\t:\t20,000";
														cout<<"\n\t\t 144 -\t\t\tDVD Players\t\t:\t1500";
														cout<<"\n\t\t 145 -\t\t\tMP3 Players\t\t:\t780";
														cout<<"\n\t\t 146 -\t\t\tRefrigerator\t\t:\t30,000";
														cout<<"\n\t\t 147 -\t\t\tSound System\t\t:\t15,000";
														cout<<"\n\t|-----------------------------------------------------------------------------|";	
														cout<<"\n\n\tEnter Product ID : ";
														cin>>ch;
														switch(ch){
															case 142:
																strcpy(pname,"Recorders");
							 									pprice=750;
							 									g=2.3;
																quantity();
																break;
															case 143:
																strcpy(pname,"Conditioners");
							 									pprice=20000;
								 								g=4.1;
								 								quantity();
																break;
															case 144:																
																strcpy(pname,"DVD Players");
								 								pprice=1500;
								 								g=5.3;
																quantity();
																break;
															case 145:
																strcpy(pname,"MP3 Players");
								 								pprice=780;
								 								g=4.5;
								 								quantity();
																break;
															case 146:																
																strcpy(pname,"Refrigerators");
							 									pprice=30000;
								 								g=3.7;
																quantity();
																break;
															case 147:																
																strcpy(pname,"Sound System");
								 								pprice=500;
								 								g=4.2;						
																quantity();
																break;
															default:
																invalid();
														}
														Bill_Receipt();       //..Function call
														cout<<"\n\tIf You Want to Purchase More  Home Appliances.. Press [H] : ";
														cin>>cho;
													}while(cho=='h'||cho=='H');
													break;
												case 2:
													do{	
														system("cls");		
														cout<<"\n\t\t\t\t ~~~ Laptops with price ~~~\t";
														cout<<"\n\n\t| Item.ID  |\t\t | Item Name |\t\t\t| Price |";
														cout<<"\n\t|-----------------------------------------------------------------------|";
														cout<<"\n\t  620    - 	\t Lenovo V130\t\t:\t40,000";
														cout<<"\n\t  621    - 	\t DELL-XPS\t\t:\t50,000";
														cout<<"\n\t  622    - 	\t SONY VAIO\t\t:\t45,000";
														cout<<"\n\t  623    - 	\t Apple Macbook\t\t:\t75,000";
														cout<<"\n\t  624    - 	\t Acer SlimNOTE\t\t:\t54,000";
														cout<<"\n\t  625    - 	\t HP Pavillion\t\t:\t35,000";
														cout<<"\n\t|-----------------------------------------------------------------------|";
														cout<<"\n\n\tEnter Item ID : ";
														cin>>ch;
														switch(ch){
															case 620:																
																strcpy(pname,"Lenovo	");
								 								pprice=40000;
								 								g=5.5;
								 								quantity();
																break;
															case 621:																
																strcpy(pname,"DELL-XPS");
									 							pprice=50000;
									 							g=6.6;
									 							quantity();
																break;
															case 622:
																strcpy(pname,"SONY VAIO");
								 								pprice=45000;
								 								g=7.3;
								 								quantity();
																break;
															case 623:																
																strcpy(pname,"Apple Macbook");
									 							pprice=75000;
									 							g=7.7;
									 							quantity();
																break;
															case 624:																
																strcpy(pname,"Acer SlimNote");
								 								pprice=54000;
								 								g=5.8;
																quantity();
																break;
															case 625:																
																strcpy(pname,"HP Pavillion");
									 							pprice=35000;
									 							g=6.2;
									 							quantity();
																break;
															default:
																invalid();
														}
														Bill_Receipt();       //..Function call
														cout<<"\n\tIf You Want to Purchase More Laptops.. Press [L] : ";
														cin>>cho;
													}while(cho=='l'||cho=='L');
													break;
												case 3:
													do{
														system("cls");
														cout<<"\n\t\t ~~~~~ Brand Name With Price ~~~~~\n";
														cout<<"\n\t  | Mobile ID |\t	| Mobile Name |\t\t	| Mobile Price |";
														cout<<"\n\t|-----------------------------------------------------------------------------|";
														cout<<"\n\t	411\t\tSamsang Galaxy S10\t:\t	70000";
														cout<<"\n\t	412\t\tRedmi Note 9\t	:\t	20000";
														cout<<"\n\t	413\t\tVivo Y70 Pro\t	:\t	25000";
														cout<<"\n\t	414\t\tOppo A7\t\t	:\t	10000";
														cout<<"\n\t	415\t\tApple F11 Pro\t	:\t	99000";
														cout<<"\n\t|-----------------------------------------------------------------------------|";
														cout<<"\n\tEnter Mobile ID : ";
														cin>>ch;
														switch(ch){
															case 411:																
																strcpy(pname,"Samsang S10");
									 							pprice=70000;
									 							g=9.5;
									 							quantity();
																break;
															case 412:																
																strcpy(pname,"Redmi Note 9");
									 							pprice=20000;
									 							g=7.2;
									 							quantity();
																break;
															case 413:																
																strcpy(pname,"Vivo Y70 Pro");
									 							pprice=25000;
									 							g=8.3;
									 							quantity();
																break;
															case 414:																
																strcpy(pname,"Oppo A7 ");
									 							pprice=10000;
									 							g=6.9;
									 							quantity();
																break;
															case 415:																
																strcpy(pname,"Apple F11 Pro");
									 							pprice=99000;
									 							g=9.3;
									 							quantity();
																break;
															default:
																invalid();
														}
														Bill_Receipt();       //..Function call
														cout<<"\n\tIf You Want To Purchase More Mobile.... Press [M] : ";
														cin>>cho;
													}while(cho=='m'||cho=='M');
													break;
												default:
													invalid();
											}											
											cout<<"\n\n\tIf You Want To Purchase More Electronics Equipments Press [E] : ";
											cin>>cho;
										}while(cho=='e'||cho=='E');
										break;
									case 3:
										do{
											system("cls");	
											cout<<"\n\t\t\t ~~~~~~~ Grocery items with price ~~~~~~\n";
											cout<<"\n\t\t| Item.ID  |\t\t| Item Name |\t\t| Price |";
											cout<<"\n\t|-----------------------------------------------------------------------|";
											cout<<"\n\t\t 132 -\t\t\t Kechup\t\t :\t  80";
											cout<<"\n\t\t 133 -\t\t\t Bread\t\t : \t  70";
											cout<<"\n\t\t 134 -\t\t\t Cheese\t\t :\t  90";
											cout<<"\n\t\t 135 -\t\t\t Milk\t\t :\t  75";
											cout<<"\n\t\t 136 -\t\t\t Rice\t\t : \t  65";
											cout<<"\n\t|-----------------------------------------------------------------------|";
											cout<<"\n\n\tEnter Item ID :  ";
											cin>>ch;
											switch(ch){
												case 132:													
													strcpy(pname,"Kechup	");
													pprice=80;
													g=2.3;
													quantity();
													break;														
												case 133:
													strcpy(pname,"Bread	");
													pprice=70;
													g=3.3;
													quantity();
													break;
												case 134:
													strcpy(pname,"Cheese	");
													pprice=90;
													g=2.7;
													quantity();
													break;
												case 135:
													strcpy(pname,"Milk	");
													pprice=75;
													g=2.9;
													quantity();
													break;
												case 136:													
													strcpy(pname,"Rice	");
													pprice=65;
													g=2.5;
													quantity();
													break;											
												default :
													invalid();
											}
											Bill_Receipt();       //..Function call
											cout<<"\n\tIf You Want To Purchase More Grocery..Press [G] : ";
											cin>>cho;
										}while(cho=='G'||cho=='g');
										break;
									case 4:
										do{
											system("cls");
												cout<<"\n\t\t\t ~~~~~ COSMETICS ~~~~~ \t";
												cout<<"\n\t|---------------------------------------------------|";
												cout<<"\n\t\t 1 - Body Lotions";
												cout<<"\n\t\t 2 - Face Creams";
												cout<<"\n\t\t 3 - Hair Oils";
												cout<<"\n\t|---------------------------------------------------|";
												cout<<"\n\t\tEnter Your Choice  : ";
												cin>>ch;
												switch(ch){
													case 1:
														do{
															system("cls");
															cout<<"\n\t\t\t ~~~~~~~ Body Lotions With prices ~~~~~~~ \n";
															cout<<"\n\t\t| Item.ID  |\t\t| Item Name |\t\t| Price |";
															cout<<"\n\t|------------------------------------------------------------------|";
															cout<<"\n\t\t 701 -\t\t\t NIVEA\t\t :\t  80";
															cout<<"\n\t\t 702 -\t\t\t SANTOOR\t :\t  70";
															cout<<"\n\t\t 703 -\t\t\t PONDS\t\t :\t  100";
															cout<<"\n\t\t 704 -\t\t\t BORO PLUS\t :\t  120";
															cout<<"\n\t\t 705 -\t\t\t VASALINE\t :\t  90";
															cout<<"\n\t|------------------------------------------------------------------|";
															cout<<"\n\n\tEnter Item ID : ";
															cin>>ch;
															switch(ch){
																	case 701:																		
																		strcpy(pname,"NIVEA   ");
																		pprice=80;
																		g=2.4;
																		quantity();
																		break;
																	case 702:
																		strcpy(pname,"SANTOOR   ");
																		pprice=70;
																		g=2.8;
																		quantity();
																		break;
																	case 703:
																		strcpy(pname,"PONDS   ");
																		pprice=100;
																		g=1.7;
																		quantity();
																		break;
																	case 704:
																		strcpy(pname,"BORO PLUS");
																		pprice=120;
																		g=1.7;
																		quantity();
																		break;
																	case 705:																		
																		strcpy(pname,"VASALINE  ");
																		pprice=90;
																		g=1.9;
																		quantity();
																		break;
																	default:
																		invalid();
															}
															Bill_Receipt();       //..Function call
															cout<<"\n\n\t\tTo Shoppping More In Body Lotions Category Press [B] : ";
															cin>>cho;
														}while(cho=='b'||cho=='B');
														break;
													case 2:
														do{
															system("cls");				
															cout<<"\n\t\t\t ~~~~~~~ Face Creams With Prices ~~~~~~~ \n";
															cout<<"\n\t\t| Item.ID  |\t\t| Item Name |\t\t  | Price |";
															cout<<"\n\t|---------------------------------------------------------------------|";
															cout<<"\n\t\t 601 -\t\t\t FAIR & LOVELY\t\t :\t80";
															cout<<"\n\t\t 602 -\t\t\tPATANJALI CREAM\t :\t70";
															cout<<"\n\t\t 603 -\t\t\t LAKME CREAM\t\t :\t130";
															cout<<"\n\t\t 604 -\t\t\t HIMALAYA CREAM\t\t :\t127";
															cout<<"\n\t\t 605 -\t\t\t COCO SUNS\t\t :\t60";
															cout<<"\n\t|---------------------------------------------------------------------|";
															cout<<"\n\n\tEnter Item ID : ";
															cin>>ch;
															switch(ch){
																case 601:
																		strcpy(pname,"FAIR & LOVELY");
																		pprice=80;
																		g=3.9;
																		quantity();
																		break;
																case 602:
																		strcpy(pname,"PATANJALI CREAM");
																		pprice=70;
																		g=2.3;
																		quantity();
																		break;
																case 603:
																		strcpy(pname,"LAKME CREAM");
																		pprice=130;
																		g=1.4;
																		quantity();
																		break;
																case 604:
																		strcpy(pname,"HIMALAYA CREAM");
																		pprice=127;
																		g=3.1;
																		quantity();
																		break;
																case 605:
																		strcpy(pname,"COCO CREAM");
																		pprice=60;
																		g=4.2;
																		quantity();
																		break;
																default:
																	invalid();
															}
															Bill_Receipt();       //..Function call
															cout<<"\n\n\t\tTo Shoppping More In Face Creams Category Press [F] : ";
															cin>>cho;
														}while(cho=='f'||cho=='F');
														break;
													case 3:
														do{
															system("cls");
															cout<<"\n\t\t\t ~~~~~~~ Hair Oils With prices ~~~~~~~ \n";
															cout<<"\n\t\t| Item.ID  |\t\t| Item Name |\t\t  | Price |";
															cout<<"\n\t|---------------------------------------------------------------------|";
															cout<<"\n\t\t 801 -\t\t\t PARACHUTE NARIAL\t:\t89";
															cout<<"\n\t\t 802 -\t\t\t BADAM OIL\t 	:\t75";
															cout<<"\n\t\t 803 -\t\t\t JASMINE OIL\t	:\t135";
															cout<<"\n\t\t 804 -\t\t\t 7HERBS OIL\t	:\t120";
															cout<<"\n\t\t 805 -\t\t\t ALMOND OIL\t	:\t65";
															cout<<"\n\t|---------------------------------------------------------------------|";
															cout<<"\n\n\tEnter Item ID : ";
															cin>>ch;
															switch(ch){
																case 801:
																	strcpy(pname,"PARACHUTE OIL");
																	pprice=89;
																	g=2.2;
																	quantity();
																	break;
																case 802:
																	strcpy(pname,"BADAM OIL");
																	pprice=75;
																	g=3.2;
																	quantity();
																	break;
																case 803:
																	strcpy(pname,"JASMINE OIL");
																	pprice=135;
																	g=4.2;
																	quantity();
																	break;
																case 804:
																	strcpy(pname,"7HERBS OIL");
																	pprice=120;
																	g=4.5;
																	quantity();
																	break;
																case 805:
																	strcpy(pname,"ALMOND OIL");
																	pprice=65;
																	g=5.1;
																	quantity();
																	break;
																default:
																	invalid();
															}
															Bill_Receipt();       //..Function call
															cout<<"\n\t\tTo Shopping More In Hair Oils Category Press [H] : ";
															cin>>cho;
														}while(cho=='h'||cho=='H');
														break;
													default:
														invalid();
												}
										cout<<"\n\n\t\tTO SHOPPING MORE IN COSMETICS CATEGORY Press [C] : ";
										cin>>cho;				
										}while(cho=='C'||cho=='c');
										break;
									default:
										invalid();
								}
								do{									
									cout<<"\n\t|-----------------------------------------------|";								
									cout<<"\n\t|\t1 - Purchase More Products\t\t|";
									cout<<"\n\t|\t2 - Cancel Product\t\t\t|";
									cout<<"\n\t|\t3 - Log Out From Portal\t\t\t|";
									cout<<"\n\t|\t\t\t\t\t\t|";
									cout<<"\n\t| Any key - Continue To Bill\t\t\t|";
									cout<<"\n\t|-----------------------------------------------|";
									cout<<"\n\n\t\t\tEnter Your Choice : ";
									cin>>ch;
									switch(ch){
										case 1:
											system("cls");
											goto ADD;
											break;										
										case 2:											
											int ID;
											cout<<"\n\t\tEnter Product ID  To Cancel Product : ";
											cin>>ID;
											DProduct(ID);
											break;
										case 3:
											goto log;
										default:
											system("cls");
											goto BILL;
									}
									cout<<"\n\n\t\tIf You Want to Continue Press [S] : ";
									cin>>cho;
								}while(cho=='s'||cho=='S');								
								BILL:
									Bill_Receipt(r);																
								ofstream Bill("Bill_Details.txt",ios::app);
								float f = 0;
								f = display1();
								cout<<"\n\t\t\tCustomer UserName : ";
								strcpy(uname,Register::getname());								
								cout<<"\n|______________________________________________________________________________________________________|";
								cout<<"\n\n\t\t\t\t\t\t\t\t\t| Final Bill  | :  "<<f;
								Bill<<"\n\n\t\t\t\t\t\t\t\t\t| Final Bill  | :  "<<f;		
								Bill<<"\n|______________________________________________________________________________________________________|";
								Bill.close();
								ofstream FBill("Final_Bill.txt",ios::app);								
								FBill<<"\n\t\t\tCustomer UserName : "<<uname;
								FBill<<"\n\n\t\t\t| Final Bill  | :  "<<f;
								FBill<<"\n|______________________________________________________________________________________________________|";
								FBill.close();
								cout<<"\n\n\n\n\n\n\t\t\tIf You Want to Stay Log-In ...Press [L] : ";
								cin>>cho;
							}while(cho=='l'||cho=='L');
							if(cho!='y'||cho!='Y'){
								log:
									
									cout<<"\n\n\t\t\t***** Logging Out Successfully....!!!!! *****";
									Sleep (2000);
									cout <<"...";
									cout<<"\n\n\n\t\t\t====== ** T H A N K     Y O U , V I S I T    A G A I N **======";
							}																
						}
						else
							cout<<"\n\n\t\t\t** ..OOPS! SEEMS LIKE YOUR USERNAME OR PASSWORD IS WRONG !... **";
						break;
					default:
							invalid();
				}							
			cout<<"\n\n\t\t To Go Back In Our Register/Login Page.... Press R : ";
			cin>>cho;
			}while(cho=='R'||cho=='r');
			start1=NULL;
		}		
};
int Host::Bill(int ch,char pname[10],int pprice,int qty,float g){	
		bi=(struct bill*)malloc(sizeof(struct bill));
		bi->Pid=ch;
		strcpy(bi->Pname,pname);
		bi->Pprice=pprice;
		bi->B=qty;
		bi->gst=g;
		bi->addr1=NULL;
		if(start1==NULL)
			start1=bi;
		else{
			curr1=start1;
			while(curr1->addr1!=NULL){
				curr1=curr1->addr1;
			}
			curr1->addr1=bi;
		}
		curr1 = start1;
		ofstream Prod("Bill_Details.txt",ios::app);
		//while(curr1!=NULL)
		{
			GST=(bi->gst/100)*bi->Pprice;
			Total=(float)bi->Pprice * bi->B+GST;
			Ftotal=(float)Ftotal+Total;	
			
			Prod<<"\n|\t"<<bi->Pid<<"\t\t"<<bi->Pname<<"\t\t"<<bi->Pprice<<"\t\t "<<bi->gst<<" %\t  "<<bi->B<<"\t\t  "<<Total<<"\t";
			curr1=curr1->addr1;
		}
		Prod<<"\n|______________________________________________________________________________________________________|";
};
void Host::DProduct(int ID){
	curr1=start1;
	float flag = 0,cnt = 0;
	prev1=NULL;
	while(curr1!=NULL){
		cnt++;
		if(curr1->Pid==ID){
			flag = cnt;
			cout<<"\n\n\t\tDeleted Product Details : "<<endl;
			cout<<"\n|______________________________________________________________________________________________________|";
			cout<<"\n|    												       |\n|	Product ID\tProduct Name\t	Product Price\t G.S.T \t Prod Quantity\t\t\t   |";
			cout<<"\n|______________________________________________________________________________________________________|";
			cout<<"\n|\t"<<curr1->Pid<<"\t\t"<<curr1->Pname<<"\t\t"<<curr1->Pprice<<"\t\t "<<curr1->gst<<" %\t  "<<curr1->B;
			prev1->addr1=curr1->addr1;
			free(curr1);
		}
		prev1=curr1;
		curr1=curr1->addr1;
	}
	if(flag==0){
		cout<<"\n\n\t\t\tProduct Not Found...";
	}
	flag = 0;
};
float Host::Bill_Receipt(int){             //Function- Body .........
	Register r;
	Host u; 
	//r.length();         //Object of class User......
	float ft=0;
	Total=0,Ftotal=0,GST=0;	
	system("cls");
	if(start1==NULL)
		cout<<"\n\n\n\t\t\t*** Product Not Added Yet .... ***";
	else{
		cout<<"\n\t\t\t\t  __________________________";
		cout<<"\n\n\t\t\t*****************|| WEBSITE WISH ||******************";
		cout<<"\n\t\t\t\t  __________________________";
		cout<<"\n\t\tNew Agriculture College Building ,Shivaji Nagar Ascent Mall, \n\t\t  	University Road Opp,Pune, Maharashtra-411007\t";
		cout<<"\n\n\t\t\t** Customer Name | Mr. / Mrs. :- "<<curr->cus<<" **";		
		//cout<<"\n\n\n\t-----------------------------------------------------------------------------------";		
		//cout<<"\n\t\t*NOTE*    : You Will Lost Your Shopping Data If You Logged Out  ";
		//cout<<"\n\t-----------------------------------------------------------------------------------";
	}	
	return 0;
};

float Host::display1(){
	Total=0,Ftotal=0,GST=0;	
	if(start1==NULL)
		cout<<"\n\n\n\t\t\t*** Product Not Added Yet .... ***";
	else{						
		curr1=start1;
		cout<<"\n|______________________________________________________________________________________________________|";
		cout<<"\n|    												       |\n|	Product ID\tProduct Name\t	Product Price\t G.S.T \t Prod Quantity\t Total Price   |";
		cout<<"\n|______________________________________________________________________________________________________|";
		while(curr1!=NULL){						
				GST=(curr1->gst/100)*curr1->Pprice;
				Total=(float)curr1->Pprice * curr1->B+GST;
				Ftotal=(float)Ftotal+Total;
				cout<<"\n|\t"<<curr1->Pid<<"\t\t"<<curr1->Pname<<"\t\t"<<curr1->Pprice<<"\t\t "<<curr1->gst<<" %\t  "<<curr1->B<<"\t\t  "<<Total<<"\t";
				curr1=curr1->addr1;
		}
		cout<<"\n|______________________________________________________________________________________________________|";
	}	
	return Ftotal;
};
int Host::padded(int b){
	Host u;
	float ftp = 0;	
	if(b>=1&&b<=100){
		Bpass();
		cout<<"\n\t\t..Product Adding To Cart Successfully !!!!\t";
		Sleep (2000);
		cout << "...";
		Sleep (2000);
		cout << "...";
		Sleep (2000);
		cout << "...";
		system("cls");
	}				
	else{
		cout<<"\n\n\t\tSorry..We Can't Add To Cart...Kindly Try Again.\n\n";
	}
	b=0;
};
class Admin:public Register{
	Register r;
	Host U;
	private:
		char uname[20],pass[10],sn[20],cho;
		int found,ch,cnt,flag;
		float f;
	public:
		Admin(){}           //....Default Constructor
		Admin(char uname[],char pass[]){           //.....Parametric construtor
			strcpy(this->uname,uname);
			strcpy(this->pass,pass);
			found=0;
			if(strcmp(this->uname,"PraMayu")== 0&&strcmp(this->pass,"PraMay")==0){
				found=1;
			}
			else{
				cout<<"\n\t\t**** Incorrect Username Or Password For Admin****";
			}
			if(found==1){
				do{
					system("cls");
					cout<<"\n\t\t\t*********** WELCOME # A D M I N ***********";
					cout<<"\n\t\t_________________________________________________________";
					cout<<"\n\n\t\t\t1 : User Details\n\n\t\t\t2 : Search User\n\n\t\t\t3 : Bill Status";
					cout<<"\n\t\t_________________________________________________________";
					cout<<"\n\n\t\tEnter your Choice : ";
					cin>>ch;
					if(ch==1){
							Register::display();
					}
						
					else if(ch==2){
							flag=Search();
							if(flag>0){									
									cout<<"\n\n\t\t*******************************************************\n";
									cout<<"\n\t\t\tCustomer Name\t:\t"<<curr->cus;			
									cout<<"\n\n\t\t\tE-Mail ID\t:\t"<<curr->em;
									cout<<"\n\n\t\t\tUsername\t:\t"<<curr->un;
									cout<<"\n\n\t\t\tPassword\t:\t"<<curr->passwd;
									cout<<"\n\n\t\t\tMobile Number\t:\t"<<curr->m;
									cout<<"\n\t\t_________________________________________________________";
									curr=curr->addr;
							}
							else{
								cout<<"\n\n\t\t\tSorry...Customer Not Found..";
							}		
					}
					else if(ch==3){
						char Frno;
						ifstream Stud;
						Stud.open("Final_Bill.txt");
						while(Stud){
							Stud.get(Frno);
							cout<<Frno;
						}  	
						Stud.close();
					}																
					else{
						cout<<"\n\n\t\t.......Invalid Choice........";					
					}						
					cout<<"\n\n\t\t\tIf You Want To Continue to Admin Press [A] : ";
					cin>>cho;
				}while(cho=='a'||cho=='A');
			}
		}
		int Search(){
			cout<<"\n\t\tEnter Username Of Customer To Search : ";
			cin>>sn;
			cnt=0;
			flag=0;
			if(start==NULL)
				cout<<"\n\n\t\t\tDatabase Empty.......";
			else{
				curr=start;
				while(curr!=NULL){
					cnt++;
					flag=0;
					if(strcmp(curr->un,sn)==0){
							flag=cnt;
							break;
					}
					curr=curr->addr;
				}
			}
			return flag;
		}	
		~Admin(){}    //.....Destructor
};

int main(){
	
	Register r;
	Host U;
	int c,found=0;
	char ch,ch1,uname[20],pass[10];
	do{
		try{           					//...Exception Handling
			cout<<"\n\n\n\n\n\n\t\t\t\t\tWelcome.....To WEBSITE WISH..!!!!";
			cout<<"\n\n\t\t\t\t\t|| Linkcode Technologies ||";									
			cout<<"\n\n\n\n\n\t\t** Online Shopping Web Portal **";
			cout<<"\n\n\n\t\t| Project By :-";			
			cout<<"\n\n\t\t\t| 1. Prasad Dhobale    9067404012		dhobaleprasad3@gmail.com\t|";
			cout<<"\n\n\t\t\t| 2. Mayuri Narute     7558232254		mayurinarute2003@gmail.com\t|";
			cout<<"\n\n\n\t\t| Guided By :-";
			cout<<"\n\n\t\t\t|Mr.Rahul Ahire Sir";
			
			Sleep(5000);
			
			system("cls");			
			cout<<"\n\n\t\t\t\t\t\t   --HOME PAGE--\n";
			cout<<"\n\t\t\t\t\t	--{{ WEBSITE WISH }}--\t";
			cout<<"\n\t**_______________________________________________________________________________________________**";
			cout<<"\n\n\t\t	New Agriculture College Building ,Shivaji Nagar Ascent Mall, \n\t\t  		University Road Opp,Pune, Maharashtra-411007\t";
			cout<<"\n\t**_______________________________________________________________________________________________**";
			cout<<"\n\n\t\t	     _________\t\t\t	     	     ________";
			cout<<"\n\t\t\t1 -  [ Admin ]	\t\t\t	2 -  [ User ] ";
			cout<<"\n\t\t\t     ---------				     	     --------";
			cout<<"\n\n\t\t\t\t\t\tEnter Your Role : ";
			cin>>c;
			switch(c){
				case 1:
					found=0;				
					cout<<"\n\tEnter Username For Admin : ";
					cin>>uname;
					cout<<"\n\tEnter Password For Admin : ";
					U.password(pass,6);
					Admin(uname,pass);		//.....Constructor Call
					break;
				case 2:
						U.user();
				break;
				default:	
					throw 1;
			}
		}
		catch(int n){
			cout<<"\n\n\t\t\t**** Invalid Choice ****";
		}
		cout<<"\n\n\n\t\t\tDo You Want to Continue To Admin / User Page... Press [P] : ";		
		cin>>ch;
		system("cls");
	}while(ch=='P'||ch=='p');
	return 0;
}
