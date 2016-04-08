#pragma once
#include <string>
#include <algorithm>
#include <iostream>
#include <iterator>

using namespace std;

class petite_chaine
{
   static const int s_getSize = 255;
   char m_chaine[256];
public:
   class size_exception {};
   petite_chaine(const char * chaine);
   petite_chaine(const std::string & chaine);
   petite_chaine(const petite_chaine& other);
   ~petite_chaine();

   unsigned int size() const { return m_chaine[s_getSize]; }
   bool empty() const { return m_chaine[s_getSize] == 0; }

   class out_of_bound_exception {};
   char &operator[](uint8_t pos)
   {
      if (pos > size())
         throw out_of_bound_exception();
      return m_chaine[pos];
   }

   petite_chaine& operator=(const petite_chaine& other)
   {
      copy(other.m_chaine, other.m_chaine+256, m_chaine);
      return *this;
   }

   char operator[](uint8_t pos) const
   {
      if (pos > size())
         throw out_of_bound_exception();
      return m_chaine[pos];
   }

   bool operator==(const petite_chaine& other) const
   {
      return !lexicographical_compare(begin(m_chaine), m_chaine + size(), begin(other.m_chaine), other.m_chaine + other.size());
   }

   bool operator!=(const petite_chaine& other) const
   {
      return !(*this == other);
   }

   bool operator<(const petite_chaine& other) const
   {
      return lexicographical_compare(begin(m_chaine), m_chaine + size(), begin(other.m_chaine), other.m_chaine + other.size());
   }
   bool operator>(const petite_chaine& other) const
   {
      return other < *this ;
   }
   bool operator<=(const petite_chaine& other) const
   {
      return !(*this>other);
   }
   bool operator>=(const petite_chaine& other) const
   {
      return !(*this < other);
   }

   friend ostream& operator<<(ostream& os, const petite_chaine& pc)
   {
      ostream_iterator<char> os_it(os);
      copy(pc.m_chaine, pc.m_chaine + pc.size(), os_it);
      return os;
   }

   friend istream& operator>>(istream& is, petite_chaine& pc)
   {
      string str;
      is >> str;
      pc = petite_chaine(str.substr(0,min(255,static_cast<int>(str.size()))));
      return is;
   }


};
static_assert(sizeof(petite_chaine) == 256, "Wrong size");
