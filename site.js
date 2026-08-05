/* 站点常量:作者信息与友情链接,替换时仅需修改本文件 */
const SITE_AUTHOR = "JularDepick";
const SITE_AUTHOR_URL = "https://github.com/JularDepick";
const SITE_REPO_URL = "https://github.com/JularDepick/JularDepick.github.io";

/* 友情链接列表:文本与网址一一对应 */
const SITE_FRIEND_LINKS = [
    { text: "RikkaLove0721's GitHub Pages", url: "https://RikkaLove0721.github.io" }
];

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

    var friendLinksBox = document.getElementById("friend-links");
    if (friendLinksBox) {
        SITE_FRIEND_LINKS.forEach(function (link) {
            var card = document.createElement("a");
            card.className = "card";
            card.href = link.url;
            card.target = "_blank";
            card.rel = "noopener";

            var icon = document.createElement("span");
            icon.className = "card-icon";
            icon.innerHTML = '<svg class="icon" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round" aria-hidden="true">' +
                '<path d="M10 13a5 5 0 0 0 7.54.54l3-3a5 5 0 0 0-7.07-7.07l-1.72 1.71"/>' +
                '<path d="M14 11a5 5 0 0 0-7.54-.54l-3 3a5 5 0 0 0 7.07 7.07l1.71-1.71"/>' +
                "</svg>";

            var body = document.createElement("span");
            body.className = "card-body";
            var title = document.createElement("span");
            title.className = "card-title";
            title.textContent = link.text;
            var desc = document.createElement("span");
            desc.className = "card-desc";
            desc.textContent = link.url;
            body.appendChild(title);
            body.appendChild(desc);

            var arrow = document.createElement("span");
            arrow.innerHTML = '<svg class="icon card-arrow" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round" aria-hidden="true">' +
                '<path d="M5 12h14"/>' +
                '<path d="m12 5 7 7-7 7"/>' +
                "</svg>";

            card.appendChild(icon);
            card.appendChild(body);
            card.appendChild(arrow);
            friendLinksBox.appendChild(card);
        });
    }
});
