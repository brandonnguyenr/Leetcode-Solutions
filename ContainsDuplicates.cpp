//(217) Given an array of integers, find if the array contains any duplicates
//* your function should return true if any value apppears at least twice in the arrray,
//and it should return false if every element is distinct *

class Solution {
public:

    //== definitions ==
    //bool: is the return type of the function: return either true or false
    //containsDuplicate: is the name of the function - use this when calling
    //vector<int>& nums: parameter of the fuction - (&) means reference to a vector 
    //                   of integers named nums. The (&) means that the vector is passed in
    //                   be reference which means that the funciton will operate on the origional vector
    //                   directly, rather than creating a copy of it

    bool containsDuplicate(vector<int>& nums) {

        //start by creating a map 
        //its key/value pair means the key type is an int, and the value type is an int

        map<int, int> countMap;

        //this for loops ends when the array size is reached
        for(int i=0; i<nums.size(); i++) {

            //this checks the map if "nums[i]]" already exists as a key in countMap
            //this condition checks if the value associated with the key 'nums[i] is non-zero

            //in C++ when you access a non-existing ket in a map, it automatically creates that key with 
            //  the default value for its data type (int is 0)

            //if the value associated with nums[i] is greater than zero it means that the element has
            //  already occured before in the 'nums' vector
            //  returning true
            if(countMap[nums[i]]) {
                return true;
            }

            //if there is no duplicate -> increment the value to check for the next integer
            countMap[nums[i]]++;
        }
        return false;
    }
};
