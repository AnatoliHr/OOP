// OOP.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>		//Подключаемые файлы
#include <conio.h>
#include <windows.h>
#include <locale.h>
#include <string.h>
#include "prototip.h"

using namespace std;

void main(void)
{
	setlocale(LC_ALL, "rus");
	int m;

	menu men("e:\\OOP\\tovary.dat", "e:\\OOP\\tovary_k.dat");

	do {
		system("cls");

		cout << "    Меню:\n";
		cout << " 1. Добавить товар\n";
		cout << " 2. Изменить информацию о товаре\n";
		cout << " 3. Удалить информацию о товаре \n";
		cout << " 4. Вывести информацию о всех товарах\n";
		cout << " 5. Поиск товаров по цене\n";
		cout << " 6. Поиск товаров по названию\n";
		cout << " 7. Поиск товаров по производителю\n";
		cout << " 0. Выход\n";
		cout << ": ";
		cin >> m;
		switch (m) {
		case 1: men.dob_zap(); break;
		case 2: try { men.red_zap(); }
				catch (net_file) {} break;
		case 3: try { men.ud_zap(); }
				catch (net_file) {} break;
		case 4: try { men.spis_zap(); }
				catch (net_file) {} break;
		case 5: try { men.poisk_cena(); }
				catch (net_file) {} break;
		case 6: try { men.poisk_nazv(); }
				catch (net_file) {} break;
		case 7: try { men.poisk_proizv(); }
				catch (net_file) {} break;
		}
	} while (m != 0);
	return;
}

