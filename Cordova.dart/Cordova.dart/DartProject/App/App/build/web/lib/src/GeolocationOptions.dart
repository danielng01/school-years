part of geolocation;
//WORK IN PROGRESS
/** Options used with [Geolocation.getCurrentPosition] and
 * [Geolocation.watchPosition] methods.
 */
class GeolocationOptions {
  /** Frequency to retrieve a Position information; default 10000 */
  int frequency;
  /** maximum time allowed in millisecond trying to retrieve a valid Position back */
  int timeout;
  /** maximum cached time in millisecond for a position */
  int maximumAge;
  /** Hint requesting best accuracy Position */
  bool enableHighAccuracy;

  GeolocationOptions({this.frequency : 10000, this.enableHighAccuracy : true,
                      this.timeout, this.maximumAge});

  Map _toMap()
  => {'frequency' : frequency, 'enableHighAccuracy' : enableHighAccuracy,
      'timeout' : timeout, 'maximumAge' : maximumAge};
}
