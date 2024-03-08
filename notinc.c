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

void bprint(const char*, ...);
// Variadic Function in C
void bprint(const char *msg, ...) {
   char *msgcpy = msg;
   va_list args;
   va_start(args);
   int count = 0;
   printf("count : %d\n", count);
   va_end(args);

   va_start(args, msg);
   int done = vfprintf(stdout, msg, args);
   va_end(args);
}

// example/testing part
int main(){
    char *testmsg = "they are stuff age {0}\n";
    printf("testmsg:%s", testmsg);
    bprint(testmsg, 10, 20);// they are studd age 10
    return 1;
}


