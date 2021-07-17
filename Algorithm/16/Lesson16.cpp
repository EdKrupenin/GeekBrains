#include <iostream>
#include "Resource/Lesson9-10.h"


#pragma region Шифрование

/// <summary>
/// Шифр перестановкой
/// </summary>
/// <param name="stirng">строка для шифрования</param>
/// <param name="key">количество столбцов</param>
/// <returns></returns>
char* simpleEncryption(char* string, int length, int key) {
	char* encrypt = new char[length];
	int row = (length % key) + (length / key); //Рассчитываем длину строки
	int col = key; //Кол-во столбцов
	for (int j = 0; j < row; j++)
		for (int i = 0; i < col; i++)
			encrypt[j * col + i] = string[i * row + j];

	return encrypt;
}

/// <summary>
/// Расшифровка перестановкой
/// </summary>
/// <param name="string">Зашифрованное сообщение</param>
/// <param name="length">Длина зашифрованного сообщения</param>
/// <param name="key">Кол-во столбцов</param>
/// <returns>Расшифрованное сообщение</returns>
char* simpleDecryption(char* string, int length, int key) {
	char* decrypt = new char[length];
	int row = (length % key) + (length / key); //Рассчитываем длину строки
	int col = key; //Кол-во столбцов
	for (int j = 0; j < row; j++)
		for (int i = 0; i < col; i++)
			decrypt[i * row + j] = string[j * col + i];

	return decrypt;
}


/// <summary>
/// Шифрование цезаря
/// </summary>
/// <param name="string">Сообщение</param>
/// <param name="length">Длина сообщения</param>
/// <param name="key">смещение</param>
/// <returns>Зашифрованное сообщение</returns>
char* cesarEncryption(char* string, int length, int key) {
	char* encrypt = new char[length];
	int LowercaseletterStart = 65;
	int LowercaseletterEnd = 90;
	int cursiveletterStart = 97;
	int cursiveletterEnd = 122;
	for (int i = 0; i < length; i++)
	{
		if ((string[i] >= LowercaseletterStart && string[i] <= LowercaseletterEnd) ||
			(string[i] >= LowercaseletterStart && string[i] <= LowercaseletterEnd))
		{
			int letter = (int)string[i] + key;
			if (letter > LowercaseletterEnd && letter < cursiveletterStart)
				encrypt[i] = char(letter - (LowercaseletterEnd + 1) + LowercaseletterStart);
			else
				if (letter > cursiveletterEnd)
					encrypt[i] = char(letter - (cursiveletterEnd + 1) + cursiveletterStart);
				else
					encrypt[i] = char(letter);
		}
		else
		{
			encrypt[i] = string[i]; //Если пришел пробел или прочие служебные символы.
		}
	}
	return encrypt;
}

/// <summary>
/// Дешифровка цезаря
/// </summary>
/// <param name="string">Зашифрованная строка</param>
/// <param name="length">Длина строки</param>
/// <param name="key">Смешение</param>
/// <returns>Расшифрованное сообщение</returns>
char* cesarDecryption(char* string, int length, int key) {
	char* decrypt = new char[length];
	int LowercaseletterStart = 65;
	int LowercaseletterEnd = 90;
	int cursiveletterStart = 97;
	int cursiveletterEnd = 122;
	for (int i = 0; i < length; i++)
	{
		if ((string[i] >= LowercaseletterStart && string[i] <= LowercaseletterEnd) ||
			(string[i] >= LowercaseletterStart && string[i] <= LowercaseletterEnd))
		{
			int letter = (int)string[i] - key;
			if (letter < LowercaseletterStart)
				decrypt[i] = char(LowercaseletterEnd - (LowercaseletterStart - letter - 1));
			else if (letter > LowercaseletterEnd && letter < cursiveletterStart)
				decrypt[i] = char(cursiveletterEnd - (cursiveletterStart - letter - 1));
			else
				decrypt[i] = char(letter);
		}
		else
		{
			decrypt[i] = string[i]; //Если пришел пробел или прочие служебные символы.
		}
	}
	return decrypt;
}

#pragma endregion


int main()
{
	simpleDecryption(simpleEncryption(mess, 20, 4), 20, 4);
	cesarDecryption(cesarEncryption(mess2, 20, 4), 20, 4);
	return 0;
}
