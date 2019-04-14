#include "holberton.h"
/**
 *  _atoi - convert char to integer
 * @s: string to convert
 * Return: number calculated
 */
int _atoi(char *s)
{
	int ispositive;
	int result = 0;
	int first_pos = 0;


	first_pos = find_pos_num(s);
	ispositive = _is_positive(s, first_pos);
	result = my_atoi(s, first_pos, first_pos, 0, ispositive);
	return (result);
}
/**
 * _is_positive - calculate how many negatives has an string
 * @s: string to calculate
 * @pos: last posicion to check sign
 * Return: 1 if is positive 0 if is negative
 */
int _is_positive(char *s, int pos)
{
	int negatives = 0;
	int contador = 0;

	while (contador < pos)
	{
		if (*(s + contador) == '-')
			negatives++;
		contador++;
	}
	return (negatives % 2 == 0);
}
/**
 * find_pos_num - find position first number
 * @s: string
 * Return: position of the first number
 */
int find_pos_num(char *s)
{
	int pos = 0;
	int value =  *(s + pos);

	while (!is_digit(value) && value >= 0 && value <= 255 && value != '\0')
	{
		pos++;
		value =  *(s + pos);
	}
	return (pos);
}
/**
 * my_atoi - return the number
 * @s: string
 * @start: initial position
 * @current: actual position
 * @value: current value
 * @ispositive: if the number is positive
 * Return: position of the last number
 */
int my_atoi(char *s, int start, int current, int value, int ispositive)
{
	int current_v;
	int result;

	current_v = *(s + current);
	if (current_v != '\0' && is_digit(current_v))
	{
		if (current == start)
		{
			current_v = ispositive ? (current_v - '0') : -(current_v - '0');
			result = my_atoi(s, start, current + 1, current_v, ispositive);
			return (result);
		}
		else
		{
			if (ispositive)
				value = (value * 10) + (current_v - '0');
			else
				value = (value * 10) - (current_v - '0');
			result = my_atoi(s, start, current + 1, value, ispositive);
			return (result);
		}
	}
	else
	{
		return (value);
	}
}
/**
 * is_digit - determinated if is digit
 * @c: character
 * Return: 1 if is digit
 */
int is_digit(char c)
{
	return ((c >= '0' && c  <= '9') ? 1 : 0);
}
