#include <fstream>
#include <iostream>
#include <cstdlib>
#include <windows.h> 
#include <cstdio>
#include <cstring>
#include <istream>
#include <conio.h>
#include <cctype>
char * m[] = { "   Functions", "  Description", "About of program", "      Exit" }; 
char *mode[] = { "   Create base",  "   Change book","   Delete base", "   Delete book","    Add book", "      Find","      View" }; 
using namespace std;

struct books{
	string name;
	string surname_of_author;
	string name_of_author;
	int year;
	int proc=0;
};

char * prov(char * );
void create_base();
void add_in_base();
void find_in_base();
void delete_in_base();
void delete_base();
double vhod(string, char *);
void change();
double slep(books*,char *);
books * sort(books *,int );
void print_list(books *,int );
int size_base();
int file_empty();
void method(); 
void instruction();
void about();  
void draw_menu(HANDLE , COORD , int , int , int , COORD , char *, char *[]); 
void view();
string tolow(string );
char * tol(char *);
void draw_ram(HANDLE,COORD ,int,int);
void draw_line(HANDLE,int);


main(){
	COORD source = {40, 10}, current = source, u = {40, 6}; 
	BOOL WINAPI GetWindowRect (_In_ HWND hWnd,_Out_ LPRECT lpRect);
	
	int n = 4, k = n - 1, fl = 1; 
	int len = 5; 
	char ch = 10, *menu =" Base of books"; 
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(h,&structCursorInfo);
	structCursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo( h, &structCursorInfo );
	SMALL_RECT z;
       BOOL b ;
       z.Left=1;
       z.Top=1;
       z.Right=140;
       z.Bottom=70;       
       b = SetConsoleWindowInfo(h, TRUE, &z); 
       COORD bufferSize={100,50}; 
	   SetConsoleScreenBufferSize(h, bufferSize);
	   COORD y = u;
	   y.X-=4;
	   y.Y+=2;
       SetConsoleTitle  ("My base of books");
	draw_menu(h, current, n - 1, n, len, u, menu, m); 
	draw_ram(h,y,23,19);
	SetConsoleTextAttribute(h, 000);
	while (fl) 
	{ 
		if (_kbhit()) 
		{ 
			ch = _getch(); 
			switch (ch) 
			{	 
				case 27: 
				{ 
					fl = 0; 
					cout << "\n"; 
					break; 
				} 
				case 13:
				{
					switch (k) 
					{ 
						case 0: 
						{ 
							method(); 	
							break; 
						} 
						case 1: 
						{ 
							instruction();
							system("PAUSE");
 							break; 
						} 
						case 2: 
						{ 
							about(); 
							system("pause"); 
							break; 
						} 
						case 3: 
						{ 
							fl = 0; 
							cout << "\n"; 
							break; 
						} 
						draw_menu(h, current, k, n, len, u, menu, m); 
						draw_ram(h,y,23,19);
						SetConsoleTextAttribute(h, 000);
						break; 
					} 
				} 
				case 80: 
				{ 
					if (k == n - 1)
					{
						k = 0;
					}else
					{
						k++; 
					} 
					draw_menu(h, current, k, n, len, u, menu, m); 
					draw_ram(h,y,23,19);
					SetConsoleTextAttribute(h,000);
					break; 
				} 
				case 72: 
				{ 
					if (k == 0) 
					{
						k = n - 1;
					}
					else 
					{ 
						k--; 
					} 
					draw_menu(h, current, k, n, len, u, menu, m); 
					draw_ram(h,y,23,19);
					SetConsoleTextAttribute(h,000);
					break; 
				} 
			} 
		} 
	}
	SetConsoleTextAttribute(h,000);
	for(int a =0;a<30;a++)
		cout<<endl; 
	return 0; 	
}


void draw_line(HANDLE h,int a){
	SetConsoleTextAttribute(h, BACKGROUND_BLUE | BACKGROUND_GREEN );
	for(int i=0;i<a;i++)
		cout<<endl;
	cout<<"                                                                                                    "<<endl;
}

char * prov(char * a){
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD g{13,13};
	for(int i;i<strlen(a);i++){
		if(isspace(a[i])){
				system("cls");
				draw_line(h,15);
				SetConsoleTextAttribute(h, 016); 
				SetConsoleCursorPosition(h, g);
				cout<<"Enter one word for correct input ";
				fflush(stdin);
				gets(a);
				prov(a);
		}
	}
	cout<<endl<<endl;
	return a;
}

