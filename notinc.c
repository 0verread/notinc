#include<stdio.h>
#include<stdarg.h>
#include<string.h>

// A better printf
// problem1: I have to mention the datatype in printf msg. I'm lazy to do that
// problem2: I can't write printf like in python3 e.g. f"this is add {addr}"
// Requirements: 1. it should take strig that includes message with dynamic var value
// 2. it should handle the var type and print the log message
// e.g. brpint("make something {0} to people who {1}", a,b);
// 0 represtes a; 1 represts b index of arr [a, b]
//

#define get_arg_type(x) _Generic((x),\
    int: "%d",\
    char*: "%c",\
    default: "",\
    )


void get_type(va_list args, int n){
  //  va_start(args, n);
    //for(int i=0; i<n; i++){
     //   var_arg(args, int);
    //}
    //char *type = get_arg_type(var_arg(args, int));
   // va_end(args)
}

// Variadic Function in C
void bprint(const char *msg, ...) {
   char *msgcpy = msg;

   va_list args;

   while(*msgcpy != '\0'){
       if(*msgcpy == '{'){
            msgcpy++;
            int ind = *msgcpy - '0';
            va_start(args, ind);
            for(int i=0; i<ind; i++){
                va_arg(args, int);
            }
            char *dtype = va_arg(args, int);
            printf("%s\n", *dtype);

       }
   }

    printf("%s\n", msgcpy);



    va_start(args, 0);
    for(int i=0; i<0; i++){
        va_arg(args, int);
    }

    printf("%d\n", va_arg(args, int));
    va_end(args);
    va_start(args, msg);
    int done = vfprintf(stdout, msg, args);
    va_end(args);
}



int main(){
    char testmsg[] = "they are stuff age %d\n";
    bprint(testmsg, 10, 20);
    return 0;
}


