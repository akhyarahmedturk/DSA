#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

// Function to compile and run the submitted code
int compileAndRunCode() {
    // Compile the code
    int compileResult = system("g++ submitted_code.cpp -o submitted_code 2> compile_errors.txt");

    if (compileResult != 0) {
        // Compilation error occurred
        return 1;
    }

    // Run the compiled code
    int runResult = system("./submitted_code > program_output.txt 2> runtime_errors.txt");

    if (runResult != 0) {
        // Runtime error occurred
        return 2;
    }

    // Code ran successfully
    return 0;
}

int main() {
    // Output the result of compile and run process
    return compileAndRunCode();
}
