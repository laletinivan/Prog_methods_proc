#pragma once
// ����������� ����������� ����� ������
#include "bush_atd.h"
#include "tree_atd.h"
#include "flower_atd.h"
#include <string>
namespace plants {
	// ���������, ���������� ��� ��������� ������
	struct plant {
		std::string name;
		// �������� ������ ��� ������ �� �����
		int cons;
		enum key { BUSH, TREE, FLOWER };
		key k; // ����	
		enum place_of_growth { Tundra, Taiga, Forest, Steppe, Jungle };
		place_of_growth pog;
		void* data;
	};
} // end plants namespace

