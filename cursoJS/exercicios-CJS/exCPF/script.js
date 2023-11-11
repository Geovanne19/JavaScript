const cpf = '705.484.450-52'
let cpfLimpo = cpf.replace(/\D+/g, '')
let cpfArray = Array.from(cpfLimpo)
let cpfReduzido = cpfArray.reduce((ac, val) => ac + Number(val), 0)
let cpf9 = cpfArray.slice(0, -2)
let cpf11 = [...cpf9]

function getPrimeiroDigito (array) {
    let digito = []
    let mult = 10
    
    for(let i=0; i < 9; i++) {
        digito [i] = array[i] * mult
        mult--
    }

    let somaDigito = digito.reduce((ac, val) => ac + Number(val), 0) 
    let digitoTemp = 11 - (somaDigito % 11)
    
    if(digitoTemp > 9) {
        return 0
    } else {
        return digitoTemp
    }
}

function getSegundoDigito(array) {
    
    let digito = [];
    let mult = 11;

    array.push(getPrimeiroDigito(cpf9));

    for (let i = 0; i < 10; i++) {
        digito[i] = array[i] * mult;
        mult--;
    }

    let somaDigito = digito.reduce((ac, val) => ac + Number(val), 0);
    let digitoTemp = 11 - (somaDigito % 11);

    if (digitoTemp > 9) {
        return 0;
    } else {
        return digitoTemp;
    }
}

cpf11.push(String(getPrimeiroDigito(cpf9)), String(getSegundoDigito(cpf9)))

console.log(cpf11)
console.log(cpfArray)