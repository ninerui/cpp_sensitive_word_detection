//
// Created by ninerui on 2020/5/19.
//

#ifndef CLION__HELLO_WORLD_SENSITIVE_WORD_DETECT_API_H
#define CLION__HELLO_WORLD_SENSITIVE_WORD_DETECT_API_H

#include <iostream>
#include <string>
#include "words_filter.h"
#include "resource.h"

using namespace std;


// 调用此函数返回匹配到的敏感词
// text: 传入的文本内容
// detect_porn: 是否检测色情词库
// detect_ads: 是否检测广告词库
// detect_violent_terrorism: 是否检测暴恐词库
// detect_violent_politics: 是否检测政治词库
set <string> sensitive_word_detect_func(const string &text,
                                        const bool &detect_porn = true,
                                        const bool &detect_ads = true,
                                        const bool &detect_violent_terrorism = true,
                                        const bool &detect_violent_politics = true) {
    vector <string> sensitive_words = {};
    if (detect_porn) {
        sensitive_words.insert(sensitive_words.end(), sensitive_words_porn.begin(), sensitive_words_porn.end());
    };
    if (detect_ads) {
        sensitive_words.insert(sensitive_words.end(), sensitive_words_ads.begin(), sensitive_words_ads.end());
    };
    if (detect_violent_terrorism) {
        sensitive_words.insert(sensitive_words.end(), sensitive_words_violent_terrorism.begin(),
                               sensitive_words_violent_terrorism.end());
    }
    if (detect_violent_politics) {
        sensitive_words.insert(sensitive_words.end(), sensitive_words_politics.begin(), sensitive_words_politics.end());
    };

    WordsFilterTree words_filter(sensitive_words);
    set <string> matched_words = words_filter.findAllSensitiveWords(text, 1);
    return matched_words;
}


#endif //CLION__HELLO_WORLD_SENSITIVE_WORD_DETECT_API_H
