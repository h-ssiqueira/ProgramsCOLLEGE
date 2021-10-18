var x = 0;
var y = 230;
var teclar = "";

var i = 0;

var c = document.getElementById("myCanvas");
var ctx = c.getContext("2d");

// Objects
var img = document.getElementById("doge");
var object1 = document.getElementById("obj1");
var object2 = document.getElementById("obj2");
var ground = document.getElementById("ground");
var background = document.getElementById("background");

// Cactus
var yObj1 = 245;
var yObj2 = 240;
var xObj1 = 500;
var xObj2 = 350;

var gameover = false;

function OnKeyDown(event){
    teclar = event.key;
}

function OnKeyUp(event){
    teclar = "";
}

// Objects move according with the time
function updateObjPos(jump){
    if(jump){
        xObj1 -= .001;
        xObj2 -= .001;
    }
    else{
        xObj1 -= 0.4;
        xObj2 -= 0.4;
    }
    if(xObj1 < 0)
        xObj1 = Math.random() * (600 - 500) + 500;
    if(xObj2 < 0)
        xObj2 = Math.random() * (600 - 500) + 500;
}

// Ground const position
function drawGround(){
    ctx.drawImage(ground, 0, 150, 300, 300);
    ctx.drawImage(ground, 150, 150, 300, 300);
    ctx.drawImage(ground, 300, 150, 300, 300);
    ctx.drawImage(background, 0, 0, 605, 350);
}

// Clear screen
function clear(){
    ctx.clearRect(0, 0, 600, 350);
}

function drawObjects(jump){
    drawGround();
    ctx.drawImage(img, x, y, 80, 80);
    updateObjPos(jump);
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
        xObj2 = 350;
        gameover = false;
    }
    if(y < 230)
        y += 1;
    if((teclar == "w" || teclar == " ") && y > 0 && y == 230)
        y -= 200;
    updateObjPos(false);
    if(checkCollision()){
        alert("Game Over");
        gameover = true;
    }
    drawObjects(false);
}

// Updates on each ms
setInterval(Update, 1);