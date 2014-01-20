extern const char* leveldbd_build_info_string;
struct leveldbd_build_info{ const char* operator()() const { return leveldbd_build_info_string;} };
