/*
 * exprtkImp.cpp
 *
 *  Created on: May 8, 2018
 *      Author: anderssandstrom
 */

#include "exprtkImp.h"

#define generate_add_function_imp_cpp(NN)                                                \
int exprtkImp::addFunction(const std::string& functionName, ff##NN##_functor function)   \
{                                                                                        \
  return !symbolTable_.add_function(functionName,function);                              \
}                                

generate_add_function_imp_cpp(00)
generate_add_function_imp_cpp(01)
generate_add_function_imp_cpp(02)
generate_add_function_imp_cpp(03)
generate_add_function_imp_cpp(04)
generate_add_function_imp_cpp(05)
generate_add_function_imp_cpp(06)
generate_add_function_imp_cpp(07)
generate_add_function_imp_cpp(08)
generate_add_function_imp_cpp(09)
generate_add_function_imp_cpp(10)
generate_add_function_imp_cpp(11)
generate_add_function_imp_cpp(12)
generate_add_function_imp_cpp(13)
generate_add_function_imp_cpp(14)
generate_add_function_imp_cpp(15)

exprtkImp::exprtkImp ()
{
  symbolTable_.add_constants();
}

exprtkImp::~exprtkImp ()
{
}

int exprtkImp::addVariable(const std::string& variableName, double& d)
{
  return !symbolTable_.add_variable(variableName,d);
}

int exprtkImp::compile(std::string expressionString)
{
  expression_.register_symbol_table(symbolTable_);
  return !parser_.compile(expressionString,expression_);
}

void exprtkImp::refresh(void)
{
  expression_.value();
}

std::string exprtkImp::getParserError()
{
  return parser_.error();
}

int exprtkImp::addVector(const std::string& vectorName, double* v, const std::size_t& size)
{
  return  !symbolTable_.add_vector(vectorName,v,size);
}

int exprtkImp::addConstants()
{
  return  !symbolTable_.add_constants();
}

int exprtkImp::addConstant(const std::string& constantName,double& d)
{
  return !symbolTable_.add_constant(constantName,d);
}

int exprtkImp::addStringvar(const std::string& stringvarName, std::string& s, const bool isConstant)
{
  return !symbolTable_.add_stringvar(stringvarName,s,isConstant);
}

int exprtkImp::addFileIO()
{
  if(!symbolTable_.add_function("println",println_)){
    return 1;
  }
  if(!symbolTable_.add_function("print",print_)){
    return 2;
  }  
  if(!symbolTable_.add_package (fileio_package_)){
    return 3;
  }
  return 0;
}