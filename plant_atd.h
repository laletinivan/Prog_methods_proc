#pragma once
// ����������� ����������� ����� ������
#include "bush_atd.h"
#include "tree_atd.h"
#include <string>
namespace plants {
	// ���������, ���������� ��� ��������� ������
	struct plant {
		std::string name;
		// �������� ������ ��� ������ �� �����
		enum key { BUSH, TREE };
		key k; // ����	
		void* data;
	};
} // end plants namespace

