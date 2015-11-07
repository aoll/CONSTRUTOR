
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
  return;
}

Variable::Variable(std::string const className):
  _className(className)
{
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
  
  this->_nbVariable++;

  std::cout << "* VARIABLE *"<<std::endl;

  while(this->checkValideIniVisibility(this->_visibility) == false)
    {
      std::cout << "Visibility variable: ";
      std::getline (std::cin,this->_visibility);
    }
  if (this->_visibility == "private")
    {
      while(this->_name[0] != '_')
	{
	  std::cout << "Private Variable must be prefixed by '_'"<<std::endl;
	  std::cout << "Enter variable name: ";
	  std::getline (std::cin,this->_name);
	}
    }
  else
    {
      	  std::cout << "Enter variable name: ";
	  std::getline (std::cin,this->_name);
    }

  std::string y = "y";
  std::string n = "n";
  std::string buff;

  std::cout << "Static? [n/y]: ";
  std::getline (std::cin,buff);
  if (buff == y)
    this->_staticOrMembre = true;
  else
    this->_staticOrMembre = false;

  std::cout << "Type: ";
  std::getline (std::cin,this->_type);
  /* //Not use for the moment
  std::cout << "Value: ";
  std::getline (std::cin,this->_value);
  */
  
}

void		Variable::write_file(std::ostream &os)
{
  
  os <<"\t";
  if (this->_staticOrMembre == true)
    os<<"static ";
  os<<this->getType();
  os<<"\t\t"<<this->getName()<<";"<<std::endl;
}

void		Variable::write_file_getter_proto(std::ostream &os_get)
{
  std::string buff;

  buff = this->getName();
  buff[0] = 't';  // replace _ by 't' for complete le ge 
  buff[1] = buff[1] -32; // Upper the "first" c
  os_get <<"\t";
  if (this->_staticOrMembre == true)
    os_get<<"static ";
  os_get<<this->getType();
  os_get<<"\t\tge"<<buff<<"(void) const;"<<std::endl;
  
}

void		Variable::write_file_setter_proto(std::ostream &os_set)
{
  std::string buff;

  buff = this->getName();
  buff[0] = 't';  // replace _ by 't' for complete le se 
  buff[1] = buff[1] -32; // Upper the "first" c
  os_set <<"\t";
  if (this->_staticOrMembre == true)
    os_set<<"static ";
  os_set<<this->getType();
  os_set<<"\t\tse"<<buff<<"(";

  buff[0] = ' ';  // replace 't' by ' '
  buff[1] = buff[1] +32; // Loupper the "first" c
  os_set<<this->getType()<<" const"<<buff<< ");"<<std::endl<<std::endl;
}

void		Variable::write_file_getter_struct(std::ostream &os_get)
{
  std::string buff;

  buff = this->getName();
  buff[0] = 't';  // replace _ by 't' for complete le ge 
  buff[1] = buff[1] -32; // Upper the "first" c
  
  if (this->_staticOrMembre == true)
    os_get<<"static ";
  os_get<<this->getType();
  os_get<<"\t\t"<<this->getClassName()<<"::";
  os_get<<"ge"<<buff<<"(void) const"<<std::endl;
  os_get<<"{"<<std::endl;
  os_get<<"\t"<<"return this->"<<this->getName()<<";"<<std::endl;
  os_get<<"}"<<std::endl;
  
}

void		Variable::write_file_setter_struct(std::ostream &os_set)
{
  std::string buff;

  buff = this->getName();
  buff[0] = 't';  // replace _ by 't' for complete le se 
  buff[1] = buff[1] -32; // Upper the "first" c
  
  if (this->_staticOrMembre == true)
    os_set<<"static ";
  os_set<<this->getType();
  os_set<<"\t\t"<<this->getClassName()<<"::";
  os_set<<"se"<<buff<<"(";

  buff[0] = ' ';  // replace 't' by ' '
  buff[1] = buff[1] +32; // Loupper the "first" c
  os_set<<this->getType()<<" const"<<buff<< ")"<<std::endl;
  os_set<<"{"<<std::endl;
  os_set<<"\t"<<"this->"<<this->getName()<<" ="<< buff<<";"<<std::endl;
  os_set<<"}"<<std::endl;
}

bool          Variable::checkValideIniVisibility(std::string const visibility)
{
  if (visibility == "private")
    return true;
  else if (visibility == "public")
    return true;
  else if (visibility == "protected")
    return true;
  return false;
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
