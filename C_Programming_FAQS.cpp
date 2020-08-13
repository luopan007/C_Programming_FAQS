// C_Programming_FAQS.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

// 第一章：关于对象

// 声明一个struct Point3d - C语言风格
typedef struct point3d
{
	float x;
	float y;
	float z;
} Point3d;

// 打印Point3d的函数 - C语言风格
void Point3d_print(Point3d *pPoint3d)
{
	printf("(%g, %g, %g)", pPoint3d->x, pPoint3d->y, pPoint3d->z);
}

// 打印Point3d的宏 - C语言风格
#define Point3d_print(point) \
   printf("(%g, %g, %g)", point->x, point->y, point->z);


// 抽象数据类型 （ADT，abstract data type） - C++语言风格
class Point3D
{
public:
	Point3D(float x = 0.0f, float y = 0.0f, float z = 0.0f)
		: _x(x), _y(y), _z(z) {}

	float GetX() 
	{
		return _x;
	}
	
	float GetY()
	{
		return _y;
	}	
	
	float GetZ()
	{
		return _z;
	}

	void SetX(float tmp) 
	{
		_x = tmp;
	}

	void SetY(float tmp)
	{
		_y = tmp;
	}

	void SetZ(float tmp)
	{
		_z = tmp;
	}

private:
	float _x;
	float _y;
	float _z;
};

// C++ 类的大小计算
class A {};

class B 
{
public:
	B() = default;
	~B() = default;
private:
	static int a;
	int b;
	char c;
};

class C : public A 
{
	int a;
};

class D {
	virtual void f() { std::cout << "D::f" << std::endl; }

	virtual void g() { std::cout << "D::g" << std::endl; }

	virtual void h() { std::cout << "D::h" << std::endl; }
};

class E {
	int a;

	virtual void f() { std::cout << "D::f" << std::endl; }

	virtual void g() { std::cout << "D::g" << std::endl; }

	virtual void h() { std::cout << "D::h" << std::endl; }
};

void test_class_size()
{
	// 64位机器
	std::cout << "The A size without any memeber is: "                     << sizeof(A) << std::endl;	// 1
	std::cout << "The B size with normal and static member is: "           << sizeof(B) << std::endl;	// 8
	std::cout << "The C size with extends A and add normal member is: "    << sizeof(C) << std::endl;	// 4
	std::cout << "The D size with virtual function is: "                   << sizeof(D) << std::endl;	// 8
	std::cout << "The E size with virtual function and normal member is: " << sizeof(E) << std::endl;	// 16
};



int main()
{
	test_class_size();
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
