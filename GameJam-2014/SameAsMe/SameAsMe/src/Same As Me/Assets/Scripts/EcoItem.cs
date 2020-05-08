using UnityEngine;
using System.Collections;

public class EcoItem : MonoBehaviour {

	// Use this for initialization
	void Start () {
	
	}
	
	// Update is called once per frame
	void Update () {
	
	}
	
	void OnTriggerEnter(Collider other) {
		if (other.transform.name == "Player1") {
			Debug.Log("Player 1 picked up small Healthy item - gets" + cameraMovement.smallHealthyItemValue + "points");
			Score.player1Score += cameraMovement.smallHealthyItemValue;
			Destroy (gameObject);
		}
		if (other.transform.name == "Player2") {
			Debug.Log("Player 2 picked up small Healthy item  - nothing happens");
			Destroy (gameObject);
		}
	}
}
