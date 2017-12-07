//
// Created by Evan Choo on 17/10/30.
//

#ifndef FIRST_POLYNOMIAL_H
#define FIRST_POLYNOMIAL_H

#include "Term.h"

class Polynomial{

public:

    Term *head = new Term;
    Term *tail = new Term;

    Polynomial();
    ~Polynomial();
    void addATerm(int exp, double coef); //添加一项
    void combineTerms();                 //将指数相同的项合并
    void sortPoly();                    //将项按照升序排列
    void inputPoly();                   //处理输入的多项式
    void outputPoly();                  //将多项式输出

    friend Polynomial operator* (const Polynomial& A, const Polynomial& B); //重载运算符＊

};

#endif //FIRST_POLYNOMIAL_H
