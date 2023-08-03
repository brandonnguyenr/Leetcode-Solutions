//(242) Given two strings s and t, return true if t is an anagram of s 
//  and false otherwise

class Solution {
public:
    bool isAnagram(string s, string t) {

        //an anagram can only be true if the two strings are the same size
        if(s.length() != t.length()) {
            return false;
        }

        //create an array with size 26, all initialzed to 0
        //this array will be used to count each occrurances of each character
        //this array are mapped to the alphabet ie. arr[2] = 'b' vice versa
        int arr[26] = {0};

        //loop ending on the length of string 's'
        //the point of this loop is to check each letter would be canceled out 
        //if string 's' has a w and 't' has a w then it would cancel out in arr making that [i] (position) a zero
        // if all elements in arr[] is 0 then its an anagram, if there is a non-zero then they are not
        for(int i=0; i<s.length(); i++) {
            //for each character in 's', the code increments the count of that character
            //example: if s[i] = 'c', then 'c' - 'a' = 2 since c is 2 positions away from a
            //this results in arr[2] being accessed
            arr[s[i] - 'a']++;

            //for each character in 't', the cdoe decrements the count of that character
            //example: if t[i] is 'c', then 'c' - 'a would be 2 since 2
            arr[t[i] - 'a']--;
        }

        //this checks if any of the elements of arr are non-zeros, indicating that 's' and 't' 
        //if a character in arr[] has a non-zero they are anagrams
        for(int i=0; i<26; i++) {
            if(arr[i] != 0) {
                return false;
            }
        }
        return true;
    }
};
