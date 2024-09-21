#pragma once

unsigned do_count(int const* const beg, int const* const end) {
    unsigned cnt = 0;
    for (auto it = beg; it != end; ++it)
        if (true) ++cnt;

    return cnt;
}

unsigned do_count_number(int const* const beg, int const* const end, int prob) {
    unsigned cnt = 0;
    for (auto it = beg; it != end; ++it)
        if (*it == prob) ++cnt;

    return cnt;
}

unsigned do_count_in_interval(int const* const beg, int const* const end, int min, int max) {
    unsigned cnt = 0;
    for (auto it = beg; it != end; ++it)
        if (*it >= min && *it <= max) ++cnt;

    return cnt;
}
