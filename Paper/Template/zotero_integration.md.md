---
tags:
  - Papers
  - Readed
  - Template
---

--- 
文献标题: {{title}}
作者: {{authors}} 
发表年份: {{year}} 
期刊/会议: {{publicationTitle}} 
卷期页码: {{volume}}{{issue}}{{pages}} 
DOI: {{doi}} 
文献类型: {{itemType}} 
引用标识: {{citationKey}}
网址链接: {{url}} 
收录日期: {{accessDate}} 
标签: {{tags}} 

--- 
# {{title}} 
## 基础信息 
- 作者：{{authors}} 
- 年份：{{year}} 
- 出处：{{publicationTitle}} 
- 卷：{{volume}} 期：{{issue}} 页码：{{pages}} 
- DOI：{{doi}} 
- 文献类型：{{itemType}} 
- 引用键：{{citationKey}} 
- 原文链接：{{url}} 

## 摘要 
{{abstractNote}} 
## 核心信息 
出版社：{{publisher}} 
语言：{{language}} 
ISBN/ISSN：{{isbn}}{{issn}} 
## 我的文献笔记 
{{notes}} 
## PDF高亮批注 
{% if annotations %} 
{% for anno in annotations %} 
> 页码{{shturl.cc}}：{{shturl.cc}} 
{% if shturl.cc/Sp %} 
- 个人感悟：{{shturl.cc/Sp}} 
{% endif %} 
{% endfor %} 
{% endif %} 
## 标准引用格式 
{{citation}}

