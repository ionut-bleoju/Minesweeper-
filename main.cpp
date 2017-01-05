#include <iostream>
using namespace std;
//variabile globale
int dim[2];//Dimensiune tabela ;
int tabel[15][15];
int actiune[3];
int mine = 0;
bool  test = true;
const string icons = " 12345678++%%*";
#define limita(X,NUM) (NUM<=dim[X] && NUM>0)

void Traseaza(string icons)
{
	cout<<endl<< "  |";
	for (int i=0;i<dim[0];i++)
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



bool testactiune()
{
	bool OK = (limita(0,actiune[0]) && limita(1,actiune[1]) && actiune[2]<=2 && actiune[2]>0);
	if (OK)
	{
		int *titlu = &tabel[actiune[0]-1][actiune[1]-1];
		if (*titlu > -1 && *titlu < 9) //Spatiul este deja inspectat sau marcat

		{
			cout << endl << "Actiunea nu este permisa " << actiune[0] << " " << actiune[1];
			OK = false;
		}
		else
		{
			cout << endl << "Permisa " << endl;
			if (actiune[2] == 1)
			{
				cout << "Actiune - Identifica";
			}
			else
			{
				cout << "Actiune - Marcheaza";
			}
			cout <<  " @ X = " << actiune[0] << ", Y = " << actiune[1];
		}
	}
	else
	{
		cout << endl << "Eroare:Valoarea introdusa este inafara domeniului";
	}
	return OK;
}

void Investigheaza()
{
	cout << endl << "Inspecteaza...";
	int *tile = &tabel[actiune[0]-1][actiune[1]-1];
	if (*tile == 10 || *tile == 12)
	{
		test = false;
		*tile = 13;
	}
	else
	{
		extinde(actiune[0]-1, actiune[1]-1);
	}
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
{
    return 0;
}
