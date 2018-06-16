#include <iostream>
#include <iterator>
#include <quick.h>


int * Partition(  int * left, int * right)
  {
      int const siz = std::distance(left, right);
      int * pivot = left+(siz / 2);
      std::swap(*pivot, *(right-1));
      int * j=left;
      for (int * i=left; i<(right-1);i++)
      {
          if (*i<*(right-1))
          {
              std::swap(*i,*j);
              j++;
          }
      }
      std::swap(*j,*(right-1));
      return j;
  }

void quick_sort( int * begi, int * en )
{
     int const siz = std::distance(begi, en);
     if (siz>0)
     {
     int * g=Partition( begi, en);
     quick_sort( begi, g );
     quick_sort( g+1, en );
     }

}