void draw_ram(HANDLE h,COORD a ,int dl,int vis){
	SetConsoleCursorPosition(h, a);
	SetConsoleTextAttribute(h, BACKGROUND_BLUE | BACKGROUND_GREEN );
	for(int i = 0;i<dl;i++){
		cout<<" ";
	}
	for(int i = 0;i<vis;i++){
		SetConsoleCursorPosition(h, a);
		a.Y++;
		cout<<" ";
	}
	SetConsoleCursorPosition(h, a);
	for(int i = 0;i<dl;i++){
		cout<<" ";
	}
	a.X+=dl;
	for(int i = 0;i<vis+1;i++){
		SetConsoleCursorPosition(h, a);
		a.Y--;
		cout<<" ";
	}
}


string  tolow(string a){
	for(int i =0;i<strlen(a.c_str())+1;i++){
		if(a[i]>64&&a[i]<91)
			a[i] +=32;
	}
	return a;
}

char *  tol(char * a){
	for(int i =0;i<strlen(a)+1;i++){
		if(a[i]>64&&a[i]<91)
			a[i] +=32;
	}
	return a;
}


void draw_menu(HANDLE h, COORD c, int k, int n, int len, COORD u, char *str, char *men[]) 
{ 
	system("cls"); 
	COORD t, b; 
	DWORD atr = 0; 
	t.X = 0; t.Y = 0; 
	b.X = 80; b.Y = 25; 
	SetConsoleCursorPosition(h, u); 
	SetConsoleTextAttribute(h, 016); 
	cout << str << endl; 
	COORD cc = c; 
	cc.X = 40; 
	SetConsoleTextAttribute(h, 012); 
	for (int i = 0; i<n; i++) 
	{ 
		cc.Y = c.Y + i*len; 
		SetConsoleCursorPosition(h, cc); 
		cout << men[i]; 
	} 
	cc.Y = c.Y + k*len; 
	SetConsoleTextAttribute(h, 013); 
	SetConsoleCursorPosition(h, cc); 
	cout << men[k]; 
}

void method()
{ 
	
	int fl = 1, ch = 10; 
	int n_mode = 7, k_mode = n_mode - 1, len_mode =4; 
	COORD current = { 5,7 }, u = { 40,3 }; 
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE); 
	char *name = "Select an action:"; 
	system("cls"); 
	draw_menu(h, current, k_mode, n_mode, len_mode, u, name, mode);
	COORD y = u;
	   y.X-=2;
	   y.Y+=2;
	draw_ram(h,y,20,28);
	SetConsoleTextAttribute(h,000);
	while (fl) 
	{ 
		if (_kbhit()) 
		{ 
			ch = _getch(); 
			switch (ch) 
			{ 
				case 27: 
				{ 
					fl = 0; 
					cout << "\n"; 
					break; 
				}			 
				case 13: 
				{
					switch (k_mode) 
					{ 
						case 0:
						{ 
							system("cls"); 
							SetConsoleTextAttribute(h, 015);
							create_base();
							system("PAUSE");
							break; 
						} 
						case 1:
						{ 
							system("cls");
							SetConsoleTextAttribute(h, 016); 
							change();
							system("PAUSE");
							break; 
						} 
						case 2:	
						{
							system("cls"); 
							SetConsoleTextAttribute(h, 017);							
							delete_base();
							system("PAUSE");
							break; 
						}
						case 3:
						{ 	
							system("cls"); 
							SetConsoleTextAttribute(h, 011);
							delete_in_base(); 
							system("PAUSE");
							break; 
						} 
						case 4: 
						{ 
							system("cls"); 
							SetConsoleTextAttribute(h, 012);
							add_in_base();							
							system("PAUSE");
							break; 
						}
						case 5:{
							system("cls"); 
							SetConsoleTextAttribute(h, 013);							
							find_in_base();
							system("PAUSE");
							break; 
						}
						 case 6:{
							system("cls"); 
							SetConsoleTextAttribute(h, 013);
							view();
							system("PAUSE");
							break; 
						}
						break; 
					} 
					case 80:
					{ 
						if (k_mode == n_mode - 1) 
						{
							k_mode = 0; 
						}else
						{
							k_mode++;
						} 
 						draw_menu(h, current, k_mode, n_mode, len_mode, u, name, mode);
						 draw_ram(h,y,20,28);
						SetConsoleTextAttribute(h,000); 
						break; 
					} 
					case 72:
					{ 
						if (k_mode == 0) 
						{
							k_mode = n_mode - 1; 
						}else
						{ 
							k_mode--; 
						} 
						draw_menu(h, current, k_mode, n_mode, len_mode, u, name, mode);
						draw_ram(h,y,20,28);
						SetConsoleTextAttribute(h,000);
						break; 
					} 
				} 
			} 
		}	 
	}
} 

