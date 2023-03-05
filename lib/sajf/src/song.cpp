#include <song.h>
#include <string>
#include <dpp/dpp.h>

sajf::song::song(std::string url, dpp::snowflake guild_id) {
    this->url = url;
    this->guild_id = guild_id;
}