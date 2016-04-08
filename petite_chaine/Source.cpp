#include <iostream>
#include "petite_chaine.h"
using namespace std;

int main()
{
   petite_chaine str("allo");
   cout << str.empty() << endl;
   cout << (int)str.size() << endl;
   for (size_t i = 0; i < str.size(); i++)
   {
      cout << str[i];
   }
   cout << endl;

   cout << "==" << endl;
   cout << boolalpha << (str == petite_chaine("allo"))<< "- true" << endl;
   cout << boolalpha << (str == petite_chaine("bye")) << "- false" << endl;

   cout << "!=" << endl;
   cout << boolalpha << (str != petite_chaine("allo")) << "- false" << endl;
   cout << boolalpha << (str != petite_chaine("bye")) << "- true" << endl;

   cout << "<" << endl;
   cout << boolalpha << (str < petite_chaine("allo")) << "- false" << endl;
   cout << boolalpha << (str < petite_chaine("bye")) << "- true" << endl;

   cout << "<=" << endl;
   cout << boolalpha << (str <= petite_chaine("allo")) << "- true" << endl;
   cout << boolalpha << (petite_chaine("bye") <= str ) << "- false" << endl;

   cout << ">" << endl;
   cout << boolalpha << (str > petite_chaine("allo")) << "- false" << endl;
   cout << boolalpha << (petite_chaine("bye") > str) << "- true" << endl;

   cout << ">=" << endl;
   cout << boolalpha << (str >= petite_chaine("allo")) << "- true" << endl;
   cout << boolalpha << (str >= petite_chaine("bye")) << "- false" << endl;

   cout << boolalpha << (petite_chaine("bye") >= str) << "- true" << endl;

   cout << str << endl;
   petite_chaine str2("bye");
   cin>>str>>str2;

   cout << str << endl;
   cout << str2 << endl;




}