//2nd program by Piskunov Yury MMF IT 19

#include <iostream>
#include <iomanip>
#include <clocale>

using namespace std;


int main()
{
	setlocale(LC_ALL,"Ru");
	int a=123;
	int mask=1;
	int rez=1;
	int size=sizeof(a)*8;

	int i;
	int temp=a;
	for (i=1;i<=size;i++)
	{
		rez=temp&mask;// каждый шаг цикла число сначала умножается на 1, чтобы взять последний бит,
		temp=temp>>1;//потом сдвигается вправо на 1, чтобы уже в следующем шаге взять следующий бит
		cout<<setw(2)<<i<<"-ый бит числа "<<a<<" равен "<<rez<<endl;
	}

	cout<<"----------------------"<<endl;

	temp=a;//чтобы не испортить
	for (i=size;i>=1;i--) //здесь начинаем смотреть число слева направо (маска типа 100000, потом 010000 и т.д.)
	{            mask=(1<<(i-1));
	rez=(temp&mask)>>(i-1);// применяется маска, обнуляющая все разряды кроме нужного, затем число сдвигается вправо до самого первого разряда
	//			 (было например, 00100 - стало 00001 - нужно чтобы выводило не 8, а 1 (бит искомого разряда))

	cout<<setw(2)<<i<<"-ый бит числа "<<a<<" равен "<<rez<<endl;
	}


	cout<<"----------------------"<<endl;
	temp=a;
	for (i=1;i<=size;i++)
	{
		rez=temp&mask;
		mask=mask<<1;
		cout<<setw(2)<<i<<"-ый бит числа "<<a<<" равен "<<(rez!=0)<<endl;
	}

	int v=1;
	cin>>v;
	return 0;
}