void instruction() 
{ 
	system("cls");
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	draw_line(h,15);
	COORD g ={0,17};
	SetConsoleCursorPosition(h, g);
	SetConsoleTextAttribute(h, 015);
	cout<<"Management in the program is performed by the following keys:"<<endl<<"1) up and down arrows"<<endl<<"2) enter to choose action or end an input"<<endl<<"3) esc to go from the main menu to auxiliary"<<endl<<endl<<"The program also has the following functions:"<<endl;
	cout<<"1) Ñreate base - the function creates a textual file( if the file alredy exists, it'll be deleted)"<<endl<<" and records an input information"<<endl;
	cout<<"2) Change book - the func searches for a coincidence in titles and offers to replace. after that "<<endl<<"you can choose what you want it to do"<<endl;
	cout<<"3) Delete base - the func has preventive protection in case you didn't want to delete the base."<<endl<<" After checking the file will be deleted"<<endl;
	cout<<"4) Delete book - Similarly to the element change function, you will be prompted to delete one or "<<endl<<"more items if they are in the database"<<endl;
	cout<<"5) Add book - function zchitue äàí dan³, entered from the klaviaturi ³ zapustuº ¿h kynets file"<<endl;
	cout<<"6) Find - you have a function to introduce a note to you from one to the next, including the system "<<endl<<"vivede zbig. Funktsy rozroblena so, scho at pomiltsi in words vona takozh mozhe vidati virnyy result."<<endl;
	cout<<"7) View - the function to display all the information on the screen with a list"<<endl;
	draw_line(h,2);
	SetConsoleTextAttribute(h, 015);} 

void about() 
{ 
	system("cls");
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	draw_line(h,15);
	COORD g ={4,17};
	SetConsoleCursorPosition(h, g);
	SetConsoleTextAttribute(h, 015);
	cout<<"This program was developed by the first-year student Kharchenko Andriy"<<endl<<" department of IASA, KA-71 group"<<endl;
	draw_line(h,2);
	SetConsoleTextAttribute(h, 015);
	
} 


int file_empty(){
	ifstream in("book.txt");
	if(in.is_open())
	{
	    in.seekg(0,ios::end);
	    int size = in.tellg();
	    if( size <=3)
	    {
	         in.close();
	         return 0;
	    }
	}
	in.close();
	return 1;
}

