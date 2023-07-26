#include <iostream>
#include <string>
#include <cctype>

int main()
{
    std::string s;
    while (std::getline(std::cin, s)) {
        std::string::iterator beg = s.begin();
        std::string::iterator end = s.end();
        while (beg != end) {
            if (!isblank(*beg)) {
                *beg = 'X';
            }
            ++beg;
        }
        std::cout << s << std::endl;
    }

    return 0;
}