part of capture;
//WORK IN PROGRESS
/** The media file data */
class MediaFileData {
  /** the actual format of the audio/video contents */
  String codecs;
  /** The average bitrate of the content; image is always 0 */
  double bitrate;
  /** The height of the image/video in pixels; for sound clip always 0 */
  int height;
  /** the width of the image/video in pixels; for sound clip always 0 */
  int width;
  /** The length of audio/video clip in seconds; image is always 0 */
  int duration;

  MediaFileData.fromProxy(js.Proxy p)
      : this.codecs = p.codecs,
        this.bitrate = p.bitrate,
        this.height = p.height,
        this.width = p.width,
        this.duration = p.duration;
}
