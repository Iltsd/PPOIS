#include "pch.h"
#include "Multiset.h"


TEST(MultisetTest, DefaultConstructor) {
    Multiset mset;
    EXPECT_TRUE(mset.getElements().empty());
}

TEST(MultisetTest, AddElement) {
    Multiset mset;
    mset.add('a', 2);
    mset.add('b', 1);

    std::unordered_map<char, int> expected = { {'a', 2}, {'b', 1} };
    EXPECT_EQ(mset.getElements(), expected);
}
TEST(MultisetTest, AddSubset) {
    Multiset mset;
    auto addedMultiset = std::make_shared<Multiset>("{{aa}{tod}{AAdd}}");
    mset.add(addedMultiset);

    EXPECT_EQ(mset.getSubsets().size(), 1);
}


TEST(MultisetTest, RemoveElement) {
    Multiset mset;
    mset.add('a', 3);
    mset.remove('a', 1);

    std::unordered_map<char, int> expected = { {'a', 2} };
    EXPECT_EQ(mset.getElements(), expected);
}
TEST(MultisetTest, RemoveSubset) {
    std::string str = "{{aaa}}";
    Multiset mset(str);
    auto removeSet = std::make_shared<Multiset>(str);
    mset.remove(removeSet);
    EXPECT_EQ(mset.getSubsets().size(), 0);
}


TEST(MultisetTest, AddMultiset) {
    auto mset1 = std::make_shared<Multiset>();
    mset1->add('x', 2);

    Multiset mset2;
    mset2.add('a', 1);
    mset2.add(mset1);

    std::unordered_map<char, int> expected = { {'a', 1} };
    EXPECT_EQ(mset2.getElements(), expected);

}

TEST(MultisetTest, PowerSet) {
    Multiset mset;
    mset.add('a', 1);
    mset.add('b', 1);

    std::vector<Multiset> powerSet = mset.boolean();
    EXPECT_EQ(powerSet.size(), 4); 
}

TEST(MultisetTest, EqualityTest) {
    Multiset mset1;
    mset1.add('a', 2);
    mset1.add('b', 1);

    Multiset mset2;
    mset2.add('a', 2);
    mset2.add('b', 1);

    EXPECT_TRUE(mset1 == mset2);
}

TEST(MultisetTest, IsEmptyTest) {
    Multiset mset;
    testing::internal::CaptureStdout();
    mset.isEmpty();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Множество не содеожит элементы\n");
}

TEST(MultisetTest, ConstructorAndPrint) {
    std::string input = "{a, b, c, {o,a,s,k},d, {r, k}, {{a}, m}}";
    Multiset multiset(input);

    ASSERT_EQ(multiset.getElements().size(), 4);
}
TEST(MultisetTest, ConstructorCharAndPrint) {
    char* input = new char[100];
    input = "{a, b, c, {o,a,s,k},d, {r, k}, {{a}, m}}";
    Multiset multiset(input);

    ASSERT_EQ(multiset.getElements().size(), 4);
}
TEST(MultisetTest, copyConstructor) {
    std::string input = "{a, b, c, {o,a,s,k},d, {r, k}, {{a}, m}}";
    auto multiset = std::make_shared<Multiset>(input);
    Multiset multiset1(multiset);

    ASSERT_EQ(multiset1.getElements().size(), 4);
}

TEST(MultisetTest, UniqueSubsets) {
    std::string input = "{{a}, {a}, {b}}";
    Multiset multiset(input);

    multiset.uniqueSubsets();

    ASSERT_EQ(multiset.getElements().size(), 0);

}

TEST(MultisetTest, EnoughBrackets) {
    std::string validSet = "{a, b, {c, d}}";
    std::string invalidSet = "{a, b, {c, d}";

    ASSERT_TRUE(enoughBrackets(validSet));
    ASSERT_FALSE(enoughBrackets(invalidSet));
}

