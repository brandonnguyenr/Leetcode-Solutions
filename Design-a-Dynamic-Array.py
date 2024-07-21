# Design a Dynamic Array (aka a resizable array) class, such as an ArrayList in Java or a vector in C++.

# Your DynamicArray class should support the following operations:

# DynamicArray(int capacity) will initialize an empty array with a capacity of capacity, where capacity > 0.
# int get(int i) will return the element at index i. Assume that index i is valid.
# void set(int i, int n) will set the element at index i to n. Assume that index i is valid.
# void pushback(int n) will push the element n to the end of the array.
# int popback() will pop and return the element at the end of the array. Assume that the array is non-empty.
# void resize() will double the capacity of the array.
# int getSize() will return the number of elements in the array.
# int getCapacity() will return the capacity of the array.
# If we call void pushback(int n) but the array is full, we should resize the array first.

class DynamicArray:
    
    def __init__(self, capacity: int):
        #size of the array; initizied to zero
        self.size = 0
        #save that capacity because it could be changing
        self.capacity = capacity 
        #initialize an array of a certain length (capacity)
        self.arr = [0] * capacity 

    def get(self, i: int) -> int:
        #check to see if the size of the array is zero; if it is throw an execption
        if i >= self.size:
            return -1
        #index i is always going to be valid - return array at given location
        return self.arr[i]

    def set(self, i: int, n: int) -> None:
        #at index i insert the value n
        self.arr[i] = n

    def pushback(self, n: int) -> None:
        #if we have the size equal to the capacity; we want to resize the array so we can add to it
        if self.size == self.capacity:
            self.resize()
        #size is incremented by 1 when we pushback a value
        self.arr[self.size] = n
        self.size += 1

    def popback(self) -> int:
        #decrease the size of the element
        self.size -= 1
        return self.arr[self.size]
 
    def resize(self) -> None:
        #double the size of the array
        self.capacity = 2 * self.capacity
        #create a new array with new capacity
        new_arr = [0] * self.capacity

        #loop old data to new array
        for i in range(self.size):
            new_arr[i] = self.arr[i]
        #set new array to the old array
        self.arr = new_arr

    def getSize(self) -> int:
        #return the size
        return self.size
        
    def getCapacity(self) -> int:
        #return the capacity
        return self.capacity
