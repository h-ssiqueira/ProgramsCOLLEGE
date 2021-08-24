function onLoad(){
    document.calc.visor.value = "";
}

function errors(str){
    var operator = false;
    if(!str || str[str.length-1] === ' ') return true; // case no input or start/end with a symbol
    for(let i = 0; i < str.length; i++){
        if(!(str[i] <= 57 || str[i] >= 48) && str[i] !== '-' && str[i] !== '/' && str[i] !== '*' && str[i] !== '+' && str[i] !== '.' && str[i] !== ' ')
            return true;
        if(str[i] === '-' && (i != 0 || i != 1) || str[i] === '+' || str[i] === '/' || str[i] === '*'){
            operator = true;
            if(i+2 < str.length && str[i+2] === ' ' && str[i+3] !== '-')
                return true;
        }
    }
    if(operator)
        return false;
    else
        return true;
}

function calculate(str){
    if(errors(str)) return "Error";
    var n1 = 0, n2 = 0, op, i = 0, neg = false,j;
    if(str[i] === ' ')
        i++;
    if(str[i] === '-'){
        neg = true;
        i++;
    }
    while(str[i] !== ' '){
        if(str[i] === '.'){
            i++;
            j = 10;
            while(str[i] !== ' '){
                n1 += (Number(str[i])/j);
                i++;
                j *= 10;
            }
        }
        else{
            n1 *= 10;
            n1 += Number(str[i]);
            i++;
        }
    }
    if(neg)
        n1 *= -1;
    i++;
    for(; i < str.length; i++, neg = false, n2 = 0){
        switch(str[i]){
            case '-':
                op = '-';
                break;
            case '+':
                op = '+';
                break;
            case '/':
                op = '/';
                break;
            case '*':
                op = '*';
                break;
        }
        i += 2;
        if(str[i+1] === '-'){
            neg = true;
            i += 3;
        }
        while(str[i] >= '0' && str[i] <= '9' || str[i] === '.' && str[i] !== ' ' && i !== str.length){
            if(str[i] === '.'){
                console.log(i,str[i])
                i++;
                j = 10;
                while(str[i] !== ' ' && i != str.length){
                    n2 += (Number(str[i])/j);
                    i++;
                    j *= 10;
                }
            }
            else{
                n2 *= 10;
                n2 += Number(str[i]);
                i++;
            }
        }
        if(neg)
            n2 *= -1;
        switch(op){
            case '-':
                n1 -= n2;
                break;
            case '+':
                n1 += n2;
                break;
            case '/':
                if(n2 === 0 || n1 === 0)
                    n1 = 0;
                else
                    n1 /= n2;
                break;
            case '*':
                n1 *= n2;
                break;
        }
    }
    return n1;
}

function onClick(button){
    if(button === "Enter")
        document.calc.visor.value = calculate(document.calc.visor.value);
    else if(button === "CE")
        document.calc.visor.value = "";
    else
        document.calc.visor.value += button;
}