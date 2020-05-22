#include <iostream>
#include <math.h>
#include <windows.h>
#include <stdlib.h>
//#include "CONST_NTT.h"
//#include "fMODE1.h"
//#include "aMODE1.h"
using namespace std;

//CONST_NTT.h
const char A_MODE = 'a';
const char F_MODE = 'f';
const char M_MODE = 'm';
const char Quit = 'Q';
const char Delete = 'D';
const char AC = 'A';
const char ADD = '+' ;
const char MINUS = '-' ;
const char MUTI = 'x';
const char DEVIDE = ':';
const char SIN = 's';
const char COS = 'c';
const char TAN = 't';
const char SQRT = 'v';
const char LOG = 'L';
const char LOGE = 'l';
const char EXP = 'e';
const char MR = 'R';
const char MC = 'C';
const char GThua = '!';
const char Percent = '%';
const double pi = 3.1415;

//aMODE1.h
void Calculate(char opf, double Number);
//fMODE.h
void TinhFMODE(char opf,double Number);
void TinhGThua(double Number);
//mMODE.h
void TinhMMODE(char opf);

void CheckOperator(char opf );
int Kiemtra(int a);

double Result = 0, Dem = 0  ;
double Memery = 0;
char op = 0, Flag , opf;
int Check = 0;

//main.cpp
int main()
{
    double Number1 , Number2  ;
    cout << "       *** Simple Calculator ***\n";
    cout << " a - AMODE      f - FMODE     m = MMODE\n";
    cout << " Q - QUIT       A - AC        D - DELETE \n";
    cout << "---------------------------------------------\n";

    if(op != Delete || op == AC )
    if (Check == 0)
    {
        cout << "Vui long chon MODE\n";
        cin >> Flag;

    }
    if(Flag == A_MODE  )
    {
        cin >> Number1;
        Result = Number1;
    }
    if(Flag == F_MODE)
    {
    	cin >> op;
    	CheckOperator(op);
        if(Kiemtra(0) == 1) main();
        if(Kiemtra(0) == -1) exit(0);
    	cin >> Number1;
    	TinhFMODE(op,Number1);
    	if(Check == 2) exit(0);
        Result = Dem;
        if(Kiemtra(0) == 0) cout <<"________\n= " << Result <<endl;
	}
    while (1 > 0)
    {
    	cin >> op ;
        CheckOperator(op);
        if(Kiemtra(0) == 1) continue;
        if(Kiemtra(0) == -1) break;

        if(Flag == A_MODE)
        {
            cin >> Number2 ;
            Calculate (op , Number2);
            if(Kiemtra(0) == 0) cout <<"________\n= " << Result <<endl;
            if (Check == 2) break;
        }
        if(Flag == F_MODE)
        {
            cin >> opf;
    	 	CheckOperator(opf);
            if(Kiemtra(0) == 1) continue;
            if(Kiemtra(0) == -1) break;

			if(opf != 'M') cin >> Number2;
            TinhFMODE(opf , Number2);
    		if(Check != 2) Number2 = Dem;
    		else break;

            Calculate(op , Number2);
            if(Kiemtra(0) == 0) cout <<"________\n= " << Result <<endl;
            if (Check == 2) break;
            }
        if(Flag == M_MODE)
        {
            CheckOperator(op);
            if(Kiemtra(0) == 1) continue;
            if(Kiemtra(0) == -1) break;

	  		TinhMMODE(op);
	  		if (Check == 2) break;
	  		Flag = A_MODE;
        }
    }
    return 0;
}
//aMODE1.cpp
int  Kiemtra(int a)
{
    if(Check == 1)
    {
        Check = 0;
        return 1;
    }
    if(Check == 2 && op != Quit)
    {
        cout << "Math Error";
        return -1 ;
    }
    if(op == Quit) return -1;
  return 0;
}

void CheckOperator(char opf )
{
	if(opf == A_MODE || opf == F_MODE || opf == M_MODE )
    {
        Flag = opf;
        Check = 1;
    }
    switch (opf)
    {
	case Quit :
		Check = 2;
		cout << "Thank you";
		exit(0);
        break;
	case Delete :
		system("cls");
		op = opf ;
		main();
        break;
	case AC :
		system("cls");
    	Result = 0;
    	Dem = 0 ;
		main ();
        break;
    }
}

void Calculate(char opf , double Number)
{
    switch(opf)
    {
        case ADD:
            Result += Number;
            break;
        case MINUS :
            Result -= Number;
            break;
        case MUTI:
            Result *=  Number;
            break;
        case DEVIDE :
            if(Number != 0 ) Result /=  Number;
            else Check = 2;
            break;
        default  :
            Check = 2;
            break;
          }
}
//fMODE.cpp

void TinhGThua(double Number)
{
    Dem = 1;
    for(int i = 1 ; i <= Number ; i ++) Dem *= i ;
}
void TinhFMODE(char opf , double Number)
{
	switch(opf)
            {
            case SIN :
                Dem = sin(Number * pi / 180);
                break;
            case COS :
                Dem = cos(Number * pi / 180);
                break;
            case TAN:
                if(Number  == 90)
                {
                    Check = 2;
                    cout << "Math Error";
                }
                else Dem = tan(Number * pi / 180);
                break;
            case SQRT:
                if(Number >= 0) Dem = sqrt(Number);
                else
                {
                    Check = 2;
                    cout << "Math Error";
                }
                break;
            case LOGE :
            	if(Number > 0) Dem = log(Number);
            	else
                {
                    Check = 2;
                    cout << "Math Error";
                }
				break;
            case LOG :
                if(Number > 0) Dem = log10(Number);
            	else
                {
                    Check = 2;
                    cout << "Math Error";
                }
				break;
            case EXP :
                Dem = exp(Number);
                break;
            case GThua :
                if(Number >= 0)  TinhGThua(Number);
                if(Number < 0)
                {
                    Check = 2;
                    cout << "Math Error";
                }
                break;
            case Percent :
                Dem = Number/100;
                break;
            case 'M':
                cin >> opf;
                if(opf == MR) Dem = Memery;
                break;
            default :
                Check = 2;
                cout << "Math Error";
                break;
            }
}
//mMODE.cpp
void TinhMMODE(char opf)
{
    switch (opf)
	  		{
            case ADD:
                Memery +=  Result;
                break;
            case MINUS:
                Memery -= Result;
                break;
            case MC:
                Memery = 0;
                break;
            case MR:
                Result = Memery;
                if(Kiemtra(0) == 0) cout <<"________\n= " << Result <<endl;
                break;
            default :
                Check = 2;
                break;
	  		}
}
