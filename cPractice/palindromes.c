#include <stdio.h>

int isPalindrome(char input[]);
int strlen(char s[]);

int main (int argc, char* argv[]){
	
	int i;
	
	if(argc<2){
		puts("You did not type anything after the executable!\n");
		return 1;
	}
	
	for(i = 1; i < argc; i++) {
        printf("arg %d: %s ", i, argv[i]);
        isPalindrome(argv[i]);
    }
	
	return(0);
}

int isPalindrome (char input[]){
	int i,j,bool;
	bool = 0;
	char copy[strlen(input)];
	for(i=0, j=strlen(input)-1; i<strlen(input);i++,j--){
		copy[j]=input[i];
	}
	for(i=0; i<strlen(input); i++){
		if(copy[i]!=input[i]){
			bool = 1;
		}
		else{
			bool = 0;
		}
	}
	if(bool==0){
		printf("is a palindrome\n");
	}
	else{
		printf("is not a palindrome\n");
	}
	return 0;
}

int strlen(char s[]){
	int i = 0;
	while(s[i]!='\0'){
		i++;
	}
	return i;
}
