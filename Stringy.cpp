//program by Piskunov Yury MMF IT 19 19102017

#include <iostream>
#include <clocale>
#include <iomanip>
#include <cmath>
#include <ctime>

using namespace std;

void printString(char s[])
{
	int i=0;
	while(s[i])
	{
		cout<<s[i];
		i++;
	}

}

int strlen(char s[])
{
	int i=0;
	while(s[i])
		i++;
	return i;
}

char* strcpy(char *dest, char *src)
{
	int i=0;
	dest [strlen(src)];

	while(src[i])
	{
		dest[i]=src[i];
		i++;
	}
	dest[i+1]='\0';
	return dest;
}

char* strncpy(char *dest, char *src, int n)//copy n chars to dest
{

	int i=0;
	dest[n+1];

	for(; i<n; i++)
	{
		dest[i]=src[i];
		i++;
	}
	src[i+1]='\0';

	return dest;
}

//till the end of dest with strlen then copy
char* strcat(char *dest, char *src)// add src in dest
{	
	for(int i=strlen(dest); i<=strlen(dest)+strlen(src); i++)
	{
		dest[i]=src[i];
		i++;
	}
	
	return dest;
}

char* strncat(char *dest, char *src, int n)// add src in dest
{
	int i=strlen(dest);
	for(; i<strlen(dest)+n; i++)
		dest[i]=src[i];

	dest[i+1]='\0';
	
	return dest;
}

enum strcmpOption {cmp_len, cmp_lex};

int strcmp(char *s1, char *s2, strcmpOption strcmpOption=cmp_lex)//return >0, 0< , 0 --- first not matching symbol, 0 - match
{
	switch(strcmpOption)
	{
	case cmp_len:
		{
			if(strlen(s1)<strlen(s2)) return -1;
			else if(strlen(s1)>strlen(s2)) return 1;
			return 0;
		}
		break;
	case cmp_lex:
		{
			int i=0;

			while(s1[i])
			{
				if(s1[i]>s2[i]) return -1;// A is more than B
				if(s1[i]<s2[i])	return 1;
				i++;
			}
			return 0;			
		}
		break;
	}
}

int strchr(char *s, char ch) //index of first match of symbol
{
	int i=0;

	while(s[i])
	{
		if(s[i]==ch) return i+1;
		i++;
	}

	return 0;
}

int strrchr(char *s, char ch) //index of first match of symbol from the right <---
{
	int i=strlen(s)-1;

	while(i+1)
	{
		if(s[i]==ch) return strlen(s)-i;
		i--;
	}

	return 0;
}

int strpbrk(char *s1, char *s2)
{
	int i=0;
	while(s1[i])
	{
		int j=0;
		while(s2[j])
		{
			if(s2[j]==s1[i]) return i;
			j++;
		}
		i++;
	}

	return 0;
}

//****Loop shift <---- to the left




/*
char* delstrBlock(char *s1, int begin, int end)
{
	s1=strncpy();
	int i=0;
	while(s1[i])
	{
		if
		i++;
	}

	return 0;
}*/

size_t strspn(char *s1, char *s2)
{
	int i=0;
	while(s1[i])
	{
		int j=0;
		while(s2[j])
		{
			if(s2[j]!=s1[i]) return i;
			j++;
		}
		i++;
	}

	return 0;
}

bool isLetter(char c)
{
	return ((c>'А'&&c<'я')||(c>'A'&&c<'z')||c=='\'');
}

//Word recognition
void wordIndeciesCapture(char s[], int borders[], int N) // even indicies are beginings, odd - endings of words (for strings)
{
	int i=1, j=0;
	if(isLetter(s[0])) {borders[j]=0; j++;}
	
	while(s[i])
	{
		if((isLetter(s[i])&&!isLetter(s[i-1]))||(isLetter(s[i])&&!isLetter(s[i+1]))) {borders[j]=i; j++;}
		i++;
	}
}

template <typename T>
void printArray(T a[], int n, char delim='\n')
{
	for(int i=0; i<n; i++)
	{
		cout<<delim<<a[i];
	}
}

int main()
{
	setlocale(LC_ALL, "Ru");
	char s[]="Hello dude! How are you?";

	printString(s);
	cout<<'\n';
	
	while(1)
	{		
		
		//cout<<(int)'А'<<' '<<(int)'а'<<' '<<(int)'я'<<' '<<(int)'A'<<' '<<(int)'a'<<' '<<(int)'z'<<(char) -64;//

		const int N=sizeof(s);
		int borders[N]={};
		wordIndeciesCapture(s, borders, N);

		printArray(borders, N, ' ');

		char q=0;
		cout<<"\nEnter q - to quit: ";
		cin>>q;
		if(q=='q') break;
	}


	return 0;
}

/*************

Создать код (для желающих оформить его как функции), который выполняет действия, аналогичные функциям из заголовочного файла <string.h> (<cstring>):
size_t strlen(char *s)
Функция возвращает длину строки т.е. количество символов (без учета символа завершающего нуля).

char* strcpy(char *dest, char *src)
Функция копирует s2 в dest и возвращает dest. В конец строки dest добавляется завершающий нуль. 

char* strncpy(char *dest, char *src, size_t n)
Функция копирует не более n символов из src в  dest и возвращает dest. Нуль-символ в строку dest не добавляется. 

char* strcat(char *dest, char *src)
Функция добавляет src к dest и возвращает dest. В конец результирующей строки добавляется нуль-символ. 

char* strncat(char *dest, char *src, size_t n)
Функция добавляет не более n символов из src к dest и возвращает dest. Первый символ src пишется на место завершающего нуль-символа строки dest. Если длина строки src меньше n, переписываются все символы src. К строке dest добавляется нуль-символ. 

int strcmp(char *sl, char *s2)
Функция сравнивает строки и  возвращает  отрицательное (если s1 меньше s2), нулевое (если s1 равно s2) или положительное (если s1 больше s2) значение.

int strchr(char *s, int ch)
Функция возвращает позицию первого вхождения символа ch в строку s, если его нет, то возвращается 0.

int strrchr(char *s, int ch)
Функция возвращает позицию первого вхождения символа ch в строку s справа, если его нет, возвращает 0.

char* strpbrk(char *sl, char *s2)
Функция возвращает позицию символа, являющийся первым вхождением любого из символов из s2 в строку s1, если его нет, возвращается 0.

size_t strspn(char *sl, char *s2)
Функция возвращает индекс первого символа в  s1, отсутствующего в s2.

2) Написать программу, которая выделяет строки в предложении. Что значит "выделяет" решите сами.
Можно их просто печатать. Можно вычислять длину каждого слова. Можно запоминать позицию начала слова и конца. И т.п.
В main объявить строку так:
char str1[N] = "1Моя строка  с  пробелами.   Новое предложение."; 
char str1[N] = "2Моя строка  с  пробелами в конце.   Новое предложение.   "; 
char str1[N] = "   3Моя строка  с  пробелами.   Новое предложение.    ";

*************/