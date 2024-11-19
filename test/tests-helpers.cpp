#include "../src/helpers.h"
#include <catch2/catch_test_macros.hpp>

TEST_CASE( "Unit test - helpers", "[helpers]" ) {

    SECTION( "Testing loadAndProceessFile." ) {

        //init
        std::stringstream captureBuffer;
        std::streambuf* oldCout = std::cout.rdbuf(captureBuffer.rdbuf());
        fs::path p(fs::current_path());
        p += fs::path("/test_data/hiya.txt");
        const fs::directory_entry testHiya(p);
        const std::string pattern = "iya";

        //test
        loadAndProcessFile(std::move(testHiya), pattern);
        std::string captured = captureBuffer.str();
        std::string expected = "hiya.txt:Line 0: Hiya!\n";
        REQUIRE( captured == expected );

        //cleanup
        std::cout.rdbuf(oldCout); // Restore stdout
        
    }

    SECTION( "Testing recursiveSearch." ) {

        //init
        fs::path p(fs::current_path());
        p += fs::path("/test_data");
        const fs::directory_entry testHiya(p);
        std::unique_ptr<Buffer> buf = std::make_unique<Buffer>();

        //test
        recursiveSearch(buf, p);
        REQUIRE( buf->size() == 1 );
        REQUIRE( buf->isDone() == 0 );
        REQUIRE( buf->isPopulated() == 1 );
        
    }

}
