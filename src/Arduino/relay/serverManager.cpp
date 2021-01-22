#include "serverManager.h"

void ServerManager::start(IPAddress _ip)
{
  ip = _ip;
  relayManager.init();
  
  server.on("/", [this](){ handleRoot(); });
  server.on("/relay/0", HTTP_GET, [this](){ readRelay(0); });
  server.on("/relay/0", HTTP_POST, [this](){ writeRelay(0); });
  server.on("/relay/1", HTTP_GET, [this](){ readRelay(1); });
  server.on("/relay/1", HTTP_POST, [this](){ writeRelay(1); });
  server.on("/relay/2", HTTP_GET, [this](){ readRelay(2); });
  server.on("/relay/2", HTTP_POST, [this](){ writeRelay(2); });
  server.on("/relay/3", HTTP_GET, [this](){ readRelay(3); });
  server.on("/relay/3", HTTP_POST, [this](){ writeRelay(3); });
  server.on("/relay/4", HTTP_GET, [this](){ readRelay(4); });
  server.on("/relay/4", HTTP_POST, [this](){ writeRelay(4); });
  server.on("/relay/5", HTTP_GET, [this](){ readRelay(5); });
  server.on("/relay/5", HTTP_POST, [this](){ writeRelay(5); });
  server.on("/relay/6", HTTP_GET, [this](){ readRelay(6); });
  server.on("/relay/6", HTTP_POST, [this](){ writeRelay(6); });
  server.on("/relay/7", HTTP_GET, [this](){ readRelay(7); });
  server.on("/relay/7", HTTP_POST, [this](){ writeRelay(7); });
  server.on("/relay/8", HTTP_GET, [this](){ readRelay(8); });
  server.on("/relay/8", HTTP_POST, [this](){ writeRelay(8); });
  
  server.begin(); 
}

