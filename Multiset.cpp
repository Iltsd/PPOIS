#include "Multiset.h"

class Multiset;
int subsetSize(const std::string& str);


    Multiset::Multiset() {};
    Multiset::Multiset(const std::string& str)          //{a, b, c, {o,a,s,k},d,  {r, k}, {{a}, m}} +{b, c, {o,a,s,k},d,  {r, k}, {{b} m}}
    {                                                                                             //{bcd} 1{oask} 1{rk} 1{m} 2{a}
        for (int i = 1;i < str.size();i++)
        {
            if (str[i] == '{')
            {
                int counter = subsetSize(str.substr(i + 1));
                subset[std::make_shared<Multiset>(str.substr(i, counter))]++;
                counter = 1;
                while (counter > 0)
                {
                    i++;
                    if (str[i] == '}') counter--;
                    else if (str[i] == '{') counter++;
                }
            }
            if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
            {
                elements[(str[i])]++;
            }
        }
    }
    Multiset::Multiset(const char*& str1)          //{a, b, c, {o,a,s,k},d,  {r, k}, {{a}, m}} +{b, c, {o,a,s,k},d,  {r, k}, {{b} m}}
    {                                                                                             //{bcd} 1{oask} 1{rk} 1{m} 2{a}
        std::string str = str1;
        for (int i = 1;i < str.size();i++)
        {
            if (str[i] == '{')
            {
                int counter = subsetSize(str.substr(i + 1));
                subset[std::make_shared<Multiset>(str.substr(i, counter))]++;
                counter = 1;
                while (counter > 0)
                {
                    i++;
                    if (str[i] == '}') counter--;
                    else if (str[i] == '{') counter++;
                }
            }
            if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
            {
                elements[(str[i])]++;
            }
        }
    }
    Multiset::Multiset (const std::shared_ptr<Multiset>&)
    {
        for (const auto& elem : elements) {
             this->add(elem.first, elem.second);
        }

        for (const auto& elem : subset) {
            this->add(elem.first, elem.second);
        }
    }
    void Multiset::uniqueSubsets()
    {
        std::map<std::shared_ptr<Multiset>, int> uniqueSubsets;

        for (const auto& elem : subset) {
            bool foundDuplicate = false;

            for (const auto& uniqueElem : uniqueSubsets) {
                if (*elem.first ==*uniqueElem.first) 
                {
                    uniqueSubsets[uniqueElem.first] += elem.second;
                    foundDuplicate = true;
                    break;
                }
            }

            if (!foundDuplicate) {
                uniqueSubsets[elem.first] = elem.second; 
            }
        }
        subset = uniqueSubsets;
    }
    bool enoughBrackets(const std::string& str)
    {
        int counter = 0;
        for (int i = 0;i < str.size();i++)
        {
            if (str[i] == '{') counter++;
            else if (str[i] == '}') counter--;
        }
        return counter <= 0;
    }
    void Multiset::add(char element, int count) {
        elements[element] += count;
    }
    void Multiset::add(std::shared_ptr<Multiset> element, int count) {
        subset[element] += count;
    }

    void Multiset::remove(char element, int count) {
        if (elements.find(element) != elements.end()) {
            elements[element] -= count;
            if (elements[element] <= 0) {
                elements.erase(element);
            }
        }
    }
    void Multiset::remove(std::shared_ptr<Multiset> element, int count) {
        if (subset.find(element) != subset.end()) {
            subset[element] -= count;
            if (subset[element] <= 0) {
                subset.erase(element);
            }
        }
    }
    void Multiset::print(int depth) const {
        std::cout << std::string(depth, ' ') << "{ " << std::endl;


        for (const auto& elem : elements) {
            std::cout << std::string(depth + 2, ' ') << "'" << elem.first << "' : " << elem.second << std::endl;
        }

        for (const auto& elem : subset) {
            std::cout << std::string(depth + 2, ' ') << "[Multiset] : " << elem.second << std::endl;
            elem.first->print(depth + 4); 
        }
        std::cout << std::string(depth, ' ') << "}" << std::endl;
    }

    bool Multiset::operator ==( const Multiset& set2) {

        if (elements != set2.elements) {
            return false;
        }


        if (subset.size() != set2.subset.size()) {
            return false;
        }

        auto it1 = subset.begin();
        auto it2 = set2.subset.begin();
        while (it1 != subset.end() && it2 != set2.subset.end()) {
            if (it1->second != it2->second) return false;
            if (!(*it1->first==*it2->first))   return false;
            ++it1;
            ++it2;
        }

        return true;
    }
    void Multiset::power()
    {
        int counter = 0;
        for (auto element : elements)
        {
            counter += element.second;
        }
        for (auto element : subset)
        {
            counter += element.second;
        }
        std::cout << "мощность данного множества: " << counter << std::endl;
        
    }

    void Multiset::isEmpty()
    {
        if (elements.size() < 1 && subset.size() < 1) std::cout << "Множество не содеожит элементы\n";
        else std::cout << "Множество содержит элементы\n";
    }
    Multiset& Multiset::operator[](const std::string& str)
    {
        if (str.size() == 1) {
            char ch = str[0];
            if (elements.find(ch) != elements.end()) {
                std::cout << "Элемент '" << ch << "' существует в множестве." << std::endl;
                return *this;
            }
        }

        auto element = std::make_shared<Multiset>(str); 
        for (const auto& subsetElem : subset) {
            if (*subsetElem.first == *element) {
                std::cout << "Такое подмножество существует." << std::endl;
                return *this;
            }
        }

        std::cout << "Такого элемента или подмножества нет." << std::endl;
        return *this;
    }



    Multiset Multiset::operator+(const std::shared_ptr<Multiset>& set)
    {
        Multiset result = *this;

        for (const auto& elem : set->elements)
            result.elements[elem.first] = std::max(result.elements[elem.first], elem.second);


        for (const auto& other : set->subset) {
            bool duplicate = false;


            for (const auto& elem : result.subset) {
                if (*elem.first == *other.first) {
                    result.subset[elem.first] = std::max(elem.second, other.second);
                    duplicate = true;
                    break;
                }
            }

            if (!duplicate) {
                result.subset[other.first] = other.second;
            }
        }

        return result;
    }
    Multiset Multiset::operator+=(const std::shared_ptr<Multiset>& set)
    {
        *this = *this + set;
        return *this;
    }

    Multiset Multiset::operator*(const std::shared_ptr<Multiset>& set) {
        Multiset result;

        for (const auto& elem : elements) {
            auto it = set->elements.find(elem.first);
            if (it != set->elements.end()) {
                result.elements[elem.first] = std::min(elem.second, it->second);
            }
        }

        for (const auto& elem : subset) {
            for (const auto& other : set->subset) {
                if (*elem.first == *other.first) {
                    result.subset[elem.first] = std::min(elem.second, other.second);
                    break;
                }
            }
        }

        return result;
    }
    Multiset Multiset::operator*=(const std::shared_ptr<Multiset>& set)
    {
        *this = *this * set;
        return *this;
    }

    Multiset Multiset::operator-(const std::shared_ptr<Multiset>& set) {
        Multiset result = *this;

        for (const auto& elem : set->elements) {
            if (result.elements.find(elem.first) != result.elements.end()) {
                result.elements[elem.first] -= elem.second;
                if (result.elements[elem.first] <= 0) {
                    result.elements.erase(elem.first);
                }
            }
        }

        for (const auto& other : set->subset) {
            for (const auto& elem : result.subset) {
                if (*elem.first == *other.first) {
                    result.subset[elem.first] -= other.second;
                    if (result.subset[elem.first] <= 0) {
                        result.subset.erase(elem.first);
                    }
                    break;
                }
            }
        }

        return result;
    }
    Multiset Multiset::operator-=(const std::shared_ptr<Multiset>& set)
    {
        *this = *this - set;
        return *this;
    }

    Multiset Multiset::operator=(const std::shared_ptr<Multiset>& set)
    {
        elements = set->elements;
        subset = set->subset;
        return *this;
    }

    std::vector<Multiset> Multiset::boolean() const {
        std::vector<Multiset> powerSet; 
        powerSet.push_back(Multiset()); 

        for (const auto& elem : elements) {
            std::vector<Multiset> newSubsets; 
            for (const auto& set : powerSet) {
                Multiset newSet = set;
                newSet.add(elem.first, elem.second); 
                newSubsets.push_back(newSet);
            }
            powerSet.insert(powerSet.end(), newSubsets.begin(), newSubsets.end());
        }

        for (const auto& sub : subset) {
            std::vector<Multiset> newSubsets; 
            for (const auto& set : powerSet) {
                Multiset newSet = set;
                newSet.add(sub.first, sub.second); 
                newSubsets.push_back(newSet);
            }
            powerSet.insert(powerSet.end(), newSubsets.begin(), newSubsets.end());
        }

        return powerSet;
    }
void showPowerSet(std::vector<Multiset> powerSet)
{
    std::cout << "Power Set:" << std::endl;
    for (const auto& subset : powerSet) {
        subset.print();
    }
}
int subsetSize(const std::string& str)
{
    int counter = 1;
    int i = 0;
    for (;counter > 0;i++)
    {
        if (str[i] == '}') counter--;
        else if (str[i] == '{') counter++;
    }
    return i;
}


