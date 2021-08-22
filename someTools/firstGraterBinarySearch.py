
#this function takes a sorted array
#and return the index of the first element in arr grater or equal to x
def fgBinarySearch(arr,x):
    low = 0
    high = len(arr) - 1
    mid = 0

    while low != high:
        mid = (high + low) // 2

        if arr[mid] < x:
            low = mid + 1

        else:
            high = mid

    
    if arr[low]<x:
        return -1 
    return low


arr1=[1,2,3,4,5,6,7,8,9,10]
for i in range(len(arr1)):
    assert( fgBinarySearch(arr1,arr1[i]) == i)

arr2=[1,1,1,2,2,3,3,3,4,5,5,6,7,7]
assert(fgBinarySearch(arr2,0)==0)
assert(fgBinarySearch(arr2,1)==0)
assert(fgBinarySearch(arr2,2)==3)
assert(fgBinarySearch(arr2,3)==5)
assert(fgBinarySearch(arr2,4)==8)
assert(fgBinarySearch(arr2,5)==9)
assert(fgBinarySearch(arr2,6)==11)
assert(fgBinarySearch(arr2,7)==12)

arr3=[1800,2000,3990,4500,10700,10700,25000,33213,35694,40777]
for i in range(0,1801):
    assert(fgBinarySearch(arr3,i)==0)

for i in range(1801,2001):
    assert(fgBinarySearch(arr3,i)==1)

for i in range(2001,3991):
    assert(fgBinarySearch(arr3,i)==2)

for i in range(3991,4501):
    assert(fgBinarySearch(arr3,i)==3)

for i in range(4501,10701):
    assert(fgBinarySearch(arr3,i)==4)

for i in range(10701,25001):
    assert(fgBinarySearch(arr3,i)==6)

for i in range(25001,33214):
    assert(fgBinarySearch(arr3,i)==7)

for i in range(33214,35695):
    assert(fgBinarySearch(arr3,i)==8)

for i in range(35695,40778):
    assert(fgBinarySearch(arr3,i)==9)

for i in range(40778,50001):
    assert(fgBinarySearch(arr3,i)==-1)
    