#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <functional> 

using namespace std;

string ltrim(const string&);
string rtrim(const string&);
vector<string> split(const string&);

/*
 * Complete the 'queensAttack' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER k
 *  3. INTEGER r_q
 *  4. INTEGER c_q
 *  5. 2D_INTEGER_ARRAY obstacles
 */

int getCount(int n, int row, int col, int dir, vector<vector<int>> obstacles)
{
    if (row <= 0 || row > n || col <= 0 || col > n) {
        return 0;
    }
    for (size_t i = 0; i < obstacles.size(); i++) {
        if (obstacles[i][0] == row && obstacles[i][1] == col) {
            return 0;
        }
    }
    int count = 0;

    if (dir == 0)
        count += getCount(n, row - 1, col, dir, obstacles);
    else if (dir == 1)
        count += getCount(n, row - 1, col + 1, dir, obstacles);
    else if (dir == 2)
        count += getCount(n, row, col + 1, dir, obstacles);
    else if (dir == 3)
        count += getCount(n, row + 1, col + 1, dir, obstacles);
    else if (dir == 4)
        count += getCount(n, row + 1, col, dir, obstacles);
    else if (dir == 5)
        count += getCount(n, row + 1, col - 1, dir, obstacles);
    else if (dir == 6)
        count += getCount(n, row, col - 1, dir, obstacles);
    else if (dir == 7)
        count += getCount(n, row - 1, col - 1, dir, obstacles);

    cout << count << endl;
    return count + 1;
}

