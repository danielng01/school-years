using UnityEngine;
using System.Collections;

public class SpeedPowerUp : MonoBehaviour {

	// Use this for initialization
	void Start () {
	
	}
	
	// Update is called once per frame
	void Update () {
	
	}
	void OnTriggerEnter(Collider other){
		if (other.name == "Player1") {
			ControllerPlayer1 controller = other.GetComponent<ControllerPlayer1>();
			controller.multiplySpeed();
			Destroy (gameObject);

		}
		if (other.name == "Player2") {
			ControllerPlayer2 controller = other.GetComponent<ControllerPlayer2>();
			controller.multiplySpeed();
			Destroy (gameObject);
		}
	}
}
