#define CATCH_CONFIG_MAIN
#include "../src/demo.hpp"
#include"catch.hpp"

TEST_CASE("Testing -1"){
string s[9]={" ","2","3","4","5","6","7","8","=A1+B2"};
REQUIRE(solution(s) == -1);
REQUIRE_FALSE(solution(s) != -1);
}
TEST_CASE("Testing -2"){
string s[9]={"1","2","3","4","5","6","7","8","=b2*6"};
REQUIRE(solution(s) == 30);
REQUIRE_FALSE(solution(s) != 30);
}
TEST_CASE("Testing -3"){
string s[9]={"1","2","3","4","5","6","7","8","=b2-b1"};
REQUIRE(solution(s) == 3);
REQUIRE_FALSE(solution(s) != 3);
}
TEST_CASE("Testing-4"){
string s[9]={"2","8","3","4","5","6","7","8","=b2/a1"};
REQUIRE(solution(s) == 2);
REQUIRE_FALSE(solution(s) != 2);
}