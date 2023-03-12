#include <iostream>
#include <vector>
#include <string>
#include <cctype>

int main()
{
    std::vector<std::string> svec;
    std::string str;
    while (std::cin >> str) {
        svec.push_back(str);
    }
    for (std::string &str : svec) {
        for (char &c : str) {
            c = toupper(c);
        }
        std::cout << str << std::endl;
    }
    return 0;
}