using UnityEngine;
using System.Collections;

public class ControllerPlayer1 : MonoBehaviour {

					bool 	isGrounded 		= 	true;
	public 			int 	speed			= 	50;
	public 			int 	jumpSpeed 		= 	15;
	public 			int		boostDuration	=	3;
	public	static 	bool	frozen 			= 	false;
	public	static 	bool	confused 		= 	false;
	public	static 	bool	darked 			= 	false;

	// Use this for initialization
	void Start () {
	
	}
	
	// Update is called once per frame
	void Update () {

		GetComponentInChildren<Animation>().PlayQueued("Idle");
		if(Input.GetKey(KeyCode.RightArrow)) {
			if (frozen) {
				StartCoroutine(freeze());
			} else if (confused) {
				moveLeft();
				StartCoroutine(confuse());
			} else {
				moveRight();
			}
		} else if (Input.GetKey(KeyCode.LeftArrow)) {
			if (frozen) {
				StartCoroutine(freeze());
			} else if (confused) {
				moveRight();
				StartCoroutine(confuse());
			} else {
				moveLeft();
			}
		}
		if(Input.GetKeyDown(KeyCode.UpArrow)) {
			if (frozen) {
				StartCoroutine(freeze());
			} else {
				jump();
			}
		}
		if(darked) {
			makeScreenDark();
			StartCoroutine(endark());
		}
	}

	void OnCollisionEnter(Collision col){
		if (col.transform.name == "EndGame") {
			Application.LoadLevel ("EndScene1");
		}
		if (col.transform.tag == "floor") {
			isGrounded = true;
		}
	}

	void moveLeft() {
		rigidbody.AddForce(speed,0,0);
		GetComponentInChildren<Animation>().Stop("Idle");
		GetComponentInChildren<Animation>().Stop("Run");
		GetComponentInChildren<Animation>().Play("RunReverse");
	}

	void moveRight() {
		rigidbody.AddForce(-speed,0,0);
		GetComponentInChildren<Animation>().Stop("Idle");
		GetComponentInChildren<Animation>().Stop("RunReverse");
		GetComponentInChildren<Animation>().Play("Run");
	}

	void jump() {
		if(isGrounded) {
			rigidbody.AddForce(0,jumpSpeed,0,ForceMode.Impulse);
			GetComponentInChildren<Animation>().Stop("Idle");
			GetComponentInChildren<Animation>().Stop("Run");
			GetComponentInChildren<Animation>().Stop("RunReverse");
			GetComponentInChildren<Animation>().Play("Jump");
			isGrounded = false;
		}
	}

	IEnumerator confuse(){
		yield return new WaitForSeconds(boostDuration);
		confused = false;
	}
	
	IEnumerator freeze(){
		yield return new WaitForSeconds(boostDuration);
		frozen = false;
	}



	public IEnumerator  multiplySpeed(){
		speed *= 20;
		yield return new WaitForSeconds (2);
		speed /= 20;
	}
	void makeScreenDark() {
		GameObject DarkenCamera;
		DarkenCamera = GameObject.Find("DarkenPlaneDown");
		DarkenCamera.GetComponent<MeshRenderer> ().enabled = true;
	}
	IEnumerator endark(){
		yield return new WaitForSeconds(boostDuration);
		GameObject DarkenCamera;
		DarkenCamera = GameObject.Find("DarkenPlaneDown");
		DarkenCamera.GetComponent<MeshRenderer> ().enabled = false;
		darked = false;
	}
}
