#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

class Person {
protected:
  string name;
  int age;

public:
  virtual void getdata() {
    cin >> name;
    cin >> age;
  }
  virtual void putdata() { cout << name << " " << age << " "; }
};

class Professor : public Person {
protected:
  int publications;
  int curr_id;

public:
  static int prof_id;

  Professor() {
    curr_id = prof_id + 1;
    prof_id++;
  }

public:
  void getdata() {
    Person::getdata();
    cin >> publications;
  }
  void putdata() {
    Person::putdata();
    cout << publications << " " << curr_id << endl;
  }
};

class Student : public Person {

protected:
  int marks[6];
  int curr_id;

public:
  static int stud_id;
  Student() {
    curr_id = stud_id + 1;
    stud_id++;
  }

public:
  void getdata() {
    Person::getdata();
    for (int i = 0; i < 6; i++) {
      cin >> marks[i];
    }
  }
  void putdata() {
    Person::putdata();
    for (int i = 0; i < 6; i++) {
      cout << marks[i] << " ";
    }
    cout << curr_id << endl;
  }
};
int Professor::prof_id = 0;
int Student::stud_id = 0;
int main() {

  int n, val;
  cin >> n; // The number of objects that is going to be created.
  Person *per[n];

  for (int i = 0; i < n; i++) {

    cin >> val;
    if (val == 1) {
      // If val is 1 current object is of type Professor
      per[i] = new Professor;

    } else
      per[i] = new Student; // Else the current object is of type Student

    per[i]->getdata(); // Get the data from the user.
  }

  for (int i = 0; i < n; i++)
    per[i]->putdata(); // Print the required output for each object.

  return 0;
}
