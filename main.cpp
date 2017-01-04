#include <iostream>
using namespace std;
//variabile globale
int dim[2];//Dimensiune tabela ;
int tabel[15][15];
const string icons = " 12345678++%%*";


void Traseaza(string icons)
{
	cout<<endl<< "  |";
	for (int i=0;i<dim[0];i++) //Prima Linie
	{
			cout << "----";
	}

	cout << "|" << endl << "  |";
	for (int i=0;i<dim[0];i++)
	{if(i+2>10)
		cout << "|" << i+1 << "|";
    else
        cout << "| " << i+1 << "|";
	}
	cout << "X" << endl;
	for (int i=0;i<dim[1];i++)
	{
		if ((i+1)>=10)
		{
			cout << (i+1)/10 << (i+1) % 10 << "|";
		}
		else
		{
			cout << " " << (i+1) % 10 << "|";
		}
		for (int j=0;j<dim[0];j++)
		{
			cout << "[ " << icons.at(0) << "]";
		}
		cout << "|" << endl;
	}
	cout << " Y|";
	for (int i=0;i<dim[0];i++)
	{
		cout << "----";
	}
	cout << "|" << endl;
}

void Actiune()
	{actiune[0] = actiune[1] = actiune[2] = 0;
	cout
	<< endl << "[" << icons.at(9) << "] - necunoscut   [" << icons.at(1) << "-" << icons.at(8) << "] - # mine inprejur"
	<< endl << "[" << icons.at(0) << "] - 0 mine  [" << icons.at(10) << "] - mine  [" << icons.at(11) << "] - Marcat"
	<< endl << "-Miscare 1-Identifica 2-Marcheaza";

	do
	{
		cout << endl << endl << "Actiune = ";
		cin >> actiune[0] >> actiune[1] >> actiune[2];
		cout << endl << "Valideaza...";
	} while (!testactiune());//De inplementat
	if (actiune[2] == 1)
	{
		Investigheaza();//De inplementat
	}
	else
	{
		Marcheaza();//De inplementat
	}
}

int main()
{cin>>dim[0];
 cin>>dim[1];

   Traseaza(icons);
    return 0;
}
