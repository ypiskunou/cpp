//program by Piskunov Yury MMF IT 19 19102017

#include <iostream>
#include <clocale>
#include <iomanip>
#include <cmath>
#include <ctime>

#define _USE_MATH_DEFINES

using namespace std;

double funcTab(double x)
{
	return sin(x)/x;
}

int funcFibonacci(int n)
{
	int z=1;
	int previousZ=0;
	int temp=0;
	int i=1;

	while(i<n)
	{
		temp=z;
		z+=previousZ;
		previousZ=temp;
		i++;
	}

	return z;
}


int funcFibonacciRecurs(int a)
{	
	if(a==1) return 1;
	if(a==2) return 2;
	return a+funcFibonacciRecurs(a-1);
}

void funcFibonacciInputOutput()
{
	int n=0;

	while(n<=0)
	{
		cout<<"\nВведите номер числа из ряда Фибоначчи (больший нуля)\n";
		cin>>n;
	}

	cout<<"Значение "<<n<<"-го члена ряда Фибионаччи равно "<<funcFibonacciRecurs(n)<<'\n';
}


void tabulating()
{

	double a=-1, b=-a;
	double h=0.01;

	for(double x=a; x<=b; x=x+h)
	{
		cout<<"\n x= "<<setw(5)<<x<<", y= "<<setw(5)<<funcTab(x);
	}


}

int gcDivisor(int a, int b)//Euclid's algorithm
{
	int gcd=0;
	int max=b, min=a;

	if(a>b)
	{
		max=a;
		min=b;
	}

	int remainder=-1;
	while(remainder!=0)
	{
		gcd=remainder;
		remainder=max%min;
		max=min;
		min=remainder;
	}

	return gcd;
}

void gcDivisorDialog()
{
	int a=0, b=0;

	char q=0;
	while(q!='q')
	{
		while(a<=0||b<=0||a==b)
		{
			cout<<"\nВведите два положительных неравных друг другу числа, НОД которых требуется найти: \n";
			cin>>a;
			cin>>b;
		}

		cout<<"\nНОД чисел "<<a<<" и "<<b<<" равен: "<<gcDivisor(a, b)<<'\n';
		a=0;

		cout<<"Для выхода введите q - любой другой символ, чтобы продолжить: ";
		cin>>q;
	}
}

bool isPrime(int n)
{
	if(n==5||n==2) return true;

	int lastDigit=n%10;	
	if(lastDigit==0||lastDigit%2==0||lastDigit==5) return false;

	int k=sqrt(n)+1;

	for(int i=3; i<=k; i=i+2)
		if(n%i==0) return false;

	return true;
}

void factorization(int a)//naive way
{
	int i=0, f=2;

	//f=2 need
	for(;a>1;i++)
		if(a%f==0) a/=f;
		else break;
		if(i) cout<<"\nThe number has a factor "<<f<<" in a power of "<<i;


		for(f=3, i=0; a>1; f=f+2, i=0)
		{
			if(isPrime(f))
			{
				for(;;i++)
					if(a%f==0) a/=f;				
					else break;
					if(i) cout<<"\nThe number has a factor "<<f<<" in a power of "<<i;
			}
			else continue;//not required
		}		
}

void factorizationDialog()
{
	int a=0;

	char q=0;
	while(q!='q')
	{
		while(a<=2)
		{
			cout<<"\nВведите положительное число большее 2, которое требуется факторизовать: \n";
			cin>>a;			
		}

		factorization(a);
		a=0;

		cout<<"\nДля выхода введите q - любой другой символ, чтобы продолжить: ";
		cin>>q;
	}
}

/*void dialogPrimeOrNot()
{
int n=0;

cout<<"\nEnter an integer number more than 1 to check if it is prime: ";
while(n<2)
{
cin>>n;
cout<<'\n';
}
if(isPrime(n)) cout<<"\n The number "<<n<<" is prime.";
else cout<<"\n The number "<<n<<" is not prime.";
}*/

int randXor(int max)
{
	int a=21, b=35, c=4, tmp=time(NULL);
	tmp^=tmp<<a;
	tmp^=tmp>>b;
	tmp^=tmp<<c;
	tmp%=max;
	return tmp>0?tmp:-tmp;
}

void randDialog()
{
	int a=0;

	char q=0;
	while(q!='q')
	{
		while(a<=0)
		{
			cout<<"\nВведите положительное число большее 0, как верхнюю границу результата: \n";
			cin>>a;			
		}

		cout<<"\nСлучайное число: "<<randXor(a);
		a=0;

		cout<<"\nДля выхода введите q - любой другой символ, чтобы продолжить: ";
		cin>>q;
	}
}

int main()
{
	setlocale(LC_ALL, "Ru");

	randDialog();
	//tabulating();
	funcFibonacciInputOutput();
	//gcDivisorDialog();
	factorizationDialog();


	for(int i=3; i<40; i++)
		cout<<'\n'<<funcFibonacci(i+1)/(float)funcFibonacci(i);// стремится к 1,61803


	int v=0;
	cin>>v;

	return 0;
}

/**********
##ДЗ9 на 3/11##
1)Написать функцию разложения на простые множители 
Написать функцию НОД(a,b)

2) Линейный конгруэнтный генератор псевдослучайных чисел  (habrahabr.ru/company/infopulse/blog/329778/)
Для большинства программ использующих случайность достаточно не настоящих случайных чисел, а лишь чисел, которые ведут себя похожим образом.
Поэтому на практике находят очень широкое применение алгоритмы генерации псевдослучайных чисел. Простейшим и обычно самым быстрым из них является
*линейный конгруэнтный метод*.  
Суть метода выражается в нахождение следующего псевдослучайного числа по предыдущему по представленной формуле:  

x(n+1) = (a*x(n) + c) mod m;

где x(n+1) новое псевдослучайное число, x(n) — старое, mod это сравнимость по модулю, что практически полностью соответствует нахождению остатка
при делении на m,  
1 <= a < m, 0 < c < m 
и m некоторые коэффициенты, которые и определяют последовательность псевдослучайных чисел.  
Не каждый набор коэффициентов определяет последовательность похожую на случайные числа, так например a = 7 c = 8 m = 16, порождают последовательность
чередующихся 0 и 8.  
Для хорошей генерации должны быть выполнены следующие правила:  
1. Числа c и m взаимно простые;  
2. a - 1 кратно p для каждого простого p, являющегося делителем m;  
3. a - 1 кратно 4, если m кратно 4.  
Реализовать линейный конгруэнтный генератор псевдослучайных чисел.  
(a) Используя коэффициенты из википедии, например a=4096, c=150889, m=714025.  
(b) Подобрав собственные коэффициенты по правилам, не использую готовые коэффициенты из википедии.  


3) В 2003 году Джордж Марсаглия предложил быстрый алгоритм XORShift генерации псевдослучайных  чисел с использованием XOR (в С++ эта операция
обозначается через знак ^ ) и битовыми сдвигами. Алгоритм состоит из 3 действий:

tmp = XOR(x(n),x(n)<<a) ;

tmp = XOR(tmp,tmp>>b) ;

x(n+1) = XOR(tmp,tmp<<c) ;

Начальное значение x(0) можно выбирать любое. Начиная с него и начнется генерация чисел (аналогично srand(____) для начала работы с rand()).
“Магические“ числа а,b и с подбираются самостоятельно. 
В частности, при 21, 35 и 4 генерируют последовательность с полным периодом равным 2^64-1.

Можно использовать числа 13,15,5.

Реализуйте этот алгоритм в качестве отдельной функции, чтобы потом выполнять задания на массивы (там где надо случайными числами заполнить массив)!
**********/