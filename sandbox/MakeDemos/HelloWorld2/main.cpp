/*
 * main.cpp
 *
 *  Created on: Jan 25, 2017
 *      Author: ashrestha
 */
#include <iostream>

using namespace std;

void DemoFunction()
{
    // Say HelloWorld five times
    for (int index = 0; index < 5; ++index)
      cout << "HelloWorld!" << endl;
    char input = 'i';
    cout << "To exit, press 'm' then the 'Enter' key." << endl;
    cin  >> input;
    while(input != 'm') {
        cout << "You just entered '" << input << "'. "
             << "You need to enter 'm' to exit." << endl;
        cin  >> input;
    }
    cout << "Thank you. Exiting." << endl;
}

int main () {

	cout << "Hello from Eclipse !!!!!" << endl;
	cout << "Test hello...\n";

    return 0;
}




