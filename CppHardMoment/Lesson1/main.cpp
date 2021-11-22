#include "LessonOne.h"

ostream& operator<< (std::ostream &out, const Persons &person){
    out<<person.surname<<" "<<person.name<<" "<<person.patronymic.value_or("") << " ";
    return out;
}

bool operator==(const Persons &left, const Persons &right) {
    return (tie(left.surname,left.name,left.patronymic) == tie(right.surname,right.name,right.patronymic));
}

bool operator<(const Persons &left, const Persons &right) {
    return (tie(left.surname,left.name,left.patronymic) < tie(right.surname,right.name,right.patronymic));
}

ostream &operator<<(ostream &out, const PhoneNumber &phone) {
    out<<"+"<<phone.countryCode<<"("<<phone.cityCode<<")"<<phone.number<<
    phone.additionalNumber.value_or("");
    return out;
}

bool operator==(const PhoneNumber &left, const PhoneNumber &right) {
    return (tie(left.countryCode,left.cityCode,left.number, left.additionalNumber) == tie(right.countryCode,right.cityCode,right.number,right.additionalNumber));;
}

bool operator<(const PhoneNumber &left, const PhoneNumber &right) {
    return (tie(left.countryCode,left.cityCode,left.number, left.additionalNumber) < tie(right.countryCode,right.cityCode,right.number,right.additionalNumber));;
}

void PhoneBook::SortByName() {
    sort(this->container.begin(), this->container.end(),
        [](pair<Persons, PhoneNumber>& lhs, pair<Persons, PhoneNumber>& rhs)
        {
            return tie(lhs.first.surname, lhs.first.name, lhs.first.patronymic) >
                tie(rhs.first.surname, rhs.first.name, rhs.first.patronymic);
        });
}

void PhoneBook::SortByPhone()
{
    sort(this->container.begin(), this->container.end(),
        [](pair<Persons, PhoneNumber>& lhs, pair<Persons, PhoneNumber>& rhs)
        {
            return tie(lhs.second.countryCode, lhs.second.cityCode, lhs.second.number, lhs.second.additionalNumber) >
                tie(rhs.second.countryCode, rhs.second.cityCode, rhs.second.number, rhs.second.additionalNumber);
        });
}
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
