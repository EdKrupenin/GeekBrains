#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

void fileCreate(std::string& wordSave, std::string& fileName) {
	std::ofstream fileOut;
	fileOut.open(fileName);
	if (fileOut.is_open()) {
		fileOut << wordSave;
		std::cout << "Информация записана!" << std::endl;
	}
	else {
		std::cout << "Ошибка открытия файла !!!" << std::endl;
	}
	fileOut.close();
}

void сoncatenationFile(std::string fileNameOne, std::string fileNameTwo) {
	std::ifstream fileOne;
	std::ofstream fileTwo;
	std::string buffer;
	fileOne.open(fileNameOne);
	fileTwo.open(fileNameTwo, std::ofstream::app);
	if (fileOne.is_open() && fileTwo.is_open()) {
		std::cout << "Оба файла открылись" << std::endl;
		while (!fileOne.eof())
		{
			std::getline(fileOne, buffer);
			fileTwo << ("\n" + buffer);
		}
	}
	else
	{
		if (!fileOne.is_open()) std::cout << "Ошибка открытия 1go файла !!!" << std::endl;
		if (!fileTwo.is_open()) std::cout << "Ошибка открытия 2go файла !!!" << std::endl;
	}
	fileOne.close();
	fileTwo.close();
}

bool findArguments(int& argc, char** a, std::string fileName) {
	std::ifstream fileOne;
	std::string buffer;
	fileOne.open(fileName);
	if (!fileOne.is_open()) return false;
	if (argc > 1) {
		while (!fileOne.eof())
		{
			std::getline(fileOne, buffer);
			if (buffer.find(a[1])) {
				fileOne.close();
				return true;
			}
		}
	}
	else
	{
		std::cout << "Not application arg" << std::endl;
		fileOne.close();
		return false;
	}
}

int main(int argc, char* argv[])
{
	std::string wordOne = "\tKarl Heinrich Marx was a German philosopher, economist, historian, sociologist, political theorist, journalist and socialist revolutionary.\n"
		"Born in Trier, Germany, Marx studied law and philosophy at university. He married Jenny von Westphalen in 1843. Due to his political publications,\n"
		"Marx became stateless and lived in exile with his wife and children in London for decades,\n"
		"where he continued to develop his thought in collaboration with German thinker Friedrich Engels and publish his writings,\n"
		"researching in the reading room of the British Museum. His best-known titles are the 1848 pamphlet The Communist Manifesto and the three-volume Das Kapital(1867 – 1883).";
	std::string fileOne = "fileOne.txt";
	fileCreate(wordOne, fileOne);
	//------------------------------------------
	std::string wordTwo = "\tFriedrich Engels sometimes anglicised as Frederick Engels (28 November 1820 – 5 August 1895), was a German philosopher, historian, political scientist and revolutionary socialist.\n"
		"He was also a businessman, journalist and political activist, whose father was an owner of large textile factories in Salford\n"
		"(Greater Manchester, England) and Barmen, Prussia (now Wuppertal, Germany).";
	std::string fileTwo = "fileTwo.txt";
	fileCreate(wordTwo, fileTwo);
	//---------------------------------
	сoncatenationFile(fileOne, fileTwo);
	std::cout << (findArguments(argc, argv, fileOne))<<std::endl;
}
