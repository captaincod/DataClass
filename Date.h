#pragma once
#include <iostream>
#include <vector>
#include <ctime>
#include <string>

using namespace std;

const int current_year = 2021;

class Date {
	int* day;
	int* month;
	int* year;
public:

	Date(int _day, int _month, int _year = current_year);

	~Date();

	bool isCorrect(); // ��������� ������������ ����
	bool isCorrect(int d, int m);

	string whatDay(); // ��������� ���� ������ ��� �������� ����
	string whatDay(int day, int month);

	int interval(int second_day, int second_month, int second_year); // ���������� ���� ����� ������
	int interval(int second_day, int second_month);

	void longDate(); // ������� � ������� 1.01.2001

	void shortDate(); // 01.01.01

	void stringDate(); // 1 ������ 2001

	bool isLeap(int year); // ��������� �� ������������

	int JDN(int day, int month, int year); // ���������� ������ ���������� ��� �� ���� �������������� ���������
};

class DateException {};


