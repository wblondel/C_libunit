/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tests_ft_strlen.h                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <wblondel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/04 08:01:58 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/04 08:33:34 by wblondel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef TESTS_FT_STRLEN_H
# define TESTS_FT_STRLEN_H

t_unit_suite	*basic_tests(void);
int				length_0_test(void);
int				length_5_test(void);
int				length_100_test(void);
int				length_500_test(void);
int				length_1000_test(void);
int				length_50000_test(void);
int				length_100000_test(void);

t_unit_suite	*error_tests(void);
int				segv_test(void);

#endif
