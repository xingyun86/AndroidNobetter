package com.nobetter.ppshuai.androidnobetter;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("nativehelper-lib");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Example of a call to a native method
        TextView tv = (TextView) findViewById(R.id.sample_text);
        tv.setText(NativeHelper.getInstance().stringFromJNI());

        Button bt = (Button) findViewById(R.id.test_button);
        //1.匿名内部类
        bt.setOnClickListener(new View.OnClickListener() {

            @Override
            public void onClick(View v) {
                // TODO Auto-generated method stub
                Log.i("匿名内部类", "点击按钮一次");
                NativeHelper.getInstance().TestSendImageData();
                //stringFromJNI();
                //获取写数据库
                //DBCipherHelper dbHelper = new DBCipherHelper(MainActivity.this);
                //SQLiteDatabase db = dbHelper.getWritableDatabase(DBCipherHelper.DB_PWD);
                //NativeHelper.getInstance().sendImageData("http://192.168.1.30/wxmsg", "{\"message\":\"撒旦发\",\"receive_alias\":\"\",\"send\":\"wxid_knot9kldi4qm22\",\"this_wx\":\"wxid_knot9kldi4qm22\",\"alias\":\"\",\"device\":\"867826022413298\",\"msg_id\":\"6247022675505186877\",\"create_at\":\"1487842223000\",\"send_alias\":\"\",\"type\":\"text\",\"receive\":\"wxid_34303t9wzkbm21\",\"isPC\":\"\"}");
            }
        });
    }
}
