#include "Date.h"
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	/*
	��������� ����������� ���� �������� ������������ � ���������� ���������� ���� ���������� �� ��� ��� �������� � ������� ����
	���� ���� �������� ������, �� ���������� ���� ��������� � ��� ��������, ���� ���� �������� �������, �� ����������� � ���� ��������
	*/
	int d, m, y;
	cout << "������������! �������, ����������, ������� ���� ������� ����� ������: ";
	cin >> d >> m >> y;
	Date currentDate(d, m, y);
	if (currentDate.isCorrect()) {
		currentDate.stringDate();
		currentDate.shortDate();
		currentDate.longDate();
		cout << "������� " << currentDate.whatDay()<<endl;
		int d, m;
		cout << "�������� ���� � ����� ������ ��� ��������. �������. ����� ������: ";
		cin >> d >> m;
		if (currentDate.interval(d, m) == 0) cout << "� ��� ��������!" << endl;
		else if (currentDate.interval(d, m) > 0) cout << "�� ��� �������� �������� " << (currentDate.interval(d, m)) << " ����! ��� ����� " << currentDate.whatDay(d, m);
		else cout << "�� ��� �������� ������ " << (currentDate.interval(d, m)) * (-1)<< " ����";
	}
	else cout << "� ����� ����� ���-�� �� ���..." << endl;
}

