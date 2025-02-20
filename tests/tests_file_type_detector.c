#include "../include/errors.h"

#include "../include/file_type_detector.h"

#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include <CUnit/Automated.h>

/**
 * Tests for get_file_type function ( "gft" for short )
 */

void test_file_not_found_gft(void)
{
    file_info info;

    int output = get_file_type("notFound", &info);

    CU_ASSERT_EQUAL(output, FILE_NOT_FOUND);
}

void test_zip_gft(void)
{
    file_info info;

    int output = get_file_type("file.txt", &info);
    printf("%d\n", output);
    CU_ASSERT_EQUAL(output, 0);
}

/**
 * Tests for get_file_size function( "gfs" for short )
 */

void test_zip_file_gfs(void)
{
    file_info info;

    int output = get_file_size("test.zip", &info);

    CU_ASSERT_EQUAL(output, 377); // Should return the file size

    int file_size = info.file_size;
    CU_ASSERT_EQUAL(file_size, 377); // File size is 377 bytes
}

CU_TestInfo tests_get_file_type[] = {
    {"Test file type #1: File not Found", test_file_not_found_gft},
    {"Test file type #2: Zip file mime type", test_zip_gft},
    CU_TEST_INFO_NULL};

CU_TestInfo tests_get_file_size[] = {
    {"Test file size #1: File size 377", test_zip_file_gfs},
    CU_TEST_INFO_NULL};

CU_SuiteInfo suite_file_type_detector[] = {
    {"Suite tests for get_file_type function", NULL, NULL, NULL, NULL, tests_get_file_type},
    {"Suite tests for get_file_size function", NULL, NULL, NULL, NULL, tests_get_file_size},
    CU_SUITE_INFO_NULL};

int main(void)
{
    CU_ErrorCode init_test_registry = CU_initialize_registry();

    if (init_test_registry == CUE_SUCCESS)
    {

        CU_ErrorCode suite_status = CU_register_suites(suite_file_type_detector);

        if (suite_status == CUE_SUCCESS)
        {
            // Verbose output of the tests on the console
            CU_basic_set_mode(CU_BRM_VERBOSE);
            CU_basic_run_tests();

            // Output files 
            CU_set_output_filename("tests/log_suite_file_type_detector");
            CU_list_tests_to_file(); // (Listing & Results xml)
            CU_automated_run_tests();
        }

        if (suite_status == CUE_NOMEMORY)
        {
            fprintf(stderr, "Memory allocation failed.\n");
            CU_cleanup_registry();
            return -1;
        }

        CU_cleanup_registry();
    }

    if (init_test_registry == CUE_NOMEMORY)
    {
        fprintf(stderr, "Error: Memory allocation failed.\n");
        return -1;
    }

    return 0;
}