void change(){ 
	char * buf5 = new char[255];
	COORD g ={13,13};
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(h,&structCursorInfo);
	structCursorInfo.bVisible = TRUE;
	SetConsoleCursorInfo( h, &structCursorInfo );
	int nn=0;
	if(!file_empty()){
		cout<<"File is empty"<<endl;
		return;
	}
	int cnt=0;
	char * buf = new char[100],* a = new char [100];
	string buf1;
	books * book = new books;
	books * book1 = new books;
	if(buf==NULL||book==NULL||a==NULL||book1==NULL){
		cout<<"Error of memory"<<endl;
		exit(0);
	}
	
	draw_line(h,15);
	SetConsoleTextAttribute(h, 016); 
	SetConsoleCursorPosition(h, g);
	cout<< "Enter name of book ";
	fflush(stdin);
	gets(buf);
	system("cls");
	buf=tol(buf);
	ifstream in("book.txt",ios::in);
	if(!in.is_open()){
		cout<<"Error of file"<<endl;
		exit(0);
	}
	ofstream out("book1.txt",ios::out);
	if(!out.is_open()){
		cout<<"Error of file"<<endl;
		exit(0);
	}
	for(int i=0;i<size_base();i++){
		system("cls");
		in>>book->name;
		in.getline(a,99);
		book->name += a;
		in >> book->surname_of_author;
		in >> book->name_of_author;
		in >> book->year;
		book1->name = tolow(book->name); 
		if(book1->name==buf){
			nn++;
			draw_line(h,15);
			SetConsoleTextAttribute(h, 016); 
			SetConsoleCursorPosition(h, g);
			COORD z = g;
			z.Y+=4;
			cout<<"Do you want change this book?Enter 'yes' or 'no'(next) ";
			SetConsoleCursorPosition(h, z);
			cout<<"Name : "<<book->name;
			z.Y++;
			SetConsoleCursorPosition(h, z);
			cout<<" Name of author : "<<book->name_of_author;
			z.Y++;
			SetConsoleCursorPosition(h, z);
			cout<<"Surname of author : "<<book->surname_of_author;
			z.Y++;
			SetConsoleCursorPosition(h, z);
			cout<<" Year of book = "<<book->year;
			z.Y-=7;
			z.X+=strlen("Do you want change this book?Enter 'yes' or 'no'(next) ");
			SetConsoleCursorPosition(h, z);
			while(1){
				cin >> buf1;
					if(buf1=="next"||buf1=="no"){
						cnt=-1;
						break;
					}
					if(buf1=="yes"){
						cnt=0;
						break;
					}
					system("cls");
					draw_line(h,15);
					SetConsoleTextAttribute(h, 016); 
					SetConsoleCursorPosition(h, g);
					cout<<"Enter correct answer ";
					z = g;
					z.Y+=4;
					SetConsoleCursorPosition(h, z);
					cout<<"Name : "<<book->name;
					z.Y++;
					SetConsoleCursorPosition(h, z);
					cout<<" Name of author : "<<book->name_of_author;
					z.Y++;
					SetConsoleCursorPosition(h, z);
					cout<<"Surname of author : "<<book->surname_of_author;
					z.Y++;
					SetConsoleCursorPosition(h, z);
					cout<<" Year of book = "<<book->year;
					z.Y-=7;
					z.X+=strlen("Enter correct answer ");
					SetConsoleCursorPosition(h, z);
			}
			system("cls");
			if(cnt==-1){
				out << book->name<<endl;
				out << book->surname_of_author<<endl;
				out<< book->name_of_author<<endl;
				out << book->year<<endl<<endl;				
			}
			if(cnt==0){
				draw_line(h,15);
				SetConsoleTextAttribute(h, 016); 
				SetConsoleCursorPosition(h, g);
				cout<< "What you want change?Enter name of field or 'nothing' ";
				z = g;
				z.Y+=4;
				SetConsoleCursorPosition(h, z);
				cout<<"Name : "<<book->name;
				z.Y++;
				SetConsoleCursorPosition(h, z);
				cout<<" Name of author : "<<book->name_of_author;
				z.Y++;
				SetConsoleCursorPosition(h, z);
				cout<<"Surname of author : "<<book->surname_of_author;
				z.Y++;
				SetConsoleCursorPosition(h, z);
				cout<<" Year of book = "<<book->year;
				z.Y-=7;
				z.X+=strlen("What you want change?Enter name of field or 'nothing' ");
				SetConsoleCursorPosition(h, z);
				while(1){
					int y=0;
					fflush(stdin);
					gets(a);
					system("cls");
					draw_line(h,15);
					SetConsoleTextAttribute(h, 016); 
					SetConsoleCursorPosition(h, g);
					buf1=a;
					if(buf1=="name"||buf1=="Name"){
						fflush(stdin);
						cout<<"Enter new name ";
						gets(a);
						book->name = a;
						y++;
					}
					if(buf1=="name of author"||buf1=="Name of author"){
						cout<<"Enter new name of author ";
						fflush(stdin);
						gets(buf5);
						book->name_of_author= prov(buf5);
						y++;
					}
					if(buf1=="surname of author"||buf1=="Surname of author"){
						cout<<"Enter new surname of author ";
						fflush(stdin);
						gets(buf5);
						book->surname_of_author= prov(buf5);
						y++;
					}
					if(buf1=="year"||buf1=="Year"){
						cout<<"Enter new year ";
						 while (1){
							fflush(stdin);
							cin >> buf1;
							int j=0;
							for(;j<=strlen(buf1.c_str());j++)
								if(isalpha(buf1[j])||ispunct(buf1[j])||isspace(buf1[j])){
									j=-1;
									break;
								}
							if(j!=-1)
								break;
							system("cls");
							draw_line(h,15);
							SetConsoleTextAttribute(h, 016); 
							SetConsoleCursorPosition(h, g);
							cout << "Enter correct data ";
						}
						book->year =  atoi(buf1.c_str());
						 y++;
					}
					if(buf1=="nothing")
					{
						out << book->name<<endl;
						out << book->surname_of_author<<endl;
						out<< book->name_of_author<<endl;
						out << book->year<<endl<<endl;	
						break;
					}
					system("cls");
					draw_line(h,15);
					SetConsoleTextAttribute(h, 016); 
					SetConsoleCursorPosition(h, g);
					if(y==1)cout<< "What yet you want change?Enter name of field or 'nothing' ";
					if(y==0)cout<<"Enter correct answer ";
					z = g;
					z.Y+=4;
					SetConsoleCursorPosition(h, z);
					cout<<"Name : "<<book->name;
					z.Y++;
					SetConsoleCursorPosition(h, z);
					cout<<" Name of author : "<<book->name_of_author;
					z.Y++;
					SetConsoleCursorPosition(h, z);
					cout<<"Surname of author : "<<book->surname_of_author;
					z.Y++;
					SetConsoleCursorPosition(h, z);
					cout<<" Year of book = "<<book->year;
					z.Y-=7;
					if(y==1)z.X+=strlen("What yet you want change?Enter name of field or 'nothing' ");
					if(y==0)z.X+=strlen("Enter correct answer ");
					SetConsoleCursorPosition(h, z);
				}
			}
				
		}
		else{
			out << book->name<<endl;
			out << book->surname_of_author<<endl;
			out<< book->name_of_author<<endl;
			out << book->year<<endl<<endl;			
		}
	}
	system("cls");
	draw_line(h,15);
	SetConsoleTextAttribute(h, 016); 
	SetConsoleCursorPosition(h, g);
	if(nn==0){	
		cout<<"			              NO MATHES				"<<endl<<endl<<endl;
		return ;
	}
	in.close();
	out.close();
	remove("book.txt");
	rename("book1.txt","book.txt");
	delete book1;
	delete []a;
	delete []buf;
	delete book;
	GetConsoleCursorInfo(h,&structCursorInfo);
	structCursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo( h, &structCursorInfo );
}

