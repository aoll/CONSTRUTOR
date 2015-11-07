#ifndef FUNCTION_CLASS_HPP
# define FUNCTION_CLASS_HPP

#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib> 
class Function
{

public:
  /*
   * Constructor & Destructor & Overload's Operator
   */
  Function(void);
  Function(std::string const nameClass);
  Function(Function const &tocopy);
  ~Function(void);
  Function	&operator=(Function const &other);

  /*
   * Different Public Function
   */
  void		add(void);
  void		print(void);
  void          writeFunctionPrototype(std::ostream &os);  
  void          writeFunctionStruct(std::ostream &os);  
  bool		checkValideIniVisibility(std::string const visibility);
  /*
   * Getter & Setter
   */
  std::string	getName(void) const;
  void		setName(std::string const src);
  std::string	getType(void) const;
  void		setType(std::string const type);
  int		getNbParameter(void) const;
  void		setNbParameter(int const nbParameter);
  std::string	getParameter(int const nb);
  void		setParameter(std::string const parameter, int const index);
  std::string	getVisibility(void) const;
  void		setVisibility(std::string const visibility);
  int		getNbFunction(void) const;
  
  bool		getStaticOrMembre(void) const;
  void		setStaticOrMembre(bool const a);
  
  std::string	getClassName(void) const;
  void		setClassName(std::string const src);
private:
  std::string	_name;
  std::string	_nameClass;
  std::string	_type;
  int		_nbParameter;
  std::string	_parameter[4];
  std::string	_visibility;
  bool		_staticOrMembre;

  static int	_nbFunction;
};

/*
 * OTHER EXTERN CLASS
 */
std::ostream	&operator<<(std::ostream &o, Function &var);

# endif
