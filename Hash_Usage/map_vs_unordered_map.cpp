#include <iostream>
#include <map>
#include<unordered_map>

using namespace std;

int main() {

    // Ordered Map orders key in ascending order
    map<int, string> orderedMap;
    orderedMap[3] = "Three";
    orderedMap[1] = "One";
    orderedMap[2] = "Two";

    cout << "Ordered Map:" << endl;
    for (const auto& pair : orderedMap) {
        cout << pair.first << ": " << pair.second << endl;
    }
    
    // Unordered map orders keys based on stack(LIFO)
    unordered_map<int, string> unorderedMap; 
    unorderedMap[3] = "Three"; 
    unorderedMap[1] = "One"; 
    unorderedMap[2] = "Two"; 
    cout << "Unordered Map:" << endl; 
    for (const auto& pair : unorderedMap) { 
    	cout << pair.first << ": " << pair.second << endl; 
    }

    return 0;
}

