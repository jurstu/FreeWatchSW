# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_examples_SRCS 变量
aux_source_directory(. DIR_freewatch)

include_directories(../lib/Config)
include_directories(../lib/GUI)
include_directories(../lib/LCD)
include_directories(../lib/QMI8658)
include_directories(../lib/Touch)
# 生成链接库
add_library(freewatch ${DIR_freewatch})
target_link_libraries(freewatch PUBLIC Config LCD Touch QMI8658 hardware_clocks hardware_rtc hardware_adc)
