## 更新日志
- 2026/05/11 [[v1.0.2]](https://github.com/JularDepick/WindsongLyre-Simulator.fork/tree/v1.0.2) [@JularDepick](https://github.com/JularDepick)
    基于上一版本 [[v1.0.1]](https://github.com/JularDepick/WindsongLyre-Simulator.fork/tree/v1.0.1) 做了如下更新：
    - 功能增强：
        - 兼容模式（离线/Chrome直接打开）下支持多音符同时发音，不再截断
        - 兼容模式下支持转调功能
    - 乐谱优化：
        - 新增休止符：逗号 `,` 表示1个单位休止，句号 `.` 表示4个单位休止
        - 输入自动过滤非法字符，提升乐谱兼容性
        - 优化大小写处理，乐谱不区分大小写
    - 项目维护：
        - 优化了项目文档的搜索引擎可见性
- 2026/05/08 [[v1.0.1]](https://github.com/JularDepick/WindsongLyre-Simulator.fork/tree/v1.0.1) [@JularDepick](https://github.com/JularDepick)
    基于上一版本 [[v1.0.0]](https://github.com/JularDepick/WindsongLyre-Simulator.fork/tree/v1.0.0) 做了如下更新：
    - bug修复：
        - 修复了同时打开多个功能弹窗的bug
        - 修复了大写状态下字母按键无响应的bug
        - 修复了离线/兼容模式下音量控制拖动条失效的bug
    - 体验优化：
        - 优化了部分UI控件的样式
        - 禁用了 Tab 键，避免浏览器聚焦到UI控件上影响体验
    - 新增功能：
        - 新增了快捷键 `ESC` ，用于关闭已打开的弹窗
