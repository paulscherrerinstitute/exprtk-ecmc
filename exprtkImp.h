/*
 * exprtkImp.h
 *
 *  Created on: May 8, 2018
 *      Author: anderssandstrom
 */

#ifndef M_EPICS_EXPRTK_EXPRTKIMP_H_
#define M_EPICS_EXPRTK_EXPRTKIMP_H_

#include "exprtkIF.h"
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include "exprtk/exprtk.hpp"


#define EXPRTK_ERROR_TAG "ERROR  => : "

typedef exprtk::symbol_table<double> symbol_table_double;
typedef exprtk::expression<double>   expression_double;
typedef exprtk::parser<double>       parser_double;


#define generate_add_function_imp_h(NN)                                       \
int addFunction(const std::string& function_name, ff##NN##_functor function); \

class exprtkImp: public exprtkIF
{
public:
  exprtkImp ();
  virtual ~exprtkImp ();
  int addVariable(const std::string& variableName, double& d);
  generate_add_function_imp_h(00)
  generate_add_function_imp_h(01)
  generate_add_function_imp_h(02)
  generate_add_function_imp_h(03)
  generate_add_function_imp_h(04)
  generate_add_function_imp_h(05)
  generate_add_function_imp_h(06)
  generate_add_function_imp_h(07)
  generate_add_function_imp_h(08)
  generate_add_function_imp_h(09)
  generate_add_function_imp_h(10)
  generate_add_function_imp_h(11)
  generate_add_function_imp_h(12)
  generate_add_function_imp_h(13)
  generate_add_function_imp_h(14)
  generate_add_function_imp_h(15)
  int addVector(const std::string& vectorName, double* v, const std::size_t& size);
  int addConstants();
  int addConstant(const std::string& constantName,double& d);
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
  void initVars();
  int getLineNumber(std::string str, size_t index);
  symbol_table_double symbolTable_;
  expression_double expression_;
  parser_double parser_;
  exprtk::rtl::io::file::package<double> fileio_package_;
  exprtk::rtl::io::println<double>       println_;
  exprtk::rtl::io::print<double>         print_;
  std::string expressionString_;
};

#endif /* M_EPICS_EXPRTK_EXPRTKIMP_H_ */
