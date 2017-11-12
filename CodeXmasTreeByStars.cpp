//program by Piskunov Yury MMF IT 19 19102017

#include <iostream>
#include <clocale>
#include <iomanip>
//#include <cmath>

using namespace std;

void triangleByBucks()
{
	int n=0;

	cout<<"\nEnter an integer number more than 1 as a base side of triangle to be printed: ";
	while(n<2)
	{
		cin>>n;
		cout<<'\n';
	}
	for(int i=1; i<=n; i++)
	{
		for(int j=0;j<i;j++)
			cout<<"$";
		cout<<'\n';
	}
}

void offsetSpaces(int n)
{
	for(int k=0;k<n;k++)// сначала оставляем пробелы, потом рисуем звездочку
		cout<<' ';
}

void triangleEquilateralBorderByStars(int n, int maxN)
{
	bool noChange=true;
	int maxRow=(n+1)*2;

	for(int i=0;i<=maxRow;i++) //рисует треугольник высотой в п строк (с пробельными строками)
	{
		if(noChange)//оставляет промежутки между звездочками по вертикали (через один ряд)
		{
			offsetSpaces(maxN-i/2);
			if(i==maxRow)
				for(int k=0; k<3+n*2; k++)
					cout<<'*';
			else if(i==0)
				cout<<'*';//      *******  - соответствует номеру последней строки, т.е. высоте п		
			else
			{					
				cout<<'*';
				for(int k=0; k<i-1; k++)
					cout<<' ';
				cout<<'*';						
			}
			cout<<'\n';
		}
		else cout<<"\n";
		noChange=!noChange;
	}
}

void xMasTree(int n)
{
	for(int i=0; i<n; i++)
		triangleEquilateralBorderByStars(i, n);
}

void dialogOutputXmasTree()
{
	int n=0;

	cout<<"\nEnter an integer number more than 1 as a quantity of tree's levels: ";
	while(n<2)
	{
		cin>>n;
		cout<<'\n';
	}
	xMasTree(n);
}


int main()
{
	setlocale(LC_ALL, "Ru");

	//triangleByBucks();
	dialogOutputXmasTree();


	int v=1;
	cin>>v;
	return 0;
}

/**********
++++ ромбик с диагоналями a и b
#ДЗ9 на 20/10##
Прочитать про манипуляторы и флаги для потоков (http://kvodo.ru/urok-10-formatirovannyiy-vvod-vyivod-v-c.html)
Создать программу, которая используя флаги выводит долларами треугольник заданного размера (размер вводить из std::cin)/
Например, ввели 5 получили
$
$$
$$$
$$$$
$$$$$
Ввели 7 получили
$
$$
$$$
$$$$
$$$$$
$$$$$$
$$$$$$$
Усложнение: сделать ёлочку. Число ярусов вводит пользователь. Смотрите рисунок ниже:
*
***
*
* *
*****
*
* *
*   *
*******
*
* *
*   *
*     *
*********
**********/