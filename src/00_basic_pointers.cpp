#define Y_STAR 12
#define Z_VAL "abc"
#define CHAR_STAR_Y "abc"
#define X_VAL 0

// Rules of the game:
// 1. Do not modify anything below this line
// 2. Read and understand the code below.
// 3. Try to get all of the points by modifying the lines above.

// Run `make 00_basic_pointers` to compile and run this file

int points = 0;

#include <string.h>
#include <iostream>

int main(int argc, char* argv[])
{
    int x;
    int *y;
    x = 10;
    y = &x;

    // Y_STAR: What is the value of *y?
    // Put the response in line 1 of this file
    if (Y_STAR == Y_STAR_ANS) { 
        std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
        std::cout << "Y_STAR is correct!" << std::endl;
        std::cout << "Y value: " << *y << std::endl;
        std::cout << "Address location: " << y << std::endl;
        points++;
    }
    
    char* z;
    z = (char*) y;
    *z = 94;
    z++;
    *z = 117;
    z++;
    *z = 45;
    z++;
    *z = 0;

    // Z_VAL: What is the value of z?
    // Put the response in line 2 of the file
    if (strcmp(Z_VAL, Z_VAL_ANS) == 0) {
        std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
        std::cout << "Z_VAL is correct!" << std::endl;
        std::cout << z << std::endl;
        points++;
    }

    // CHAR_STAR_Y_VAL: What is the value of y?
    // Put the response in line 3 of the file
    if (strcmp(CHAR_STAR_Y, CHAR_STAR_Y_ANS) == 0) {
        std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
        std::cout << "CHAR_STAR_Y is correct!" << std::endl;
        std::cout << (char*) y << std::endl;
        points++;
    }

    // X_VAL: What is the value of x?
    // Put the response in line 4 of the file
    if (X_VAL == X_VAL_ANS) {
        std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
        std::cout << "X_VAL is correct!" << std::endl;
        std::cout << x << std::endl;
        points++;
    }

    std::cout << "You got " << points << " points out of " << 4 << std::endl;
    return 0;
}
