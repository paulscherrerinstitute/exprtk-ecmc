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
  initVars();
  symbolTable_.add_constants();  
}

exprtkImp::~exprtkImp ()
{
}

void exprtkImp::initVars()
{
  expressionString_="";
}

int exprtkImp::addVariable(const std::string& variableName, double& d)
{
  return !symbolTable_.add_variable(variableName,d);
}

int exprtkImp::compile(std::string expressionString)
{
  expressionString_=expressionString;
  expression_.register_symbol_table(symbolTable_);  
  return !parser_.compile(expressionString,expression_);
}

int exprtkImp::compile()  
{
  return compile(expressionString_);
}

int exprtkImp::setExpression(std::string expressionString)  
{
  expressionString_=expressionString;
  return 0;
}

std::string exprtkImp::getExpression()  
{
  return expressionString_;  
}

void exprtkImp::refresh(void)
{
  expression_.value();
}

std::string exprtkImp::getParserError()
{
  std::stringstream ss;
  std::string exprStingWithError=expressionString_;
  int addedChars=0;
  int lineNumberOld=-1;
  for (std::size_t i = 0; i < parser_.error_count(); ++i)
  {
    exprtk::parser_error::type error = parser_.get_error(i);    
    int lineNumber=getLineNumber(expressionString_,error.token.position);    
    ss << "\n----------------------------------------------------------------------\n"
       << "Error Index: " << i << "\n"
       << "Position:    " << error.token.position << "\n"
       << "Line Number: " << lineNumber << "\n"
       << "Type:        " << exprtk::parser_error::to_str(error.mode).c_str() << "\n"
       << "Diagnostic:  " << error.diagnostic.c_str() << "\n";  

    // Add ERROR TAG to beginning of row (Must compensate for the chars added in previous error)
    if(lineNumberOld!=lineNumber){
      if(exprStingWithError.length()>error.token.position+addedChars){
        size_t pos=exprStingWithError.rfind('\n',error.token.position+addedChars);
        if(pos+1<exprStingWithError.length()){
          exprStingWithError.insert(pos+1,EXPRTK_ERROR_TAG);
          addedChars+=strlen(EXPRTK_ERROR_TAG);
        }      
      }
    }
    lineNumberOld=lineNumber;
  }
  ss << "----------------------------------------------------------------------\n";
  ss << "Code (errors are marked with \"" << EXPRTK_ERROR_TAG << "\"):\n\n";   
  ss << exprStingWithError.c_str() << "\n";  
  ss << "----------------------------------------------------------------------\n\n";
  return ss.str();
}

int exprtkImp::getLineNumber(std::string str, size_t index)
{
  int lines=0;
  for(size_t i=0;i<index;i++){
    if(i>=str.length()){
      return lines;
    }
    if(str[i]=='\n'){
      lines++;
    }
  }
  
  return lines;
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

int exprtkImp::collectVariables(std::vector<std::string> &varList)
{
  return !exprtk::collect_variables(expressionString_,symbolTable_,varList);
}

int exprtkImp::collectFunctions(std::vector<std::string> &funcList)  
{
  return !exprtk::collect_functions(expressionString_,symbolTable_,funcList);  
}