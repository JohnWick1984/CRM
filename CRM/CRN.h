#pragma once
#include<iostream>
#include<string>
#include<mysql.h>
#include <Windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
using namespace std;


class User
{
public:
	
	User() {}

	User(int id, string Name, string Lastname, string Patronymic, int Position) :id(id), Name(Name), Lastname(Lastname), Patronymic(Patronymic), Position(Position) {}



private:
	int id;
	string Name;
	string Lastname;
	string Patronymic;
	int Position;


};

int main()
{
    setlocale(LC_ALL, "Rus");

    //���������� � ����� ������ MySQL � ����� ������ ������
    cout << "����� �������� ���� ������ �������: " << "\n";

    MYSQL* conn;
    MYSQL_RES* res;
    MYSQL_ROW row;

    int i = 0;

    // �������� ���������� ����������
    conn = mysql_init(NULL);
    if (conn == NULL)
    {
        // ���� ���������� �� ������� � ������� ��������� �� ������
        fprintf(stderr, "������: MySQL ���������� �� ������\n");
        //exit(1); //���� ������������ ������� ����������
    }
    // ������������ � �������
    if (!mysql_real_connect(conn, "localhost", "root", "", "User", NULL, NULL, 0))
    {
        // ���� ��� ����������� ���������� ���������� � ��������
        // ���� ������ ������� ��������� �� ������
        fprintf(stderr, "������: ��� ���������� � ����� ������ %s\n", mysql_error(conn));
    }
    else
    {
        // ���� ���������� ������� ����������� ������� ����� - "�������!"
        fprintf(stdout, "���������� � ����� MySQL �������!\n");
    }
    mysql_set_character_set(conn, "cp1251");//��� ����������� ���������
    //������� ���������� �� ��������� �� ������, �� ��������� ��� latin1
    cout << "���������: " << mysql_character_set_name(conn) << endl;

    mysql_query(conn, "SELECT id, surname, name, Patronymic, position FROM User"); //������ ������ nameMark � ������� �� ����� catalogwallpaper =)

    if (res = mysql_store_result(conn)) {
        while (row = mysql_fetch_row(res)) {
            for (i = 0; i < mysql_num_fields(res); i++) {
                cout << row[i] << "\n"; //������� ��� ��� ���� � ���� ����� ����
            }
            cout << endl;
        }
    }
    else fprintf(stderr, "%s\n", mysql_error(conn));

    // ��������� ���������� � �������� ���� ������
    mysql_close(conn);
}
