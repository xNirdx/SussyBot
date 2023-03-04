#include <sajf/sajf.h>
#include <dpp/dpp.h>

sajf::command::command() {
    this->set_name("command");
    this->set_description("Generic command that doesn't do anything");
}

void sajf::command::execute(dpp::slashcommand_t &event) {
    event.reply("This command has not yet been configured.");
}