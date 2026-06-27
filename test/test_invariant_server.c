#include <check.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>

// Forward declaration of the function from server.c
extern void *allocate_buffer(size_t count, size_t size);

START_TEST(test_allocation_overflow_check)
{
    // Invariant: Multiplication for allocation size must not overflow
    // or must be properly checked before allocation
    struct {
        size_t count;
        size_t size;
        const char *description;
    } test_cases[] = {
        {SIZE_MAX, 2, "Maximum size multiplication overflow"},
        {SIZE_MAX / 2 + 1, 2, "Boundary overflow case"},
        {100, 10, "Valid normal allocation"},
        {0, SIZE_MAX, "Zero count with max size"},
        {SIZE_MAX, 0, "Max count with zero size"}
    };
    
    int num_cases = sizeof(test_cases) / sizeof(test_cases[0]);
    
    for (int i = 0; i < num_cases; i++) {
        // The security property: if count * size would overflow SIZE_MAX,
        // the function must either return NULL or handle it safely
        void *result = allocate_buffer(test_cases[i].count, test_cases[i].size);
        
        if (test_cases[i].count > 0 && test_cases[i].size > 0) {
            size_t max_allowed = SIZE_MAX / test_cases[i].size;
            if (test_cases[i].count > max_allowed) {
                // Overflow would occur - function must detect this
                ck_assert_msg(result == NULL, 
                    "Overflow not detected for %s (count=%zu, size=%zu)",
                    test_cases[i].description, test_cases[i].count, test_cases[i].size);
            } else {
                // No overflow - allocation may succeed
                ck_assert_msg(result != NULL || test_cases[i].count == 0 || test_cases[i].size == 0,
                    "Valid allocation failed for %s (count=%zu, size=%zu)",
                    test_cases[i].description, test_cases[i].count, test_cases[i].size);
            }
        }
        
        if (result != NULL) {
            free(result);
        }
    }
}
END_TEST

Suite *security_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("Security");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_allocation_overflow_check);
    suite_add_tcase(s, tc_core);

    return s;
}

int main(void)
{
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = security_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}