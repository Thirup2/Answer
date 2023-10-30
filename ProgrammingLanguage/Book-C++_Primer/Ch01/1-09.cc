#include <iostream>
#include <string>

int main()
{
    int sum = 0;
    std::string method("while");
    std::cout << "please input the loop way you want: ";
    while (std::cin >> method) {
        if (method == "while") {
            int i = 50;
            while (i <= 100) {
                sum += i++;
            }
            break;
        } else if (method == "for") {
            for (int i = 50; i <= 100; i++) {
                sum += i;
            }
            break;
        } else {
            std::cout << "input error, please input a loop way from while, for: ";
            continue;
        }
    }
    std::cout << "add from 50 to 100 is " << sum << std::endl;

    return 0;
}