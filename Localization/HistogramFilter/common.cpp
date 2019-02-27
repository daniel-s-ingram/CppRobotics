#include "common.h"

int mod(int x, int y)
{
    return (x % y + y) % y;
}