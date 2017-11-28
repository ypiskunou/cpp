//program by Piskunov Yury MMF IT 19 19102017

#include <iostream>
#include <clocale>
#include <iomanip>
#include <cmath>
#include <ctime>

typedef int TYPE;

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

bool isSquare(int a)
{
	double root=sqrt(a);
	return (root-(int)root)==0;
}

void isSquareDialog()
{
	int a=0;

	char q=0;
	while(q!='q')
	{
		while(a<=0)
		{
			cout<<"\nВведите положительное число большее 0: \n";
			cin>>a;			
		}

		cout<<"\nЧисло "<<a; isSquare(a)?cout<<" является полным квадратом ":cout<<" не является полным квадратом ";
		a=0;

		cout<<"\nДля выхода введите q - любой другой символ, чтобы продолжить: ";
		cin>>q;
	}
}
/*
void toBin(int a)
{
	int rez=1;
	int size=sizeof(a)*8;
	int mask=1;
		
	for (int i=size;i>=1;i--) //здесь начинаем смотреть число слева направо (маска типа 100000, потом 010000 и т.д.)
	{            mask=(1<<(i-1));
	rez=(a&mask)>>(i-1);// применяется маска, обнуляющая все разряды кроме нужного, затем число сдвигается вправо до самого первого разряда
	//			 (было например, 00100 - стало 00001 - нужно чтобы выводило не 8, а 1 (бит искомого разряда))

	cout<<setw(2)<<i<<"-ый бит числа "<<a<<" равен "<<rez<<endl;
	}
}*/

void toBin(int a)
{
	int rez=1;
	int size=sizeof(a)*8;
	int mask=1;
		
	for (int i=size;i>=1;i--)
	{
		mask=(1<<(i-1));
		rez=a&mask;
		cout<<(rez!=0);
	}
}

void toBinDialog()
{
	int a=-1;

	char q=-1;
	while(q!='q')
	{
		a=-1;
		while(a<0)
		{
			cout<<"\nВведите целое положительное число: \n";
			cin>>a;			
		}

		toBin(a);

		cout<<"\nДля выхода введите q - любой другой символ, чтобы продолжить: ";
		cin>>q;
	}
}

void toHex(int a)
{
	int rez=1;
	int size=sizeof(a)*8;
	int mask=1;
		
	for (int i=size/4;i>=1;i--)
	{
		mask=(15<<(i-1)*4);
		rez=(a&mask)>>(i-1)*4;
		if(rez<10)
		{
			cout<<rez;
			continue;
		}
		switch(rez)
		{
		case 10: cout<<'A';
			break;
		case 11: cout<<'B';
			break;
		case 12: cout<<'C';
			break;
		case 13: cout<<'D';
			break;
		case 14: cout<<'E';
			break;
		case 15: cout<<'F';
			break;
		}
	}
}

void toHexDialog()
{
	int a=-1;

	char q=-1;
	while(q!='q')
	{
		a=-1;
		while(a<0)
		{
			cout<<"\nВведите целое положительное число: \n";
			cin>>a;			
		}

		toHex(a);

		cout<<"\nДля выхода введите q - любой другой символ, чтобы продолжить: ";
		cin>>q;
	}
}

void swap(int a, int b)
{
	int temp;
	temp=a;
	a=b;
	b=temp;
}

int main()
{
	setlocale(LC_ALL, "Ru");
	char a='l', b='k';
	swap(a,b);
	cout<<a<<b;

	toBinDialog();
	toHexDialog();
	isSquareDialog();
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
##ДЗ9 на 27/10##
(Функции)
1) Во всех предыдущих выполненных заданиях сделать так, чтобы main() выглядел как последовательный вызов нескольких функций. Например,
void main(){
    int a,b,c;
    printCondition();/функция печатает условие задачи и просит ввести три числа 
    cin>>a>>b>>c;
    if (checkSide(a,b,c)) return; /функция проверяет существование треугольника
    calcArea(a,b,c); функция вычисления площади треугольника по формуле Герона 
// для слудующей задачи    
    sort3num(a,b,c); /функция "сортирует" три числа
    solveSquareEq(a,b,c);
    solveLinearEq(a,b,c);


2) Создать функции 
isPrime(a); isSquare(a); *****
sumOfDgit(a); maxDigit(a); minDigit(a); reverse(); isPolindrom(a); 
toBin(a) печатает двоичное представление числа, toHex(a);****
swap(a,b) для всех типов данных

printTriangle(n);/долларами треугольник заданного размера 
printTriangle(n,symb); символами symb треугольник заданного размера 
printRectangle(n,m,symb); символами symb прямоугольник заданного размера 



##ДЗ на 7/11##
1) Покажите к чему стремится отношение соседних чисел Фибоначчи. Для этого выведите в столбик отношение последующего к предыдущему и предыдущего к последующему для первых 40 чисел Фибоначчи (long long int должно хватить для хранения).  
2) Напишите игру в кости между человеком и компьютером. Они по очереди кидают по два кубика. Побеждает тот у кого сумма больше. Кубики рисуйте псевдографикой. Желательно реализовать хоть какой-то интерфейс взаимодействия с пользователем.    
3а) Печать "графика" функции на промежутке [a,b] с шагом h если заранее известен min(y) и max(y) (например, sin(2x)).
3б) Печать "графика" функции на промежутке [a,b] с шагом h если НЕизвестен min(y) и max(y) (например, x*sin(2x)). Сначала табулируем функцию чтобы найти min(y) и max(y). Потом еще раз (как в предыдущем случае) табулируем функцию чтобы строить график. 
4)*************** Вы хотите взломать сейф, ключевая комбинация в нём задаётся перестановкой цифр в заданном числе. Напишите программу помощник, которая по введённому числу распечатает все перестановки цифр в числе1.
(для этого можно использовать рекурсию и delLastDigit(a),delFirstDigit(a), reverse(a) и т.д.)
5) для "прошаренных" к письму есть в приложении файл с задачами и теорией по рекурсии.
**********/