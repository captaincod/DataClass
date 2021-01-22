#include "Date.h"
bool Date::isLeap(int year)
{
	return (year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0));
};

Date::Date(int _day, int _month, int _year) {
	day = &_day;
	month = &_month;
	year = &_year;
};

Date::~Date() {
	delete day;
	delete month;
	delete year;
}

bool Date::isCorrect() {
	int has31days[7] = { 1,3,5,7,8,10,12 };
	int has30days[4] = { 4,6,9,11 };
	if (*year <= current_year && *year >= 0) {
		if (*month == 2) {
			if (isLeap(*year) && (*day >= 1 && *day <= 29)) return true;
			else if (*day >= 1 && *day <= 28) return true;
			else return false;
		}
		else {
			int* mon = find(begin(has31days), end(has31days), *month);
			if (mon != end(has31days)) {
				if (*day >= 1 && *day <= 31) return true;
				else return false;
			}
			else if (*day >= 1 && *day <= 30) return true;
			else return false;
		}
	}
	else return false;
}
bool Date::isCorrect(int d, int m){
	int has31days[7] = { 1,3,5,7,8,10,12 };
	int has30days[4] = { 4,6,9,11 };
	if (m == 2) {
		if (isLeap(current_year) && (d >= 1 && d <= 29)) return true;
		else if (d >= 1 && d <= 28) return true;
		else return false;
	}
	else {
		int* mon = find(begin(has31days), end(has31days), m);
		if (mon != end(has31days)) {
			if (d >= 1 && d <= 31) return true;
			else return false;
		}
		else if (d >= 1 && d <= 30) return true;
		else return false;
	}

};

string Date::whatDay() {
	/*
	день недели = (день + код месяца + код года) % 7

	код месяца:
	Обычные годы			Високосные			m
	Апрель июль			Январь апрель июль		0
	Январь октябрь			Октябрь				1
	Май								2
	Август				Февраль август			3
	Февраль март ноябрь		Март ноябрь			4
	Июнь								5
	Сентябрь декабрь						6

	код года = (6 + последние две цифры года + последние две цифры года / 4) % 7

	*/
	vector < vector <int> > months_nonLeap = { {4, 7}, {1, 10}, {5}, {8}, {2, 3, 11}, {6}, {9, 12} };
	vector < vector <int> > months_Leap = { {1, 4, 7}, {10}, {5}, {2, 8}, {3, 11}, {6}, {9, 12} };


	int code_month = -1;
	if (isLeap(*year)) {
		for (int i = 0; i < 7; i++) {
			vector<int>::iterator it;
			it = find(months_Leap[i].begin(), months_Leap[i].end(), *month);
			if (it != months_Leap[i].end()) {
				code_month = i;
				break;
			}
		}
	}
	else {
		for (int i = 0; i < 7; i++) {
			vector<int>::iterator it;
			it = find(months_nonLeap[i].begin(), months_nonLeap[i].end(), *month);
			if (it != months_nonLeap[i].end()) {
				code_month = i;
				break;
			}
		}
	}
	if (code_month < 0) throw DateException{};
	int code_year = (6 + (*year % 100) + (*year % 100) / 4) % 7;
	int day_of_week = (*day + code_month + code_year) % 7;

	switch (day_of_week) {
	case 0:
		return "Суббота";  break;
	case 1:
		return "Воскресенье"; break;
	case 2:
		return "Понедельник"; break;
	case 3:
		return "Вторник"; break;
	case 4:
		return "Среда"; break;
	case 5:
		return "Четверг";  break;
	case 6:
		return "Пятница"; break;
	}
}

string Date::whatDay(int day, int month) {
	vector < vector <int> > months_nonLeap = { {4, 7}, {1, 10}, {5}, {8}, {2, 3, 11}, {6}, {9, 12} };
	vector < vector <int> > months_Leap = { {1, 4, 7}, {10}, {5}, {2, 8}, {3, 11}, {6}, {9, 12} };


	int code_month = -1;
	if (isLeap(current_year)) {
		for (int i = 0; i < 7; i++) {
			vector<int>::iterator it;
			it = find(months_Leap[i].begin(), months_Leap[i].end(), month);
			if (it != months_Leap[i].end()) {
				code_month = i;
				break;
			}
		}
	}
	else {
		for (int i = 0; i < 7; i++) {
			vector<int>::iterator it;
			it = find(months_nonLeap[i].begin(), months_nonLeap[i].end(), month);
			if (it != months_nonLeap[i].end()) {
				code_month = i;
				break;
			}
		}
	}
	if (code_month < 0) throw DateException{};
	int code_year = (6 + (current_year % 100) + (current_year % 100) / 4) % 7;
	int day_of_week = (day + code_month + code_year) % 7;

	switch (day_of_week) {
	case 0:
		return "Суббота";  break;
	case 1:
		return "Воскресенье"; break;
	case 2:
		return "Понедельник"; break;
	case 3:
		return "Вторник"; break;
	case 4:
		return "Среда"; break;
	case 5:
		return "Четверг";  break;
	case 6:
		return "Пятница"; break;
	}
}

int Date::JDN(int day, int month, int year) {
	int a = (14 - month) / 12;
	int y = year + 4800 - a;
	int m = month + 12 * a - 3;

	return day + ((153 * m + 2) / 5) + 365 * y + y / 4 - y / 100 + y / 400 - 32045;
};

int Date::interval(int second_day, int second_month, int second_year){
	if (!isCorrect(second_day, second_month)) {
		cout << "ЧТО-ТО НЕ ТАК С ДАТОЙ";
		throw DateException{};
	}
	long first = JDN(*day, *month, *year);
	long second = JDN(second_day, second_month, second_year);
	if (second - first < 0) return first - second;
	else return second - first;
}
int Date::interval(int second_day, int second_month) {
	if (!isCorrect(second_day, second_month)) {
		cout << "ЧТО-ТО НЕ ТАК С ДАТОЙ";
		throw DateException{};
	}
	long first = JDN(*day, *month, *year);
	long second = JDN(second_day, second_month, current_year);
	return second - first;
}
void Date::longDate() {
	int m = *month;
	string zero = "";
	int number_of_digits = 0;
	do {
		++number_of_digits;
		m /= 10;
	} while (m);
	if (number_of_digits == 1) zero = "0";
	cout << *day << "." << zero << *month << "." << *year << endl;
};
void Date::shortDate(){
	string m = "0" + to_string(*month);
	string d = "0" + to_string(*day);
	if (size(d) > 2) d.erase(0, 1); 
	if (size(m) > 2) m.erase(0, 1);
	string y = to_string(*year);
	if (size(y) > 3) y.erase(0, 2);
	cout << d << "." << m << "." << y << endl;
};
void Date::stringDate() {
	string months[12] = { " января ", " февраля ", " марта ", " апреля ", " мая ", " июня ", " июля ", " августа ", " сентября ", " октября ", " ноября ", " декабря " };
	cout << *day << months[*month - 1] << *year << endl;
};

