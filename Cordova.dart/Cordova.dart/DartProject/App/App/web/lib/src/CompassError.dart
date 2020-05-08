part of compass;
//WORK IN PROGRESS
/** Error returned when failed to get the heading information from the
 * [Compass] service.
 */
class CompassError {
  static final int COMPASS_INTERNAL_ERR = 0;
  static final int COMPASS_NOT_SUPPORTED = 20;

  final int code;

  CompassError.fromProxy(js.Proxy p)
      : this.code = p.code;
}
