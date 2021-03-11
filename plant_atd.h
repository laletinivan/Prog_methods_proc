#pragma once
// Подключение необходимых типов данных
#include "bush_atd.h"
#include "tree_atd.h"
#include "flower_atd.h"
#include <string>
namespace plants {
	// структура, обобщающая все имеющиеся фигуры
	struct plant {
		std::string name;
		// значения ключей для каждой из фигур
		enum key { BUSH, TREE, FLOWER };
		key k; // ключ	
		void* data;
	};
} // end plants namespace

