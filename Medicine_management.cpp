#include<fstream>
#include<iostream>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include<dos.h>
#include<stdio.h>
using namespace std;
 
//***************************************
//CLASS CONTAINING ALL THE FUNCTIONS USED
//***************************************
class medicine
{
   char name_med[100],purpose[50],id[10],per_name[20],address[50],ph_number[15],date[10],
   id1[10],name_med1[100],password[100],doctor_name[50],pat_name[50],phno[15],detail[100],med[100],
   ex_date[10];
   float price,amount;
   int stock,age;	
   public:
   	void getdata();
   	void showdata();
   	void getbill();
   	void showbill();
   	
//*********************
//FUNCTION TO RETURN ID
//*********************   	
   	char *getid()
   	{
	 	return id;
	 }
	 
//********************************
//FUNCTION TO RETURN MEDICINE NAME
//********************************	 
   	char *gettype()
   	{
	 	return name_med;
	 }
	 
	 	     
   	void getperson_detail();
   	void showperson_detail();
   	void input_data();
   	void showit();
   	void modify();
   	void search();
   	void delete_records();
   	void per_detail();
   	void add_data();
   	void show_perdetail();
   	void password1();
   	void bill();
   	void show_bill();
   	void per_add();
   	
//***************************
//FUNCTION TO RETUR PASSWORD	  
//***************************
   	char *getpass()
   	 {
	  	 return password;
	  }	 
	  
	  
   	void enter_file();
   	void choose_function();
   	void choice_function();
   	void pushX(int);
   	void front_screen();
};

   	   	
//********************
//DETAILS OF MEDICINE
//********************
    void medicine::getdata()
    {
    fflush(stdin);	
    cout<<"enter the id of the medicine";
    gets(id);
    fflush(stdin);
	cout<<"enter the medicine name";
	gets(name_med);
	cout<<"enter the medicine`s category";
	gets(purpose);
	cout<<"enter the price of medicine";
	cin>>price;
	fflush(stdin);
	cout<<"enter the date of expiry";
	gets(ex_date);
	cout<<"enter the stock left";
	cin>>stock;
    }
	
//****************	   	
//TO SHOW DETAILS
//****************
    void medicine::showdata()
    {
    cout<<"id of the medicine : ";
    puts(id);
    cout<<endl;
    cout<<"name of medicine : ";
    puts(name_med);
    cout<<endl;
    cout<<"medicine`s category : ";
    puts(purpose);
    cout<<endl;
    cout<<"expiry date : ";
    puts(ex_date);
    cout<<endl;
    cout<<"price : "<<price<<endl<<endl;
    cout<<"stock left : "<<stock<<endl<<endl;
    cout<<"==========================================";
    }
    
//****************
//INPUT BILL DATA 
//****************
    void medicine::getbill()
	{
	  cout<<endl<<endl<<endl<<endl;
      cout<<"************************************************GANESH MEDICAL STORE****************************************************"<<endl;
	  cout<<"                                                 Doctor`s name : ";
	  cin>>doctor_name;	
	  fflush(stdin);
	  cout<<"Patient`s name_ _ _ _ _ _ _";
	  fflush(stdin);
	  cin>>pat_name;
	  cout<<"Age_ _ _ _ _ _";
	  cin>>age;
	  cout<<"Phone number_ _ _ _ _ _ _ _";
	  cin>>phno;
	  fflush(stdin);
	  cout<<"-------------------------------------------------Details of the problem-------------------------------------------------"<<endl;
	  gets(detail);
	  cout<<"---------------------------------------------------------Medicine-------------------------------------------------------"<<endl;
	  gets(med);
	} 
	
