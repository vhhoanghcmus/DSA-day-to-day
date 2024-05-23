#include <bits/stdc++.h>

using namespace std;

template<typename Comparable>

class BinarySearchTree 
{
    struct BinaryNode
    {
        Comparable emlement;
        BinaryNode *pLeft;
        BinaryNode *pRight;

        BinaryNode( const Comparable & theElement, BinaryNode *pLeft, BinaryNode *pRight) : element {theElement}, pLeft {pLeft}, pRight {pRight} {}
        BinaryNode( Comparable && theElement, BinaryNode *pLeft, BinaryNode *pRight) : element { std :: move(theElement)}, pLeft {pLeft}, pRight {pRight} {}

    };
    public:
        BinarySearch();
        BinarySearch(const BinarySearchTree & rhs);
        BinarySearch(BinarySearchTree && rhs);
        ~BinarySearch();

        const Comparable & findMin () const;
        const Comparable & findMax () const;
        bool contains( const Comparable & x ) const;
        bool isEmpty( ) const;
        void printTree( ostream & out = count ) const;

        void makeEmpty();
        void insert( const Comparable & x );
        void insert( Comparable && x );
        void remove( const Comparable & x );

        BinarySearchTree & operator = ( const BinarySearchTree & rhs ); 
        BinarySearchTree & operator = (BinarySearchTree && rhs );

        void insert ( const Comparable & x, BinaryNode * & t );
        void insert ( Comparable && x, BinaryNode * & t );
        void remove ( const Comparable & x, BinaryNode * & t );

        BinaryNode * findMin ( BinaryNode *t) const;
        BinaryNode * findMax ( BinaryNode *t) const;
        
        bool contains( const Comparable & x, BinaryNode *t ) const;
        void makeEmpty (BinaryNode * & t);
        void printTree( BinaryNode *t, ostream & out) const;
        BinaryNode * clone( BinaryNode * t ) const;


/**
* Returns true if x is found in the tree.
*/
bool contains( const Comparable & x ) const
{
return contains( x, root );
}
/**
 * Insert x into the tree; duplicates are ignored.
 */
void insert( const Comparable & x )
{
insert( x, root );
}

/**
* Remove x from the tree. Nothing is done if x is not found.
*/
void remove( const Comparable & x )
{
remove( x, root );
}
};

