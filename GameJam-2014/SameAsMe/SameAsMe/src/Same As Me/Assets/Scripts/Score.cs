using UnityEngine;
using System.Collections;

public class Score : MonoBehaviour {

	public 	static	int 	player1Score 			= 	0;
	public 	static 	int 	player2Score 			= 	0;
	
	void OnGUI () {
		GUI.Box (new Rect (0,0,123,25), "Player1 score:" + player2Score);
		GUI.Box (new Rect (0,Screen.height/2 - 12,123,25), "Player2 score:" + player1Score);
	}
}