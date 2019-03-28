#include <string>
#include <iostream>
#include <vector>

using namespace std;

string simplifyPath(string path) {
	vector<string> paths;

	// transform path to a format vector<string> paths.
	// e.g. /a/../../b/../c//.//  ==>  [/a, /.., /.., /b, /.., /c, /.]
	for (int i = 0; i < path.length(); i++) {
		string p;
		bool firstSlash = false;
		bool hasPathName = false;
		int j = i;
		while (j < path.length()) {
			if (!firstSlash && path[j] == '/') {
				firstSlash = true;
				p.push_back(path[j++]);
			} else if (firstSlash && path[j] == '/' && !hasPathName) {
				j++;
			} else if (firstSlash && path[j] == '/' && hasPathName) {
				i = j - 1;
				break;
			} else {
				hasPathName = true;
				p.push_back(path[j++]);
				i = j;
			}
		}
		if(p != "/")
			paths.push_back(p);
	}

	vector<string> results;
	for (auto p: paths) {
		if (p == "/..") {
			if (results.size() > 0)
				results.pop_back();
		} else if (p == "/.") {
			// do nothing
		} else {
			results.push_back(p);
		}
	}

	if (results.size() == 0)
		return "/";


	string result = "";
	for (auto r: results) {
		result += r;
	}
	return result;
}

void judge(string input, string output) {
	string r = simplifyPath(input);
	if (r == output) {
		cout << "T  " << input << "  \"" << r << "\"" << endl;
	} else {
		cout << "X  " << input << "  \"" << r << "\" (" << output << ")" << endl;
	}
}

int main() {
	judge("/home/", "/home");
	judge("/../", "/");
	judge("/home//foo/", "/home/foo");
	judge("/a/./b/../../c/", "/c");
	judge("/a/../../b/../c//.//", "/c");
	judge("/a//b////c/d//././/..", "/a/b/c");
	judge("/...", "/..."); // WTF???
	judge("/..hidden", "/..hidden"); // WTF???

}
