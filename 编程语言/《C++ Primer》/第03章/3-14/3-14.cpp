#include <iostream>
#include <vector>

int main()
{
    std::vector<int> ivec;
    int now;
    while (std::cin >> now) {
        ivec.push_back(now);
    }
    for (int i : ivec) {
        std::cout << i << std::endl;
    }

    return 0;
}