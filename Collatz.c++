// ----------------------------
// projects/collatz/Collatz.c++
// Copyright (C) 2013
// Glenn P. Downing
// ----------------------------

// --------
// includes
// --------

#include <cassert>  // assert
#include <iostream> // endl, istream, ostream
#include <string>  //for testing purposes
#include <stdio.h>
using namespace std;


#include "Collatz.h"

// ------------
// collatz_read
// ------------

	int cache [1000000];

bool collatz_read (std::istream& r, int& i, int& j) {
    r >> i;
    if (!r)
        return false;
    r >> j;
    assert(i > 0);
    assert(j > 0);
    return true;}

// ------------
// collatz_eval
// ------------

int collatz_eval (int i, int j) {
    assert(i > 0);
    assert(j > 0);
    int max = 1;
	int temp;
	if(i>j)
	{
		temp = i;
		i = j;
		j = temp;
	}
	if(i<(j/2))
		i = j/2+1;
	for(int a = i; a <= j; a++)
	{
		int count = 1; 
		//string q("hello");
		int loca = a; 		
		if(cache[a] != 0)		//use cache if available
			count = cache[a];
		else					//otherwise, find cycle length
		{
			while (loca!=1)
			{
				//cout << "cache[" << loca << "]: " << cache[loca] << endl;
				if(loca<1000000)
				if(cache[loca] != 0)
				{
					count = count + cache[loca] - 1; //subtract 1 b/c count was initialized at 1 twice
					break;
				}
				if(loca%2 == 1)
				{
					loca = loca + (loca>>1) + 1;	//odd: (3n+1)/2, 2 steps
					count += 2;
				}
				else
				{
					loca = loca/2;					//even: n/2, 1 step
					count++;
				}
			}
			cache[a] = count;
			
		}
	if (count > max)
				max = count;
    assert(max > 0);
	}
	  return max;
}

// -------------
// collatz_print
// -------------

void collatz_print (std::ostream& w, int i, int j, int v) {
    assert(i > 0);
    assert(j > 0);
    assert(v > 0);
    w << i << " " << j << " " << v << std::endl;}

// -------------
// collatz_solve
// -------------

void collatz_solve (std::istream& r, std::ostream& w) {
    int i;
    int j;
    while (collatz_read(r, i, j)) {
        const int v = collatz_eval(i, j);
        collatz_print(w, i, j, v);}}
