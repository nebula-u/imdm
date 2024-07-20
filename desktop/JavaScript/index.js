const { remote } = require('electron')
const { createApp } = Vue
const net = require('net')

let clientToServer001 = {
    operation: 0,
    uid: '',
    password: '',
    phoneNumber: '',
}

createApp({
    data() {
        return {
            uid: '',
            password: ''
        }
    },

    methods: {
        closeEvent() {
            const loginWindow = remote.getCurrentWindow()
            loginWindow.close()
        },

        login() {
            clientToServer001.operation = 1
            clientToServer001.uid = this.uid
            clientToServer001.password = this.password
            clientToServer001.phoneNumber = ''

            let jsonData = JSON.stringify(clientToServer001)
            console.log(jsonData)

            if (true === connected) {
                client.write(jsonData)
            }
            else {
                console.log('未连接到服务器')
            }
        }
    }
}).mount('#app')