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
#include "exprtk/exprtk.hpp"

typedef exprtk::symbol_table<double> symbol_table_double;
typedef exprtk::expression<double>   expression_double;
typedef exprtk::parser<double>       parser_double;

class exprtkImp: public exprtkIF
{
public:
  exprtkImp ();
  virtual ~exprtkImp ();
  int addVariable(const std::string& variable_name, double& d);
  int compile(std::string expressionString);
  void refresh(void);
  std::string getParserError();
private:
  symbol_table_double symbolTable_;
  expression_double expression_;
  parser_double parser_;
};

#endif /* M_EPICS_EXPRTK_EXPRTKIMP_H_ */
