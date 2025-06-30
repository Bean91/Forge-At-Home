#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <utility>
using namespace std;

int encode(vector<string>& tokenlist) {
    map<string, int> token_to_id;
    size_t max_token_len = 0;

    for (size_t i = 0; i < tokenlist.size(); i++) {
        token_to_id[tokenlist[i]] = i;
        if (tokenlist[i].size() > max_token_len) {
            max_token_len = tokenlist[i].size();
        }
    }

    ifstream input("input.txt");
    string line;
    vector<int> encodedlist;

    if (input.is_open()) {
        while (getline(input, line)) {
            size_t i = 0;
            while (i < line.size()) {
                string match = "";
                int match_id = -1;

                size_t try_max = min(max_token_len, line.size() - i);
                for (size_t len = try_max; len >= 1; --len) {
                    string sub = line.substr(i, len);
                    if (token_to_id.count(sub)) {
                        match = sub;
                        match_id = token_to_id[sub];
                        break;
                    }
                }

                if (match_id != -1) {
                    encodedlist.push_back(match_id);
                    i += match.size();
                } else {
                    cerr << "Unknown token starting at: " << line[i] << i << line << endl;
                    i += 1;
                }
            }
        }
        input.close();
    }

    ofstream output("output.txt");
    for (int j = 0; j < encodedlist.size(); j++) {
        output << encodedlist[j] << endl;;
    }

    return 0;
}

int decode(vector<string>& tokenlist) {
    // map<int, string> id_to_token;

    // ifstream input("input.txt");
    // string line;
    // vector<string> decodedlist;

    // if (input.is_open()) {
    //     while (getline(input, line)) {
    //         size_t i = 0;
    //         while (i < line.size()) {
    //             string match = "";
    //             int match_id = -1;

    //             size_t try_max = min(max_token_len, line.size() - i);
    //             for (size_t len = try_max; len >= 1; --len) {
    //                 string sub = line.substr(i, len);
    //                 if (token_to_id.count(sub)) {
    //                     match = sub;
    //                     match_id = token_to_id[sub];
    //                     break;
    //                 }
    //             }

    //             if (match_id != -1) {
    //                 encodedlist.push_back(match_id);
    //                 i += match.size();
    //             } else {
    //                 cerr << "Unknown token starting at: " << line[i] << i << line << endl;
    //                 i += 1;
    //             }
    //         }
    //     }
    //     input.close();
    // }

    // ofstream output("output.txt");
    // for (int j = 0; j < encodedlist.size(); j++) {
    //     output << encodedlist[j];
    // }

    return 0;
}

int main() {
    ifstream inFile("vocab.txt");
    string line;
    vector<string> tokenlist;

    if (inFile.is_open()) {
        while (getline(inFile, line)) {
            tokenlist.push_back(line);
        }
        inFile.close();
    }

    cout << "Please have file to de/encode called 'input.txt'\n(E)ncode or (D)ecode?" << endl;
    string choice;
    cin >> choice;
    if (choice == "E" || choice == "e") {
        cout << "Generating output.txt..." << endl;
        encode(tokenlist);
    } else if (choice == "D" || choice == "d") {
        cout << "Generating output.txt..." << endl;
        decode(tokenlist);
    } else {
        cout << "Please have file to de/encode called 'input.txt'\n(E)ncode or (D)ecode?" << endl;
        cin >> choice;
    }

    return 0;
}