//**********************
//FUNCTION TO SHOW BILL	
//**********************
   void medicine::showbill()
   {
   	          cout<<endl<<endl;
		   	  cout<<"***************************************************GANESH MEDICAL STORE***************************************************"<<endl;
	          cout<<"                                                    Doctor`s name : "<<doctor_name;
	          cout<<endl<<endl;
	          cout<<"Patient`s name_ _ _ _ _ _ _"<<pat_name<<endl<<endl;
	          cout<<"Age_ _ _ _ _ _"<<age<<endl<<endl;
	          cout<<"Phone number_ _ _ _ _ _ _ _"<<phno<<endl<<endl;
	          cout<<"Details of the problem_ _ _ _ _ _ _ _";
	          puts(detail);
	          cout<<"Medicines priscribed _ _ _ _ _ _ _ _ _ _";
	          puts(med);
	          cout<<endl;
	          cout<<"=========================================================================================================================="<<endl;
	        
   }        
    
//*********************
//GET PERSON`S DETAILS 
//*********************
    void medicine::getperson_detail()
	{
		fflush(stdin);
		cout<<"enter the person`s name";
		gets(per_name);
		cout<<"enter the address";
		gets(address);
		cout<<"enter the phone number";
		gets(ph_number);
		cout<<"enter date of purchasing,id and name of medicine";
		gets(date);
		gets(id1);
		gets(name_med1);
		cout<<"enter the paid amount";
		cin>>amount;
	} 
	
	  
//**********************
//SHOW PERSON`S DETAILS	
//**********************
    void medicine::showperson_detail()
	{
	  	cout<<"name : ";
		puts(per_name);
		cout<<"address : ";
		puts(address);
		cout<<"phone number : ";
		puts(ph_number);
		cout<<"date of purchasing : ";
		puts(date);
		cout<<"id : ";
		puts(id1);
		cout<<"medecine`s name : ";
		puts(name_med1);
		cout<<"amount : ";
		cout<<amount;	
	}
	
//******************
//INPUT OF MEDICINE
//******************
        void medicine::input_data()
		{
			fstream f("stock.dat",ios::out|ios::binary);
			medicine m;
			char ch,ab,op,pu,re,dh;
			system("cls");
			do
			{
				m.getdata();
				cout<<"want to save the records (y/n)"<<endl;
				cin>>ch;
				if(tolower(ch)=='y')
				{
					f.write((char *)&m,sizeof(m));
					cout<<"records saved_ _ _ _ _ _ _ _ "<<endl;
					cout<<"want to enter more records (y/n)"<<endl;
					cin>>re;
				}
			else if(tolower(ch)=='n')
			  {
			  	cout<<"records not saved_ _ _ _ _ _ _ _ "<<endl;
			  	cout<<"do you again want to enter the records(y/n)"<<endl;
			  	cin>>ab;
			    if(tolower(ab)=='y')
			  	      {
			  	      	do
			  	      	{
			  	      	    m.getdata();
				            cout<<"want to save the records (y/n)"<<endl;
				            cin>>op;
				            if(tolower(op)=='y')
				             {
					          f.write((char *)&m,sizeof(m));
					           cout<<"records saved_ _ _ _ _ _ _ _ "<<endl;
							   cout<<"want to enter more records (y/n)"<<endl;
			  	               cin>>pu;	
			  	               fflush(stdin);
							 }
						}while(tolower(pu)=='y');
					    
						break;
				  }	
				  else
				  {
				  	cout<<endl<<endl<<endl;
				  	cout<<"No records entered_ _ _ _ _ _ _ _ _ _ _ _ _"<<endl;
				  }
			   }
		   }while(tolower(re)=='y');
		   f.close();
		   cout<<endl<<endl;
		   cout<<"Do you want to continue (y/n)";
		   cin>>dh;
		   if(tolower(dh)=='y')
		   {
		   	system("cls");
		   	choice_function();
		   }
		      else 
		      {
				cout<<endl<<endl;
		      	cout<<"PRESS ANY KEY TO EXIT............."<<endl;
		      	exit(1);
			  }
	   }
	   
