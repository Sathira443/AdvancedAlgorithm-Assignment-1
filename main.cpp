#include "BST.h"
#include "RBTree.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int main()
{
    BST bst;
    RBTree rbtree;

    std::ifstream data_file("data/data/insert/set1/data_1.txt");

    if (!data_file.is_open())
    {
        std::cerr << "Error: Could not open data file." << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(data_file, line))
    {
        std::stringstream ss(line);

        int number;
        while (ss >> number)
        {
            bst.put(number, number);
        }
    }

    data_file.close();

    bst.print_in_order();

    return 0;
}