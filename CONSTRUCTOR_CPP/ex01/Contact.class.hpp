// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Contact.class.hpp                                  :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: aollivie <aollivie@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/11/02 16:46:03 by aollivie          #+#    #+#             //
//   Updated: 2015/11/02 21:38:36 by aollivie         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

class Contact {

  std::string _first_name;
  std::string _last_name;
  std::string _nickname;
  std::string _login;
  std::string _postal_adress;
  std::string _email_adress;
  std::string _phone_number;
  std::string _birthday_date;
  std::string _favorite_meal;
  std::string _underwear_color;
  std::string _darkest_secret;

  void		ft_print(string str);
  
  static int	_nbContact;

public:

  Contact( void );

  int	getNbContact();
  void	ft_add();
  void  ft_search(int i);
  void	ft_index();
};

#endif