TEST(MultisetTest, OperatorEquality) {
    std::string set1 = "{a, b, {c}}";
    std::string set2 = "{a, b, {c}}";

    Multiset multiset1(set1);
    Multiset multiset2(set2);

    ASSERT_TRUE(multiset1 == multiset2);
}

TEST(MultisetTest, Power) {
    std::string input = "{a, b, {c, d}}";
    Multiset multiset(input);
    std::stringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

    multiset.power();

    std::cout.rdbuf(old);
    ASSERT_EQ(buffer.str(), "мощность данного множества: 3\n");
}

TEST(MultisetTest, OperatorBreakets)
{
    std::string set1 = "{a, b, {c}}";

    Multiset multiset(set1);
    int result = multiset["a"];

    ASSERT_EQ(result, 1); 
}
TEST(MultisetTest, OperatorBreaketsSubsets)
{
    std::string set1 = "{a, b, {c}}";

    Multiset multiset(set1);
    int result = multiset["{c}"];

    ASSERT_EQ(result, 1);
}

// Тест на оператор +
TEST(MultisetTest, OperatorPlus) {
    std::string set1 = "{a, b, {c}}";
    std::string set2 = "{b, d, {e}}";

    Multiset multiset1(set1);
    Multiset multiset2(set2);

    Multiset result = multiset1 + std::make_shared<Multiset>(multiset2);

    ASSERT_EQ(result.getElements().size(), 3);
}
TEST(MultisetTest, OperatorEqualPlus) {
    std::string set1 = "{a, b, {c}}";
    std::string set2 = "{b, {c}}";

    Multiset multiset1(set1);
    Multiset multiset2(set2);

    multiset1 += std::make_shared<Multiset>(multiset2);

    ASSERT_EQ(multiset1.getElements().size(), 2);
    ASSERT_EQ(multiset1.getSubsets().size(), 1);
}

// Тест на оператор *
TEST(MultisetTest, OperatorMultiply) {
    std::string set1 = "{a, b, {c}}";
    std::string set2 = "{a, {c}}";

    Multiset multiset1(set1);
    Multiset multiset2(set2);

    Multiset result = multiset1 * std::make_shared<Multiset>(multiset2);

    ASSERT_EQ(result.getElements().size(), 1);

}
TEST(MultisetTest, OperatorEqualMultiply) {
    std::string set1 = "{a, b, {c}}";
    std::string set2 = "{b, {c}}";

    Multiset multiset1(set1);
    Multiset multiset2(set2);

    multiset1 *= std::make_shared<Multiset>(multiset2);

    ASSERT_EQ(multiset1.getSubsets().size(), 1); 
    ASSERT_EQ(multiset1.getSubsets().size(), 1);
}

// Тест на оператор -
TEST(MultisetTest, OperatorMinus) {
    std::string set1 = "{a, b, {c}}";
    std::string set2 = "{b, {c}}";

    Multiset multiset1(set1);
    Multiset multiset2(set2);

    Multiset result = multiset1 - std::make_shared<Multiset>(multiset2);

    ASSERT_EQ(result.getElements().size(), 1);
    
}
TEST(MultisetTest, OperatorEqualMinus) {
    std::string set1 = "{a, b, {c}}";
    std::string set2 = "{b, {c}}";

    Multiset multiset1(set1);
    Multiset multiset2(set2);

    multiset1 -= std::make_shared<Multiset>(multiset2);

    ASSERT_EQ(multiset1.getElements().size(), 1);
    ASSERT_EQ(multiset1.getSubsets().size(), 0);
}

TEST(MultisetTest, IsEmpty) {
    std::string input = "{}";
    Multiset multiset(input);

    std::stringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

    multiset.isEmpty();

    std::cout.rdbuf(old);
    ASSERT_EQ(buffer.str(), "Множество не содеожит элементы\n");
}


TEST(MultisetTest, BooleanTest) {
    std::string input = "{a, b}";
    Multiset multiset(input);

    auto powerSet = multiset.boolean();

    ASSERT_EQ(powerSet.size(), 4);
}
