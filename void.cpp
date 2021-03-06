#include <bits/stdc++.h> 
#include <vector> 
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>
using namespace std;

vector<string>phone; 
vector<string>name;
vector<string>surname;

string first_name;
string last_name;
string number;

string newname;
string newsurname;
string newnumber;

char choise;
string question;	

char key;

int index;
int control;
int element;
int quit = false;

bool is_number(string s) 
{ 
    for (int i = 0; i < s.length(); i++)
	{ 
        if (isdigit(s[i]) == false) 
            return false; 
	}	
    return true; 
}

void random_name()
{
	int i = 0;
	string random_name[10] = {"Bianca", "Alice", "Marco", "Simone", "Mauro", "Giovanni", "Andrea", "Federica", "Max", "Licia"};
	while(i++ < 20) 
	{
		int r = (rand() % 10);
		string element = random_name[r];
		name.push_back(element);
	}
}

void random_surname()
{
	int i = 0;
	string random_surname[10] = {"Greco", "Conti", "Ricci", "Ferri", "Costa", "Galli", "Serra", "Parisi", "Villa", "Riva"};
	while(i++ < 20) 
	{
		int r = (rand() % 10);
		string element = random_surname[r];
		surname.push_back(element);
	} 
}

void random_number(){
	int i = 0;
	while(i++ < 20) 
	{
		int r = (rand() % 10000) + 348599999;
		stringstream numberConvert;	
		numberConvert << r;
		string word_num = numberConvert.str();
		phone.push_back(word_num);
	}
}

void print_vector()
{
	cout << "I TUOI CONTATTI" << endl << endl; 
    for (int i = 0; i < name.size(); i++)
	{
		cout << " " << name[i];
		for(int e = name[i].length(); e <= 10; e++){
			cout << " " ;
		}
		cout << " " << surname[i];
		for(int e = surname[i].length(); e <= 10; e++){
			cout << " " ;
		}
		cout << " " << phone[i] << " " 
    	<< endl;
	}          
}

void check()
{
	control = 0;
	for (int i = 0; i < name.size(); i++)
	{
	    for (int e = 0; e < surname.size(); e++)
		{
	   		if(name[i] == first_name and surname[e] == last_name and i == e)
			{
	   			control = 1;
			}else if(phone[e] == number and i == e)
			{
				control = 2;
			}
		}
	}
}

void random_check()
{
	for(int j = 0; j < name.size(); j++)
	{
		first_name = name[j];
		last_name = surname[j];
		
		for (int i = 1 + j; i < name.size(); i++)
		{
			if(first_name == name[i] and last_name == surname[i])
			{
				name.erase(name.begin() + i);
	    		surname.erase(surname.begin() + i);
	    		phone.erase(phone.begin() + i);
			}
		}	
	}
	for(int e = 0; e < phone.size(); e++)
	{
		number = phone[e];
		for (int l = 1 + e; l < phone.size(); l++)
		{
			if(number == phone[l])
			{
				name.erase(name.begin() + l);
	    		surname.erase(surname.begin() + l);
	    		phone.erase(phone.begin() + l);
			}
		}
	}
}

void main_page()
{
	cout << endl;
	print_vector();
	cout << endl
	<< "A - aggiungi contatto" << endl
	<< endl
	<< "S - cerca contatto" << endl
	<< endl
	<< "D - digita un contatto per accedere ad altre opzioni" << endl 
	<< endl
	<< "E - elimina rubrica" << endl 
	<< endl
	<< "Q - esci" << endl 
	<< endl;
}

void add_contact()
{
	cout << "Nome: ";
    cin >> first_name;
    //getline(cin, first_name);
    cout << "Cognome: ";
    cin >> last_name;
    //getline(cin, last_name);
    cout << "Numero: ";
    cin >> number;
    
    check();
    if(control == 1)
    {
    	cout << endl;
    	cout << "Impossibile salvare il contatto: nome o cognome esistenti." << endl;
	}else if(control == 2)
	{
		cout << endl;
    	cout << "Impossibile salvare il contatto: numero esistente." << endl;
	}else if(control == 0)
	{
		name.push_back(first_name);
    	surname.push_back(last_name);
    	phone.push_back(number);
		cout << endl;
		main_page();
	}
}

