#include <stdio.h>
 
int  length_string (char[]);
char is_symmetry(char[]);
void str_copy(char[], char[]);
char find_char(char[], char);
void find_substr(char[], char[]);
void to_lower(char[]);
void to_upper(char[]);
void to_title(char[]);
 
int main(){
    char str[100], key;
    printf("\nNhap chuoi: ");
    gets(str);
 
    printf("Length = %d", length_string(str));
    
	if (!is_symmetry(s1))
    {
        printf("chuoi vua nhap khong phai chuoi doi xung\n");
    }
    if (is_symmetry(s1))
    {
        printf("chuoi vua nhap la chuoi doi xung\n");
    }
    
    printf("\nxin moi ban nhap vao ki tu can dem\n");
    scanf("%c", &key);
    if (kiemtra(chuoi, key) == 1)
    {
        printf("\nki tu %c khong co trong chuoi\n", key);
    }
}

int 
length_string (char str[]){
    int i = 0;
    for(; str[i]; i++); // for(int i = 0; str[i] != '\0'; i++){}
    
    return i;
}

char 
is_symmetry(char s1[100]) {
    int i;
    for (i = 0; i < strlen(s1) / 2; i++) {
        if (s1[i] != s1[strlen(s1) - 1 - i]) {
            return 0;
        }
    }
    return 1;
}

char 
find_char(char str[100], char key) {
    int i, dem = 0;
    for (i = 0; i < strlen(chuoi); i++) {
        if (key == chuoi[i]) {
            dem++;
        }
    }
    
    if (dem > 0) {
        printf("\nki tu %c trong chuoi xuat hien %d lan ", key, dem);
    }
    
    if (dem == 0) {
        return 1;
    }
}

void find_substr(char[], char[]) {
	 char s1[] = "VietTuts hoc lap trinh online, hoc c, hoc c++, hoc java, ...";
   char s2[] = "hoc";
  
   int n = 0;
   int m = 0;
   int times = 0;
   // bien luu giu do dai cua chuoi can tim kiem
   int len = strlen(s2);
  
   while(s1[n] != '\0') {
  
      if(s1[n] == s2[m]) {    // neu ky tu dau tien la giong nhau
  
         // tiep tuc tim kiem
         while(s1[n] == s2[m]  && s1[n] !='\0') {
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

void 
to_lower(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32;
        }
    }
}
 
void 
to_upper(char s[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 32;
        }
    }
}
 
void 
to_title(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') str[i] += 32;
        if (str[i - 1] == ' ' || i == 0) {
            if (str[i] >= 'a' && str[i] <= 'z')
                str[i] = str[i] - 32;
        }
    }
}
