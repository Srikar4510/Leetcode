class NumberContainers {
public:
//O(N),O(N)
    // Constructor
    // The data structures are already initialized as
    // part of the member variable declarations.
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(indexToNumber.find(index)!=indexToNumber.end()){
            int previousNumber = indexToNumber[index];
            numberToIndices[previousNumber].erase(index);
            if(numberToIndices[previousNumber].empty()){
                numberToIndices.erase(previousNumber);
            }
        }
        indexToNumber[index]=number;
        numberToIndices[number].insert(index);
    }
    
    int find(int number) {
        if(numberToIndices.find(number)!=numberToIndices.end()){
            // Get the smallest index
            return *numberToIndices[number].begin();
        }
        return -1;
    }
private:
   unordered_map<int,set<int>> numberToIndices;
   unordered_map<int,int> indexToNumber;    
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */