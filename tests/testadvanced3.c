#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "ijvm.h"
#include "testutil.h"

void test_wide1()
{
    int res = init_ijvm("files/advanced/test-wide1.ijvm");
    assert(res != -1);

    steps(6);
    assert(get_local_variable(1) == 0x1);
    steps(2);
    assert(get_local_variable(257) == 0x2);
    step();
    assert(tos() == 0x1);
    step();
    assert(tos() == 0x2);

    destroy_ijvm();
}

void test_wide2()
{
    int res = init_ijvm("files/advanced/test-wide2.ijvm");
    assert(res != -1);

    steps(6);
    assert(get_local_variable(1) == 0x1);
    steps(2);
    assert(get_local_variable(32768) == 0x2);
    step();
    assert(tos() == 0x1);
    step();
    assert(tos() == 0x2);

    destroy_ijvm();
}

int main()
{
    test_wide1();
    test_wide2();
    printf("## PASSED ALL TESTS FOR ADVANCED 3 ##\n");
    return 0;
}
