#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <utility>
using namespace std;

void merge_pair(vector<int>& encoded, pair<int, int> to_merge, int new_token_id) {
    vector<int> new_encoded;
    for (size_t i = 0; i < encoded.size(); ) {
        if (i + 1 < encoded.size() &&
            encoded[i] == to_merge.first &&
            encoded[i + 1] == to_merge.second) {
            new_encoded.push_back(new_token_id);
            i += 2;
        } else {
            new_encoded.push_back(encoded[i]);
            i += 1;
        }
    }
    encoded = new_encoded;
}


vector<int> encode(vector<string>& tokenlist) {
    map<string, int> token_to_id;
    size_t max_token_len = 0;

    for (size_t i = 0; i < tokenlist.size(); i++) {
        token_to_id[tokenlist[i]] = i;
        if (tokenlist[i].size() > max_token_len) {
            max_token_len = tokenlist[i].size();
        }
    }

    ifstream input("training_corpus.txt");
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
    return encodedlist;
}

pair<int, int> combinetokens(const vector<int>& encoded, vector<string>& tokenlist) {
    ofstream vocab("vocab.txt", ios::app);
    map<pair<int, int>, int> pair_counts;
    pair<int, int> most_frequent = {-1, -1};
    int max_count = 0;

    for (size_t i = 0; i + 1 < encoded.size(); i++) {
        pair<int, int> token_pair = {encoded[i], encoded[i + 1]};
        pair_counts[token_pair]++;
    }

    for (const auto& entry : pair_counts) {
        if (entry.second > max_count) {
            max_count = entry.second;
            most_frequent = entry.first;
        }
    }

    string new_token = tokenlist[most_frequent.first] + tokenlist[most_frequent.second];

    for (const string& token : tokenlist) {
        if (token == new_token) {
            return {-1, -1};
        }
    }
    tokenlist.push_back(new_token);

    if (vocab.is_open()) {
        vocab << new_token << endl;
        vocab.close();
    }

    return most_frequent;
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

    for (int i = 0; i < 1000; i++) {
        vector<int> encodedlist = encode(tokenlist);

        int new_token_id = tokenlist.size();
        pair<int, int> pair = combinetokens(encodedlist, tokenlist);
        
        merge_pair(encodedlist, pair, new_token_id);
    }


    return 0;
}