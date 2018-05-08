/*
 * exprtkIF.h
 *
 *  Created on: May 8, 2018
 *      Author: anderssandstrom
 */

#ifndef M_EPICS_EXPRTK_EXPRTKIF_H_
#define M_EPICS_EXPRTK_EXPRTKIF_H_
#include <string>

class exprtkIF
{
public:
  exprtkIF ();
  virtual ~exprtkIF ();
  virtual int addVariable(const std::string& variableName, double& d)=0;
  //virtual int setExpression(std::string expressionString)=0;
  //virtual std::string *getExpression()=0;
  virtual int compile(std::string expressionString)=0;
  virtual void refresh()=0;
};

#endif /* M_EPICS_EXPRTK_EXPRTKIF_H_ */
