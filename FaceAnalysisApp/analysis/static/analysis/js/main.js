function display_one(csrf_token) {
    $(document).ready(function() {
          var e = document.getElementById("camera_display_1");
          var strUser = e.options[e.selectedIndex].text;
          var image = document.getElementById("one");
          console.log(strUser);
            $.ajax({
                url: "/cam_display/",
                type: "POST",
                dataType: "json",
                data: {
                    url: strUser,
                    csrfmiddlewaretoken: csrf_token
                    },
                success : function(params) {
                    alert(params['img_url']);
                    var image = document.getElementById("one");
                    image.src = params['img_url']
                    image.src = "http://124.44.106.144:50000/SnapshotJPEG?Resolution=640x480&amp;Quality=Clarity&amp;COUNTER"
                },
                error : function(xhr,errmsg,err) {
                    alert("Could not send URL to Django. Error: " + xhr.status + ": " + xhr.responseText);
                }
            });
       
    });
}

function display_two(csrf_token) {
    $(document).ready(function() {
          var e = document.getElementById("camera_display_2");
          var strUser = e.options[e.selectedIndex].text;
          var image = document.getElementById("two");
          console.log(strUser);
            $.ajax({
                url: "/cam_display/",
                type: "POST",
                dataType: "json",
                data: {
                    url: strUser,
                    csrfmiddlewaretoken: csrf_token
                    },
                success : function(params) {
                    alert(params['img_url']);
                    var image = document.getElementById("two");
                    image.src = params['img_url']
                    image.src = "http://80.155.54.125:80/cgi-bin/faststream.jpg?stream=half&fps=15&rand=COUNTER"
                },
                error : function(xhr,errmsg,err) {
                    alert("Could not send URL to Django. Error: " + xhr.status + ": " + xhr.responseText);
                }
            });
       
    });
}


function display_three(csrf_token) {
    $(document).ready(function() {
          var e = document.getElementById("camera_display_3");
          var strUser = e.options[e.selectedIndex].text;
          var image = document.getElementById("three");
          console.log(strUser);
            $.ajax({
                url: "/cam_display/",
                type: "POST",
                dataType: "json",
                data: {
                    url: strUser,
                    csrfmiddlewaretoken: csrf_token
                    },
                success : function(params) {
                    alert(params['img_url']);
                    var image = document.getElementById("three");
                    image.src = params['img_url']
                    image.src = "http://37.182.240.202:82/cgi-bin/faststream.jpg?stream=half&fps=15&rand=COUNTER"
                },
                error : function(xhr,errmsg,err) {
                    alert("Could not send URL to Django. Error: " + xhr.status + ": " + xhr.responseText);
                }
            });
       
    });
}

function display_four(csrf_token) {
    $(document).ready(function() {
          var e = document.getElementById("camera_display_4");
          var strUser = e.options[e.selectedIndex].text;
          var image = document.getElementById("four");
          console.log(strUser);
            $.ajax({
                url: "/cam_display/",
                type: "POST",
                dataType: "json",
                data: {
                    url: strUser,
                    csrfmiddlewaretoken: csrf_token
                    },
                success : function(params) {
                    alert(params['img_url']);
                    var image = document.getElementById("four");
                    image.src = params['img_url']
                    image.src = "http://213.167.138.133:3000/cgi-bin/faststream.jpg?stream=half&fps=15&rand=COUNTER"
                },
                error : function(xhr,errmsg,err) {
                    alert("Could not send URL to Django. Error: " + xhr.status + ": " + xhr.responseText);
                }
            });
       
    });
}
