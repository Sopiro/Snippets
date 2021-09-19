// import org.json.JSONObject;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.net.HttpURLConnection;
import java.net.URL;
import java.net.URLConnection;
import java.util.Map;

class Analyzer {
    private static final String BOUNDARY = "boundary";
    private static final String DOUBLE_DASH = "--";
    private static final String LINE_FEED = "\r\n";
    private static final String CHARSET = "UTF-8";
    private static final int TIMEOUT = 5000;
    private static final int BUFFER_SIZE = 1024;

    private static final String SERVER_URL = "http://server.url:5000/rest";

    /* 
        file: 보낼 파일
        mode: url 뒤에 붙을 rest api route
        subData: form-data content로 전송되어질 Key, Data pair
     */
    String sendFile(File file, String mode, Map<String, String> subData) {
        try {
            URL url = new URL(SERVER_URL + mode);

            HttpURLConnection conn = (HttpURLConnection) url.openConnection();

            conn.setRequestProperty("Connection", "Keep-Alive");
            conn.setRequestProperty("User-Agent", "Android Multipart HTTP Client 1.0");
            conn.setRequestProperty("Content-Type", "multipart/form-data;charset=utf-8;boundary=" + BOUNDARY);
            conn.setRequestMethod("POST");
            conn.setDoInput(true);
            conn.setDoOutput(true);
            conn.setUseCaches(false);
            conn.setConnectTimeout(TIMEOUT);

            OutputStream os = conn.getOutputStream();
            BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(os, CHARSET));

            bw.append("--" + BOUNDARY).append(LINE_FEED);
            bw.append("Content-Disposition: form-data; name=\"file\"; filename=\"").append(file.getName()).append("\"")
                    .append(LINE_FEED);
            bw.append("Content-Type: ").append(URLConnection.guessContentTypeFromName(file.getName()))
                    .append(LINE_FEED);
            bw.append("Content-Transfer-Encoding: binary").append(LINE_FEED);
            bw.append(LINE_FEED);
            bw.flush();

            FileInputStream inputStream = new FileInputStream(file);
            byte[] buffer = new byte[BUFFER_SIZE];
            int bytesRead;
            while ((bytesRead = inputStream.read(buffer)) != -1)
                os.write(buffer, 0, bytesRead);
            os.flush();
            inputStream.close();
            bw.append(LINE_FEED);
            bw.flush();

            // Json 형식의 서브데이터를 받아서 Body에 form data로 인코드.
            if (subData != null)
                for (String key : subData.keySet()) {
                    String value = subData.get(key);
                    bw.append("--" + BOUNDARY).append(LINE_FEED);
                    bw.append("Content-Disposition: form-data; name=\"").append(key).append("\"").append(LINE_FEED);
                    bw.append(LINE_FEED);

                    bw.append(value);
                    bw.append(LINE_FEED);
                }

            bw.append(DOUBLE_DASH + BOUNDARY + DOUBLE_DASH).append(LINE_FEED);
            bw.close();

            int responseCode = conn.getResponseCode();
            // Utils.log(responseCode);

            BufferedReader br = new BufferedReader(new InputStreamReader(conn.getInputStream()));

            StringBuilder response = new StringBuilder();
            String line;

            while ((line = br.readLine()) != null)
                response.append(line);

            inputStream.close();

            // JSONObject jsoned = new JSONObject(response.toString());

            // Log.d("@@@", jsoned.toString());

            // return jsoned.get("result").toString();
            return "Uncomment above" + responseCode;
        } catch (Exception e) {
            e.printStackTrace();
            return null;
        }
    }
}
