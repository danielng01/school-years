using UnityEngine;
using System.Collections;

public class EcoItemBig : MonoBehaviour {

	// Use this for initialization
	void Start () {
	
	}
	
	// Update is called once per frame
	void Update () {
	
	}

	void OnTriggerEnter(Collider other) {
		if (other.transform.name == "Player1") {
			Debug.Log("Player 1 picked up big Healthy item - gets" + cameraMovement.bigHealthyItemValue + "points");
			Score.player1Score += cameraMovement.bigHealthyItemValue;
			Destroy (gameObject);
		}
		if (other.transform.name == "Player2") {
			Debug.Log("Player 2 picked up big Healthy item  - nothing happens");
			Destroy (gameObject);
		}
	}
}
