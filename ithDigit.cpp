//4th program by Piskunov Yury MMF IT 19 28092017

#include <iostream>
#include <iomanip>
#include <clocale>
#include <cmath>
//разбить число на циферки, начиная слева направо.,
//дз вывести максимальную цифру числа
using namespace std;


void swap(int &a, int &b)
{
	int temp;
	temp=a;
	a=b;
	b=temp;
}

int main()
{
	setlocale(LC_ALL,"Ru");
	int a=0, b=0, c=1;
	int numberLength=2;
	
	cout<<"Enter a ";
	cin>>a;


	b=a;
	int i=0;
	while(b!=0)
		{
			b/=10;
			i++;
		}
	
	numberLength=i;
	b=a;
	while(i>0)
	{		
		i--;
		c=b/pow(10,i);
		cout<<numberLength-i<<"th digit of number "<<a<<" is "<<c<<'\n';
		b-=c*pow(10,i);		
	}


	int v=1;
	cin>>v;
	return 0;
}