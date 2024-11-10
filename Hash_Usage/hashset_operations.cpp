#include<iostream>
#include<unordered_set>
using namespace std;

// In C++, an unordered set is used to implement a hash map which is used to store unique elements

class HashSet
{
    private:
            unordered_set<int> set;
    public:
            void add(int val)
            {
                set.insert(val);
            }
            void del(int val)
            {
                set.erase(val);
            }
            bool contains(int val)
            {
                return set.find(val)!=set.end();
            }
            void print()
            {
                cout<<"\nElements of Hash Set:\n";
                for (const int& val : set) 
                { 
                    cout << val << " "; 
                
                }
            }
            
};

int main()
{
    // Create object of hashset 
    HashSet hashset;
    
    // Adding elements to the hashset
    hashset.add(2);
    hashset.add(3);
    hashset.add(5);
    
    // Check if elements are present in the set
    cout<<"\nContains 2?"<<hashset.contains(2)?"Yes":"No";
    cout<<"\nContains 7?"<<hashset.contains(7)?"Yes":"No";
    
    // Print the elements of the hashset
    hashset.print();
    
    // Removing an element 
    hashset.del(3);
    hashset.print();
    
    // Adding duplicate element- will not take place as '2' is present
    hashset.add(2);
    hashset.print();
    
    return 0;
}
