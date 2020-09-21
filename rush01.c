/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrank <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 15:34:57 by rfrank            #+#    #+#             */
/*   Updated: 2020/09/21 20:26:00 by rfrank           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);



/////// Эта функция предзначена для проверке столбцов в 1 строке и в последней
void	prnt(int column, int c, int l, char a) // Внизу описана для чего нужна эта функция
{
	char b;

	if (a == '\\') /* Если мы пишем \, то то тогда b = /, так как в первом условии нам нужно чтобы сначала в условии писалось \, а потом /. А во втором условии нужно сначала написать /, и тогда следующая переменная поменяется на \ */
		b = '/'; 
	else
		b = '\\';
	if (column == 0) // Если 1 колонка
		ft_putchar(a); // Выводим a  <= (Там будет либо '/' ,  либо '\' <= все зависит от того какой символ мы присвоем переменной - a в функции
	else if (column == c) // Если колонка последняя
		ft_putchar(b); // Проигрываем функцию со значением '/'
	else
		ft_putchar('*'); // Иначе если колонка не первая и не последняя, то мы выводим '*'
}

void	put_at(int line, int column, int c, int l)
{
	if (line == 0) // Если строчка первая
		prnt(column, c, l, '/'); // То мы используем  функцию prnt со значением /, соотвественно. запоминаем что строка у нас равна нулю и идем проигрывать функцию с a = '\' 
	else if (line == l) // иначе если строка уже последняя
		prnt(column, c, l, '\\'); // мы выводим эту функцию с \, идем и так же прогоняем функцию с a='\'
	else // иначе если у нас строка не первая, колонка не первая и колонка не последняя
	{
		if (column == 0 || column == c) // мы прогоняем это условие: если строка любая, а колонка первая или последняя, то мы выводим '*' || То есть здесь мы пишем условия для ребер.
			ft_putchar('*');
		else // инаече если у нас строка не первая, колонка не первая, колонка не последняя и это не ребра, то мы выводим пробел
			ft_putchar(' ');
	}
}

void	rush(char x, char y)
{
	char line;
	char column;

	line = 0; // Считаем строку с первой
	while (line < y) // Пока колонка меньше заданной намми столбца(y)
	{
		column = 0; // Считаем колонку с первой
		while (column < x) // Пока колонка меньше заданной нами строки(x)
		{
			put_at(line, column, x - 1, y - 1); // И с помощью while мы проигрываем функцию для каждой строки в столбце и наоборот
			column++; //
		}
		line++;
		ft_putchar('\n'); // Здесь мы начинаем с нового абзаца после вывода первой всей строки
	}
}
