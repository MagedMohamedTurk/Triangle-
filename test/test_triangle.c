#include "unity.h"
#include "../check_triangle.h" 
#include <string.h>

float triangle1[3] = {3, 4, 5};
float triangle2[3] = {6, 8, 10};
float triangle3[3] = {3, 3, 5};
float triangle4[3] = {6, 6, 6};
float triangle5[3] = {5, 6, 5.5};
float NotTriangle[3] = {1, 3, 9};
void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void test_square(void) {
    //test stuff
    TEST_ASSERT_EQUAL_FLOAT(16, square(4));
}

void test_check_triangle(void)
{
    TEST_ASSERT(check_triangle(triangle1));
    TEST_ASSERT(check_triangle(triangle2));
    TEST_ASSERT(check_triangle(triangle3));
    TEST_ASSERT(check_triangle(triangle4));
    TEST_ASSERT(check_triangle(triangle5));
    TEST_ASSERT_MESSAGE(!check_triangle(NotTriangle), "Not a triangle!");
}


void test_classify_side(void)
{
    TEST_ASSERT_MESSAGE(strcmp(classify_side(triangle1), "Scalene Triangle") == 0, "Test Scalene");
    TEST_ASSERT_MESSAGE(strcmp(classify_side(triangle3), "Isosceles Triangle") == 0, "Test Isosceles");
    TEST_ASSERT_MESSAGE(strcmp(classify_side(triangle4),  "Equilateral Triangle") == 0, "Test Equilateral");
}

void test_classify_angle(void)
{
    TEST_ASSERT_MESSAGE(strcmp(classify_angle(triangle1), "Right-angled Triangle") == 0, "Test Right-angled");
    TEST_ASSERT_MESSAGE(strcmp(classify_angle(triangle2), "Right-angled Triangle") == 0, "Test Right-angled");
    TEST_ASSERT_MESSAGE(strcmp(classify_angle(triangle4), "Equiangular Triangle") == 0, "Test Right-angled");
    TEST_ASSERT_MESSAGE(strcmp(classify_angle(triangle5), "Acute Triangle") == 0, "Test Acute");
}

void test_check_obtuse(void)
{
    TEST_ASSERT_MESSAGE(check_obtuse(-0.866), "Obtuse 150");
    TEST_ASSERT_MESSAGE(!check_obtuse(0.0174), "Obtuse 89");
    TEST_ASSERT_MESSAGE(!check_obtuse(0.866), "Obtuse 30");
}
int main(void)
{
UNITY_BEGIN();
RUN_TEST(test_square);
RUN_TEST(test_check_triangle);
RUN_TEST(test_classify_side);
RUN_TEST(test_classify_angle);
RUN_TEST(test_check_obtuse);

return UNITY_END();
}