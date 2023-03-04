#include <sajf/sajf.h>
#include <dpp/dpp.h>
#include <vector>
#include <json.hpp>
#include <iostream>
#include <fstream>
#include <commands.h>

std::ifstream config("../config.json");
nlohmann::json config_data = nlohmann::json::parse(config);

int main() {
    sajf::bot bot(config_data["bot_token"]);

    bot.logging = true;

    std::vector<sajf::command *> commands = {
        new Play
    };

    for (int i = 0; i < commands.size(); i++) {
        sajf::command *curr_cmd = commands.at(i);

        bot.add_command(curr_cmd);
    }

    bot.start();
}