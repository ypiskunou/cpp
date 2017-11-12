//program by Piskunov Yury MMF IT 19 10102017

#include <iostream>
#include <clocale>
#include <cmath>

using namespace std;

void stateMessage(int store)
{
	cout<<"\nThe lift is at the "<<store<<" store.\n";
}

void up()
{
	cout<<"\nЕду уверх...";
}
void down()
{
	cout<<"\nЕду униз...";
}

void liftAtTheSameStore(bool upMoving)
{
	cout<<"\nДзверы зачыняются... Пасля аб'явы аб зачыненнi дзвярэй уваход забаронены.\nMind your head.";
	if(upMoving) up();
	else down();
	cout<<"\nДзверы адчыняются... See you soon sir\n\n";	
}

void initLiftAtAnotherStore(bool initUpMoving)
{
	cout<<"\nДзверы зачыняются... Пасля аб'явы аб зачыненнi дзвярэй уваход забаронены.\n(На всякий случай - вдруг кто есть)";
	if(initUpMoving) up();
	else down();
	cout<<"\nДзверы адчыняются... Welcome on board sir";
	liftAtTheSameStore(!initUpMoving);//т.е. лифт был первоначально на требуемом этаже приехал и соответственно меняет направление
}


int main()
{
	setlocale(LC_ALL, "Ru");

	int storeDestination=0;
	int storeInitial=1;
	int myPosition=0;

	bool noSense=true;
	bool itWasThere=false;
	bool initUpMoving=false;
	bool upMoving=true;

	/*******
	Действия зависят от трех переменных - положение лифта, положение человека, нажатие кнопки.
	От последних двух зависит - является ли действие бессмысленн.ым или нет.
	Бессмысленно, если
	1) человек на первом и жмет вверх;
	2) человек на нулевом и жмет вниз.
	После проверки на смысл/ошибочность операции дальнейшие действия зависят от того - где находится лифт:
	1) на том же этаже, тогда: двери просто закрываются и лифт едет куда нужно - двери открываются, человек выходит
	2) на другом этаже - двери закрываются, лифт едет к человеку, двери открываются - повторение пункта один (лифт на том же этаже)
	*******/
	while(true)
	{
		noSense=true;	
		stateMessage(storeInitial);
		cout<<"\nEnter a store where you are\n";
		cin>>myPosition;

		//проверка на логичность
		while(noSense)
		{
			cout<<"\nPress button: 1 - to move up, 0 - to move down\n";		
			cin>>storeDestination;
			if(!(storeDestination-myPosition))
			{
				cout<<"Action doesn't have sense because you are at the destination store";
				continue;
			}
			else if(storeDestination<0||storeDestination>1) cout<<"Wrong command";
			else noSense=false;
		}

		//основная часть программы после ввода данных и их проверки на логичность

		//сперва определяем куда мы хотим ехать: вверх или вниз
		if(storeDestination-myPosition>0) upMoving=true;
		else upMoving=false;

		//в зависимости от того, находится ли лифт на том же этаже что и человек - или нет, вызывается одна из функций
		if(myPosition-storeInitial==0)
		{
			liftAtTheSameStore(upMoving);
			
		}
		else
		{
			if(myPosition-storeInitial>0) initUpMoving=true;
			else if(myPosition-storeInitial<0) initUpMoving=false;
			initLiftAtAnotherStore(initUpMoving);
		}

		storeInitial=storeDestination;//меняем положение лифта по его прибытии на требуемый этаж
		

		//storeInitial=rand()%2;	ПОЧЕМУ rand так плохо работает - всегда одно и то же значение 41 и только в цикле меняется	
	}


	int v=1;
	cin>>v;
	return 0;
}



/*

В лифте кнопки с номерами этажей заменены двумя другими кнопками. При нажатии на первую кнопку лифт поднимается на один этаж вверх,
а при нажатии на вторую – опускается на один этаж вниз. Лифт первоначально находится на произвольном этаже с открытыми дверями. 
Он может выполнять 4 операции: открыть/закрыть двери, подняться/опуститься. Запрограммировать управление этим лифтом:
пользователю печатают где сейчас лифт. Он "нажимает" на кнопку в лифте. 
Если действие "невозможно" (например, он на 1м этаже и хочет ехать вверх) 
то просто игнорируется команда. Если действие разрешено, то лифт выполняет некие операции (закрыл-поехал-открыл),
печатает их и опять ждет ввода от пользователя.
P.S. бесконечный цикл ожидающий действия пользователя организовать так:
while(1) {
cout<<"куда едем? 1-вверх, 2 - вниз";
cin>>doing;

// тут ваш код

}

*/