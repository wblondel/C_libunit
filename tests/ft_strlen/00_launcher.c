/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   00_launcher.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <wblondel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/04 07:40:00 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/04 08:49:38 by wblondel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libunit.h"
#include "tests_ft_strlen.h"

int				main(int argc, char **argv)
{
	static t_unit_list *list = NULL;

	(void)argc;
	unit_add_suite(&list, "Basic tests", basic_tests());
	unit_add_suite(&list, "Error management tests", error_tests());
	return (unit_run_all(list, argv[0]));
}
