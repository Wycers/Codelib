import Vue from 'vue'
import locale from 'element-ui/lib/locale/lang/en'
import ElementUI from 'element-ui'
import 'element-ui/lib/theme-chalk/index.css'
import App from './App.vue'
import moment from 'moment'

Vue.use(ElementUI, { locale })

new Vue({
    el: '#app',
    render: h => h(App)
})