void ServerManager::handleRoot()
{
  String webPage = "<!DOCTYPE html>\r\n<html lang=\"en\">\r\n<head>\r\n  <title>Panneau de contrôle des relais</title>\r\n  <meta charset=\"utf-8\">\r\n  <meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">  \r\n  <link rel=\"stylesheet\" href=\"https://stackpath.bootstrapcdn.com/bootswatch/4.4.1/materia/bootstrap.min.css\" />\r\n  <script src=\"https://ajax.googleapis.com/ajax/libs/jquery/3.4.1/jquery.min.js\"></script>\r\n  <script src=\"https://stackpath.bootstrapcdn.com/bootstrap/4.4.1/js/bootstrap.bundle.min.js\"></script>\r\n\r\n  <style>\r\n  html, body {\r\n width: 100%;\r\n  height: 100%;\r\n  }\r\n  \r\n  h1, h2, h3, h4, h5, h6, .h1, .h2, .h3, .h4, .h5, .h6\r\n  {\r\n margin-bottom: 0;\r\n  }\r\n  \r\n  .card-body .row\r\n  {\r\n  padding:5px 0 5px 0;\r\n  }\r\n  \r\n  /* The switch - the box around the slider */\r\n.switch {\r\n  position: relative;\r\n  display: inline-block;\r\n  width: 90px;\r\n  height: 50px;\r\n  margin-bottom:-5px;\r\n}\r\n\r\n/* Hide default HTML checkbox */\r\n.switch input {display:none;}\r\n\r\n/* The slider */\r\n.slider {\r\n  position: absolute;\r\n  cursor: pointer;\r\n  top: 0;\r\n  left: 0;\r\n  right: 0;\r\n  bottom: 0;\r\n  background-color: #ccc;\r\n  -webkit-transition: .4s;\r\n  transition: .4s;\r\n}\r\n\r\n.slider:before {\r\n  position: absolute;\r\n  content: \"\";\r\n  height: 38px;\r\n  width: 38px;\r\n  left: 6px;\r\n  bottom: 6px;\r\n  background-color: white;\r\n  -webkit-transition: .4s;\r\n  transition: .4s;\r\n}\r\n\r\ninput.default:checked + .slider {\r\n  background-color: #2196F3;\r\n}\r\n\r\ninput:focus + .slider {\r\n  box-shadow: 0 0 1px #2196F3;\r\n}\r\n\r\ninput:checked + .slider:before {\r\n  -webkit-transform: translateX(38px);\r\n  -ms-transform: translateX(38px);\r\n  transform: translateX(38px);\r\n}\r\n\r\n.slider.round {\r\n  border-radius: 34px;\r\n}\r\n\r\n.slider.round:before {\r\n  border-radius: 50%;\r\n}\r\n  </style>\r\n  \r\n  <script>\r\n var baseUrl = \"http://";
  webPage += String(ip[0]) + "." + String(ip[1]) + "." + String(ip[2]) + "." + String(ip[3]);
  webPage += "\";\r\n  \r\n    $(document).ready(function() {\r\n    initialize();\r\n   sync();\r\n });\r\n \r\n  function sync()\r\n {   \r\n    $.getJSON( baseUrl + \"/relay/0\", function(data) { $('#toggle0').prop('checked', data.value); });\r\n    $.getJSON( baseUrl + \"/relay/1\", function(data) { $('#toggle1').prop('checked', data.value); });\r\n    $.getJSON( baseUrl + \"/relay/2\", function(data) { $('#toggle2').prop('checked', data.value); });\r\n    $.getJSON( baseUrl + \"/relay/3\", function(data) { $('#toggle3').prop('checked', data.value); });\r\n    $.getJSON( baseUrl + \"/relay/4\", function(data) { $('#toggle4').prop('checked', data.value); });\r\n    $.getJSON( baseUrl + \"/relay/5\", function(data) { $('#toggle5').prop('checked', data.value); });\r\n    $.getJSON( baseUrl + \"/relay/6\", function(data) { $('#toggle6').prop('checked', data.value); });\r\n    $.getJSON( baseUrl + \"/relay/7\", function(data) { $('#toggle7').prop('checked', data.value); });\r\n    $.getJSON( baseUrl + \"/relay/8\", function(data) { $('#toggle8').prop('checked', data.value); });\r\n  }\r\n \r\n  function initialize()\r\n {\r\n   var relayDetails = \"\";\r\n    for(i=0;i<9;i++)\r\n    {\r\n     relayDetails += '<div class=\"row align-middle\">' +\r\n              ' <div class=\"col text-left align-self-center\"><H3>Relais ' + i + '</H3></div>' +\r\n             ' <div class=\"col text-right align-self-center\">' +\r\n             '   <label class=\"switch\">' +\r\n             '     <input id=\"toggle' + i + '\" type=\"checkbox\" class=\"default\" data-idrelay=\"' + i + '\" onclick=\"toggleChanged(this)\" >' +\r\n             '     <span class=\"slider round\"></span>' +\r\n             '   </label>' +\r\n             ' </div>' +\r\n             '</div>';\r\n   }\r\n   $(\"#relays\").html(relayDetails);\r\n  }\r\n \r\n  function toggleChanged(sender)\r\n  {\r\n   var idRelay = $('#'+sender.id).data(\"idrelay\");\r\n   var val = 0;\r\n    if(sender.checked){ val = 1; }        \r\n    $.post( baseUrl + \"/relay/\" + idRelay + \"?value=\" + val );\r\n  }\r\n  </script>\r\n</head>\r\n<body>\r\n<br/>\r\n<div class=\"container\"> \r\n  <div class=\"row\"> \r\n    <div class=\"col d-flex justify-content-center\" >    \r\n      <div class=\"card bg-light text-center\" style=\"width: 19rem;\">\r\n       <div class=\"card-header\"><H2>Panneau de Contrôle</H2></div>\r\n       <div class=\"card-body\">\r\n       <div id=\"relays\" class=\"container\" />\r\n     </div>\r\n    </div>\r\n  </div>\r\n</div>\r\n\r\n</body>\r\n</html>\r\n\r\n";
  server.send(200, "text/html", webPage);
}

void ServerManager::readRelay(int i)
{
  sendValue(relayManager.read(i));
}

void ServerManager::writeRelay(int i)
{
  String strVal = server.arg("value");
  
  String errMsg = ServerManager::validateArg(strVal);
  if (errMsg != "")
  {     
    server.send(422, "text/json", errMsg);
  }
  
  relayManager.write(i, strVal.toInt());
  sendValue(relayManager.read(i));  
}

void ServerManager::sendValue(int i)
{
  String message = "{\"value\":" + String(i) + "}";
  Serial.println(message);
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "text/json", message);  ;  
}

bool ServerManager::isNumber(String str) {
  for(byte i=0;i<str.length();i++){
    if(!isDigit(str.charAt(i))) {
      return false;
    }
  }
  return true;
}

String ServerManager::validateArg(String strVal)
{
  if (strVal == "")
  {     
    return "{\"error\":\"'value' parameter is required\"}";
  }

  if (!isNumber(strVal))
  {
    return "{\"error\":\"'value' parameter must be an integer.  Only 0 and 1 are supported\"}";
  }

  int val = strVal.toInt();
  if (val != 0 && val != 1)
  {
    return "{\"error\":\"'value' parameter must be an integer.  Only 0 and 1 are supported\"}";
  }

  return "";
}
