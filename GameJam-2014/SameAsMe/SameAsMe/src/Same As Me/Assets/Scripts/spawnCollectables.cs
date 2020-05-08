using UnityEngine;
using System.Collections;

public class spawnCollectables : MonoBehaviour {
	
	public Transform smallHealtyObject;
	public Transform bigHealtyObject;
	public Transform smallToxicObject;
	public Transform bigToxicObject;
	public Transform boosterDarkenObject;
	public Transform boosterFreezeObject;
	public Transform boosterMistakenObject;
	
	public static	int segmentLength 				= 	5;
	public static	int levelLength					=	340;
	private 		int availableSegments 			= 	levelLength / segmentLength;

	public		 	int percentSmallHealthBoost 	= 	85;
	public 			int percentSmallToxicBoost		=  	85;
	public 			int	percentBoosterOne			= 	40;
	public 			int percentBoosterTwo			= 	40;
	private 		int	currentHealthBoost			=	0;
	private 		int	currentToxicBoost			=	0;
	private 		int currentBooster				=	0;
	private 		int boosterToPlayer				=	0;

	public			int maxCollectableHeight		=	3;
	public 			float healthXCoordinate 		= 	0;
	public 			float toxicXCoordinate 			= 	0;
	public 			float boosterXCoordinate		= 	0;
	public 			float healthYCoordinate 		= 	0;
	public 			float toxicYCoordinate 			= 	0;
	public 			float boosterYCoordinate 		= 	0;
	private 	 	float healthZCoordinate			= 	0;
	private 	 	float toxicZCoordinate		 	= 	-6f;
	private 	 	float boosterZCoordinate	 	= 	0;
	
	// Use this for initialization
	void Start () {

		createHealtyObjects ();
		createToxicObjects ();
		createBoosters ();
	}

	// Update is called once per frame
	void Update () {

	}


	private void createHealtyObjects() {

		for (int i = 0; i < availableSegments; i++) {

			currentHealthBoost = Random.Range(1, 100);

			healthXCoordinate = i*segmentLength + Random.Range(1, segmentLength);
			healthXCoordinate *= -1;

			healthYCoordinate = Random.Range(0, maxCollectableHeight);
			healthYCoordinate += 3;

			if (currentHealthBoost <= percentSmallHealthBoost) {
				Instantiate(smallHealtyObject, new Vector3(healthXCoordinate,healthYCoordinate,healthZCoordinate), transform.rotation);
			} else {
				Instantiate(bigHealtyObject, new Vector3(healthXCoordinate,healthYCoordinate,healthZCoordinate), transform.rotation);
			}
		}
	}

	private void createToxicObjects () {

		for (int i = 0; i < availableSegments; i++) {

			currentToxicBoost = Random.Range(1, 100);

			toxicXCoordinate = i*segmentLength + Random.Range(1, segmentLength);
			toxicXCoordinate *= -1;

			toxicYCoordinate = Random.Range(0, maxCollectableHeight);
			toxicYCoordinate += 6;

			if (currentToxicBoost <= percentSmallToxicBoost) {
				Instantiate(smallToxicObject, new Vector3(toxicXCoordinate,toxicYCoordinate,toxicZCoordinate), transform.rotation);
			} else {
				Instantiate(bigToxicObject, new Vector3(toxicXCoordinate, toxicYCoordinate, toxicZCoordinate), transform.rotation);
			}
		}
	}

	private void createBoosters () {

		int customAvailableSegments = 0;
		customAvailableSegments = availableSegments / 3;
		for (int i = 0; i < customAvailableSegments; i++) {

			boosterToPlayer = Random.Range(1,3);
			if (boosterToPlayer == 1) {
				boosterXCoordinate = i*segmentLength*3 + Random.Range(1, segmentLength*3);
				boosterXCoordinate *= -1;
				boosterYCoordinate = Random.Range(0, maxCollectableHeight);
				boosterYCoordinate += 3;
				boosterZCoordinate = 0f;
			} else {
				boosterXCoordinate = i*segmentLength*3 + Random.Range(1, segmentLength*3);
				boosterXCoordinate *= -1;
				boosterYCoordinate = Random.Range(0, maxCollectableHeight);
				boosterYCoordinate += 6;
				boosterZCoordinate = -6f;
			}

			currentBooster = Random.Range(1, 100);

			if (currentBooster <= percentBoosterOne) {
				Instantiate(boosterMistakenObject, new Vector3(boosterXCoordinate,boosterYCoordinate,boosterZCoordinate), transform.rotation);
			} else if (currentBooster > percentBoosterOne && currentBooster <= percentBoosterOne+percentBoosterTwo) {
				Instantiate(boosterFreezeObject, new Vector3(boosterXCoordinate, boosterYCoordinate, boosterZCoordinate), transform.rotation);
			} else {
				Instantiate(boosterDarkenObject, new Vector3(boosterXCoordinate, boosterYCoordinate, boosterZCoordinate), transform.rotation);
			}
		}
	}
}
