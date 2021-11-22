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
    Persons() = default;
    Persons(string Surname, string Name, optional<string> Patronymic = nullopt)
        : surname(move(Surname)), name(move(Name)), patronymic(move(Patronymic))
	{}
    friend ostream& operator<< (std::ostream &out, const Persons &person);
    friend bool operator==(const Persons& left, const Persons& right);
    friend bool operator<(const Persons& left, const Persons& right);
};

struct PhoneNumber{
    int countryCode {};
    int cityCode {};
    string number {};
    optional<int> additionalNumber{};
    PhoneNumber() = default;
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
    explicit PhoneBook(ifstream& fInput)
    {
        Persons man;
        PhoneNumber phone;
        if(!fInput.is_open()){
            cout << "Файл не может быть открыт!!!"<< endl;
        }
        else {
            regex regularPerson("([A-Za-z]*) ([A-Za-z]*) ([A-Za-z]*)");

            regex regularPhone("(?:.*) ([1-9]*) ([0-9]*) ([0-9]*) ([0-9]*||[-])");
            smatch result;                      //Результат поиска с помощью регулярного выражения
            string s{};                           //Строка для считывания из файла
            while (std::getline(fInput, s)) {
                //fInput >> s;
                regex_search(s, result, regularPerson); //Поиск в строке регулярных выражений!!!
                man = result.size() < 3 ? Persons(result[1], result[2]) : Persons(result[1], result[2], result[3]);
                regex_search(s, result, regularPhone);
                phone = result.str(4) == "" ? PhoneNumber(stoi(result.str(1)), stoi(result.str(2)), result.str(3))
                    : PhoneNumber(stoi(result.str(1)), stoi(result.str(2)), result.str(3),
                        stoi(result.str(4)));
                container.emplace_back(man, phone);
            }
            fInput.close();
        }
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

    /// <summary>
    ///  Реализуйте метод GetPhoneNumber, который принимает фамилию человека, а возвращает кортеж из строки и PhoneNumber.
    ///  Строка должна быть пустой, если найден ровно один человек с заданном фамилией в списке.Если не найден ни один
    ///  человек с заданной фамилией, то в строке должна быть запись «not found», если было найдено больше одного человека,
    ///  то в строке должно быть «found more than 1».
    /// </summary>
    tuple<string, PhoneNumber> GetPhoneNumber(string Surname);

    /// <summary>
    /// Реализуйте метод ChangePhoneNumber, который принимает человека и новый номер телефона и, если находит заданного
    /// человека в контейнере, то меняет его номер телефона на новый, иначе ничего не делает.
    /// </summary>
	bool ChangePhoneNumber(Persons man, PhoneNumber num);

    friend ostream& operator<< (ostream& out, const PhoneBook& phone);
};

#endif //LESSON1_LESSONONE_H
