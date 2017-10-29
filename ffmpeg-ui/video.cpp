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

QString Video::duration() const {

    int64_t d = fmt_ctx->duration;

    int hours, mins, secs, us;
    secs = d / AV_TIME_BASE;
    us = d % AV_TIME_BASE;
    mins = secs / 60;
    secs %= 60;
    hours = mins / 60;
    mins %= 60;

    return QString("%1:%2:%3.%4")
            .arg(
                QString::number(hours),
                QString::number(mins),
                QString::number(secs),
                QString::number((10 * us) / AV_TIME_BASE));
}
