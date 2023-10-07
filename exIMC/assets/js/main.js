const form = document.querySelector('#formulario')

form.addEventListener('submit', function (e) {
    e.preventDefault()
    const inputPeso = e.target.querySelector('#peso')
    const inputAltura = e.target.querySelector('#altura')

    const peso = Number(inputPeso.value)
    const altura = Number(inputAltura.value)

    if(!peso && ! altura) {
        setResultado('Altura e Peso Inválidos', false)
        return
    }

    if(!peso) {
        setResultado('Peso Inválido', false)
        return
    }

    if(!altura) {
        setResultado('Altura Inválida', false)
        return
    }

    const imc = peso/(altura*altura)
    const nivelImc = getNivelImc(imc)
    
    
    setResultado(`Seu IMC é ${imc.toFixed(2)} (${nivelImc})`)
})

function getNivelImc (imc) {
    const nivel = ['Abaixo do peso', 'Peso normal', 'Sobrepeso', 'Obesidade grau 1', 'Obesidade grau 2', 'Obesidade grau 3']

    if(imc >= 39.9) return nivel[5]
    if (imc >= 34.9) return nivel[4]      
    if (imc >= 29.9) return nivel[3]
    if (imc >= 24.9) return nivel[2]       
    if (imc >= 18.5) return nivel[1]
    if (imc < 18.5) return nivel[0]
}

function setResultado (msg, isValid) {
    const result = document.querySelector('#result')
    result.innerHTML = ' '
    const p = document.createElement('p') //cria um elemento 'p'

    if (isValid) {
        p.classList.add('paragrafo-resultado')
    } else {
        p.classList.add('bad')
    }

    p.innerHTML = `${msg}`//escreve qual mensagem será inserida
    result.appendChild(p)//adiciona a mensagem efetivamente 
}