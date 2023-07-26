#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::vector<int> v1;
    std::vector<int> v2(10);
    std::vector<int> v3(10, 42);
    std::vector<int> v4{10};
    std::vector<int> v5{10, 42};
    std::vector<std::string> v6{10};
    std::vector<std::string> v7{10, "hi"};

    std::cout << "Now test the 1 example:" << std::endl;
    std::cout << "size: " << v1.size() << std::endl;
    for (auto now : v1) {
        std::cout << now << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "Now test the 2 example:" << std::endl;
    std::cout << "size: " << v2.size() << std::endl;
    for (auto now : v2) {
        std::cout << now << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "Now test the 3 example:" << std::endl;
    std::cout << "size: " << v3.size() << std::endl;
    for (auto now : v3) {
        std::cout << now << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "Now test the 4 example:" << std::endl;
    std::cout << "size: " << v4.size() << std::endl;
    for (auto now : v4) {
        std::cout << now << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "Now test the 5 example:" << std::endl;
    std::cout << "size: " << v5.size() << std::endl;
    for (auto now : v5) {
        std::cout << now << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "Now test the 6 example:" << std::endl;
    std::cout << "size: " << v6.size() << std::endl;
    for (auto now : v6) {
        std::cout << now << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "Now test the 7 example:" << std::endl;
    std::cout << "size: " << v7.size() << std::endl;
    for (auto now : v7) {
        std::cout << now << " ";
    }
    std::cout << std::endl;

    return 0;
}