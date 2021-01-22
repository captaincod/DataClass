#include "Date.h"
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	/*
	Программа запрашивает дату рождения пользователя и возвращает количество дней оставшихся до его дня рождения в текущем году
	Если день рождения прошел, то количество дней прошедших с дня рождения, если день рождения сегодня, то поздравляет с днем рождения
	*/
	int d, m, y;
	cout << "Здравствуйте! Введите, пожалуйста, текущую дату числами через пробел: ";
	cin >> d >> m >> y;
	Date currentDate(d, m, y);
	if (currentDate.isCorrect()) {
		currentDate.stringDate();
		currentDate.shortDate();
		currentDate.longDate();
		cout << "Сегодня " << currentDate.whatDay()<<endl;
		int d, m;
		cout << "Назовите день и месяц Вашего дня рождения. Числами. Через пробел: ";
		cin >> d >> m;
		if (currentDate.interval(d, m) == 0) cout << "С Днём Рождения!" << endl;
		else if (currentDate.interval(d, m) > 0) cout << "До Дня Рождения осталось " << (currentDate.interval(d, m)) << " дней! Это будет " << currentDate.whatDay(d, m);
		else cout << "Со Дня Рождения прошло " << (currentDate.interval(d, m)) * (-1)<< " дней";
	}
	else cout << "С Вашей датой что-то не так..." << endl;
	
	//пример с секундами
	Date first(22, 1, 2021, 11, 40, 30);
	cout << first.timeInterval(24, 1, 2021, 11, 40, 20) << endl;
	
}

