/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libunit.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <wblondel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/04 01:05:46 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/04 05:58:59 by wblondel    ###    #+. /#+    ###.fr     */
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
# include <fcntl.h>
# include <stddef.h>
# include <stdarg.h>

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
void						unit_run_suite(t_unit_suite *suite, char *name,
									int *count, int *success);
int							unit_assert_output(int *p, char *expect);

/*
** A suites list contains test suites.
*/

typedef struct				s_unit_list
{
	char					*name;
	t_unit_suite			*suite;
	struct s_unit_list		*next;
}							t_unit_list;

/*
** Functions to manage suites lists.
*/

t_unit_list					*unit_add_suite(t_unit_list **list, char *name,
											t_unit_suite *suite);
int							unit_run_all(t_unit_list *list, char *name);

/*
** Utility functions
*/

void						unit_printf(const char *format, ...);

#endif
