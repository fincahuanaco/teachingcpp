#include <iostream>       // std::cout
#include <queue>          // std::priority_queue, std::swap(priority_queue)
#include <vector>

using namespace std;

template<class T>
class CDescending
{
    public:
    bool operator()(T a, T b) const {
        return a > b;
    }
};

int main ()
{
  std::priority_queue<int> mypq;

  mypq.push(10);
  mypq.push(20);
  mypq.push(15);

  std::cout << "mypq.top() :" << mypq.top() << '\n';


  std::priority_queue<int> foo,bar;

  foo.push (15); 
  foo.push(30); 
  foo.push(10);

  bar.push (101); 
  bar.push(202);

  swap(foo,bar);

  std::cout << "foo.size() : " << foo.size() << '\n';
  std::cout << "bar.size() : " << bar.size() << '\n';

  std::priority_queue<int,vector<int>,CDescending<int> > mypqd;

  mypqd.push(30);
  mypqd.push(100);
  mypqd.push(25);
  mypqd.push(40);

  std::cout << "Popping :";
  while (!mypqd.empty())
  {
     std::cout << ' ' << mypqd.top();
     mypqd.pop();
  }
  std::cout << '\n';

  return 0;
}
//g++ pq1.cpp -o pq1 
