#include <iostream>
#include <vector>

bool isBadVersion(int version);

/*
bool isBadVersion(int version)
{
    return version >= 4;
}
*/

int firstBadVersion(int n)
{
    unsigned int l{1};
    unsigned int r{static_cast<unsigned int>(n)};
    while (l < r)
    {
        unsigned int m = (static_cast<unsigned  int>(r + l) / 2);
        if (isBadVersion(m))
        {
            if (m == 1) return m;
            r = m;
        }
        else l = m + 1;
    }
    return l;
}

int main()
{
    int ex1{firstBadVersion(5)};
    std::cout << "Should be 4: " << ex1 << std::endl;
}