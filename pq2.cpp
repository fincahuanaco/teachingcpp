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

class CStudent
{
   public:
   int age;
   string name;
   public:
   CStudent()
   {
     this->age=0;      
     this->name="";
   }
   CStudent(int age,string name)
   {
     this->age=age;      
     this->name=name;
   }
   bool operator>(const CStudent &to) const
   {
      return this->age > to.age;
   }

   bool operator<(const CStudent &to) const
   {
      return this->age<to.age;
   }
   friend ostream& operator<<(ostream& out, const CStudent &vec) // output
   {
    out << "(" << vec.age << ", " << vec.name << ")";
    return out;
   }
};

int main (int argc,char *argv[])
{
  std::priority_queue<CStudent> mypq;

  mypq.push(CStudent(10,"Yessenia"));
  mypq.push(CStudent(20,"Laura"));
  mypq.push(CStudent(15,"Jaqueline"));

  std::cout << "mypq.top() :" << mypq.top() << '\n';

  std::cout << "foo.size() : " << mypq.size() << '\n';

  std::cout << "Popping : \n";
  while (!mypq.empty())
  {
     std::cout << ' ' << mypq.top() <<endl;
     mypq.pop();
  }
  std::cout << '\n';


  std::priority_queue<CStudent,vector<CStudent>,CDescending<CStudent> > mypqd;

  mypqd.push(CStudent(10,"Yessenia"));
  mypqd.push(CStudent(20,"Laura"));
  mypqd.push(CStudent(15,"Jaqueline"));

  std::cout << "Popping :\n";
  while (!mypqd.empty())
  {
     std::cout << ' ' << mypqd.top() << "\n";
     mypqd.pop();
  }
  std::cout << '\n';

  return 0;
}
//g++ pq2.cpp -o pq2 