//*************
//SHOW RECORDS
//*************	   
	   void medicine::showit()
	   {
	   	fstream f1("stock.dat",ios::in|ios::binary);
	   	medicine m1;
	   	char dh;
	   	system("cls");
	   	while(f1.read((char *)&m1,sizeof(m1)))
	   	{
	   		m1.showdata();
	   		cout<<endl;
		}
		f1.close();
		cout<<endl<<endl;
		   cout<<"Do you want to continue (y/n)";
		   cin>>dh;
		   if(tolower(dh)=='y')
		   {
		   	system("cls");
		   	choice_function();
		   }
		      else 
		      {
		      	cout<<endl<<endl;
		      	cout<<"PRESS ANY KEY TO EXIT............."<<endl;
		      	exit(1);
			  }
	   }
	   
//******************
//TO MODIFY RECORDS
//******************
        void medicine::modify()
		{
			fstream f2("stock.dat",ios::in|ios::out|ios::binary);
			medicine m2;
			char ids[10],re,ch,dh,name[100];
			system("cls");
			cout<<"do want to modify or not (y/n)";
			cin>>ch;
			if(tolower(ch)=='y')
		   {
			do
			{
				fflush(stdin);
				cout<<"enter the id which you want to modify"<<endl;
				gets(ids);
				while(!f2.eof())
				{
					f2.read((char *)&m2,sizeof(m2));
					if(strcmpi(m2.getid(),ids)==0)
					{
						cout<<"enter the details"<<endl;
						int i=f2.tellg();
						f2.seekg(i-sizeof(m2),ios::beg);
						m2.getdata();
						f2.write((char *)&m2,sizeof(m2));
						break;
					}
				}
				cout<<"want to modify more records (y/n)"<<endl;
				cin>>re;
			}while(tolower(re)=='y');
		}
		else
		{ 
		  cout<<"==================================="<<endl;
		  cout<<"THANK YOU"<<endl;
		  cout<<endl;  
		}
			f2.close();
			cout<<endl<<endl;
		   cout<<"Do you want to continue (y/n)";
		   cin>>dh;
		   if(tolower(dh)=='y')
		   {
		   	system("cls");
		   	choice_function();
		   }
		      else 
		      {
		      	cout<<endl<<endl;
		      	cout<<"PRESS ANY KEY TO EXIT............."<<endl;
		      	exit(1);
			  }
		}
			   
		
//********************************
//TO SEARCH A PARTICULAR MEDICINE
//********************************
    void medicine::search()
	{
		fstream c("type.dat",ios::out|ios::binary);
		medicine m3;
		char medic_name[100],ch,ab,dh;
		system("cls");
		do
		{
			fstream f3("stock.dat",ios::in|ios::binary);
			fflush(stdin);
			cout<<"enter the name of the medicine to be searched"<<endl;
			gets(medic_name);
			while(!f3.eof())
			{
				f3.read((char *)&m3,sizeof(m3));
				if(strcmpi(m3.gettype(),medic_name)==0)
				{
					f3.seekg(0);
					c.write((char *)&m3,sizeof(m3));
					m3.showdata();
					cout<<endl;
					break;
				}
			}
			if(f3.eof())
			{
				f3.seekg(0);
				cout<<"medicine not found"<<endl;
				f3.close();
			}
			cout<<"want to search again (y/n)"<<endl;
			cin>>ch;
		}while(tolower(ch)=='y');
		c.close();
		cout<<endl<<endl;
		   cout<<"Do you want to continue (y/n)";
		   cin>>dh;
		   if(tolower(dh)=='y')
		   {
		   	system("cls");
		   	choice_function();
		   }
		      else 
		      {
		      	cout<<endl<<endl;
		      	cout<<"PRESS ANY KEY TO EXIT............."<<endl;
		      	exit(1);
			  }
	}		
	
