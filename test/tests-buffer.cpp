#include "../src/buffer.h"
#include <catch2/catch_test_macros.hpp>

TEST_CASE( "Testing buffer produce and consume", "[buffer]" ) {


    SECTION( "Testing basic produce and consume funtionality 1 element." ) {

        //init
        const fs::path p("test/test_data/hiya.txt");
        const fs::directory_entry testHiya(p);
        std::unique_ptr<Buffer> buf = std::make_unique<Buffer>();

        //test
        buf->produce(testHiya);
        REQUIRE( buf->size() == 1 );
        buf->consume();
        REQUIRE( buf->size() == 0 );
        buf->setPopulated();
        REQUIRE( buf->isDone() );

    }

}
