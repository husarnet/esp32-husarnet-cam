#pragma once

const char index_html[] = R"rawliteral(
<!DOCTYPE html>
<style type="text/css">
  html, body {
    height: 100%;
    background: #1c1b1b;
    color: #fafafa;
    font-family: sans-serif;
  }

  .container {
    display: flex;
    flex-direction: column;
    justify-content: center;
    justify-items: center;
    align-items: center;
    height: 100%;
    text-align: center;
  }

  .header {
    width: 250px;
  }

  .item {
    margin: 20px;
  }

  a {
    color: #fafafa;
  }

</style>
<html>
<head>
  <title>Husarnet ESP32 Cam</title>
  <meta charset="utf-8">
</head>
<body>
  <div class="container">
      <img class="header" src="https://github.com/husarnet/husarnet/raw/master/docs/logo.svg">
    <div class="item">
      <h2>Husarnet ESP32 Cam</h2>
      <p>Live stream from the ESP32-CAM</p>
      <a href="https://husarnet.com/docs/esp32-guide/">Documentation 📖</a>
    </div>
    <div class="item">
      <img src="http://husarnet-esp32-cam/cam.mjpeg" alt="">
    </div>
  </div>
</body>
</html>
)rawliteral";