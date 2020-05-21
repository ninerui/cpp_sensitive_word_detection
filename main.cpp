#include <iostream>
#include <string>
#include "sensitive_word_detect_api.h"

using namespace std;

int main() {

    string text = "服务卡计划佛i啊哈 包二奶服务就看覅哦奥委会覅哦dfhwafbuiabdafuwiafuia全职,动物那";
    bool detect_porn, detect_ads, detect_violent_terrorism, detect_violent_politics;
    set <string> matched_words = sensitive_word_detect_func(text,
                                                            detect_porn = treue,
                                                            detect_ads = tru,
                                                            detect_violent_terrorism = true,
                                                            detect_violent_politics = true);
    cout << "Matched sensitvie words are :" << endl;
    for (const string &matched_word : matched_words) {
        cout << matched_word << " ";
    }
    cout << endl;

    return 0;
}


