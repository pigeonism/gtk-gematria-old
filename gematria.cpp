#include "gematria.h"
#include <string>
#include <iostream>
// Gematria.cpp : Defines the entry point for the console application.
// eng method, multiples of 6, a-6, b-12 etc (444, 666, 888, 1110 ) are of note apparently
// ctd... 444 to do with ruling, 666 to do with man, beastly and lies test: 'computer'

using namespace std;

gematria::gematria()
{
    //ctor
    //! added, so index is an ordinal value
    alpha = "!abcdefghijklmnopqrstuvwxyz";
    total = 0;
    // 'ordinal ' shorten down to 1 digit, 'english'  use multiples of 6 but dont shorten to 1 digit
    useMethod = "english"; // default
}

int gematria::check_alpha(char letter, string method){

    // if method is eng, return i * 6
	int j = alpha.length(); //alphabet string
	int i;

	for (i = 1; i < j; i++) {
		if (letter == alpha.at(i))
		{

			//std::cout << letter << i<< endl;
			//total += i;
			if (method == "ordinal"){
                return i;
			}
			if (method == "english"){
                return i * 6;
			}

		}
	}

	return 0;

}

// shorten a total further by seperating a number into parts (str) and adding them from int conversions
void gematria::testShorten(){

    string s = to_string(total);
    //cout << "total: (testShorten) " << total << " str: " << s << " len str: " << s.length() << endl;

    int testTotal = 0;

    for(int x = 0; x < s.length(); x++ ){
        //cout << " element: " << x << " substr: " << s.substr(x,1) << endl;
        testTotal += std::stoi( s.substr(x,1) );
    }

    //cout << "testTotal: (testShorten addition)" << testTotal << endl;
    total = testTotal;

}

void gematria::numerate(string msg){
    int j = msg.length();
	int i;

	for (i = 0; i < j; i++) {

		total += check_alpha( msg.at(i) , useMethod);
		//std::cout <<msg.at(i);
	}
    //std::cout << "total: (inital addition)" <<  total << endl;

	// shorten if possible or if appropriate
	if(useMethod != "english"){
        while (total > 9){
            testShorten();
        }
    }
    //cout << endl;
    //cout << "The numerical value of the word " + msg + " reduced is: " << total;
    numeratedText = to_string(total);
}

void gematria::setMethod(string method){
    // add checks incase, but a radio btton will use this method later
    useMethod = method;
}

string gematria::getResult(){
    return numeratedText;
}

gematria::~gematria()
{
    //dtor
}
