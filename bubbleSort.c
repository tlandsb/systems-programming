/*-------------------------------------------------------------------------*
 *------*
 *---bubbleSort.c---*
 *------*
 *---    This file defines a function that implements the bubble----*
 *---sort algorithm.---*
 *------*
 *--------------------------------------*
 *------*
 *---Version 1aJoseph Phillips---*
 *------*
 *-------------------------------------------------------------------------*/

#include "header.h"

//  PURPOSE:  To sort the 'arrayLen' strings in array 'array' with the
//bubble-sort algorithm.  No return value.
void bubbleSort(char**array,
	       int arrayLen
	       )
{
  int i;
  int haveExchanged;

  do
    {
      haveExchanged= 0;

      for  (i = 0;  i < arrayLen-1;  i++)
	if  ( strncmp(array[i],array[i+1],strLen) > 0 )
	  {
	    swap(array,i,i+1);
	    haveExchanged= 1;
	  }
    }
  while  (haveExchanged);

}
