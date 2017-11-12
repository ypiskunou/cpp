//2nd program by Piskunov Yury MMF IT 19

#include <iostream>
#include <clocale>

using namespace std;

float m=0,n=0,p=0;


void variablesInput()
{
	cout<<"Enter lengths of sides\n";
	cin>>m;
	cin>>n;
	cin>>p;
}


int main()
{
	setlocale(LC_ALL, "Ru");

	variablesInput();


	//test of existance-->sort by ascending then sum first two - if sum>max then true
	//тест на существование треугольника и одновременно определение наибольшей стороны
	//когда мы нашли наибольшую сторону, нам нужно только сравнить её с суммой двух оставшихся меньших

	float temp=0;

	//after this sorting p equals maximal side
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
	
	
	cout<<"\n\n\n";
	
	// p contains the biggest side - so we search for a type of the angle opposite to it
	// р содержит наибольшую сторону - поэтому мы ищем косинус угла именно напротив этой стороны
	float cosinusP=(m*m+n*n-p*p)/(2*m*n); // здесь все переменные вещественные (типа float), поэтому с делением все нормально
	// но было бы нормально, даже если бы была одна вещественная переменная и при этом результат писался бы в вещественную


	if(cosinusP)//если косинус не равен нулю, то 2 варианта - либо угол острый, либо тупой:
		if(cosinusP>0) cout<<"\nThe triangle is acute-angled\n";//остроугольный
		else cout<<"\nThe triangle is obtuse\n";//тупоугольный
	else cout<<"\nThe triangle is right\n";//прямоугольный (здесь остается вариант, в котором косинус равен нулю)

	if(m==p&&m==n&&n==p) cout<<"\nThe triangle is equilateral\n";//равносторонний
	else if(m==p||m==n||n==p) cout<<"\nThe triangle is isosceles\n";//равнобедренный




	int v=1;
	cin>>v;
	return 0;
}