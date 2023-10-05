function contar(){
    var inicio = document.getElementById('inicio')
    var fim = document.getElementById('fim')
    var passo = document.getElementById('passo')
    var res = document.getElementById('res')
    var res2 = document.getElementById('res2')
    if(inicio.value.length == 0 || fim.value.length == 0 || passo.value.length == 0){
        res.innerHTML = `Impossível Contar!`
        alert('[ERRO] Faltam Dados!')       
    } else{
        res.innerHTML = `<br>Contando: <br>`
        let i = Number(inicio.value)
        let f = Number(fim.value)
        let p = Number(passo.value)
        if(p <= 0){
            p = 1
        }
        if(i < f){
            for(let c = i; c <= f; c += p){
                res.innerHTML += `${c} \u{1F449} `
            }
        } else{
            for(let c = i; c >= f; c -= p){
                res.innerHTML += `${c} \u{1F449} `
            }
        }
        res.innerHTML += '\u{1F3C1}'
    }
    
}