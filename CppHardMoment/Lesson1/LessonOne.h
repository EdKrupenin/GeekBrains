//
// Created by edkru on 18.11.2021.
//

#ifndef LESSON1_LESSONONE_H
#define LESSON1_LESSONONE_H
#include <iostream>
#include <string>
#include <utility>
#include <tuple>
#include <fstream>
#include <vector>
#include <regex>
#include <optional>

using namespace std;

struct Persons{
    string surname{};
    string name{};
    optional<string> patronymic{};
    Persons()= default;
    Persons(string Surname,string Name, optional<string> Patronymic = nullopt)
            : surname(move(Surname)), name(move(Name)), patronymic(move(Patronymic))
    {}
    friend std::ostream& operator<< (std::ostream &out, const Persons &person);
    friend bool operator==(const Persons& left, const Persons& right);
    friend bool operator<(const Persons& left, const Persons& right);
};

struct PhoneNumber{
    int countryCode {};
    int cityCode {};
    string number {};
    optional<int> additionalNumber {};
    PhoneNumber()= default;
    PhoneNumber(int coCode, int ciCode, string num, optional<int> addNum = nullopt) :
            countryCode(coCode), cityCode(ciCode), number(move(num)),
			additionalNumber(move(addNum))
    {}
    friend ostream& operator<< (ostream &out, const PhoneNumber &phone);
    friend bool operator==(const PhoneNumber& left, const PhoneNumber& right);
    friend bool operator<(const PhoneNumber& left, const PhoneNumber& right);
};

class PhoneBook{
private:
    vector<pair<Persons,PhoneNumber>> container;
public:
    explicit PhoneBook(ifstream fInput)
    {
        Persons man;
        PhoneNumber phone;
        if(!fInput.is_open()){
            cout << "Файл не может быть открыт!!!"<< endl;
        }
        regex regularPerson ("([a-zA-Z]+)");
        regex regularPhone ("(\\d+)");
        cmatch result;                      //Результат поиска с помощью регулярного выражения
        string s;                           //Строка для считывания из файла
        while(!fInput.eof()){
            fInput>>s;
            regex_search(s.c_str(), result, regularPerson); //Поиск в строке регулярных выражений!!!
            man = result.size() < 3 ? Persons(result[0], result[1]) : Persons(result[1], result[2], result[2]);
            regex_search(s.c_str(),result,regularPhone);
            phone = result.size() < 3 ? PhoneNumber(stoi(result.str(0)), stoi(result.str(1)),result.str(2))
                                       : PhoneNumber(stoi(result.str(0)),stoi(result.str(1)),result.str(2),
                                                     stoi(result.str(3)));
            container.emplace_back(man,phone);
        }
        fInput.close();
    }
    /// <summary>
    /// В классе PhoneBook реализуйте метод SortByName, который должен сортировать элементы контейнера по фамилии людей
    /// в алфавитном порядке.Если фамилии будут одинаковыми, то сортировка должна выполняться по именам, если имена
    /// будут одинаковы, то сортировка производится по отчествам.Используйте алгоритмическую функцию sort.
    /// </summary>
    void SortByName();

    /// <summary>
    /// Реализуйте метод SortByPhone, который должен сортировать элементы контейнера по номерам телефонов. Используйте
    /// алгоритмическую функцию sort.
    /// </summary>
    void SortByPhone();

	tuple<string,PhoneNumber> GetPhoneNumber(string Surname)
    {
        string Answer{};
        int counter{};
	    switch (counter)
	    {
            case 0:
                Answer = "not found";
	    		break;
	    	case 1:
        default:
            Answer = "found more than 1";
	    }
        return tuple<Answer, PhoneNumber>;
    }
    /*
     

     Реализуйте метод GetPhoneNumber, который принимает фамилию человека, а возвращает кортеж из строки и PhoneNumber.
     Строка должна быть пустой, если найден ровно один человек с заданном фамилией в списке. Если не найден ни один
     человек с заданной фамилией, то в строке должна быть запись «not found», если было найдено больше одного человека,
     то в строке должно быть «found more than 1».

     Реализуйте метод ChangePhoneNumber, который принимает человека и новый номер телефона и, если находит заданного
     человека в контейнере, то меняет его номер телефона на новый, иначе ничего не делает.
    */
};

#endif //LESSON1_LESSONONE_H