void search()
{
	cout << "Inserici un nome o un numero per esteso da cercare" << endl;
	cin >> question;
	cout << endl;
	//if(question[0] == '0'||'1'||'2'||'3'||'4'||'5'||'6'||'7'||'8'||'9')
	if(is_number(question))
	{
		cout << endl << "Risultato della ricerca:"<< endl << endl;
		for (int i = 0; i < phone.size(); i++)
		{
		    if(phone[i] == question)
			{
				cout << name[i] << " "
				<< surname[i] << " "
				<< phone[i] << " "
	    		<< endl;
	    	}
		}
	} 
    else
    {
    	cout << endl << "Risultato della ricerca:"<< endl << endl;
		for (int i = 0; i < name.size(); i++)
		{
		    if(name[i] == question)
			{
				cout << name[i] << " "
				<< surname[i] << " "
				<< phone[i] << " "
	    		<< endl;
	    	}
		}
		for (int i = 0; i < surname.size(); i++)
		{
		    if(surname[i] == question)
			{
				cout << name[i] << " "
				<< surname[i] << " "
				<< phone[i] << " "
	    		<< endl;
	    	}
		}
	}
	cout << endl
	<< "S - ripeti la ricerca"<< endl
	<< "M - torna alla rubrica" << endl;
	cin >> key;
	
	if(key == 's'){
    	search();
	}else if(key == 'm'){
		main_page();
	}     
}

void open_contact()
{
	cout << "Inserisci il nome del contatto" << endl;
	cin >> first_name;
	cout << "Inserisci il cognome del contatto" << endl;
	cin >> last_name;
	
	for (int i = 0; i < name.size(); i++)
	{
	    for (int e = 0; e < surname.size(); e++)
		{
	    	if(name[i] == first_name and surname[e] == last_name and i == e)
			{
	    			index = e;
	    			cout << endl << name[e] << " " << surname[e] << " " << phone[e] << " " << endl
					<< "C - modifica" << endl
					<< "R - elimina"<< endl
					<< "M - torna alla rubrica" << endl;
			}
		}
	}
}

void change()
{
	cout << endl << "MODIFICA" << endl
	<< "1 - nome" << endl
	<< "2 - cognome" << endl
	<< "3 - numero" << endl
	<< "4 - indietro" << endl;
	cin >> element;
	switch(element)
	{
		case 1:
			cout << "Nome: ";
			cin >> newname;
			name[index]	= newname;
			change();
			break;				
		case 2:
			cout << "Cognome: ";
			cin >> newsurname;
			surname[index]	= newsurname;
			change();
			break;							
		case 3:
			cout << "Numero: ";
			cin >> newnumber;
			phone[index] = newnumber;
			change();
			break;
		case 4:
			main_page();
			break;
	}		 			
}

void remove()
{
	cout << "Sei sicuro di voler eliminare il contatto?" << endl
	<< "1 - Si" << endl << "2 - No" << endl;;
	cin >> choise;
	if(choise == '1')
	{
		name.erase(name.begin() + index);
		surname.erase(surname.begin() + index);
		phone.erase(phone.begin() + index);
		main_page();
	}else if(choise == '2'){
		open_contact();
	}	
}

void remove_all()
{
	cout << "Sei sicuro di voler eliminare tutta la rubrica?" << endl
	<< "1 - Si" << endl << "2 - No" << endl;
	cin >> choise;
	if(choise == '1')
	{
		name.clear();
		surname.clear();
		phone.clear();
	}else if(choise == '2')
	{
		main_page();
	}
}
