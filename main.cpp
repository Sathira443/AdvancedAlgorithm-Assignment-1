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

void insert(string combined_string)
{
}

int main()
{
    std::vector<std::string> sets = {"set1", "set2"};
    std::vector<std::string> txt_files = {"data_1.txt", "data_2.txt", "data_3.txt"};

    for (const std::string &set : sets)
    {
        for (const std::string &txt_file : txt_files)
        {
            std::string combined_string = "data/data/insert/" + set + "/" + txt_file;
            std::cout << combined_string << std::endl;

            BST bst;
            RBTree rbtree;
            SplayTree splaytree;

            ifstream data_file(combined_string);

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

            data_file.open(combined_string);
            if (!data_file.is_open())
            {
                cerr << "Error: Could not open data file." << endl;
                return 1;
            }

            auto start_rbtree = high_resolution_clock::now();
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
                        rbtree.put(number, number);
                    }
                }
            }
            auto stop_rbtree = high_resolution_clock::now();
            auto duration_rbtree = duration_cast<microseconds>(stop_rbtree - start_rbtree);

            data_file.close();

            data_file.open(combined_string);
            if (!data_file.is_open())
            {
                cerr << "Error: Could not open data file." << endl;
                return 1;
            }

            auto start_splaytree = high_resolution_clock::now();
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
                        splaytree.put(number, number);
                    }
                }
            }
            auto stop_splaytree = high_resolution_clock::now();
            auto duration_splaytree = duration_cast<microseconds>(stop_splaytree - start_splaytree);

            data_file.close();

            cout << "Total BST insertion time: " << duration_bst.count() << " microseconds" << endl;
            cout << "Total RBTree insertion time: " << duration_rbtree.count() << " microseconds" << endl;
            cout << "Total SplayTree insertion time: " << duration_splaytree.count() << " microseconds" << endl;
        }
    }

    return 0;
}
