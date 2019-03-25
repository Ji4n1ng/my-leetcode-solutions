#include <string>
#include <iostream>
#include <vector>

using namespace std;

string simplifyPath(string path) {
//    string p1;
//    // remove useless slash
//    for (int i = 0; i < path.length(); i++) {
//        if (path[i] == '/') {
//
//        } else {
//
//        }
//    }


    vector<string> paths;

    for (int i = 0; i < path.length(); i++) {
        string p;
        bool firstSlash = false;
        bool hasPathName = false;
//        bool first
        int j = i;
        while (true) {
            if (!firstSlash && path[j] == '/') {
                firstSlash = true;
                p.push_back(path[j++]);
            } else if (firstSlash && path[j] == '/' && !hasPathName) {
                j++;
            } else if (firstSlash && path[j] == '/' && hasPathName) {
                i = j;
                break;
            } else if (path[j] == '.') {
                if (j+1 < path.length() && path[j+1] == '.') {
                    p.push_back(path[j++]);
                    p.push_back(path[j++]);
                    i = j;
                    break;
                }
            }
        }
    }
}

void judge(string input, string output) {
    string r = simplifyPath(input);
    if (r == output) {
        cout << "√  " << input << "\t\"" << r << "\"" << endl;
    } else {
        cout << "X  " << input << "\t\"" << r << "\" (" << output << ")" << endl;
    }
}

int main() {
//    judge("", "");
    judge("/home/", "/home");
    judge("/../", "/");
    judge("/home//foo/", "/home/foo");
    judge("/a/./b/../../c/", "/c");
    judge("/a/../../b/../c//.//", "/c");
    judge("/a//b////c/d//././/..", "/a/b/c");
}