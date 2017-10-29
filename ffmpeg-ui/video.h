#ifndef VIDEO_H
#define VIDEO_H

#ifdef __cplusplus
extern "C"
{
    #include <libavcodec/avcodec.h>
    #include <libavformat/avformat.h>
    #include <libswscale/swscale.h>
}
#endif

class Video {

private:
   AVFormatContext *fmt_ctx = NULL;

public:
   Video(const char *filename);
   ~Video();

   int64_t duration() const;


};

#endif // VIDEO_H
