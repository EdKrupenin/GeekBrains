#include <stdio.h>

int main()
{
    int d;
	printf("%s \n","Ввведите число :");
    scanf("%d", &d);
	int i = 2;
	// начинаем с 2 намерено и ищем только 1 делитель тогда число будет простым
	while ((d % i != 0) && (i < d)) {
		i++;
	}
    printf("%s \n",((i == d) ? "Yes" : "No"));
}