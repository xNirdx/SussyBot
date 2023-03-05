#pragma once

// Sajf library includes
#include <sajf/sajf.h>

// Standard library includes
#include <string>
#include <vector>
#include <unordered_map>

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

            /* An unordered map which stores the song queues
             * of all the bot's guilds by the guild ID */
            std::unordered_map<dpp::snowflake, sajf::queue> song_queues;

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

            void play(sajf::song song);
    };

}