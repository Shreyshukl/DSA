// C++ Program to reverse a string without 
// using temp variable 
#include <bits/stdc++.h> 
using namespace std; 

// Function to reverse string and return reversed string 
string reversingString(string str, int start, int end) 
{ 
	// Iterate loop upto start not equal to end 
	while (start < end) 
	{ 
		// XOR for swapping the variable 
		str[start] ^= str[end]; 
		str[end] ^= str[start]; 
		str[start] ^= str[end]; 

		++start; 
		--end; 
	} 
	return str; 
} 

// Driver Code 
int main() 
{ 
	string s = "GeeksforGeeks"; 
	cout << reversingString(s, 0, 12); 
	return 0; 
} 
//
string reversingString(string str, int start, int end) 
{ 
    while (start < end) {
        swap(str[start], str[end]);
        start++;
        end--;
    }
    return str; 
}
