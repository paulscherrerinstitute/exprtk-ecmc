/*
 * exprtkWrap.cpp
 *
 *  Created on: May 8, 2018
 *      Author: anderssandstrom
 */

#include "exprtkWrap.h"
#include "exprtkImp.h"

#define generate_add_function_wrap_cpp(NN)                                               \
int exprtkWrap::addFunction(const std::string& function_name, ff##NN##_functor function) \
{                                                                                        \
  if(!exprtk_){                                                                          \
    return ERROR_ALLOCATION_FAILED;                                                      \
  }                                                                                      \
  return exprtk_->addFunction(function_name,function);                                   \
}                                                                                        \

generate_add_function_wrap_cpp(00)
generate_add_function_wrap_cpp(01)
generate_add_function_wrap_cpp(02)
generate_add_function_wrap_cpp(03)
generate_add_function_wrap_cpp(04)
generate_add_function_wrap_cpp(05)
generate_add_function_wrap_cpp(06)
generate_add_function_wrap_cpp(07)
generate_add_function_wrap_cpp(08)
generate_add_function_wrap_cpp(09)
generate_add_function_wrap_cpp(10)
generate_add_function_wrap_cpp(11)
generate_add_function_wrap_cpp(12)
generate_add_function_wrap_cpp(13)
generate_add_function_wrap_cpp(14)
generate_add_function_wrap_cpp(15)

exprtkWrap::exprtkWrap ()
{
  exprtk_=new exprtkImp();
  if(!exprtk_){
    printf("%s/%s:%d: FAILED TO ALLOCATE MEMORY FOR EXPRTK.\n",__FILE__,__FUNCTION__,__LINE__);
    exit(EXIT_FAILURE);
  }
}

exprtkWrap::~exprtkWrap ()
{
  delete exprtk_;
}

int exprtkWrap::addVariable(const std::string& variableName, double& d)
{
  if(!exprtk_){
    return ERROR_ALLOCATION_FAILED;
  }
  return exprtk_->addVariable(variableName,d);
}

int exprtkWrap::compile(std::string expressionString)
{
  if(!exprtk_){
    return ERROR_ALLOCATION_FAILED;
  }
  return exprtk_->compile(expressionString);
}

int exprtkWrap::compile()  
{
  if(!exprtk_){
    return ERROR_ALLOCATION_FAILED;
  }

  return exprtk_->compile();  
}

int exprtkWrap::setExpression(std::string expressionString)  
{
  if(!exprtk_){
    return ERROR_ALLOCATION_FAILED;
  }

  return exprtk_->setExpression(expressionString);  
}

std::string exprtkWrap::getExpression()  
{
  return exprtk_->getExpression();  
}

void exprtkWrap::refresh(void)
{
  if(!exprtk_){
    return;
  }
  exprtk_->refresh();
}

std::string exprtkWrap::getParserError()
{
  if(!exprtk_){
    return "EXPRTK OBJECT NULL";
  }
  return exprtk_->getParserError();
}

int exprtkWrap::addVector(const std::string& vectorName, double* v, const std::size_t& size)
{
  if(!exprtk_){
    return ERROR_ALLOCATION_FAILED;
  }
  return exprtk_->addVector(vectorName, v,size);
}

int exprtkWrap::addConstants()
{
  if(!exprtk_){
    return ERROR_ALLOCATION_FAILED;
  }
  return exprtk_->addConstants();
}

int exprtkWrap::addConstant(const std::string& constantName,double& d)
{
  if(!exprtk_){
    return ERROR_ALLOCATION_FAILED;
  }
  return exprtk_->addConstant(constantName,d);
}

int exprtkWrap::addStringvar(const std::string& stringvarName, std::string& s, const bool isConstant)
{
  if(!exprtk_){
    return ERROR_ALLOCATION_FAILED;
  }
  return exprtk_->addStringvar(stringvarName,s,isConstant);
}

int exprtkWrap::addFileIO()
{
  if(!exprtk_){
    return ERROR_ALLOCATION_FAILED;
  }
  return exprtk_->addFileIO();
}

int exprtkWrap::collectVariables(std::vector<std::string> &varList)
{
  if(!exprtk_){
    return ERROR_ALLOCATION_FAILED;
  }
  return exprtk_->collectVariables(varList);
}

int exprtkWrap::collectFunctions(std::vector<std::string> &funcList)  
{
  if(!exprtk_){
    return ERROR_ALLOCATION_FAILED;
  }
  return exprtk_->collectFunctions(funcList);  
}