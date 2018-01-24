#include <stdio.h>
#define LIMIT 2000

int toLower(int c);
int strlen(char s[]);

int main()
{
	int c;
    int i,i2;
    i=i2=0;
    int count[26]= {0}; //Only 26 letters in alphabet
    char ch = 97;  //ASCII for lowercase a
    char s[LIMIT];
    
    while((c=getchar())!=EOF){
		s[i]=toLower(c);
		++i;
	}
    for (i = 0; i < strlen(s); i++)  
    {
        for(i2=0;i2<26;i2++)
            {
            if (s[i] == (ch+i2))
                {
                    count[i2]++;
                }
        }
    }
    for(i2=0;i2<26;i2++)
        {	
            printf("%c:  ",ch+i2);
            //will only work if certain letter appears less than this amount of dashes below!!!!!! FIX this!!!
            printf("%.*s", count[i2], "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------");
            printf("|\n");
    }
	return 0;
}

int toLower(int c){
	if(c>='A' && c<='Z'){
		return c + 'a' - 'A';
	}
	else{
		return c;
	}
}

int strlen(char s[]){
	int i = 0;
	while(s[i]!='\0'){
		i++;
	}
	return i;
}
