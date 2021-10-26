var http = require("http");
var qs = require("querystring");
var url = require("url");
let users = [];

function compareObjs(obj1,obj2){
    var o1 = Object.keys(obj1);
    if(o1.length !== Object.keys(obj2).length)
        return false;
    for(let key of o1){
        if(obj1[key] !== obj2[key])
            return false;
    }
    return true;
}

function GetRequest(request){
    console.log("GET info:");
    console.log(url.parse(request.url,true).query); // Via GET
}

function PostRequest(request){
    var body = "";
    var splited = "";
    request.on('data',function (data){
        body += data;
        if(body.length > 1000000){
            request.connection.destroy();
            return;
        }
        splited = body.split('&');
        if(request.url === '/register.html'){
            for(var usr in users){
                if(splited[0] === users[usr][0]){
                    console.log("User already exists in database.\n");
                    return;
                }
            }
            users.push(splited);
            console.log("User registered!\n");
        }
        else if(request.url === '/login.html'){
            for(var usr in users){
                if(compareObjs(splited,users[usr])){
                    console.log("Logged in\n");
                    return;
                }
            }
            console.log("Error 404. User not found\n");
        }
        else if(request.url === '/show.html'){
            for(var i in users)
                console.log(users[i][0] + " -> " + users[i][1]);
            console.log();
        }
        else
            console.log("Link doesn\'t exist on server database.\n");
    });
    request.on('end',function (){
        console.log("POST info:");
        console.log(qs.parse(body)); // Via POST
    });
}

http.createServer(function (req,res){
    //console.log(req);
    if(req.method === 'POST')
        PostRequest(req);
    else if(req.method === 'GET')
        GetRequest(req);
    res.write("Resquest done");
    res.end();
    console.log("--------------------------------\n");
}).listen(8080);
