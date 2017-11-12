//program by Piskunov Yury MMF IT 19 31102017

#include <iostream>
#include <clocale>
#include <cmath>
#include<ctime>

using namespace std;

bool isEven(int n)
{
	return n%2==0;	
}

bool isOdd(int n)
{
	return !isEven(n);
}

int main()
{
	setlocale(LC_ALL, "Ru");
	
	int n=0;
	cout<<"\n Enter a number to check if it is even: ";
	cin>>n;

	cout<<isEven?"\n The number is even.":"\n The number is odd.";

	int v=1;
	cin>>v;
	return 0;
}

/***********
isEven isOdd
***********/