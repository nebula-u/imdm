const { remote } = require('electron')
const {createApp} = Vue

createApp({
    data(){
        return{
            msg: 'IMDM'
        }
    },

    methods:{
        closeEvent(){
            const loginWindow = remote.getCurrentWindow()
            loginWindow.close()
        }
    }
}).mount('#app')