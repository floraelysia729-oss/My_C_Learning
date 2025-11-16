# My_C_Learning

储存、记录C语言学习代码和反思

## 📂 仓库结构

```
My_C_Learning/
├── exercises/          # 日常练习代码
│   ├── TEMPLATE.md    # 练习模板
│   └── YYYY-MM-DD_练习名称/
│       ├── README.md
│       └── 源代码.c
├── projects/          # 综合项目
│   └── 项目名称/
├── notes/             # 学习笔记和反思
└── README.md
```

## 🎯 使用指南

### 添加日常练习

1. 在 `exercises/` 目录下创建新文件夹，命名格式：`YYYY-MM-DD_练习名称`
2. 参考 `exercises/TEMPLATE.md` 创建练习文件
3. 每个练习包含：
   - 源代码文件（.c）
   - README.md（说明、笔记、运行方法）

**示例：**
```bash
cd exercises
mkdir 2025-11-16_variables
cd 2025-11-16_variables
# 创建 README.md 和 .c 文件
```

### 添加项目

1. 在 `projects/` 目录下创建项目文件夹
2. 按照 `projects/README.md` 中的建议组织代码
3. 为项目编写详细的 README 文档

### 记录学习笔记

1. 在 `notes/` 目录下创建笔记文件
2. 可以按主题或日期组织
3. 记录学习过程中的理解、问题和解决方案

## 📝 示例练习

查看 `exercises/2025-11-16_hello_world/` 获取一个完整的练习示例。

## 🔧 编译和运行

### 基本命令
```bash
# 编译单个C文件
gcc 源文件.c -o 输出文件

# 运行编译后的程序
./输出文件

# 编译时显示所有警告
gcc -Wall 源文件.c -o 输出文件
```

### 调试
```bash
# 编译时包含调试信息
gcc -g 源文件.c -o 输出文件

# 使用gdb调试
gdb ./输出文件
```

## 📚 学习建议

1. **每天练习**：坚持每天写代码，哪怕只是小练习
2. **记录笔记**：将学到的知识点和遇到的问题记录下来
3. **代码注释**：养成写注释的习惯，解释代码的思路
4. **定期回顾**：定期回顾之前的代码，看看能否改进
5. **动手实践**：看书学习的同时，一定要动手实践

## 🎓 学习资源

- C语言程序设计（谭浩强）
- The C Programming Language (K&R)
- C Primer Plus
- [cppreference.com](https://en.cppreference.com/w/c)

## 📈 学习进度

在这里记录你的学习进度和里程碑：

- [ ] 基础语法（变量、数据类型、运算符）
- [ ] 控制结构（if、switch、循环）
- [ ] 函数
- [ ] 数组和字符串
- [ ] 指针
- [ ] 结构体和联合
- [ ] 文件操作
- [ ] 动态内存分配
- [ ] 预处理器
- [ ] 标准库函数
