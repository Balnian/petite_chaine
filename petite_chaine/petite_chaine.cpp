#include "petite_chaine.h"
#include <algorithm>

using namespace std;

petite_chaine::petite_chaine(const char * chaine)
{
   unsigned int size = 0;
   for (; size<=255?*(chaine + size) != 0:throw size_exception(); ++size);

   copy(chaine, chaine+size, begin(m_chaine));
   m_chaine[s_getSize] = size;
}

petite_chaine::petite_chaine(const std::string& chaine)
{
   if (chaine.size() > 255)
      throw size_exception();

   copy(begin(chaine), end(chaine), begin(m_chaine));
   m_chaine[s_getSize] = chaine.size();
}

petite_chaine::petite_chaine(const petite_chaine & other)
{
   *this = other;
}


petite_chaine::~petite_chaine()
{
}
