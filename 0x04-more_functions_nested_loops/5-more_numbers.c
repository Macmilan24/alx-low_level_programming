#include "main.h"

/**
 * more-number - print the number form 0 to 14 10 times
 * Return: the number 0 to 14 10 times
 */
void more_number(void)
{
	int x;
	int i;
	for (x = 0; x < 10; x++)
	{
		for (i = 0; i < 14; i++)
		{
			if (i > 0)
			{
			_putchar((i / 10) + '0');
			}
			_putchar((i % 10) + '0');
		}
		_putchar('\n');
	}
}
