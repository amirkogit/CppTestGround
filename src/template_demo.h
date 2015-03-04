#pragma once
class Template_Demo
{
public:
	Template_Demo();
	~Template_Demo();

	template<typename T1, typename T2>
	void Sum(const T1& firstArg, const T2& secondArg);
};

template<typename T1, typename T2>
void Template_Demo::Sum(const T1& firstArg, const T2& secondArg)
{
	std::cout << "\nSum = " << (firstArg + secondArg);
}


