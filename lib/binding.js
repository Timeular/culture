const exec  = require('child_process').exec;

let culture = require('bindings')('culture-native.node');

const get = () => culture.get().toLowerCase().replace('_', '-')

const openSettings = () => {
    if (process.platform === 'win32') {
        // https://support.microsoft.com/en-us/help/192806/how-to-run-control-panel-tools-by-typing-a-command
        exec('intl.cpl')
    } else if (process.platform === 'darwin') {
        const command = 
        `tell application "System Preferences"
            activate
            set the current pane to pane id "com.apple.Localization"
        end tell`
        exec(`osascript -e '${command}'`)
    }
}

module.exports = { get, openSettings };