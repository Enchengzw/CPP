/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: encheng <encheng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 16:33:38 by ezhou             #+#    #+#             */
/*   Updated: 2024/09/03 18:38:07 by encheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Include/Template.hpp"

void print(int x)
{
    std::cout << x + 1 << " ";
}

int main() 
{
    int arr[] = {1, 2, 3, 4, 5};
    int length = 5;

    iter(arr, length, print);
    std::cout << std::endl;
    return 0;
}