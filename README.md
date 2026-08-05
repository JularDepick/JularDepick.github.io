# JularDepick.github.io

本仓库是作者 [JularDepick](https://github.com/JularDepick) 的 GitHub Pages 静态托管仓库,作为站点导航首页,收录演示项目、独立工具与教程文档,实际内容由各子项目独立部署承载。本 README 作为仓库的目录索引。

## 目录索引

| 分类 | 名称 | 说明 | 在线入口 |
|:---:|:---:|:---:|:---:|
| 演示 | ChatAnalysis.SKILL | 「往日种种」群聊深度分析站点 | [https://JularDepick.github.io/SKILL.demo/ChatAnalysis.SKILL](https://JularDepick.github.io/SKILL.demo/ChatAnalysis.SKILL) |
| 演示 | Ollama-Web-UI | Ollama 模型的 Web 界面 | [https://JularDepick.github.io/Ollama-Web-UI](https://JularDepick.github.io/Ollama-Web-UI) |
| 演示 | WindsongLyre-Simulator.fork | 原神风物之诗琴模拟器 | [https://JularDepick.github.io/WindsongLyre-Simulator.fork](https://JularDepick.github.io/WindsongLyre-Simulator.fork) |
| 工具 | GitHubNav | GitHub 导航,输入用户名查看公开仓库列表与 README 摘要 | [https://JularDepick.github.io/Web-Tool/GitHubNav](https://JularDepick.github.io/Web-Tool/GitHubNav) |
| 教程 | ClaudeCode安装教程 | Claude Code 在 Windows 平台上的安装配置教程 | [https://JularDepick.github.io/Tutorial/ToInstallClaudeCode/](https://JularDepick.github.io/Tutorial/ToInstallClaudeCode/) |

## 关联仓库

| 仓库名称 | 仓库地址 | 在线入口 |
|:---:|:---:|:---:|
| Tutorial | [https://github.com/JularDepick/Tutorial](https://github.com/JularDepick/Tutorial) | [https://JularDepick.github.io/Tutorial](https://JularDepick.github.io/Tutorial) |
| Web-Tool | [https://github.com/JularDepick/Web-Tool](https://github.com/JularDepick/Web-Tool) | [https://JularDepick.github.io/Web-Tool](https://JularDepick.github.io/Web-Tool) |
| SKILL.demo | [https://github.com/JularDepick/SKILL.demo](https://github.com/JularDepick/SKILL.demo) | [https://JularDepick.github.io/SKILL.demo](https://JularDepick.github.io/SKILL.demo) |

> SKILL.demo 聚合多个 SKILL 仓库的实例产物:SKILL 非源码,无法编译出产物,只能在具体情景下演示;各实例的演示地址记录于 `demo/README.md` 表格

## 目录结构

```
JularDepick.github.io/
├── index.html              站点导航首页
├── style.css               站内页面共享样式(设计系统 token)
├── site.js                 站点作者信息常量(页面页脚引用)
├── favicon.ico             站点图标
├── README.md               仓库目录索引
├── LICENSE                 AGPL-3.0 许可证文本
├── COPYRIGHT               版权声明
├── COMMERCIAL.md           商用授权说明
├── demo/                   演示项目索引
│   └── README.md           记录各演示项目仓库地址与演示地址的表格
├── menav/                  导航嵌入页(iframe 嵌入 Web-Tool/GitHubNav)
│   └── index.html
├── tutorial/               跳转入口(自动跳转子项目 Tutorial)
│   └── index.html
├── web-tool/               跳转入口(自动跳转子项目 Web-Tool)
│   └── index.html
├── tool/                   跳转入口(自动跳转子项目 Web-Tool)
│   └── index.html
└── .skills/                本仓库挂载的 Agent 技能
```

## 说明

- 演示项目的入口为其各自的远程 Pages 演示地址,记录于 `demo/README.md` 地址表格,维护根页面时读取该表格生成演示卡片
- 工具、教程的具体项指向对应子项目内的远程 Pages 地址,维护时查看子项目获取
- 根项目跳转到子项目或演示一律使用远程地址,不使用相对路径跨项目跳转;`tutorial/`、`web-tool/`、`tool/` 目录仍作为直接访问的跳转入口保留
- 子项目(Tutorial、Web-Tool)独立仓库开发与部署,不使用本仓库资源
- 在线访问入口:https://julardepick.github.io

## 许可证

- 本仓库采用 AGPL-3.0 许可证，详见 [[LICENSE]](./LICENSE) 。
- **商用闭源授权** 详见 [[COMMERCIAL.md]](./COMMERCIAL.md)

## 版权信息

Copyright (c) 2026 JularDepick

详见[[COPYRIGHT]](./COPYRIGHT)。
