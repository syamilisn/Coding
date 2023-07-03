    #include <stdio.h>
    #include <string.h>
    /*
        input version
    */
    void get_pair(int *a, int *b, int len){
        *a = *a % len;
        *b = *b % len;
        if (*a < 0){     // if 'a' is negative value
            *a = len + *a;
        }

        if (*b < 0){     // if 'b' is negative value
            *b = len + *b;
        }
    }

    void string_reversal(char *str, int a, int b){
        //a and b are intervals 
        b = b-1;
    
        for(; a<b; a++, b--){
            char temp = str[a];
            str[a] = str[b];
            str[b] = temp;
        }
    }
    void main(){
        char string[1000];
        scanf("%[^\n]s", string);
        printf(" \n");
        // char string[50] = "Little Lamb, I'll tell thee;";
        int n;
        scanf("%d", &n);
        int len = strlen(string);
        int a, b;
        for (int i = 0; i < n; i++)
        {
            scanf("%d %d", &a, &b);
            get_pair(&a, &b, len);
            // a = len + (a%len);
            printf("a = %d \n", a);
            // b = b % len;
            printf("b = %d \n", b);
            if (a > b){
                int temp;
                temp = a, a = b, b = temp;
            }
            string_reversal(string, a, b); 
            // printf("\nAfter reversing it becomes :%s\n",string);
        }
        
        // printf("The original String is: %s\n",string);
        // string_reversal(string, 2, 11);
        // printf("\nAfter reversing it becomes :%s\n",string);
        // string_reversal(string, 21, 26);
        printf("\n%s\n",string);
    }