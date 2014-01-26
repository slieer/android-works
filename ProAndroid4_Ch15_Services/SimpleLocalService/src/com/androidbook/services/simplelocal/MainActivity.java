package com.androidbook.services.simplelocal;

// MainActivity.java
import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.util.Log;
import android.view.View;
import android.widget.Button;

public class MainActivity extends Activity
{
    private static final String TAG = "MainActivity";
    private int counter = 1;

    @Override
    public void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);
        
        hand = new MyHandler(this);
    }

    public void doClick(View view) {
        switch(view.getId()) {
        case R.id.startBtn:
            Log.i(TAG, "Starting service... counter = " + counter);
            Intent intent = new Intent(MainActivity.this,
                    BackgroundService.class);
            intent.putExtra("counter", counter++);
            startService(intent);
            break;
        case R.id.stopBtn:
            stopService();
        }
    }

    private void stopService() {
    	Log.i(TAG, "Stopping service...");
        if(stopService(new Intent(MainActivity.this,
                    BackgroundService.class)))
        	Log.i(TAG, "stopService was successful");
        else
        	Log.i(TAG, "stopService was unsuccessful");
    }

    @Override
    public void onDestroy()
    {
    	stopService();
        super.onDestroy();
    }
    
    public static MyHandler hand = null;
    
    /**
     * @author slieer 2013-6-13
     */
    public static class MyHandler extends Handler{
        Activity act;
        public MyHandler(Activity act){
            this.act = act;
        }
        public void handleMessage(Message msg) {
            Button b = (Button)act.findViewById(R.id.startBtn);
            String val = b.getText().toString();
            Log.i(TAG, "val.equals start ?" + val.equals("start"));
            if(val.equals("Start")){
                b.setText("Start Service");
            }else{
                b.setText("Start");
            }
        };
    }
}
