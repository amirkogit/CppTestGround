#include <iostream>
#include "initializer_demo.h"
#include "range_based_for_loop_demo.h"
#include "variadic_templates_demo.h"
#include "template_demo.h"
#include "lamda_demo.h"
#include "explicit_initialization_demo.h"

void InitializerDemo()
{
	std::cout << "Initializer Demo\n";

	Initializer_Demo id1(2, 3);
	id1.PrintSelf();

	Initializer_Demo id2{ 1, 2, 3, 4, 5, 6 };
	id2.PrintSelf();

	Initializer_Demo id3{ 2, 3 };
	id3.PrintSelf();
}

void RangeBasedForLoopDemo()
{
	std::cout << "Range based for loop Demo\n";

	range_based_for_loop_demo rangedemo;
	rangedemo.MultiplyVectorElements();
	rangedemo.AddAllArrayElements();
}

void VariadicTemplatesDemo()
{
	std::cout << "Variadic templates demo\n";

	variadic_templates_demo vtd;
	vtd.Print(7.5, "hello", "world", 45);
}

void TemplateDemo()
{
	std::cout << "Templates demo\n";

	Template_Demo td;
	td.Sum(9, 1);
	td.Sum(7.3, 2.5);
	//td.Sum("Hello", "World");
}

void LamdaDemo()
{
	std::cout << "Lambda demo\n";

	Lamda_Demo ld;
	ld.SimpleLamda();

	ld.ParameterizedLamda();

	ld.ReturnTypeLambda();

	ld.CaptureLambda();

	ld.MutableLambda();

	ld.ReturnLambda();
}

void ExplicitInitializationDemo()
{
	Explicit_Initialization_Demo eid;
	eid.Fundamental_Types_Explicit_Initialization();
}

int main()
{
//	InitializerDemo();

//	RangeBasedForLoopDemo();

//	VariadicTemplatesDemo();

//	TemplateDemo();

//	LamdaDemo();

	ExplicitInitializationDemo();


	getchar();
	return 0;
}