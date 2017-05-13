#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include "prototip.h"
#include <stdio.h>

using namespace std;

net_file::net_file()
{
	cout << "���� � ������� �� ������.\n";
	getch();
}
nehvatka_pamjati::nehvatka_pamjati()
{
	cout << "������ ��������� ������.\n";
	getch();
}
void magazin::set_nazv_mag(char *ch)
{
	strcpy(nazv_mag, ch);
}
void otdel::set_nazv_otd(char *ch)
{
	strcpy(nazv_otd, ch);
}
void tovar::set_pr(char *ch) { strcpy(proizv, ch); }
void tovar::set(char *ch) { strcpy(nazv_tov, ch); }
void tovar::set(float fl) { stoim = fl; }
void tovar::set(int i) { prodano = i; }
float tovar::show_st(void) { return stoim; }
int tovar::show_prod(void) { return prodano; }

menu::menu(char *ch, char *chk)		         //����������� � �����������
{
	bin_f = ch;
	bin_fk = chk;
}
tovar menu::vvodDannyh(void)				//������������ ������ �����
{
	tovar tov;
	int i;
	float fl;
	char *ch_m = new char[20];
	if (ch_m == NULL)
		throw nehvatka_pamjati();        	//��������
	fflush(stdin);
	cout << "\t �������: ";
	cin >> ch_m;
	tov.set_nazv_mag(ch_m);
	fflush(stdin);
	cout << "\t �����: ";
	cin >> ch_m;
	tov.set_nazv_otd(ch_m);
	fflush(stdin);
	cout << "\t �������������: ";
	cin >> ch_m;
	tov.set_pr(ch_m);
	fflush(stdin);
	cout << "\t ������������ ������: ";
	cin >> ch_m;
	tov.set(ch_m);
	cout << "\t ����: ";
	cin >> fl;
	tov.set(fl);
	cout << "\t �������: ";
	cin >> i;
	tov.set(i);
	return tov;
};
void menu::show_shapka(void)				//����� �����
{
	cout << "-----------------------------------------------------------------------------\n";
	cout << "| � |" << setw(13) << "  �������  |" << setw(10) << "  �����  |" << setw(14) << "  ������������� |" << setw(10) << "   �����  |" << setw(12) << "  ����     |" << setw(8) << " �������|\n";
	cout << "-----------------------------------------------------------------------------\n";
}
void menu::show_stroka(int i, tovar tov)	//����� ������ ������ �� �����
{
	cout << "| " << i << " |";
	cout << setw(12) << left << Rus(tov.show_nazv_mag()) << "|";
	cout << setw(9) << Rus(tov.show_nazv_otd()) << "|";
	cout << setw(16) << Rus(tov.show_pr()) << "|";
	cout << setw(10) << Rus(tov.show_nazv()) << "|";
	cout << fixed << setprecision(2) << setw(11) << tov.show_st() << "|";
	cout << setw(8) << tov.show_prod() << "|\n";
	cout << "-----------------------------------------------------------------------------\n";

}
void menu::dob_zap(void)		            //���������� ������ � �������� ����
{
	FILE *fp;
	tovar tov;
	fp = fopen(bin_f, "a+b");
	cout << "\t ������� ������:\n";
	try {						//�������
		tov = vvodDannyh();
		fwrite(&tov, sizeof(tovar), 1, fp);
		fclose(fp);
		cout << "\t ������ ���������\n";
		getch();
	}
	catch (nehvatka_pamjati) {}		//��������
};
void menu::red_zap(void)	//�������������� ���������� � ������
{
	FILE *fp;
	char n_mag[20], n_tov[20];
	tovar tov;
	int fl = 0;
	if ((fp = fopen(bin_f, "r+b")) == NULL)
		throw net_file();
	cout << "\t ������ ������ �������������� ������: \n";
	fflush(stdin);
	cout << "\t\t �������� ��������: ";
	cin >> n_mag;
	fflush(stdin);
	cout << "\t\t ������������ ������: ";
	cin >> n_tov;
	while (fread(&tov, sizeof(tovar), 1, fp) != NULL)
		if ((strcmp(tov.show_nazv_mag(), n_mag) == 0) && (strcmp(tov.show_nazv(), n_tov) == 0)) {
			fl = 1;
			show_shapka();
			show_stroka(1, tov);
			cout << "\t ������� ����� ������:\n";
			tov = vvodDannyh();
			fseek(fp, sizeof(tovar)*(-1), SEEK_CUR);	//�������� �� ������� �����
			fwrite(&tov, sizeof(tovar), 1, fp);
			break;
		}
	fclose(fp);
	if (fl == 0)
		cout << "\t ����� �� ������.\n";
	else cout << "\t ������ ��������.\n";
	getch();
}
void menu::ud_zap(void)					//�������� ������
{
	FILE *fp, *fpk;
	char n_mag[20], n_tov[20];
	tovar tov;
	int fl = 0;
	if ((fp = fopen(bin_f, "r+b")) == NULL)
		throw net_file();
	fpk = fopen(bin_fk, "w+b");	       //�������� ������
	cout << "\t ������ ������ ���������� ������: \n";
	fflush(stdin);
	cout << "\t\t �������� ��������: ";
	cin >> n_mag;
	fflush(stdin);
	cout << "\t\t ������������ ������: ";
	cin >> n_tov;
	while (fread(&tov, sizeof(tovar), 1, fp) != NULL)
		if ((strcmp(tov.show_nazv_mag(), n_mag) != 0) || (strcmp(tov.show_nazv(), n_tov) != 0))
			fwrite(&tov, sizeof(tovar), 1, fpk);
		else fl = 1;
		fclose(fp);
		fclose(fpk);
		fpk = fopen(bin_fk, "r+b");
		fp = fopen(bin_f, "w+b");
		while (fread(&tov, sizeof(tovar), 1, fpk) != NULL)
			fwrite(&tov, sizeof(tovar), 1, fp);
		fclose(fp);
		fclose(fpk);
		if (fl == 0)
			cout << "\t ����� �� ������.\n";
		else cout << "\t ����� ������.\n";
		fpk = fopen(bin_fk, "w+b");
		fclose(fpk);
		remove(bin_fk);				//�������� ���������� �����
		getch();
}
void menu::spis_zap(void)		//������ ���� �������
{
	FILE *fp;
	tovar tov;
	int i = 0;
	if ((fp = fopen(bin_f, "r+b")) == NULL)
		throw net_file();
	show_shapka();
	while (fread(&tov, sizeof(tovar), 1, fp) != NULL)
		show_stroka(++i, tov);
	fclose(fp);
	getch();
}
void menu::poisk_cena(void)		//����� ������� �� ����
{
	FILE *fp;
	tovar tov;
	float stoim;
	int fl = 0, i = 0;
	if ((fp = fopen(bin_f, "r+b")) == NULL)
		throw net_file();
	cout << "\t\t ����: ";
	cin >> stoim;
	while (fread(&tov, sizeof(tovar), 1, fp) != NULL)
		if (tov.show_st() == stoim) {
			if (fl == 0)
				show_shapka();
			fl = 1;
			show_stroka(++i, tov);
		}
	fclose(fp);
	if (fl == 0)
		cout << "\t ����� � ����� ����� �� ������.\n";
	getch();
}
void menu::poisk_nazv(void)		//����� ������� �� ��������
{
	FILE *fp;
	tovar tov;
	char n_tov[20];
	int fl = 0, i = 0;
	if ((fp = fopen(bin_f, "r+b")) == NULL)
		throw net_file();
	fflush(stdin);
	cout << "\t\t ������� �������� ������: ";
	cin >> n_tov;
	while (fread(&tov, sizeof(tovar), 1, fp) != NULL)
		if (strcmp(tov.show_nazv(), n_tov) == 0) {
			if (fl == 0)
				show_shapka();
			fl = 1;
			show_stroka(++i, tov);
		}
	fclose(fp);
	if (fl == 0)
		cout << "\t ����� � ����� ��������� �� ������.\n";
	getch();
}
void menu::poisk_proizv(void)		//����� ������� �� �������������
{
	FILE *fp;
	tovar tov;
	char n_pr[20];
	int fl = 0, i = 0;
	if ((fp = fopen(bin_f, "r+b")) == NULL)
		throw net_file();
	fflush(stdin);
	cout << "\t\t ������� �������� �������������: ";
	cin >> n_pr;
	while (fread(&tov, sizeof(tovar), 1, fp) != NULL)
		if (strcmp(tov.show_pr(), n_pr) == 0) {
			if (fl == 0)
				show_shapka();
			fl = 1;
			show_stroka(++i, tov);
		}
	fclose(fp);
	if (fl == 0)
		cout << "\t ����� ������ ������������� �� ������.\n";
	getch();
}