//**********************
//TO DELETE ANY DETAIL
//**********************
       void medicine::delete_records()
	   {
	   	  fstream f4("stock.dat",ios::in|ios::binary);
	   	  fstream s("del.dat",ios::out|ios::binary);
	   	  medicine m4;
	   	  char medo_name[100],ch,re,dh;
	   	  system("cls");
	   	  cout<<"do you want to delete any record (y/n)"<<endl;
	   	  cin>>ch;
	   	  if(tolower(ch)=='y')
	   	  {
	   	  	 do
	   	  	 {
	   	  	 	fflush(stdin);
				cout<<"enter the name of medicine which you want to delete"<<endl;
	   	  	 	gets(medo_name);
	   	  	 	while(!f4.eof())
	   	  	 	{
	   	  	 		f4.read((char *)&m4,sizeof(m4));
	   	  	 		if(strcmpi(m4.gettype(),medo_name)!=0)
	   	  	 		s.write((char *)&m4,sizeof(m4));
				}
				f4.close();
				s.close();
				remove("stock.dat");
				rename("del.dat","stock.dat");
				cout<<"want to delete more records (y/n)"<<endl;
				cin>>re;
			 }while(tolower(re)=='y');
		  }
		  else
		  {
		  	cout<<"=============================="<<endl;
		  	cout<<"THANK YOU"<<endl;
		  	cout<<endl;
		  }
		  cout<<endl<<endl;
		   cout<<"Do you want to continue (y/n)";
		   cin>>dh;
		   if(tolower(dh)=='y')
		   {
		   	system("cls");
		   	choice_function();
		   }
		      else 
		      {
		      	cout<<endl<<endl;
		      	cout<<"PRESS ANY KEY TO EXIT............."<<endl;
		      	exit(1);
			  }
	   }
	   
//***********************
//FUNCTION TO ADD RECORD
//***********************
       void medicine::add_data()
	   {
	   	  fstream f5("stock.dat",ios::in|ios::binary|ios::app);
	   	  medicine m5;
	   	  char re,dr,dh;
	   	  system("cls");
	   	  cout<<"do you want to add some new records (y/n)"<<endl;
	   	  cin>>dr;
	   	  if(tolower(dr)=='y')
	   	  {
	   	  	  do
	   	  	  {
	   	  	  	  m5.getdata();
	   	  	  	  f5.write((char *)&m5,sizeof(m5));
	   	  	  	  cout<<"do you want to enter more records (y/n)"<<endl;
	   	  	  	  cin>>re;
			  }while(tolower(re)=='y');
		  }
		  else
		  {
		  	cout<<"=============================="<<endl;
		  	cout<<"THANK YOU"<<endl;
		  	cout<<endl;
		  }
		  f5.close();
		  cout<<endl<<endl;
		   cout<<"Do you want to continue (y/n)";
		   cin>>dh;
		   if(tolower(dh)=='y')
		   {
		   	system("cls");
		   	choice_function();
		   }
		      else 
		      {
		      	cout<<endl<<endl;
		      	cout<<"PRESS ANY KEY TO EXIT............."<<endl;
		      	exit(1);
			  }
	   }	   	
	   
//******************************
//FUNCTION FOR PERSON`S DETAILS	   
//******************************
         void medicine::per_detail()
         {
         	fstream p("perdetail.dat",ios::out|ios::binary);
         	medicine m6;
         	char ch,dh;
         	system("cls");
         	do
         	{
         		cout<<"enter the details of the person"<<endl;
         		m6.getperson_detail();
         		p.write((char *)&m6,sizeof(m6));
         		cout<<"do you want to enter more records (y/n)"<<endl;
         		cin>>ch;
			}while(tolower(ch)=='y');
			p.close();
			cout<<endl<<endl;
		   cout<<"Do you want to continue (y/n)";
		   cin>>dh;
		   if(tolower(dh)=='y')
		   {
		   	system("cls");
		   	choice_function();
		   }
		      else 
		      {
		      	cout<<endl<<endl;
		      	cout<<"PRESS ANY KEY TO EXIT............."<<endl;
		      	exit(1);
			  }
		 }
		 
