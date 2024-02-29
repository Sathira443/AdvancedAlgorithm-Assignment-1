#include <vector>
#include "BST.h"
#include "RBTree.h"
#include "SplayTree.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <chrono>

using namespace std;
using namespace chrono;

int main()
{
    std::vector<std::string> sets = {"set1", "set2"};
    std::vector<std::string> txt_files = {"data_1.txt", "data_2.txt", "data_3.txt"};

    BST bst;

    ifstream data_file("data/data/insert/set1/data_1.txt");

    if (!data_file.is_open())
    {
        cerr << "Error: Could not open data file." << endl;
        return 1;
    }

    string line;

    auto start_bst = high_resolution_clock::now();
    while (getline(data_file, line))
    {
        stringstream next_line(line);
        string number_str;

        while (getline(next_line, number_str, ','))
        {
            if (!next_line.eof())
            {
                long long int number = stoll(number_str);
                // cout << "Number is: " << number << " number" << endl;
                bst.put(number, number);
            }

            
        }
    }
    auto stop_bst = high_resolution_clock::now();
    auto duration_bst = duration_cast<microseconds>(stop_bst - start_bst);

    data_file.close();

    bst.print_in_order();

    cout << "Total BST insertion time: " << duration_bst.count() << " microseconds" << endl;

    return 0;
}
