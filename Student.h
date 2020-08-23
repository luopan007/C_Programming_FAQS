#pragma once

#include <iostream>
#include <string>
using namespace std;

struct Student
{
	std::string name;
	int score;

	// ��������� С�ں�
	bool operator<(const Student& other) {
		return score > other.score;
	}

	// ��������� ���ں�
	bool operator>(const Student& other) {
		return score < other.score;
	}

	// ��������� << 
	friend ostream& operator<<(ostream &os, Student &student) {
		os << "Student:" << student.name << " " << student.score << endl;
		return os;
	}
};