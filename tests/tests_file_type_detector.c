#include "../include/errors.h"

#include "../include/file_type_detector.h"

#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include <CUnit/Automated.h>

/**
 * Tests for get_file_type function ( "gft" for short )
 */

void test_sfo_file_gft(void)
{
    file_info info;

    int output = get_file_type("sfo", &info);
    get_file_size("sfo", &info);
    CU_ASSERT_EQUAL(output, 0);
    CU_ASSERT_EQUAL(true, info.success_analyse);
    CU_ASSERT_NSTRING_EQUAL(info.type, "ELF 64-bit LSB shared object", strlen("ELF 64-bit LSB shared object"));
    CU_ASSERT_EQUAL(info.file_size, 22840);
}

void test_jpeg_file_gft(void)
{
    file_info info;

    int output = get_file_type("brick_texture.jpg", &info);
    get_file_size("brick_texture.jpg", &info);
    CU_ASSERT_EQUAL(output, 0);
    CU_ASSERT_EQUAL(true, info.success_analyse);
    CU_ASSERT_NSTRING_EQUAL(info.type, "JPEG image data", strlen("JPEG image data"));
    CU_ASSERT_EQUAL(info.file_size, 1031241);
}

void test_zip_file_gft(void)
{
    file_info info;

    int output = get_file_type("test.zip", &info);
    get_file_size("test.zip", &info);

    CU_ASSERT_EQUAL(output, 0);
    CU_ASSERT_EQUAL(true, info.success_analyse);
    CU_ASSERT_NSTRING_EQUAL(info.type, "Zip archive data", strlen("Zip archive data"));
    CU_ASSERT_EQUAL(info.file_size, 377);
}

void test_rar_file_gft(void)
{
    file_info info;

    int output = get_file_type("test.rar", &info);
    get_file_size("test.rar", &info);

    CU_ASSERT_EQUAL(output, 0);
    CU_ASSERT_EQUAL(true, info.success_analyse);
    CU_ASSERT_NSTRING_EQUAL(info.type, "RAR archive data", strlen("RAR archive data"));
    CU_ASSERT_EQUAL(info.file_size, 1046817);
}

void test_makefile_file_gft(void)
{
    file_info info;

    int output = get_file_type("Makefile", &info);
    get_file_size("Makefile", &info);

    CU_ASSERT_EQUAL(output, 0);
    CU_ASSERT_EQUAL(true, info.success_analyse);
    CU_ASSERT_NSTRING_EQUAL(info.type, "makefile script", strlen("makefile script"));
    CU_ASSERT_EQUAL(info.file_size, 457);
}

void test_text_file_gft(void)
{
    file_info info;

    int output = get_file_type("file.txt", &info);
    get_file_size("file.txt", &info);

    CU_ASSERT_EQUAL(output, 0);
    CU_ASSERT_TRUE(info.success_analyse);
    CU_ASSERT_NSTRING_EQUAL(info.type, "Unicode text", strlen("Unicode text"));
}

void test_file_not_found_gft(void)
{
    file_info info;

    int output = get_file_type("notFound", &info);

    CU_ASSERT_EQUAL(output, FAIL_OPEN_FILE);
    CU_ASSERT_FALSE(info.success_analyse);
}

CU_TestInfo tests_get_file_type[] = {
    {"Test file type #1: File not Found", test_file_not_found_gft},
    {"Test file #2: ZIP file (success analysis, filesize, type)", test_zip_file_gft},
    {"Test file #3: RAR file (success analysis, filesize, type)", test_rar_file_gft},
    {"Test file #4: sfo file (success analysis, filesize, type)", test_sfo_file_gft},
    {"Test file #5: JPEG file (success analysis, filesize, type)", test_jpeg_file_gft},
    {"Test file #6: Makefile file (success analysis, filesize, type)", test_makefile_file_gft},
    CU_TEST_INFO_NULL};

CU_SuiteInfo suite_file_type_detector[] = {
    {"Suite tests for get_file_type function", NULL, NULL, NULL, NULL, tests_get_file_type},
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
