/*
 * exprtkIF.h
 *
 *  Created on: May 8, 2018
 *      Author: anderssandstrom
 */

#ifndef M_EPICS_EXPRTK_EXPRTKIF_H_
#define M_EPICS_EXPRTK_EXPRTKIF_H_
#include <string>
#include <vector>

typedef double (*ff00_functor)();
typedef double (*ff01_functor)(double);
typedef double (*ff02_functor)(double,double);
typedef double (*ff03_functor)(double,double,double);
typedef double (*ff04_functor)(double,double,double,double);
typedef double (*ff05_functor)(double,double,double,double,double);
typedef double (*ff06_functor)(double,double,double,double,double,double);
typedef double (*ff07_functor)(double,double,double,double,double,double,double);
typedef double (*ff08_functor)(double,double,double,double,double,double,double,double);
typedef double (*ff09_functor)(double,double,double,double,double,double,double,double,double);
typedef double (*ff10_functor)(double,double,double,double,double,double,double,double,double,double);
typedef double (*ff11_functor)(double,double,double,double,double,double,double,double,double,double,double);
typedef double (*ff12_functor)(double,double,double,double,double,double,double,double,double,double,double,double);
typedef double (*ff13_functor)(double,double,double,double,double,double,double,double,double,double,double,double,double);
typedef double (*ff14_functor)(double,double,double,double,double,double,double,double,double,double,double,double,double,double);
typedef double (*ff15_functor)(double,double,double,double,double,double,double,double,double,double,double,double,double,double,double);

#define generate_add_function_if_h(NN)                                   \
virtual int addFunction(const std::string& function_name, ff##NN##_functor function)=0; \

class exprtkIF
{
public:
  exprtkIF ();
  virtual ~exprtkIF ();
  virtual int addVariable(const std::string& variableName, double& d)=0;
  generate_add_function_if_h(00)
  generate_add_function_if_h(01)
  generate_add_function_if_h(02)
  generate_add_function_if_h(03)
  generate_add_function_if_h(04)
  generate_add_function_if_h(05)
  generate_add_function_if_h(06)
  generate_add_function_if_h(07)
  generate_add_function_if_h(08)
  generate_add_function_if_h(09)
  generate_add_function_if_h(10)
  generate_add_function_if_h(11)
  generate_add_function_if_h(12)
  generate_add_function_if_h(13)
  generate_add_function_if_h(14)
  generate_add_function_if_h(15)
  virtual int addVector(const std::string& vectorName, double* v, const std::size_t& size)=0;
  virtual int addConstants()=0;
  virtual int addConstant(const std::string& constantName,double& d)=0;
  virtual int addStringvar(const std::string& stringvarName, std::string& s, const bool isConstant)=0;
  virtual int addFileIO()=0;
  virtual int compile(std::string expressionString)=0;
  virtual int compile()=0;
  virtual int setExpression(std::string expressionString)=0;
  virtual std::string getExpression()=0;
  virtual void refresh()=0;
  virtual int collectVariables(std::vector<std::string> &varList)=0;
  virtual int collectFunctions(std::vector<std::string> &funcList)=0;  
  virtual std::string getParserError()=0;
};

#endif /* M_EPICS_EXPRTK_EXPRTKIF_H_ */
