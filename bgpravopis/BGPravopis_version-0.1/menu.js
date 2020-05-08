
var MENU_ARRAY = ["test","contact","login"];
var elemName;
var isMouseInMenu = false;

// Some browser detection used to fix some problems with different browsers
var isChrome = navigator.userAgent.toLowerCase().indexOf("chrome") > -1;
var isExplorer = navigator.userAgent.toLowerCase().indexOf("msie") > -1;
var isFirefox = navigator.userAgent.toLowerCase().indexOf("firefox") > -1;
var isExplorer6 = navigator.userAgent.toLowerCase().indexOf("msie 6") > -1;

// Atach common handler that does some job after page is loaded
window.onload = onLoadPage;


/*
* This function handles lat2cyr via cookies if sets,
* multiLine via hidden parameters and a few more things.
*/
function onLoadPage() {
try {
var encoding = getCookie("lat2cyr");
if (encoding != null) {
var element = document.getElementById("lat2cyrLink");
if (element != null) {
switchEncoding(element, encoding);
}
}
} catch(err) {
// Ignore error as this one may not apply
}
try {
var wHidden = document.getElementById("hiddenWord");
if (wHidden != null) {
var mlHidden = document.getElementById("hiddenMultiLine");
if ((mlHidden != null) && (mlHidden.value == "true")) {
var ml = document.getElementById("multiLine");
if (ml != null) {
ml.value = wHidden.value;
var mlLink = document.getElementById("multiLineLink");
if (mlLink != null) {
toggleMultiLine(mlLink, "word", "multiLine");
}
ml.focus();
}
} else {
var w = document.getElementById("word");
if (w != null) {
w.value = wHidden.value;
w.select();
w.focus();
}
}
} else {
var w = document.getElementById("word");
if (w != null) {
w.focus();
} else {
var ml = document.getElementById("multiLine");
if (ml != null) {
ml.focus();
} else {
document.forms[0].elements[0].focus();
}
}
}
} catch(err) {
// Ignore error as this one may not apply
}
}


/*
* Menu handling
*/
function toggleMenu(el) {
//for (var i = 0; i < MENU_ARRAY.length; i++) {
//if (el != MENU_ARRAY[i]) {
//hideMenu(MENU_ARRAY[i]);
//}
//}
elemName = el;
var elem = document.getElementById(el);
elem.style.display = (elem.style.display == "block" ? "none" : "block");
var x = getXOffset(document.getElementById(el + "Menu"));
if (isFirefox) {
x--;
}
elem.style.left = x + "px";
if (isExplorer) {
elem.style.top = "1.3em";
}
if (isExplorer6) {
// Change shadow effect in IE6 because it simply does not work as expected
document.getElementById(el + "VShadow").style.display = "none";
document.getElementById(el + "HShadow").style.display = "none";
document.getElementById(el).firstChild.style.backgroundColor = "silver";
} else {
// For the rest of browsers adjust overlaping shadows because to avoid double opacity which does not look good
var vs = getXOffset(document.getElementById(el + "VShadow"));
var hs = getXOffset(document.getElementById(el + "HShadow"));
document.getElementById(el + "HShadow").style.width = (vs - hs) + "px";
}
isMouseInMenu = true;
return false;
}

function hideMenu(el) {
var elem = document.getElementById(el);
elem.style.display = "none";
return false;
}

function showMenu(el) {
var elem = document.getElementById(el);
elem.style.display = "block";
return false;
}

function keepMenuOnMouseMove() {
isMouseInMenu = true;
}

function hideMenuOnMouseOut() {
isMouseInMenu = false;
setTimeout("hideMenuDelay(elemName)", 500);
}

function hideMenuDelay(el) {
if (!isMouseInMenu) {
hideMenu(el);
}
}


/*
* Calculating X, Y offset of an element
*/
function getYOffset(el) {
var ret = 0;
while (el && !isNaN(el.offsetTop)) {
ret += el.offsetTop - el.scrollTop;
el = el.parentNode;
}
return ret;
}

function getXOffset(el) {
var ret = 0;
while (el && !isNaN(el.offsetLeft)) {
ret += el.offsetLeft - el.scrollLeft;
el = el.parentNode;
}
return ret;
}


/*
* Cookies
*/
function getCookie(name) {
var search = name + "=";
if (document.cookie.length > 0) {
var offset = document.cookie.indexOf(search);
if (offset != -1) {
offset += search.length;
var end = document.cookie.indexOf(";", offset);
if (end == -1) {
end = document.cookie.length;
}
return unescape(document.cookie.substring(offset, end));
}
}
return null;
}

function setCookie(name, value, expiresDays, path) {
var newCookie = name + "=" + escape(value);
if (expiresDays != null) {
var d = new Date();
d.setTime(d.getTime() + expiresDays*24*60*60*1000);
newCookie += ("; expires=" + d.toGMTString());
}
newCookie += ("; path=" + (path == null ? "/" : path));
document.cookie = newCookie;
}

function removeCookie(name) {
setCookie(name, "", -1);
}


/*
* Some common functions for validating data and generate error messages
*/
function isValidEmail(email) {
var regex = /^[a-z0-9\._-]+@([a-z0-9_-]+\.)+[a-z]{2,6}$/i;
return regex.test(email);
}

function mixMessage(msg, values) {
var re = "";
for (var i = 0; i < values.length; i++) {
re = new RegExp("%" + (i + 1));
msg = msg.replace(re, values[i]);
}
return msg;
}

function trim(s) {
return s.replace(/^\s+|\s+$/g,"");
}
