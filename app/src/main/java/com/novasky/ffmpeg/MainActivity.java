package com.novasky.ffmpeg;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    private FFmpegUtil fFmpegUtil;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

         fFmpegUtil=new FFmpegUtil();
        // Example of a call to a native method
        TextView tv = findViewById(R.id.tv_name);
        tv.setText(fFmpegUtil.stringFromJNI());

        tv.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Toast.makeText(MainActivity.this,"调用结果："+fFmpegUtil.FFNovaPushInit(),Toast.LENGTH_LONG).show();
            }
        });

    }
}
