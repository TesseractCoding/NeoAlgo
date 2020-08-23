# Bucket Sort Algorithm

# Function to perform Insertion Sort
def insertion_sort(array, size):
        
    for index1 in range(1, size):
        
        value = array[index1]
        index2 = index1 - 1
            
        while index2 >= 0 and array[index2] > value : 
            
            array[index2 + 1] = array[index2] 
            index2 -= 1
            
        array[index2 + 1] = value
      
    return array   

# Function to perform Bucket Sorting
def bucket_sort(unsortedArray, size):
    
    bucket = [[]] * size # Bucket should be of same size as that of Unsorted Array
    MAX = max(unsortedArray)
    
    for index in range(size):
        index1 = int((size * unsortedArray[index])/MAX)
        
        if index1 == size:
            index1 -= 1
        
        if len(bucket[index1]):
            bucket[index1].append(unsortedArray[index])
        else:
            bucket[index1] = [unsortedArray[index]]
        
    sortedArray = [] # List in which sorted elements are to be placed
    
    # Perform Insertion Sort on all non-empty individual Bucket
    for index in range(size):
        
        if len(bucket[index]):
            sortedArray.extend(insertion_sort(bucket[index], len(bucket[index])))
        
    return sortedArray

def main():
    # Enter the size of Unsorted List/Array
    size = int(input())

    unsortedArray = []

    # Enter the elements of List/Array 
    for index in range(size):
    
        element = int(input())
        unsortedArray.append(element)

    print("Unsorted Array :", unsortedArray) # Print Unsorted Array

    print("Sorted Array : ", bucket_sort(unsortedArray, size)) # Print Sorted Array
 
if __name__ == "__main__":
    main()
