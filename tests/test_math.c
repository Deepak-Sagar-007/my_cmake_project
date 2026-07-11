#include <assert.h>
#include "math_utils.h"

int add(int a, int b) {
    return a + b;
}

int main() {
    assert(add(2, 3) == 5);
    assert(add(10, 5) == 15);

    return 0;
}