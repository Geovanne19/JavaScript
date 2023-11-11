class Pessoa {
    constructor(nome, sobrenome) {
        this.nome = nome
        this.sobrenome = sobrenome
    }

    falar(p) {
        console.log(`Estou falando ${p}`)
    }

    comer(p) {
        console.log(`Estou comendo ${p}`)
    }

    beber(p) {
        console.log(`Estou bebendo ${p}`)
    }
}

const p1 = new Pessoa('Luiz', 'Miranda')
console.log(p1.nome, p1.sobrenome)
p1.beber('pinga')