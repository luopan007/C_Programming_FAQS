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


// 编码风格
// 1. 类、结构体、枚举、联合体、作用域、函数 - 大驼峰
// 2. 全局变量、局部变量、函数参数、成员变量 - 小驼峰
// 3. 宏、常量、枚举值、goto标签 - 全大写，下滑线分割
// 4. 全局变量应增加 'g_' 前缀，静态变量命名不需要加特殊前缀
// 5. 行宽不超过 120 个字符
// 6. 使用空格进行缩进，每次缩进4个空格
// 7. 类访问控制块的声明依次序是 public:,protected:,private:，缩进和 class 关键字对齐
// 8. 不要在头文件中或者#include之前使用using导入命名空间


// 为避免隐式转换，将单参数构造函数声明为explicit
class ExplicitTest {

public:
	ExplicitTest(const std::string& name) : name(name)
	{
	}
private:
	std::string name;
};

void ExplicitDemo(const ExplicitTest &ex) {}

void test_explicit() {
	std::string test = "test";
	//ExplicitDemo(test); // 添加 explicit 修饰，编译不通过，test是string类型 与 ExplicitTest 不匹配
	ExplicitDemo(test); // 去掉 explicit 修饰 编译通过 可以执行  让人疑惑： string类型居然可以传入ExplicitTest类型中
}

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
