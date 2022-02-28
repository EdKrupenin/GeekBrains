#include "LessonOne.h"

ostream& operator<< (std::ostream& out, const Persons& person) {
    out << person.surname << " " << person.name << " " << person.patronymic.value_or("") << " ";
    return out;
}

bool operator==(const Persons& left, const Persons& right) {
    return (tie(left.surname, left.name, left.patronymic) == tie(right.surname, right.name, right.patronymic));
}

bool operator<(const Persons& left, const Persons& right) {
    return (tie(left.surname, left.name, left.patronymic) < tie(right.surname, right.name, right.patronymic));
}

ostream& operator<<(ostream& out, const PhoneNumber& phone) {
    out << "+" << phone.countryCode << "(" << phone.cityCode << ")" << phone.number <<
       (phone.additionalNumber.has_value()? to_string(phone.additionalNumber.value()):"");
    return out;
}

bool operator==(const PhoneNumber& left, const PhoneNumber& right) {
    return (tie(left.countryCode, left.cityCode, left.number, left.additionalNumber) == tie(right.countryCode, right.cityCode, right.number, right.additionalNumber));;
}

bool operator<(const PhoneNumber& left, const PhoneNumber& right) {
    return (tie(left.countryCode, left.cityCode, left.number, left.additionalNumber) < tie(right.countryCode, right.cityCode, right.number, right.additionalNumber));;
}

void PhoneBook::SortByName() {
    sort(this->container.begin(), this->container.end(),
        [](pair<Persons, PhoneNumber>& lhs, pair<Persons, PhoneNumber>& rhs)
        {
            return lhs.first < rhs.first;
        });
}

void PhoneBook::SortByPhone()
{
    sort(this->container.begin(), this->container.end(),
        [](pair<Persons, PhoneNumber>& lhs, pair<Persons, PhoneNumber>& rhs)
        {
            return lhs.second < rhs.second;
        });
}

tuple<string, PhoneNumber> PhoneBook::GetPhoneNumber(string Surname)
{
    string Answer{};
    PhoneNumber num;
    int counter{};
    for (auto record : this->container) {
        if (Surname == record.first.surname) {
            counter++;
            num = record.second;
        }
    }
    switch (counter)
    {
    case 0:
        Answer = "not found";
        break;
    case 1:
        Answer = "";
        break;
    default:
        Answer = "found more than 1";
    }
    return make_tuple(Answer, num);
}

bool PhoneBook::ChangePhoneNumber(Persons man, PhoneNumber num)
{
    bool res = false;
	for(auto record: this->container) {
        if (record.first == man) {
            record.second = num;
            res = true;
        }
	}
    return res;
}

ostream& operator<< (ostream& out, const PhoneBook& phone)
{
    for_each(phone.container.begin(), phone.container.end(), [&](pair<Persons, PhoneNumber> record)
        {
            out << record.first << "\t" << record.second << "\n";
        });
    return out;
}
