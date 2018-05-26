#include <iostream>
#include <vector>

using namespace std;

bool add(char a[], char b[], int size, char res[]) {
  vector <int> v;
  int temp = 0;
  bool result = true;

  for(int i = 0; i < size; i++) {
    int sum = (b[size - 1 - i] - '0') + (a[size - 1 - i] - '0');

    if(temp) sum += 1;

    if(sum > 9) {
      temp = 1;
      sum -= 10;
    } else {
      temp = 0;
    }

    if(sum < 0 || sum > 18) {
      result = false;
      break;
    }

    v.push_back(sum);
  }

  if(temp == 1) v.push_back(temp);

  for(int i = 0; i < v.size(); i++) {
    res[v.size() - 1 - i] = v[i] + '0';
  }

  return result;
}

bool calcSum(char a[], char b[], char res[]) {
  int a_size = 0;
  int b_size = 0;
  bool result = true;

  while(a[a_size] != '\0') {
    a_size++;
  }

  while(b[b_size] != '\0') {
    b_size++;
  }

  if(a_size > b_size) {
    int diff = a_size - b_size;

    char c[a_size + 1];
    for(int i = 0; i < a_size; i++) {
      if(i < diff) {
        c[i] = '0';
      } else {
        c[i] = b[i - diff];
      }
    }

    cout << a << "-" << c << endl;

    result = add(a, c, a_size, res);
  } else if(b_size > a_size){
    int diff = b_size - a_size;
    
    char c[b_size + 1];
    for(int i = 0; i < b_size; i++) {
      if(i < diff) {
        c[i] = '0';
      } else {
        c[i] = a[i - diff];
      }
    }

    cout << c << "-" << b << endl;

    result = add(c, b, b_size, res);
  } else {
    cout << a << "-" << b << endl;

    result = add(a, b, a_size, res);
  }

  return result;
}

int main() {
  char a[2] = "2";
  char b[6] = "99999";
  char res[1024];

  cout << calcSum(a, b, res) << endl;
  cout << res << endl;
}
