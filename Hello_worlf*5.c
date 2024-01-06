//5 different ways to orint hello world in C
//Method 1: Using printf()

#include <stdio.h>

int main() {
    // Using the printf() function to print "Hello, World!"
    printf("Hello, World!\n");
    return 0;
}


//Method 2: Using puts()


#include <stdio.h>

int main() {
    // Using the puts() function to print "Hello, World!"
    puts("Hello, World!");
    return 0;
}


Method 3: Using putchar() in a loop

//
#include <stdio.h>

int main() {
    const char helloWorld[] = "Hello, World!";
    int i = 0;

    // Using putchar() in a loop to print each character of "Hello, World!"
    while (helloWorld[i] != '\0') {
        putchar(helloWorld[i]);
        i++;
    }

    putchar('\n');
    return 0;
}


//Method 4: Using fprintf()


#include <stdio.h>

int main() {
    // Using the fprintf() function to print "Hello, World!" to stdout
    fprintf(stdout, "Hello, World!\n");
    return 0;
}

//Method 5: Using fwrite()


#include <stdio.h>

int main() {
    const char helloWorld[] = "Hello, World!\n";

    // Using fwrite() to write the string "Hello, World!" to stdout
    fwrite(helloWorld, sizeof(char), sizeof(helloWorld)-1, stdout);
    return 0;
}
