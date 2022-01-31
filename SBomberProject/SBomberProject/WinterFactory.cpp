#include "WinterFactory.h"

Ground* WinterFactory::CreateGround()
{
    return new (std::nothrow) WinterGround;
}

House* WinterFactory::CreateHouse()
{
    return new (std::nothrow) WinterHouse;
}

Tank* WinterFactory::CreateTank()
{
    return new (std::nothrow) WinterTank;
}

void WinterFactory::CreateLevel1(std::vector<GameObject*>& refStaticObjVec)
{
	const uint16_t maxX = MyTools::ScreenSingleton::getInstance().GetMaxX();
	const uint16_t maxY = MyTools::ScreenSingleton::getInstance().GetMaxY();
	const uint16_t offset = 3;
	const uint16_t width = maxX - 7;

	Ground* pGr = CreateGround();
	const uint16_t ground_y = maxY - 5;
	pGr->SetPos(offset + 1, ground_y);
	pGr->SetWidth(width - 2);
	refStaticObjVec.push_back(pGr);

	Tank* pTank = CreateTank();
	pTank->SetWidth(13);
	pTank->SetPos(30, ground_y - 1);
	refStaticObjVec.push_back(pTank);

	pTank = CreateTank();
	pTank->SetWidth(13);
	pTank->SetPos(50, ground_y - 1);
	refStaticObjVec.push_back(pTank);

	House* pHouse = CreateHouse();
	pHouse->SetWidth(13);
	pHouse->SetPos(80, ground_y - 1);
	refStaticObjVec.push_back(pHouse);
}
