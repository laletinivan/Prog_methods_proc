#pragma once
namespace plants {
	// ������ ��������� ����� ������ ��� ��������������
	// ���������� ���������� �� ���������
	struct plant;
	// ���������� ��������� �� ������ ����������� �������
	struct elem {
		plant* data;
		elem* next;
	};
	struct container{
		int size;
		elem *head, *tail;
	};
} // end plants namespace
