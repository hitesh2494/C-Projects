//
//  students.cpp
//  Pi Recipes
//
//  Created by Hitesh Bhatia on 3/6/21.
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

const string INPUT_FILE_NAME = "students.txt";

/**
 * Main.
 */
int main()
{
    ifstream input;
    input.open(INPUT_FILE_NAME);
    if(input.fail())
    {
        cout << "Failed to open " << INPUT_FILE_NAME << endl;
        return -1;
    }

    /***** Complete this program. *****/
}
