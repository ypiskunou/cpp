//2nd program by Piskunov Yury MMF IT 19

#include <iostream>
#include <clocale>
#include <cmath>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Ru");

	char operation = -1;
	double a = 0;
	double b = 0;
	double rez=0;
	int i=1;	

	cout << "\nEnter operands divided by any of following operation + - * / % (enter = for result)";
	cin >> rez;
	
	while (true)
	{

		if(i==1)
		{
			a=rez;				
			cin>>operation;
			i++;
		}
		if(i==2&&operation!='=') cin >> b;
		if(operation=='/'&&b==0)
		{
			while(b==0)
			{
				cout<<"\nZero is not allowed to use as a divisor - enter another one: ";
				cin>>b;
			}
		}
		i=1;

		switch (operation)
		{
		case '+': rez=a+b;
			break;
		case '-': rez=a-b;
			break;
		case '*': rez=a*b;
			break;
		case '/': rez=a/b;
			break;
		case '%': if(a- (int)a==0&&b- (int)b==0) rez=(int)a%(int)b;
				  else {cout<<"This operation is appliable only to integer operands"; rez=a;}
				  break;
		case '=': cout<<rez;
			break;
		//case 'c': break;

		default:
			{
				cout << "Wrong operation";
				break;
			}
		}
	}


	int v = 1;
	cin >> v;
	return 0;
}

/**********
##ƒ«6 на 13/10##

калькул€тор на switch . –еализовать простой калькул€тор. ѕользователь вводит число, затем операцию в виде символа
(Т+Т, Т-Т, Т*Т, Т/Т, '%' и т.д.), после второе число. ¬ывести результат операции.

"Ќормальный" калькул€тор. ќбработка ситуации делени€ на 0. –езультат вычислений остаетс€ как текущее значение.
≈сли вместо операции ввести символ ТcТ, то калькул€тор сбрасываетс€ в начало, при вводе символа ТqТ вместо операции
калькул€тор завершает работу (quit).   

"ѕрошаренный" калькул€тор (на бонус) ѕользователь может вводить произвольное количество чисел и операций (поочерЄдно),
после введени€ символа Т=Т выдаЄтс€ конечный результат, и калькул€тор сбрасываетс€ в начало.  
********/