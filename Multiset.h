#pragma once

#include <iostream>
#include <unordered_map>
#include <memory>
#include <string>
#include <vector>


class Multiset {
private:
    std::unordered_map<char, int> elements;
    std::unordered_map<std::shared_ptr<Multiset>, int> subset;

public:
    Multiset();
    Multiset(const std::string& str);
    Multiset(const char* str1);
    Multiset(const std::shared_ptr<Multiset>&);
    void uniqueSubsets();
    void add(char element, int count = 1);
    void add(std::shared_ptr<Multiset> element, int count = 1);
    void remove(char element, int count = 1);
    void remove(std::shared_ptr<Multiset> element, int count = 1);
    void print(int depth = 0) const;
    void power();
    void isEmpty();


    int operator[](const std::string& str);
    bool operator ==(const Multiset& set2);
    Multiset operator+(const std::shared_ptr<Multiset>& set);
    Multiset operator+=(const std::shared_ptr<Multiset>& set);
    Multiset operator*(const std::shared_ptr<Multiset>& set);
    Multiset operator*=(const std::shared_ptr<Multiset>& set);
    Multiset operator-(const std::shared_ptr<Multiset>& set);
    Multiset operator-=(const std::shared_ptr<Multiset>& set);
    Multiset operator=(const std::shared_ptr<Multiset>& set);
    std::vector<Multiset> boolean() const;


    std::unordered_map<char, int> getElements();
    std::unordered_map<std::shared_ptr<Multiset>, int> getSubsets();
};

    bool enoughBrackets(const std::string& str);
    void showPowerSet(std::vector<Multiset> powerSet);
    int subsetSize(const std::string& str);