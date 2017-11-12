//program by Piskunov Yury MMF IT 19 19102017

#include <iostream>
#include <clocale>
#include <iomanip>
#include <cmath>

using namespace std;


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

void dialogPrimeOrNot()
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
}


int main()
{
	setlocale(LC_ALL, "Ru");

	int total=0;
	for(int i=2; i<1000; i++)
		if(isPrime(i)) {cout<<'\n'<<i; total++;}
		cout<<"\n Total: "<<total;

	while(1)
	{
		dialogPrimeOrNot();

		char q=0;
		cout<<"\nEnter q - to quit: ";
		cin>>q;
		if(q=='q') break;
	}


	return 0;
}

/**********
IsPrime - функция определяет - является ли заданное число простым
**********/