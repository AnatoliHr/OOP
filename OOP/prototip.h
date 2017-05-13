#pragma once

#define WIN32_LEAN_AND_MEAN	
#include <stdio.h>		                
#include <conio.h>
#include <windows.h>
#include <locale.h>
#include <string>

class net_file	                     	//����� ����������
{
public:
	net_file();
};
class nehvatka_pamjati              	//����� ����������
{
public:
	nehvatka_pamjati();
};
class magazin		                	//����� �������
{
	char nazv_mag[20];
public:
	void set_nazv_mag(char *ch);
	char *show_nazv_mag(void) { return nazv_mag; }
	virtual ~magazin() { strcpy(nazv_mag, ""); }
};
class otdel			             		//����� �����
{
private:
	char nazv_otd[20];
public:
	void set_nazv_otd(char *ch);
	char *show_nazv_otd(void) { return nazv_otd; }
	virtual ~otdel() { strcpy(nazv_otd, ""); }
};
class tovar :public magazin, public otdel //����� ����� (������������)
{
private:
	char nazv_tov[20];
	char proizv[20];
	float stoim;
	int prodano;
public:
	void set_pr(char *ch);
	void set(char *ch);
	void set(float fl);
	void set(int i);
	char *show_nazv(void) { return nazv_tov; }
	char *show_pr(void) { return proizv; }
	float show_st(void);
	int show_prod(void);
	virtual ~tovar()
	{
		strcpy(nazv_tov, "");
		strcpy(proizv, "");
		stoim = 0.0;
		prodano = 0;
	}

};
class menu
{
private:
	char *bin_f;
	char *bin_fk;
public:
	menu(char *ch, char *chk);		    //����������� � �����������
	char *Rus(const char * text)		//������������� ������
	{
		char *buf = new char[strlen(text)];
		CharToOemA(text, buf);
		return buf;
	}
	tovar vvodDannyh(void);				//������������ ������ �����
	void show_shapka(void);				//����� ����� ������� �� �����
	void show_stroka(int i, tovar tov);	//����� ������ ������ �� �����
	void dob_zap(void);		            //���������� ������ � �������� ����
	void red_zap(void);	                //�������������� ���������� � ������
	void ud_zap(void);					//�������� ������
	void spis_zap(void);        		//������ ���� �������
	void poisk_cena(void);      		//����� ������� �� ����
	void poisk_nazv(void);      		//����� ������� �� ��������
	void poisk_proizv(void);	        //����� ������� �� �������������
	virtual ~menu() { bin_f = NULL; bin_fk = NULL; } //����������� ����������
};
