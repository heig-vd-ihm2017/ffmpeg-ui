#include "video.h"

#include <stdexcept>

Video::Video(const char *filename) {
   av_register_all();

   // Open file
   if (avformat_open_input(&fmt_ctx, filename, NULL, NULL)) {
      throw std::runtime_error("Cannot open input file");
   }
}

Video::~Video() {
   avformat_close_input(&fmt_ctx);
}

int64_t Video::duration() const {
   return fmt_ctx->duration;
}
