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

// 错误的指针声明 - 此处指针是 p, *p 是指针的解引用
// char *p;
// *p = malloc(10);

// 声明和定义的区别:
// 声明和定义的区别在于: 声明只表明变量的类型, 定义真正分配空间和赋初值

// 比如: 这就是声明
extern int i;
extern int f();

// 比如:这就是定义
int i = 0;
int f() {
	return i;
}

// 注意: extern 只对数据声明有意义,对于函数声明,仅仅是一种提示


// typedef关键字和 #define
typedef char* String_t;
#define String_d char*
String_t s1, s2;
String_d s3, s4;
// 在这个例子中:s1 s2 s3 军是char* 类型, s4是char类型

// 定义一个链表
struct Node {
	char* item;
	struct Node *next;
};

typedef struct Node *NodePtr;

// typedef 与函数指针
typedef int(*funcPtr)(); // 定义了一个类型funcPtr, 表示指向返回值为int型(参数未指明)的函数的指针
funcPtr fp1, fp2; // 声明两个函数指针

// 字符串字面量
char aa[] = "string literal"; // 数组初始化方式
const char *paa = "string literal"; // 指针初始化方式3


// 第二章: 结构体、联合和枚举
struct x1 {};
typedef struct {} x2;
// x1 只是一个结构标签
// x2 是类型定义
// 类型定义之后的,都可以当成类型使用,比如:
x2 b;


// 第四章: 指针
// 后缀 ++ 和 -- 操作符本质上是一元操作符,因此, ++ 和 -- 优先级比 * 高


// 泛型编程
template<class T>
T max(T t1, T t2) {
	return t1 > t2 ? t1 : t2;
}

template<class T>
class TemplateTest {
public:
	T max(T t1, T t2) {
		return t1 > t2 ? t1 : t2;
	}
};

// 利用泛型计算和
template<int n>
struct Sum {
	enum Value { N = Sum<n - 1>::N + n };
};

template<>
struct Sum<1> {
	enum Value { N = 1 };
};

// 该函数的耗时为 0
// 泛型是在编译器完成的
void test_template_sum() {
	std::cout << "1+2+...+100 = " << Sum<100>::N << std::endl;
}

// STL : vector/list/deque
#include <vector>
#include <list>
#include <queue>
#include <stack>

void Print_Element(int element) {
	std::cout << element << " ";
}

void test_STL() {
	using namespace std;

	// 1.使用array初始化vector/list/deque
	int array[] = { 1,2,3,4,5 };
	vector<int> vector_from_array = { array, array + 4 };
	list<int>  list_from_array = { array, array + 4 };
	deque<int> deque_from_array = { array, array + 4 };

	// 2. 使用for_each遍历vector/list/deque, 并输出元素值
	// for_each 参数
	// 参数1：vector/list/deque的开始元素
	// 参数2：vector/list/deque的结束元素
	// 参数3：处理vector/list/deque的元素的函数指针
	for_each(vector_from_array.begin(), vector_from_array.end(), Print_Element);
	cout << endl;
	for_each(list_from_array.begin(), list_from_array.end(), Print_Element);
	cout << endl;
	for_each(deque_from_array.begin(), deque_from_array.end(), Print_Element);
	cout << endl;

	// 3.由deque创建queue/stack
	queue<int> queue_from_deque(deque_from_array); // 队列: 先进先出
	stack<int> stack_from_deque(deque_from_array); // 栈:   先进后出
	
	// 4.由数组创建priority_queue
	priority_queue<int> priority_queue_from_array = { array, array + 4 }; // 优先队列: 按优先级

	// 5.输出队列/栈和优先队列
	while (!queue_from_deque.empty()) {
		cout << "queue_from_deque front element: " << queue_from_deque.front() << endl; // 该函数只会返回队列头部元素,并不会移除
		queue_from_deque.pop(); // 需要使用pop函数移除队列头部元素
	}
	
	while (!stack_from_deque.empty()) {
		cout << "stack_from_deque top element: " << stack_from_deque.top() << endl; // 该函数只会返回栈顶元素,并不会移除
		stack_from_deque.pop(); // 需要使用pop函数移除队列头部元素
	}

	while (!priority_queue_from_array.empty()) {
		cout << "priority_queue_from_array top element: " << priority_queue_from_array.top() << endl; // 该函数只会返回优先队列头部元素,并不会移除
		priority_queue_from_array.pop(); // 需要使用pop函数移除队列头部元素
	}
}

// STL - map
#include <map>
using namespace std;

