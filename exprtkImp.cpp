/*
 * exprtkImp.cpp
 *
 *  Created on: May 8, 2018
 *      Author: anderssandstrom
 */

#include "exprtkImp.h"


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