void delete_in_base(){
	COORD g ={13,13};
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(h,&structCursorInfo);
	structCursorInfo.bVisible = TRUE;
	SetConsoleCursorInfo( h, &structCursorInfo );
	draw_line(h,15);
	SetConsoleTextAttribute(h, 016); 
	SetConsoleCursorPosition(h, g);
	int nn=0;
	if(!file_empty()){
		cout<<"File is empty"<<endl;
		return;
	}
	int cnt=0;
	char * buf = new char[100],*a = new char[100];
	string buf1;
	books * book = new books;
	books *book1 = new books;
	if(buf==NULL||book==NULL||a==NULL ||book1==NULL){
		cout<<"Error of memory"<<endl;
		exit(0);
	}
	cout<< "Enter name of book ";
	fflush(stdin);
	gets(buf);
	buf = tol(buf);
	ifstream in("book.txt",ios::in);
	if(!in.is_open()){
		cout<<"Error of file"<<endl;
		exit(0);
	}
	ofstream out("book1.txt",ios::out);
	if(!out.is_open()){
		cout<<"Error of file"<<endl;
		exit(0);
	}
	for(int i=0;i<size_base();i++){
		in>>book->name;
		in.getline(a,99);
		book->name += a;
		in >> book->surname_of_author;
		in >> book->name_of_author;
		in >> book->year;
		book1->name = tolow(book->name);
		if(book1->name==buf){
			COORD u = g;
			u.Y+=4;
			nn++;
			system("cls");
			draw_line(h,15);
			SetConsoleTextAttribute(h, 016); 
			SetConsoleCursorPosition(h, g);
			cout<<"Do you want delete this book?Enter 'yes' or 'no'(next) ";
			SetConsoleCursorPosition(h, u);
			u.Y++;
			cout<<"Name : "<<book->name;
			SetConsoleCursorPosition(h, u);
			u.Y++;
			cout<<"Name of author : "<<book->name_of_author;
			SetConsoleCursorPosition(h, u);
			u.Y++;
			cout<<"Surname of author : "<<book->name_of_author;
			SetConsoleCursorPosition(h, u);
			u.Y++;
			cout<<" Year of book = "<<book->year<<endl<<endl;
			u.Y-=8;
			u.X+=strlen("Do you want delete this book?Enter 'yes' or 'no'(next) ");
			SetConsoleCursorPosition(h, u);

			while(1){
				cin >> buf1;
					if(buf1=="no"||buf1=="next"){
						cnt=-1;
						break;
					}
					if(buf1=="yes"){
						cnt=0;
						break;
					}
					system("cls");
					
					u = g;
					u.Y+=4;
					nn++;
					system("cls");
					draw_line(h,15);
					SetConsoleTextAttribute(h, 016); 
					SetConsoleCursorPosition(h, g);
					cout<<"Enter correct answer ";
					SetConsoleCursorPosition(h, u);
					u.Y++;
					cout<<"Name : "<<book->name;
					SetConsoleCursorPosition(h, u);
					u.Y++;
					cout<<"Name of author : "<<book->name_of_author;
					SetConsoleCursorPosition(h, u);
					u.Y++;
					cout<<"Surname of author : "<<book->name_of_author;
					SetConsoleCursorPosition(h, u);
					u.Y++;
					cout<<" Year of book = "<<book->year<<endl<<endl;
					u.Y-=8;
					u.X+=strlen("Enter correct answer ");
					SetConsoleCursorPosition(h, u);
			}
			if(cnt==-1){
				out << book->name<<endl;
				out << book->surname_of_author<<endl;
				out<< book->name_of_author<<endl;
				out << book->year<<endl<<endl;				
			}
			if(cnt==0)
				continue;
		}
		else{
			out << book->name<<endl;
			out << book->surname_of_author<<endl;
			out<< book->name_of_author<<endl;
			out << book->year<<endl<<endl;			
		}
	}
	if(nn==0){
		cout<<"			              NO MATHES				"<<endl<<endl;
		return ;
	}
	in.close();
	out.close();
	remove("book.txt");
	rename("book1.txt","book.txt");
	delete []a;
	delete []buf;
	delete book;
	GetConsoleCursorInfo(h,&structCursorInfo);
	structCursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo( h, &structCursorInfo );
}
int size_base(){
	if(!file_empty()){
		cout<<"File is empty"<<endl;
		return 0;
	}
	int n=0;
	char * buf = new char [100];
	if(buf==NULL){
		cout<<"Error of memory"<<endl;
		exit(0);
	}
	fstream s("book.txt",ios::in);
	if(!s.is_open()){
		cout<<"Error of file"<<endl;
		exit(0);
	}
	while(!s.eof()){
		s>>buf;
		s.getline(buf,99);
		s>>buf;
		s>>buf;
		s>>buf;
		n++;
	}
	s.close();
	delete []buf;
	return n-1;
}

