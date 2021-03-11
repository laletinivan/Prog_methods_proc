#pragma once
#include "plant_atd.h"
namespace plants {
	class flower : public plant {
		enum type { Home, Garden, Wild };
		type t;
	public:
		// переопределяем интерфейс класса
		void InData(ifstream& ifst); // ввод
		void Out(ofstream& ofst); // вывод
		flower() {} // создание без инициализации.
	};
} // end plants namespace
