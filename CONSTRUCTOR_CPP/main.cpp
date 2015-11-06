#include <iostream>
#include <fstream>
#include "class/Variable.class.hpp"
#include "class/Function.class.hpp"

#include <iostream>
#include <cstring>
#include <string>

void	upper_file(std::ostream &os, std::string av)
{
   int i;
 
   i = 0;
   while (av[i]) {
     if (av[i] >= 'a' && av[i] <= 'z') {
       os<< char(av[i] -32);
     }
     else
       os << char(av[i]);
     i++;
   }
}


int	main(void)
{
  std::string buff;
  std::string className;
  Variable	var[42];
  int		index = 0;
  //  int		index2 = 0;
  //  Variable	function[42];
  int		nb = 0;
  /*
   * Initialisation of Function & Variable
   */
  std::cout<<"Enter Class Name: ";
  getline(std::cin, className);  

  buff = "y";
  while(buff != "n")
    {  
      while (buff != "n")
	{
	  var[index].add();
	  var[index++].setClassName(className);
	  std::cout<<"Add Variable [y/n]: ";
	  getline(std::cin, buff);
	}
      /*
      buff = "y";
       while (buff != "n")
	{
	  function[index2].add();
	  function[index2++].setClassName(className);
	  std::cout<<"Add function [n/y]: ";
	  getline(std::cin, buff);
	}
      */
    }

  /*
   * Create file .hpp with nameClass
   */
 
  std::ofstream myfile;
  std::string	str_class = className;
  className += ".class.hpp";

  /*
   * Write in "file".class.hpp
   */
  myfile.open (className.c_str());
 
   
  myfile<<"#ifndef ";
  upper_file(myfile, str_class);
  myfile<<"_CLASS_HPP"<<std::endl;

  myfile<<"# define ";
  upper_file(myfile, str_class);
  myfile<<"_CLASS_HPP"<<std::endl;
  myfile<<"#include "<<"<iostream>"<< std::endl;
  myfile<<std::endl;
  
  myfile<<"class"<< className<<std::endl;
  myfile<<"{"<<std::endl;
  
  myfile<<"public:"<<std::endl;
  
  while(nb < index)
    {
      //if (var[nb].getVisibility() == "public")
	var[nb].write_file(myfile);
      nb++;
    }


  
  myfile.close();

    return 0;
}



  



      



/*
void	file(void)
{
  std::cout << "ok" << std::endl;
  myfile.open("className");
  myfile << "Writing this to a file.\n";
  myfile << std::endl;
  myfile << "test.\n";
  myfile.close();
}
*/
/*
  int remain(void)
{
  Function a;
  Variable b;
  a.print();
  std::cout << std::endl;
  b.print();
   return 0;
}
*/
