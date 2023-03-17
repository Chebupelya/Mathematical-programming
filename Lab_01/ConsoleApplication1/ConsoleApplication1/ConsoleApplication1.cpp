#include "stdafx.h"
#include "Auxil.h"                            // вспомогательные функции
#include <chrono>

#define  CYCLE  250000                      // количество циклов  

int main()
{
	setlocale(LC_ALL, "rus");

	int av1 = 0; double av2 = 0;
	clock_t  t1 = 0, t2 = 0;


	auxil::start();                          // старт генерации 
	t1 = clock();                            // фиксация времени 
	for (long long i = 0; i < CYCLE; i++)
	{
		av1 += (int)auxil::iget(-100, 100); // сумма случайных чисел 
		av2 += auxil::dget(-100, 100);         // сумма случайных чисел 
	}
	t2 = clock();                            // фиксация времени 

	std::cout << "количество циклов:         " << CYCLE;
	std::cout << "\nсреднее значение (int):    " << av1 / CYCLE;
	std::cout << "\nсреднее значение (double): " << av2 / CYCLE;
	std::cout << "\nпродолжительность (у.е):   " << (t2 - t1);
	std::cout << "\n                  (сек):   "
		<< ((double)(t2 - t1)) / ((double)CLOCKS_PER_SEC);
	std::cout << std::endl;
	system("pause");


	int numbers = 35;

	auto begin = std::chrono::steady_clock::now();
	
	auxil::recursion_fibonachi(numbers);
	
	auto end = std::chrono::steady_clock::now();

	auto elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

	std::cout << "количество циклов:         " << numbers;
	/*std::cout << "\nсреднее значение (int):    " << av1 / CYCLE;
	std::cout << "\nсреднее значение (double): " << av2 / CYCLE;*/
	std::cout << "\nпродолжительность (у.е):   " << (elapsed_ms.count());
	std::cout << std::endl;
	system("pause");

	return 0;
}