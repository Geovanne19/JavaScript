function carregar(){
    var msg = document.getElementById('msg')
    var imagem = document.getElementById('imagem')
    var data = new Date()
    var hora = data.getHours()
    msg.innerHTML = `Agora são ${hora} horas.`
    if(hora >= 0 && hora < 12){
        //BOM DIA!
        imagem.src = 'manha.jpg'
        document.body.style.background = '#e2cd9f'
    } else if(hora >= 12 && hora < 18){
        //BOA TARDE!
        imagem.src = 'tarde.jpg'
        document.body.style.background = '#b9846f'
    } else{
        //BOA NOITE!
        imagem.src = 'noite.jpg'
        document.body.style.background = '#515154'
    }
}