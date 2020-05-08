import 'dart:html';
import 'lib/accelerometer.dart';
import 'lib/notification.dart';
import 'lib/camera.dart';
import 'dart:js' as js;

void main() {
  querySelector("#sample_text_id").text = "Hello from dart";
  var jsDocument = (js.context['document']);
  document.on['deviceready'].listen(deviceReady);
}

void deviceReady(event) {
  querySelector("#accel").style.height = "100px";
  print("event = $event");
  print("device is ready");
  querySelector("body").style.backgroundColor = "aliceblue";
  window.alert('Cordova loaded');
  querySelector("#camera_btn").onClick.listen(( MouseEvent evt){
    camera.getPicture(onCameraSuccess, onCameraError);  
  });
  querySelector("#vibrate_btn").onClick.listen(( MouseEvent evt){
    notification.vibrate(7000);
  });
  querySelector("#beep_btn").onClick.listen(( MouseEvent evt){
    notification.beep(3);  
  });
  accessAccelerometer();
  //contactsTest();
}

void accessAccelerometer() {
  var id = accelerometer.watchAcceleration(
    (Acceleration acc) {
    querySelector("#accel").text = 'Accelerometer\n' + 'x:${acc.x}\n' + 'y:${acc.y}\n' + 'z:${acc.z}\n';
      
    },
    () => js.context.callMethod('alert', ['Failed!']),
    new AccelerometerOptions()
  );
}

void onCameraSuccess(String imageData)
{
  
}

void onCameraError(String error)
{
  
}