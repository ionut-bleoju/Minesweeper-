#include <iostream>
#include <string>
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace std;
//variabile globale
int dim[2];//Dimensiune tabela ;
int **tabel;
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
			cout << "[ " << icons.at(tabel[i][j]) << "]";
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
bool sfarsit()
{
	for (int i=0;i<dim[0];i++)
	{
		for (int j=0;j<dim[1];j++)
		{
			if (tabel[i][j] == 9 || tabel[i][j] == 11)
			{
				return false;
			}
		}
	}
	return true;
}

void Marcheaza()
{
	cout << endl << "Marcheaza...";
	int *tile = &tabel[actiune[0]-1][actiune[1]-1];
	*tile += 2*(*tile == 9 || *tile == 10) - 2*(*tile == 11 || *tile == 12);
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

int vecini(int X, int Y)
{
	int nrMine = 0;
	for (int i=-1+(X==0);i<=1-(X==dim[0]-1);i++)
	{
		for (int j=-1+(Y==0);j<=1-(Y==dim[1]-1);j++)
		{
			if (tabel[X+i][Y+j] == 10 || tabel[X+i][Y+j] == 12)
			{
				nrMine++;
			}
		}
	}
	return nrMine;
}

void extinde(int X, int Y)
{

	if (tabel[X][Y] == 9 || tabel[X][Y] == 11)
	{
		tabel[X][Y] = -1;
		do
		{
			if (tabel[X][Y] == -1)
			{
				tabel[X][Y] = vecini(X,Y);
				if (tabel[X][Y] == 0)
				{
					for (int i=-1+(X==0);i<=1-(X==dim[0]-1);i++)
					{
						for (int j=-1+(Y==0);j<=1-(Y==dim[1]-1);j++)
						{
							if (tabel[X+i][Y+j] == 9)
							{
								tabel[X+i][Y+j] = -1;
							}
						}
					}
					X -= (X>0)+(X>-1);
					Y -= (Y>0);
					cout << endl << "--X = " << X << "  Y = " << Y;
				}
			}
			Y += (X==dim[0]-1);
			X = X*(X!=dim[0]-1) - (X==dim[0]-1);
			X += (X<dim[0]-1);
		} while (Y!=dim[1]);
		cout << endl << "X = " << X << "  Y = " << Y;
	}
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
{
    actiune[0] = actiune[1] = actiune[2] = 0;
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
{   srand(time(0)); //RNG
	int bin;
	double prob;
	double random;
	cout << endl << "Consola Minesweeper"
	<< endl << "Latimea tabelei (X) = ";
	cin >> dim[0];
	cout << endl << "Inaltimea tabelei (Y) = ";
	cin >> dim[1];
	tabel = new int * [dim[0]];
	for(int i=0;i<dim[0];i++)
	{
		tabel[i] = new int[dim[1]];
	}
    return 0;
}
