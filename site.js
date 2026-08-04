/* 站点作者信息常量:替换作者信息时仅需修改本文件 */
const SITE_AUTHOR = "JularDepick";
const SITE_AUTHOR_URL = "https://github.com/JularDepick";
const SITE_REPO_URL = "https://github.com/JularDepick/JularDepick.github.io";

document.addEventListener("DOMContentLoaded", function () {
    var authorLink = document.getElementById("author-link");
    if (authorLink) {
        authorLink.setAttribute("href", SITE_AUTHOR_URL);
        authorLink.textContent = SITE_AUTHOR;
    }
    var repoLink = document.getElementById("repo-link");
    if (repoLink) {
        repoLink.setAttribute("href", SITE_REPO_URL);
    }
});
