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
