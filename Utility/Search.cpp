//
// Created by MAHMOUD on 5/19/2023.
//
#include <iostream>
#include <algorithm>

double calculateRelevanceScore(int queryLength,int maxCommonLength){
    return (maxCommonLength / float(queryLength) * 100);
}

int calculateCommonSubstringLength(std::string& ref, std::string& query) {
    transform(ref.begin(), ref.end(), ref.begin(), ::tolower);

    // get str2 in lowercase
    transform(query.begin(), query.end(), query.begin(), ::tolower);

    const int QUERY_LENGTH = (int) query.size();
    const int TITLE_LENGTH = (int) ref.size();

    int substringLength = 0;
    int maxCommonLength = 0;

    for (int Q = 0; Q < QUERY_LENGTH; ++Q) {
        for (int T = 0; T < TITLE_LENGTH; ++T) {

            if (query[Q] == ref[T]){
                substringLength++;
                T++;
                Q++;
                continue;
            }
            else {
                T++;
                if (substringLength >= 2) maxCommonLength+=substringLength;
                substringLength = 0;
            }
        }
    }

    return maxCommonLength;
}