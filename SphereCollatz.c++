// --------------------------
// projects/collatz/Collatz.h
// Copyright (C) 2013
// Glenn P. Downing
// --------------------------

//#ifndef Collatz_h
//#define Collatz_h

// --------
// includes
// --------

#include <iostream> // istream, ostream
#include <cassert>  // assert
// ------------
// collatz_read
// ------------

/**
 * reads two ints into i and j
 * @param r a  std::istream
 * @param i an int by reference
 * @param j an int by reference
 * @return true if that succeeds, false otherwise
 */
bool collatz_read (std::istream&, int&, int&);

// ------------
// collatz_eval
// ------------

/**
 * @param i the beginning of the range, inclusive
 * @param j the end       of the range, inclusive
 * @return the max cycle length in the range [i, j]
 */
int collatz_eval (int, int);

// -------------
// collatz_print
// -------------

/**
 * prints the values of i, j, and v
 * @param w a std::ostream
 * @param i the beginning of the range, inclusive
 * @param j the end       of the range, inclusive
 * @param v the max cycle length
 */
void collatz_print (std::ostream&, int, int, int);

// -------------
// collatz_solve
// -------------

/**
 * read, eval, print loop
 * @param r a std::istream
 * @param w a std::ostream
 */
void collatz_solve (std::istream&, std::ostream&);

//#endif  Collatz_h


// ----------------------------
// projects/collatz/Collatz.c++
// Copyright (C) 2013
// Glenn P. Downing
// ----------------------------

// --------
// includes
// --------


#include <iostream> // endl, istream, ostream
#include <string>  //for testing purposes
#include <stdio.h>
using namespace std;


//#include "Collatz.h"

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
	for(int a = i; a <= j; a++)
	{
		int count = 1; 
		//string q("hello");
		int loca = a; 		//I am so fiching high right now I just don't even know what to do twith myselfl. I might pass out soon frim all of these crazy drugs Taylor just gave me.
		//cout << "cache[" << a << "]: " << cache[a] << endl;
		if(cache[a] != 0)		//use cache if available
			count = cache[a];
		else					//otherwise, find cycle length
		{
			while (loca!=1)
			{
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
		
		
		
// -------------------------------
// projects/collatz/RunCollatz.c++
// Copyright (C) 2013
// Glenn P. Downing
// -------------------------------

/*
To run the program:
    % g++ -pedantic -std=c++0x -Wall Collatz.c++ RunCollatz.c++ -o RunCollatz
    % valgrind RunCollatz < RunCollatz.in > RunCollatz.out

To configure Doxygen:
    % doxygen -g
That creates the file "Doxyfile".
Make the following edits:
    EXTRACT_ALL            = YES
    EXTRACT_PRIVATE        = YES
    EXTRACT_STATIC         = YES
    GENERATE_LATEX         = NO

To document the program:
    % doxygen Doxyfile
*/

// -------
// defines
// -------

#ifdef ONLINE_JUDGE
    #define NDEBUG
#endif

// --------
// includes
// --------

#include <iostream> // cin, cout, ios_base

//#include "Collatz.h"

// ----
// main
// ----

int main () {
    using namespace std;
    ios_base::sync_with_stdio(false); // turn off synchronization with C I/O
    collatz_solve(cin, cout);
    return 0;}