const {app, BrowserWindow} = require('electron')

function createLoginWindow(params) {
    let mainWin = new BrowserWindow({
        show: false,
        width: 320,
        height: 450,
        frame: false,
        resizable: false,
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