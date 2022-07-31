#include <stdio.h>
#include <stdlib.h>

void  swap(char*, char*);
int   str_len(char* str);
char  str_is_symmetry(char*);
char* str_concat(const char*, const char*);
void  str_copy(char*, const char*);
void  str_rev(char*);
char  str_find_char(const char*, char);
void  str_find_substr(char*, const char);
void  str_lower(char*);
void  str_upper(char*);
void  str_capital(char*);
 
int main(){
	return 0;
}

/*
 *\brief			swap 2 character	
 *\param[in]
 *\param[in]
 *\return			
 */
void
swap(char* a, char* b) {
	*b += *a;
	*a = *b - *a;
	*b -= *a;
}
					
/*
 *\brief			get length of string
 *\param[in]
 *\return			
 */
int 
str_len(char* str){
    int i = 0;
    while(*(str++) != '\0') {
    	i++;
	}
    
    return i;
}

/*
 *\brief			check a string is symmetry 	
 *\param[in]
 *\return			
 */
char 
is_symmetry(char* str) {
    int i;
    for (i = 0; i < [str_len(str) / 2]; i++) {
        if (str[i] != str[str_len(str) - 1 - i]) {
            return 0;
        }
    }
    return 1;
}

/*
 *\brief			concatenate 2 string
 *\param[in]
 *\return			
 */
char* 
str_concat(char* str_1, char* str_2) {
	char* des = (char *) malloc(str_len(str_1) + str_len(str_2) + 1);

	while (*str_1 != '\0') {
		*des = *str_1;
		str_1++;
	}
		
	while(*str_2 != '\0') {
		*des = *str_2;
		str_2++;
	}
	
	*des = '\0';
	
	return des;
}

/*
 *\brief			copy a string
 *\param[in]
 *\return			
 */
void  
str_copy(char* des, const char* src) {
	while (*src != '\0') {
		*des = *src;
		des++;
		src++;
	}
	
	*des = '\0';
}
					
/*
 *\brief			reverse a string
 *\param[in]
 *\return			
 */
void 
str_rev(char* str) {
	int i;
	int len = str_len(str);
	
	for (i = 0; i < (len / 2); i++) {
		swap(&str[i], &str[len - i - 1]);
	}
	
}

/*
 *\brief			find a character in a string
 *\param[in]
 *\return			
 */
char 
find_char(const char* str, char key) {
    int i, cnt = 0;
    for (i = 0; i < str_len(str); i++) {
        if (key == str[i]) {
            cnt++;
        }
    }
    
    if (cnt > 0) {
        printf("\nki tu %c trong chuoi xuat hien %d lan ", key, cnt);
    }
    
    if (cnt == 0) {
        return 1;
    }
}

/*
 *\brief			find a sub-string in a string and the times of appearance of sub-string
 *\param[in]
 *\return			
 */
void 
find_substr(char* sub_str, const char* str) {
   int i, j;
   int times = 0;

   int len = strlen(s2);
  
   while(s1[n] != '\0') {
  
      if(*sub_str == *str) {    
         while((*sub_str == *str)  && s1[n] !='\0') {
            n++;
            m++;
         }
  
         // Neu day ky tu nay co do dai bang chuoi tim kiem
         if(m == len && (s1[n] == ' ' || s1[n] == '\0')) {
  
            // Chuc mung ban da tim ra chuoi can tim
            times++;
         }
      } else {   // Neu ky tu dau tien khong giong nhau
         while(s1[n] != ' ') {    //bo qua, tiep tuc tim kiem tu tiep theo
            n++;
            if(s1[n] == '\0')
            break;
         }
      }
          
      n++;
      m=0;  // reset bien dem.
   }
}
					
/*
 *\brief			convert a string to lowercase
 *\param[in]
 *\return			
 */
void 
str_lower(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32;
        }
    }
}

/*
 *\brief			convert a string to uppercase
 *\param[in]
 *\return			
 */
void 
str_upper(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 32;
        }
    }
}

/*
 *\brief			convert a string to capital
 *\param[in]
 *\return			
 */
void 
str_capital(char *str) {
	while (*str != '\0') {
        if (*str >= 'A' && *str <= 'Z') {
        	*str += 32;
		} 

        if (str[i - 1] == ' ' || i == 0) {
            if (*str >= 'a' && *str <= 'z')
                *str = *str - 32;
        }
        
        str++;
    }
}
