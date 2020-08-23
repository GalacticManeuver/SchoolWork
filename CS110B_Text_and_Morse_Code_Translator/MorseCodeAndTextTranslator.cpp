/* Written by Joselin Lybrand for Sam Johnson's C++ Fundamentals Class */

#include <iostream>
#include <string>
using std::string;
using std::cin;
using std::cout;


class MorseText {

  public:

    MorseText() {
      //initilize the text to morse code binary data tree
      //the leftmost 1 is right before the bit we start analyzing
      morseCodeTree[1][0]  = 0 <<  4|0 << 3|1 << 2|1 << 1|0 << 0; //a
      morseCodeTree[1][1]  = 1 <<  4|0 << 3|1 << 2|1 << 1|1 << 0; //b
      morseCodeTree[1][2]  = 1 <<  4|0 << 3|1 << 2|0 << 1|1 << 0; //c
      morseCodeTree[1][3]  = 0 <<  4|1 << 3|0 << 2|1 << 1|1 << 0; //d
      morseCodeTree[1][4]  = 0 <<  4|0 << 3|0 << 2|1 << 1|1 << 0; //e
      morseCodeTree[1][5]  = 1 <<  4|1 << 3|1 << 2|0 << 1|1 << 0; //f
      morseCodeTree[1][6]  = 0 <<  4|1 << 3|0 << 2|0 << 1|1 << 0; //g
      morseCodeTree[1][7]  = 1 <<  4|1 << 3|1 << 2|1 << 1|1 << 0; //h
      morseCodeTree[1][8]  = 0 <<  4|0 << 3|1 << 2|1 << 1|1 << 0; //i
      morseCodeTree[1][9]  = 1 <<  4|1 << 3|0 << 2|0 << 1|0 << 0; //j
      morseCodeTree[1][10] = 0 <<  4|1 << 3|0 << 2|1 << 1|0 << 0; //k
      morseCodeTree[1][11] = 1 <<  4|1 << 3|0 << 2|1 << 1|1 << 0; //l
      morseCodeTree[1][12] = 0 <<  4|0 << 3|1 << 2|0 << 1|0 << 0; //m
      morseCodeTree[1][13] = 0 <<  4|0 << 3|1 << 2|0 << 1|1 << 0; //n
      morseCodeTree[1][14] = 0 <<  4|1 << 3|0 << 2|0 << 1|0 << 0; //o
      morseCodeTree[1][15] = 1 <<  4|1 << 3|0 << 2|0 << 1|1 << 0; //p
      morseCodeTree[1][16] = 1 <<  4|0 << 3|0 << 2|1 << 1|0 << 0; //q
      morseCodeTree[1][17] = 0 <<  4|1 << 3|1 << 2|0 << 1|1 << 0; //r
      morseCodeTree[1][18] = 0 <<  4|1 << 3|1 << 2|1 << 1|1 << 0; //s
      morseCodeTree[1][19] = 0 <<  4|0 << 3|0 << 2|1 << 1|0 << 0; //t
      morseCodeTree[1][20] = 0 <<  4|1 << 3|1 << 2|1 << 1|0 << 0; //u
      morseCodeTree[1][21] = 1 <<  4|1 << 3|1 << 2|1 << 1|0 << 0; //v
      morseCodeTree[1][22] = 0 <<  4|1 << 3|1 << 2|0 << 1|0 << 0; //w
      morseCodeTree[1][23] = 1 <<  4|0 << 3|1 << 2|1 << 1|0 << 0; //x
      morseCodeTree[1][24] = 1 <<  4|0 << 3|1 << 2|0 << 1|0 << 0; //y
      morseCodeTree[1][25] = 1 <<  4|0 << 3|0 << 2|1 << 1|1 << 0; //z
      morseCodeTree[1][26] = 0 <<  4|0 << 3|0 << 2|0 << 1|0 << 0; //error
    }//Constructor

    string MTinput(string str) {
      output.erase(output.begin(), output.end());
      if(str[0] == '-' || str[0] == '.') { morseCodeToText(str);
	  }//if 
      else  { textToMorseCode(str);
	  }//else
      return output;
    }//MTinput

    string translate() {
      return output;
    }//translate

    void textToMorseCode(string str) {
	  i = 0, k = 0;
      length = str.length();
      for(i = 0; i < length; ++i) {

        //resetting the startcounting, location, and binary
        startCounting = false;
        location = 32;
        binary = morseCodeTree[1][26];

        //if the input is a lowercase or uppercase character, go to it's spot in the array,
        //and set binary equal to corrosponding value. otherwise output ? for invalid inputs.
        if(str[i] >= 65 && str[i] <= 90) binary = morseCodeTree[1][str[i]-65];
        else if(str[i] >= 97 && str[i] <= 122) binary = morseCodeTree[1][str[i]-97];
        else {
          binary = morseCodeTree[1][26];
        }

        //iterates through the relevent parts of the binary
        for(k = 3; k < 8; k++) {

          location /= 2; //reducing location so that we check different parts of the binary

          //if we are counting, 0 = . 1 = -
          if(startCounting) {
            if(binary >= location) output += '.';
            else  output += '-';
          }//if


          //once the first 1 in the binary is found, change startcounting to true, this first 1 will never output a -
          if(binary >= location) {
            startCounting = true;
            //iterating down binary only after we start counting so that we
            //don't subtract 32 from say: e, that is only 2 (00000010)
            binary -= location;
          }//if
        }//for
	  output += ' '; //space between letters
	  }//for
    }//morseCodeToText

    void morseCodeToText(string str) {

      i = 0, location = 0; //iterators
      length = str.length();
      //going through the entire string
      for(i = 0; i < length; i++) {
        //if a . is found, progress "left"
        if(str[i] == '.') location = (location*2)+1;
        //if a - is found, progress "right"
        else if(str[i] == '-') location = (location*2)+2;
        //if input invalid, set location to invalid
        else if(str[i] != ' ') { location = 31; }
        if(str[i] == ' ' || i == length-1) { //if a space is found, or last letter
          //outputs the character corrosponding to the location in the moseCodeTree,
          //which also corrosponded to the sequence of .s and -s we got in user input.
          if(location < 31) { output += morseCodeTree[0][location];
		  }
          //if the user inputs to long a chain of .---- then output ? to indicate error.
          else { output +='?';
		  }
          //resets location to 0 for another pass
          location = 0;
        }//if
      }//for

      //setting outputs size to be exactly as big as we need
    }//textToMorseCode

  private:

    //initilize the morse code to text binary data tree
    unsigned char morseCodeTree[2][31] = {{' ', 'E', 'T', 'I', 'A', 'N', 'M', 'S', 'U', 'R', 'W', 'D', 'K', 'G', 'O', 'H', 'V', 'F', '?', 'L', '?', 'P', 'J', 'B', 'X', 'C', 'Y', 'Z', 'Q', '?', '?'},{}};

    string output;
	int i,k,location,length;
	bool startCounting;
	unsigned char binary;

};//MorseText



int main() {

  string morse = ".... . .-.. .-.. ---  .-- --- .-. .-.. -..";
  string text = "Hello World";
  MorseText obj;
  cout << obj.MTinput(morse) << '\n';
  cout << obj.MTinput(text) << '\n';
  morse = "- . ... - .. -. --.  - . ... - .. -. --.";
  cout << obj.MTinput(morse) << '\n';
  cout << obj.MTinput(morse) << '\n';
  text = "Testing Testing";
  cout << obj.MTinput(text) << '\n';
  cout << obj.MTinput(text) << '\n';
}//main