int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>> obstacles) {
    /*cout << obstacles.size() << endl;
    for(size_t i = 0; i < obstacles.size(); i++){
        cout << obstacles[i][0] << " " << obstacles[i][1] << endl;
    }*/

    // This is the recursive approach and there can be another solution
    // 0: up, 1: up right, 2: right, 3: down right
    // 4: down, 5: down left, 6: left, 7: up left
    /* int count = 0;
    count += getCount(n, r_q-1, c_q,    0, obstacles);
    count += getCount(n, r_q-1, c_q+1,  1, obstacles);
    count += getCount(n, r_q,   c_q+1,  2, obstacles);
    count += getCount(n, r_q+1, c_q+1,  3, obstacles);
    count += getCount(n, r_q+1, c_q,    4, obstacles);
    count += getCount(n, r_q+1, c_q-1,  5, obstacles);
    count += getCount(n, r_q,   c_q-1,  6, obstacles);
    count += getCount(n, r_q-1, c_q-1,  7, obstacles);
    return count;*/

    // variables to hold the distance between queen and obstacles
    int up = 0,
        up_right = 0,
        right = 0,
        down_right = 0,
        down = 0,
        down_left = 0,
        left = 0,
        up_left = 0;

    // first is the distance between queen and borders
    up = r_q - 1;
    down = n - r_q;
    right = n - c_q;
    left = c_q - 1;
    up_left = min(c_q - 1, r_q - 1);
    up_right = min(n - c_q, r_q - 1);
    down_left = min(c_q - 1, n - r_q);
    down_right = min(n - r_q, n - c_q);

    // Loop over the obstacles
    for (size_t i = 0; i < obstacles.size(); i++) {
        // cout << obstacles[i][0] << " " << obstacles[i][1] << endl;
        // same row left
        if (obstacles[i][0] == r_q && obstacles[i][1] < c_q)
            left = min(left, c_q - obstacles[i][1] - 1);
        // same row right
        else if (obstacles[i][0] == r_q && obstacles[i][1] > c_q)
            right = min(right, obstacles[i][1] - c_q - 1);
        // same col up
        else if (obstacles[i][0] < r_q && obstacles[i][1] == c_q)
            up = min(up, r_q - obstacles[i][0] - 1);
        // same col down
        else if (obstacles[i][0] > r_q && obstacles[i][1] == c_q)
            down = min(down, obstacles[i][0] - r_q - 1);
        // same diag up left
        else if (obstacles[i][0] < r_q && obstacles[i][1] < c_q
            && r_q - obstacles[i][0] == c_q - obstacles[i][0])
            up_left = min(up_left, r_q - obstacles[i][0] - 1);
        // same diag up right
        else if (obstacles[i][0] < r_q && obstacles[i][1] > c_q
            && r_q - obstacles[i][0] == -c_q + obstacles[i][0])
            up_right = min(up_right, r_q - obstacles[i][0] - 1);
        // same diag down left
        else if (obstacles[i][0] > r_q && obstacles[i][1] < c_q
            && -r_q + obstacles[i][0] == c_q - obstacles[i][0])
            down_left = min(down_left, -r_q + obstacles[i][0] - 1);
        // same diag down right
        else if (obstacles[i][0] > r_q && obstacles[i][1] > c_q
            && r_q - obstacles[i][0] == c_q - obstacles[i][0])
            down_right = min(down_right, -r_q + obstacles[i][0] - 1);

    }
    return up + up_right + right + down_right + down + down_left + left + up_left;

    /*int d11, d12, d21, d22, r1, r2, c1, c2;

    // Initialise the distance to end of the board.
    d11 = min( c_q-1, r_q-1 );
    d12 = min( n-c_q, n-r_q );
    d21 = min( n-c_q, r_q-1 );
    d22 = min( c_q-1, n-r_q );

    r1 = r_q-1;
    r2 = n-r_q;
    c1 = c_q-1;
    c2 = n-c_q;

    // For each obstacle find the minimum distance.
    // If obstacle is present in any direction,
    // distance will be updated.
    for (int i = 0; i < k; i++)
    {
        if ( c_q > obstacles[i][0] && r_q > obstacles[i][1] &&
                 c_q-obstacles[i][0] == r_q-obstacles[i][1] )
            d11 = min(d11, c_q-obstacles[i][0]-1);

        if ( obstacles[i][0] > c_q && obstacles[i][1] > r_q &&
                  obstacles[i][0]-c_q == obstacles[i][1]-r_q )
            d12 = min( d12, obstacles[i][0]-c_q-1);

        if ( obstacles[i][0] > c_q && r_q > obstacles[i][1] &&
                   obstacles[i][0]-c_q == r_q-obstacles[i][1] )
            d21 = min(d21, obstacles[i][0]-c_q-1);

        if ( c_q > obstacles[0][i] && obstacles[i][1] > r_q &&
                    c_q-obstacles[i][0] == obstacles[i][1]-r_q )
            d22 = min(d22, c_q-obstacles[i][0]-1);

        if ( c_q == obstacles[i][0] && obstacles[i][1] < r_q )
            r1 = min(r1, r_q-obstacles[i][1]-1);

        if ( c_q == obstacles[i][0] && obstacles[i][1] > r_q )
            r2 = min(r2, obstacles[i][1]-r_q-1);

        if ( r_q == obstacles[i][1] && obstacles[i][0] < c_q )
            c1 = min(c1, c_q-obstacles[i][0]-1);

        if ( r_q == obstacles[i][1] && obstacles[i][0] > c_q )
            c2 = min(c2, obstacles[i][0]-c_q-1);
    }

    return d11 + d12 + d21 + d22 + r1 + r2 + c1 + c2; */
}



int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int k = stoi(first_multiple_input[1]);

    string second_multiple_input_temp;
    getline(cin, second_multiple_input_temp);

    vector<string> second_multiple_input = split(rtrim(second_multiple_input_temp));

    int r_q = stoi(second_multiple_input[0]);

    int c_q = stoi(second_multiple_input[1]);

    vector<vector<int>> obstacles(k);

    for (int i = 0; i < k; i++) {
        obstacles[i].resize(2);

        string obstacles_row_temp_temp;
        getline(cin, obstacles_row_temp_temp);

        vector<string> obstacles_row_temp = split(rtrim(obstacles_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int obstacles_row_item = stoi(obstacles_row_temp[j]);

            obstacles[i][j] = obstacles_row_item;
        }
    }

    int result = queensAttack(n, k, r_q, c_q, obstacles);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string& str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string& str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string& str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
