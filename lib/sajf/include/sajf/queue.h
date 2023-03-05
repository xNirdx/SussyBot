#pragma once

#include <vector>
#include <string>
#include <song.h>

namespace sajf {

    class queue {
        public:
            // Vector which holds song objects
            std::vector<sajf::song> queue;

            // Adds a song to the queue
            void add(sajf::song song);

            // Clears the queue of all songs
            void clear();
    };

}