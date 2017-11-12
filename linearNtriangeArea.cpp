//2nd program by Piskunov Yury MMF IT 19

#include <iostream>
#include <clocale>

using namespace std;

float m=0,n=0,p=0;

float a=0;
int b,d=0;

void variablesInput()
{
	cout<<"Enter lengths of sides\n";
	cin>>m;
	cin>>n;
	cin>>p;
}

void coeffsInput()
{
	cout<<"Enter coefficients of equation d=ax+b\n";
	cout<<"\nFor d: ";
	cin>>d;
	cout<<"\nFor a: ";
	cin>>a;
	cout<<"\nFor b: ";
	cin>>b;
}

int main()
{
	/*char c=0;
	int j=1;
	long int l=2;
	long long int ll=22;
	float f=12;
	double b=1233445566788;

	
	/*cout<<sizeof(c)*8<<'\n';
	cout<<sizeof(j)*8<<'\n';
	cout<<sizeof(l)*8<<'\n';
	cout<<sizeof(ll)*8<<'\n';
	cout<<sizeof(f)*8<<'\n';
	cout<<sizeof(b)*8<<'\n';*/

	setlocale(LC_ALL, "Ru");

	float pp=0;
	variablesInput();


	//test of existance-->sort by ascending then sum first two - if sum>max then true

	int temp=0;

	while(true)
	{
		if(m>n)
		{
			temp=n;
			n=m;
			m=temp;
		}
		if(n>p)
		{
			temp=p;
			p=n;
			n=temp;
		}

		if((m+n)<=p)
		{
			cout<<"\nTringle with such sides doesn't exist - enter another one:\n";
			variablesInput();			
		}
		else break;
	}




	pp=(m+n+p)/2.0;
	cout<<"The square of triangle is "<<pp*(pp-m)*(pp-n)*(pp-p);


	cout<<"\n\n\n";
	coeffsInput();
	while(true)
	{
		
		if(a==0)
		{
			cout<<"\nThere is no solution due to a=0. Enter another one\n\n\n";
			coeffsInput();			
		}
		else break;
	}

	float x=(d-b)/a;

	cout<<"\nThe solution of equation is: x= "<<x;


	float cosinusM=(p*p+n*n-m*m)/(2*p*n);
	if(cosinusM)
		if(cosinusM>0) cout<<"\nThe triangle is acute-angled\n";
		else cout<<"\nThe triangle is obtuse\n";
	else cout<<"\nThe triangle is right\n";



	int v=1;
	cin>>v;
	return 0;
}