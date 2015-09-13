# cpp_skiplist

This is a skiplist implemented as a usable container class in C++. Make sure to add a template instantiation at the end of the skiplist.cpp file. This class is built around many functions that don't exist prior to C++11, so I'd strongly recommend not using it for anything that can't support that standard.

Use 'make test' to compile the test program. This is a very simple program that lets you see the functioning of the skiplist. You enter an integer that isn't in the list to add it, and enter an integer that is already in the list to delete it. Enter -1 to quit. You will see output that looks something like this (NB: git's text display will concatenate this to meaninglessness. Try it in a real editor):

-infinity   - - - 
0           - | | 
1           - - | 
4           - | | 
19          - | | 
22          - - - 
47          - | | 
56          - | | 
98          - - | 
100         - - | 
101         - - | 
infinity    - - - 

where the height for each node is depicted with dashes on the horizontal axis. The vertical bars represent connections between nodes with the same height, for instance the connection at the top level between negative infinity and 22.
