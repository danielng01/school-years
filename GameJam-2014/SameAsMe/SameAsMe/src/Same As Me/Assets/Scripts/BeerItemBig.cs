using UnityEngine;
using System.Collections;

public class BeerItemBig : MonoBehaviour {

	// Use this for initialization
	void Start () {
	
	}
	
	// Update is called once per frame
	void Update () {
	
	}

	void OnTriggerEnter(Collider other) {
		if (other.transform.name == "Player1") {
			Debug.Log("Player 1 picked up big Toxic item  - nothing happens");
			Destroy (gameObject);
		}
		if (other.transform.name == "Player2") {
			Debug.Log("Player 2 picked up big Toxic item - gets" + cameraMovement.bigToxicItemValue + "points");
			Score.player2Score += cameraMovement.bigToxicItemValue;
			Destroy (gameObject);
		}
	}
}
