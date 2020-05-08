using UnityEngine;
using System.Collections;

public class OutroSceneCamera : MonoBehaviour
{
	public MovieTexture movTexture;


	// Use this for initialization
	void Start ()
	{
		renderer.material.mainTexture = movTexture;
		movTexture.Play();
		Invoke ("Transition", 10f);
	}

	// Update is called once per frame
	void Update ()
	{
		if(Input.anyKey) {
			Application.LoadLevel ("MainMenu");
		}

	}

	void Transition () {
		Application.LoadLevel ("MainMenu");
	}
}

