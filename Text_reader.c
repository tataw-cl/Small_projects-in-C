//Here is a simple C code example that reads a text file
#include <stdio.h>

int main() {
    FILE *file;
    char line[100];

    // Open the file in read mode
    file = fopen("example.txt", "r");

    // Check if the file was opened successfully
    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }

    // Read the file line by line
    while (fgets(line, sizeof(line), file)) {
        // Print each line to the console
        printf("%s", line);
    }

    // Close the file
    fclose(file);

    return 0;
}

/*In this code:
- We include the necessary header file `stdio.h`.
- We declare a file pointer `file` and a character array `line` to store each line read from the file.
- We open the file "example.txt" in read mode using `fopen`.
- We check if the file was opened successfully.
- We read the file line by line using `fgets` in a loop.
- We print each line to the console using 'printf'.
- Finally, we close the file using 'fclose'.

You can replace "example.txt" with the path to your desired text file.*/
