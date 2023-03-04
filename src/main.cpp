#include <sajf/sajf.h>
#include <dpp/dpp.h>
#include <vector>

#include <commands.h>

// TODO: Read token from json config file

int main() {
    sajf::bot bot(BOT_TOKEN);

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