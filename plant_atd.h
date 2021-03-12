#pragma once
// Подключение необходимых типов данных
#include "bush_atd.h"
#include "tree_atd.h"
#include <string>
namespace plants {
	// структура, обобщающая все имеющиеся фигуры
	struct plant {
		std::string name;
		// значения ключей для каждой из фигур
		enum key { BUSH, TREE };
		key k; // ключ	
		enum place_of_growth { Tundra, Taiga, Forest, Steppe, Jungle };
		place_of_growth pog;
		void* data;
	};
} // end plants namespace

