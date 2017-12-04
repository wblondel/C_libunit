/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libunit.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/04 01:05:46 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/04 01:14:49 by wblondel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LIBUNIT_H
# define LIBUNIT_H

/* Includes */
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <signal.h>

/* Test result global variables */
# define TEST_SUCCESS 0
# define TEST_ERROR -1
# define TEST_TIMEOUT 10

#endif
