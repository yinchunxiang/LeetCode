#include <iostream>
#include <vector>

using namespace std;


string simplifyPath(string path) {
    if (path.empty()) {
        return "/";
    }

    vector<string> dirs;

    path.append("/");
    int n = path.size();
    int start = 0;
    for (int i = 0; i < n + 1; ++i) {
        if ('/' == path[i]) {
            string dir = path.substr(start, i - start);
            start = i + 1;
            if (dir.empty() || dir == ".") {
                continue;
            }
            if (dir == "..") {
                if (!dirs.empty()){
                    dirs.pop_back();
                }
            }
            else {
                dirs.push_back(dir);
            }
        }
    }

    string ret;
    for (int i = 0; i < dirs.size(); ++i){
        ret += "/";
        ret += dirs[i];
    }

    if (ret.empty()) {
        ret = "/";
    }
    return ret;
}

int main(int argc, const char *argv[])
{
    cout << simplifyPath("/a/./b/../../c/") << endl;
    cout << simplifyPath("/home/") << endl;
    cout << simplifyPath("/../") << endl;
    cout << simplifyPath("/home//foo/") << endl;
    cout << simplifyPath("/...") << endl;
    return 0;
}
