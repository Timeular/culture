const culture = require('bindings')('culture-native.node');

const get = () => culture.get().toLowerCase().replace('_', '-')

module.exports = { get };
