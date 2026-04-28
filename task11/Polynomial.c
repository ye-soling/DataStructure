#include "Polynomial.h"
#include <stdio.h>

polynomial* createPolynomial(int capacity) {
	return (polynomial*)createArrayList(capacity);
}

polynomial* addItemPolynomial(polynomial* po, elementType item) {
	int i;

	for (i = 0; i < sizeArrayList(po); i++) {
		if (po->data[i].expo < item.expo) {
			break;
		}

		if (po->data[i].expo == item.expo) {
    		po->data[i].coef += item.coef;

    		if (po->data[i].coef == 0) {
        		deleteArrayList(po, i);
   			}

    		return po;
		}
	}

	insertArrayList(po, i, item);
	return po;
}

polynomial* addPolynomial(polynomial* p1, polynomial* p2) {
	polynomial* r = createPolynomial(100);

	int i = 0, j = 0;

	while (i < sizeArrayList(p1) && j < sizeArrayList(p2)) {

		if (p1->data[i].expo > p2->data[j].expo) {
			addItemPolynomial(r, p1->data[i]);
			i++;
		}
		else if (p1->data[i].expo < p2->data[j].expo) {
			addItemPolynomial(r, p2->data[j]);
			j++;
		}
		else {
			elementType temp = {
				p1->data[i].coef + p2->data[j].coef,
				p1->data[i].expo
			};
			addItemPolynomial(r, temp);
			i++;
			j++;
		}
	}

	while (i < sizeArrayList(p1)) {
		addItemPolynomial(r, p1->data[i]);
		i++;
	}

	while (j < sizeArrayList(p2)) {
		addItemPolynomial(r, p2->data[j]);
		j++;
	}

	return r;
}

void printPolynomial(polynomial* po) {
	printf("Polynomial:\n");
	printArrayList(po);
	printf("\n");
}