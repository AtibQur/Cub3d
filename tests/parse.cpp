/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-der <tvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/21 11:34:06 by tvan-der      #+#    #+#                 */
/*   Updated: 2022/11/21 11:45:19 by tvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gtest/gtest.h"

extern "C" {
#include "cub3d.h"
}

TEST(return_double, basic_test1)
{
    int num = return_double(5);
    ASSERT_EQ(10, num);
}

TEST(return_double, basic_test2)
{
    int num = return_double(7);
    ASSERT_EQ(14, num);
}