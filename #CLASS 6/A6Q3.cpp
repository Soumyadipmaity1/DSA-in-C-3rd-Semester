//3. WAP to convert an infix expression into its equivalent postfix  notation using stack. 


#include <stdio.h> 
#include <stdlib.h> 
#include <ctype.h> 
struct CharStack { 
 char data; 
 struct CharStack* next; 
}; 
void initializeCharStack(struct CharStack** stack) { 
 *stack = NULL; 
} 
void pushChar(struct CharStack** stack, char ch) { 
 struct CharStack* newNode = (struct CharStack*)malloc(sizeof(struct CharStack)); 
 if (newNode == NULL) { 
 printf("Memory allocation failed. Cannot push character.\n"); 
 exit(1); 
 } 
 newNode->data = ch; 
 newNode->next = *stack; 
 *stack = newNode; 
} 
char popChar(struct CharStack** stack) { 
 if (*stack == NULL) { 
 printf("Character stack is empty. Cannot pop character.\n"); 
 exit(1); 
 } 
 char ch = (*stack)->data; 
 struct CharStack* temp = *stack; 
 *stack = (*stack)->next; 
 free(temp); 
 return ch; 
} 
int isOperator(char ch) { 
 return (ch == '+' || ch == '-' || ch == '*' || ch == '/'); 
} 
void infixToPostfix(char* infixExpression) { 
 struct CharStack* charStack; 
 initializeCharStack(&charStack); 
 int infixIndex = 0; 
 int postfixIndex = 0; 
 char postfixExpression[100]; 
 while (infixExpression[infixIndex] != '\0') { 
 char currentChar = infixExpression[infixIndex]; 
 if (isalnum(currentChar)) { 
 postfixExpression[postfixIndex++] = currentChar; 
 } else if (isOperator(currentChar)) { 
 while (charStack != NULL && isOperator(charStack->data) && charStack->data 
!= '(') { 
 postfixExpression[postfixIndex++] = popChar(&charStack); 
 } 
 pushChar(&charStack, currentChar); 
 } else if (currentChar == '(') { 
 pushChar(&charStack, currentChar); 
 } else if (currentChar == ')') { 
 while (charStack != NULL && charStack->data != '(') { 
 postfixExpression[postfixIndex++] = popChar(&charStack); 
 } 
 if (charStack == NULL || charStack->data != '(') { 
 printf("Invalid infix expression. Mismatched parentheses.\n"); 
 exit(1); 
 } else { 
 popChar(&charStack); 
 } 
 } 
 infixIndex++; 
 } 
 while (charStack != NULL) { 
 if (charStack->data == '(') { 
 printf("Invalid infix expression. Mismatched parentheses.\n"); 
 exit(1); 
 } 
 postfixExpression[postfixIndex++] = popChar(&charStack); 
 } 
 postfixExpression[postfixIndex] = '\0'; 
 printf("Postfix expression: %s\n", postfixExpression); 
} 
int main() { 
 char infixExpression[100]; 
 
 printf("Enter an infix expression: "); 
 scanf("%s", infixExpression); 
 infixToPostfix(infixExpression); 
 return 0; 
}