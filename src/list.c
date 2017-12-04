/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   list.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <wblondel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/04 03:41:21 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/04 03:51:35 by wblondel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libunit.h"
#include "libft.h"

/*
** Creates a new list element.
** Returns a pointer to the element, or NULL if malloc failed.
*/

static inline t_unit_list	*create_list(char *name, t_unit_suite *suite)
{
	t_unit_list		*list;

	list = (t_unit_list *)ft_memalloc(sizeof(t_unit_list));
	if (list == NULL)
		return (NULL);
	list->name = name;
	list->suite = suite;
	list->next = NULL;
	return (list);
}

/*
** Appends a list element created with create_list to the end of list.
** We want tests to be run in the order they are called.
*/

static inline void			append_to_list(t_unit_list *list, t_unit_list *new)
{
	while (list->next)
		list = list->next;
	list->next = new;
}

/*
** Adds a suite to a list. If the list is empty, it creates a list.
** Returns a pointer to the element created, or NULL if it failed.
*/

t_unit_list					*unit_add_suite(t_unit_list **list, char *name,
											t_unit_suite *suite)
{
	t_unit_list		*new;

	if (list == NULL)
		return (NULL);
	new = create_list(name, suite);
	if (*list == NULL)
		*list = new;
	else
		append_to_list(*list, new);
	return (new);
}
