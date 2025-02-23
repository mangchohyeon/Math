#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// 문자열에서 소수점 이하의 불필요한 trailing zero들을 제거하는 함수입니다.
string RemoveZero(const string& numStr) {
    string result = numStr;
    // 소수점이 있는 경우에만 처리합니다.
    if (result.find('.') != string::npos) {
        // 문자열 끝에서부터 0을 제거합니다.
        while (!result.empty() && result.back() == '0') {
            result.pop_back();
        }
        // 만약 마지막 문자가 소수점('.')이라면 제거합니다. (예: "123." -> "123")
        if (!result.empty() && result.back() == '.') {
            result.pop_back();
        }
    }
    return result;
}

int main() {
    ifstream infile1("pi_value.txt");
    if (!infile1) {
        cerr << "Can't open pi_value.txt(infile)\n";
        return -1;
    }
    
    string line, res1("");
    while (getline(infile1, line)) {
        // 만약 줄에 "pi :"가 포함되어 있다면 숫자 부분을 찾아 처리합니다.
        size_t pos = line.find("pi :");
        if (pos != string::npos) {
            // "pi :" 이후의 숫자 부분을 추출합니다. (여기서 5는 "pi :" 다음의 공백까지 포함한 길이입니다.)
            string number = line.substr(pos + 5);
            string trimmedNumber = RemoveZero(number);
            // "pi :"와 수정된 숫자 문자열을 결과 파일에 씁니다.
            res1.append("pi : " + trimmedNumber + "\n");
        } else {
            // 그 외의 라인은 그대로 출력합니다.
            res1.append(line + "\n");
        }
    }
    
    infile1.close();

    ofstream outfile1("pi_value.txt");
    if (!outfile1) {
        cerr << "Can't open pi_value.txt.(outfile)\n";
        return -1;
    }

    outfile1 << res1;

    outfile1.close();

    ifstream infile2("pi_value_last.txt");
    if (!infile2) {
        cerr << "Can't open pi_value_last.txt(infile)\n";
        return -1;
    }

    getline(infile2, line);
    string res2 = RemoveZero(line);

    infile2.close();

    ofstream outfile2("pi_value_last.txt");
    if (!outfile2) {
        cerr << "Can't open pi_value_last.txt.(outfile)\n";
        return -1;
    }

    outfile2 << res2;

    outfile2.close();
    
    cout << "Complete!\n";
    return 0;
}
