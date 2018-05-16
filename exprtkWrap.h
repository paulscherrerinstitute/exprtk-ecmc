/*
 * exprtkWrap.h
 *
 *  Created on: May 8, 2018
 *      Author: anderssandstrom
 */

#ifndef M_EPICS_EXPRTK_EXPRTKWRAP_H_
#define M_EPICS_EXPRTK_EXPRTKWRAP_H_

#include "exprtkIF.h"
#include <string>

#define ERROR_ALLOCATION_FAILED 0x30008

class exprtkWrap: public exprtkIF
{
public:
  exprtkWrap ();
  virtual ~exprtkWrap();
  int addVariable(const std::string& variable_name, double& d);
  int compile(std::string expressionString);
  void refresh(void);
  std::string getParserError();
private:
  exprtkIF *exprtk_;

};

#endif /* M_EPICS_EXPRTK_EXPRTKWRAP_H_ */
