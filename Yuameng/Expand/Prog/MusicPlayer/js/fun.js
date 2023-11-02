function Player(musicArr) {
	this.audio = document.getElementsByTagName('audio')[0];
	/*this.singer = document.getElementById('singer');*/
	this.song = document.getElementById('song');
	this.lineBar = document.getElementById('line');
	this.lineBar1 = document.getElementById('line1');
	this.circleBar = document.getElementById('circle');

	this.musicArr = musicArr;
	this.timer;
	this.lrcTimer;
	this.index = 0;
	this.isPlay = false;
	this.audio.volume = 1;
	this.audio.loop = false;              /**/

	this.playAndPause();
	this.nextSong();
	this.prevSong();
	this.progressJump();
	this.volumeUpAndOff();
	this.orderAndRepeat();
	this.progressShow();
	
	this.loadDataList();
	this.clickList();
}
Player.prototype = {
	init: function() {
		this.audio.src = this.musicArr[this.index].musicSrc;  /*song src*/
		/*this.singer.innerHTML = this.musicArr[this.index].musicSinger;*/
		this.song.innerHTML = this.musicArr[this.index].musicName+'__'+this.musicArr[this.index].musicSinger;

		this.audio.currentTime = 0;
		this.circleBar.style.left = 0;
		this.lineBar1.style.width = 0;

		/*if(!this.isPlay) {
            this.audio.pause();
		}*/
		var self = this;
		EventUtil.addHandler(self.audio, 'ended', function() {
			if(self.loop) {
				return;
			} else {
				self.index = ++self.index % self.musicArr.length;
				self.init();
			}
		});	

		/*this.lyricShow();*/

	},
	// 根据歌曲数组生成歌曲列表
	loadDataList: function() {
		var self = this;
		var tbody = document.getElementsByTagName('tbody')[0];
		for(var i = 0; i < this.musicArr.length; i++) {
			var trNew = document.createElement('tr');
			var tdSong = document.createElement('td');
			var tdSinger = document.createElement('td');
			trNew.className = i;
			tdSong.innerHTML = this.musicArr[i].musicName;
			tdSinger.innerHTML = this.musicArr[i].musicSinger;
			trNew.appendChild(tdSong);
			trNew.appendChild(tdSinger);
			tbody.appendChild(trNew);
		}
	},
	// 点击列表播放对应歌曲
	clickList: function() {
		var self = this;
		var tr = document.getElementsByTagName('tr')
		for(var i = 0; i < tr.length; i++) {
			EventUtil.addHandler(tr[i], 'click', function() {
				self.index = this.className;
				// console.log(self.index);
				self.init();
			});
		}
	},
	// 暂停和继续
	playAndPause: function() {
		var playBlock = document.getElementById('play-pause');
		var playBtn = document.getElementById('play');
		var pauseBtn = document.getElementById('pause');
		var self = this;
		playBtn.style.display = "block";
		pauseBtn.style.display = "none";

        EventUtil.addHandler(playBlock, 'click', function() {
        	if(self.isPlay) {
				self.audio.pause();
				self.isPlay = false;
				playBtn.style.display = "block";
				pauseBtn.style.display = "none";
			} else {
				self.audio.play();
				self.isPlay = true;
				playBtn.style.display = "none";
				pauseBtn.style.display = "block";
			}
        });
	},
	// 下一首
	nextSong: function() {
		var curTime = document.getElementById('cur-time');
		/*var endTime = document.getElementById('end-time');*/
		var nextBtn = document.getElementById('next');
		var self = this;
		var playBtn = document.getElementById('play');
		var pauseBtn = document.getElementById('pause');

        EventUtil.addHandler(nextBtn, 'click', function() {
            self.index = ++self.index%self.musicArr.length;
			curTime.innerHTML = "00:00";
			/*endTime.innerHTML = " / 00:00";*/
			self.isPlay= true;
			playBtn.style.display = "none";
			pauseBtn.style.display = "block";
			self.init();
			self.audio.play();
        });
	},
	// 上一首
	prevSong: function() {
		var curTime = document.getElementById('cur-time');
		/*var endTime = document.getElementById('end-time');*/
		var prevBtn = document.getElementById('prev');
		var self = this;

        EventUtil.addHandler(prevBtn, 'click', function() {
        	self.index = (--self.index + self.musicArr.length)%self.musicArr.length;
			curTime.innerHTML = "00:00";
			/*endTime.innerHTML = " / 00:00";*/
			self.isPlay= true;
			playBtn.style.display = "none";
			pauseBtn.style.display = "block";
			self.audio.play();
			self.init();
        });
	},
	// 进度跳转
	progressJump: function() {
		var self = this;
		var musicBox = document.getElementById('music-box');
		var progressBlock = document.getElementById('play-progress');

        EventUtil.addHandler(self.lineBar, 'mousedown',function(event) {
			var event = EventUtil.getEvent(event);
			// 获取鼠标与进度条开始处的距离
			var x = parseInt(event.clientX - progressBlock.offsetLeft - musicBox.offsetLeft - self.circleBar.offsetWidth / 2);
			// 超出边界情况
			if(x < 0) {
				x = 0;
			}
			if(x > self.lineBar.offsetWidth + self.circleBar.offsetWidth / 2) {
				x = self.lineBar.offsetWidth + self.circleBar.offsetWidth / 2;
			}

			self.circleBar.style.left = x + "px";
			self.lineBar1.style.width = x + "px";
			self.audio.currentTime = x / self.lineBar.offsetWidth * self.audio.duration;
		});
		
	},
	// 静音开启与关闭
	volumeUpAndOff: function() {
		var volumeBlock = document.getElementById('volume-up-off');
		var volumeUpBtn = document.getElementById('volume-up');
		var volumeOffBtn = document.getElementById('volume-off');
		var self = this;

        EventUtil.addHandler(volumeBlock, 'click',function() {
			if(self.audio.volume > 0) {
				volumeUpBtn.style.display = "none";
				volumeOffBtn.style.display = "block";
				self.audio.volume = 0;
			} else {
				volumeUpBtn.style.display = "block";
				volumeOffBtn.style.display = "none";
				self.audio.volume = 1;
			}
	    });
	},
	// 顺序播放和循环播放
	orderAndRepeat: function() {
		var orderBlock = document.getElementById('order-repeat');
		var orderBtn = document.getElementById('order');
		var repeatBtn = document.getElementById('repeat');
		var self = this;

        EventUtil.addHandler(orderBlock, 'click',function() {
			if(self.audio.loop) {
				orderBtn.style.display = "block";
				repeat.style.display = "none";
				self.audio.loop = false;
			} else {
				orderBtn.style.display = "none";
				repeatBtn.style.display = "block";
				self.audio.loop = true;
			}
		});
	},
	
	// 显示播放进度
	progressShow: function() {
		var curTime = document.getElementById('cur-time');
		var endTime = document.getElementById('end-time');
		var self = this;
		
		// 播放时间显示
		/*EventUtil.addHandler(self.audio, 'canplay', function() {
			/*var endTim = Math.floor(this.duration);
			var endMin = Math.floor(endTim / 60);
			var endSec = endTim % 60;
			endTime.innerHTML = +"\s\s\s\s\s" + endMin + ":" + endSec;
		});*/
		// 进度条更新
		clearInterval(this.timer);
		this.timer = setInterval(function() {
			var curTim = Math.floor(self.audio.currentTime);
			var curMin = Math.floor(curTim / 60);
			var curSec = curTim % 60;
			curMin = curMin >= 10 ? curMin : '0' + curMin;
            curSec = curSec >= 10 ? curSec : '0' + curSec;
            curTime.innerHTML = curMin + ":" + curSec;

            self.circleBar.style.left = parseInt(self.audio.currentTime / self.audio.duration * self.lineBar.offsetWidth) + "px";
            self.lineBar1.style.width = parseInt(self.audio.currentTime / self.audio.duration * self.lineBar.offsetWidth) + "px"
		},500);
	},
	
	
	// 显示歌词
	/*
	lyricShow: function() {
		/*var lrcBlock = document.getElementById('lyric');
		var lrcPara = lrcBlock.getElementsByTagName('p');
		var timeArr = new Array();
		var lrcArr = new Array();
		var minArr = new Array();
		var secArr = new Array();
		var secTotal = new Array();
		var self = this;
		var str = self.musicArr[self.index].musicLrc.split('[');
		for(var i = 1; i < str.length; i++) {
			/*var j = i - 1;*/
			/*timeArr[j] = str[i].split(']')[0];
			lrcArr[j] = str[i].split(']')[1];
			minArr[j] = timeArr[j].split(':')[0];
			secArr[j] = timeArr[j].split(':')[1];
			secTotal[j] = parseInt(minArr[j]) * 60 + parseInt(secArr[j]);
		}
		// 歌词更新
		clearInterval(self.lrcTimer);
		self.lrcTimer = setInterval(function() {
			for(var i = 0; i < lrcPara.length; i++) {
				lrcPara[i].style.color = "#000";
			}
			var secDiffer = secTotal.map(function(item,index,array) {
				return parseInt(item - self.audio.currentTime);
			})
			for(var k = 0; k < secDiffer.length; k++) {
				if(secDiffer[k] == 0) {
					var lrcIndex = k;
					// lrcPara[lrcIndex%6].style.color = "rgb(247,209,0)";
					if(lrcIndex < 6) {
						lrcPara[0].innerHTML = lrcArr[0];
						lrcPara[1].innerHTML = lrcArr[1];
						lrcPara[2].innerHTML = lrcArr[2];
						lrcPara[3].innerHTML = lrcArr[3];
						lrcPara[4].innerHTML = lrcArr[4];
						lrcPara[5].innerHTML = lrcArr[5];
					} else if(lrcIndex > lrcArr.length - 6) {
						lrcPara[0].innerHTML = lrcArr[lrcArr.length - 5];
						lrcPara[1].innerHTML = lrcArr[lrcArr.length - 4];
						lrcPara[2].innerHTML = lrcArr[lrcArr.length - 3];
						lrcPara[3].innerHTML = lrcArr[lrcArr.length - 2];
						lrcPara[4].innerHTML = lrcArr[lrcArr.length - 1];
						lrcPara[5].innerHTML = lrcArr[lrcArr.length];
					} else {
						var tempIndex = lrcIndex;
						lrcPara[1].innerHTML = lrcArr[--tempIndex];
						lrcPara[0].innerHTML = lrcArr[--tempIndex];
						lrcPara[2].innerHTML = lrcArr[lrcIndex];
						lrcPara[3].innerHTML = lrcArr[++lrcIndex];
						lrcPara[4].innerHTML = lrcArr[++lrcIndex];
						lrcPara[5].innerHTML = lrcArr[++lrcIndex];
					}
				}
			}
		},500);
	}*/
}
var musicArr=[
    {
        musicSinger:'林俊杰',
        musicName:'AlwaysOnline',
        musicSrc:'/Yuameng/file/Music/AlwaysOnline_林俊杰.mp3',
    },
    {
        musicSinger:'黄子韬',
        musicName:'Beggar',
        musicSrc:'/Yuameng/file/Music/Beggar_黄子韬.mp3',
    },
    {
        musicSinger:'鞠文娴',
        musicName:'BINGBIAN 病变',
        musicSrc:'/Yuameng/file/Music/BINGBIAN病变_女声版__鞠文娴.mp3',
    },
    {
        musicSinger:'澤野弘之',
        musicName:'IVORY TOWER',
        musicSrc:'/Yuameng/file/Music/IVORYTOWER_feat_SennaRin__澤野弘之_SennaRin.mp3',
    },
    {
        musicSinger:'坂井泉水',
        musicName:'Love Is Gone',
        musicSrc:'/Yuameng/file/Music/LoveIsGone_BigroomMix__TuozhAo.mp3',
    },
    {
        musicSinger:'坂井泉水',
        musicName:'Love Is Gone',
        musicSrc:'/Yuameng/file/Music/LoveIsGone_乐笑笑.mp3',
    },
    {
        musicSinger:'Cécile Corbel',
        musicName:'Take Me Hand',
        musicSrc:'/Yuameng/file/Music/TakeMeHand_DAISHIDANCE_CécileCorbel.mp3',
    },
    {
        musicSinger:'Pianoboy',
        musicName:'The Truth That You Leave',
        musicSrc:'/Yuameng/file/Music/TheTruthThatYouLeave_Pianoboy高至豪.mp3',
    },
    {
        musicSinger:'HillsongYoung&Free',
        musicName:'Wake',
        musicSrc:'/Yuameng/file/Music/Wake_Live__HillsongYoung&Free.mp3',
    },
    {
        musicSinger:'PUBGMOBILE',
        musicName:'Win For You',
        musicSrc:'/Yuameng/file/Music/WinForYou_Knvwn_DONFVBIO.mp3',
    },
    {
        musicSinger:'温崇正',
        musicName:'一梦繁唐',
        musicSrc:'/Yuameng/file/Music/一梦繁唐_温崇正.mp3',
    },
    {
        musicSinger:'周杰伦',
        musicName:'一路向北',
        musicSrc:'/Yuameng/file/Music/一路向北_周杰伦.mp3',
    },
    {
        musicSinger:'温奕心',
        musicName:'一路生花',
        musicSrc:'/Yuameng/file/Music/一路生花_温奕心.mp3',
    },
    {
        musicSinger:'要不要买菜',
        musicName:'下山',
        musicSrc:'/Yuameng/file/Music/下山_要不要买菜.mp3',
    },
    {
        musicSinger:'川青',
        musicName:'下潜',
        musicSrc:'/Yuameng/file/Music/下潜_川青.mp3',
    },
    {
        musicSinger:'林俊杰',
        musicName:'不为谁而作的歌',
        musicSrc:'/Yuameng/file/Music/不为谁而作的歌_林俊杰.mp3',
    },
    {
        musicSinger:'毛不易',
        musicName:'不染',
        musicSrc:'/Yuameng/file/Music/不染_毛不易.mp3',
    },
    {
        musicSinger:'徐佳莹',
        musicName:'不舍',
        musicSrc:'/Yuameng/file/Music/不舍_徐佳莹.mp3',
    },
    {
        musicSinger:'叶炫清',
        musicName:'九张机',
        musicSrc:'/Yuameng/file/Music/九张机_叶炫清.mp3',
    },
    {
        musicSinger:'黄子韬',
        musicName:'余生都是你',
        musicSrc:'/Yuameng/file/Music/余生都是你_黄子韬.mp3',
    },
    {
        musicSinger:'于果',
        musicName:'侧脸',
        musicSrc:'/Yuameng/file/Music/侧脸_于果.mp3',
    },
    {
        musicSinger:'林俊杰',
        musicName:'修炼爱情',
        musicSrc:'/Yuameng/file/Music/修炼爱情_林俊杰.mp3',
    },
    {
        musicSinger:'邓紫棋',
        musicName:'倒数',
        musicSrc:'/Yuameng/file/Music/倒数_G_E_M_邓紫棋.mp3',
    },
    {
        musicSinger:'毛不易',
        musicName:'像我这样的人',
        musicSrc:'/Yuameng/file/Music/像我这样的人_Live__毛不易.mp3',
    },
    {
        musicSinger:'王贰浪',
        musicName:'像鱼',
        musicSrc:'/Yuameng/file/Music/像鱼_王贰浪.mp3',
    },
    {
        musicSinger:'邓紫棋',
        musicName:'光年之外',
        musicSrc:'/Yuameng/file/Music/光年之外_G_E_M_邓紫棋.mp3',
    },
    {
        musicSinger:'BEYOND',
        musicName:'光辉岁月',
        musicSrc:'/Yuameng/file/Music/光辉岁月_BEYOND.mp3',
    },
    {
        musicSinger:'冰冰超人',
        musicName:'八年的爱',
        musicSrc:'/Yuameng/file/Music/八年的爱_新版__冰冰超人.mp3',
    },
    {
        musicSinger:'李哈哈',
        musicName:'再也不会遇见第二个她',
        musicSrc:'/Yuameng/file/Music/再也不会遇见第二个她_李哈哈.mp3',
    },
    {
        musicSinger:'许佳豪',
        musicName:'再见我的女孩',
        musicSrc:'/Yuameng/file/Music/再见我的女孩_烟_许佳豪_.mp3',
    },
    {
        musicSinger:'李玉刚',
        musicName:'刚好遇见你',
        musicSrc:'/Yuameng/file/Music/刚好遇见你_李玉刚.mp3',
    },
    {
        musicSinger:'张碧晨',
        musicName:'刻骨',
        musicSrc:'/Yuameng/file/Music/刻骨_张碧晨.mp3',
    },
    {
        musicSinger:'赵丽颖',
        musicName:'十年',
        musicSrc:'/Yuameng/file/Music/十年_赵丽颖.mp3',
    },
    {
        musicSinger:'陈奕迅',
        musicName:'十年',
        musicSrc:'/Yuameng/file/Music/十年_陈奕迅.mp3',
    },
    {
        musicSinger:'王大毛',
        musicName:'去年夏天',
        musicSrc:'/Yuameng/file/Music/去年夏天_王大毛.mp3',
    },
    {
        musicSinger:'贺敬轩',
        musicName:'双世恋人',
        musicSrc:'/Yuameng/file/Music/双世恋人_贺敬轩.mp3',
    },
    {
        musicSinger:'周杰伦',
        musicName:'反方向的钟',
        musicSrc:'/Yuameng/file/Music/反方向的钟_周杰伦.mp3',
    },
    {
        musicSinger:'邓紫棋',
        musicName:'句号',
        musicSrc:'/Yuameng/file/Music/句号_G_E_M_邓紫棋.mp3',
    },
    {
        musicSinger:'林俊杰',
        musicName:'可惜没如果',
        musicSrc:'/Yuameng/file/Music/可惜没如果_林俊杰.mp3',
    },
    {
        musicSinger:'周杰伦',
        musicName:'听妈妈的话',
        musicSrc:'/Yuameng/file/Music/听妈妈的话_周杰伦.mp3',
    },
    {
        musicSinger:'周杰伦',
        musicName:'告白气球',
        musicSrc:'/Yuameng/file/Music/告白气球_周杰伦.mp3',
    },
    {
        musicSinger:'1个球',
        musicName:'善变',
        musicSrc:'/Yuameng/file/Music/善变_DJ版__1个球.mp3',
    },
    {
        musicSinger:'邓紫棋',
        musicName:'喜欢你',
        musicSrc:'/Yuameng/file/Music/喜欢你_G_E_M_邓紫棋.mp3',
    },
    {
        musicSinger:'路飞文',
        musicName:'嘉宾',
        musicSrc:'/Yuameng/file/Music/嘉宾_路飞文.mp3',
    },
    {
        musicSinger:'Zyboy忠宇',
        musicName:'堕',
        musicSrc:'/Yuameng/file/Music/堕_Zyboy忠宇.mp3',
    },
    {
        musicSinger:'杨千嬅',
        musicName:'处处吻',
        musicSrc:'/Yuameng/file/Music/处处吻_杨千嬅.mp3',
    },
    {
        musicSinger:'1个球',
        musicName:'外婆的澎湖湾',
        musicSrc:'/Yuameng/file/Music/外婆的澎湖湾_DJ阿卓版__1个球.mp3',
    },
    {
        musicSinger:'邓紫棋',
        musicName:'多远都要在一起',
        musicSrc:'/Yuameng/file/Music/多远都要在一起_G_E_M_邓紫棋.mp3',
    },
    {
        musicSinger:'周深',
        musicName:'大鱼',
        musicSrc:'/Yuameng/file/Music/大鱼_周深.mp3',
    },
    {
        musicSinger:'邓寓君',
        musicName:'天下',
        musicSrc:'/Yuameng/file/Music/天下_邓寓君_等什么君_.mp3',
    },
    {
        musicSinger:'薛之谦',
        musicName:'天外来物',
        musicSrc:'/Yuameng/file/Music/天外来物_薛之谦.mp3',
    },
    {
        musicSinger:'林俊杰',
        musicName:'她说',
        musicSrc:'/Yuameng/file/Music/她说_林俊杰.mp3',
    },
    {
        musicSinger:'吴青峰',
        musicName:'如果声音不记得',
        musicSrc:'/Yuameng/file/Music/如果声音不记得_吴青峰.mp3',
    },
    {
        musicSinger:'周深',
        musicName:'如许',
        musicSrc:'/Yuameng/file/Music/如许_周深.mp3',
    },
    {
        musicSinger:'Zyboy忠宇',
        musicName:'妈妈的话',
        musicSrc:'/Yuameng/file/Music/妈妈的话_Zyboy忠宇.mp3',
    },
    {
        musicSinger:'陈奕迅',
        musicName:'孤勇者',
        musicSrc:'/Yuameng/file/Music/孤勇者_陈奕迅.mp3',
    },
    {
        musicSinger:'刘可',
        musicName:'寂寞才说爱',
        musicSrc:'/Yuameng/file/Music/寂寞才说爱_DJ朱迪尼克版__刘可.mp3',
    },
    {
        musicSinger:'张碧晨',
        musicName:'年轮',
        musicSrc:'/Yuameng/file/Music/年轮_张碧晨.mp3',
    },
    {
        musicSinger:'小可',
        musicName:'幻昼',
        musicSrc:'/Yuameng/file/Music/幻昼_小可.mp3',
    },
    {
        musicSinger:'叶炫清',
        musicName:'归去来兮',
        musicSrc:'/Yuameng/file/Music/归去来兮_叶炫清.mp3',
    },
    {
        musicSinger:'1个球',
        musicName:'心动限定',
        musicSrc:'/Yuameng/file/Music/心动限定_1个球_zy哲研.mp3',
    },
    {
        musicSinger:'林俊杰',
        musicName:'心墙',
        musicSrc:'/Yuameng/file/Music/心墙_林俊杰.mp3',
    },
    {
        musicSinger:'零一九零贰',
        musicName:'忘川彼岸',
        musicSrc:'/Yuameng/file/Music/忘川彼岸_DJ名龙版__零一九零贰.mp3',
    },
    {
        musicSinger:'零一九零贰',
        musicName:'忘川彼岸',
        musicSrc:'/Yuameng/file/Music/忘川彼岸_零一九零贰.mp3',
    },
    {
        musicSinger:'邓寓君',
        musicName:'怎叹',
        musicSrc:'/Yuameng/file/Music/怎叹_邓寓君_等什么君_.mp3',
    },
    {
        musicSinger:'薛之谦',
        musicName:'怪咖',
        musicSrc:'/Yuameng/file/Music/怪咖_薛之谦.mp3',
    },
    {
        musicSinger:'葛东琪',
        musicName:'悬溺',
        musicSrc:'/Yuameng/file/Music/悬溺_葛东琪.mp3',
    },
    {
        musicSinger:'林俊杰',
        musicName:'我们的爱',
        musicSrc:'/Yuameng/file/Music/我们的爱_Live__林俊杰.mp3',
    },
    {
        musicSinger:'尹昔眠',
        musicName:'我叫长安,你叫故里',
        musicSrc:'/Yuameng/file/Music/我叫长安,你叫故里_尹昔眠_小田音乐社.mp3',
    },
    {
        musicSinger:'周杰伦',
        musicName:'我是如此相信',
        musicSrc:'/Yuameng/file/Music/我是如此相信_周杰伦.mp3',
    },
    {
        musicSinger:'南征北战NZBZ',
        musicName:'我的天空',
        musicSrc:'/Yuameng/file/Music/我的天空_南征北战NZBZ.mp3',
    },
    {
        musicSinger:'半阳',
        musicName:'我的将军啊',
        musicSrc:'/Yuameng/file/Music/我的将军啊_半阳.mp3',
    },
    {
        musicSinger:'爱情公寓全体',
        musicName:'我的未来式',
        musicSrc:'/Yuameng/file/Music/我的未来式_爱情公寓全体.mp3',
    },
    {
        musicSinger:'林俊杰',
        musicName:'手心的蔷薇',
        musicSrc:'/Yuameng/file/Music/手心的蔷薇_林俊杰_G_E_M_邓紫棋.mp3',
    },
    {
        musicSinger:'王唯乐',
        musicName:'执迷不悟',
        musicSrc:'/Yuameng/file/Music/执迷不悟_DJ版__小乐哥_王唯乐_.mp3',
    },
    {
        musicSinger:'王唯乐',
        musicName:'执迷不悟',
        musicSrc:'/Yuameng/file/Music/执迷不悟_小乐哥_王唯乐_.mp3',
    },
    {
        musicSinger:'段奥娟',
        musicName:'拾忆长安',
        musicSrc:'/Yuameng/file/Music/拾忆长安_段奥娟.mp3',
    },
    {
        musicSinger:'黄子韬',
        musicName:'揭穿',
        musicSrc:'/Yuameng/file/Music/揭穿_黄子韬.mp3',
    },
    {
        musicSinger:'陈雪燃',
        musicName:'无名之辈',
        musicSrc:'/Yuameng/file/Music/无名之辈_陈雪燃.mp3',
    },
    {
        musicSinger:'毛不易',
        musicName:'无名的人',
        musicSrc:'/Yuameng/file/Music/无名的人_毛不易.mp3',
    },
    {
        musicSinger:'1个球',
        musicName:'日不落',
        musicSrc:'/Yuameng/file/Music/日不落_1个球.mp3',
    },
    {
        musicSinger:'邓紫棋',
        musicName:'来自天堂的魔鬼',
        musicSrc:'/Yuameng/file/Music/来自天堂的魔鬼_G_E_M_邓紫棋.mp3',
    },
    {
        musicSinger:'周杰伦',
        musicName:'枫',
        musicSrc:'/Yuameng/file/Music/枫_周杰伦.mp3',
    },
    {
        musicSinger:'邓紫棋',
        musicName:'桃花诺',
        musicSrc:'/Yuameng/file/Music/桃花诺_G_E_M_邓紫棋.mp3',
    },
    {
        musicSinger:'海伦',
        musicName:'桥边姑娘',
        musicSrc:'/Yuameng/file/Music/桥边姑娘_海伦.mp3',
    },
    {
        musicSinger:'康乐,名决',
        musicName:'樱花树下的约定',
        musicSrc:'/Yuameng/file/Music/樱花树下的约定_咚鼓版__MC康乐_名决.mp3',
    },
    {
        musicSinger:'郭顶',
        musicName:'水星记',
        musicSrc:'/Yuameng/file/Music/水星记_郭顶.mp3',
    },
    {
        musicSinger:'林俊杰',
        musicName:'江南',
        musicSrc:'/Yuameng/file/Music/江南_林俊杰.mp3',
    },
    {
        musicSinger:'诗人凉',
        musicName:'江海不渡你',
        musicSrc:'/Yuameng/file/Music/江海不渡你_诗人凉.mp3',
    },
    {
        musicSinger:'王靖雯',
        musicName:'沦陷',
        musicSrc:'/Yuameng/file/Music/沦陷_王靖雯.mp3',
    },
    {
        musicSinger:'邓紫棋',
        musicName:'泡沫',
        musicSrc:'/Yuameng/file/Music/泡沫_G_E_M_邓紫棋.mp3',
    },
    {
        musicSinger:'BEYOND',
        musicName:'海阔天空',
        musicSrc:'/Yuameng/file/Music/海阔天空_BEYOND.mp3',
    },
    {
        musicSinger:'毛不易',
        musicName:'消愁',
        musicSrc:'/Yuameng/file/Music/消愁_Live__毛不易.mp3',
    },
    {
        musicSinger:'金渔',
        musicName:'深陷',
        musicSrc:'/Yuameng/file/Music/深陷_金渔.mp3',
    },
    {
        musicSinger:'薛之谦',
        musicName:'演员',
        musicSrc:'/Yuameng/file/Music/演员_薛之谦.mp3',
    },
    {
        musicSinger:'安苏羽,傅梦彤',
        musicName:'潮汐',
        musicSrc:'/Yuameng/file/Music/潮汐_Natural__IN_K_安苏羽_傅梦彤.mp3',
    },
    {
        musicSinger:'周杰伦',
        musicName:'爱在西元前',
        musicSrc:'/Yuameng/file/Music/爱在西元前_周杰伦.mp3',
    },
    {
        musicSinger:'周深',
        musicName:'玦恋',
        musicSrc:'/Yuameng/file/Music/玦恋_周深.mp3',
    },
    {
        musicSinger:'大籽',
        musicName:'白月光与朱砂痣',
        musicSrc:'/Yuameng/file/Music/白月光与朱砂痣_大籽.mp3',
    },
    {
        musicSinger:'张韶涵',
        musicName:'破茧',
        musicSrc:'/Yuameng/file/Music/破茧_张韶涵.mp3',
    },
    {
        musicSinger:'周杰伦',
        musicName:'稻香',
        musicSrc:'/Yuameng/file/Music/稻香_周杰伦.mp3',
    },
    {
        musicSinger:'吕大叶',
        musicName:'篝火旁',
        musicSrc:'/Yuameng/file/Music/篝火旁_吕大叶_马子林Broma_陈觅Lynne_王以诺.mp3',
    },
    {
        musicSinger:'蔡健雅',
        musicName:'红色高跟鞋',
        musicSrc:'/Yuameng/file/Music/红色高跟鞋_蔡健雅.mp3',
    },
    {
        musicSinger:'周林枫',
        musicName:'罪与爱',
        musicSrc:'/Yuameng/file/Music/罪与爱_周林枫_三楠.mp3',
    },
    {
        musicSinger:'林俊杰',
        musicName:'背对背拥抱',
        musicSrc:'/Yuameng/file/Music/背对背拥抱_林俊杰.mp3',
    },
    {
        musicSinger:'王忻辰,苏星婕',
        musicName:'落日与晚风',
        musicSrc:'/Yuameng/file/Music/落日与晚风_IN_K_王忻辰_苏星婕.mp3',
    },
    {
        musicSinger:'张远',
        musicName:'落霞与鲸',
        musicSrc:'/Yuameng/file/Music/落霞与鲸_张远_Vicky宣宣.mp3',
    },
    {
        musicSinger:'张碧晨',
        musicName:'蓝银色的海',
        musicSrc:'/Yuameng/file/Music/蓝银色的海_张碧晨.mp3',
    },
    {
        musicSinger:'印子月',
        musicName:'蜗牛的愿望',
        musicSrc:'/Yuameng/file/Music/蜗牛的愿望_印子月.mp3',
    },
    {
        musicSinger:'蒋龙',
        musicName:'行者',
        musicSrc:'/Yuameng/file/Music/行者_蒋龙.mp3',
    },
    {
        musicSinger:'林俊杰',
        musicName:'裂缝中的阳光',
        musicSrc:'/Yuameng/file/Music/裂缝中的阳光_林俊杰.mp3',
    },
    {
        musicSinger:'林俊杰',
        musicName:'裹着心的光',
        musicSrc:'/Yuameng/file/Music/裹着心的光_林俊杰.mp3',
    },
    {
        musicSinger:'周杰伦',
        musicName:'说好的幸福呢',
        musicSrc:'/Yuameng/file/Music/说好的幸福呢_周杰伦.mp3',
    },
    {
        musicSinger:'伊格赛听',
        musicName:'谪仙',
        musicSrc:'/Yuameng/file/Music/谪仙_伊格赛听_叶里.mp3',
    },
    {
        musicSinger:'邓寓君',
        musicName:'赤伶',
        musicSrc:'/Yuameng/file/Music/赤伶_邓寓君_等什么君_.mp3',
    },
    {
        musicSinger:'邓寓君',
        musicName:'辞九门回忆',
        musicSrc:'/Yuameng/file/Music/辞九门回忆_邓寓君_等什么君_.mp3',
    },
    {
        musicSinger:'零一九零贰',
        musicName:'还在假装',
        musicSrc:'/Yuameng/file/Music/还在假装_零一九零贰.mp3',
    },
    {
        musicSinger:'王忻辰',
        musicName:'迷失幻境',
        musicSrc:'/Yuameng/file/Music/迷失幻境_IN_K_王忻辰.mp3',
    },
    {
        musicSinger:'林俊杰',
        musicName:'那些你很冒险的梦',
        musicSrc:'/Yuameng/file/Music/那些你很冒险的梦_林俊杰.mp3',
    },
    {
        musicSinger:'林志炫',
        musicName:'醉梦前尘',
        musicSrc:'/Yuameng/file/Music/醉梦前尘_林志炫.mp3',
    },
    {
        musicSinger:'李常超',
        musicName:'长安姑娘',
        musicSrc:'/Yuameng/file/Music/长安姑娘_李常超_Lao乾妈_.mp3',
    },
    {
        musicSinger:'蓝心羽',
        musicName:'阿拉斯加海湾',
        musicSrc:'/Yuameng/file/Music/阿拉斯加海湾_蓝心羽.mp3',
    },
    {
        musicSinger:'时光胶囊',
        musicName:'青丝',
        musicSrc:'/Yuameng/file/Music/青丝_时光胶囊.mp3',
    },
    {
        musicSinger:'周杰伦',
        musicName:'青花瓷',
        musicSrc:'/Yuameng/file/Music/青花瓷_周杰伦.mp3',
    },
    {
        musicSinger:'伦桑',
        musicName:'龙武盛唐',
        musicSrc:'/Yuameng/file/Music/龙武盛唐_伦桑.mp3',
    },

];
var player = new Player(musicArr);
player.init();
