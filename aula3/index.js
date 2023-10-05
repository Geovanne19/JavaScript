console.log("Olá 'Mundo'")
console.log('Olá "Mundo"')
console.log(`"Olá" 'Mundo'`)

console.log(35, 15.85, 'Olá Mundo');

console.log(`Meu nome é "Geovanne". Estou aprendendo JavaScript às`, 10, `da  manhã.`)

//comentário
/*comentário*/

const nome = 'Geovanne Rodrigues' //string
let idade = 20 //number
let peso = 84
var altura = 1.80
let nomeAluno //undefined -> não aponta para local nenhum de memória
let sobrenomeAluno = null //undefined -> não aponta para local nenhum de memória
const boolean = true //variável booleana -> true e false(lógico)

console.log(typeof nome, nomeAluno, sobrenomeAluno, boolean) //função typeof

var imc = (peso/(altura*altura))
let anonascimento = 2023 - idade

console.log(`${nome} tem ${30} anos, pesa ${84} kg`)
console.log(`tem ${altura} de altura e seu IMC é de ${imc}`)
console.log(`${nome} nasceu em ${anonascimento}`)

// let varA = 'A' //B
// let varB = 'B' //C
// let varC = 'C' //A

// [varA, varB, varC] = [varB, varC, varA]

// console.log(varA, varB, varC)

const alunos = ['Luiz', 'Maria', 'João', 'Luiza', 'Eduardo']

// for(let i = 0; i < 3; i++){
//     console.log(alunos[i])
// }
// console.log(alunos)

alunos.length //tamanho do array  
alunos.push //add no final do array
alunos.unshift //add no começo do array
alunos.pop //apaga o último do array alterando os índices
alunos.shift// apaga o priemeiro do array alterando os índices
alunos.slice(0, 3) //fatia o array
delete alunos[alunos.length] //deleta sem alterar os índices

console.log(typeof alunos) //array é um objeto
console.log(alunos instanceof Array) //saber com que instância eu estou trabalhando

//posso declarar uma variável com o valor de retorno de uma função
const raiz = function (n) {
    return n ** 0.5;
}

console.log(raiz(9))
console.log(raiz(16))
console.log(raiz(25))

//ou posso fazer a mesma coisa em declaração de arrow function

const raiz_ = (n) => {
    return n ** 0.5;
}

console.log(raiz_(9))
console.log(raiz_(16))
console.log(raiz_(25))

//Objeto Simples

const pessoa = {
    nome: 'Luiz',
    sobrenome: 'Miranda',
    idade: 25
}

//função par criar objetos

function criaPessoa (nome, sobrenome, idade) {
    return {
        nome: nome,
        sobrenome: sobrenome,
        idade: idade
    }
}

//podemos simplificar esta função

function criaPessoaSimplificada (nome, sobrenome, idade) {
    return { nome, sobrenome, idade }
}

const pessoa1 = criaPessoaSimplificada('Luiz', 'Miranda', 25)
const pessoa2 = criaPessoaSimplificada('Maria', 'Oliveira', 32)
const pessoa3 = criaPessoaSimplificada('João', 'Moreira', 55)
const pessoa4 = criaPessoaSimplificada('Junior', 'Lara', 44)
const pessoa5 = criaPessoaSimplificada('Jean', 'Otávio', 69)

console.log(pessoa1.nome, pessoa2.nome)

//Métodos

const pessoa6 = {
    nome: 'Luiz',
    sobrenome: 'Miranda',
    idade: 25,

    fala() {
        console.log('Olá Mundo!')
    }
}

pessoa6.fala()

//This

const pessoa7 = {
    nome: 'Luiz',
    sobrenome: 'Miranda',
    idade: 25,

    fala() {
        console.log(`A minha idade atual é ${this.idade}.`)
    }, //não esqueca da vírgula

    incrementaIdade() {
        this.idade++ //"this" em JavaScript se refere ao objeto atual em que uma função está sendo chamada ou ao objeto para o qual um método pertence. Ele fornece acesso às propriedades e métodos desse objeto dentro da função.
    }
}

pessoa7.fala()