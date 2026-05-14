let global = document.querySelector('body');
var curInst = "";

// 切换乐器
function choice(id = "windsong_lyre") {
    if(id == curInst) {
        return;
    }
    if(curInst!=="") {
        document.getElementById('Inst-' + curInst).style.backgroundColor='var(--dialog-background-color)';
    }
    curInst = id;
    document.getElementById('Inst-' + curInst).style.backgroundColor='#405870'; // ThisColorFrom -> toolbar.css -> .combo-box p:hover
    loadAudio(id);
    global.style.setProperty('--note-color', insts[id].color);
    global.style.setProperty('--background-color-hover1', insts[id].bg1);
    global.style.setProperty('--background-color-hover2', insts[id].bg2);
    global.style.setProperty('--animation-color', insts[id].bg2);
    document.getElementById("instruments").innerText = insts[id].name;
}