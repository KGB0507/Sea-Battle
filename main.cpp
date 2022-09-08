/////////////////////////////////////////////////////////////////////////////
//Sea Battle (Console game) v. 1.0
/////////////////////////////////////////////////////////////////////////////
//Copyright (c) Kirill Belozerov, 2022. All Rights Reserved
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
//Notes: 
/////////////////////////////////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
//#define DEBUG 1.0


#include <iostream>
#include <string>
#include <time.h>
#include <vector>

const int N = 5;
const int NUMBEROFSHIPS = 5;

using namespace std;


int main()
{
	setlocale(LC_ALL, "rus");
	int x, y, xFire, yFire, count = 0;
	bool gameOver = false;
	//creating and initialization of the map
	int map[N][N];
	for (x = 0; x < N; x++)
	{
		for (y = 0; y < N; y++)
		{
			map[x][y] = 0;
		}
	}

	srand(time(NULL));
	//generating randomly placed ships (single-decked only)
	for (x = 0; x < N; x++)
	{
		for (y = 0; y < N; y++)
		{
			//checking other ships nearly this coordinates
			if (map[x][y - 1] != 1 && map[x][y + 1] != 1 && map[x - 1][y] != 1 && map[x + 1][y] != 1)
			{
				map[x][y] = rand() % 2;
				if (map[x][y] == 1)
				{
					count++;
					if (count == NUMBEROFSHIPS)
					{
						break;
					}
				}
			}
		}
		if (count == NUMBEROFSHIPS)
		{
			break;
		}
	}
	//making fire on the selected coordinates
	while (!gameOver)
	{
		//printing the map
		cout << endl << endl;
		for (int x = 0; x < N; x++)
		{
			cout << "  ";
			for (int y = 0; y < N; y++)
			{
				switch (map[x][y])
				{
				case -2:
					cout << "*";
				case -1:
					cout << "@";
				case 0:
					cout << map[x][y];
				case 1:
					cout << 0;
				}
			}
			cout << endl;
		}
		cout << "ќсталось " << count << " кораблей" << endl;
		cout << "¬ведите координаты дл€ выстрела через пробел: ";
		cin >> xFire >> yFire;
		if (map[xFire][yFire] == 1)
		{
			map[xFire][yFire] = -1;
			count--;
		}
		else
			map[xFire][yFire] = -2;
		system("cls");
	}
	system("pause");
	return 0;
}