# include <iostream>

// library for generating random 64 bit number
# include <cstdlib>

// to ensure random number are different each time the program runs
# include <ctime>
# include <string>
# include <random>

using namespace std;

// creating Node
class Node {
public:

	// to store 64 bit number in each node
	uint64_t data;

	// pointer to point to next node in list
	Node* next;

	// constructor
	Node(uint64_t value) {
		data = value;
		next = nullptr;
	}
};

// creating linked list
class LinkedList {
public:
	Node* head;

	LinkedList() {
		head = nullptr;
	}

	// function to insert a new node in list
	void insert(uint64_t value) {

		// allocating memory for new node
		Node* newNode = new Node(value);

		// if list is empty then new node is the head
		if (head == nullptr) {
			head = newNode;
		}

		// else insert a node

		else {
			Node* current = head;
			// loop that continues until last node
			while (current->next) {
				current = current->next;
			}

			// now the next of current node will point to newNode(and not the nullptr)
			current->next = newNode;
		}
	}

	// converting the 64 bit number to string so it be reconstructed easily

	string conversion() {
		Node* current = head;

		// variable to store string
		string after_conversion;

		while (current) {

			// using to_string function for conversion
			after_conversion = to_string(current->data) + after_conversion;
			current = current->next;
		}
		return after_conversion;
	}

	// destructor
	~LinkedList() {
		Node* current = head;
		while (current) {
			Node* nextNode = current->next;

			// free the memory
			delete current;
			current = nextNode;
		}
	}
};

// function for modular exponentation

uint64_t modular_exponentation(uint64_t base, uint64_t exponent, uint64_t mod) {
	uint64_t result = 1;
	base = base % mod;

	// a loop that runs until exponent is greater than zero
	while (exponent > 0) {

		// if result is odd
		if (exponent % 2 == 1) {
			result = (result * base) % mod;
		}

		// else divide by 2
		exponent = exponent / 2;
		base = (base * base) % mod;
	}

	return result;
}

// Miller Rabin primality test
bool is_prime(LinkedList& linked_list, int k = 10) {

	// reconstructing the number
	Node* current = linked_list.head;
	uint64_t n = 0;
	uint64_t base = 1;

	
	while (current) {

		// Combining data of all nodes
		n += current->data * base;
		base <<= 64; 
		current = current->next;
	}
	


	// 0 and 1 are not prime

	if (n <= 1) {
		return false;
	}

	// 2 and 3 are prime
	if (n <= 3) {
		return true;
	}

	if (n % 2 == 0) {
		return false;
	}
	// logic to check primality
	uint64_t d = n - 1;
	int r = 0;
	while (d % 2 == 0) {
		d /= 2;
		r++;
	}

	// performing iterations
	for (int i = 0; i < k; i++) {
		uint64_t a = 2 + rand() % (n - 2);
		uint64_t x = modular_exponentation(a, d, n);

		if (x == n - 1) {
			continue;
		}

		// assuming number is composite
		bool composite = true;
		for (int i = 0; i < r - 1; i++) {
			x = modular_exponentation(x, 2, n);

			if (x == n - 1) {
				composite = false;
				break;
			}
		}

		// number is not prime
		if (composite) {
			return false;
		}

	}
	return true;
}

// function to print smaller prime numbers

void print() {
	cout << "Smaller primes: [";
	for (int i = 2; i < 100; i++) {
		bool isprime = true;
		for (int j = 2; j * j <= i; j++) {

			if (i % j == 0) {
				isprime = false;
				break;
			}
		}
		if (isprime) {
			if (i < 97) {
				cout << i << ", ";
			}
			else {
				cout << i;
			}
		}
	}
	cout << "]" << endl;

}

// main
int main() {

	// ensuring different random sequences on each run
	srand(static_cast <unsigned int> (time(0)));

	// creating object
	LinkedList linked_list;

	{
		for (int i = 0; i < 16; i++) {

			// // Generate a 64 bit random number by combining two 32 bit random numbers.
			uint64_t chunk = (static_cast<uint64_t>(rand()) << 32) | rand();
			linked_list.insert(chunk);

		}

		// reconstructing the number
		string after_conversion = linked_list.conversion();
		cout << "Input: A 1024-bit number represented as \"" << after_conversion << "\"" << endl;

		// printing smaller prime numbers
		print();

		// checking if result is prime or not
		bool result = is_prime(linked_list);
		if (result) {
			cout << "Output: True" << endl;
		}
		else {
			cout << "Output: False" << endl;
		}
	}

}
