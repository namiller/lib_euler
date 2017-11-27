#Iterables
There are two iterable utilities available at this time.
##Subset
The subset iterable allows for iteration of all subsets of a provided size of a given set.
``` c++
subsets(set<> s, int size);
```
Will produce an iterable object that can be used to iterate over all subsets of size "size" of set s. For example:
``` c++
for (const auto& s : subsets(set<int>{1,2,3,4}, 2)) {
	// Do processing of the sets {1,2}, {1,3}, ...
}
```
##Permutation
The perumation iterable allows for iteration of all permutations of a given vector of elements.
``` c++
permutations(vector<> v);
```
Will produce an iterable object that can be used to iterate over all permutations of the given vector. For example:
``` c++
for (const auto& v : permutations(vector<int>{1,2,3})) {
	// Do processing of the vectors {1,2,3}, {1,3,2}, ...
}
```