void test_map() {
	// 1. 声明一个map
	map<string, double> studentScores;

	// 2. 往map里面存储数据
	studentScores["LiMing"] = 96.0;
	studentScores["LiHong"] = 92.0;
	studentScores.insert(pair<string, double>("zhangsan", 100.0));
	studentScores.insert(pair<string, double>("lisi", 98.6));
	studentScores.insert(pair<string, double>("wangwu", 95.0));
	studentScores.insert(map<string, double>::value_type("wangwu", 95.0));

	// 3. 使用的for_each打印 - 找不到 cout 标识符

	// 4. 采用迭代器查找指定key
	map<string, double>::iterator iter;
	iter = studentScores.find("wangwu");
	if (iter != studentScores.end()) {
		cout << "Found the score is " << iter->second << endl;
	}
	else {
		cout << "Didn't find the key." << endl;
	}

	// 5.采用迭代器遍历
	iter = studentScores.begin();
	while (iter != studentScores.end())
	{
		cout << ":" << iter->second << endl;
		iter++;
	}

}

// 仿函数：本质就是类重载了operator(),创建一个具备函数能力的对象
#include <algorithm>

// C++ 原始函数
bool MySort(int a, int b) {
	return a < b;
}

void Display(int a) {
	cout << a << " ";
}

// C++模板函数
template<class T>
inline bool MySortT(T const& a, T const& b) {
	return a < b;
}

template<class T>
inline void DisplayT(T const& a) {
	cout << a << " ";
}

// C++ 仿函数
struct SortF 
{
	bool operator() (int a, int b) {
		return a < b;
	}
};

struct DisplayF
{
	void operator() (int a) {
		cout << a << " ";
	}
};

// C++仿函数模板
template<class T>
struct SortTF
{
	inline bool operator() (T const& a, T const& b) const {
		return a < b;
	}
};

template<class T>
struct DisplayTF
{
	inline void operator() (T const& a) const {
		cout << a << " ";
	}
};

void test_imitate_function() {
	// C++方式
	int arr[] = { 4, 3, 2, 1, 7 };
	sort(arr, arr + 5, MySort);
	for_each(arr, arr + 5, Display);
	cout << endl;

	// C++泛型
	int arr2[] = { 4, 3, 2, 1, 7 };
	sort(arr2, arr2 + 5, MySortT<int>);
	for_each(arr2, arr2 + 5, DisplayT<int>);
	cout << endl;

	// C++仿函数
	int arr3[] = { 4, 3, 2, 1, 7 };
	sort(arr3, arr3 + 5, SortTF<int>());
	for_each(arr3, arr3 + 5, DisplayTF<int>());
	cout << endl;

	// C++仿函数模板
	int arr4[] = { 4, 3, 2, 1, 7 };
	sort(arr4, arr4 + 5, SortF());
	for_each(arr4, arr4 + 5, DisplayF());
	cout << endl;
}

// STL算法
#include <algorithm>
#include <functional>
#include <numeric>

void test_stl_algorithm() {
	int ones[] = { 1, 2, 3, 4, 5 };
	int twos[] = { 10, 20, 30, 40, 50 };
	int results[5];
	transform(ones, ones + 5, twos, results, std::plus<int>()); // 数组元素依次相加并返回
	for_each(results, results + 5,
		[](int a)->void { // 中括号接受外部参数，小括号是内部参数，花括号是函数体
		cout << a << endl; }); // lambda表达式（匿名函数）
	cout << endl;

	// find
	int arr[] = { 0, 1, 2, 3, 3, 4, 4, 5, 6, 6, 7, 7, 7, 8 };
	int len = sizeof(arr) / sizeof(arr[0]);
	vector<int> iA(arr + 2, arr + 6);   // {2,3,3,4}
	cout << std::count(arr, arr + len, 6) << endl; // 统计6的个数
	cout << std::count_if(arr, arr + len, std::bind2nd(std::less<int>(), 7)) << endl; // 统计 < 7 的个数
	cout << std::binary_search(arr, arr + len, 9) << endl;   // 9找不到
	cout << *std::search(arr, arr + len, iA.begin(), iA.end()) << endl; // 查找子序列
}

// 1.排序算法

#include "SortFunction.h"
#include "Student.h"
#include "SortTestHelper.h"

void testSort() {
	int arr[10] = { 10,9,8,7,6,5,4,3,2,1 };
	SortTestHelper::testSort("Selection Sort", SortFunction::selectionSort, arr, 10);
	
	Student students[4] = { {"D",98},{"C",100},{"B",88},{"A",88} };
	SortTestHelper::testSort("Selection Sort", SortFunction::selectionSort, students, 4);

	int arrayLenght = 100000;
	int *array = SortTestHelper::generateRandomArray(arrayLenght, 0, arrayLenght);
	SortTestHelper::testSort("Selection Sort", SortFunction::selectionSort, array, arrayLenght);
	delete[] array;
}


int main()
{
	test_class_size();
	test_template_sum();
	test_STL();
	test_map();
	test_imitate_function();
	test_stl_algorithm();
	testSort();

	return 0;
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
