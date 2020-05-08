using UnityEngine;
using System.Collections;

public class cameraMovement : MonoBehaviour {

	public 			float 	cameraSpeed 			= 	0.025f;
	public 	static 	int 	smallHealthyItemValue 	= 	100;
	public 	static 	int 	bigHealthyItemValue	 	= 	50;
	public 	static 	int 	smallToxicItemValue 	= 	100;
	public 	static 	int 	bigToxicItemValue	 	= 	50;

	// Use this for initialization
	void Start () {
		InvokeRepeating ("MoveCamera", 0.025f, 0.025f);
	}
	
	// Update is called once per frame
	void Update () {

	}

	void MoveCamera() {
		if(Camera.main != null) {
			Camera.main.transform.Translate(new Vector3(cameraSpeed, 0, 0));
		}
	}
}