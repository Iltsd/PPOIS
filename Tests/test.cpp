#include "pch.h"
#include "Multiset.h"

// Тест конструктора по умолчанию
TEST(MultisetTest, DefaultConstructor) {
    Multiset mset;
    EXPECT_TRUE(mset.getElements().empty()); // Проверяем, что элементов нет
}

// Тест добавления элементов
TEST(MultisetTest, AddElement) {
    Multiset mset;
    mset.add('a', 2);
    mset.add('b', 1);

    std::unordered_map<char, int> expected = { {'a', 2}, {'b', 1} };
    EXPECT_EQ(mset.getElements(), expected);
}

// Тест удаления элементов
TEST(MultisetTest, RemoveElement) {
    Multiset mset;
    mset.add('a', 3);
    mset.remove('a', 1);

    std::unordered_map<char, int> expected = { {'a', 2} };
    EXPECT_EQ(mset.getElements(), expected);
}

// Тест добавления мультимножества
TEST(MultisetTest, AddMultiset) {
    auto mset1 = std::make_shared<Multiset>();
    mset1->add('x', 2);

    Multiset mset2;
    mset2.add('a', 1);
    mset2.add(mset1);

    // Проверим, что в mset2 присутствуют элементы
    std::unordered_map<char, int> expected = { {'a', 1} };
    EXPECT_EQ(mset2.getElements(), expected);
    // Здесь можно добавить проверки для подмножеств, если будет необходимость.
}

// Тест на мощность множества
TEST(MultisetTest, PowerSet) {
    Multiset mset;
    mset.add('a', 1);
    mset.add('b', 1);

    std::vector<Multiset> powerSet = mset.boolean();
    EXPECT_EQ(powerSet.size(), 4); // Пустое множество + все возможные подмножества
}

// Тест на равенство мультимножеств
TEST(MultisetTest, EqualityTest) {
    Multiset mset1;
    mset1.add('a', 2);
    mset1.add('b', 1);

    Multiset mset2;
    mset2.add('a', 2);
    mset2.add('b', 1);

    EXPECT_TRUE(mset1 == mset2);
}

// Тест на пустое множество
TEST(MultisetTest, IsEmptyTest) {
    Multiset mset;
    testing::internal::CaptureStdout(); // Захватываем вывод
    mset.isEmpty();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Множество не содеожит элементы\n");
}
