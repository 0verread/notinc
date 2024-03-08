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

   // Approach 3: get the highest number from list {} of msg string. say hn = 5
   // look for elements until 5
   va_list args;
   va_start(args, msg);
   int highestNumber = -1;
   int currentNumber = 0;
   int isBraces = 0;
   int i=0;
   while(msgcpy[i] != '\0'){
       if(msgcpy[i] == '{'){
          isBraces = 1;
          currentNumber = 0;
       }else if(msgcpy[i] == '}'){
          isBraces = 0;
          if(currentNumber > highestNumber){
               highestNumber = currentNumber;
          }
       }else if(isBraces==1 && msgcpy[i] >= '0' && msgcpy[i] <='9'){
          currentNumber = currentNumber * 10 + (msgcpy[i] - '0');
       }
       i++;
   }

   printf("count: %d\n", highestNumber);
   va_end(args);

   va_start(args, msg);
   int done = vfprintf(stdout, msg, args);
   va_end(args);
}

// example/testing part
int main(){
    char *testmsg = "they are stuff age {0} {1} {10} {9} something {3}\n";
    printf("testmsg:%s\n", testmsg);
    bprint(testmsg, 10, 20);// they are studd age 10
    return 1;
}


