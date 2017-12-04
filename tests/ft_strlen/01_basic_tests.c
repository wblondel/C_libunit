/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   01_basic_tests.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <wblondel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/04 08:15:50 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/04 08:47:20 by wblondel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libunit.h"
#include "tests_ft_strlen.h"
#include <stdio.h>

t_unit_suite	*basic_tests(void)
{
	static t_unit_suite *suite = NULL;

	if (suite)
		return (suite);
	unit_add_test(&suite, "String of length 0", &length_0_test, 0);
	unit_add_test(&suite, "String of length 5", &length_5_test, 0);
	unit_add_test(&suite, "String of length 100", &length_100_test, 0);
	unit_add_test(&suite, "String of length 500", &length_500_test, 0);
	unit_add_test(&suite, "String of length 1000", &length_1000_test, 0);
	unit_add_test(&suite, "String of length 50000", &length_50000_test, 0);
	unit_add_test(&suite, "String of length 100000", &length_100000_test, 0);
	return (suite);
}

int				length_0_test(void)
{
	if (ft_strlen("") == strlen(""))
		return (TEST_SUCCESS);
	else
		return (TEST_ERROR);
}

int				length_5_test(void)
{
	char str[6];

	str[5] = '\0';
	ft_memset(str, 'a', 5);
	if (ft_strlen(str) == strlen(str))
		return (TEST_SUCCESS);
	else
		return (TEST_ERROR);
}

int				length_100_test(void)
{
	char str[101];

	str[100] = '\0';
	ft_memset(str, 'a', 100);
	if (ft_strlen(str) == strlen(str))
		return (TEST_SUCCESS);
	else
		return (TEST_ERROR);
}

int				length_500_test(void)
{
	char str[501];

	str[500] = '\0';
	ft_memset(str, 'a', 500);
	if (ft_strlen(str) == strlen(str))
		return (TEST_SUCCESS);
	else
		return (TEST_ERROR);
}

int				length_1000_test(void)
{
	char str[1001];

	str[1000] = '\0';
	ft_memset(str, 'a', 1000);
	if (ft_strlen(str) == strlen(str))
		return (TEST_SUCCESS);
	else
		return (TEST_ERROR);
}

int				length_50000_test(void)
{
	char str[50001];

	str[50000] = '\0';
	ft_memset(str, 'a', 50000);
	if (ft_strlen(str) == strlen(str))
		return (TEST_SUCCESS);
	else
		return (TEST_ERROR);
}

int				length_100000_test(void)
{
	char str[100001];

	str[100000] = '\0';
	ft_memset(str, 'a', 100000);
	if (ft_strlen(str) == strlen(str))
		return (TEST_SUCCESS);
	else
		return (TEST_ERROR);
}
