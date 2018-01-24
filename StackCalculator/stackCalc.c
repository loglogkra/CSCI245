/* KR p. 76-79 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAXOP 100
#define NUMBER '0'
#define ALPHA 1 

int getop(char []);
void push(double);
double pop(void);
double swap(void);
void mathFunctions(char s[]);
int M, j= 0;

main()
{
  int type; /* is it an operator or and operand */
  double op2; /*triangle shift for modulus*/
  char s[MAXOP]; /* hold operands (i.e., numbers) */

  printf("      Post-Fix Calculator\n-------------------------------\n"); 
  while((type = getop(s)) != EOF){
    switch(type){
    case NUMBER:
      push(atof(s));
      break;
    case ALPHA:
		if(s[j]=='M'){
			printf("\t%d\n", M);
		}
      mathFunctions(s);
      break;  
    case '+':
	  M = pop() + pop();
      push(M);
      break;
    case '*':
	  M = pop() * pop();
      push(M);
      break;
    case '-':
      swap();
	  M = pop() - pop();
      push(M);
      break;
    case '%':
      op2 = pop();
      int op3 = pop();
      if(op3 != 0){
      M = ((op3 - (op2 * (int)(op3/op2))));
	  push(M);
      }
      else
		printf("Illegal division of 0\n");
      break;
    case '/':
      op2 = pop();
      if(op2 != 0){
		  M = pop()/op2;
		push(M);
	  }
      else
		printf("error: zero divisor\n");
      break;
    case '\n':
      printf("\t%.8g\n", pop());
      break;
    default:
      printf("error: unknown command %s\n Please enter valid command\n", s);
      break;
    }
  }
  return 0;
}

#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

void push (double f)
{
  if(sp < MAXVAL)
    val[sp++] = f;
  else
    printf("error: stack full, cant push %g\n",f);
}

double pop(void)
{
  if(sp > 0)
    return val[--sp];
  else
    {
      printf("error: stack empty \n");
      return 0.0;
    }
}

double swap(void){
	double a = pop();
	double b = pop();
	push(a);
	push(b);
	return a;
}

void mathFunctions(char s[]){
   double op;
   int i = 0;
   if(strcmp(s, "sin")==0)
      push(sin(pop()));
   else if (strcmp(s, "exp")==0)
      push(exp(pop()));
   else if(strcmp(s, "pow")==0)
   {
      op = pop();
      push(pow(pop(), op));
   }
}

int getch(void);
void ungetch(int);

int getop(char s[])
{
   int i = 0;
   int c, n;
   
   while((s[0] = c = getch()) == ' ' || c == '\t')
      ;
   s[1] = '\0';
   
   if(isalpha(c))
   {
      i = 0;
      while(isalpha(s[i++] = c ))
         c = getch();     
      s[i - 1] = '\0';
      if(c != EOF)
         ungetch(c);
      return ALPHA;
   }
   
   if(!isdigit(c) && c != '.' && c != '-')
      return c;                 
   
   if(c == '-')
   {
      n = getch();
      if(!isdigit(n) && n != '.' && n != ' '){
         return c;
      }
      c = n;
   }
   else
      c = getch();
   
   while(isdigit(s[++i] = c))
      c = getch();
   if(c == '.')           
      while(isdigit(s[++i] = c = getch()))
         ;
      s[i] = '\0';
      if(c != EOF)
         ungetch(c);
      return NUMBER;
}

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
  return(bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
  if(bufp >= BUFSIZE){
    printf("ungetch: too many characters\n");
  }
  else
    {
      buf[bufp++] = c;
    }
}
