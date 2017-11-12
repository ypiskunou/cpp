//4th program by Piskunov Yury MMF IT 19 28092017

#include <iostream>
#include <iomanip>
#include <clocale>
#include <cmath>
//разбить число на циферки, начиная слева направо.,
//дз вывести максимальную цифру числа
using namespace std;

int digitsSum(int n)
{
	int sum=0;
	
	while(n!=0)
	{
		sum+=n%10;
		n/=10;
	}

	return sum;
}

void quadraticEquation()
{
	int a=1, b=0, c=0;
	int x1=0, x2=0;
	cout<<"\nEnter coefficients of square equation: "<<b<<'\n'<<"a ";
	cin>>a;
	cout<<"\nb ";
	cin>>b;
	cout<<"\nc ";
	cin>>c;
	cout<<"\nThe roots of equation "<<a<<"x^2+"<<b<<"x"<<c<<" are: "<<x1<<' '<<x2;
	if(a==0) cout<<"\nThe given equation is not quadratic!";

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
	

	/*+Find max and min digit in a given number*/
	int max=0, min=10;
	int sum=0, sumOfEvenPositions=0, sumHappy=0;
	int numberBack=0;
	bool flagAscendingNumber=true;
	int maxAscending=0;
	

	numberLength=i;
	b=a;
	while(i>0)
	{		
		i--;
		c=b/pow(10,i);
		cout<<numberLength-i<<"th digit of number "<<a<<" is "<<c<<'\n';
		b-=c*pow(10,i);

		if(maxAscending>c) flagAscendingNumber=false;
		maxAscending=c;
		
		if(c<min) min=c;
		if(c>max) max=c;
		sum+=c;

		if(!((numberLength-i)%2)) sumOfEvenPositions+=c;

		if(numberLength==6)
		{
			if(numberLength-i<=3) sumHappy+=c;
			else sumHappy-=c;
		}

		numberBack+=c*pow(10,numberLength-i-1);
	}

	cout<<"\nMinimal digit is "<<min<<", maximal digit is "<<max<<'\n';
	cout<<"\nSum of all digits is "<<sum<<'\n';
	cout<<"\nSum of digits at even positions is "<<sumOfEvenPositions<<'\n';
	if(sumHappy) cout<<"\nThere is not happy sum"<<'\n';
	else if(!sumHappy) cout<<"\nThere is a happy sum. YEAH, dude."<<'\n';

	cout<<"\nNumber upside down is "<<numberBack<<'\n';
	if(a==numberBack) cout<<"\nIt's a polindrome, dude! POLINDROooME! o_O\n";
	
	
	bool flagNextSameSumFound=false;
	b=a;
	while(!flagNextSameSumFound)
	{
		b++;
		if(sum==digitsSum(b)) flagNextSameSumFound=true;
	}
	cout<<"\nNext number with the same digits' sum is "<<b<<'\n';


	//quadraticEquation();
	
	//найти число, в котором цифры расположены по порядку
	if(flagAscendingNumber)	cout<<"\nThis number is ascending! ";


	
	int v=1;
	cin>>v;
	return 0;
}