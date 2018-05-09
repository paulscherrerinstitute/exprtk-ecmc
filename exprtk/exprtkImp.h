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



class exprtkImp: public exprtkIF
{
public:
  exprtkImp ();
  virtual ~exprtkImp ();
  int addVariable(const std::string& variable_name, double& d);
//  int setExpression(std::string expressionString);
//  std::string *getExpression(void);
  int compile(std::string expressionString);
  void refresh(void);
  std::string getParserError();
private:
  symbol_table_double symbolTable_;
  expression_double expression_;
  parser_double parser_;
};

#endif /* M_EPICS_EXPRTK_EXPRTKIMP_H_ */
