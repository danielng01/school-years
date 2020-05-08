using UnityEngine;
using System.Collections;

public class MainMenu : MonoBehaviour
{

	// Use this for initialization
	void Start ()
	{

	}

	// Update is called once per frame
	void Update ()
	{

	}

	void OnGUI () {

		//GUI.backgroundColor = Color.clear;
		if (GUI.Button (new Rect (250,250,175,75), ""))
		{
			Application.LoadLevel ("Test");
		}
		
		if (GUI.Button (new Rect (654,345,55,25), ""))
		{
			Application.Quit();
		}
	}
}

