//Program outputs symbols according to their ASCII numeration
/*by Yury Piskunov MMF IT 19*/

#include <iostream>
using namespace std;

int main()
{
	cout<<"Hello world\n";

	for (int i = 32; i < 128; i++)
	{
		cout<<(char) i<<"  "<<i<<'\n';
	}

	int a=1;
	cin>>a;
	return 0;
}