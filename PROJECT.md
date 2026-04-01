# 脑屿 (BrainIsle) - 项目综合文档

<p align="center">
  <strong>🧠 你的脑健康伙伴</strong>
</p>

<p align="center">
  AI驱动的一站式个人脑健康主动管理平台
</p>

---

## 📋 目录

- [项目概述](#项目概述)
- [核心功能](#核心功能)
- [技术架构](#技术架构)
- [项目结构](#项目结构)
- [快速开始](#快速开始)
- [开发指南](#开发指南)
- [文档索引](#文档索引)
- [团队与贡献](#团队与贡献)

---

## 项目概述

### 愿景

**脑屿 (BrainIsle)** 是一个专注于"全脑生态"的一站式个人脑健康主动管理平台，致力于帮助用户从"认知"到"干预"全面关爱大脑健康。

在现代社会内卷严重、压力巨大的背景下，脑屿通过整合疾病科普、风险评估、AI智能咨询、AI辅助诊断与康复管理，为用户提供从引导、预防、辅助诊断到康复的完整服务链路。

### 核心问题

现代人面临严峻的脑健康挑战：
- 工作学习压力巨大，导致头疼、失眠、抑郁、焦虑等问题频发
- 大部分人选择忽视早期信号，等到问题严重时往往为时已晚
- 即使意识到问题，用户在寻求帮助时也面临重重障碍：挂号排队慢、专家不靠谱、治疗花销大、治疗效率不高

### 目标用户

| 用户类型 | 年龄段 | 核心需求 | MVP优先级 |
|---------|--------|---------|----------|
| 职场焦虑者 | 25-35岁 | 快速了解自身状态，不想去医院 | P0 (核心) |
| 心理敏感者 | 18-25岁 | 匿名了解心理状态，避免污名化 | P1 |
| 照护者/预防者 | 45-60岁 | 获取可靠信息，管理家人健康 | P2 |
| 健康管理型 | 35-50岁 | 高效管理健康数据，个性化建议 | P2 |

### 独特价值

1. **专注脑健康垂直领域**：只专注于"大脑（包括人的心智）"，提供深度而非广度
2. **自研AI辅助诊断能力**：拥有成熟的脑卒中AI算法（论文撰写中），可提供CTP灌注图合成与梗死区分析
3. **C端用户定位**：面向普通用户而非B端医院，降低专业医疗AI的使用门槛
4. **全脑生态**：结合病理性（脑卒中）和心理性（失眠/焦虑/抑郁）的完整脑健康服务
5. **全链路服务**：从引导、预防、辅助诊断到康复的一条龙服务

---

## 核心功能

### 功能模块概览

```
┌─────────────────────────────────────────────────────────────────────┐
│                         脑屿 功能架构                                │
├─────────────────────────────────────────────────────────────────────┤
│                                                                     │
│   ┌─────────────┐   ┌─────────────┐   ┌─────────────┐              │
│   │   脑语 AI   │   │   脑侦查    │   │  用户中心   │              │
│   │  智能对话   │   │  风险评估   │   │  账户管理   │              │
│   └─────────────┘   └─────────────┘   └─────────────┘              │
│         │                 │                 │                       │
│         ▼                 ▼                 ▼                       │
│   ┌─────────────────────────────────────────────────────────┐      │
│   │                    核心能力层                            │      │
│   │  • DeepSeek AI 对话    • 标准化量表评估                  │      │
│   │  • RAG 知识检索        • AI 辅助诊断（脑卒中）           │      │
│   │  • 情感识别与支持      • 历史追踪与趋势分析              │      │
│   └─────────────────────────────────────────────────────────┘      │
│                                                                     │
└─────────────────────────────────────────────────────────────────────┘
```

### 1. 脑语 AI - 智能对话系统

**核心功能：**
- 自然语言对话界面，流式响应（SSE）
- 聚焦场景：失眠、焦虑、压力、情绪低落
- 情感陪伴与倾听（混合式风格：朋友式 + 专业式）
- 健康建议与科普信息推送
- 高风险情况就医引导
- 对话历史保存与管理

**技术实现：**
- DeepSeek API + Vercel AI SDK 5.0
- pgvector RAG 知识检索
- 场景化 System Prompt

### 2. 脑侦查 - 风险评估系统

**支持的评估量表：**
- ISI 失眠严重程度指数（7题）
- GAD-7 广泛性焦虑障碍量表（7题）
- PHQ-9 患者健康问卷/抑郁筛查（9题）

**核心功能：**
- 温和的结果呈现（去污名化）
- 基于评估结果的改善建议
- 高风险就医引导
- 历史记录与趋势追踪
- 定期评估提醒

**脑卒中模块 - AI 看片诊断：**
- 支持 nii.gz 格式医学影像上传
- CTP 灌注图生成（CBF、CBV、Tmax）
- 核心梗死区 + 缺血半暗带识别
- Mismatch 比值计算
- 通俗语言结果解读
- 免责声明与就医引导

### 3. 用户中心

**核心功能：**
- 用户注册/登录（支持匿名模式）
- 匿名转正式用户（数据保留）
- 评估历史记录
- AI 对话历史
- 数据导出与删除
- 隐私设置

---

## 技术架构

### 技术栈概览

| 层级 | 技术选择 | 版本 |
|------|---------|------|
| **前端框架** | Next.js (App Router) | 15.5+ |
| **UI 框架** | React | 19 |
| **语言** | TypeScript | 5.0+ |
| **样式** | Tailwind CSS | 4.0+ |
| **组件库** | shadcn/ui (New York style) | - |
| **状态管理** | Zustand | 5.0+ |
| **数据获取** | TanStack Query | 5.0+ |
| **表单处理** | React Hook Form + Zod | - |
| **后端 API** | Next.js API Routes (REST) | - |
| **数据库** | Supabase (PostgreSQL + pgvector) | 15+ |
| **认证** | Supabase Auth (含匿名认证) | - |
| **AI 对话** | DeepSeek API + Vercel AI SDK | 5.0 |
| **AI 诊断** | Modal.com (Serverless GPU) + PyTorch | - |
| **部署** | Vercel (前端) + Supabase + Modal.com | - |

### 架构图

```
┌─────────────────────────────────────────────────────────────────────┐
│                           用户层                                     │
│                    浏览器 / PWA / 移动端                             │
└─────────────────────────────────────────────────────────────────────┘
                                │
                                ▼
┌─────────────────────────────────────────────────────────────────────┐
│                         前端层 (Vercel)                              │
│  ┌─────────────────────────────────────────────────────────────┐   │
│  │                    Next.js 15.5+ App Router                  │   │
│  │  ┌─────────────┐  ┌─────────────┐  ┌─────────────┐         │   │
│  │  │   Pages     │  │  Components │  │   Hooks     │         │   │
│  │  │  (RSC/CSR)  │  │  (shadcn)   │  │  (Custom)   │         │   │
│  │  └─────────────┘  └─────────────┘  └─────────────┘         │   │
│  │  ┌─────────────┐  ┌─────────────┐  ┌─────────────┐         │   │
│  │  │   Zustand   │  │  TanStack   │  │  Vercel AI  │         │   │
│  │  │   Stores    │  │   Query     │  │    SDK      │         │   │
│  │  └─────────────┘  └─────────────┘  └─────────────┘         │   │
│  └─────────────────────────────────────────────────────────────┘   │
└─────────────────────────────────────────────────────────────────────┘
                                │
                                ▼
┌─────────────────────────────────────────────────────────────────────┐
│                         API 层 (Next.js)                             │
│  ┌─────────────────────────────────────────────────────────────┐   │
│  │                    API Routes (REST)                         │   │
│  │  /api/auth/*     /api/chat/*     /api/assessment/*          │   │
│  │  /api/diagnosis/*  /api/user/*   /api/content/*             │   │
│  └─────────────────────────────────────────────────────────────┘   │
└─────────────────────────────────────────────────────────────────────┘
                                │
                ┌───────────────┼───────────────┐
                ▼               ▼               ▼
┌───────────────────┐ ┌───────────────────┐ ┌───────────────────┐
│    Supabase       │ │    DeepSeek       │ │    Modal.com      │
│  ┌─────────────┐  │ │  ┌─────────────┐  │ │  ┌─────────────┐  │
│  │ PostgreSQL  │  │ │  │   Chat API  │  │ │  │  GPU 推理   │  │
│  │  + pgvector │  │ │  │   (SSE)     │  │ │  │  (PyTorch)  │  │
│  └─────────────┘  │ │  └─────────────┘  │ │  └─────────────┘  │
│  ┌─────────────┐  │ │                   │ │  ┌─────────────┐  │
│  │    Auth     │  │ │                   │ │  │  CTP 生成   │  │
│  │  (匿名支持) │  │ │                   │ │  │   模型      │  │
│  └─────────────┘  │ │                   │ │  └─────────────┘  │
│  ┌─────────────┐  │ │                   │ │                   │
│  │   Storage   │  │ │                   │ │                   │
│  └─────────────┘  │ │                   │ │                   │
└───────────────────┘ └───────────────────┘ └───────────────────┘
```

### 命名约定

| 类型 | 约定 | 示例 |
|------|------|------|
| 数据库表/列 | snake_case | `user_profiles`, `created_at` |
| API 端点 | kebab-case, 复数名词 | `/api/chat-sessions`, `/api/assessments` |
| React 组件 | PascalCase | `ChatContainer`, `AssessmentCard` |
| 函数/变量 | camelCase | `getUserProfile`, `isLoading` |
| 常量 | SCREAMING_SNAKE_CASE | `MAX_RETRY_COUNT` |
| 类型/接口 | PascalCase | `UserProfile`, `ChatMessage` |
| 文件名 | kebab-case | `chat-container.tsx`, `use-auth.ts` |

### API 响应格式

```typescript
// 成功响应
{
  "success": true,
  "data": { ... },
  "meta": {
    "page": 1,
    "limit": 20,
    "total": 100
  }
}

// 错误响应
{
  "success": false,
  "error": {
    "code": "VALIDATION_ERROR",
    "message": "用户友好的错误信息",
    "details": { ... }
  }
}
```

---

## 项目结构

```
brainisle/
├── src/
│   ├── app/                    # Next.js App Router
│   │   ├── (main)/            # 主应用布局组
│   │   │   ├── chat/          # 脑语 AI 对话
│   │   │   ├── detective/     # 脑侦查评估
│   │   │   │   └── stroke/    # 脑卒中模块
│   │   │   │       └── ai-scan/  # AI 看片
│   │   │   ├── profile/       # 用户中心
│   │   │   └── layout.tsx     # 主布局（含底部导航）
│   │   ├── api/               # API 路由
│   │   │   ├── auth/          # 认证相关
│   │   │   ├── chat/          # 对话相关
│   │   │   │   └── stream/    # SSE 流式响应
│   │   │   ├── assessment/    # 评估相关
│   │   │   ├── diagnosis/     # 诊断相关
│   │   │   └── user/          # 用户相关
│   │   ├── layout.tsx         # 根布局
│   │   └── page.tsx           # 首页
│   │
│   ├── components/            # React 组件
│   │   ├── ui/               # shadcn/ui 基础组件
│   │   ├── chat/             # 对话相关组件
│   │   ├── assessment/       # 评估相关组件
│   │   ├── diagnosis/        # 诊断相关组件
│   │   └── common/           # 通用组件
│   │
│   ├── hooks/                # 自定义 Hooks
│   │   ├── useAuth.ts
│   │   ├── useChat.ts
│   │   └── ...
│   │
│   ├── lib/                  # 工具库
│   │   ├── supabase/         # Supabase 客户端
│   │   ├── ai/               # AI 相关
│   │   │   ├── deepseek.ts   # DeepSeek 客户端
│   │   │   ├── prompts.ts    # 提示词模板
│   │   │   └── rag.ts        # RAG 检索
│   │   ├── assessment/       # 评估逻辑
│   │   └── utils.ts          # 通用工具
│   │
│   ├── stores/               # Zustand 状态管理
│   │   ├── authStore.ts
│   │   ├── chatStore.ts
│   │   └── uiStore.ts
│   │
│   ├── types/                # TypeScript 类型定义
│   │   └── index.ts
│   │
│   └── providers/            # React Context Providers
│       └── index.tsx
│
├── public/                   # 静态资源
├── supabase/                 # Supabase 配置
│   └── migrations/           # 数据库迁移
├── docs/                     # 项目文档
└── .bmad/                    # BMAD 方法论文档
    └── docs/                 # 设计文档
        ├── prd.md           # 产品需求文档
        ├── architecture.md  # 架构设计文档
        ├── ux-design-specification.md  # UX 设计规范
        └── epics.md         # Epic 和 Story 分解
```

---

## 快速开始

### 环境要求

- Node.js 18.17+
- pnpm 8.0+ (推荐) 或 npm
- Git

### 安装步骤

1. **克隆仓库**
```bash
git clone <repository-url>
cd 2b/brainisle
```

2. **安装依赖**
```bash
pnpm install
# 或
npm install
```

3. **配置环境变量**
```bash
cp .env.example .env.local
```

编辑 `.env.local` 文件，填入必要的配置：
```env
# Supabase
NEXT_PUBLIC_SUPABASE_URL=your_supabase_url
NEXT_PUBLIC_SUPABASE_ANON_KEY=your_supabase_anon_key

# DeepSeek AI
DEEPSEEK_API_KEY=your_deepseek_api_key
DEEPSEEK_BASE_URL=https://api.deepseek.com

# Modal.com (可选，用于 AI 诊断)
MODAL_TOKEN_ID=your_modal_token_id
MODAL_TOKEN_SECRET=your_modal_token_secret
```

4. **启动开发服务器**
```bash
pnpm dev
# 或
npm run dev
```

5. **访问应用**
打开浏览器访问 http://localhost:3000

### 快速启动脚本

Windows 用户可以使用提供的启动脚本：
- `start.bat` - 命令行启动
- `start.ps1` - PowerShell 启动

---

## 开发指南

### 代码规范

- 使用 ESLint + Prettier 进行代码格式化
- 遵循 TypeScript 严格模式
- 组件使用函数式组件 + Hooks
- 状态管理使用 Zustand（不可变更新）
- 数据获取使用 TanStack Query

### Git 工作流

```
main (生产环境)
  └── develop (开发环境)
        ├── feature/xxx (功能分支)
        ├── bugfix/xxx (修复分支)
        └── hotfix/xxx (紧急修复)
```

### 提交规范

```
<type>(<scope>): <subject>

类型：
- feat: 新功能
- fix: 修复
- docs: 文档
- style: 格式
- refactor: 重构
- test: 测试
- chore: 构建/工具
```

### 开发流程

1. 从 `develop` 创建功能分支
2. 开发并测试功能
3. 提交 PR 到 `develop`
4. Code Review 后合并
5. 定期从 `develop` 合并到 `main` 发布

---

## 文档索引

### 核心设计文档

| 文档 | 路径 | 描述 |
|------|------|------|
| 产品需求文档 (PRD) | [`.bmad/docs/prd.md`](.bmad/docs/prd.md) | 完整的产品需求，56条功能需求 + 40项非功能需求 |
| 架构设计文档 | [`.bmad/docs/architecture.md`](.bmad/docs/architecture.md) | 技术架构决策，命名约定，实现模式 |
| UX 设计规范 | [`.bmad/docs/ux-design-specification.md`](.bmad/docs/ux-design-specification.md) | 用户体验设计，视觉规范，组件策略 |
| Epic 分解 | [`.bmad/docs/epics.md`](.bmad/docs/epics.md) | 7个 Epic，49个 Story，100% FR 覆盖 |

### 技术文档

| 文档 | 路径 | 描述 |
|------|------|------|
| API 规范 | [`docs/api-specification.md`](docs/api-specification.md) | REST API 端点定义 |
| 数据库 Schema | [`docs/database-schema.md`](docs/database-schema.md) | PostgreSQL 表结构设计 |
| 开发路线图 | [`docs/development-roadmap.md`](docs/development-roadmap.md) | 10周开发计划 |

### 团队文档

| 文档 | 路径 | 描述 |
|------|------|------|
| 新人指南 | [`docs/onboarding-guide.md`](docs/onboarding-guide.md) | 环境配置，技术栈入门 |
| 项目管理指南 | [`docs/project-management-guide.md`](docs/project-management-guide.md) | Git 流程，会议规范 |

---

## 团队与贡献

### 项目状态

- **当前阶段**: MVP 开发中
- **目标**: 10,000 MAU (MVP) → 100,000 MAU (12个月)
- **开发周期**: 约 10 周

### Epic 开发计划

| Sprint   | Epic             | 内容          | 状态     |
| -------- | ---------------- | ----------- | ------ |
| Sprint 1 | Epic 1           | 项目基础设施      | 🟢 进行中 |
| Sprint 2 | Epic 2 + 7.1-7.3 | 用户认证 + 基础页面 | ⚪ 待开始  |
| Sprint 3 | Epic 3           | 脑语 AI 对话    | ⚪ 待开始  |
| Sprint 4 | Epic 4           | 脑侦查评估       | ⚪ 待开始  |
| Sprint 5 | Epic 5           | AI 看片诊断     | ⚪ 待开始  |
| Sprint 6 | Epic 6 + 7.4-7.7 | 用户中心 + 完善   | ⚪ 待开始  |

### 贡献指南

1. Fork 本仓库
2. 创建功能分支 (`git checkout -b feature/amazing-feature`)
3. 提交更改 (`git commit -m 'feat: add amazing feature'`)
4. 推送到分支 (`git push origin feature/amazing-feature`)
5. 创建 Pull Request

### 联系方式

- **项目负责人**: Drinkingwater
- **创建日期**: 2025-12-05

---

## 许可证

本项目为私有项目，未经授权不得使用、复制或分发。

---

<p align="center">
  <sub>Built with ❤️ for brain health</sub>
</p>