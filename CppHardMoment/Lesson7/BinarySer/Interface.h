#pragma once
#include <string>
#include "FullName.pb.h"

class IRepository {
public:
	virtual ~IRepository() = default;
private:
	virtual void Open() = 0; // �������� �������������� � ����
	virtual void Save() = 0; // �������� ������������ � ����
};


class IMethods {
public:
	virtual ~IMethods() = default;
private:
	virtual double GetAverageScore(const StudentsProto::FullName& name) = 0;
	virtual std::string GetAllInfo(const StudentsProto::FullName& name) = 0;
	virtual std::string GetAllInfo() = 0;
};

