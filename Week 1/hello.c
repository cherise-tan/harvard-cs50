// Create a program which first prompts the user for their name, and then prints ```hello, <name>```
// Make sure to compile program with ```make hello```

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string name = get_string("What is your name?\n");
    printf("hello, %s\n", name);
}