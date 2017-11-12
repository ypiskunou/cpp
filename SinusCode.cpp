//program by Piskunov Yury MMF IT 19 10102017

#include <iostream>
#include <clocale>
#include <cmath>

using namespace std;

#pragma region sinus
double degreesToRadians(int degrees)
{
	double pi=3.14159265358979232;
	return degrees/180.0*pi;
}

double sinus(double radians, double precision)
{
	double z=radians; // нулевой член
	double previousZ=0;
	double rez=z;
	float i=1;
	//long int j=0;

	while(abs(abs(z)-previousZ)-precision>0)//(j<1000000)//остаточный член находится на самом деле по другой формуле
	{
		previousZ=abs(z);
		i++;
		z*=-radians*radians/i/(i+1);
		rez+=z;
		//j++;
	}

	return rez;
}

void sinusInputOutput()
{
	int angle=0;
	double precision=10;

	cout<<"\nВведите угол требуемого синуса в виде целого числа градусов\n";
	cin>>angle;
	while(precision>angle/10.0||precision>=1)
	{
		cout<<"Введите требуемую точность вычисления синуса меньшую либо равную 1/10 аргумента, но не большую 1\n";
		cin>>precision;
	}

	cout<<"Значение синуса "<<sinus(degreesToRadians(angle), precision)<<'\n';
}
#pragma endregion

#pragma region exponentaPowered
double expPower(double power, double precision)
{
	double z=1; // нулевой член
	double previousZ=0;
	double rez=z;
	float i=0;
	//long int j=0;

	while(previousZ-z-precision>0||i<3)//(j<1000000)//остаточный член находится на самом деле по другой формуле
	{
		previousZ=z;
		i++;
		z*=power/i;
		rez+=z;
		//j++;
	}

	return rez;
}

void expPowerInputOutput()
{
	int power=0;
	double precision=-1;

	cout<<"\nВведите целую степень, в которую вы хотите возвести экспоненту\n";
	cin>>power;
	while(precision<=0)
	{
		cout<<"Введите требуемую точность вычисления\n";
		cin>>precision;
	}

	cout<<"Значение экспоненты в степени "<<power<<" равно "<<expPower(power, precision)<<'\n';
}
#pragma endregion

#pragma region Fibonacci
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

void funcFibonacciInputOutput()
{
	int n=0;
	
	while(n<=0)
	{
		cout<<"\nВведите номер числа из ряда Фибоначчи (больший нуля)\n";
		cin>>n;
	}

	cout<<"Значение "<<n<<"-го члена ряда Фибионаччи равно "<<funcFibonacci(n)<<'\n';
}
#pragma endregion

int main()
{
	setlocale(LC_ALL, "Ru");

	funcFibonacciInputOutput();
	expPowerInputOutput();
	sinusInputOutput();
	
	int v=1;
	cin>>v;
	return 0;
}



/*

Написать функцию, вычисляющую синус по ряду Тейлора.
Вычислить f(x) (последовательность Фиббоначчи) по реккурентной формуле до тех пор пока очередной член не станет меньше эпсилон.
Или разность соседних членов должна быть меньше эпсилон. Вычисление проводим пока итый член не станет меньше наперед 
заданного эпсилон Итый член ни в коем случае не надо вычислять по формуле, потому что это приведет к н операциям умножения
при увеличении н это очень медленно. Надо обнаружить рекрсию - каждый следующий член суммы может быть вычислен по предыдущему
с помощью всего двух операций умножения - умножить на х в числителе, на i в знаменателе.

*/