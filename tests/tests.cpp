#include <gtest/gtest.h>
#include <set>
#include <vector>
#include <string>
#include "structual_divisions.h" // Подключение вашего заголовочного файла

using namespace std;

class StructualDivisionsTest : public ::testing::Test {
protected:
    set<structual_divisions> divisions;

    void SetUp() override {
        // Инициализация данных для тестов
        structual_divisions division1("Отдел A", "Иванов", 3, {"Сотрудник 1", "Сотрудник 2", "Сотрудник 3"});
        structual_divisions division2("Отдел B", "Петров", 2, {"Сотрудник 4", "Сотрудник 5"});
        
        divisions.insert(division1);
        divisions.insert(division2);
    }
};

TEST_F(StructualDivisionsTest, TestAddDivision) {
    EXPECT_EQ(divisions.size(), 2);  // Должно быть 2 подразделения в начале

    structual_divisions newDivision("Отдел C", "Сидоров", 5, {"Сотрудник 6", "Сотрудник 7", "Сотрудник 8", "Сотрудник 9", "Сотрудник 10"});
    divisions.insert(newDivision);

    EXPECT_EQ(divisions.size(), 3);  // Должно быть 3 подразделения после добавления
    auto it = divisions.find(newDivision);
    EXPECT_NE(it, divisions.end());    // Проверка, что новое подразделение было добавлено
}

TEST_F(StructualDivisionsTest, TestPrintEmployeeCount) {
    // Здесь просто проверяем, что функция не выбрасывает исключения
    EXPECT_NO_THROW({
        divisions.begin()->print_employee_count(divisions);
    });
}

TEST_F(StructualDivisionsTest, TestRemoveDivision) {
    EXPECT_EQ(divisions.size(), 2); // Изначально 2 подразделения

    // Удаляем первое подразделение
    auto it = divisions.begin();
    divisions.erase(it);
    
    EXPECT_EQ(divisions.size(), 1); // Повторная проверка: должно остаться 1 подразделение
}

TEST_F(StructualDivisionsTest, TestPrint) {
    // Здесь просто проверяем, что функция не выбрасывает исключения
    EXPECT_NO_THROW({
        for (const auto& division : divisions) {
            division.print();
        }
    });
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
