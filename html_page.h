#pragma once
const char htmlPage[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html>
<head><title>Motor Speed Control</title></head>
<body>
  <h2>Motor Speed Control</h2>
  <input type=\"range\" min=\"0\" max=\"100\" value=\"0\" id=\"slider\" oninput=\"updateSlider(this.value)\">
  <p>Speed: <span id=\"val\">0</span>%</p>
  <script>
    function updateSlider(val) {
      document.getElementById(\"val\").innerText = val;
      fetch("/setSpeed?value=" + val);
    }
    setInterval(() => {
      fetch("/getSpeed")
        .then(res => res.text())
        .then(val => {
          document.getElementById("slider").value = val;
          document.getElementById("val").innerText = val;
        });
    }, 1000);
  </script>
</body>
</html>
)rawliteral"; 