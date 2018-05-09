/*
 * exprtkWrap.cpp
 *
 *  Created on: May 8, 2018
 *      Author: anderssandstrom
 */

#include "exprtkWrap.h"
#include "exprtkImp.h"

exprtkWrap::exprtkWrap ()
{
  exprtk_=new exprtkImp();
}

exprtkWrap::~exprtkWrap ()
{
  delete exprtk_;
}

int exprtkWrap::addVariable(const std::string& variableName, double& d)
{
  return exprtk_->addVariable(variableName,d);
}

int exprtkWrap::compile(std::string expressionString)
{
  return exprtk_->compile(expressionString);
}

void exprtkWrap::refresh(void)
{
  exprtk_->refresh();
}

std::string exprtkWrap::getParserError()
{
  return exprtk_->getParserError();
}
