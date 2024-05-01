
#include "misc.h"
#include <string>
using namespace std;

void printMe(string type){
    if (type == "banner"){
        char banner[] = \
"   ######## ########   #######        ##    ###    ##    ##         ########   #######   #######  ##    ## \n \
     ##    ##     ## ##     ##       ##   ## ##   ###   ##         ##     ## ##     ## ##     ## ##   ## \n \
     ##    ##     ## ##     ##       ##  ##   ##  ####  ##         ##     ## ##     ## ##     ## ##  ## \n \
     ##    ########  ##     ##       ## ##     ## ## ## ## ####### ########  ##     ## ##     ## ##### \n \
     ##    ##   ##   ##     ## ##    ## ######### ##  ####         ##     ## ##     ## ##     ## ##  ## \n \
     ##    ##    ##  ##     ## ##    ## ##     ## ##   ###         ##     ## ##     ## ##     ## ##   ## \n \
     ##    ##     ##  #######   ######  ##     ## ##    ##         ########   #######   #######  ##    ##\n";
        cout << endl << banner << endl << endl;
    }
}

string codeName(string str1, string str2) {  // concat str1 and str2, remove spaces, make all letters lower case
	string code = "";
	
	for(int i=0;i<str1.length();i++) {
		if(str1[i] != ' ') {
			code = code + (char)tolower(str1[i]);
		}
	}
	for(int i=0;i<str2.length();i++) {
		if(str2[i] != ' ') {
			code = code + (char)tolower(str2[i]);
		}
	}
	return code;

}

