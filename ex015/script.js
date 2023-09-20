function verificar(){
    var data = new Date()
    var ano = data.getFullYear()
    var fano = document.getElementById('txtano')
    var res = document.getElementById('res')
    if(fano.value.length == 0 || fano.value > ano){
        alert('[ERRO] Verifique os dados e tente novamente!')
    } else{
        var fsex = document.getElementsByName('radsex')
        var idade = ano - Number(fano.value)
        var genero = ''
        var img = document.createElement('img')
        img.setAttribute('id', 'foto')
        if(fsex[0].checked){
            genero = 'Homem'
            img.setAttribute('src', 'pexels-andrea-piacquadio-846741.jpg')
        } else if(fsex[1].checked){
            genero = 'Mulher'
            img.setAttribute('src', 'pexels-moose-photos-1036623.jpg')
        }
        res.style.textAlign = 'center'
        res.innerHTML = `Detectamos ${genero} com ${idade} anos.`
        res.appendChild(img)
    }
}

function verificarTecla(event) {
    if (event.key === "Enter") {
        verificar();
    }
}
