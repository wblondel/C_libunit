/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libunit.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <wblondel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/04 01:05:46 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/04 02:30:07 by wblondel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LIBUNIT_H
# define LIBUNIT_H

/*
** Includes
*/

# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <signal.h>

/*
** Test result global variables
*/

# define TEST_SUCCESS 0
# define TEST_ERROR -1
# define TEST_TIMEOUT 10

typedef int		(*t_test_out)(int *);
typedef int		(*t_test_simple)(void);

/*
** Individual test case.
*/

typedef union				u_test
{
	t_test_out				out;
	t_test_simple			simple;
}							t_test;

/*
** A tests suite contains individual test cases.
** There is generally one test suite per function.
*/

typedef struct				s_unit_suite
{
	char					*name;
	t_test					test;
	int						expected;
	int						use_stdout;
	struct s_unit_suite		*next;
}							t_unit_suite;

/*
** Functions to manage tests suites.
*/

t_unit_suite				*unit_add_test(t_unit_suite **suite, char *name,
											t_test_simple test, int expected);
t_unit_suite				*unit_add_test_output(t_unit_suite **suite,
									char *name, t_test_out test, int expected);

/*
** A suites list contains test suites.
*/

typedef struct				s_unit_list
{
	char					*name;
	t_unit_suite			*suite;
	struct s_unit_suite		*next;
}							t_unit_list;

/*
** TODO: Functions to manage suites lists.
*/

#endif
