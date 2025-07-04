# Overview

cmake中的export和install(EXPORT ...)都是用于导出target的信息，但是使用时机不一样：
- export：
   1. 将当前cmake项目中的terget的构建信息导出到一个cmake(通常是xxxTargets.cmake)中，提供给其他正在构建的cmake项目
   2. 构建期间导出，适合本地开发，临时共享，不涉及安装
- install(EXPORT ...)：
   1. 将target信息导出并安装到指定目录下。用于其他项目使用
   2. 安装阶段导出，适合分发、复用、find_package查找

