it was a premiu problem in leetcode that whay we need to explain this in the readme file.

there is a tree given in which you have to do some tasks repeatedly untill all nodes get deleted:-
1. collect all leaf nodes and push them in a vector and then push that vector in to the ans vector which isa 2d vector
2. remove the leafe nodes you collected now
3. then repeat these steps again untill all nodes get deleted

At last return the vector of vectors which contains collection of leaf nodes we got while performing theses operations repeatedly..

like in tree:- 1,2,3,4,5,N,N,6

the ans will be: [ [6,5,3], [4], [2], [1 ] ]
