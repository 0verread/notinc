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

#define typename(X) _Generic((X),   \
                            int:    'd',  \
                            char:   'c',   \
                            char*:  's',   \
                            float:  'f'    \
                            );



void bprint(char *msg, ...) {
   char msgcpy[strlen(msg)];

   va_list args;

   va_start(args, msg);
   int highestNumber = -1;
   int currentNumber = 0;
   int isBraces = 0;
   int i=0;
   while(msg[i] != '\0'){
       char currentChar = msg[i];
       if(msg[i] == '{'){
          isBraces = 1;
          currentChar = '%';
       }else if(msg[i] == '}'){
          isBraces = 0;
          currentChar = ' ';
       }else if(isBraces==1 && msg[i] >= '0' && msg[i] <='9'){
          currentNumber = currentNumber * 10 + (msg[i] - '0');
          for(int i=0; i<=currentNumber; i++){
            char atype = typename(va_arg(args, int));
            currentChar = atype;
          }
       }
       msgcpy[i] = currentChar;
       i++;
   }

   va_end(args);

   char *logmsg = msgcpy;

   va_start(args, logmsg);
   int done = vfprintf(stdout, logmsg, args);
   va_end(args);
}



