#include <iostream>
#include "Polynomial.h"


using namespace std;

Polynomial::Polynomial() {

    head->predecessor = nullptr;
    head->successor = nullptr;
    head->coef = 0;
    head->exp = 0;

    tail = head;

}

Polynomial::~Polynomial() = default;

void Polynomial::addATerm(int exp, double coef) {

    Term *newTerm = new Term;

    newTerm->exp = exp;
    newTerm->coef = coef;

    newTerm->successor = nullptr;
    newTerm->predecessor = tail;
    tail->successor = newTerm;

    tail = newTerm;

}

void Polynomial::combineTerms() {

    Term *cur = head;
    bool isCombined = false;

    while(cur->successor != nullptr){

        if(!isCombined)
            cur = cur->successor;

        isCombined = false;

        if(cur->successor == nullptr)
            break;

        if(cur->exp == cur->successor->exp){

            if(cur->successor->successor != nullptr){
                cur->coef += cur->successor->coef;
                cur->successor->successor->predecessor = cur;
                cur->successor = cur->successor->successor;
            }else{
                cur->coef += cur->successor->coef;
                cur->successor = nullptr;
            }

            isCombined = true;

        }

        if(cur->coef == 0){

            Term *tmp = cur->successor;
            cur->successor->predecessor = cur->predecessor;
            cur->predecessor->successor = cur->successor;

            cur = tmp;

        }


    }


}

void Polynomial::sortPoly() {

    bool isChanged;

    do{

        Term *cur = head;
        isChanged = false;

        while(cur->successor != nullptr){

            cur = cur->successor;

            if(cur->successor == nullptr)
                break;

            if(cur->exp > cur->successor->exp){

                double tmpCoef = cur->coef;
                cur->coef = cur->successor->coef;
                cur->successor->coef = tmpCoef;

                int tmpExp = cur->exp;
                cur->exp = cur->successor->exp;
                cur->successor->exp = tmpExp;

                isChanged = true;

            }

        }

    }while(isChanged);

}

void Polynomial::inputPoly() {

    cout << "请依次输入多项式每项的系数和指数（常数n输入n 0）,输入－100 -100以结束" << endl;

    double coef;
    int exp;

    for(;;){

        cin >> coef >> exp;

        if(coef == -100 && exp == -100)
            break;

        this->addATerm(exp, coef);

    }

    this->sortPoly();
    this->combineTerms();

}

void Polynomial::outputPoly() {

    Term *cur = head;
    bool isFirst = true;

    cout << "表达式为：";

    while(cur->successor != nullptr){

        cur = cur->successor;

        if(isFirst){

            if(cur->coef != 1)
                cout << cur->coef;

            isFirst = false;

        }else{

            if(cur->coef > 1)
                cout << "+" << cur->coef;
            if(cur->coef < 0)
                cout << cur->coef;
            if(cur->coef == 1)
                cout << "+";

        }

        if(cur->exp == 1)
            cout << "x";
        if(cur->exp > 1)
            cout << "x^" << cur->exp;
        if(cur->exp < 0)
            cout << "x^(" << cur->exp << ")";

    }

    cout << endl;

}

Polynomial operator* (const Polynomial& A, const Polynomial& B) {

    Polynomial C;
    Term *curA = A.head;
    Term *curB = B.head;

    while(curA->successor != nullptr){

        curA = curA->successor;

        curB = B.head;

        while(curB->successor != nullptr){

            curB = curB->successor;

            C.addATerm(curA->exp+curB->exp, curA->coef*curB->coef);

        }

    }

    C.sortPoly();
    C.combineTerms();

    return C;

}


int main()
{

    Polynomial ah,bh,ch;
    ah.inputPoly();      //input polynomial a
    ah.outputPoly();
    bh.inputPoly();      //input polynomial b
    bh.outputPoly();
    ch = ah*bh;
    ch.outputPoly();    //output the result
    return 0;

}