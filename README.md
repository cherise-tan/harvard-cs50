# Harvard CS50: Introduction to Computer Science
Collection of notes, problem sets and projects for Harvard CS50: Introduction to Computer Science

### Sections
* [Week 0](#Week-0)
* [Week 1](#Week-1)

## Week 0
* A BYTE is 8 BITS
* ASCII is a standard mapping system, which dictates how numbers match to letters -> uses ONE BYTE
* UNICODE is a standard that allows characters/emojis etc to be represented as characters with MULTIPLE BYTES

### Abstraction
* ABSTRACTION is a concept in computer science where some low-level implementation (e.g. how data is ultimately stored in binary) is simplified or taken for granted
    * This allows us to use that implementation at a higher level (e.g. representing letters, that we can then use in our programs)
    * When we receive an emoji, computer is actually just receiving a decimel number - which maps to the image of the emoji
* Computers also use binary to represent images -> RGB
    * Within 3 bytes, each representing some amount of red, green and blue, we can represent millions of colours

### Algorithms
* ALGORITHMS are step-by-step instrutions for solving a problem

## Week 1
### C
```
#include  <stdio.h>
int main(void)
{
    printf("hello, world\n");
}
```
* ```printf``` prints something to the screen
    * ```f``` stands for "format" - meaning the string can be formatted in different ways
    * ```\n``` indicates a new line on the screen

#### Loops
* ```while(true)``` will cause our loop to run forever (as 'true' always evaluates to 'true')
* For Loop:
    * ```for (int i = 0; i < 50; i++) {...};```

#### Getting User Input
```
string answer = get_string("What's your name?\n");
printf("hello, %s\n", answer);
```
* ```get_string``` returns a variable of type "string"
    * This stores the users' response
* ```%s``` is a PLACEHOLDER for the string we want to pass in
* ```answer``` is the VALUE of the string we want to pass in -> this replaces ```%s```

#### Maths with printf
```
int x = get_int("x: ");
int y = get_int("y: ");
printf("x + y = %i\n", x + y);
```

#### Floats and Decimel Places
```printf("x / y = %.7f\n", x / y);```
* ```%.7f``` specifies the number of decimel places required

#### Creating Functions
```
void cough(void);
int main(void){
    for (nt i = 0; i < 3; i++){
        cough();
    }
}
void cough(void){
    printf("cough\n```);
}
```
* Need to declare the function before it is referenced ->  ```void cough(void)``` at the top of the page
* ```void cough``` indicates the function doesn't return anything
* ```cough(void)``` indicates the function doesn't take any inputs

This can be further abstracted
```
void cough(int n);
int main(void){
    cough(3);
}
void cough(int n){
    for (int i = 0; i < n; i++){
        printf("cough\n");
    }
}
```
* ```void cough(int n)``` indicates that the "cough" function takes an INPUT "n" -> aka an ARGUMENT

### Using the CS50 Sandbox
* First need to save the file -> e.g. "hello.c" (indicates it is written in C)
* Then need to convert the SOURCE CODE to MACHINE CODE (binary instructions)
    * Use a COMPILER: a program which compiles our source code to machine code
    * ```clang hello.c```
        * ```clang``` stands for "C languages"
    * This will create a new file called "a.out"
    * ```./a.out``` will then run the program
        * ```./``` just means the current folder
* Can change the name of our program from "a.out" to something else
    * ```clang -o hello hello.c```
        * ```-o hello``` tells the program ```clang``` to save the compiled output as just ```hello```
    * Can then just run ```./hello```
* Can further abstract away and just type ```make hello```
    * ```make``` uses ```clang``` to compile our code from ```hello.c``` into ```hello```

#### Using Libraries
* Need to use libraries (sets of code) to tell our program what certain things are
* ```#include <stdio.h>``` is a library that comes with C, that stands for "standard input/output" 
    * Includes the ```printf``` function
* ```#include <cs50.h>``` 
    * Includes the ```string``` variable type, ```get_string``` function
    * Other functions include: ```get_char```, ```get_double```, ```get_float```, ```get_int```, ```get_long```
* To compile with the library: ```clang hello.c -lcs50```
    * ```-l``` stands for "link"

##### Data Types
* ```int```, ```%i```
    * Uses 4 bytes (32 bits) of memory. Range is ~-2 billion -> +2 billion
    * ```unsigned int``` will double the positive range, at the cost of disallowing negative values
* ```char```, ```%c``` 
    * Uses 1 byte (8 bits) to store a single character. Range is -128 -> +127
* ```double```
    * A double uses 8 bytes (64 bits) to store FLOATING POINT VALUES -> has a higher level of precision
* ```float```, ```%f```
    * A float uses 4 bytes (32 bits) to store FLOATING POINT VALUES
* ```long```, ```%l```
* CS50 data types
    * ```bool```
    * ```string```

##### Structures and Defined Types
* Later in the course, will also encounter STRUCTURES (structs) and DEFINED TYPES (typedefs) which afford great flexibility in creating data types for your programs

### Command Line
* ```ls```: lists everything in the folder
* ```cd```: change directory to the ROOT directory
* ```cd ..``` : allows you to move up a directory (to the parent directory)
* ```cd **********```: moves you into the matching child direcoty
* ```pwd```: present working directory -> tells us where we are (the path it takes to get there)
* ```mkdir```: make a directory (aka folder)
* ```cp <source> <destination>```: copy a file - takes two inputs: a SOURCE and a DESTINATION
	* E.g. cp hello.txt hi.txt: will create a copy of 'hello.txt' called 'hi.txt'
* ```cp -r <source> <destination>```: will copy an entire folder and all its contents
	* '-r' stands for RECURSIVE: will dive into the folder and copy everything inside it
	* E.g. cp -r pset0 pset1
* ```rm <file>```: will remove a file -> there is NO WAY TO RECOVER THIS FILE 
	* E.g. rm hi.txt -> will ask you to confirm you want to delete this file
* ```rm -f <file>```: will forcibly remove a file, without getting the check prompt
	* 'f' stands for FORCE
* ```rm -r <folder>```: will recursively remove an ENTIRE directory
* ```rm -rf <folder>```: will recursively and forcibly remove an entire directory
* ```mv <source> <destination>```: will MOVE a file
    * E.g. mv greddy.c greedy.c: will move the contents of 'greddy.c' into a new file called 'greedy.c' -> effectively RENAMING it

### Conditional Statements
#### Switch Statements
```
int x = GetInt();
switch (x)
{
  case 1: printf("One!\n");
  break;
  case 2: printf("Two!\n");
  break;
  case 3: printf("Three!\n");
  break;
  default: printf("Sorry!\n");
}
```
* It is important to ```break;``` between each case, or you will 'fall through' each case (unless this is the desired behaviour)

#### Temporary Operators
```
int x;
if (expr)
{  x = 5;  }
else
{ x = 6;  }

// is functionally identical to

int x = (expr) ? 5 : 6;
```
* The TEMPORARY OPERATOR ?: is useful for writing trivially short conditional branches
* Basically, if 'expr' is TRUE -> x wil equal 5
* If 'expr' is FALSE -> x will equal 6

