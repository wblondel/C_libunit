/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   suite.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <wblondel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/04 01:58:03 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/04 08:00:10 by wblondel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libunit.h"

/*
** Creates a new suite element.
** Returns a pointer to the element, or NULL if malloc failed.
*/

static inline t_unit_suite	*create_suite(char *name, t_test test, int expected,
																int use_stdout)
{
	t_unit_suite	*suite;

	suite = (t_unit_suite *)ft_memalloc(sizeof(t_unit_suite));
	if (suite == NULL)
		return (NULL);
	suite->name = name;
	suite->test = test;
	suite->expected = expected;
	suite->use_stdout = use_stdout;
	suite->next = NULL;
	return (suite);
}

/*
** Appends a suite element created with create_suite to the end of suite.
** We want tests to be run in the order they are called.
*/

static inline void			append_to_suite(t_unit_suite *suite,
															t_unit_suite *new)
{
	while (suite->next)
		suite = suite->next;
	suite->next = new;
}

/*
** Adds a single test to a suite. If the suite is enpty, it creates a suite.
** Returns a pointer to the element created, or NULL if malloc failed.
*/

t_unit_suite				*unit_add_test(t_unit_suite **suite, char *name,
									t_test_simple test, int expected)
{
	t_unit_suite	*new;

	if (suite == NULL)
		return (NULL);
	new = create_suite(name, (t_test){.simple = test}, expected, 0);
	if (*suite == NULL)
		*suite = new;
	else
		append_to_suite(*suite, new);
	return (new);
}

/*
** Same as previous function, but defines a test case that catches stdout.
*/

t_unit_suite				*unit_add_test_output(t_unit_suite **suite,
									char *name, t_test_out test, int expected)
{
	t_unit_suite	*new;

	if (suite == NULL)
		return (NULL);
	new = create_suite(name, (t_test){.out = test}, expected, 1);
	if (*suite == NULL)
		*suite = new;
	else
		append_to_suite(*suite, new);
	return (new);
}
