/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 01:14:55 by hel-moue          #+#    #+#             */
/*   Updated: 2024/01/15 23:00:28 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    std::cout<<"\033[31mPhonbook create \033[35mBY Hel-moue\033[0m\n";
    std::cout<<" \033[33m& THIS IS THE MANUEL : \n";
    std::cout<<"\033[32m-------------------------------\n";
    std::cout<<"|\033[33mADD    \033[32m| to add a contact    |\n";
    std::cout<<"|\033[33mSEARCH \033[32m| to search a contact |\n";
    std::cout<<"|\033[33mEXIT   \033[32m| to EXIT the program |\n";
    std::cout<<"|\033[33mSAVE   \033[32m| to save the contacts|\n";
    std::cout<<"|\033[33mHELP   \033[32m| to show the manuel  |\n"; 
    std::cout<<"\033[32m-------------------------------\033[0m\n";
    std::cout << "\033[34mYou can use X or x to exit anytime\033[0m\n";
    std::cout << "\033[34mYou can use CTRL + D to exit the program\033[0m\n";
    std::cout << "\033[34mYou can use HELP or help to show the manuel anytime\033[0m\n";
    std::cout << "\033[34mIf You Save the contacts, you will lose them when you exit the program\033[0m\n";
    std::cout << "\033[34mIf You Don't Want to lose the contacts, you can save them anytime in the main menu\033[0m\n";
    std::cout << "\033[31mThe Memory of the PhoneBook is limited to 8 contacts\033[0m\n";
    std::cout << "\033[33mEnjoy !!\033[0m\n";
    nb_contacts = 0;
}

void PhoneBook::Start()
{
    std::cout<<"Enter the \033[35mcommand\033[0m :\n";
    std::getline(std::cin, command);
    if(command == "ADD" || command == "add")
    {
        if (nb_contacts > 7)
            std::cout<<"\033[31mWarning !! You will lose the first contact !!\033[0m\n";
        ADD_CONTACT(Contacts[nb_contacts%8]);
    }
    else if(command == "SEARCH" || command == "search")
        SEARCH();
    else if(command == "EXIT" || std::cin.eof() || command == "exit")
        EXIT();
    else if(command == "HELP" || command == "help")
    {
        PhoneBook();
        Start();
    }   
    else if (command == "SAVE" || command == "save")
    {
        PRINT_CONTACTS();
        std::ofstream file("Contacts.csv");
        if (file.is_open())
        {
            file << "First Name,Last Name,Nick Name,Phone Number,Darkest Secret\n";
            for (unsigned int i = 0; i < nb_contacts; i++)
            {
                file << Contacts[i].get_first_name() << ",";
                file << Contacts[i].get_last_name() << ",";
                file << Contacts[i].get_nick_name() << ",";
                file << Contacts[i].get_phone_number() << ",";
                file << Contacts[i].get_darckest_secret() << "\n";
            }
            file.close();
            std::cout << "\033[32mContacts saved successfully !!\033[0m\n";
            std::cout << "\033[32mYou can find them in the file \033[35mContacts.csv\033[0m\n";
        }
        else
            std::cout << "\033[31mError\033[0m : \033[35mUnable to open file\033[0m\n";
        Start();
    }
    else
        Start();
}

void PhoneBook::SEARCH()
{
    std::string index;
    unsigned int i = 0;

    PRINT_CONTACTS();
    while (nb_contacts)
    {
        std::cout << "Enter the \033[35mindex\033[0m :\n";
        std::getline(std::cin, index);
		if (std::cin.eof())
			EXIT();
        if(index == "X" || index == "x")
            Start();
        if(index == "HELP" || index == "help")
        {
            PhoneBook();
            SEARCH();
        }
        if (nb_contacts < 8)
            i = nb_contacts;
        else
            i = 8;
        if (nb_contacts && (index.length() != 1 || index[0] < '1' || index[0] > '8' || (unsigned int) index[0] > nb_contacts+48))
            std::cout << "\033[31mInvalid index !!\033[0m try between \033[35m1 & " << i << "\033[0m" << "or X to exit\n";
        else if ((index[0] >= '1' && index[0] <= '8' && index.length() == 1)
                && (unsigned int) index[0] - 48 <= nb_contacts)
                    break;
    }
    if(nb_contacts)
        PRINT_CONTACT(index);
    else
        std::cout<<"\033[31mNo contacts !!\033[0m\n";
    Start();
}

void PhoneBook::EXIT()
{
	std::cout<<"\033[32mGood bye !!\n";
    exit(0);
}

void PhoneBook::ADD_CONTACT(Contact &Contacts)
{
    ADD_FIRST_NAME(Contacts);
    ADD_LAST_NAME(Contacts);
    ADD_NICK_NAME(Contacts);
    ADD_PHONE_NUMBER(Contacts);
    ADD_DARCKEST_SECRET(Contacts);
    std::cout<<"\033[32mContact added successfully !!\033[0m\n";
    nb_contacts += 1;;
    Start();
}

void PhoneBook::PRINT_CONTACTS()
{
    unsigned int i = 0;
    std::cout << " ___________________________________________ \n";
	std::cout << "|     Index|First Name| Last Name|  Nickname|\n";
	std::cout << "|----------|----------|----------|----------|\n";
    for(;i <nb_contacts && i < 8;i++)
    {
        std::cout << "|\033[35m" << std::setw(10) << i+1 << "\033[0m|";
        std::cout << std::setw(10) << Get_10(Contacts[i].get_first_name()) << "|";
        std::cout << std::setw(10) << Get_10(Contacts[i].get_last_name()) << "|";
        std::cout << std::setw(10) << Get_10(Contacts[i].get_nick_name()) << "|\n";
    }
	std::cout << " ___________________________________________ \n";
}

void PhoneBook::PRINT_CONTACT(std::string index)
{
    std::cout << "\033[33mFirst Name     : \033[0m" << Contacts[index[0] - '1'].get_first_name() << std::endl;
    std::cout << "\033[33mLast Name      : \033[0m" << Contacts[index[0] - '1'].get_last_name() << std::endl;
    std::cout << "\033[33mNick Name      : \033[0m" << Contacts[index[0] - '1'].get_nick_name() << std::endl;
    std::cout << "\033[33mPhone Number   : \033[0m" << Contacts[index[0] - '1'].get_phone_number() << std::endl;
    std::cout << "\033[33mDarkest Secret : \033[0m" << Contacts[index[0] - '1'].get_darckest_secret() << std::endl;
}
