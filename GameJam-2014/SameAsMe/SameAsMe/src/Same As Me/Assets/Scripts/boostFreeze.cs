using UnityEngine;
using System.Collections;

public class boostFreeze : MonoBehaviour {
	
	// Use this for initialization
	void Start () {
	
	}
	
	// Update is called once per frame
	void Update () {
	
	}

	void OnTriggerEnter(Collider other) {

		if (other.transform.name == "Player1") { 
			ControllerPlayer2.frozen = true;
			Destroy (gameObject);
		}

		if (other.transform.name == "Player2") {
			ControllerPlayer1.frozen = true;
			Destroy (gameObject);
		}
	}
}
