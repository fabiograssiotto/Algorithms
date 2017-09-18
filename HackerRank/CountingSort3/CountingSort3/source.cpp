/* https://www.hackerrank.com/challenges/countingsort3
In the previous challenge, it was easy to print all the integers in order, since you did not have to access
the original list. Once you had obtained the frequencies of all the integers, you could simply print each 
integer in order the correct number of times. However, if there is other data associated with an element, 
you will have to access the original element itself.

In the final counting sort challenge, you are required to print the data associated with each integer.
This means, you will go through the original array to get the data, and then use some "helper arrays"
to determine where to place everything in a sorted array.

If you know the frequencies of each element, you know how many times to place it, but which index will
you start placing it from? It will be helpful to create a helper array for the "starting values" of each element.

Challenge
You will be given a list that contains both integers and strings. In this challenge you just care about the integers.
For every value i from 0 to 99, can you output L, the number of elements that are less than or equal to i?

Input Format
- n, the size of the list ar.
- n lines follow, each containing an integer x and a string s.

Output Format
Output L for all numbers from 0 to 99 (inclusive).

Constraints
1 <= n <= 1000000
0 <= x < 100, x E ar
length of string <= 10

*/
#include <iostream>
#include <string>
using namespace std;

int main() {
	int n; 
	cin >> n;
	int count[100] = { 0 };
	// Read in numbers and add to frequency vector.
	for (int i = 0; i < n; i++) {
		int number;
		cin >> number;
		count[number]++;
		string s;
		cin >> s; // discard
	}
	// Create cummulative count vector.
	for (int i = 1; i < 100; i++) {
		count[i] = count[i] + count[i-1];
	}
	for (int j = 0; j < 100; j++) {
		cout << count[j] << " ";
	}
	cout << endl;
}