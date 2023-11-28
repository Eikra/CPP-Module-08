#include <iostream>
#include <stack>
#include <list>
#include <deque>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
public:
    typedef typename Container::iterator iterator;
    typedef typename Container::const_iterator const_iterator;
    typedef typename Container::reverse_iterator reverse_iterator;
    typedef typename Container::const_reverse_iterator const_reverse_iterator;

    // Constructors
    MutantStack() : std::stack<T, Container>() {}
    MutantStack(const MutantStack& other) : std::stack<T, Container>(other) {}

    // Assignment operator
    MutantStack& operator=(const MutantStack& other) {
        if (this != &other) {
            std::stack<T, Container>::operator=(other);
        }
        return *this;
    }

    // Destructor
    ~MutantStack() {}

    // Iterators
    iterator begin() { return this->c.begin(); }
    iterator end() { return this->c.end(); }

    const_iterator begin() const { return this->c.begin(); }
    const_iterator end() const { return this->c.end(); }

    reverse_iterator rbegin() { return this->c.rbegin(); }
    reverse_iterator rend() { return this->c.rend(); }

    const_reverse_iterator rbegin() const { return this->c.rbegin(); }
    const_reverse_iterator rend() const { return this->c.rend(); }
};

int main() {
    MutantStack<int, std::deque<int> > mstack;
    mstack.push(5);
    mstack.push(17);

    MutantStack<int, std::deque<int> > mstack_copy(mstack);

    MutantStack<int, std::deque<int> >::reverse_iterator rit = mstack_copy.rbegin();
    MutantStack<int, std::deque<int> >::reverse_iterator rend = mstack_copy.rend();
    while (rit != rend) {
        std::cout << *rit << std::endl;
        ++rit;
    }

    // Assignment
    MutantStack<int, std::deque<int> > mstack_assign;
    mstack_assign = mstack_copy;

    return 0;
}