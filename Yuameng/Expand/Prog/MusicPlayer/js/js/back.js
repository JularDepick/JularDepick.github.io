window.onload = function () {
    var total=12;
    var head = document.getElementById("-body");
	var i = 0;
    function time() {
		i++;
		if(i>total) {
			i=1;
		}
        head.style.backgroundImage = "url(./images/bg" +i+ ".jpg)";
    }
    setInterval(time, 10*1000);
}