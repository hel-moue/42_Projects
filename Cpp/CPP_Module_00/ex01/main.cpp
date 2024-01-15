/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 01:14:52 by hel-moue          #+#    #+#             */
/*   Updated: 2024/01/15 22:20:23 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PhoneBook.hpp"

int main(int ac, char **av)
{
    (void)av;
    if(ac > 1)
    {
        std::cout << "Error: This program doesn't take any arguments\n";
        return (1);
    }
    PhoneBook phonebook;
    phonebook.Start();
}