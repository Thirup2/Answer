#include <iostream>
int main()
{
    std::cout << "以下print是一些语法错误:" << std::endl;
    std::cout << "int main({\n" 
              << "    std::cout << \"Read each file.\" << std::endl:\n"
              << "    std::cout << Update master. << std::endl;\n"
              << "    std::cout << \"Write new master.\" std::endl;\n"
              << "    return 0\n"
              << "}" << std::endl;
    std::cout << "以下print是一些类型错误:" << std::endl;
    std::cout << "int n;\n"
              << "n=\"hello\";" << std::endl;
    std::cout << "以下print是一些声明错误:" << std::endl;
    std::cout << "#include <iostream>\n"
              << "int main()\n"
              << "{\n"
              << "    int v1=0,v2=0;\n"
              << "    std::cin >> v >> v2;\n"
              << "    cout << v1 + v2 << std::endl;\n"
              << "    return 0;\n"
              << "}" << std::endl;
    return 0;
}