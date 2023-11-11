// Escreva uma função que recebe um número e retorne o seguinte:
/*
Número é divisível por 3 = Fizz
Número é divisível por 5 = Buzz
Número é divisível por 3 e 5 = FizzBuzz
Número NÃO é divisível por 3 e 5 = Retorna o próprio número
Checar se o número é realmente um número
Use a função com números de 0 a 100
*/

function FizzBuzz (num) {
    if(typeof num === 'number' && num >= 0 && num <=100) {
        if(num%3 !== 0 && num%5 !== 0) return num       
        if (num%3 === 0 && num%5 === 0) return 'FizzBuzz'
        if (num%3 === 0) return 'Fizz'
        if (num%5 === 0) return 'Buzz'
    }
    return 'Número Inválido'
}

// const array = ['teste', 101, 17, 15, 6, 10]

// for (let i = 0; i < array.length; i++) {
//     console.log(FizzBuzz(array[i]))
// }

for (let i = 0; i < 100; i++) {
    console.log(i, FizzBuzz(i))
}