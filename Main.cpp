#include <iostream>
#include <functional>

//Функторы - классы объекта которых можено использовать вместо функций.


//0-pointer 
//system-memory
//programm-memory
// BSS/BRS
// HEAP
// STACK
// programm-args



int Summ(int a, int b) {
	return a + b;
}
int Multyply(int a, int b) {
	return a * b;
}

using FunctionName = int (*)(int, int);
typedef int (*NewName)(int, int);


void PrintOperation(int Jane, int Jacob, FunctionName Alg) {
	std::cout << "Our operation take params:\n" <<
		"\tJane - " << Jane << '\n' 
		<< "\tJacob - " << Jacob << '\n' 
		<< "With result " << Alg(Jane, Jacob);
}

class Functor {
public:
	Functor(int val):num(val){}

	void operator()(int& val) {
		val = num;
	}
private:
	int num;
};

void OperateArray(int* arr, int length, std::function<void(int&)> alg) {
	for (int i = 0; i < length; i++) {
		alg(arr[i]);
	}
}

void F02(int& j) {
	j = 9;
}



int main() {
	setlocale(0, "");

	int a{ 5 }, b{ 9 };
	std::cout << Summ << " with " << a << " " << b << "args - " << Summ(a,b) << "\n";
	
	std::cout << Multyply << " with " << a << " " << b << "args - " << Multyply(a, b) << "\n";

	auto pFunc = Summ;

	int (*pFunc2)(int, int);
	pFunc = Multyply;
	pFunc2 = Summ;


	PrintOperation(2, 4, Multyply);
	std::cout << '\n';
	PrintOperation(a, b, pFunc2);
	std::cout << '\n';

	int* arr = new int[6] {};
	OperateArray(arr, 6, F02);
	for (int i = 0; i < 6; i++) {
		std::cout << arr[i] << ' ';
	}
	std::cout << '\n';

	Functor funtic(4);
	OperateArray(arr, 6, funtic);
	for (int i = 0; i < 6; i++) {
		std::cout << arr[i] << ' ';
	}
	std::cout << '\n';



	return 0;
}