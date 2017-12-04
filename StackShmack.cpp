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

// Возвратить значение true, если стек заполнен, 
bool isFull()
{ 
	return tos==size; 
} 
// Поместить символы в стек, 
bool push(int ch)
{ 
	if(isFull()) {cout<<"\n Stack overflow! "; return false;}
	stck[tos] = ch; 
	tos++;
	return true;
}
// Возвратить значение true, если стек пуст, 
bool isEmpty()
{ 
	return tos==0; 
}
// Извлечь символ из стека, 
int pop()
{ 
	if(isEmpty())
	{ 
		cout<<"\n Стек пуст."; 
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
		cout<<"\n Стек пуст."; 
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
Дописать программу, которая реализует стек целых чисел на массиве (функции push,
pop и дополнительную функцию с именем view,
которая печатает элемент, находящийся в вершине стека).

Внутри main выполнить по очереди следующие 22 действия:
* Подготовить пустой стек (N=5, n=0)
* Ввести число с клавиатуры. Поместить его в стек (push).
* Ввести еще число с клавиатуры. Поместить его в стек  (push).
* Ввести еще число с клавиатуры. Поместить его в стек  (push).
* Распечатать вершину стека (view).
* Распечатать кол-во элементов в стеке.
* Достать элемент из стека (pop). 
* Распечатать новое кол-во элементов в стеке.
* Достать элемент из стека (pop). Вывести его на экран.
* Распечатать новое кол-во элементов в стеке.
* Достать элемент из стека (pop). Вывести его на экран.
* Распечатать новое кол-во элементов в стеке.
* Попробовать достать элемент из стека (pop). Функция pop (или в main) должна вывести предупреждение.
* Ввести число с клавиатуры. Поместить его в стек (push).
* Распечатать новое кол-во элементов в стеке.
* Ввести число с клавиатуры. Поместить его в стек (push).
* Ввести число с клавиатуры. Поместить его в стек (push).
* Ввести число с клавиатуры. Поместить его в стек (push).
* Ввести число с клавиатуры. Поместить его в стек (push).
* Распечатать новое кол-во элементов в стеке.
* Ввести число с клавиатуры. Поместить его в стек (push). Увидеть сообщение, что стек переполнен
* Распечатать новое кол-во элементов в стеке.
*****************/