//************************
//TO SHOW PERSON`S DETAIL
//************************
      void medicine::show_perdetail()
	  {
	  	  fstream p1("perdetail.dat",ios::in|ios::binary);
	  	  medicine m7;
	  	  char dh;
	  	  system("cls");
	  	  while(p1.read((char *)&m7,sizeof(m7)))
	  	  {
	  	  	 cout<<"person`s details are"<<endl;
	  	  	 cout<<"============================================"<<endl;
	  	  	 cout<<endl;
	  	  	 m7.showperson_detail();
	  	  	 cout<<endl;	  	  	 
		  }
		  p1.close();
		  cout<<endl<<endl;
		   cout<<"Do you want to continue (y/n)";
		   cin>>dh;
		   if(tolower(dh)=='y')
		   {
		   	system("cls");
		   	choice_function();
		   }
		      else 
		      {
		      	cout<<endl<<endl;
		      	cout<<"PRESS ANY KEY TO EXIT............."<<endl;
		      	exit(1);
			  }
	  }
	  
//**************************
//TO SET PASSWORD ON SYSTEM
//**************************
      void medicine::password1()
	  {
	     	fstream g("pass.dat",ios::out|ios::binary);
	     	medicine m8;
	     	char ch;
	     	system("cls");
	     	START:
	     		system("cls");
	     	cout<<"enter the password to set.... \n \n(Minimum 6 characters......)"<<endl;
			 int i=0;
			 char a;
			 for(i=0;;)
			 {
			 	a=getch();
			 	if(a=='\r')
				 {
			 		break;
				 }
				 else{
				 	cout<<"*";
					this->password[i] = a;
					i++;
				 }
			  }	
			  if(i<=5)
			  {
			  	cout<<"minimum 6 digits are needed"<<endl;
			  	goto START;
			  }
			  g.write((char *)&m8,sizeof(m8));
			  g.close();
			  enter_file();
		   }

//***********************
//FUNCTION TO CREAT BILL
//***********************
   void medicine::bill()
   {
   	  fstream b("bill.dat",ios::out|ios::binary|ios::app);
   	  medicine mb;
   	  char dh,ch;
   	  system("cls");
   	  do
   	  {
   	  mb.getbill();
   	  b.write((char *)&mb,sizeof(mb));	
	  cout<<endl<<endl<<endl;
	  cout<<"DATA SAVED_ _ _ _ _ _ _ _ _ "<<endl<<endl; 
	  cout<<"want to enter more bills (y/n)"<<endl;
	  cin>>ch;
      }while(tolower(ch)=='y');
      cout<<"=============================="<<endl;
	  cout<<"    THANK YOU   ";
	  b.close();
	  cout<<endl<<endl;
		   cout<<"Do you want to continue (y/n)";
		   cin>>dh;
		   if(tolower(dh)=='y')
		   {
		   	system("cls");
		   	choice_function();
		   }
		      else 
		      {
		      	cout<<endl<<endl;
		      	cout<<"PRESS ANY KEY TO EXIT............."<<endl;
		      	exit(1);
			  }
   }	  
   
//**********************
//FUNCTION TO SHOW BILL
//**********************
         void medicine::show_bill()
		 {
		   fstream b1("bill.dat",ios::in|ios::binary);
		   medicine mj;
		   char dh;
		   system("cls");
		   while(b1.read((char *)&mj,sizeof(mj)))
		   {
		   	   mj.showbill();
		   	   cout<<endl;
		   } 	
		   b1.close();
		   cout<<endl<<endl;
		   cout<<"Do you want to continue (y/n)";
		   cin>>dh;
		   if(tolower(dh)=='y')
		   {
		   	system("cls");
		   	choice_function();
		   }
		      else 
		      {
		      	cout<<endl<<endl;
		      	cout<<"PRESS ANY KEY TO EXIT............."<<endl;
		      	exit(1);
			  }
		 }   	 
	  
