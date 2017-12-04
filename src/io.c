/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   io.c                                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <wblondel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/04 05:33:36 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/04 05:33:49 by wblondel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libunit.h"
#include "libft.h"

/*
** Reads stdout from a pipe, and returns a value to be used by tests.
*/

int			unit_assert_output(int *p, char *expect)
{
	char	*output;
	size_t	len;
	size_t	actual;
	int		res;

	len = ft_strlen(expect);
	if ((output = ft_strnew(len)) == NULL)
		return (-1);
	actual = read(p[0], output, len + 1);
	if (actual != len)
		res = -1;
	else
		res = (ft_strcmp(expect, output) == 0 ? 0 : -1);
	ft_strdel(&output);
	return (res);
}
