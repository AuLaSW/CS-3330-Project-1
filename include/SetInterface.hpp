#ifndef SET_INTERFACE
#define SET_INTERFACE

/*

Set Interface is an abstract class that represents
the public interface for interacting with sets. It
is up to the implementation of the interface to determine
what member variables are needed. This class only
provides methods to create an API for sets.

Class T: the derived class that will be implementing
         the SetInterface class template.
		 
Typename V: the typename that will be stored in the member
			variables of the set elements.

*/

template <class Derived, typename V> class SetInterface {
public:
    // Destructor
    virtual ~SetInterface();

    // Accessors/Getters
	
	// Get the next element of the set
    virtual Derived& getNext() const = 0;
	
	// Not a requirement to be able to get
	// previous element, can be implemented
	// as needed per each derived class.
	Derived& getPrev() const;

	// Input integer index, go to the element
	// at the index, and return the element
    virtual Derived& getSetElement(const int) const = 0;
    
	// Input integer index, go to element,
	// and return the element member.
    virtual V getElementMember(const int) const = 0;
    
	// Get the index number of the given element.
    virtual int getElementIndex(const Derived&) const = 0;

    // Updaters/Setters
    virtual void add(const Derived&) = 0;
    virtual void addToBeginning(const Derived&) = 0;
    virtual void addToEnd(const Derived&) = 0;
    virtual void remove(const Derived&) = 0;
    virtual void remove(const int) = 0;
};

#endif