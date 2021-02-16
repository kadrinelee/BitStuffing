/*
Name: Kadrine Lee-Taylor
Lab 4 - Bit Stuffing 
Student #: 102-399-201
Class Section: DCF255 NDD
Professor: Stan Szlapetis
Date: February 8th, 2021
*/


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <windows.h>


void colour(int colour) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colour);
}

int main() {
	std::vector<int> m_data = {0,1,1,1,1,1,1,0,1,1,1,1,1,1,0};
	std::vector<int>b_flag = {0,1,1,1,1,1,1,0};
	std::vector<int>e_flag = {0,1,1,1,1,1,1,0};
	std::vector<int>::iterator m_it;
	unsigned int i = 0;
	int m_counter = 0;

	colour(14);
	std::cout << "Before stuffing:";
	for (i = 0; i < m_data.size(); i++) {
		std::cout <<' '<< m_data[i];
	}

	std::cout <<" -- "<< m_data.size() << " characters" << std::endl;
	for (i = 0; i <m_data.size(); i++) {
		if (m_data[i] == 1) {
			m_counter++;

			if (m_counter == 5 ) {
				auto it = m_data.begin();
				m_data.insert(it + i+1, 0);
			}
		}
		else {
			m_counter = 0;
		}
	}

	std::cout << "After stuffing: ";
	colour(4);

	for (auto it = m_data.begin(); it != m_data.end(); ++it) {
		std::cout<<' '<<  *it;
	}

	colour(14);
	std::cout<<" -- "<< m_data.size() << " characters" << std::endl;


	std::cout << "After framing:  ";
	m_data.insert(m_data.begin(), b_flag.begin(), b_flag.end());
	m_data.insert(m_data.end(), e_flag.begin(), e_flag.end());

	colour(1);
	for (i = 0; i < b_flag.size(); i++) {
		std::cout << " "  << m_data.at(i);
	}

	colour(14);
	for (i = b_flag.size(); i < m_data.size() - b_flag.size(); i++) {
		std::cout << " " << m_data.at(i);
	}

	colour(1);
	for (i = m_data.size() - e_flag.size(); i < m_data.size(); i++) {
		std::cout << " " << m_data.at(i);
	}

	std::cout << '\n';
	colour(14);

	return 0;
}



