const {app, BrowserWindow} = require('electron')

function createLoginWindow(params) {
    let mainWin = new BrowserWindow({
        show: false,
        width: 350,
        height: 500,
        frame: false,
        webPreferences:{
            nodeIntegration: true,
            enableRemoteModule: true
        }
    })
    mainWin.once('ready-to-show', ()=>{
        mainWin.show()
    })

    mainWin.loadFile('./index.html')
}

function poweron() {
    var LoggedIn = false
    if(LoggedIn){

    }else{
        createLoginWindow()
    }
}

app.on('ready', poweron)