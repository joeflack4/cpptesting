/* Testing various things
 * */
#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"

#include <iostream>

using std::cout;
using std::endl;

// Tests ----------------------------------------------------------------------
/* Test undefined behavior of uninitialized variable
 * In this example, output is '0', but if I were to do some other things in
 * the function, the output would be a sort of random number. */
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wuninitialized"
void testUndefinedBehavior() {
    float a;
    cout << "Undefined behavior: \n";
    cout << a;
}

/* Test single and double ampersand usage in an expression
 * &: bitwise operator
 * &&: logical and */
void testAmpersandUsage() {
    int a = -1;
    int b = 2;
    bool _1x = (a > -1) & (a <= b);
    bool _2x = (a > -1) && (a <= b);
    cout << "&: " << _1x << endl;
    cout << "&&: " << _2x << endl;
}

// Choose test to run ---------------------------------------------------------
int main() {
    // call one of the above functions here
    return 0;
}
#pragma clang diagnostic pop
