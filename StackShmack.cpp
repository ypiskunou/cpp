//program by Piskunov Yury MMF IT 19 5122017

#include <iostream>
#include <clocale>
#include <iomanip>
#include <cmath>
#include <ctime>

using namespace std;

const int M=100;
int stck[M]={};
int size=0, tos=0;// size - the size of the whole stack

// ���������� �������� true, ���� ���� ��������, 
bool isFull()
{ 
	return tos==size; 
} 
// ��������� ������� � ����, 
bool push(int ch)
{ 
	if(isFull()) {cout<<"\n Stack overflow! "; return false;}
	stck[tos] = ch; 
	tos++;
	return true;
}
// ���������� �������� true, ���� ���� ����, 
bool isEmpty()
{ 
	return tos==0; 
}
// ������� ������ �� �����, 
int pop()
{ 
	if(isEmpty())
	{ 
		cout<<"\n ���� ����."; 
		return 0; 
	} 
	tos--; 
	return stck[tos]; 
}
//to peek a number at the top of stack
int peek()
{
	if(isEmpty())
	{ 
		cout<<"\n ���� ����."; 
		return 0;
	}
	return stck[tos-1];
}

int main()
{
	setlocale(LC_ALL, "Ru");

	while(1)
	{
		size=5;
		tos=0; //top of stack
		int c=0;

		cout<<"\nEnter number you want to push into stack ";
		cin>>c; push(c);
		cout<<"\nEnter number you want to push into stack ";
		cin>>c; push(c);
		cout<<"\nEnter number you want to push into stack ";
		cin>>c; push(c);
		cout<<"\nLast element "<<peek();
		cout<<"\nElements quantity "<<tos;
		pop();
		cout<<"\nElements quantity "<<tos;
		cout<<"\nElement ejected from the stack "<<pop();
		cout<<"\nElements quantity "<<tos;
		cout<<"\nElement ejected from the stack "<<pop();
		cout<<"\nElements quantity "<<tos;
		pop(); //warninig
		cout<<"\nEnter number you want to push into stack ";
		cin>>c; push(c);
		cout<<"\nElements quantity "<<tos;
		cout<<"\nEnter number you want to push into stack ";
		cin>>c; push(c);
		cout<<"\nEnter number you want to push into stack ";
		cin>>c; push(c);
		cout<<"\nEnter number you want to push into stack ";
		cin>>c; push(c);
		cout<<"\nEnter number you want to push into stack ";
		cin>>c; push(c);
		cout<<"\nElements quantity "<<tos;
		cout<<"\nEnter number you want to push into stack ";
		cin>>c; push(c);
		cout<<"\nElements quantity "<<tos;

		char q=0;
		cout<<"\nEnter q - to quit: ";
		cin>>q;
		if(q=='q') break;
	}
	
	return 0;
}


/*****************
�������� ���������, ������� ��������� ���� ����� ����� �� ������� (������� push,
pop � �������������� ������� � ������ view,
������� �������� �������, ����������� � ������� �����).

������ main ��������� �� ������� ��������� 22 ��������:
* ����������� ������ ���� (N=5, n=0)
* ������ ����� � ����������. ��������� ��� � ���� (push).
* ������ ��� ����� � ����������. ��������� ��� � ����  (push).
* ������ ��� ����� � ����������. ��������� ��� � ����  (push).
* ����������� ������� ����� (view).
* ����������� ���-�� ��������� � �����.
* ������� ������� �� ����� (pop). 
* ����������� ����� ���-�� ��������� � �����.
* ������� ������� �� ����� (pop). ������� ��� �� �����.
* ����������� ����� ���-�� ��������� � �����.
* ������� ������� �� ����� (pop). ������� ��� �� �����.
* ����������� ����� ���-�� ��������� � �����.
* ����������� ������� ������� �� ����� (pop). ������� pop (��� � main) ������ ������� ��������������.
* ������ ����� � ����������. ��������� ��� � ���� (push).
* ����������� ����� ���-�� ��������� � �����.
* ������ ����� � ����������. ��������� ��� � ���� (push).
* ������ ����� � ����������. ��������� ��� � ���� (push).
* ������ ����� � ����������. ��������� ��� � ���� (push).
* ������ ����� � ����������. ��������� ��� � ���� (push).
* ����������� ����� ���-�� ��������� � �����.
* ������ ����� � ����������. ��������� ��� � ���� (push). ������� ���������, ��� ���� ����������
* ����������� ����� ���-�� ��������� � �����.
*****************/