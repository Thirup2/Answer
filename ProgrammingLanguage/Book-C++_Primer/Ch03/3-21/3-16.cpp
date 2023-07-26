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

    std::vector<int>::iterator vbeg;
    std::vector<int>::iterator vend;
    std::vector<std::string>::iterator sbeg;
    std::vector<std::string>::iterator send;

    vbeg = v1.begin();
    vend = v1.end();
    std::cout << "Now test the 1 example:" << std::endl;
    std::cout << "size: " << v1.size() << std::endl;
    while (vbeg != vend) {
        std::cout << *vbeg << " ";
        ++vbeg;
    }
    std::cout << std::endl;
    std::cout << std::endl;

    vbeg = v2.begin();
    vend = v2.end();
    std::cout << "Now test the 2 example:" << std::endl;
    std::cout << "size: " << v2.size() << std::endl;
    while (vbeg != vend) {
        std::cout << *vbeg << " ";
        ++vbeg;
    }
    std::cout << std::endl;
    std::cout << std::endl;

    vbeg = v3.begin();
    vend = v3.end();
    std::cout << "Now test the 3 example:" << std::endl;
    std::cout << "size: " << v3.size() << std::endl;
    while (vbeg != vend) {
        std::cout << *vbeg << " ";
        ++vbeg;
    }
    std::cout << std::endl;
    std::cout << std::endl;

    vbeg = v4.begin();
    vend = v4.end();
    std::cout << "Now test the 4 example:" << std::endl;
    std::cout << "size: " << v4.size() << std::endl;
    while (vbeg != vend) {
        std::cout << *vbeg << " ";
        ++vbeg;
    }
    std::cout << std::endl;
    std::cout << std::endl;

    vbeg = v5.begin();
    vend = v5.end();
    std::cout << "Now test the 5 example:" << std::endl;
    std::cout << "size: " << v5.size() << std::endl;
    while (vbeg != vend) {
        std::cout << *vbeg << " ";
        ++vbeg;
    }
    std::cout << std::endl;
    std::cout << std::endl;

    sbeg = v6.begin();
    send = v6.end();
    std::cout << "Now test the 6 example:" << std::endl;
    std::cout << "size: " << v6.size() << std::endl;
    while (sbeg!=send) {
        std::cout << *sbeg << " ";
        ++sbeg;
    }
    std::cout << std::endl;
    std::cout << std::endl;

    sbeg = v7.begin();
    send = v7.end();
    std::cout << "Now test the 7 example:" << std::endl;
    std::cout << "size: " << v7.size() << std::endl;
    while (sbeg != send) {
        std::cout << *sbeg << " ";
        ++sbeg;
    }
    std::cout << std::endl;

    return 0;
}