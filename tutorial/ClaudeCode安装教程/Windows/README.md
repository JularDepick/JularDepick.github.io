# Claude Code 安装教程
- 平台：Windows(64bit)
- 前置环境：
  - Git (最新版即可)
  - Node.js (v18+)
  - ClaudeCode v2.1.xxx (本文档可能不适用于更新的版本)

## 一、安装 Git for Windows
- 下载安装包：
  - [[Git for Windows GitHub官网下载地址]](https://github.com/git-for-windows/git/releases/download/v2.54.0.windows.1/Git-2.54.0-64-bit.exe)
  - [[Git for Windows 清华镜像源下载地址]](https://mirrors.tuna.tsinghua.edu.cn/github-release/git-for-windows/git/LatestRelease/Git-2.54.0-64-bit.exe)
  - [[Git for Windows GitHub镜像源下载地址]](https://j.1lin.dpdns.org/https://github.com/git-for-windows/git/releases/download/v2.54.0.windows.1/Git-2.54.0-64-bit.exe)
- 安装：运行安装包程序，根据引导以默认选项安装
- 验证：打开新的CMD命令行，输入 `git -v` 或 `git --version` 回车，看到版本号如 `git version 2.54.0.windows.1` 则表示安装成功
- 初步配置：打开CMD命令行分别运行以下两条命令（可选，推远程仓库必用）

```cmd
git config --global user.name "此处替换为你的用户名"
git config --global user.email "此处替换为你的邮箱"
```

## 二、安装 Node.js
- 下载安装包：
  - [[Node.js 官网下载地址]](https://nodejs.org/dist/v24.15.0/node-v24.15.0-x64.msi)
  - [[Node.js 中科大镜像源下载地址]](https://mirrors.ustc.edu.cn/node/latest-v24.x/node-v24.15.0-x64.msi)
- 安装：运行安装包程序，根据引导以默认选项安装
- 验证：打开新的CMD命令行，先后输入 `node -v` 和 `npm -v` 回车，看到版本号如 `v24.15.0` 和 `11.12.1` 则表示安装成功

## 三、安装Claude Code
- 打开CMD命令行，运行以下命令（**三选一即可**）：

```
# 从阿里云平台下载安装
npm install -g @anthropic-ai/claude-code --registry=https://registry.npmmirror.com

# 从腾讯云平台下载安装
npm install -g @anthropic-ai/claude-code --registry=https://mirrors.cloud.tencent.com/npm/

# 从华为云平台下载安装
npm install -g @anthropic-ai/claude-code --registry=https://mirrors.huaweicloud.com/repository/npm/
```

- 验证：在CMD命令行输入 `claude --version` 回车，看到版本号如 `2.1.143 (Claude Code)` 则表示安装成功，然后运行 `claude` 启动一次并强制关闭（这一部是为了创建Claude的默认文件夹）

## 四、购买大模型API
- 说明：Claude Code客户端本身是免费的，但其对话核心依赖大语言模型API，而调用大语言模型API需要付费购买服务，计费按Claude Code消耗的输入输出TOKEN数量计费。可以根据自身需求和后续体验动态切换不同的API服务商。
- 提醒：如果要使用国内大语言模型（如DeepSeek、MiMo），请到国内官网购买，切勿到API中转站购买（坑）。如果要使用国外大语言模型（如Claude系列、GPT系列），才有必要找一个低价高质量的API中转站（如果不会魔法的话）。
- 打开一个权威的大模型开放平台，如 [DeepSeek开放平台](https://platform.deepseek.com)，注册并登录（部分平台需要身份证实名认证）
- 充值余额（先充一块钱试试水）
- 在开放平台页面中找到 **API Keys** （密钥）的选项或字样，打开其页面
- 在该页面中找到 **创建 API Key** 的按钮，点击创建，可能需要输入一个名称做备注
- 确认创建后会弹出一个窗口，其中形如 `sk-xxxxxxxxxxxxxxxxxxxxxxxxx` 的一串内容就是你新建的 API Key，该窗口关闭后密钥将不再完全可见，请粘贴到安全位置暂时保存
- 注意保密你创建的 API Key ，如果泄露，任何人都能使用你的账户余额，届时需要在API开放平台删除你泄露领地的 API Key 并创建新的使用
- 返回主页面，寻找类似 `开发文档` `接口文档` 的入口并点击打开页面
- 在文档页面中找一个表格，其中应该包含 `base_url (Anthropic)` 的项，注意一定要是 **Anthropic** 类型的，才能接入Claude Code
- 复制找到的 `base_url` 粘贴到安全位置暂时保存
- 查看表格中可选哪些模型，根据价格和性能选择合适模型，记住或复制模型名称，如 `deepseek-v4-pro`。注意模型名称的字母一般都是小写

## 五、为Claude Code配置API
- 打开目录 `%USERPROFILE%\.claude` 并新建一个文件 `settings.json` （如果不存在则手动创建）
- 编辑 `settings.json` ，配置文件内容解释如下：

```json
{
  "env": {
    "CLAUDE_CODE_DISABLE_NONESSENTIAL_TRAFFIC": "1", // 关闭非必要的隐私数据上报
    "ANTHROPIC_BASE_URL": "", // base_url，粘贴你在API开放平台复制到的 base_url 链接
    "ANTHROPIC_AUTH_TOKEN": "", // API Key，粘贴你在API开放平台创建并复制的 API Key
    "ANTHROPIC_MODEL": "", // 全局默认使用的模型名称，粘贴你在API开放平台选择的模型名称
    "ANTHROPIC_DEFAULT_OPUS_MODEL": "", // Opus模型(性能优先)场景下使用的模型名称
    "ANTHROPIC_DEFAULT_SONNET_MODEL": "", // Sonnet模型(性能/速度均衡)场景下使用的模型名称
    "ANTHROPIC_DEFAULT_HAIKU_MODEL": "", // Haiku模型(速度优先)场景下使用的模型名称
    "CLAUDE_CODE_SUBAGENT_MODEL": "", // 并行任务等场景下使用的子模型名称
    "CLAUDE_CODE_EFFORT_LEVEL": "max" // 思考深度等级，max 最强思考，low 最快响应
  },
  "includeCoAuthoredBy": false, // （false=不）在代码里添加 Co-Authored 署名
  "model": "opus", // 当前使用的主模型，可选 opus/sonnet/haiku，分别对应之前配置的模型名称
  "enabledPlugins": { // 启用的插件列表，不需要手动配置，留空
  },
  "skipDangerousModePermissionPrompt": true, // 跳过危险操作确认，允许直接执行高危命令，一般开启
  "theme": "dark-daltonized", // 界面主题，无需手动配置
  "hasCompletedOnboarding": true // 已完成新手引导，建议开启，无需手动配置
}
```

- 以上配置文件空白模板如下，可直接复制粘贴，修改部分参数使用：
<details><summary>展开查看</summary>

```json
{
  "env": {
    "CLAUDE_CODE_DISABLE_NONESSENTIAL_TRAFFIC": "1",
    "ANTHROPIC_BASE_URL": "https://api.deepseek.com/anthropic",
    "ANTHROPIC_AUTH_TOKEN": "APIKey",
    "ANTHROPIC_MODEL": "模型名称",
    "ANTHROPIC_DEFAULT_OPUS_MODEL": "模型名称",
    "ANTHROPIC_DEFAULT_SONNET_MODEL": "模型名称",
    "ANTHROPIC_DEFAULT_HAIKU_MODEL": "模型名称",
    "CLAUDE_CODE_SUBAGENT_MODEL": "模型名称",
    "CLAUDE_CODE_EFFORT_LEVEL": "max"
  },
  "includeCoAuthoredBy": false,
  "model": "opus",
  "enabledPlugins": {
  },
  "skipDangerousModePermissionPrompt": true,
  "theme": "dark-daltonized",
  "hasCompletedOnboarding": true
}
```

</details>

- 如果你使用的是 `DeepSeek开放平台` ，以下这套配置可以直接使用：
<details><summary>展开查看</summary>

```json
{
  "env": {
    "CLAUDE_CODE_DISABLE_NONESSENTIAL_TRAFFIC": "1",
    "ANTHROPIC_BASE_URL": "https://api.deepseek.com/anthropic",
    "ANTHROPIC_AUTH_TOKEN": "此处替换为你的APIKey",
    "ANTHROPIC_MODEL": "deepseek-v4-pro[1m]",
    "ANTHROPIC_DEFAULT_OPUS_MODEL": "deepseek-v4-pro[1m]",
    "ANTHROPIC_DEFAULT_SONNET_MODEL": "deepseek-v4-pro[1m]",
    "ANTHROPIC_DEFAULT_HAIKU_MODEL": "deepseek-v4-flash",
    "CLAUDE_CODE_SUBAGENT_MODEL": "deepseek-v4-flash",
    "CLAUDE_CODE_EFFORT_LEVEL": "max"
  },
  "includeCoAuthoredBy": false,
  "model": "opus",
  "enabledPlugins": {
  },
  "skipDangerousModePermissionPrompt": true,
  "theme": "dark-daltonized",
  "hasCompletedOnboarding": true
}
```

</details>

- 编辑好 `settings.json` 后保存即可
- 一般的 **大语言模型API开放平台** 的 **接口文档** 都会提供接入 Claude Code 等 Agent工具 终端的配置教程，这里列出几个常见的平台官方接口文档接入教程地址：
  - [[DeepSeek开放平台接口文档接入ClaudeCode教程地址]](https://api-docs.deepseek.com/zh-cn/quick_start/agent_integrations/claude_code)
  - [[XiaomiMiMo开放平台接口文档接入ClaudeCode教程地址]](https://platform.xiaomimimo.com/docs/zh-CN/integration/claudecode)
  - [[月之暗面开放平台接口文档接入ClaudeCode教程地址]](https://platform.kimi.com/docs/guide/agent-support#%E5%AE%89%E8%A3%85-claude-code)
  - [[火山引擎开放平台接口文档接入ClaudeCode教程地址]](https://www.volcengine.com/docs/82379/2373740?lang=zh)
  - [[阿里云开放平台接口文档接入ClaudeCode教程地址]](https://bailian.console.aliyun.com/cn-beijing/?spm=5176.28507329.nav-v2-dropdown-menu-0.d_main_1_0_0.26c22868zqaPKt&tab=doc&scm=20140722.M_10992489._.V_1#/doc/?type=model&url=2949529)
  - [[百度智能云开放平台接口文档接入ClaudeCode教程地址]](https://cloud.baidu.com/doc/qianfan/s/0mn2mnemj)
- 提醒：轻量模型只适用于日常对话和小型任务，要完成复杂任务还请使用高级模型，否则可能会消耗更多TOKEN和时间且效果不佳，具体可根据模型服务提供商的模型能力和性能数据选择

## 六、运行Claude Code
- 打开CMD命令行，`cd` 切换到你的工作目录（或在文件资源管理器打开你的工作目录，在路径输入框输入cmd回车打开CMD命令行）
- 运行以下命令之一开始 Claude Code ：

```cmd
# 当前目录以默认模式运行
claude

# 指定目录以默认模式运行
claude [路径]

# 以计划模式运行  ——仅规划思路，零修改、零执行，纯只读分析
claude --permission-mode plan

# 以安全不询问模式运行  ——危险操作直接拒绝，只放行安全操作
claude --permission-mode dontAsk

# 以默认模式运行  ——安全自动过，高危弹窗确认
claude --permission-mode default

# 以自动模式运行  ——自动执行常规操作，仅拦截极端高危动作，自由度偏高
claude --permission-mode auto

# 以编辑模式运行  ——允许直接编辑 / 写入项目文件
claude --permission-mode acceptEdits

# 以全放行模式运行  ——跳过全部权限校验，不拦截
claude --permission-mode bypassPermissions
```

- 如果预算充足，项目周期长，需要全自动化操作，且不担心项目被搞坏，建议以 `claude --permission-mode bypassPermissions` 方式运行

## 七、可选：安装 CCSwitch 快速切换模型服务商
- 说明：Claude Code 依赖于 `settings.json` 配置文件内容运行，本身并不提供任何快捷切换配置的功能
- CCSwitch 是一个第三方开发的小工具，用于快速切换ClaudeCode等Agent终端的模型服务商，如果需要频繁切换可选择性下载安装使用
- 官网地址：[[CCSwitch官网]](https://ccswitch.io/zh/)
- CCSwitch 目前兼容性较差，部分用户反馈切换配置失效、闪退，仅供参考
