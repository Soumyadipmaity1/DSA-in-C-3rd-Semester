
/*5. Write a program to represent a polynomial equation of 
single variable using single linked list and perform the 
addition of two polynomial equations. */
#include <stdio.h> 
#include <stdlib.h> 
struct Term { 
 int coefficient; 
 int exponent; 
}; 
struct Node { 
 struct Term term; 
 struct Node* next; 
}; 
struct Term createTerm(int coefficient, int exponent) { 
 struct Term term; 
 term.coefficient = coefficient; 
 term.exponent = exponent; 
 return term; 
} 
struct Node* createNode(struct Term term) { 
 struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
 if (newNode == NULL) { 
 printf("Memory allocation failed.\n"); 
 exit(1); 
 } 
 newNode->term = term; 
 newNode->next = NULL; 
 return newNode; 
} 
void insertTerm(struct Node** poly, struct Term term) { 
 struct Node* newNode = createNode(term); 
 if (*poly == NULL) { 
 *poly = newNode; 
 } else { 
 struct Node* current = *poly; 
 while (current->next != NULL) { 
 current = current->next; 
 } 
 current->next = newNode; 
 } 
} 
void inputPolynomial(struct Node** poly) { 
 int n, coefficient, exponent; 
 printf("Enter the number of terms in the polynomial: "); 
 scanf("%d", &n); 
 for (int i = 0; i < n; i++) { 
 printf("Enter coefficient and exponent of term %d: ", i + 1); 
 scanf("%d %d", &coefficient, &exponent); 
 insertTerm(poly, createTerm(coefficient, exponent)); 
 } 
} 
struct Node* addPolynomials(struct Node* poly1, struct Node* poly2) { 
 struct Node* result = NULL; 
 while (poly1 != NULL || poly2 != NULL) { 
 struct Term term; 
 if (poly1 != NULL && poly2 != NULL) { 
 if (poly1->term.exponent == poly2->term.exponent) { 
 term.coefficient = poly1->term.coefficient + poly2->term.coefficient; 
 term.exponent = poly1->term.exponent; 
 poly1 = poly1->next; 
 poly2 = poly2->next; 
 } else if (poly1->term.exponent > poly2->term.exponent) { 
 term = poly1->term; 
 poly1 = poly1->next; 
 } else { 
 term = poly2->term; 
 poly2 = poly2->next; 
 } 
 } else if (poly1 != NULL) { 
 term = poly1->term; 
 poly1 = poly1->next; 
 } else { 
 term = poly2->term; 
 poly2 = poly2->next; 
 } 
 insertTerm(&result, term); 
 } 
 return result; 
} 
void displayPolynomial(struct Node* poly) { 
 if (poly == NULL) { 
 printf("0\n"); 
 return; 
 } 
 while (poly != NULL) { 
 printf("%dx^%d", poly->term.coefficient, poly->term.exponent); 
 poly = poly->next; 
 if (poly != NULL) { 
 printf(" + "); 
 } 
 } 
 printf("\n"); 
} 
void freeLinkedList(struct Node* poly) { 
 struct Node* current = poly; 
 while (current != NULL) { 
 struct Node* temp = current; 
 current = current->next; 
 free(temp); 
 } 
} 
int main() { 
 struct Node* poly1 = NULL; 
 struct Node* poly2 = NULL; 
 struct Node* result = NULL; 
 printf("Enter the first polynomial equation:\n"); 
 inputPolynomial(&poly1); 
 printf("Enter the second polynomial equation:\n"); 
 inputPolynomial(&poly2); 
 result = addPolynomials(poly1, poly2); 
 printf("Result of addition:\n"); 
 displayPolynomial(result); 
 freeLinkedList(poly1); 
 freeLinkedList(poly2); 
 freeLinkedList(result); 
 return 0; 
}