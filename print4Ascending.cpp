//4th program by Piskunov Yury MMF IT 19 28092017

#include <iostream>
#include <iomanip>
#include <clocale>

using namespace std;


void swap(int *a, int *b)
{
	int *temp;
	temp=a;
	a=b;
	b=temp;
}

int main()
{
	setlocale(LC_ALL,"Ru");
	int a=0, b=0, c=0, d=0;
	
	cout<<"Enter a ";
	cin>>a;
	cout<<"\nEnter b ";
	cin>>b;
	cout<<"\nEnter c ";
	cin>>c;
	cout<<"\nEnter d ";
	cin>>d;


	int a2=a, b2=b, c2=c, d2=d;

	if(a2>=b2) swap(a2,b2);//тут разве не нужно брать адрес??? или приведение?
	if(b2>=c2) swap(b2,c2);
	if(c2>=d2) swap(c2,d2);

	if(a2>=b2) swap(a2,b2);
	if(b2>=c2) swap(b2,c2);

	if(a2>=b2) swap(a2,b2);

	cout<<"\n"<<a2<<' '<<b2<<' '<<c2<<' '<<d2;

	/*нижеприведенный код правильный, но... */
	/*if(a<=b&&a<=c&&a<=d)
	{
		if(b<=c&&b<=d)
			if(c<=d)
				cout<<"\n"<<a<<' '<<b<<' '<<c<<' '<<d;
			else cout<<"\n"<<a<<' '<<b<<' '<<d<<' '<<c;
		else if(c<=b&&c<=d)
			if(b<=d)
				cout<<"\n"<<a<<' '<<c<<' '<<b<<' '<<d;
			else cout<<"\n"<<a<<' '<<c<<' '<<d<<' '<<b;
		else if(d<=b&&d<=c)
			if(b<=c)
				cout<<"\n"<<a<<' '<<d<<' '<<b<<' '<<c;
			else cout<<"\n"<<a<<' '<<d<<' '<<c<<' '<<b;
	}


	if(b<=a&&b<=c&&b<=d)
	{
		if(a<=c&&a<=d)
			if(c<=d)
				cout<<"\n"<<b<<' '<<a<<' '<<c<<' '<<d;
			else cout<<"\n"<<b<<' '<<a<<' '<<d<<' '<<c;
		else if(c<=a&&c<=d)
			if(a<=d)
				cout<<"\n"<<b<<' '<<c<<' '<<a<<' '<<d;
			else cout<<"\n"<<b<<' '<<c<<' '<<d<<' '<<a;
		else if(d<=a&&d<=c)
			if(a<=c)
				cout<<"\n"<<b<<' '<<d<<' '<<a<<' '<<c;
			else cout<<"\n"<<b<<' '<<d<<' '<<c<<' '<<a;
	}

	if(c<=a&&c<=b&&c<=d)
	{
		if(a<=b&&a<=d)
			if(b<=d)
				cout<<"\n"<<c<<' '<<a<<' '<<b<<' '<<d;
			else cout<<"\n"<<c<<' '<<a<<' '<<d<<' '<<b;
		else if(b<=a&&b<=d)
			if(a<=d)
				cout<<"\n"<<c<<' '<<b<<' '<<a<<' '<<d;
			else cout<<"\n"<<c<<' '<<b<<' '<<d<<' '<<a;
		else if(d<=a&&d<=b)
			if(a<=b)
				cout<<"\n"<<c<<' '<<d<<' '<<a<<' '<<b;
			else cout<<"\n"<<c<<' '<<d<<' '<<b<<' '<<a;
	}

	if(d<=a&&d<=b&&d<=c)
	{
		if(a<=b&&a<=c)
			if(b<=c)
				cout<<"\n"<<d<<' '<<a<<' '<<b<<' '<<c;
			else cout<<"\n"<<d<<' '<<a<<' '<<c<<' '<<b;
		else if(b<=a&&b<=c)
			if(a<=c)
				cout<<"\n"<<d<<' '<<b<<' '<<a<<' '<<c;
			else cout<<"\n"<<d<<' '<<b<<' '<<c<<' '<<a;
		else if(c<=a&&c<=b)
			if(a<=b)
				cout<<"\n"<<d<<' '<<c<<' '<<a<<' '<<b;
			else cout<<"\n"<<d<<' '<<c<<' '<<b<<' '<<a;
	}*/
		
	int v=1;
	cin>>v;
	return 0;
}