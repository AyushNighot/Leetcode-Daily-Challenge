Problem Link:- https://leetcode.com/problems/insert-delete-getrandom-o1

///////////////////////////////////////////////////////////////////////////////////////////////

Intuition & Approach
Let's break down the main components of the class:

1- Constructor (RandomizedSet()): Initializes the class, and sets the variable i to 0.

2- Insert (bool insert(int val) ): Inserts an element into the set if it's not already present. It checks if the element is present in the unordered_map (mp). If not, it adds the element to the vector (arr), updates the mapping in the unordered_map, increments the index (i`), and returns true. If the element is already present, it returns false.

3-Remove (bool remove(int val) ): Removes an element from the set if it exists. It checks if the element is present in the unordered_map (mp). If not, it returns false. If the element is present, it swaps the element with the last element in the vector (arr), updates the mapping in the unordered_map, and removes the last element. It then updates the index (i`) and returns true.

4- GetRandom (int getRandom() ): Returns a random element from the set. It generates a random index using rand() % arr.size() and returns the element at that index in the vector (arr`).

The RandomizedSet class ensures that insert, remove, and getRandom operations have an average time complexity of O(1). This is achieved by using an unordered_map for constant-time lookup and a vector for constant-time random access. The removal operation swaps the element to be removed with the last element in the vector, allowing for constant-time removal.

///////////////////////////////////////////////////////////////////////////////////////////////////

Complexity

Time complexity:0(1)
Space complexity:0(n) because of map and vector

////////////////////////////////////////////////////////////////////////////////////////////////////

CODE :-

class RandomizedSet {
public:
    unordered_map<int,int>mp;
    vector<int> arr;
    int i;
    RandomizedSet() {
        i=0;
    }
    
    bool insert(int val) {
        if(mp.find(val)==mp.end()){
            arr.push_back(val);
            mp[val]=i++;
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(mp.find(val)==mp.end()){
            return false;
        }
        else{
            int x=arr.back();
            arr[mp[val]]=x;
            arr.pop_back();
            mp[x]=mp[val];
            mp.erase(val);
            i--;
            return true;
        }
    }
    
    int getRandom() {
        return arr[rand()%arr.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */