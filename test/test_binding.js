const culture = require("../lib/binding.js");
const assert = require("assert");

assert(culture, "The expected module is undefined");

let locale = culture.get();
console.log(locale);

console.log("Tests passed - everything looks OK!");