void print_list(books *a, int b){
	for(int i=0;i<b;i++){
		cout.width(25);
		cout<<a[i].name;
		cout.width(30);
		cout<<a[i].surname_of_author;
		cout.width(30);
		cout<<a[i].name_of_author;
		cout.width(5);
		cout<<a[i].year<<endl;		
	}
}

books * sort(books * a,int b){
	books temp;
	for(int j=0;j<b;j++)
	for(int i = 0;i<b-1;i++){
		if(a[i].proc<a[i+1].proc){
			temp = a[i];
			a[i]=a[i+1];
			a[i+1] = temp;
		}
	}
	return a;
}


double slep(books * a,char * c){
	char * b = new char[100];
	if(b==NULL){
		cout<<"Error of memory"<<endl;
		exit(0);
	}
	strcpy(b,c);
	for(int i = 0;i<strlen(b);i++){
		if(b[i]==' '){
			for(int j=i;j<strlen(b);j++){
				b[j]=b[j+1];
			}
		}
	}
	char * buf3 = new char[100];
	if(buf3==NULL){
		cout<<"Error of memory"<<endl;
		exit(0);
	}
	string buf;
	itoa(a->year,buf3,10);
	buf=buf3;
	delete []buf3;
	return (vhod(a->name,b)+vhod(a->name_of_author,b)+vhod(a->surname_of_author,b)+vhod(buf,b))*1.5;
}



double vhod(string a,char * b){
	double c = strlen(b);
	double d = a.size();
	if(a.size()>=strlen(b)){
		for(int i=0;i<a.size()+1-strlen(b);i++){
			if(b[0]==a[i])
			{
				int c=i;
				for(int j=0;j<strlen(b);j++,c++)
				{
					if(b[j]!=a[c]){
							c=-1;
							break;
						}
				}
				if(c!=-1)
					return (c/d)*10;
			}
		}
		return 0;
	}
	if(a.size()<strlen(b)){
		for(int i=0;i<strlen(b)+1-a.size();i++){
			if(a[0]==b[i])
			{
				int c=i;
				for(int j=0;j<a.size();j++,c++){
					if(a[j]!=b[c]){
							c=-1;
							break;
						}
				}
				if(c!=-1)
					return (d/c)*10;
			}
		}
		return 0;
	}
}

