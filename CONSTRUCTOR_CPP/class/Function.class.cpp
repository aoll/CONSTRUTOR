 
#include "Function.class.hpp"

/*
 * Not Menbers Attributs
 */
int	Function::_nbFunction = 0;

/*
 * Constructor & Destructor
 */
Function::Function(void)
{
  this->_nbFunction++;
  return;
}

Function::Function(std::string const nameClass):
  _nameClass(nameClass)
{
  this->_nbFunction++;
  std::cout << "Cons String var" << std::endl;
  return;
}
 
Function::Function(Function const &tocopy):
  _name(tocopy._name)
{
  this->_nbFunction++;
  std::cout << "Cons Copy var" << std::endl;
  return;
}
 
Function::~Function(void)
{
  this->_nbFunction--;
  std::cout << "Dest var" << std::endl; 
}


/*
 *Overload operator function
 */

std::ostream	&operator<<(std::ostream &o, Function &var)
{
  o << var.getName();
  return o;
}

Function      &  Function::operator=(Function const &other)
{
  this->_name = other._name;
  return *this;
}

/*
 *
 * Different Public Function
 */
void		Function::add(void)
{
  int t = 0;
  int i = 0;
  std::string buff;

  std::cout << "Enter function's sweaty name: ";
  std::getline (std::cin,this->_name);

  std::string y = "y";
  std::string n = "n";

  std::cout << "Static? [n/y]: ";
  std::getline (std::cin,buff);
  if (buff == y)
    this->_staticOrMembre = true;
  else
    this->_staticOrMembre = false;

  std::cout << "Type? : ";
  std::getline (std::cin,this->_type);

  std::cout << "Number of parameter: ";
  std::getline (std::cin,buff);
  t = atoi(buff.c_str());
  this->setNbParameter(t);
  
  while (t)
    {
      std::cout << "Name parameter " << (i + 1) << ": ";
      std::getline (std::cin,this->_parameter[i++]);
      t--;
    }

  std::cout << "Visibility: ";
  std::getline (std::cin,this->_visibility);
}

void            Function::print(void)
{
  int index = 0;

  std::cout <<"\t";
  if (this->_staticOrMembre == true)
    std::cout<<"static ";
  std::cout<<this->getType();
  std::cout <<"\t\t"<<this->getName()<<"(";
  if (this->_nbParameter)
    {
      while (index < this->_nbParameter)
	{
	  if (index)
	    std::cout<<", ";
	  std::cout<<this->_parameter[index++];
	}
      std::cout<<");"<<std::endl;
    }
  else
    std::cout<<"void);"<<std::endl;
}


/*
 *
 * Geter and seter
 */
std::string	Function::getName(void) const
{
  return this->_name;
}
void		Function::setName(std::string const src)
{
  this->_name = src;
  return;
}

std::string	Function::getNameClass(void) const
{
  return this->_nameClass;
}
void		Function::setNameClass(std::string const src)
{
  this->_nameClass = src;
  return;
}

int	Function::getNbParameter(void) const
{
  return this->_nbParameter;
}

void		Function::setNbParameter(int const nbParameter)
{
  this->_nbParameter = nbParameter;
  return;
}

std::string	Function::getParameter(int const nb)
{
  return this->_parameter[nb];
}
void		Function::setParameter(std::string const parameter, int const index)
{
  this->_parameter[index] = parameter;
  return;
}

std::string	Function::getType(void) const
{
  return this->_type;
}
void		Function::setType(std::string const type)
{
  this->_type = type;
  return;
}

std::string	Function::getVisibility(void) const
{
  return this->_visibility;
}
void		Function::setVisibility(std::string const visibility)
{
  this->_visibility = visibility;
  return;
}

int		Function::getNbFunction(void) const
{
  return this->_nbFunction;
}

bool            Function::getStaticOrMembre(void) const
{
  return this->_staticOrMembre;
}

void            Function::setStaticOrMembre(bool const a)
{
  this->_staticOrMembre = a;
  return;
}
