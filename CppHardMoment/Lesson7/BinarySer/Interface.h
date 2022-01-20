#pragma once
#include <string>
#include "FullName.pb.h"

class IRepository {
public:
	virtual ~IRepository() = default;
private:
	virtual void Open() = 0; // бинарная десериализация в файл
	virtual void Save() = 0; // бинарная сериализация в файл
};


class IMethods {
public:
	virtual ~IMethods() = default;
private:
	virtual double GetAverageScore(const StudentsProto::FullName& name) = 0;
	virtual std::string GetAllInfo(const StudentsProto::FullName& name) = 0;
	virtual std::string GetAllInfo() = 0;
};

