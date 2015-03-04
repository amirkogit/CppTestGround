#pragma once
class variadic_templates_demo
{
public:
	variadic_templates_demo();
	~variadic_templates_demo();

	void Print() {};

	template<typename T, typename... Types>
	void Print(const T& firstArg, const Types& ...args){
		std::cout << firstArg << std::endl;
		Print(args...);
	}
};

