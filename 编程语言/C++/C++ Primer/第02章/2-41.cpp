#include <iostream>
struct Sales_data{
    std::string ISBN;
    unsigned Book_num;
    double All_money;
};
void exercise1(void);
void exercise2(void);
void exercise3(void);
void exercise4(void);
void exercise5(void);
int main(void)
{
    int ch;
    std::cout << "请输入题目选择(0表示1.20, 1表示1.21, 以此类推)" << std::endl;
    while(std::cin >> ch){
        while(getchar()!='\n'){
            continue;
        }
        switch (ch){
            case 0:
                std::cout << "练习 1.20" << std::endl;
                exercise1();
                break;
            case 1:
                std::cout << "练习 1.21" << std::endl;
                exercise2();
                break;
            case 2:
                std::cout << "练习 1.22" << std::endl;
                exercise3();
                break;
            case 3:
                std::cout << "练习 1.23" << std::endl;
                exercise4();
                break;
            case 4:
                std::cout << "练习 1.25" << std::endl;
                exercise5();
                break;
            default:
                std::cout << "请输入正确的选项" << std::endl;
                break;
        }
        while(getchar()!='\n'){
            continue;
        }
        std::cout << "请输入题目选择(0表示1.20, 1表示1.21, 以此类推)" << std::endl;
    }

    return 0;
}
void exercise1(void)
{
    Sales_data book;
    while(std::cin >> book.ISBN){
        std::cin >> book.Book_num >> book.All_money;
        std::cout << book.ISBN << " " << book.Book_num << " " << book.All_money << std::endl;
    }
}
void exercise2(void)
{
    Sales_data book1,book2;
    std::cin >> book1.ISBN >> book1.Book_num >> book1.All_money;
    std::cin >> book2.ISBN >> book2.Book_num >> book2.All_money;
    if(book1.ISBN==book2.ISBN){
        unsigned Book_Num;
        double All_Money;
        Book_Num=book1.Book_num+book2.Book_num;
        All_Money=book1.All_money+book2.All_money;
        std::cout << book1.ISBN << " " << Book_Num << " " << All_Money << std::endl;
    }else{
        std::cout << "您所输入的不是同一本书" <<std::endl;
        return;
    }
}
void exercise3(void)
{
    Sales_data book1,book2;
    if(std::cin >> book1.ISBN){
        std::cin >> book1.Book_num >> book1.All_money;
        while(std::cin >> book2.ISBN >> book2.Book_num >> book2.All_money){
            if(book1.ISBN==book2.ISBN){
                book1.Book_num+=book2.Book_num;
                book1.All_money+=book2.All_money;
            }else{
                std::cout << "您的输入不是一本书" << std::endl;
                return;
            }
        }
        std::cout << book1.ISBN << " " << book1.Book_num << " " << book1.All_money << std::endl;
    }
}
void exercise4(void)
{
    Sales_data book1,book2;
    if(std::cin >> book1.ISBN){
        std::cin >> book1.Book_num >> book1.All_money;
        while(std::cin >> book2.ISBN >> book2.Book_num >> book2.All_money){
            if(book1.ISBN==book2.ISBN){
                book1.Book_num+=book2.Book_num;
                book1.All_money+=book2.All_money;
            }else{
                std::cout << book1.ISBN << " " << book1.Book_num << " " << book1.All_money << std::endl;
                book1.ISBN=book2.ISBN;
                book1.Book_num=book2.Book_num;
                book1.All_money=book2.All_money;
            }
        }
        std::cout << book1.ISBN << " " << book1.Book_num << " " << book1.All_money << std::endl;
    }
}
void exercise5(void)
{
    Sales_data total;
    if(std::cin >> total.ISBN >> total.Book_num >> total.All_money){
        Sales_data trans;
        while(std::cin >> total.ISBN >> total.Book_num >> total.All_money){
            if(total.ISBN==trans.ISBN){
                total.Book_num+=trans.Book_num;
                total.All_money+=trans.All_money;
            }else{
                std::cout << total.ISBN << " " << total.Book_num << " " << total.All_money << std::endl;
                total.ISBN=trans.ISBN;
                total.Book_num=trans.Book_num;
                total.All_money=trans.All_money;
            }
        }
        std::cout << total.ISBN << " " << total.Book_num << " " << total.All_money << std::endl;
    }else{
        std::cerr << "No data?!" << std::endl;
        return;
    }
}