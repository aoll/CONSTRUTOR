
#include "Variable.class.hpp"

/*
 * Not Menbers Attributs
 */
int	Variable::_nbVariable = 0;

/*
 * Constructor & Destructor
 */
Variable::Variable(void)
{
  this->_nbVariable++;
  return;
}

Variable::Variable(std::string const className):
  _className(className)
{
  this->_nbVariable++;
  std::cout << "Cons String var" << std::endl;
  return;
}
 
Variable::Variable(Variable const &tocopy):
  _value(tocopy._value)
{
  std::cout << "Cons Copy var" << std::endl;
  return;
}
 
Variable::~Variable(void)
{
  this->_nbVariable--;
  std::cout << "Dest var" << std::endl;
}


/*
 *Overload operator function
 */

std::ostream	&operator<<(std::ostream &o, Variable &var)
{
  o << var.getValue();
  return o;
}

Variable      &  Variable::operator=(Variable const &other)
{
  this->_value = other._value;
  return *this;
}

/*
 *
 * Diferent Public Functions
 */
void		Variable::add(void)
{
  
  std::cout << "Enter variable's sweaty name: ";
  std::getline (std::cin,this->_name);

  std::string y = "y";
  std::string n = "n";
  std::string buff;

  std::cout << "Static? [n/y]: ";
  std::getline (std::cin,buff);
  if (buff == y)
    this->_staticOrMembre = true;
  else
    this->_staticOrMembre = false;

  std::cout << "Type? : ";
  std::getline (std::cin,this->_type);

  std::cout << "Value: ";
  std::getline (std::cin,this->_value);

  std::cout << "Visibility: ";
  std::getline (std::cin,this->_visibility);
}

void		Variable::write_file(std::ostream &os)
{
  os <<"\t";
  if (this->_staticOrMembre == true)
    os<<"static ";
  os<<this->getType();
  os<<"\t\t"<<this->getName()<<";"<<std::endl;
}

/*
 *
 * Geter and seter
 */
std::string	Variable::getName(void) const
{
  return this->_name;
}

void		Variable::setName(std::string const src)
{
  this->_name = src;
  return;
}

std::string	Variable::getValue(void) const
{
  return this->_value;
}

void		Variable::setValue(std::string const value)
{
  this->_value = value;
  return;
}

std::string	Variable::getType(void) const
{
  return this->_type;
}

void		Variable::setType(std::string const type)
{
  this->_type = type;
  return;
}

std::string	Variable::getVisibility(void) const
{
  return this->_visibility;
}

void		Variable::setVisibility(std::string const visibility)
{
  this->_visibility = visibility;
  return;
}

std::string	Variable::getClassName(void) const
{
  return this->_className;
}

void		Variable::setClassName(std::string const className)
{
  this->_className = className;
  return;
}

int		Variable::getNbVariable(void) const
{
  return this->_nbVariable;
}

bool		Variable::getStaticOrMembre(void) const
{
  return this->_staticOrMembre;
}

void		Variable::setStaticOrMembre(bool const a)
{
  this->_staticOrMembre = a;
  return;
}
