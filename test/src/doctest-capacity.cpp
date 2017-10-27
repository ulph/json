#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "json.hpp"
using nlohmann::json;

TEST_SUITE("capacity")
{
    TEST_CASE("empty()")
    {
        SUBCASE("boolean")
        {
            json j = true;
            const json j_const(j);

            SUBCASE("result of empty")
            {
                CHECK(j.empty() == false);
                CHECK(j_const.empty() == false);
            }

            SUBCASE("definition of empty")
            {
                CHECK(j.empty() == (j.begin() == j.end()));
                CHECK(j_const.empty() == (j_const.begin() == j_const.end()));
            }
        }

        SUBCASE("string")
        {
            json j = "hello world";
            const json j_const(j);

            SUBCASE("result of empty")
            {
                CHECK(j.empty() == false);
                CHECK(j_const.empty() == false);
            }

            SUBCASE("definition of empty")
            {
                CHECK(j.empty() == (j.begin() == j.end()));
                CHECK(j_const.empty() == (j_const.begin() == j_const.end()));
            }
        }

        SUBCASE("array")
        {
            SUBCASE("empty array")
            {
                json j = json::array();
                const json j_const(j);

                SUBCASE("result of empty")
                {
                    CHECK(j.empty() == true);
                    CHECK(j_const.empty() == true);
                }

                SUBCASE("definition of empty")
                {
                    CHECK(j.empty() == (j.begin() == j.end()));
                    CHECK(j_const.empty() == (j_const.begin() == j_const.end()));
                }
            }

            SUBCASE("filled array")
            {
                json j = {1, 2, 3};
                const json j_const(j);

                SUBCASE("result of empty")
                {
                    CHECK(j.empty() == false);
                    CHECK(j_const.empty() == false);
                }

                SUBCASE("definition of empty")
                {
                    CHECK(j.empty() == (j.begin() == j.end()));
                    CHECK(j_const.empty() == (j_const.begin() == j_const.end()));
                }
            }
        }

        SUBCASE("object")
        {
            SUBCASE("empty object")
            {
                json j = json::object();
                const json j_const(j);

                SUBCASE("result of empty")
                {
                    CHECK(j.empty() == true);
                    CHECK(j_const.empty() == true);
                }

                SUBCASE("definition of empty")
                {
                    CHECK(j.empty() == (j.begin() == j.end()));
                    CHECK(j_const.empty() == (j_const.begin() == j_const.end()));
                }
            }

            SUBCASE("filled object")
            {
                json j = {{"one", 1}, {"two", 2}, {"three", 3}};
                const json j_const(j);

                SUBCASE("result of empty")
                {
                    CHECK(j.empty() == false);
                    CHECK(j_const.empty() == false);
                }

                SUBCASE("definition of empty")
                {
                    CHECK(j.empty() == (j.begin() == j.end()));
                    CHECK(j_const.empty() == (j_const.begin() == j_const.end()));
                }
            }
        }

        SUBCASE("number (integer)")
        {
            json j = -23;
            const json j_const(j);

            SUBCASE("result of empty")
            {
                CHECK(j.empty() == false);
                CHECK(j_const.empty() == false);
            }

            SUBCASE("definition of empty")
            {
                CHECK(j.empty() == (j.begin() == j.end()));
                CHECK(j_const.empty() == (j_const.begin() == j_const.end()));
            }
        }

        SUBCASE("number (unsigned)")
        {
            json j = 23u;
            const json j_const(j);

            SUBCASE("result of empty")
            {
                CHECK(j.empty() == false);
                CHECK(j_const.empty() == false);
            }

            SUBCASE("definition of empty")
            {
                CHECK(j.empty() == (j.begin() == j.end()));
                CHECK(j_const.empty() == (j_const.begin() == j_const.end()));
            }
        }

        SUBCASE("number (float)")
        {
            json j = 23.42;
            const json j_const(j);

            SUBCASE("result of empty")
            {
                CHECK(j.empty() == false);
                CHECK(j_const.empty() == false);
            }

            SUBCASE("definition of empty")
            {
                CHECK(j.empty() == (j.begin() == j.end()));
                CHECK(j_const.empty() == (j_const.begin() == j_const.end()));
            }
        }

        SUBCASE("null")
        {
            json j = nullptr;
            const json j_const(j);

            SUBCASE("result of empty")
            {
                CHECK(j.empty() == true);
                CHECK(j_const.empty() == true);
            }

            SUBCASE("definition of empty")
            {
                CHECK(j.empty() == (j.begin() == j.end()));
                CHECK(j_const.empty() == (j_const.begin() == j_const.end()));
            }
        }
    }

    TEST_CASE("size()")
    {
        SUBCASE("boolean")
        {
            json j = true;
            const json j_const(j);

            SUBCASE("result of size")
            {
                CHECK(j.size() == 1);
                CHECK(j_const.size() == 1);
            }

            SUBCASE("definition of size")
            {
                CHECK(std::distance(j.begin(), j.end()) == j.size());
                CHECK(std::distance(j_const.begin(), j_const.end()) == j_const.size());
                CHECK(std::distance(j.rbegin(), j.rend()) == j.size());
                CHECK(std::distance(j_const.crbegin(), j_const.crend()) == j_const.size());
            }
        }

        SUBCASE("string")
        {
            json j = "hello world";
            const json j_const(j);

            SUBCASE("result of size")
            {
                CHECK(j.size() == 1);
                CHECK(j_const.size() == 1);
            }

            SUBCASE("definition of size")
            {
                CHECK(std::distance(j.begin(), j.end()) == j.size());
                CHECK(std::distance(j_const.begin(), j_const.end()) == j_const.size());
                CHECK(std::distance(j.rbegin(), j.rend()) == j.size());
                CHECK(std::distance(j_const.crbegin(), j_const.crend()) == j_const.size());
            }
        }

        SUBCASE("array")
        {
            SUBCASE("empty array")
            {
                json j = json::array();
                const json j_const(j);

                SUBCASE("result of size")
                {
                    CHECK(j.size() == 0);
                    CHECK(j_const.size() == 0);
                }

                SUBCASE("definition of size")
                {
                    CHECK(std::distance(j.begin(), j.end()) == j.size());
                    CHECK(std::distance(j_const.begin(), j_const.end()) == j_const.size());
                    CHECK(std::distance(j.rbegin(), j.rend()) == j.size());
                    CHECK(std::distance(j_const.crbegin(), j_const.crend()) == j_const.size());
                }
            }

            SUBCASE("filled array")
            {
                json j = {1, 2, 3};
                const json j_const(j);

                SUBCASE("result of size")
                {
                    CHECK(j.size() == 3);
                    CHECK(j_const.size() == 3);
                }

                SUBCASE("definition of size")
                {
                    CHECK(std::distance(j.begin(), j.end()) == j.size());
                    CHECK(std::distance(j_const.begin(), j_const.end()) == j_const.size());
                    CHECK(std::distance(j.rbegin(), j.rend()) == j.size());
                    CHECK(std::distance(j_const.crbegin(), j_const.crend()) == j_const.size());
                }
            }
        }

        SUBCASE("object")
        {
            SUBCASE("empty object")
            {
                json j = json::object();
                const json j_const(j);

                SUBCASE("result of size")
                {
                    CHECK(j.size() == 0);
                    CHECK(j_const.size() == 0);
                }

                SUBCASE("definition of size")
                {
                    CHECK(std::distance(j.begin(), j.end()) == j.size());
                    CHECK(std::distance(j_const.begin(), j_const.end()) == j_const.size());
                    CHECK(std::distance(j.rbegin(), j.rend()) == j.size());
                    CHECK(std::distance(j_const.crbegin(), j_const.crend()) == j_const.size());
                }
            }

            SUBCASE("filled object")
            {
                json j = {{"one", 1}, {"two", 2}, {"three", 3}};
                const json j_const(j);

                SUBCASE("result of size")
                {
                    CHECK(j.size() == 3);
                    CHECK(j_const.size() == 3);
                }

                SUBCASE("definition of size")
                {
                    CHECK(std::distance(j.begin(), j.end()) == j.size());
                    CHECK(std::distance(j_const.begin(), j_const.end()) == j_const.size());
                    CHECK(std::distance(j.rbegin(), j.rend()) == j.size());
                    CHECK(std::distance(j_const.crbegin(), j_const.crend()) == j_const.size());
                }
            }
        }

        SUBCASE("number (integer)")
        {
            json j = -23;
            const json j_const(j);

            SUBCASE("result of size")
            {
                CHECK(j.size() == 1);
                CHECK(j_const.size() == 1);
            }

            SUBCASE("definition of size")
            {
                CHECK(std::distance(j.begin(), j.end()) == j.size());
                CHECK(std::distance(j_const.begin(), j_const.end()) == j_const.size());
                CHECK(std::distance(j.rbegin(), j.rend()) == j.size());
                CHECK(std::distance(j_const.crbegin(), j_const.crend()) == j_const.size());
            }
        }

        SUBCASE("number (unsigned)")
        {
            json j = 23u;
            const json j_const(j);

            SUBCASE("result of size")
            {
                CHECK(j.size() == 1);
                CHECK(j_const.size() == 1);
            }

            SUBCASE("definition of size")
            {
                CHECK(std::distance(j.begin(), j.end()) == j.size());
                CHECK(std::distance(j_const.begin(), j_const.end()) == j_const.size());
                CHECK(std::distance(j.rbegin(), j.rend()) == j.size());
                CHECK(std::distance(j_const.crbegin(), j_const.crend()) == j_const.size());
            }
        }

        SUBCASE("number (float)")
        {
            json j = 23.42;
            const json j_const(j);

            SUBCASE("result of size")
            {
                CHECK(j.size() == 1);
                CHECK(j_const.size() == 1);
            }

            SUBCASE("definition of size")
            {
                CHECK(std::distance(j.begin(), j.end()) == j.size());
                CHECK(std::distance(j_const.begin(), j_const.end()) == j_const.size());
                CHECK(std::distance(j.rbegin(), j.rend()) == j.size());
                CHECK(std::distance(j_const.crbegin(), j_const.crend()) == j_const.size());
            }
        }

        SUBCASE("null")
        {
            json j = nullptr;
            const json j_const(j);

            SUBCASE("result of size")
            {
                CHECK(j.size() == 0);
                CHECK(j_const.size() == 0);
            }

            SUBCASE("definition of size")
            {
                CHECK(std::distance(j.begin(), j.end()) == j.size());
                CHECK(std::distance(j_const.begin(), j_const.end()) == j_const.size());
                CHECK(std::distance(j.rbegin(), j.rend()) == j.size());
                CHECK(std::distance(j_const.crbegin(), j_const.crend()) == j_const.size());
            }
        }
    }

    TEST_CASE("max_size()")
    {
        SUBCASE("boolean")
        {
            json j = true;
            const json j_const(j);

            SUBCASE("result of max_size")
            {
                CHECK(j.max_size() == 1);
                CHECK(j_const.max_size() == 1);
            }
        }

        SUBCASE("string")
        {
            json j = "hello world";
            const json j_const(j);

            SUBCASE("result of max_size")
            {
                CHECK(j.max_size() == 1);
                CHECK(j_const.max_size() == 1);
            }
        }

        SUBCASE("array")
        {
            SUBCASE("empty array")
            {
                json j = json::array();
                const json j_const(j);

                SUBCASE("result of max_size")
                {
                    CHECK(j.max_size() >= j.size());
                    CHECK(j_const.max_size() >= j_const.size());
                }
            }

            SUBCASE("filled array")
            {
                json j = {1, 2, 3};
                const json j_const(j);

                SUBCASE("result of max_size")
                {
                    CHECK(j.max_size() >= j.size());
                    CHECK(j_const.max_size() >= j_const.size());
                }
            }
        }

        SUBCASE("object")
        {
            SUBCASE("empty object")
            {
                json j = json::object();
                const json j_const(j);

                SUBCASE("result of max_size")
                {
                    CHECK(j.max_size() >= j.size());
                    CHECK(j_const.max_size() >= j_const.size());
                }
            }

            SUBCASE("filled object")
            {
                json j = {{"one", 1}, {"two", 2}, {"three", 3}};
                const json j_const(j);

                SUBCASE("result of max_size")
                {
                    CHECK(j.max_size() >= j.size());
                    CHECK(j_const.max_size() >= j_const.size());
                }
            }
        }

        SUBCASE("number (integer)")
        {
            json j = -23;
            const json j_const(j);

            SUBCASE("result of max_size")
            {
                CHECK(j.max_size() == 1);
                CHECK(j_const.max_size() == 1);
            }
        }

        SUBCASE("number (unsigned)")
        {
            json j = 23u;
            const json j_const(j);

            SUBCASE("result of max_size")
            {
                CHECK(j.max_size() == 1);
                CHECK(j_const.max_size() == 1);
            }
        }

        SUBCASE("number (float)")
        {
            json j = 23.42;
            const json j_const(j);

            SUBCASE("result of max_size")
            {
                CHECK(j.max_size() == 1);
                CHECK(j_const.max_size() == 1);
            }
        }

        SUBCASE("null")
        {
            json j = nullptr;
            const json j_const(j);

            SUBCASE("result of max_size")
            {
                CHECK(j.max_size() == 0);
                CHECK(j_const.max_size() == 0);
            }
        }
    }
}
