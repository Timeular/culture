const exec  = require('child_process').exec;

let culture = require('bindings')('culture-native.node');

const get = () => culture.get().toLowerCase().replace('_', '-')

const openSettings = () => {
    if (process.platform === 'win32') {
        // https://support.microsoft.com/en-us/help/192806/how-to-run-control-panel-tools-by-typing-a-command
        exec('intl.cpl')
    } else if (process.platform === 'darwin') {
        exec('open "x-apple.systempreferences:com.apple.Localization?Region"')
    }
}

module.exports = { get, openSettings };