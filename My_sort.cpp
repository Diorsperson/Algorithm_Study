#include<iostream>
#include<functional>
using namespace std;
 

class My_sort{
public:
  template<typename T>
  static bool ascending_order(T a,T b){
    return a > b;
  }
  //想要实现降序，需要强转为（function<bool(int,int)>）
  template<typename T>
  static bool descending_order(T a,T b){
    return a < b;
  }

  template<typename T>  
  static void bubble_sort(T* a,int n,function<bool(T,T)> cmp = ascending_order<T>,int begin = 0,int end = -1){
    if(end == -1){
      end = n - 1;
    }
    for(int i = begin;i <= end - 1;i++){
      bool flag = false;
      for(int j = begin;j <= end - 1 - i;j++){
        if(cmp(a[j],a[j + 1])){
          swap(a[j],a[j + 1]);
          flag = true;
        }
      }
      if(!flag)
        break;
    }
  }

  template<typename T>
  static void showArr(T* arr,int n,int begin = 0,int end = -1){
    if(end == -1)
      end = n - 1;
    for(int i = begin;i <= end;i++)
      cout << arr[i] << " ";
    cout << '\n';
  }
public:

};

int main(){
  int a[] = {2,5,1,4,3};
  int n = sizeof a / sizeof(int);
  My_sort::bubble_sort(a,n);
  My_sort::showArr(a,n,1);
  My_sort::bubble_sort(a,n,(function<bool(int,int)>)My_sort::descending_order<int>);
  My_sort::showArr(a,n);

  return 0;
}