#include <stdio.h>
#define OUT 0
#define IN 1

int strlen(char s[]);

int main(){
  int c, nw, state,i;
  i=0;
  state = OUT;
  nw = 0;
  char input[1000];
  int count = 0;
  
  while ((c = getchar()) != EOF) {
	  input[i]=c;
	  ++i;
    if (c==' ' || c=='\t' || c=='\n')
      state = OUT;
    else if (state == OUT) {
      state = IN;
      ++nw;  
	  }
    }
    for(i=0;i<strlen(input);i++){
		if(input[i] == input[i+1]){
			count++;
		}
	}
	
	printf("\nOut of %d word(s), %d of them had repeated letters",nw, count);
	
    return 0;
}


int strlen(char s[]){
	int i = 0;
	while(s[i]!='\0'){
		i++;
	}
	return i;
}
