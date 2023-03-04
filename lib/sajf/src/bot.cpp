// Sajf library includes
#include <sajf/sajf.h>

// Standard library includes
#include <string>

// D++ library includes
#include <dpp/dpp.h>

sajf::bot::bot(const std::string bot_token) {
    this->bot_token = bot_token;
}

void sajf::bot::start() {
    dpp::cluster dpp_bot(this->bot_token);

    this->bot_id = dpp_bot.me.id;

    if (this->logging) dpp_bot.on_log(dpp::utility::cout_logger());

    dpp_bot.on_slashcommand([this](const dpp::slashcommand_t &event) {
        this->command_handler(event);
    });

    dpp_bot.on_ready([&dpp_bot, this](const dpp::ready_t &event) {
        if (dpp::run_once<struct register_bot_commands()>) {
            this->register_commands(dpp_bot);
        }
    });

    dpp_bot.start(dpp::st_wait);
}

void sajf::bot::add_command(sajf::command *command) {
    command->set_application_id(this->bot_id);

    this->bot_commands.push_back(command);
}

void sajf::bot::register_commands(dpp::cluster &bot) {
    for (int i = 0; i < this->bot_commands.size(); i++) {
        sajf::command *curr_cmd = this->bot_commands.at(i);

        bot.global_command_create(
            dpp::slashcommand(
                curr_cmd->name,
                curr_cmd->description,
                curr_cmd->application_id
            )
        );
    }
}

void sajf::bot::command_handler(dpp::slashcommand_t event) {
    for (int i = 0; i < this->bot_commands.size(); i++) {
        sajf::command *curr_cmd = this->bot_commands.at(i);

        if (curr_cmd->name == event.command.get_command_name()) {
            curr_cmd->execute(event);
        }
    };
}