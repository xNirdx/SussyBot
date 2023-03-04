#include <commands.h>
#include <dpp/dpp.h>

Play::Play() {
    this->set_name("play");
    this->set_description("Play a song from YouTube or Spotify.");
}

void Play::execute(dpp::slashcommand_t &event) {
    //TODO: implement play functionality
}