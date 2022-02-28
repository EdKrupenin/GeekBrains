#include <iostream>
#include <set>
#include <iterator>
#include <vector>
#include <algorithm>
#include <map>
#include <string>


template<class Container>
void print_container(Container input)
{
	for (const auto& element : input) {
		std::cout << element << " ";
	}
	std::cout << std::endl;
}


/// <summary>
/// Функция, которая принимаети выводящую в консоль список уникальных слов.
/// </summary>
/// <typeparam name="Iterator">Тип итераторов</typeparam>
/// <param name="begin">итераторы на начало последовательности слов</param>
/// <param name="end">итераторы на конец последовательности слов</param>
template<class Iterator>
void uniq_word(Iterator begin, Iterator end)
{
	using value_type = typename std::iterator_traits<Iterator>::value_type; //Определяем тип контейнера
	std::set<value_type> set_word; //Обеспечит уникальность слов
	std::for_each(begin, end, [&set_word](const auto& element) {set_word.insert(element); }); //Заполняем множество
	print_container(set_word);
}


/// <summary>
/// Cчитывает данные введенные пользователем
/// из стандартного потока ввода и разбивает их на предложения.
/// Далее выводит пользователю все предложения, отсортировав их по длине.
/// </summary>
void textFunction()
{
	std::string str;
	std::multimap<int, std::string> proposition{};
	for (std::string line; std::getline(std::cin, line, '.'); ) {
		proposition.insert({ line.size(), line });
	}
	for (const auto& element : proposition) {
		std::cout << element.second << ". The length of the sentence is " << element.first << std::endl;
	}
}

int main()
{
	std::vector<int> vector_int{ 1,2,3,4,5,6,6,7 };
	uniq_word(vector_int.begin(), vector_int.end());
	textFunction();

	
	std::cout << "Hello World!\n";
}
