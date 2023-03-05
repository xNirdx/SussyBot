#include <commands.h>
#include <dpp/dpp.h>
#include <sajf/sajf.h>

Play::Play() {
    this->set_name("play");
    this->set_description("Play a song from YouTube or Spotify.");
}

void Play::execute(dpp::slashcommand_t &event) {
    // Get the guild in which the command was invoked
    dpp::guild g = event.command.get_guild();

    // Get the voice connection object for the bot in that guild
    dpp::voiceconn *vc = event.from->get_voice(g.id);

    sajf::song song("songlink", g.id);
}