void find_in_base(){
	if(!file_empty()){
		cout<<"File is empty"<<endl;
		return;
	}	
	char * c = new char[100];
	int nn=0;
	books * find = new books[size_base()];
	books *book2 = new books;
	books * book1 = new books;
	char * buf1 = new char[100],*buf2 = new char[100],*buf3 = new char[100];
	if(find==NULL||book1==NULL||buf1==NULL||buf2==NULL||buf3==NULL||book2==NULL)
	{
		cout<<"Error of memory"<<endl;
		exit(0);
	}
	COORD g ={13,13};
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(h,&structCursorInfo);
	structCursorInfo.bVisible = TRUE;
	SetConsoleCursorInfo( h, &structCursorInfo );
	draw_line(h,15);
	SetConsoleTextAttribute(h, 016); 
	SetConsoleCursorPosition(h, g);
	cout << "Enter request ";
	while(1){
		int l = 0;
		fflush(stdin);
		gets(buf1);
		for(int i = strlen(buf1);buf1[i-1]==' ';i--)
			buf1[i-1]=buf1[i];
		for(int i=0;i<strlen(buf1)+1;i++){
			if(buf1[i]==' ')
				l++;}
		if(l>3){
			system("cls");
			draw_line(h,15);
			SetConsoleTextAttribute(h, 016); 
			SetConsoleCursorPosition(h, g);
			cout<<"Long reques.Please, enter new reques"<<endl;
		}
		else break;	
	}
	system("cls");
	draw_line(h,15);
	SetConsoleTextAttribute(h, 016); 
	SetConsoleCursorPosition(h, g);
	cout<<"Request : ";
	puts(buf1); 
	g.Y+=3;
	g.X=0;
	SetConsoleCursorPosition(h, g);
	cout.setf(ios::left);
	cout.width(25);
	cout<<"Name";
	cout.width(30);
	cout<<"Surname of author";
	cout.width(30);
	cout<<"Name of author";
	cout.width(5);
	cout<<"Year"<<endl<<endl;;
	fstream book("book.txt",ios::in);
		if(!book.is_open()){
		cout<<"Error of file"<<endl;
		exit(0);
	}
	int b=0;
	for(int a = 1;a<=size_base();a++){
		int cnt1=0,cnt2=0;
		book>>book1->name;
		book.getline(c,99);
		book1->name += c;
		book >> book1->surname_of_author;
		book >> book1->name_of_author;
		book >> book1->year;
		book2->name = tolow(book1->name); 
		book2->surname_of_author = tolow(book1->surname_of_author); 
		book2->name_of_author = tolow(book1->name_of_author); 
		book2->year = book1->year;
		int i=0,j;
		for(j=0;i<=strlen(buf1)+1;i++,j++){
				if(buf1[i]!=' '&& i<strlen(buf1)+1){
					buf2[j]=buf1[i];
					continue;
				}
				if(buf1[i]==' '|| i==strlen(buf1)+1){

					cnt1++;
					buf2[j]='\0';
					buf2 = tol(buf2);
					if(strcmp(buf2,book2->name.c_str())==0||strcmp(buf2,book2->surname_of_author.c_str())==0||strcmp(buf2,book2->name_of_author.c_str())==0||book2->year ==atoi(buf2)){
						if(buf1[i]==' '){
							cnt2++;
							j=-1;
							continue;
						}
						if(buf1[i-1]==0){
							cnt2++;
						}
					}
				}
					
					j=-1;
			}
			if(cnt1-cnt2==1&&cnt1==4)
				book2->proc=75;	
			if(cnt1-cnt2==2&&cnt1==4)
				book2->proc=50;	
			if(cnt1-cnt2==3&&cnt1==4)
				book2->proc=25;	
			if(cnt1-cnt2==1&&cnt1==3)
				book2->proc=66;	
			if(cnt1-cnt2==2&&cnt1==3)
				book2->proc=33;	
			if(cnt1-cnt2==1&&cnt1==2)
				book2->proc=50;	
			if(cnt2==cnt1)
				book2->proc=100;
			if(cnt2==0)
				book2->proc=0;
			double proc;
			cnt1=0;
			i=0;
			for(j=0;i<=strlen(buf1)+1;i++,j++){
				if(buf1[i]!=' '&& i<strlen(buf1)+1){
					buf2[j]=buf1[i];
					continue;
				}
					cnt1++;
					buf2[j]='\0';
					buf2 = tol(buf2);
				string buf;
				itoa(book2->year,buf3,10);
				buf=buf3;
				proc =vhod(book2->name,buf2)+ vhod(book2->surname_of_author,buf2)+vhod(book2->name_of_author,buf2)+vhod(buf,buf2);
				if(proc*2.5>book1->proc)
					book2->proc=proc*2.5;
			}
			if(slep(book2,buf1)>book2->proc)
				book2->proc=slep(book2,buf1);
			if(book2->proc>0){
				nn++;		
				find[b].name=book1->name;
				find[b].name_of_author=book1->name_of_author;
				find[b].surname_of_author=book1->surname_of_author;
				find[b].year=book1->year;
				find[b].proc=book1->proc;
				b++;
			}
		}
		find = sort(find,b);
		if(nn==0){
			cout<<"			               NO MATHES				"<<endl;
			return ;
		}
		print_list(find,b);			
	book.close();
	delete book2;
	delete []c;
	delete []find;
	delete book1;
	delete []buf1;
	delete []buf2;
	delete []buf3;
	GetConsoleCursorInfo(h,&structCursorInfo);
	structCursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo( h, &structCursorInfo );
	}


void delete_base(){
	COORD g ={13,13};
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(h,&structCursorInfo);
	structCursorInfo.bVisible = TRUE;
	SetConsoleCursorInfo( h, &structCursorInfo );
	draw_line(h,15);
	SetConsoleTextAttribute(h, 016); 
	SetConsoleCursorPosition(h, g);
	if(!file_empty()){
		cout<<"File is empty"<<endl;
		return;
	}
	string buf;
	cout<< "Are you sure? Enter 'yes' or 'no' ";
	while(1){
		cin >>buf;
		if(buf == "yes"){
			fstream book("book.txt");
			book.close();
			remove("book.txt");
			break;
		}
		if(buf=="no")
			break;
		system("cls");
		draw_line(h,15);
		SetConsoleTextAttribute(h, 016); 
		SetConsoleCursorPosition(h, g);
		cout << "Enter correct answer ";	
	}
	GetConsoleCursorInfo(h,&structCursorInfo);
	structCursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo( h, &structCursorInfo );
}

