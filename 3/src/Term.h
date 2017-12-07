//
// Created by Evan Choo on 17/10/30.
//

#ifndef FIRST_TERM_H
#define FIRST_TERM_H


class Term {

public:

    Term *predecessor, *successor; //双向链表的节点有两个指针，分别指向前驱和后继
    int exp;                       //指数
    double coef;                   //系数

    friend class Polynomial;

};

#endif //FIRST_TERM_H
