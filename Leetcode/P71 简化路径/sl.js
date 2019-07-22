/**
 * @param {string} path
 * @return {string}
 */
var simplifyPath = function(path) {
    const Path = require('path')
    return Path.resolve(path)
};
