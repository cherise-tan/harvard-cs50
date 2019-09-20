# Harvard CS50: Introduction to Computer Science
Collection of notes, problem sets and projects for Harvard CS50: Introduction to Computer Science

### Sections
* [Week 0](#Week-0)
* [Week 1](#Week-1)
* [Week 2](#Week-2)

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

### Using the CS50 Sandbox
* First need to save the file -> e.g. "hello.c" (indicates it is written in C)
* Then need to convert the SOURCE CODE to MACHINE CODE (binary instructions)
    * Use a COMPILER: a program which compiles our source code to machine code
    * ```clang hello.c```
        * ```clang``` stands for "C languages"
    * This will create a new file called "a.out"
    * ```./a.out``` will then run the program
        * ```./``` just means the current folder
* If we want to use a library via ```#include <cs50.h>```, need to add the flag ```clang hello.c -lcs50```
    * The ```-l``` tag links the ```cs50``` file
* Can change the name of our program from "a.out" to something else
    * ```clang -o hello hello.c```
        * ```-o hello``` tells the program ```clang``` to save the compiled output as just ```hello```
    * Can then just run ```./hello```
* Can further abstract away and just type ```make hello```
    * ```make``` uses ```clang``` to compile our code from ```hello.c``` into ```hello```

#### Debugging in the CS50 IDE
* ```debug50```
    * This is a GUI (graphical user interface) wrapper for a program called GDB, which is a debugging program
    * Need to define a BREAK POINT: code will run up til this point and then pause
        * Do this by clicking to the LEFT of the line of code (will create a red dot)
    * Command line: ```debug50 ./<title>```
        * Debugger tab on the right will then pop open
    * Click 'play' button to start running through code
    * Can then take slow steps through the program by clicking 'step over' button
    * If going into a block (e.g. an ```if``` block) -> click 'step into' button
        * Click on 'step out' to exit this block
* ```eprintf("...");```
    * Stands for "error printf" -> basically ```printf``` but for the person testing the program
    * Instead of just printing out to the console, it will also say WHERE in the code it is coming from
* ```help50 make <title>```
    * This is a virtual teaching fellow which will give clues and hints about what might be going on in your program, without immediately telling you the full answer
* ```style50 file.c``` will give suggestions on what to change to improve the style of the code

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

## Week 2
### Compiling
* 'Compiling' source code into machine code is made up of a number of small steps:
* Preprocessing: involves looking at lines that start with ```#```
    * e.g. ```#include <cs50.h>``` will tell ```clang``` to look at that header file first, as it contains content we want to use in our program
    * Then, ```clang``` will essentially replace the contents of those header files into the program
* Compiling: turns source code to assembly code, which can be understood by the CPU more directly 
    * These instructions are lower-level, and generally operate on bytes as opposed to abstractions like variable names
* Assembling: converts assembly code to instructions in binary
* Linking: includes the contents of linked libraries, such as ```cs50.c``` into the program as binary

### Functions
* Function Declarations: ```return-type name(argument-list);```
    * The ```return-type``` is the type of variable the function will output
    * The ```argument-list``` is the comma-separated set of inputs to your function, each of which has a type and a name
    * Examples:
        ```int add_two_ints(int a, int b);```

* Function Definitions: 
    ```
    float add_two_ints(int a, int b){
        return a + b;
    }
    ```
* Function Calls: ```int c = add_two_ints(a, b);```
* Functions with VOID
    ```void cough(void)```
        * ```void cough``` indicates the function doesn't return anything
        * ```cough(void)``` indicates the function doesn't take any inputs

### Arrays
* Arrays are used to hold values of the same data type at continuous memory locations
* Array declarations: ```type name[size];``` -> e.g. ```int grades[8];```
    * Where ```type``` refers to the kind of variable each element of the array will be
    * Remember arrays range from index 0 -> (n-1); the above array indexes will range from 0 - 7
* Array initialisation requires special syntax to fill up the array with starting values
    * Instantiation syntax: ```bool truth[3] = { false, true, true };```
        * If using this syntax, don't need to indicate the size of the array
        * Can just use: ```bool truth[] = { false, true, true };```
    * Individual element syntax: ```bool truth[3];   truth[0] = false;   ...```
    * Can also use a loop to iterate over the array to assign values (recommended for large arrays)
* Arrays can consist of more than a specific dimension. You can have as many size specifiers as you wish
    * ```bool battleship[10][10];```
    * Can think of this as 10 x 10 grid of cells
    * NB in memory it's really just a 100 element one-dimensional array
    * Multidimensional arrays are great ABSTRACTIONS to help visualise game boards or other complex representations
* In C, while we can treat individual elements of arrays as variables, we CANNOT treat entire arrays themselves as variables
    * In C, we cannot assign one array to another array using ```=```
    * Instead must use a loop to copy over the elements one at a time
        ```
        int foo[5] = { 1, 2, 3, 4, 5 };
        int bar[5];
        for (int j = 0; j < 5; j++){
            bar[j] = foo[j];
        }
        ```
* In C, most variables are PASSED BY VALUE in function calls (i.e. it receives a local copy of the value that is passed down; not the original value itself)
    * Arrays are instead PASSED BY REFERENCE -> the callee receives the ACTUAL array, not a copy of it

### Strings
* Strings are arrays of characters: "chars"
* Incorporating ```string.h``` library will give us access to the ```strlen``` function 
    * ```strlen(string)``` will return the number of characters in a string (i.e. string length)
* Can use array syntax to access individual string characters: e.g. ```string[i]```

#### ASCII
* Can look up which ASCII character a certain character in a string corresponds to
```
string s = get_string("String: ");
for (int i = 0; i < strlen(s); i++) {
    int c = (int) s[i];
    printf("%c %i", s[i], c);
}
```
* ```int c = (int) s[i]``` converts one data type to another data type
    * This is known as "Casting"
    * The data type in brackets (i.e. ```(int)```) dictates what data type you want to convert the following value (i.e. ```s[i]```) into
    * This is then stored as the desired data type (i.e. ```int c = ```)

* Technically can also do this more simply: ```int c = s[i]``` will also convert the datatype

* Technically can even write ```printf("%c %i\n", s[i], s[i])``` and this will also convert to the specified datatype

### Sorting & Searching Algorithms
#### Selection Sort
* Find the SMALLEST unsorted element in an array and swap it with the FIRST unsorted element of the array
    * Builds a sorted list one element at a time
* ```Ω(n^2) -> O(n^2)```   
    * Best-case + Worst-case: have to iterate over each of the 'n' elements of the array, which must be repeated 'n' times -> since only one element gets sorted on each pass
* Pseudocode: 
    * Repeat until no unsorted elements remain
        * Search the unsorted part of the data to find the smallest value
        * Swap the smallest found value with the first element of the unsorted part
        * Can consider the new first element of the array to be SORTED

#### Bubble Sort
* Swap ADJACENT PAIRS of elements if they are out of order, effectively "bubbling" larger elements to the right and smaller ones to the left
* ```Ω(n) -> O(n^2)``` (Better than selection sort)
    * Best-case: the array is already perfectly sorted, so no swaps are made on the first pass
    * Worst-case: the array is in reverse order, and we have to 'bubble' each of the 'n' elements all the way across the array
        * Since we can only fully bubble one element into position per pass, we must do this 'n' times
* Pseudocode:
    * Set swap counter to a non-zero value
    * Repeat until the swap counter is '0'
        * Reset swap counter to '0'
        * Look at each adjacet pair
            * If two adjacent elements are not in order, swap them and then add '1' to te swap counter
    * NB: after each iteration, do not need to look at the final value in the next iteration. This is because the highest value will always be bubbled right to the end
        * Can consider the final value to be part of the 'sorted' portion of the array

#### Insertion Sort
* Proceed once through the array from left-to-right, SHIFTING elements as necessary to insert each element into its correct place -> the sorted array is built ONE ELEMENT at a time
* ```Ω(n) -> O(n^2)```
    * Best-case: The array is already perfectly sorted, and we simply keep moving the line between 'sorted' and 'unsorted' as we examine each element
    * Worst-case: The aray is in revers order, and we have to shift each of the 'n' elements 'n' positions each time we make an insertion
* Pseudocode:
    * Call the first element of the array "sorted"
    * Repeat until all elements are sorted:
        * Look at the next unsorted element, insert into the 'sorted' portion by shifting the requisite number of elements

#### Merge Sort
* SPLIT the full array into subarrays, then MERGE those subarrays back together in the correct order
    * Merge sort leverages RECURSION to do this
* ```Ω(n log n) -> O (n log n)``` 
    * Best-case: The array is already perfect sorted, but still need to split and recombine it
    * Worst-case: Have to split 'n' elements up and then recombine them, effectively doubling the srted subarrays as we build them (combining sorted 1-element arrays into 2-element arrays, combining sorted 2-element arrays into 4-element arrays...)
* Pseudocode:
    * Sort the left half of the array (assuming n > 1)
    * Sort the right half of the array (assuming n > 1)
    * Merge the two halves together
    * NB array keeps being split into smaller sub-arrays until each sub-array contains only one element

#### Linear Search
* ITERATE across the array from left-to-right, trying to find the target element
* ```Ω(1) -> O(n)```
    * Best-case: The target element is the first element in the array
    * Worst-case: We have to look through the entire array of 'n' elements
* Pseudocode:
    * Repeat, starting at the first element:
        * If the first element is the target, stop
        * Otherwise, move to the next element

#### Binary Search
* Given a SORTED array, DIVIDE AND CONQUER by systematically eliminating half of the remaining elements in the search for the target element
* ```Ω(1) -> O(log n)``` (More effective IF array is already sorted)
    * Best-case: the target element is the first element found, so can stop searching after that    
    * Worst-case: have to divide a list of 'n' elements in half repeatedly to find the target element, either because the target element will be found at the end of the last division, or it doesn't exist in the array at all
* The algorithm will divide and conquer, reducing the search area by half each time, trying to find a target number -> it MUST be sorted first in order to use this power
* Pseudocode:
    * Repeat until the (sub)array is of size 0
        * Calculate the middle point of the current (sub)array
        * If the target is at the middle, stop
        * Otherwise, if the target < middle, repeat -> changing the end point to be just to the left of the middle
        * Otherwise, if the target > middle, repeat -> changing the start point to be just to the right of the middle

