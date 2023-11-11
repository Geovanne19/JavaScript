const paragrafos = document.querySelector('.paragrafos') //pega apenas o primeiro 'p'
const ps = paragrafos.querySelectorAll('p')
const estilosBody = getComputedStyle(document.body) //pega todos os estilos do body
const backgroundColorBody = estilosBody.backgroundColor //pega a cor de fundo do body

for (let p of ps) {
    p.style.backgroundColor = backgroundColorBody //trocar os estilos via JS
    p.style.color = 'white' 
}

