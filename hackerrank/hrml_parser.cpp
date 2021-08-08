#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

map<string, string> parseMap;

void print_map() {
  map<string, string>::iterator itr;
  cout << "\nThe map is : \n";
  cout << "\tKEY\tELEMENT\n";
  for (itr = parseMap.begin(); itr != parseMap.end(); ++itr) {
    cout << '\t' << itr->first << '\t' << itr->second << '\n';
  }
  cout << endl;
}

void add_to_map(vector<string> hrml) {
  int i = 0;
  string whole_tag_name = "";

  while (i < hrml.size()) {

    string line = hrml[i];
    if (line.compare(1, 1, "/") != 0) {
      int start = 1;
      // cout << "start in the beginning: " << start << endl;
      string curr_tag_name = "";
      while (line.compare(start, 1, " ") && line.compare(start, 1, ">")) {
        curr_tag_name.push_back(line[start++]);
        // cout << curr_tag_name << endl;
      }
      whole_tag_name +=
          (whole_tag_name == "") ? curr_tag_name : "." + curr_tag_name;
      start = (line[start] != '>') ? start + 1 : start;

      string prop = "", value = "";

      while (line.compare(start, 1, ">")) {
        while (line.compare(start, 4, " = \"")) {
          prop.push_back(line[start++]);
        }
        start += 4;
        while (line.compare(start, 1, "\"")) {
          value.push_back(line[start++]);
        }
        parseMap.insert(
            pair<string, string>(whole_tag_name + "~" + prop, value));

        prop = "";
        value = "";
        start++;
        if (line.compare(start, 1, " ") == 0) {
          start++;
        }
      }

    } else {
      int index = 1;
      while (line.compare(index, 1, ">") && whole_tag_name != "") {
        whole_tag_name.pop_back();
        // cout << "whole tag name: " << whole_tag_name << endl;
        index++;
      }
      if (whole_tag_name[whole_tag_name.size() - 1] == '.') {
        whole_tag_name.pop_back();
      }
      // cout << "index: " << index << endl;
    }
    i++;
  }
}

void answer_queries(vector<string> queries) {
  for (int i = 0; i < queries.size(); i++) {
    string ans = parseMap.find(queries[i])->second;
    if (ans == "") {
      ans = "Not Found!";
      parseMap.erase(queries[i]);
    }
    cout << ans << endl;
  }
}

void print_Vector(vector<string> ans) {

  for (auto ip = ans.begin(); ip != ans.end(); ip++) {

    cout << *ip << ",";
  }
  cout << endl;
}

int main() {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */

  int n, q;
  cin >> n >> q;
  string line;
  vector<string> hrml_list;
  vector<string> queries;

  while (q > 0) {
    getline(cin >> ws, line);
    if (n > 0) {
      hrml_list.push_back(line);
      n--;
    } else {
      queries.push_back(line);
      q--;
    }
  }
  // print_Vector(hrml_list);
  // print_Vector(queries);
  add_to_map(hrml_list);
  // print_map();
  answer_queries(queries);

  return 0;
}