//******************************
//TO ADD MORE DETAILS OF PERSON	
//******************************
      void medicine::per_add()
	  {
	  	fstream p6("perdetail.dat",ios::out|ios::app|ios::binary);
	   	  medicine ma;
	   	  char re,dr,dh;
	   	  system("cls");
	   	  cout<<"do you want to add more records of person (y/n)"<<endl;
	   	  cin>>dr;
	   	  if(tolower(dr)=='y')
	   	  {
	   	  	  do
	   	  	  {
	   	  	  	  ma.getperson_detail();
	   	  	  	  p6.write((char *)&ma,sizeof(ma));
	   	  	  	  cout<<"do you want to enter more records (y/n)"<<endl;
	   	  	  	  cin>>re;
			  }while(tolower(re)=='y');
		  }
		  else
		  {
		  	cout<<"==============================="<<endl;
		  	cout<<"THANK YOU"<<endl;
		  	cout<<endl;
		  }
		  p6.close();
		  cout<<endl<<endl;
		   cout<<"Do you want to continue (y/n)";
		   cin>>dh;
		   if(tolower(dh)=='y')
		   {
		   	system("cls");
		   	choice_function();
		   }
		      else 
		      {
		      	cout<<endl<<endl;
		      	cout<<"PRESS ANY KEY TO EXIT............."<<endl;
		      	exit(1);
			  }
	  }  
	  	 
//**********************
//TO ENTER PASSWORD FILE
//**********************
          void medicine::enter_file()
		  {
		  	 system("cls");
			 cout<<endl;
		  	 fstream g2("pass.dat",ios::in|ios::binary);
          	 medicine ml;
         	 char pss1[100];
         	 cout<<"Please re-enter the password to enter the file.........."<<endl;
			 int i=0;
			 char a;
			 for(i=0;;)
			 {
			 	a=getch();
			 	if((a>='a'&&a<='z')||(a>='A'&&a<='Z')||(a>='0'&&a<='9'))
			 	{
			 	   pss1[i]=a;
					++i;
					cout<<"*";
				}
			      if(a=='\r')
			      {
			      	pss1[i]='\0';
			      	break;
				  }
			  }	
			  g2.read((char *)&ml,sizeof(class medicine));
		while(!g2.eof())
		{
         if(strcmp(pss1,getpass())==0)
            {
				front_screen();
			}
			else 
			{
				
				cout<<endl;
				cout<<"entered wrong password"<<endl;
				system("cls");
				enter_file();
			}
       }
       g2.close();
		  }	 
//*******************************
//TO CHOOSE THE DESIRED FUNCTION	 
//*******************************
          void medicine::choose_function()
          {
          	int no;
          	cout<<"enter your choice"<<endl;
          	cin>>no;
          	if(no==1)
          	{
          	  system("color 4");
			  input_data();		
			}
			  else if(no==2)
			  {
			  	system("color 3");
			  	showit();
			  }
			    else if(no==3)
			    {
			    	system("color 2");
			    	modify();
				}
				  else if(no==4)
				  {
				  	system("color 1");
				  	search();
				  }
				     else if(no==5)
				   {
				   	system("color 5");
				   	delete_records();
				   }
				    else if(no==6)
				    {
				    	system("color 6");
				    	add_data();
					}
					  else if(no==7)
					 {
					 	system("color 4");
					 	per_detail();
					 }
					   else if(no==8)
					   {
					   system("color 8");
					   	show_perdetail();
					   }
					   else if(no==9)
					   {
					   system("color 9");
					   	per_add();
					   }
					     else if(no==10)
					     {
					     	 system("color 1");
							 bill();
						 }
						   else if(no==11)
						   {
						   	   system("color A");
							   show_bill();
						   }
				else if(no==12)
				{	
				exit(1);
				}	
		           else
				   {
				      cout<<"wrong input"<<endl;
					  cout<<"enter your choise again between (1-12)"<<endl;
					  cin>>no;
					  
			if(no==1)
          	{
          	  
			  system("color 4");
			  input_data();		
			}
			  else if(no==2)
			  {
			  	system("color 3");
			  	showit();
			  }
			    else if(no==3)
			    {
					system("color 2");
			    	modify();
				}
				  else if(no==4)
				  {
				  	system("color 1");
				  	search();
				  }
				    else if(no==5)
				   {
				   system("color 5");
				   	delete_records();
				   }
				    else if(no==6)
				    {
				    	system("color 6");
				    	add_data();
					}
					 else if(no==7)
					 {
					 system("color 4");
					 	per_detail();
					 }
					 else if(no==8)
					   {
					   system("color 8");
					   	show_perdetail();
					   }
					   else if(no==9)
					   {
					   system("color 9");
					   	per_add();
					   }
			              else if(no==10)
					     {
					     	system("color 1");
					     	bill();
						 }
						   else if(no==11)
						   {
						   	system("color 2"); //system("color f2) for the screen to be with at the 
						   	                      //place of black
						   	show_bill();
						   }
				else if(no==12)
				{	
				exit(1);
				}
				choose_function();	
				   }   
		  }
		  
