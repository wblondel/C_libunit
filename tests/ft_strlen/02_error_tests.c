/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   02_error_tests.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <wblondel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/04 08:16:46 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/04 08:32:47 by wblondel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libunit.h"
#include "tests_ft_strlen.h"

t_unit_suite	*error_tests(void)
{
	static t_unit_suite *suite = NULL;

	if (suite)
		return (suite);
	unit_add_test(&suite, "Segfault test", &segv_test, SIGSEGV);
	return (suite);
}

int				segv_test(void)
{
	ft_strlen(NULL);
	return (TEST_SUCCESS);
}
