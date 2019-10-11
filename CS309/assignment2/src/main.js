import Vue from 'vue'
import ElementUI from 'element-ui'
import 'element-ui/lib/theme-chalk/index.css'
import App from './App.vue'
import moment from 'moment'

Vue.use(ElementUI)
Vue.prototype.$moment = moment

new Vue({
    el: '#app',
    render: h => h(App)
})