//****************
//CHOICE FUNCTION
//****************
     void medicine::choice_function()
	 {
	    system("color 0f");
	    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~WELCOME~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	    cout<<endl;
	    cout<<"========================================================CHOICE SCREEN====================================================="<<endl;
	    cout<<endl<<endl;
	    cout<<"# Enter 1 : To enter the stock of medicine"<<endl;
	    cout<<"# Enter 2 : To show the stock of medicine"<<endl;
	    cout<<"# Enter 3 : To modify data"<<endl;
	    cout<<"# Enter 4 : To search any medicine according to its name"<<endl;
	    cout<<"# Enter 5 : To delete any record"<<endl;
	    cout<<"# Enter 6 : To add new record"<<endl;
	    cout<<"# Enter 7 : To enter the person`s detail"<<endl;
	    cout<<"# Enter 8 : To see person`s detail"<<endl;
	    cout<<"# Enter 9 : To add more person`s details"<<endl;
	    cout<<"# Enter 10 : To make the bill"<<endl;
	    cout<<"# Enter 11 : To see the bill"<<endl;
	    cout<<"# Enter 12 : to exit"<<endl;
	    cout<<endl;
	    cout<<"*******************************************************************************"<<endl;
	    cout<<endl;
	    choose_function();
	    }  
		
//*****************
//FUNCTION TO PUSH 
//****************		
			void medicine::pushX(int num)
		  {
            for(int i=0;i<num;i++)
            cout<<" ";
          } 
		
//*************
//FRONT SCREEN
//*************
      void medicine::front_screen()
	  {
         system("color 5f"); 
        for(int j=0;j<50;j++)
		{
        system("CLS");
        pushX(j);
        cout<<"*********Welcome*********"<<endl;
        cout<<endl<<endl<<endl;
        cout<<"##########################################################################################################################"<<endl;
        cout<<endl<<endl<<endl<<endl;
        pushX(j);
        cout<<"  Made by  : "<<"SHAGUN AGRAWAL"<<endl;
        cout<<"                                                            ___________________"<<endl<<endl;
        cout<<"##########################################################################################################################"<<endl;
        cout<<endl<<endl<<endl<<endl;
        Sleep(15);
	   }
	  char ch;
	  cout<<endl<<endl;
	  cout<<"Want to enter_ _ _ _ _ _ _('y/n')"<<endl;
	  cin>>ch;
	  if(tolower(ch)=='y')
	  {
	  	system("cls");
	  	choice_function();
	  }
	   else
	   {
	   	cout<<"TO EXIT PRESS ANY KEY............"<<endl;
	   	exit(1);
	   }
     }
main()
{
	medicine f;
    f.password1();
	getch();
}

