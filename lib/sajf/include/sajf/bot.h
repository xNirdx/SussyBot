#pragma once

// Sajf library includes
#include <sajf/sajf.h>

// Standard library includes
#include <string>
#include <vector>

// D++ library includes
#include <dpp/dpp.h>

namespace sajf {

    class bot {
        private:
            // Bot token
            std::string bot_token;

            // Vector holding bot commands
            std::vector<sajf::command *> bot_commands;

            // Bot ID
            dpp::snowflake bot_id;

        public:
            // Determines whether logging is enabled or not
            bool logging = false;

            // Constructor
            bot(const std::string bot_token);

            // Start the bot
            void start();

            // Create a bot command
            void add_command(sajf::command *command);

            // Registers the bot commands globally
            void register_commands(dpp::cluster &bot);

            void command_handler(dpp::slashcommand_t event);
    };

}