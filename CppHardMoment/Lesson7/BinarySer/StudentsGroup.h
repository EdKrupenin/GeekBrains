#pragma once
#include "stdafx.h"

class StudentsGroup : public StudentsProto::StudentsGroup , virtual public IMethods, virtual public IRepository
{
	void Open() override;
	void Save() override;
	double GetAverageScore(const StudentsProto::FullName& name) override;
	std::string GetAllInfo() override;
	std::string GetAllInfo(const StudentsProto::FullName& name) override;
};

