// OOP.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>		//������������ �����
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

		cout << "    ����:\n";
		cout << " 1. �������� �����\n";
		cout << " 2. �������� ���������� � ������\n";
		cout << " 3. ������� ���������� � ������ \n";
		cout << " 4. ������� ���������� � ���� �������\n";
		cout << " 5. ����� ������� �� ����\n";
		cout << " 6. ����� ������� �� ��������\n";
		cout << " 7. ����� ������� �� �������������\n";
		cout << " 0. �����\n";
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