void create_base(){
	COORD g ={13,13};
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(h,&structCursorInfo);
	structCursorInfo.bVisible = TRUE;
	SetConsoleCursorInfo( h, &structCursorInfo );
	draw_line(h,15);
	SetConsoleTextAttribute(h, 016); 
	SetConsoleCursorPosition(h, g);
	char * buf1= new char[100];
		if(buf1 == NULL){
		cout<<"Error of memory"<< endl;
		exit(0);
	}
	cout<< "Enter quantity of book ";
	while(1){
		fflush(stdin);
		cin >> buf1;
		int j=0;
		for(;j<=strlen(buf1);j++)
			if(isalpha(buf1[j])||ispunct(buf1[j])||isspace(buf1[j])){
				j=-1;
				break;
			}
		if(j!=-1)
			break;
		system("cls");
		draw_line(h,15);
		SetConsoleTextAttribute(h, 016); 
		SetConsoleCursorPosition(h, g);
		cout << "Enter correct quantity ";
	}
	system("cls");
	int n = atoi(buf1);
	delete []buf1;
	for(int i = 0 ; i< n;i++){
		system("cls");
		add_in_base();
	}
	GetConsoleCursorInfo(h,&structCursorInfo);
	structCursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo( h, &structCursorInfo );
}

void add_in_base(){
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	ofstream book("book.txt",ios_base::app);
	if (!book.is_open()){
	 	cout << "Error of file"<<endl;
	 	exit(0);
	}
	char  * buf1 = new char[100];
	if(buf1 == NULL){
		cout<<"Error of memory"<< endl;
		exit(0);
	}
	int b;
	COORD g ={13,13};
	char * a = new char[100];
	draw_line(h,15);
	SetConsoleTextAttribute(h, 016); 
	SetConsoleCursorPosition(h, g);
	string buf;
	cout << "Enter name of  book ";
	fflush(stdin);
	gets(a);
	system("cls");
	fflush(stdin);
	buf = a;
	book<<endl<< buf<<endl;
	draw_line(h,15);
	SetConsoleTextAttribute(h, 016); 
	SetConsoleCursorPosition(h, g);
	cout << "Enter surname of author of  book ";
	fflush(stdin);
	gets(a);
	buf = prov(a);
	system("cls");
	fflush(stdin);
	book<< buf<<endl;
	draw_line(h,15);
	SetConsoleTextAttribute(h, 016); 
	SetConsoleCursorPosition(h, g);
	cout << "Enter name of author of  book ";
	fflush(stdin);
	gets(a);
	buf = prov(a);
	system("cls");
	book<< buf<<endl;
	fflush(stdin);
	draw_line(h,15);
	SetConsoleTextAttribute(h, 016); 
	SetConsoleCursorPosition(h, g);
	cout << "Enter year of  book ";
	while (1){
		fflush(stdin);
		cin >> buf1;
		int j=0;
		for(;j<=strlen(buf1);j++)
			if(isalpha(buf1[j])||ispunct(buf1[j])||isspace(buf1[j])){
				j=-1;
				break;
			}
		if(j!=-1)
			break;
		system("cls");
		draw_line(h,15);
		SetConsoleTextAttribute(h, 016); 
		SetConsoleCursorPosition(h, g);
		cout << "Enter correct data ";
		}
		book << atoi(buf1)<<endl;
	
	book.close();
	delete buf1;
	delete []a;
}


void view(){ 
	COORD g ={10,13};
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	draw_line(h,15);
	SetConsoleTextAttribute(h, 016); 
	g.Y+=3;
	g.X=0;
	SetConsoleCursorPosition(h, g);
	if(!file_empty()){
		cout<<"File is empty"<<endl;
		return;
	}
	fstream book("book.txt",ios::in);
	if(!book.is_open()){
		cout<<"Error of file"<<endl;
		exit(0);
	}
	string s;
	char * c = new char[100];
	cout.setf(ios::left);
	cout.width(25);
	cout<<"Name";
	cout.width(30);
	cout<<"Surname of author";
	cout.width(30);
	cout<<"Name of author";
	cout.width(5);
	cout<<"Year"<<endl<<endl;
	for(int a = 1;a<=size_base();a++){
		int cnt1=0,cnt2=0;
		book>>s;
		book.getline(c,99);
		cout.width(25);
		cout<< s+c;
		book.getline(c,99);
		cout.width(30);
		cout<< c;
		book.getline(c,99);
		cout.width(30);
		cout<< c;
		book.getline(c,99);
		cout.width(5);
		cout<< c<<endl;
	}
	draw_line(h,0);
	SetConsoleTextAttribute(h, 016); 
	delete []c;
	book.close();
}

