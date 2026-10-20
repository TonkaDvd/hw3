#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
  int m_;
  PComparator c_;
  vector<T> HeapVector;





};

// Add implementation of member functions here
template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c){
  m_ = m;
  c_ = c;
}

template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap()
{

}


template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item){
  HeapVector.push_back(item);
  int child = HeapVector.size() - 1;
  int parent = ((child) - 1) / m_;
  while(child > 0){
    if(c_(HeapVector[child], HeapVector[parent])){
        std::swap(HeapVector[child], HeapVector[parent]);
    } else{
      break;
    }
    child = parent;
    parent = ((child) - 1) / m_;
  }
}


// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Empty Heap");


  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
   return HeapVector[0];


}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T, PComparator>::pop()
{
  if (empty()) {
    throw std::underflow_error("Empty Heap");
  }

  std::swap(HeapVector.front(), HeapVector.back());
  HeapVector.pop_back();

  if (empty()) {
    return;
  }

  size_t parent = 0;
  while (true) {
    size_t first_child = m_ * parent + 1; 

    if (first_child >= HeapVector.size()) {
      break;
    }

    size_t best_child = first_child;
    for (int i = 2; i <= m_; ++i) {
      size_t child = m_ * parent + i;
      if (child < HeapVector.size()) {
        if (c_(HeapVector[child], HeapVector[best_child])) {
          best_child = child;
        }
      } else {
        break;
      }
    }

    if (c_(HeapVector[best_child], HeapVector[parent])) {
      std::swap(HeapVector[parent], HeapVector[best_child]);
      parent = best_child;
    } else {
      break;
    }
  }
}

template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const
{
  return HeapVector.empty();
}

template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const
{
  return HeapVector.size();
}



#endif

