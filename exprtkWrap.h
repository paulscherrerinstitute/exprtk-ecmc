/*
 * exprtkWrap.h
 *
 *  Created on: May 8, 2018
 *      Author: anderssandstrom
 */

#ifndef M_EPICS_EXPRTK_EXPRTKWRAP_H_
#define M_EPICS_EXPRTK_EXPRTKWRAP_H_

#include "exprtkIF.h"
#include <string>
#include <vector>

#define ERROR_ALLOCATION_FAILED 0x30008

#define generate_add_function_wrap_h(NN)                                   \
int addFunction(const std::string& function_name, ff##NN##_functor function); \

class exprtkWrap: public exprtkIF
{
public:
  exprtkWrap ();
  virtual ~exprtkWrap();
  int addVariable(const std::string& variable_name, double& d);
  generate_add_function_wrap_h(00)
  generate_add_function_wrap_h(01)
  generate_add_function_wrap_h(02)
  generate_add_function_wrap_h(03)
  generate_add_function_wrap_h(04)
  generate_add_function_wrap_h(05)
  generate_add_function_wrap_h(06)
  generate_add_function_wrap_h(07)
  generate_add_function_wrap_h(08)
  generate_add_function_wrap_h(09)
  generate_add_function_wrap_h(10)
  generate_add_function_wrap_h(11)
  generate_add_function_wrap_h(12)
  generate_add_function_wrap_h(13)
  generate_add_function_wrap_h(14)
  generate_add_function_wrap_h(15)
  int addVector(const std::string& vector_name, double* v, const std::size_t& size);
  int addConstants();
  int addConstant(const std::string& constant_name,double& d);
  int addStringvar(const std::string& stringvarName, std::string& s, const bool isConstant);
  int addFileIO();
  int compile(std::string expressionString);
  int compile();
  int setExpression(std::string expressionString);
  std::string getExpression();
  void refresh(void);
  int collectVariables(std::vector<std::string> &varList);
  int collectFunctions(std::vector<std::string> &funcList);  
  std::string getParserError();
private:
  exprtkIF *exprtk_;

};

#endif /* M_EPICS_EXPRTK_EXPRTKWRAP_H_ */
