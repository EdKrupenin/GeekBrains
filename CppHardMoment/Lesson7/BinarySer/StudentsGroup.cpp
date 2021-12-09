#include "StudentsGroup.h"


void StudentsGroup::Open()
{
	//По хорошему передавать путь к файлу
	std::ifstream in("./students.bin", std::ios::binary);
	if(this->ParseFromIstream(&in)){
		
	}
}

void StudentsGroup::Save()
{
	//По хорошему передавать путь к файлу
	std::ofstream out("./students.bin", std::ios::binary);
	this->SerializePartialToOstream(&out);
}

double StudentsGroup::GetAverageScore(const StudentsProto::FullName& name)
{
	for (const auto& student : this->group())
	{
		if(std::tie(student.full_name()) == std::tie(name))
		{
			return  student.average_score();
		}
	}
}

std::string StudentsGroup::GetAllInfo(const StudentsProto::FullName& name)
{
	std::string answer;
	for (const auto& value : this->group())
	{
		if (std::tie(value.full_name()) == std::tie(name))
		{
			std::string people = value.full_name().name() + value.full_name().surname() + value.full_name().patronymic() + std::to_string(value.average_score());
			for (auto const& score : value.appraisal())
			{
				people.append(std::to_string(score));
			}
			answer.append(people);
		}
	}
	return answer;
}

std::string StudentsGroup::GetAllInfo()
{
	std::string answer;
	for (const auto& value : this->group())
	{
		std::string people = value.full_name().name() + value.full_name().surname() + value.full_name().patronymic() + std::to_string(value.average_score());
		for (auto const& score : value.appraisal())
		{
			people.append(std::to_string(score));
		}
		answer.append(people);
	}
	return answer;
}
