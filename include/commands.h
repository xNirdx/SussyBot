#pragma once

#include <sajf/sajf.h>
#include <dpp/dpp.h>

class Play: public sajf::command {
    public:
        Play();

        void execute(dpp::slashcommand_t &event);
};