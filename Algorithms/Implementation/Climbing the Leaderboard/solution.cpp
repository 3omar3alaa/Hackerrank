#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the climbingLeaderboard function below.
vector<int> climbingLeaderboard(vector<int> scores, vector<int> alice) {
    int rank = 1;
    int AliceCurrentIndex = scores.size() - 1;
    vector<int> result(alice.size());
    vector<int> ranks(scores.size());
    for(int i = 0 ; i < alice.size(); i++){
        result[i] = 1;
    }

    
    /*for(int j = 0; j < alice.size(); j++){
        if((alice[j] < alice[j-1] && j != 0) || j == 0){
            // Traversing Downwards
            cout << "Traversing Downwards" << endl;
            for(int i = AliceCurrentIndex; i < scores.size(); i++){
                if(i > 0 && scores[i] < scores[i - 1]){
                    rank++;
                    cout << "Rank: " << rank << endl;
                }
                cout << "i: " << i << endl << "j: " << j << endl;
                if(alice[j] >= scores[i]){
                    //scores.insert(scores.begin() + i, alice[j]);
                    result[j] = rank;
                    AliceCurrentIndex = i;
                    //inserted = true;
                    cout << "=============================" << endl;
                    //cout << "Inserted in NOT start" << endl;
                    cout << "Rank: " << rank << endl; 
                    cout << "Alice Score: " << alice[j] << endl;
                    cout << "AliceCurrentIndex: " << AliceCurrentIndex << endl; 
                    cout << "result of " << j << " is " << result[j] << endl;
                    cout << "=============================" << endl;
                    break;
                }
                if(i == scores.size() - 1){
                    // Score is definetly less than last item in scores array
                    //scores.insert(scores.end(), alice[j]);
                    //rank++;
                    result[j] = rank + 1;
                    AliceCurrentIndex = i;
                    cout << "=============================" << endl;
                    //cout << "Inserted in NOT start" << endl;
                    cout << "Rank: " << rank << endl; 
                    cout << "Alice Score: " << alice[j] << endl;
                    cout << "AliceCurrentIndex: " << AliceCurrentIndex << endl; 
                    cout << "result of " << j << " is " << result[j] << endl;
                    cout << "=============================" << endl;
                    //break;
                }
            }   
        }
        else if(alice[j] >= alice[j-1] && j != 0){
            // Traversing Upwards
            cout << "Traversing Upwards" << endl;
            for(int i = AliceCurrentIndex - 1; i >= 0; i--){
                if(i < scores.size()-1 && scores[i] > scores[i + 1]){
                    rank--;
                    cout << "Rank: " << rank << endl;
                }
                cout << "i: " << i << endl << "j: " << j << endl;
                if(alice[j] < scores[i]){
                    result[j] = rank + 1;
                    AliceCurrentIndex = i;
                    cout << "=============================" << endl;
                    cout << "Rank: " << rank << endl; 
                    cout << "Alice Score: " << alice[j] << endl;
                    cout << "AliceCurrentIndex: " << AliceCurrentIndex << endl; 
                    cout << "result of " << j << " is " << result[j] << endl;
                    cout << "=============================" << endl;
                    break;
                }
                else if(alice[j] == scores[i]){
                    result[j] = rank;
                    AliceCurrentIndex = i;
                    cout << "=============================" << endl;
                    //cout << "Inserted in NOT start" << endl;
                    cout << "Rank: " << rank << endl; 
                    cout << "Alice Score: " << alice[j] << endl;
                    cout << "AliceCurrentIndex: " << AliceCurrentIndex << endl; 
                    cout << "result of " << j << " is " << result[j] << endl;
                    cout << "=============================" << endl;
                    break;
                }
                else if(i == 0 && alice[j] > scores[i]){
                    //rank--;
                    result[j] = 1;
                    //rank++;
                    AliceCurrentIndex = 0;
                    cout << "=============================" << endl;
                    cout << "Rank: " << rank << endl; 
                    cout << "Alice Score: " << alice[j] << endl;
                    cout << "AliceCurrentIndex: " << AliceCurrentIndex << endl; 
                    cout << "result of " << j << " is " << result[j] << endl;
                    cout << "=============================" << endl;
                    break;
                }

            }   
        }
    }*/

    // Alice scores are in ascending order

    // One time down traversal to find the end rank
     
    for(int i = 0; i < scores.size(); i++){
        if(scores[i] < scores[i - 1] && i != 0){
            rank++;
            //cout << "Rank: " << rank << endl;
        }
        ranks[i] = rank;
    }
    cout << "Ending Rank: " << rank << endl;
    bool inserted = false;
    for(int i = 0; i < alice.size(); i++){
        inserted = false;
        for(int j = AliceCurrentIndex; j >= 0; j--){
            /*if(j < scores.size()-1 && scores[j] > scores[j + 1]){
                    rank--;
                    cout << "Rank: " << rank << endl;
            }*/
            if(alice[i] < scores[j]){
                result[i] = ranks[j] + 1;
                AliceCurrentIndex = j;
                inserted = true;
            }
            else if(alice[i] == scores[j]){
                result[i] = ranks[j];
                AliceCurrentIndex = j;   
                inserted = true;
            }
            else if(j == 0 && alice[i] > scores[j]){
                result[i] = 1;
                AliceCurrentIndex = 1;
                inserted = true;
            }

            if(inserted){
                cout << "=============================" << endl;
                cout << "Rank: " << rank << endl; 
                cout << "Alice Score: " << alice[i] << endl;
                cout << "AliceCurrentIndex: " << AliceCurrentIndex << endl; 
                cout << "result of " << i << " is " << result[i] << endl;
                cout << "=============================" << endl;
                break;
            }
        }

    }
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int scores_count;
    cin >> scores_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string scores_temp_temp;
    getline(cin, scores_temp_temp);

    vector<string> scores_temp = split_string(scores_temp_temp);

    vector<int> scores(scores_count);

    for (int i = 0; i < scores_count; i++) {
        int scores_item = stoi(scores_temp[i]);

        scores[i] = scores_item;
    }

    int alice_count;
    cin >> alice_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string alice_temp_temp;
    getline(cin, alice_temp_temp);

    vector<string> alice_temp = split_string(alice_temp_temp);

    vector<int> alice(alice_count);

    for (int i = 0; i < alice_count; i++) {
        int alice_item = stoi(alice_temp[i]);

        alice[i] = alice_item;
    }

    vector<int> result = climbingLeaderboard(scores, alice);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
