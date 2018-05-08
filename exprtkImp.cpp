/*
 * exprtkImp.cpp
 *
 *  Created on: May 8, 2018
 *      Author: anderssandstrom
 */

#include "exprtkImp.h"

exprtkImp::exprtkImp ()
{
  // TODO Auto-generated constructor stub

}

exprtkImp::~exprtkImp ()
{
  // TODO Auto-generated destructor stub
}

int exprtkImp::addVariable(const std::string& variableName, double& d)
{
  return !symbolTable_.add_variable(variableName,d);
}

/*int exprtkImp::setExpression(std::string expressionString)
{

}*/

/*std::string exprtkImp::*getExpression(void)
{

}*/

int exprtkImp::compile(std::string expressionString)
{
  return !parser_.compile(expressionString,expression_);
}

void exprtkImp::refresh(void)
{
  expression_.value();
}
