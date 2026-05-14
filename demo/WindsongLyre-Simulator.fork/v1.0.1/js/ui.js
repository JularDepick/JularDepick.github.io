var show = {
    'transpose': false,
    'input': false
};
var isMobile = 'ontouchstart' in document.documentElement;  // 检测是否为手机
let curModeNode = null;

// 显示对话框
function showTextarea(id,target) { // target = true / false
    if(target==show[id]) {
        return;
    }
    let hadOn = (show['transpose'] || show['input']);
    if(target&&hadOn) {
        return;
    }
    let whichDOM = document.getElementById(id);
    let rmClsName,adClsName;
    if(target) {
        // 打开
        rmClsName='input-inactive';
        adClsName='input-active';
    } else {
        // 关闭
        rmClsName='input-active';
        adClsName='input-inactive';
    }
    whichDOM.classList.remove(rmClsName);
    whichDOM.classList.add(adClsName);
    show[id] = target;
    // console.log(`${id} act: ${target}`);
}

/* // 检测回车事件
function clickEnter(e) {
    var theEvent = e || window.event;
    var code = theEvent.keyCode || theEvent.which || theEvent.charCode;
    if (code == 13) {
        / 阻止事件的默认行为
        e.preventDefault();
        startMusic();
    }
}
*/

document.querySelectorAll('button').forEach(el => {
    // 禁止Tab键聚焦页面元素
    // 踢出 Tab 键盘导航
    el.tabIndex = -1;
    // 鼠标点击时，阻止浏览器默认自动获焦
    el.addEventListener('mousedown', function(e) {
        e.preventDefault();
    }, true);
});

document.addEventListener('keydown', e => {
    // console.log(`Got key down for UI: ${e.key}`);
    if (e.key === 'Tab') {
        // 禁止Tab键唤聚焦浏览器界面组件
        e.preventDefault();
        e.stopPropagation();
    } else
    if(e.key === 'Escape') {
        // 关闭所有对话框
        showTextarea('transpose',false);
        showTextarea('input',false);
    }
}, true);

// 为琴键添加事件
for (let node of document.querySelectorAll('.triangle')) {
    let key = node.querySelector('.key').id;
    if (isMobile) {
        node.addEventListener('touchstart', e => {
            if (show != -1) play(key, true);
        });
    } else {
        node.addEventListener('mousedown', e => {
            if (show != -1) play(key, true);
        });
    }
    removeID(node.parentNode.childNodes[1]);
}

// BPM自动更新
let bpmField = document.getElementById("bpm");
bpmField.addEventListener('focusout', () => {
    updateBpm(bpmField.value);
});

// 转调自动更新
document.getElementById('transpose-num').addEventListener('change', e => {
    transpose= parseInt(e.target.value);
});

function removeID(spread) {
    spread.addEventListener("animationend", function () {
        spread.removeAttribute('id');
    }, false);
}

// 设置调式
function selectMode(node){
    mode = node.innerText;
    if(curModeNode==node) {
        return;
    }
    document.querySelector("#modeText").innerText = node.innerText;
    if(curModeNode) {
        curModeNode.style.backgroundColor='var(--dialog-background-color)';
    }
    node.style.backgroundColor='#405870'; // ThisColorFrom -> toolbar.css -> .combo-box p:hover
    curModeNode=node;
}

let volumeSlider = document.getElementById('volume');
volumeSlider.addEventListener('change',e=>{
    masterVolume.gain.value = Math.pow(volumeSlider.value /100,2);
});

// 设备方向检测与横屏提醒
function checkOrientation() {
    const orientationWarning = document.getElementById('orientationWarning');
    const isMobileOrTablet = isMobile || (window.innerWidth < 1024);
    const isPortrait = window.innerHeight > window.innerWidth;

    if (isMobileOrTablet && isPortrait) {
        orientationWarning.style.display = 'flex';
    } else {
        orientationWarning.style.display = 'none';
    }
}

document.addEventListener('DOMContentLoaded', function() {
    const dropdown = document.getElementById('instrumentDropdown');
    const comboItems = dropdown.querySelector('.combo-items');

    dropdown.addEventListener('click', function(e) {
        e.stopPropagation();
        comboItems.style.display = comboItems.style.display === 'block' ? 'none' : 'block';
    });

    document.addEventListener('click', function(e) {
        if (!dropdown.contains(e.target)) {
            comboItems.style.display = 'none';
        }
    });
});

window.addEventListener('load', function() {
    const closeBtn = document.querySelector('.close-orientation-warning');
    const orientationWarning = document.getElementById('orientationWarning');

    if (closeBtn && orientationWarning) {
        closeBtn.addEventListener('click', function() {
            orientationWarning.style.display = 'none';
        });
    }
});

window.addEventListener('load', checkOrientation);
window.addEventListener('resize', checkOrientation);
window.addEventListener('orientationchange', checkOrientation);
