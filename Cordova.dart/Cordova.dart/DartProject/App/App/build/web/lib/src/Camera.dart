part of camera;

typedef CameraSuccessCB(String imageData);
typedef CameraErrorCB(String message);
typedef CleanupSuccessCB();

/** Singleton Camera. */
Camera camera = new Camera._internal();

/**
 * Access to the camera application of this device.
 */
class Camera {
  js.JsObject _camera;

  factory Camera() => camera;

  Camera._internal() {
    _camera = js.context['navigator']['camera'];
    if (_camera == null)
    {
      throw new StateError('Not ready yet.');
    }
  }

  /**
  * Takes a photo using the camera or retrieves a photo from the device's
  * album based on the cameraOptoins paremeter. Returns the image as a
  * base64 encoded String or as the URI of an image file.
  */
  void getPicture(CameraSuccessCB success,
      CameraErrorCB error, [CameraOptions options]) {
      var ok = (p) => success(p);
      var fail = error;
      //var opts = options == null ? null : js.map(options._toMap());
      _camera.callMethod('getPicture', [ok, fail]);
  }
}
