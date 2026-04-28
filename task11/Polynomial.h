#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include "arrayList.h"

typedef arrayList polynomial;
typedef elementArrayList elementType;

// 함수 선언
polynomial* createPolynomial(int capacity);
polynomial* addItemPolynomial(polynomial* po, elementType item);
polynomial* addPolynomial(polynomial* p1, polynomial* p2);
void printPolynomial(polynomial* po);

#endif