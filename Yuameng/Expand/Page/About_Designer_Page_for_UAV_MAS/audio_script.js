/*音乐控制*/
var music=document.getElementById("music001");
var avail=true;
var but=document.getElementById("button001");
music.volume=0.5;
but.addEventListener('click',function () {
	if(avail==true) {
		avail=false;
		music.pause();
		
	} else {
		avail=true;
		music.play();
	}
});
var look=document.getElementById('watcher');
look.outerHTML=String(Number(look.innerHTML)+1);