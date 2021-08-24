// Ex1 - troca de vars sem var aux
console.log("ex1")
let a = 5, b = 10
a ^= b,b ^= a,a ^= b
console.log(a)
console.log(b)

// Ex2 - fatorial
var resp = parseInt(prompt('msg', '')), x
x = resp
resp = 1
while(x > 0){
    resp *= x
    x--
}
alert(resp);