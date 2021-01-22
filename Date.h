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
	int* hours;
	int* minutes;
public:

	Date(int _day, int _month, int _year = current_year, int _hours = 0, int _minutes = 0);

	~Date();

	bool isCorrect(); // Проверяет корректность даты
	bool isCorrect(int d, int m);
	bool isCorrectTime(int hour, int minutes);

	string whatDay(); // Вычисляет день недели для заданной даты
	string whatDay(int day, int month);

	int interval(int second_day, int second_month, int second_year); // Количество дней между датами
	int interval(int second_day, int second_month);

	string timeInterval(int second_day, int second_month, int second_year = current_year, int second_hours = 0, int second_minutes = 0);

	void longDate(); // Выводит в формате 1.01.2001

	void shortDate(); // 01.01.01

	void stringDate(); // 1 января 2001

	bool isLeap(int year); // Проверяет на високосность

	int JDN(int day, int month, int year); // Вычисление номера юлианского дня по дате григорианского календаря

	
};

class DateException {};





