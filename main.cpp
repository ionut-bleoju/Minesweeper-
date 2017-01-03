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
			cout << "---";
	}

	cout << "|" << endl << "  |";
	for (int i=0;i<dim[0];i++)
	{if(i+1>10)
		cout << "|" << i+1 << "|";
	}
	cout << "X" << endl;
	for (int i=0;i<dim[1];i++)
	{
		if ((i+1) % 10 == 0)
		{
			cout << (i+1)/10 << (i+1) % 10 << "|";
		}
		else
		{
			cout << " " << (i+1) % 10 << "|";
		}
		for (int j=0;j<dim[0];j++)
		{
			cout << "[" << icons.at(tabel[j][i]) << "]";
		}
		cout << "|" << endl;
	}
	cout << " Y|";
	for (int i=0;i<dim[0];i++)
	{
		cout << "---";
	}
	cout << "|" << endl;
}


int main()
{cin>>dim[0];
 cin>>dim[1];

   Traseaza(icons);
    return 0;
}
