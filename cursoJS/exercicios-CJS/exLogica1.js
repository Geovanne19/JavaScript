// Escreva uma função que recebe 2 números e retorne o maior deles

function maiorNumero(num1, num2) {
    if(num1 > num2) {
        return num1
    } else {
        return num2
    }
}

const max2 = (x, y) => x > y ? x : y //arrow function

const num1 = 45345
const num2 = 4543565
const maior = maiorNumero(num1, num2)

console.log(`O maior número é ${maior}`)
console.log(max2(10, 5))