# Cpractice
Some C exercises from class when I started learning C. I provide the excercise instructions, my code, and my intructor's critique

## Repeats
Instructions: 
"Write a C program in a file named repeats.c that prints the number of words in the input that have repeated letters (e.g. the m's in programming, but not the t's in potato).Be careful with phrases like 'that time Lucy tricked Charlie Brown', which should not be counted as a repeated letter.  Also look out for Mississippi!

The output of the program should be similar to:

'Out of 10 words, 3 had repeated letters'

## Histogram
Instructions: 
"Write a C program in a file named histogram.c that creates a histogram showing the number of occurrences of each letter in the input (case is not important; your program should include a function that converts any upper case letters to lowercase; do not use any built in library functions to do this).

Your program should print create a histogram by printing dashes followed by a pipe; each underscore represents one occurrence of the corresponding letter, e.g., "

Sample output:

a:  --------------|

b:  -------------------------------------|

c:  ---------|

d:  -----------------------------------------------|

e:  --------|

f:  -|

g:  |

...

z:  |

## Palindromes
Instructions:
"In a file named palindromes.c, write a function with the signature:
int isPalindrome (char input[]) that returns 1 if the charters in input are the same forwards and backwards (e.g. civic and deified).  Assume that the parameter input is a '\0' terminated string as described in section 1.9 of the textbook (K & R).

Also include a main function to test your palindrome function.  Its signature should be
int main (int argc, char* argv[])

The main function should ensure that at least 1 command line argument is present by testing the value of argc.  If not, it should print out an error message and terminate by returning a non-zero value (convention is that a non-zero value returned from main indicates an error).  

Note that in a C program, argc is always at least 1, even if no arguments are passed.  The first argument in argv contains the name of the program being run.  Therefore, the value of argc must be at least 2 for there to be any command line arguments.

If there is at least 1 command line argument, the main function should print out a line like this:
Arg 1: civic IS a palindrome
Arg 2: duties IS NOT a palindrome
for each command line argument, and then return 0.

## LinkedList and ArrayList Excercise
Instructions are in a pdf named "ImplementArray/LinkedList" along with the folders containing the files for the assignment.

