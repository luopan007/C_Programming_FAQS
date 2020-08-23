#pragma once

#include <iostream>
#include <string>
using namespace std;

struct Student
{
	std::string name;
	int score;

	// 重载运算符 小于号
	bool operator<(const Student& other) {
		return score > other.score;
	}

	// 重载运算符 大于号
	bool operator>(const Student& other) {
		return score < other.score;
	}

	// 重载运算符 << 
	friend ostream& operator<<(ostream &os, Student &student) {
		os << "Student:" << student.name << " " << student.score << endl;
		return os;
	}
};