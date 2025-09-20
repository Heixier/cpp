#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>
#include <unistd.h>

#include "MutantStack.hpp"
#include "colors.hpp"

static void mstack_pdf()
{
	std::cout << ICE_BLUE << "MutantStack PDF test: " << END << '\n';
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
}

static void list_pdf()
{
	std::cout << ICE_BLUE << "std::list PDF test: " << END << '\n';
	std::list<int> mstack;
	mstack.push_back(5);
	mstack.push_back(17);
	std::cout << mstack.back() << std::endl;
	mstack.pop_back();
	std::cout << mstack.size() << std::endl;
	mstack.push_back(3);
	mstack.push_back(5);
	mstack.push_back(737);
	mstack.push_back(0);
	std::list<int>::iterator it = mstack.begin();
	std::list<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::list<int> s(mstack);
}

static void mstack_alphabet()
{
	std::cout << ICE_BLUE << "MutantStack Alphabet test: " << END << '\n';

	MutantStack<char> alphabet;
	for (char letter = 'a'; letter <= 'z'; letter++)
		alphabet.push(letter);

	std::copy(alphabet.begin(), alphabet.end(), std::ostream_iterator<char>(std::cout, ""));
	std::cout << '\n';
}

static void mstack_random()
{
	std::cout << ICE_BLUE << "MutantStack Random test: " << END << '\n';
	srand(time(NULL));

	static int bound = 100;
	int amount_to_add = rand() % bound;
	int amount_to_pop = rand() % bound;
	amount_to_pop = (amount_to_add < amount_to_pop) ? amount_to_add : amount_to_pop;

	MutantStack<long long> rand_mstack;
	
	std::cout << YELLOW << "Adding " << amount_to_add << " random numbers to stack: " << END << '\n';
	for (int i = 0; i < amount_to_add; i++)
		rand_mstack.push(rand() % __LONG_LONG_MAX__);

	std::cout << LIGHT_GREEN << "Random stack contents (size: " << rand_mstack.size() << ", last: " << (rand_mstack.empty() ? 0 : rand_mstack.top()) << "): " << END << '\n';
	std::copy(rand_mstack.begin(), rand_mstack.end(), std::ostream_iterator<long long>(std::cout, "\n"));

	std::cout << YELLOW << "Making backup of original stack...\n";
	MutantStack<long long> backup(rand_mstack);

	std::cout << YELLOW << "Popping " << amount_to_pop << " numbers from stack: " << END << '\n';
	for (int i = 0; i < amount_to_pop; i++)
		rand_mstack.pop();

	std::cout << LIGHT_GREEN << "Remaining stack contents (size: " << rand_mstack.size() << ", last: " << (rand_mstack.empty() ? 0 : rand_mstack.top()) << "): " << END << '\n';
	std::copy(rand_mstack.begin(), rand_mstack.end(), std::ostream_iterator<long long>(std::cout, "\n"));

	std::cout << LIGHT_GREEN << "Backup stack contents (size: " << backup.size() << ", last: " << (backup.empty() ? 0 : backup.top()) << "): " << END << '\n';
	std::copy(backup.begin(), backup.end(), std::ostream_iterator<long long>(std::cout, "\n"));

	std::cout << YELLOW << "Assigning original stack to backup stack..." << END << '\n';
	backup = rand_mstack;

	std::cout << LIGHT_GREEN << "Backup stack contents (size: " << backup.size() << ", last: " << (backup.empty() ? 0 : backup.top()) << "): " << END << '\n';
	std::copy(backup.begin(), backup.end(), std::ostream_iterator<long long>(std::cout, "\n"));

	std::cout << LIGHT_GREEN << "Original remaining stack contents (size: " << rand_mstack.size() << ", last: " << (rand_mstack.empty() ? 0 : rand_mstack.top()) << "): " << END << '\n';
	std::copy(rand_mstack.begin(), rand_mstack.end(), std::ostream_iterator<long long>(std::cout, "\n"));
}

int main()
{
	mstack_pdf();
	list_pdf();
	mstack_alphabet();
	mstack_random();
}