//diferenças entre var, let, const

var nome1 = 'Geovanne'
// let nome2 = 'Rodrigues'

var nome1 = 'Nycolle'//var permite a redeclaração, onde o valor será sobrescrito
// let nome2 = 'Araujo'//let não permite redeclaração

console.log(nome1)

const verdadeira = true

let nome = 'Luiz'//let tem escopo de bloco --> { ... bloco}
var nome2 = 'Luiz'//var tem escopo de função

if(verdadeira) {
    let nome = 'Otávio'//apesar de ter o mesmo nome, não é a mesma variável, pois ela está dentro de um ooutro bloco
    console.log('OK')
}