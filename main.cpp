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

int main() {
    BST bst;
    RBTree rbtree;
    SplayTree splaytree;

    ifstream data_file("data/data/insert/set1/data_1.txt");

    if (!data_file.is_open()) {
        cerr << "Error: Could not open data file." << endl;
        return 1;
    }

    string line;

    // Measure BST insertion time
    auto start_bst = high_resolution_clock::now();
    while (getline(data_file, line)) {
        stringstream ss(line);

        int number;
        while (ss >> number) {
            bst.put(number, number);
        }
    }
    auto stop_bst = high_resolution_clock::now();
    auto duration_bst = duration_cast<microseconds>(stop_bst - start_bst);

    data_file.close(); // Close file after BST insertion

    // Open the file again for RBTree and SplayTree insertions
    data_file.open("data/data/insert/set1/data_1.txt");
    if (!data_file.is_open()) {
        cerr << "Error: Could not open data file." << endl;
        return 1;
    }

    // Measure RBTree insertion time
    auto start_rbtree = high_resolution_clock::now();
    while (getline(data_file, line)) {
        stringstream ss(line);

        int number;
        while (ss >> number) {
            rbtree.put(number, number);
        }
    }
    auto stop_rbtree = high_resolution_clock::now();
    auto duration_rbtree = duration_cast<microseconds>(stop_rbtree - start_rbtree);

    data_file.close(); // Close file after RBTree insertion

    // Open the file again for SplayTree insertions
    data_file.open("data/data/insert/set1/data_1.txt");
    if (!data_file.is_open()) {
        cerr << "Error: Could not open data file." << endl;
        return 1;
    }

    // Measure SplayTree insertion time
    auto start_splaytree = high_resolution_clock::now();
    while (getline(data_file, line)) {
        stringstream ss(line);

        int number;
        while (ss >> number) {
            splaytree.put(number, number);
        }
    }
    auto stop_splaytree = high_resolution_clock::now();
    auto duration_splaytree = duration_cast<microseconds>(stop_splaytree - start_splaytree);

    data_file.close();

    // Print the total insertion times for each tree
    cout << "Total BST insertion time: " << duration_bst.count() << " microseconds" << endl;
    cout << "Total RBTree insertion time: " << duration_rbtree.count() << " microseconds" << endl;
    cout << "Total SplayTree insertion time: " << duration_splaytree.count() << " microseconds" << endl;

    return 0;
}
