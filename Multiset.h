#pragma once

#include <iostream>
#include <map>
#include <memory>
#include <variant>
#include <string>
#include <vector>


class Multiset {
private:
    std::map<char, int> elements;
    std::map<std::shared_ptr<Multiset>, int> subset;

public:
    Multiset();
    Multiset(const std::string& str);
    Multiset(const char*& str1);
    Multiset(const std::shared_ptr<Multiset>&);
    void uniqueSubsets();
    void add(char element, int count = 1);
    void add(std::shared_ptr<Multiset> element, int count = 1);
    void remove(char element, int count = 1);
    void remove(std::shared_ptr<Multiset> element, int count = 1);
    void print(int depth = 0) const;
    void power();
    void isEmpty();


    Multiset& operator[](const std::string& str);
    bool operator ==(const Multiset& set2);
    Multiset operator+(const std::shared_ptr<Multiset>& set);
    Multiset operator+=(const std::shared_ptr<Multiset>& set);
    Multiset operator*(const std::shared_ptr<Multiset>& set);
    Multiset operator*=(const std::shared_ptr<Multiset>& set);
    Multiset operator-(const std::shared_ptr<Multiset>& set);
    Multiset operator-=(const std::shared_ptr<Multiset>& set);
    Multiset operator=(const std::shared_ptr<Multiset>& set);
    std::vector<Multiset> boolean() const;



};

    bool enoughBrackets(const std::string& str);
    void showPowerSet(std::vector<Multiset> powerSet);