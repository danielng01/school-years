using UnityEngine;
using System.Collections;

public class backToMainMenu : MonoBehaviour {

	// Use this for initialization
	void Start ()
	{
		Invoke ("Transition", 7.5f);
	}
	
	// Update is called once per frame
	void Update ()
	{
		
	}
	
	void Transition () {
		Application.LoadLevel ("MainMenu");
	}
}
