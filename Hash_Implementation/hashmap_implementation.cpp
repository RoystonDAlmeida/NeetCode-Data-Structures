// HashMap operations
#include<iostream>
#include<algorithm> //remove_if
#include<utility> //pair
#include<vector>
#include<list>

using namespace std;

class HashMap
{
    private:
            vector<list<pair<int, int>>> data; // vector of lists for seperate chaining
            const static int size=1000; //size of the hashmap
    public:
            HashMap()
            {
                data.resize(size);  //construct the hashmap with 'size'
            }
            int hash(int key)
            {
                // Hash function generating an index
                return key%size;
            }
            void put(int key, int value)
            {
                // Insert [key, value] pair at a specific hashcode
                int hashkey=hash(key);
                for(auto &pair:data[hashkey])
                {
                    // Updating value at 'key'
                    if(pair.first==key)
                    {
                        pair.second=value;
                        return;
                    }
                }
                data[hashkey].emplace_back(key, value);
            }
            
            int get(int key)
            {
                // Return the value associated with 'key'
                int hashkey=hash(key);
                for(auto &pair:data[hashkey])
                {
                    if(pair.first==key)
                    {
                        return pair.second;
                    }
                }
                return -1;
            }
            
            void remove(int key)
            {
                // Remove a [key, value] pair with the 'key'
                // Search for the hashkey
                int hashkey=hash(key);
                data[hashkey].remove_if([key](pair<int, int>& p){return p.first==key; });
            }
};

int main()
{
    HashMap hashmap;
    
    // Inserting elements(key-value) pairs into the hashmap
    hashmap.put(1,1);
    hashmap.put(2,2);
    
    // Get the value for a key
    cout<<"Get key 1:"<<hashmap.get(1)<<endl;
    cout<<"Get key 3:"<<hashmap.get(3)<<endl;
    
    // Update the value for a key
    hashmap.put(2,1);
    
    // Check if the value is updated 
    cout<<"Get key 2:"<<hashmap.get(2)<<endl;
    
    // Remove a [key, value] pair from HashMap
    hashmap.remove(2);
    cout<<"Get Key 2:"<<hashmap.get(2)<<endl;
    
    return 0;
}
