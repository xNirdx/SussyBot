#pragma once

#include <string>
#include <dpp/dpp.h>

namespace sajf {

    class command: public dpp::slashcommand {
        public:
            // Constructor
            command();

            /* The code which should be executed
             * when the command is used */
            virtual void execute(dpp::slashcommand_t &event);
    };

}