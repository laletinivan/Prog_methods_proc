#pragma once
namespace plants {
	// «нание структуры самой фигуры дл€ представленной
	// реализации контейнера не требуетс€
	struct plant;
	// ѕростейший контейнер на основе одномерного массива
	struct elem {
		plant* data;
		elem* next;
	};
	struct container{
		int size;
		elem *head, *tail;
	};
} // end plants namespace
