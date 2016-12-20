#include <stdio.h>
int getstr(char *str,size_t length);		// imitacion de fgets y gets
void clear_str(char *str,size_t length);	// imitacion de memset;
int strlen(char *str);						// copia de strlen
char *strcpy(char *dir,char *str);			// copia de strcpy
int strncpy(char *dir,char *str,size_t n);	// copia de strncpy
char *strupr(char *str);					// copia de strupr
char *strlwr(char *str);					// copia de strlwr
char toupper(char c);						// toupper
char tolower(char c);						// tolower
char *strrev(char *str);					// strrev
int strcmp(char *str1,char *str2);			// strcmp
int main(int argc,char **argv) {
	int i;
	char str[20],str2[20],*str3,*str4;
	clear_str(str,sizeof(str));
	getstr(str,sizeof(str));
	printf("getstr(str,size) -> %s,\n",str);
	clear_str(str2,sizeof(str2));
	strcpy(str2,str);
	printf("strcpy(str1,str2) -> %s,\n",str2);
	strupr(str2);
	printf("strupr(str) -> %s,\n",str2);
	strlwr(str2);
	printf("strlwr(str) -> %s,\n",str2);
	strrev(str2);
	printf("strrev(str) -> %s\n",str2);
	strcpy(str2,str);
	printf("strcmp(str1,str2) -> %i\n",strcmp(str,str2));
	
	
	return 0;
}

void clear_str(char *str,size_t length) {
	int i = 0;
	while(i < length) {str[i] = '\0';i++;}
}

int getstr(char *str,size_t length) {
	int i = 1;
	while( ((*str = getchar()) != '\n' && *str != '\r') && i++ < length ) {*str++;}
	*str = '\0';
	return 0;
}

int strlen(char *str) {
	int i = 0;
	while(*str != '\0' && *str != '\n' && *str != '\r' && i < 1000) {
		str++;i++;
	}
	return (i >= 1000)?EOF:i;
}

char *strcpy(char *dir,char *str) {
	int i = 0;
	int length;
	if((length = strlen(str)) == EOF)
		return NULL;
	while(i < length) {
		dir[i] = str[i];
		i++;
	}
	dir[i] = str[i];
	return dir;
}

int strncpy(char *dir,char *str,size_t n) {
	int i;
	for(i = 0; i < n; i++) {
		dir[i] = str[i];
	}
	return 0;
}

char *strupr(char *str) {
	int i = 0,length;
	if((length = strlen(str)) == NULL) 
		return NULL;
	while(i++ < strlen(str)) {
		str[i-1] = toupper(str[i-1]);
	}
	return str;
}

char *strlwr(char *str) {
	int i = 0,length;
	if((length = strlen(str)) == EOF)
		return NULL;
	while(i++ < length) {
		str[i-1] = tolower(str[i-1]);
	}
	return str;
}

char toupper(char c) {
	if(c >= 97 && c <= 122) {
		return c-32;
	}
}

char tolower(char c) {
	if(c >= 65 && c <= 90) {
		return c+32;
	}
}
char *strrev(char *str) {
	int j,i,length;
	char tmp;
	if((length = strlen(str)) != EOF) {
		i = 0;
		j = length - 1;
		while(i <= j) {
			tmp = str[j];
			str[j] = str[i];
			str[i] = tmp;
			i++;j--;
		}
		str[length] = '\0';
		return str;
	}
	return NULL;
}
int strcmp(char *str1,char *str2) {
	int cont,cont2,i,j;
	int length_str1 = strlen(str1),length_str2 = strlen(str2);
	char *str1_aux = str1,*str2_aux = str2;
	i = 0;
	while(i < length_str1) {
		str1_aux[i] = tolower(str1_aux[i]);
		i++;
	}
	j = 0;
	while(j < length_str2) {
		str2_aux[j] = tolower(str2_aux[j]);
		j++;
	}
	if(length_str1 == length_str2) {
		cont = 0;
		for(i = 0; i < j; i++)
			if(str1_aux[i] == str2_aux[i]) {cont++;}
		if(cont == length_str1)
			return 0;
	}
	
	for(i = 0; i < length_str1; i++) {
		if(str1_aux[i] > str2_aux[i]) {
			return -1;
		}
		else if(str1_aux[i] < str2_aux){
			return 1;
		}
	}
}
