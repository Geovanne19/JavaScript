const data = new Date()

function pegaDiaSemana() {
    const dia_semana = data.getDay()
    const vetor = ['Domingo', 'Segunda-Feira', 'Terça-Feira', 'Quarta-Feira', 'Quinta-Feira', 'Sexta-Feira', 'Sábado']
    
    switch (dia_semana) {
        case 0:
            return(vetor[0])
        case 1:
            return(vetor[1])
        case 2:
            return(vetor[2])
        case 3:
            return(vetor[3])
        case 4:
            return(vetor[4])
        case 5:
            return(vetor[5])
        case 6:
            return(vetor[6])
        default:
            break
    }
}

function PegaMes() {
    const mes = data.getMonth()
    const vetor = [
        'Janeiro', 'Fevereiro', 'Março', 'Abril', 'Maio', 'Junho', 'Julho', 'Agosto', 'Setembro', 'Outubro', 'Novembro', 'Dezembro'
    ]

    switch (mes) {
        case 0:
            return(vetor[0])
        case 1:
            return(vetor[1])
        case 2:
            return(vetor[2])
        case 3:
            return(vetor[3])
        case 4:
            return(vetor[4])
        case 5:
            return(vetor[5])
        case 6:
            return(vetor[6])
        case 7:
            return(vetor[7])
        case 8:
            return(vetor[8])
        case 9:
            return(vetor[9])
        case 10:
            return(vetor[10])
        case 11:
            return(vetor[11])
        default:
            break
    }

}

function FormataData() {
    const dia = data.getDate()
    const ano = data.getFullYear()
    const hora = data.getHours()
    const min = data.getMinutes()
    
    return(`${pegaDiaSemana()}, ${dia} de ${PegaMes()} de ${ano} ${hora}:${min}`)
}

function MostraMensagem(msg) {
    const resultado = document.querySelector('#resultado')
    const h1 = document.createElement('h1')
    h1.innerHTML = `${msg}`
    resultado.appendChild(h1)
}

MostraMensagem(FormataData())
