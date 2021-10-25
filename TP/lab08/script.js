var x = 0;
var y = 230;
var teclar = "";
var playing = true;
var i = 0;
var sxr = 0,syr = 0;
var sxj = 0, syj = 0;
var c = document.getElementById("myCanvas");
var ctx = c.getContext("2d");

// Objects
var dead = document.getElementById("dead");
var run = document.getElementById("run");
var jump = document.getElementById("jump");
var idle = document.getElementById("idle");
var object1 = document.getElementById("obj1");
var object2 = document.getElementById("obj2");
var ground = document.getElementById("ground");
var background = document.getElementById("background");

// Cactus
var yObj1 = 245;
var yObj2 = 240;
var xObj1 = 500;
var xObj2 = 380;

var gameover = false;

function OnKeyDown(event){
    teclar = event.key;
}

function OnKeyUp(event){
    teclar = "";
}

// Objects move according with the time
function updateObjPos(){
    xObj1 -= 5;
    xObj2 -= 5;
    if(xObj1 < 0){
        do{
            xObj1 = Math.random() * (600 - 500) + 500;
        }while(Math.abs(xObj1-xObj2) < 165);
    }
    if(xObj2 < 0){
        do{
           xObj2 = Math.random() * (600 - 500) + 500;
        }while(Math.abs(xObj1-xObj2) < 165);
    }
}

// Ground const position
function drawGround(){
    ctx.drawImage(background, 0, 0, 605, 350);
    ctx.drawImage(ground, 0, 150, 300, 300);
    ctx.drawImage(ground, 150, 150, 300, 300);
    ctx.drawImage(ground, 300, 150, 300, 300);
}

// Clear screen
function clear(){
    ctx.clearRect(0, 0, 600, 350);
}

function drawObjects(jumping){
    drawGround();
    if(jumping){
        ctx.drawImage(jump,sxj,syj,400,472,x,y,80,80);
        sxj += 510;
        if(sxj > 3923)
            sxj = 0;
    }
    else{
        ctx.drawImage(run,sxr,syr,400,472,x,y,80,80);
        sxr += 510;
        if(sxr > 3923)
            sxr = 0;
    }
    updateObjPos();
    ctx.drawImage(object1, xObj1, yObj1, 70, 70);
    ctx.drawImage(object2, xObj2, yObj2, 70, 70);
}

function checkCollision(){
    if(Math.abs(x-xObj1) < 75 && Math.abs(y-yObj1) < 60 || Math.abs(x-xObj2) < 75 && Math.abs(y-yObj2) < 75)
        return true;
    return false;
}

function Update(){
    clear();
    if(gameover){
        x = 0;
        y = 230;
        teclar = "";
        i = 0;
        // Cactus
        yObj1 = 245;
        yObj2 = 240;
        xObj1 = 500;
        xObj2 = 335;
        gameover = false;
    }
    if(y < 230)
        y += 15;
    if((teclar == "w" || teclar == " ") && y > 200)
        y -= 200;
    updateObjPos();
    if(checkCollision()){
        gameover = true;
        alert("Game Over. Play again?");
    }
    drawObjects(y > 200 ? false:true);
}

// Updates on each ms
setInterval(Update, 100);
