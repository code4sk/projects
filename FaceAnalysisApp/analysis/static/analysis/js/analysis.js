
function analysis_js(){
  console.log("reach")
  // var strUser = e.options[e.selectedIndex].text
  var strCamera = document.getElementById("camera");
  var strAnalysis = document.getElementById("analysis");
  
  strCamera = strCamera.options[strCamera.selectedIndex].text;
  strAnalysis = strAnalysis.options[strAnalysis.selectedIndex].text;

  console.log(strAnalysis)
  console.log(strCamera)
  window.open(url, "_blank");
}


