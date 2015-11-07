#ifndef VARIABLE_CLASS_HPP
# define VARIABLE_CLASS_HPP

#include <iostream>
#include <iomanip>

class Variable
{

public:
  /*
   * Constructor & Destructor & Operator's Overload
   */
  Variable(void);
  Variable(std::string const name);
  Variable(Variable const &tocopy);
  ~Variable(void);
  Variable	&operator=(Variable const &other);

  /*
   * Diferent Public Functions
   */

  void		add(void);
  void		write_file(std::ostream &os);
  void		write_file_getter_proto(std::ostream &os_get);
  void		write_file_setter_proto(std::ostream &os_set);
  void		write_file_getter_struct(std::ostream &os_get);
  void		write_file_setter_struct(std::ostream &os_set);
  bool 	checkValideIniVisibility(std::string const visibility);
  /*
   * Seter & Geter
   */
  std::string	getName(void) const;
  void		setName(std::string const src);

  std::string	getType(void) const;
  void		setType(std::string const type);
  
  std::string	getValue(void) const;
  void		setValue(std::string const value);

  std::string	getClassName(void) const;
  void		setClassName(std::string const className);

  std::string	getVisibility(void) const;
  void		setVisibility(std::string const visibility);

  int		getNbVariable(void) const;

  bool		getStaticOrMembre(void) const;
  void		setStaticOrMembre(bool const a);
private:
  std::string	_name;
  std::string	_type;
  std::string	_value;
  std::string	_visibility;
  std::string	_className;
  bool		_staticOrMembre;
  
  static int	_nbVariable;
};

/*
 *
 * OTHER EXTERN CLASS
 */
std::ostream	&operator<<(std::ostream &o, Variable &var);

# endif
