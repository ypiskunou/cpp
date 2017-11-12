//program by Piskunov Yury MMF IT 19 10102017

#include <iostream>
#include <clocale>
#include <cmath>
#include<ctime>

using namespace std;

void outputNumbers()
{
	int n=0;

	cout<<"\nEnter a positive non-zero integer number, all preceding numbers of which will be on screen: ";
	while(n<1)
	{
		cin>>n;
		cout<<'\n';
	}

	for(int i=1;i<=n;i++)
		cout<<i<<' ';
}

void outputNumbersProduct()
{
	int n=0;
	float a=0;
	float rez=1;

	cout<<"\nEnter a positive non-zero integer number as a quantity of factors to enter: ";
	while(n<1)
	{
		cin>>n;
		cout<<'\n';
	}

	for(int i=0;i<n;i++)
	{
		cout<<"\nEnter factor ";
		cin>>a;
		rez*=a;
	}

	cout<<"\nThe product is "<<rez;
}

void minMax()
{
	int n=0;
	float min=INT_MAX;
	float max=INT_MIN;
	float a=0;

	cout<<"\nEnter a positive non-zero integer number as a quantity of numbers to enter: ";
	while(n<1)
	{
		cin>>n;
		cout<<'\n';
	}

	for(int i=0;i<n;i++)
	{
		cout<<"\nEnter number ";
		cin>>a;
		if(a<min) min=a;
		if(a>max) max=a;
	}

	cout<<"\nThe maximum is "<<max<<"\nThe minimum is "<<min;
}

void cubesOdd17()
{
	cout<<"\nList of cubes of odd numbers up to 17 ";

	//for(long int i=1, j=0;j<17;i+=2, j++)
		//cout<<"\n"<<i*i*i;
	
	for(long int i=0;i<17;i++)
		cout<<"\n"<<(2*i+1)*(2*i+1)*(2*i+1);
}

void rectangleFilled()
{
	int m=0;
	int n=0;

	cout<<"\nEnter a positive non-zero integer number as a width of rectangle to be printed: ";
	while(m<1)
	{
		cin>>m;
		cout<<'\n';
	}
	cout<<"\nEnter a positive non-zero integer number as a height of rectangle to be printed: ";
	while(n<1)
	{
		cin>>n;
		cout<<'\n';
	}

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
			cout<<'*';
		cout<<'\n';
	}
}

void rectangleBorder()
{
	int m=0;
	int n=0;

	cout<<"\nEnter a positive non-zero integer number as a width of rectangle to be printed: ";
	while(m<1)
	{
		cin>>m;
		cout<<'\n';
	}
	cout<<"\nEnter a positive non-zero integer number as a height of rectangle to be printed: ";
	while(n<1)
	{
		cin>>n;
		cout<<'\n';
	}

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
			if(i==0||i==n-1) cout<<'*';
			else if(j==0||j==m-1) cout<<'*';
			else cout<<' ';
		cout<<'\n';
	}
}

void chessPattern()
{
	int m=0;
	int n=0;

	cout<<"\nEnter a positive non-zero integer number as a width of rectangle to be printed: ";
	while(m<1)
	{
		cin>>m;
		cout<<'\n';
	}
	cout<<"\nEnter a positive non-zero integer number as a height of rectangle to be printed: ";
	while(n<1)
	{
		cin>>n;
		cout<<'\n';
	}

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
			if(i==0||i==n-1) cout<<'*';
			else if(j==0||j==m-1) cout<<'*';
			else if((j+i)%2) cout<<'*';
			else cout<<' ';
		cout<<'\n';
	}
}

void moreLess()
{
	srand(time(NULL));
	int n=0;
	int i=1;
	int guess=0;
	char q=' ';

	while(true)
	{
		n=rand()%98+1;
		i=1;
		while(true)
		{
			cout<<"\nEnter your guess integer number (from 1 to 99): ";
			guess=0;
			while(guess<1)
			{
				cin>>guess;
				cout<<'\n';
			}

			if (guess-n>0) { cout<<"\nThe number you are trying to find is less. "; i++; }
			else if (guess-n<0) { cout<<"\nThe number you are trying to find is more. "; i++; }
			else { cout<<"\nCongratulations! You guessed the number out in "<<i<<" tries. "; break; }
		}

		cout<<"\nEnter q - to quit this game (anything else to continue): ";
		cin>>q;
		if(q=='q') break;
	}
}

int main()
{
	setlocale(LC_ALL, "Ru");
	/*//first part
	outputNumbers();
	outputNumbersProduct();
	minMax();
	cubesOdd17();
	*/

	//second part
	rectangleFilled();
	rectangleBorder();
	chessPattern();
	moreLess();

	int v=1;
	cin>>v;
	return 0;
}

/***********
##ДЗ8 на 17/10##
Доделать калькулятор.
(Циклы)
1. (только для начинающих) Вывести фразу ”I know and I understand the cycles!” 123 раза.
Пользователь вводит число n. Вывести через пробел числа от 1 до n. 
Пользователь вводит число n. Затем ему надо ввести n чисел. Вывести произведения этих чисел.
Пользователь вводит число n. Затем вводит n чисел. Вывести максимальное и минимальное из этих чисел.
Вывести в столбик таблицу кубов первых 17 нечётных чисел.

2. (для всех) Пользователь вводит два натуральных числа m; n. Напечатать звёздочками прям2.оугольник введённой ширины и высоты.
Усложнение1: напечатать только "границу" этого прямоугольника.
Усложнение2: заполнить поле звёздочками в шахматном порядке (правильно печатать для любой четности m и n).

Написать программу угадайку. Компьютер загадывает произвольное число от 1 до 99 включительно, а пользователь пытается его угадать.
Компьютер даёт подсказки («перебор», «недобор») и считает число попыток угадывания. В результате выдаётся число попыток
за которые пользователь смог угадать число, и предлагается сыграть повторно.
***********/