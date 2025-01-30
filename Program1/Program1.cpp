#include "Program1.h"
#include "../Library/Library.h"

using namespace std;

int main()
{
    StringTools strTools;
    string str = "234732";
    strTools.sortAndReplace(str);
    cout << str << endl;

    cout << strTools.calculateSum("1sdf2jbjh3llh4hy5bh67bh8kj9bh0") << endl;

    cout << strTools.analyzeString("s") << endl;
    cout << strTools.analyzeString("s1") << endl;
    cout << strTools.analyzeString("s1sdffvsddvsdvvsdvsdsdvsdvsdd") << endl;
    cout << strTools.analyzeString("s1sdffvsddvsdvvsdvsdsdvsdvsddsdfsfdfsdfsdfsdfsfsdfsdfsdfsggsfdgd") << endl;
    cout << strTools.analyzeString("s1sdffvsddvsdvvsdvsdsdvsdvsddsdfsdffsdfsdfsdfsfsdfsdfsdfsggsfdgdd") << endl;
    cout << strTools.analyzeString("s1sdffvsddvsdvvsdvsdsdvsdvsddsdfsfdfsdfsdfsdfsfsdfsdfsdfsggsfdd") << endl;
    cout << strTools.analyzeString("s1sdffvsddvsdvvsdvsdsdvsdvsddsdf") << endl;
}