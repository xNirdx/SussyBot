#pragma once

#include <string>
#include <dpp/dpp.h>

namespace sajf {

    class song {
        public:
            std::string url;
            dpp::snowflake guild_id;

            song(std::string url, dpp::snowflake guild_id);
    };

}