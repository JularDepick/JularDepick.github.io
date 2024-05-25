/* 预设脚本 */

//根目录
const proot = "https://JularDepick.github.io/Yuameng";
const phmicro = proot + "/file/media/pic/ico/hmicro.ico";
const pjquery = proot + "/file/render/js/jQuery.js";

//初始化网页head
(function() {
	var head = document.getElementsByTagName('head')[0];
	
	var charset = document.createElement('meta');
	charset.setAttribute('charset','utf-8');
	head.appendChild(charset);
	
	var hmicro = document.createElement('link');
	hmicro.setAttribute('rel','shortcut icon');
	hmicro.setAttribute('href',phmicro);
	head.appendChild(hmicro);
	/*
	var jquery = document.createElement('script');
	jquery.setAttribute('src',pjquery);
	head.appendChild(jquery);
	*/
	
})();