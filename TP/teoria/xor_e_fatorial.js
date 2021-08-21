console.log("ex1")
let a = 5, b = 10
a ^= b,b ^= a,a ^= b
console.log(a)
console.log(b)
var resp = parseInt(prompt('msg', '')), x
x = resp
resp = 1
while(x > 0){
    resp *= x
    x--
}
alert(resp);