/*
Name: Joselin Lybrand
Class: CS 110C Data Structures & Algorithms
Assignment: M02: Programming Problem
*/

using namespace std;

/**
  @param int k : refers to the index+1 that we are looking for.
  @param int anArray[] : the array we are searching.
  @param first : the start of the array.
  @param last : the end of the array.
  @post the k-1 index of the array is sorted, with all values greater than the value
    of index k-1 to the right and all values less than the value of index k-1 to the left.
    The array might be more sorted, up to being completely sorted.
  @return the value of the sorted k-1 index.
*/
int kSmall(int k, int anArray[], int first, int last)
{

  //if we are looking in a partition
  if(first >= 0 && last >= 0) {
    int f = 0;
    int l = 0;
    int p = 0;

    //if this is the first pass of this partition, slightly different logic
    if(k > 0) {

      //iterating first until we find a value bigger then our pivot,
      //or we reach the end of the array.
      //Using f instead of first so we remember the beggining of the array.
      if(anArray[first+1] <= anArray[first]) {
        //changing first to a negative number so the function knows to iterate.
        f = kSmall(first, anArray, ((first+1)*-1)-1, last);
      }
      else {
        f = first+1;
      }

      //iterating last until we find a value smaller then our pivot,
      //or we reach the beggining of the array.
      //Using l instead of last so we remember the end of the array.
      if(anArray[last] >= anArray[first]) {
        //changing last to a negative number so the function knows to iterate
        l = kSmall(first, anArray, first, (last*-1)-1);
      }
      else {
        l = last;
      }
    }//if(k > 0)

    //in subsuqent iterations of a partition, k is set to a negative number
    //that corrosponds to the number we are pivoting
    //so whenever we compare to our value we have change k back to positive
    else {
      //iterate first
      if(anArray[first] <= anArray[(k+1)*-1]) {
        f = kSmall((k+1)*-1, anArray, (first*-1)-1, last);
      }
      else {
        f = first;
      }

      //iterate last
      if(anArray[last] >= anArray[(k+1)*-1]) {
        l = kSmall((k+1)*-1, anArray, first, (last*-1)-1);
      }
      else {
        l = last;
      }
    }//else



    //if first and last are not the same yet we swap those index's values
    //and call a subpartition
    if(f < l) {
      int temp = anArray[f];
      anArray[f] = anArray[l];
      anArray[l] = temp;

      //we set k to a negative number that corrosponds to out pivot value,
      //the first number of this partition.
      if(k > 0) {
        //create subpartition
        p = kSmall((first*-1)-1, anArray, f, l);
      }//if(k > 0)
      //because k is already the encoded negative number, we can just pass it as is.
      else {
        //create subpartition
        return p = kSmall(k, anArray, f, l);
      }//else
    }//if(f < l)

    //set pivot position
    else
      if(k > 0) {
        p = l;
      }
      else {
        return l;
      }


    //insert our pivot value into the corrosponding index
    int temp = anArray[p];
    anArray[p] = anArray[first];
    anArray[first] = temp;

    //if our pivot position is equal to the position we are looking for we are done!
    if(p == k-1)
      return anArray[p];
    //if it's after then we know we need to look at smaller numbers
    else if(p > k-1)
      return kSmall(k, anArray, first, p-1);
    //if it's before then we know we need to look at larger numbers
    else
      return kSmall(k, anArray, p+1, last);

  }//if(first >= 0 && last >= 0)



  //iterating first
  else if(first < 0) {
    if(anArray[(first+1)*-1] <= anArray[k] && (first+1)*-1 < last) {
      return kSmall(k, anArray, first-1, last);
    }//if(anArray[(first+1)*-1] <= anArray[k] && (first+1)*-1 <= last)
    return (first+1)*-1;
  }//else if(first < 0)

  //iterating last
  else {
    if(anArray[(last+1)*-1] >= anArray[k] && (last+1)*-1 > first) {
      return kSmall(k, anArray, first, last+1);
    }//if(anArray[(first+1)*-1] <= anArray[k] && (first+1)*-1 <= last)
    return (last+1)*-1;
  }//else

}// kSmall(int k, int anArray[], int first, int last)
