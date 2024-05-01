//A3Q4 WAP to represent a polynomial of single variable using 1-D array and perform addition of two polynomial equations.

#include <stdio.h>
struct Term {
    int coefficient;
    int exponent;
};
void addPolynomials(struct Term poly1[], int size1, struct Term poly2[], int size2, struct Term result[], int *size3) {
    int i = 0, j = 0, k = 0;
    
    while (i < size1 && j < size2) {
        if (poly1[i].exponent > poly2[j].exponent) {
            result[k++] = poly1[i++];
        } else if (poly1[i].exponent < poly2[j].exponent) {
            result[k++] = poly2[j++];
        } else {
            result[k].exponent = poly1[i].exponent;
            result[k].coefficient = poly1[i].coefficient + poly2[j].coefficient;
            i++;
            j++;
            k++;
        }
    }
    while (i < size1) {
        result[k++] = poly1[i++];
    }
    
    while (j < size2) {
        result[k++] = poly2[j++];
    }
    
    *size3 = k;
}
void displayPolynomial(struct Term poly[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%dx^%d", poly[i].coefficient, poly[i].exponent);
        if (i < size - 1) {
            printf(" + ");
        }
    }
    printf("\n");
}
int main() {
    struct Term poly1[10], poly2[10], result[20];
    int size1, size2, size3;
    
    printf("Enter the number of terms in the first polynomial: ");
    scanf("%d", &size1);
    printf("Enter the coefficients and exponents of the terms:\n");
    for (int i = 0; i < size1; i++) {
        scanf("%d %d", &poly1[i].coefficient, &poly1[i].exponent);
    }
    
    printf("Enter the number of terms in the second polynomial: ");
    scanf("%d", &size2);
    printf("Enter the coefficients and exponents of the terms:\n");
    for (int i = 0; i < size2; i++) {
        scanf("%d %d", &poly2[i].coefficient, &poly2[i].exponent);
    }
    addPolynomials(poly1, size1, poly2, size2, result, &size3);
    printf("First polynomial: ");
    displayPolynomial(poly1, size1);
    printf("Second polynomial: ");
    displayPolynomial(poly2, size2);
    printf("Sum of the polynomials: ");
    displayPolynomial(result, size3);
    return 0;
}