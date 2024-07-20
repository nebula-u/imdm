const {app, BrowserWindow} = require('electron')
const net = require('net')
const config = require('./config.json')

const serverHost = config['server-host']
const serverPort = config['server-port']

const client = new net.Socket();

var connected = false

console.log('中文')

client.connect(serverPort, serverHost, () => {
    connected = true
    console.log('建立连接')
})

client.on('data', (data) => {
    let jsonObject = JSON.parse(data);
    console.log(jsonObject.password)
})

client.on('error', (err) => {
    console.log('error: ' + err.message)
})

client.on('close', () => {
    console.log('和服务器的连接已断开')
    connected = false
})

function createLoginWindow(params) {
    let mainWin = new BrowserWindow({
        show: false,
        width: 320,
        height: 450,
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