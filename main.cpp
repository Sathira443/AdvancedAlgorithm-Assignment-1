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

    for (const std::string &set : sets)
    {
        for (const std::string &txt_file : txt_files)
        {
            std::string combined_string = "data/data/insert/" + set + "/" + txt_file;
            std::cout << "FILE LOCATION : "<< combined_string << std::endl;

            BST bst;
            RBTree rbtree;
            SplayTree splaytree;

            ifstream data_file(combined_string);

            if (!data_file.is_open())
            {
                cerr << "Error: Could not open data file." << endl;
                return 1;
            }

            /*
                =============BST Insert===============
            */
            string line;
            auto start_bst_insert = high_resolution_clock::now();
            while (getline(data_file, line))
            {
                stringstream next_line(line);
                string number_str;

                while (getline(next_line, number_str, ','))
                {
                    if (!next_line.eof())
                    {
                        long long int number = stoll(number_str);
                        bst.put(number, number);
                    }
                }
            }
            auto stop_bst_insert = high_resolution_clock::now();
            auto duration_bst_insert = duration_cast<microseconds>(stop_bst_insert - start_bst_insert);
            data_file.close();

            /*
            =============BST Search===============
            */
            data_file.open(combined_string);
            auto start_bst_search = high_resolution_clock::now();
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
                        bst.contains(number);
                    }
                }
            }
            auto stop_bst_search = high_resolution_clock::now();
            auto duration_bst_search = duration_cast<microseconds>(stop_bst_search - start_bst_search);
            data_file.close();

            /*
            =============BST Delete===============
            */
            data_file.open(combined_string);
            auto start_bst_delete = high_resolution_clock::now();
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
                        bst.del(number);
                    }
                }
            }
            auto stop_bst_delete = high_resolution_clock::now();
            auto duration_delete_rbtree = duration_cast<microseconds>(stop_bst_delete - start_bst_delete);
            data_file.close();

            /*
            =============Red-Black Tree Insert===============
            */
            data_file.open(combined_string);
            auto start_rbtree_insert = high_resolution_clock::now();
            while (getline(data_file, line))
            {
                stringstream next_line(line);
                string number_str;

                while (getline(next_line, number_str, ','))
                {
                    if (!next_line.eof())
                    {
                        long long int number = stoll(number_str);
                        rbtree.put(number, number);
                    }
                }
            }
            auto stop_rbtree_insert = high_resolution_clock::now();
            auto duration_rbtree_insert = duration_cast<microseconds>(stop_rbtree_insert - start_rbtree_insert);
            data_file.close();

            /*
            =============Red-Black Tree Search===============
            */
            data_file.open(combined_string);
            auto start_rbtree_search = high_resolution_clock::now();
            while (getline(data_file, line))
            {
                stringstream next_line(line);
                string number_str;

                while (getline(next_line, number_str, ','))
                {
                    if (!next_line.eof())
                    {
                        long long int number = stoll(number_str);
                        rbtree.contains(number);
                    }
                }
            }
            auto stop_rbtree_search = high_resolution_clock::now();
            auto duration_rbtree_search = duration_cast<microseconds>(stop_rbtree_search - start_rbtree_search);
            data_file.close();

            /*
            =============Red-Black Tree Deletion===============
            */
            data_file.open(combined_string);
            auto start_rbtree_delete = high_resolution_clock::now();
            while (getline(data_file, line))
            {
                stringstream next_line(line);
                string number_str;

                while (getline(next_line, number_str, ','))
                {
                    if (!next_line.eof())
                    {
                        long long int number = stoll(number_str);
                        rbtree.del(number);
                    }
                }
            }
            auto stop_rbtree_delete = high_resolution_clock::now();
            auto duration_rbtree_delete = duration_cast<microseconds>(stop_rbtree_delete - start_rbtree_delete);
            data_file.close();

            /*
            =============Splay Tree Insertion===============
            */
            data_file.open(combined_string);
            auto start_splaytree_insert = high_resolution_clock::now();
            while (getline(data_file, line))
            {
                stringstream next_line(line);
                string number_str;

                while (getline(next_line, number_str, ','))
                {
                    if (!next_line.eof())
                    {
                        long long int number = stoll(number_str);
                        splaytree.put(number, number);
                    }
                }
            }
            auto stop_splaytree_insert = high_resolution_clock::now();
            auto duration_splaytree_insert = duration_cast<microseconds>(stop_splaytree_insert - start_splaytree_insert);
            data_file.close();

            /*
            =============Splay Tree Search===============
            */
            data_file.open(combined_string);
            auto start_splaytree_search = high_resolution_clock::now();
            while (getline(data_file, line))
            {
                stringstream next_line(line);
                string number_str;

                while (getline(next_line, number_str, ','))
                {
                    if (!next_line.eof())
                    {
                        long long int number = stoll(number_str);
                        splaytree.contains(number);
                    }
                }
            }
            auto stop_splaytree_search = high_resolution_clock::now();
            auto duration_splaytree_search = duration_cast<microseconds>(stop_splaytree_search - start_splaytree_search);
            data_file.close();

            /*
            =============Splay Tree Deletion===============
            */
            data_file.open(combined_string);
            auto start_splaytree_delete = high_resolution_clock::now();
            while (getline(data_file, line))
            {
                stringstream next_line(line);
                string number_str;

                while (getline(next_line, number_str, ','))
                {
                    if (!next_line.eof())
                    {
                        long long int number = stoll(number_str);
                        splaytree.del(number);
                    }
                }
            }
            auto stop_splaytree_delete = high_resolution_clock::now();
            auto duration_splaytree_delete = duration_cast<microseconds>(stop_splaytree_delete - start_splaytree_delete);
            data_file.close();

            cout << "Set = " << set << ", Txt = "<< txt_file <<" Total BST Insertion time: " << duration_bst_insert.count() << " microseconds" << endl;
            cout << "Set = " << set << ", Txt = "<< txt_file <<" Total BST Search time: " << duration_bst_search.count() << " microseconds" << endl;
            cout << "Set = " << set << ", Txt = "<< txt_file <<" Total BST Deletion time: " << duration_delete_rbtree.count() << " microseconds\n" << endl;

            cout << "Set = " << set << ", Txt = "<< txt_file <<" Total RBTree Insertion time: " << duration_rbtree_insert.count() << " microseconds" << endl;
            cout << "Set = " << set << ", Txt = "<< txt_file <<" Total RBTree Search time: " << duration_rbtree_search.count() << " microseconds" << endl;
            cout << "Set = " << set << ", Txt = "<< txt_file <<" Total RBTree Deletion time: " << duration_rbtree_delete.count() << " microseconds\n" << endl;

            cout << "Set = " << set << ", Txt = "<< txt_file <<" Total SplayTree Insertion time: " << duration_splaytree_insert.count() << " microseconds" << endl;
            cout << "Set = " << set << ", Txt = "<< txt_file <<" Total SplayTree Search time: " << duration_splaytree_search.count() << " microseconds" << endl;
            cout << "Set = " << set << ", Txt = "<< txt_file <<" Total SplayTree Deletion time: " << duration_splaytree_delete.count() << " microseconds\n" << endl;
        }
    }

    return 0;
}
