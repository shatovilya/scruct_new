#include <iostream>																		//����������� ���������� iostream ��� ����� ������ ����������, �� ������������ ������ �����/������ stdin/stdout (�������)
#include <string>
#include <Windows.h>

#include "route_header.hpp"																//


bool has_only_digits(const std::string check_number)											// ���������� ������� �������� ���������� ��������, ���������� TRUE ���� �������� �������� �����.
{
	return check_number.find_first_not_of("0123456789") == std::string::npos;					// ���������� ����� find_first_not_of() (���� � ������ ������ ������, ������� �� ������������� �� ������ �� ��������, ��������� � ��� ����������), 
																								// std::string::npos �������� ���������� �� ����� ������.
}

void add_route(MARSH TRAFIC[], int arraylength)													// ������� ��� ���������� ������ � ������ TRAFIC, � ����������� ����������� �� �����������.
{
	int i;
	std::string check_number;
	std::cout << "������� � ���������� ���������� ��� ���������� ������� " << std::endl;		// �������� ������ � ��������� �� ����. ������ � ����������� ����� ������ stdout
	for (i = 0; i < unsigned(arraylength); i++)													// ��������� ���� FOR � ��������, � ����������������� ���������� ��������� ������� TRAFIC
	{
		do																						// ��������� ���� WHILE ������� ��������� �� ��� ���,
		{
			std::cout << "����� �������� (������������� ����� �����): ";						// ���� ������� has_only_digits �� ������ �������e FALSE.
			std::cin >> check_number;
			has_only_digits(check_number);
		} while (has_only_digits(check_number) == false);

		TRAFIC[i].NUMER = atoi(check_number.c_str());											// ����������� �������� ��������  �� ������������ ������ ����� �������� TRAFIC[i].NUMER.
		std::cout << "�������� ���������� ������ ��������: ";
		std::cin >> TRAFIC[i].BEGST;
		std::cout << "�������� ��������� ������ ��������: ";
		std::cin >> TRAFIC[i].TERM;
	}
	// ����� ���������� ������� ���������� � ��� ����������
	int r;
	MARSH arr_temp;																				// ��������� ��������������� ���������� ��� ���������� �������� �������� �� ������ ������ ������ � ������� TRAFIC.

	for (i = 0; i < unsigned(arraylength); i++)													// ������ ������� ���������� �� ����� ���������� ����������� ������ � �������
	{

		for (r = 0; r < unsigned(arraylength); r++)
		{
			// ����� ������� ��������� � ������� ���������� �� �������� "����� ������� ����� ������� ���������� ������, ������ ������� ��������"
			if (TRAFIC[r].NUMER > TRAFIC[r + 1].NUMER)
			{
				arr_temp = TRAFIC[r + 1];														// ��������� �������� �������� ��� ������������ �������� ����� � �������.
				TRAFIC[r + 1] = TRAFIC[r];														// ������� �� ������� ����� ������� ������� �����, ������������� �������� ������� �������� ��������� ������ ��������.
				TRAFIC[r] = arr_temp;															// �� ��������� ���������� ����������� �������� ������ ��������. 
			}
		}
	}

}


int lineSearch(MARSH TRAFIC[], int requiredKey, int arraylength)								// ������� ��� ������ � ������� TRAFIC ���������� �� ������ ��������, ���������� ���������� ����������.
{
	for (int i = 0; i < arraylength; i++)													// ���������� ������ ������� ������� TRAFIC � �������� ���������.
	{
		if (TRAFIC[i].NUMER == requiredKey)
			return i;																		// ���� ��� ����� ���������� ����� �������� � �������.
	}
	return 0;																				// ���� ��� ������� ���������� 0.
}

void show_one_route(MARSH TRAFIC[], int arraylength)											// ������� (�� ������������ ��������) ��� ��������� ������������� �������� �� ������� TRAFIC
{

	int requiredKey;
	std::cout << "������� � ���������� ����� �������� ��� ���������: ";
	std::cin >> requiredKey;

	int m = (lineSearch(TRAFIC, requiredKey, arraylength));										// ����� ������� lineSearch � ��������� ���������� 

	if (m == 0)
	{
		std::cout << "������� ����������� � �������" << std::endl;
	}
	else
	{
		std::cout << "������ �� ������ �������:" << std::endl;									// ���� ������� ������, ���������� ���������� � ������ ��������.
		std::cout << "����� ��������" << TRAFIC[m].NUMER << std::endl;
		std::cout << "�������� ���������� ������ ��������: " << TRAFIC[m].BEGST << std::endl;
		std::cout << "�������� ��������� ������ ��������: " << TRAFIC[m].TERM << std::endl;
	}
}


void show_full_route(MARSH TRAFIC[], int arraylength)											// ������� (�� ������������ ��������) ��� ��������� ���� ��������� �� ������� TRAFIC, �������� ���������� � �������.
{
	std::cout << "����� ������� ������� ���������" << std::endl;
	int i;
	for (i = 0; i < unsigned(arraylength); i++)
	{
		std::cout << "����� ��������:" << TRAFIC[i].NUMER << std::endl;
		std::cout << "�������� ���������� ������ ��������: " << TRAFIC[i].BEGST << std::endl;
		std::cout << "�������� ��������� ������ ��������: " << TRAFIC[i].TERM << std::endl;
	}

}