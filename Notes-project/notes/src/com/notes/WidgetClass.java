package com.notes;


import org.apache.cordova.SplashScreen;

import android.app.Activity;
import android.app.PendingIntent;
import android.appwidget.AppWidgetProvider;
import android.appwidget.AppWidgetManager;
import android.content.ComponentName;
import android.content.Context;
import android.content.DialogInterface;
import android.content.DialogInterface.OnClickListener;
import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.webkit.WebView;
import android.widget.Button;
import android.widget.RemoteViews;
import android.widget.Toast;

public class WidgetClass extends AppWidgetProvider {
	
	@Override
	public void onDeleted(Context context, int[] appWidgetIds){

		super.onDeleted(context, appWidgetIds);
		Toast.makeText(context, "Deleted", Toast.LENGTH_SHORT).show();	

	}

	@Override
	public void onUpdate(Context context, AppWidgetManager appWidgetManager, int[] appWidgetIds){

		super.onUpdate(context, appWidgetManager, appWidgetIds);
		 
	
	}
}

