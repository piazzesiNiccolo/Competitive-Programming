#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct frog
{
    int position, i;
    int tongue_length;
    frog(int position, int tongue_length) : position(position), tongue_length(tongue_length) {}
};

