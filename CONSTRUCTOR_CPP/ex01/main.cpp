// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: aollivie <aollivie@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/11/02 16:28:55 by aollivie          #+#    #+#             //
//   Updated: 2015/11/02 22:04:33 by aollivie         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <cstdlib>
#include <cstring>
#include <iostream>
#include <iomanip>
#include "Contact.class.hpp"

using namespace std;

int	main(void)
{
  std::string buff;
  Contact User[8];
  int nbContact = 0;
  int i;

  for(;;)
    {
      std::cout << "Put a action: ";
      std::getline(std::cin,buff);
      if (buff == "EXIT")
		return 0;
      else if (buff == "ADD")
	{
	  if (nbContact >= 7)
	    std::cerr << "The Book is Over" << endl;
	  else {
	    std::cout << "ADD" <<  endl;
	    User[nbContact++].ft_add();
	  }
	}
	else if (buff == "SEARCH")
	{
	  i = 0;
	  std::cout << "Search" << endl;
	  while (i < User[0].getNbContact())
	    {
		User[i].ft_search(i);
		i++;
	    }
	  i = -1;
	  while (i == -1) {
	    std::cout << "Index: ";
	    std::getline(std::cin,buff);
	    
	    i = atoi(buff.c_str());
	    if (buff.length() > 1 || buff[0] < '0' || buff[0] > '7')
	      i = -1;
	    if (i >= 0 && i <= 7 && i < nbContact)
	      User[i].ft_index();
	    else {
	      std::clog << "Error message : " << buff << " is not valid Index" << endl;
	      i = -1;
	    }
	  }

	}
	else
	  std::clog << "Error message : " << buff << " is not valid comand" << endl;
    }
      
      
  // User.ft_index();


      return (0);
}
