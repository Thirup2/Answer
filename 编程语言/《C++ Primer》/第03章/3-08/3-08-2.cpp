#include <iostream>
#include <string>
#include <cctype>

int main()
{
    std::string s;
    while (std::getline(std::cin, s)) {
        for (std::string::iterator beg = s.begin(), end = s.end(); beg != end; beg++) {
            if (!isblank(*beg)) {
                *beg = 'X';
            }
        }
        std::cout << s << std::endl;
    }

    return 0;
}