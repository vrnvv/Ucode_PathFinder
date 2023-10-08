Ucode_Pathfinder - This is an implementation of an algorithm for finding shortcuts and alternative methods.
To use Pathfinder, install it using the step-by-step MakeFile build and follow people:

````bash
make - install Pathfinder
make reinstall - reinstall Pathfinder
make uninstall - uninstall Pathfinder
make clean - Delete binary file
````
Start Pathfinder

````bash
./pathfinder [file]
````
The utility accepts a text file with instructions as input arguments:
````c++
1. 5 = number of islands
2. A-B,2 = from island - to island, distance
3. B-C,3
4. C-D,6
5. D-E,1
6. 
````

````output
========================================
Path: A -> B
Route: A -> B
Distance: 2
========================================
========================================
Path: A -> C
Route: A -> B -> C
Distance: 2 + 3 = 5
========================================
========================================
Path: A -> D
Route: A -> B -> C -> D
Distance: 2 + 3 + 6 = 11
========================================
========================================
Path: A -> E
Route: A -> B -> C -> D -> E
Distance: 2 + 3 + 6 + 1 = 12
========================================
========================================
Path: B -> C
Route: B -> C
Distance: 3
========================================
========================================
Path: B -> D
Route: B -> C -> D
Distance: 3 + 6 = 9
========================================
========================================
Path: B -> E
Route: B -> C -> D -> E
Distance: 3 + 6 + 1 = 10
========================================
========================================
Path: C -> D
Route: C -> D
Distance: 6
========================================
========================================
Path: C -> E
Route: C -> D -> E
Distance: 6 + 1 = 7
========================================
========================================
Path: D -> E
Route: D -> E
Distance: 1
========================================
````
