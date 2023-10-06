
# Consider dependencies only in project.
set(CMAKE_DEPENDS_IN_PROJECT_ONLY OFF)

# The set of languages for which implicit dependencies are needed:
set(CMAKE_DEPENDS_LANGUAGES
  "ASM"
  )
# The set of files for implicit dependencies of each language:
set(CMAKE_DEPENDS_CHECK_ASM
  "/root/pico/pico-sdk/src/rp2_common/hardware_divider/divider.S" "/root/projects/FreeWatchSW/c-example/bild/freeWatch/CMakeFiles/freewatch.dir/root/pico/pico-sdk/src/rp2_common/hardware_divider/divider.S.obj"
  "/root/pico/pico-sdk/src/rp2_common/hardware_irq/irq_handler_chain.S" "/root/projects/FreeWatchSW/c-example/bild/freeWatch/CMakeFiles/freewatch.dir/root/pico/pico-sdk/src/rp2_common/hardware_irq/irq_handler_chain.S.obj"
  "/root/pico/pico-sdk/src/rp2_common/pico_bit_ops/bit_ops_aeabi.S" "/root/projects/FreeWatchSW/c-example/bild/freeWatch/CMakeFiles/freewatch.dir/root/pico/pico-sdk/src/rp2_common/pico_bit_ops/bit_ops_aeabi.S.obj"
  "/root/pico/pico-sdk/src/rp2_common/pico_divider/divider.S" "/root/projects/FreeWatchSW/c-example/bild/freeWatch/CMakeFiles/freewatch.dir/root/pico/pico-sdk/src/rp2_common/pico_divider/divider.S.obj"
  "/root/pico/pico-sdk/src/rp2_common/pico_double/double_aeabi.S" "/root/projects/FreeWatchSW/c-example/bild/freeWatch/CMakeFiles/freewatch.dir/root/pico/pico-sdk/src/rp2_common/pico_double/double_aeabi.S.obj"
  "/root/pico/pico-sdk/src/rp2_common/pico_double/double_v1_rom_shim.S" "/root/projects/FreeWatchSW/c-example/bild/freeWatch/CMakeFiles/freewatch.dir/root/pico/pico-sdk/src/rp2_common/pico_double/double_v1_rom_shim.S.obj"
  "/root/pico/pico-sdk/src/rp2_common/pico_float/float_aeabi.S" "/root/projects/FreeWatchSW/c-example/bild/freeWatch/CMakeFiles/freewatch.dir/root/pico/pico-sdk/src/rp2_common/pico_float/float_aeabi.S.obj"
  "/root/pico/pico-sdk/src/rp2_common/pico_float/float_v1_rom_shim.S" "/root/projects/FreeWatchSW/c-example/bild/freeWatch/CMakeFiles/freewatch.dir/root/pico/pico-sdk/src/rp2_common/pico_float/float_v1_rom_shim.S.obj"
  "/root/pico/pico-sdk/src/rp2_common/pico_int64_ops/pico_int64_ops_aeabi.S" "/root/projects/FreeWatchSW/c-example/bild/freeWatch/CMakeFiles/freewatch.dir/root/pico/pico-sdk/src/rp2_common/pico_int64_ops/pico_int64_ops_aeabi.S.obj"
  "/root/pico/pico-sdk/src/rp2_common/pico_mem_ops/mem_ops_aeabi.S" "/root/projects/FreeWatchSW/c-example/bild/freeWatch/CMakeFiles/freewatch.dir/root/pico/pico-sdk/src/rp2_common/pico_mem_ops/mem_ops_aeabi.S.obj"
  "/root/pico/pico-sdk/src/rp2_common/pico_standard_link/crt0.S" "/root/projects/FreeWatchSW/c-example/bild/freeWatch/CMakeFiles/freewatch.dir/root/pico/pico-sdk/src/rp2_common/pico_standard_link/crt0.S.obj"
  )

# Preprocessor definitions for this target.
set(CMAKE_TARGET_DEFINITIONS_ASM
  "LIB_PICO_BIT_OPS=1"
  "LIB_PICO_BIT_OPS_PICO=1"
  "LIB_PICO_DIVIDER=1"
  "LIB_PICO_DIVIDER_HARDWARE=1"
  "LIB_PICO_DOUBLE=1"
  "LIB_PICO_DOUBLE_PICO=1"
  "LIB_PICO_FLOAT=1"
  "LIB_PICO_FLOAT_PICO=1"
  "LIB_PICO_INT64_OPS=1"
  "LIB_PICO_INT64_OPS_PICO=1"
  "LIB_PICO_MALLOC=1"
  "LIB_PICO_MEM_OPS=1"
  "LIB_PICO_MEM_OPS_PICO=1"
  "LIB_PICO_PLATFORM=1"
  "LIB_PICO_PRINTF=1"
  "LIB_PICO_PRINTF_PICO=1"
  "LIB_PICO_RUNTIME=1"
  "LIB_PICO_STANDARD_LINK=1"
  "LIB_PICO_STDIO=1"
  "LIB_PICO_STDIO_UART=1"
  "LIB_PICO_STDLIB=1"
  "LIB_PICO_SYNC=1"
  "LIB_PICO_SYNC_CRITICAL_SECTION=1"
  "LIB_PICO_SYNC_MUTEX=1"
  "LIB_PICO_SYNC_SEM=1"
  "LIB_PICO_TIME=1"
  "LIB_PICO_UTIL=1"
  "PICO_BOARD=\"pico\""
  "PICO_BUILD=1"
  "PICO_CMAKE_BUILD_TYPE=\"Release\""
  "PICO_COPY_TO_RAM=0"
  "PICO_CXX_ENABLE_EXCEPTIONS=0"
  "PICO_NO_FLASH=0"
  "PICO_NO_HARDWARE=0"
  "PICO_ON_DEVICE=1"
  "PICO_USE_BLOCKED_RAM=0"
  )

# The include file search paths:
set(CMAKE_ASM_TARGET_INCLUDE_PATH
  "../freeWatch/../lib/Config"
  "../freeWatch/../lib/GUI"
  "../freeWatch/../lib/LCD"
  "../freeWatch/../lib/QMI8658"
  "../freeWatch/../lib/Touch"
  "freeWatch"
  "/root/pico/pico-sdk/src/rp2_common/hardware_pio/include"
  "/root/pico/pico-sdk/src/common/pico_base/include"
  "generated/pico_base"
  "/root/pico/pico-sdk/src/boards/include"
  "/root/pico/pico-sdk/src/rp2_common/pico_platform/include"
  "/root/pico/pico-sdk/src/rp2040/hardware_regs/include"
  "/root/pico/pico-sdk/src/rp2_common/hardware_base/include"
  "/root/pico/pico-sdk/src/rp2040/hardware_structs/include"
  "/root/pico/pico-sdk/src/rp2_common/hardware_claim/include"
  "/root/pico/pico-sdk/src/rp2_common/hardware_sync/include"
  "/root/pico/pico-sdk/src/rp2_common/hardware_gpio/include"
  "/root/pico/pico-sdk/src/rp2_common/hardware_irq/include"
  "/root/pico/pico-sdk/src/common/pico_sync/include"
  "/root/pico/pico-sdk/src/common/pico_time/include"
  "/root/pico/pico-sdk/src/rp2_common/hardware_timer/include"
  "/root/pico/pico-sdk/src/common/pico_util/include"
  "/root/pico/pico-sdk/src/common/pico_stdlib/include"
  "/root/pico/pico-sdk/src/rp2_common/hardware_uart/include"
  "/root/pico/pico-sdk/src/rp2_common/hardware_resets/include"
  "/root/pico/pico-sdk/src/rp2_common/hardware_clocks/include"
  "/root/pico/pico-sdk/src/rp2_common/hardware_pll/include"
  "/root/pico/pico-sdk/src/rp2_common/hardware_vreg/include"
  "/root/pico/pico-sdk/src/rp2_common/hardware_watchdog/include"
  "/root/pico/pico-sdk/src/rp2_common/hardware_xosc/include"
  "/root/pico/pico-sdk/src/rp2_common/hardware_divider/include"
  "/root/pico/pico-sdk/src/rp2_common/pico_runtime/include"
  "/root/pico/pico-sdk/src/rp2_common/pico_printf/include"
  "/root/pico/pico-sdk/src/common/pico_bit_ops/include"
  "/root/pico/pico-sdk/src/common/pico_divider/include"
  "/root/pico/pico-sdk/src/rp2_common/pico_double/include"
  "/root/pico/pico-sdk/src/rp2_common/pico_float/include"
  "/root/pico/pico-sdk/src/rp2_common/pico_malloc/include"
  "/root/pico/pico-sdk/src/rp2_common/pico_bootrom/include"
  "/root/pico/pico-sdk/src/common/pico_binary_info/include"
  "/root/pico/pico-sdk/src/rp2_common/pico_stdio/include"
  "/root/pico/pico-sdk/src/rp2_common/pico_stdio_uart/include"
  "/root/pico/pico-sdk/src/rp2_common/pico_int64_ops/include"
  "/root/pico/pico-sdk/src/rp2_common/pico_mem_ops/include"
  "/root/pico/pico-sdk/src/rp2_common/boot_stage2/include"
  "/root/pico/pico-sdk/src/rp2_common/hardware_spi/include"
  "/root/pico/pico-sdk/src/rp2_common/hardware_i2c/include"
  "/root/pico/pico-sdk/src/rp2_common/hardware_pwm/include"
  "/root/pico/pico-sdk/src/rp2_common/hardware_adc/include"
  "/root/pico/pico-sdk/src/rp2_common/hardware_rtc/include"
  )

# The set of dependency files which are needed:
set(CMAKE_DEPENDS_DEPENDENCY_FILES
  "/root/projects/FreeWatchSW/c-example/freeWatch/GPS.c" "freeWatch/CMakeFiles/freewatch.dir/GPS.c.obj" "gcc" "freeWatch/CMakeFiles/freewatch.dir/GPS.c.obj.d"
  "/root/projects/FreeWatchSW/c-example/freeWatch/buttons.c" "freeWatch/CMakeFiles/freewatch.dir/buttons.c.obj" "gcc" "freeWatch/CMakeFiles/freewatch.dir/buttons.c.obj.d"
  "/root/projects/FreeWatchSW/c-example/freeWatch/colors.c" "freeWatch/CMakeFiles/freewatch.dir/colors.c.obj" "gcc" "freeWatch/CMakeFiles/freewatch.dir/colors.c.obj.d"
  "/root/projects/FreeWatchSW/c-example/freeWatch/ext_i2c.c" "freeWatch/CMakeFiles/freewatch.dir/ext_i2c.c.obj" "gcc" "freeWatch/CMakeFiles/freewatch.dir/ext_i2c.c.obj.d"
  "/root/projects/FreeWatchSW/c-example/freeWatch/information.c" "freeWatch/CMakeFiles/freewatch.dir/information.c.obj" "gcc" "freeWatch/CMakeFiles/freewatch.dir/information.c.obj.d"
  "/root/projects/FreeWatchSW/c-example/freeWatch/mcp23008.c" "freeWatch/CMakeFiles/freewatch.dir/mcp23008.c.obj" "gcc" "freeWatch/CMakeFiles/freewatch.dir/mcp23008.c.obj.d"
  "/root/projects/FreeWatchSW/c-example/freeWatch/minmea.c" "freeWatch/CMakeFiles/freewatch.dir/minmea.c.obj" "gcc" "freeWatch/CMakeFiles/freewatch.dir/minmea.c.obj.d"
  "/root/pico/pico-sdk/src/common/pico_sync/critical_section.c" "freeWatch/CMakeFiles/freewatch.dir/root/pico/pico-sdk/src/common/pico_sync/critical_section.c.obj" "gcc" "freeWatch/CMakeFiles/freewatch.dir/root/pico/pico-sdk/src/common/pico_sync/critical_section.c.obj.d"
  "/root/pico/pico-sdk/src/common/pico_sync/lock_core.c" "freeWatch/CMakeFiles/freewatch.dir/root/pico/pico-sdk/src/common/pico_sync/lock_core.c.obj" "gcc" "freeWatch/CMakeFiles/freewatch.dir/root/pico/pico-sdk/src/common/pico_sync/lock_core.c.obj.d"
  "/root/pico/pico-sdk/src/common/pico_sync/mutex.c" "freeWatch/CMakeFiles/freewatch.dir/root/pico/pico-sdk/src/common/pico_sync/mutex.c.obj" "gcc" "freeWatch/CMakeFiles/freewatch.dir/root/pico/pico-sdk/src/common/pico_sync/mutex.c.obj.d"
  "/root/pico/pico-sdk/src/common/pico_sync/sem.c" "freeWatch/CMakeFiles/freewatch.dir/root/pico/pico-sdk/src/common/pico_sync/sem.c.obj" "gcc" "freeWatch/CMakeFiles/freewatch.dir/root/pico/pico-sdk/src/common/pico_sync/sem.c.obj.d"
  "/root/pico/pico-sdk/src/common/pico_time/time.c" "freeWatch/CMakeFiles/freewatch.dir/root/pico/pico-sdk/src/common/pico_time/time.c.obj" "gcc" "freeWatch/CMakeFiles/freewatch.dir/root/pico/pico-sdk/src/common/pico_time/time.c.obj.d"
  "/root/pico/pico-sdk/src/common/pico_time/timeout_helper.c" "freeWatch/CMakeFiles/freewatch.dir/root/pico/pico-sdk/src/common/pico_time/timeout_helper.c.obj" "gcc" "freeWatch/CMakeFiles/freewatch.dir/root/pico/pico-sdk/src/common/pico_time/timeout_helper.c.obj.d"
  "/root/pico/pico-sdk/src/common/pico_util/datetime.c" "freeWatch/CMakeFiles/freewatch.dir/root/pico/pico-sdk/src/common/pico_util/datetime.c.obj" "gcc" "freeWatch/CMakeFiles/freewatch.dir/root/pico/pico-sdk/src/common/pico_util/datetime.c.obj.d"
  "/root/pico/pico-sdk/src/common/pico_util/pheap.c" "freeWatch/CMakeFiles/freewatch.dir/root/pico/pico-sdk/src/common/pico_util/pheap.c.obj" "gcc" "freeWatch/CMakeFiles/freewatch.dir/root/pico/pico-sdk/src/common/pico_util/pheap.c.obj.d"
  "/root/pico/pico-sdk/src/common/pico_util/queue.c" "freeWatch/CMakeFiles/freewatch.dir/root/pico/pico-sdk/src/common/pico_util/queue.c.obj" "gcc" "freeWatch/CMakeFiles/freewatch.dir/root/pico/pico-sdk/src/common/pico_util/queue.c.obj.d"
  "/root/pico/pico-sdk/src/rp2_common/hardware_adc/adc.c" "freeWatch/CMakeFiles/freewatch.dir/root/pico/pico-sdk/src/rp2_common/hardware_adc/adc.c.obj" "gcc" "freeWatch/CMakeFiles/freewatch.dir/root/pico/pico-sdk/src/rp2_common/hardware_adc/adc.c.obj.d"
  "/root/pico/pico-sdk/src/rp2_common/hardware_claim/claim.c" "freeWatch/CMakeFiles/freewatch.dir/root/pico/pico-sdk/src/rp2_common/hardware_claim/claim.c.obj" "gcc" "freeWatch/CMakeFiles/freewatch.dir/root/pico/pico-sdk/src/rp2_common/hardware_claim/claim.c.obj.d"
  "/root/pico/pico-sdk/src/rp2_common/hardware_clocks/clocks.c" "freeWatch/CMakeFiles/freewatch.dir/root/pico/pico-sdk/src/rp2_common/hardware_clocks/clocks.c.obj" "gcc" "freeWatch/CMakeFiles/freewatch.dir/root/pico/pico-sdk/src/rp2_common/hardware_clocks/clocks.c.obj.d"
  "/root/pico/pico-sdk/src/rp2_common/hardware_gpio/gpio.c" "freeWatch/CMakeFiles/freewatch.dir/root/pico/pico-sdk/src/rp2_common/hardware_gpio/gpio.c.obj" "gcc" "freeWatch/CMakeFiles/freewatch.dir/root/pico/pico-sdk/src/rp2_common/hardware_gpio/gpio.c.obj.d"
  "/root/pico/pico-sdk/src/rp2_common/hardware_i2c/i2c.c" "freeWatch/CMakeFiles/freewatch.dir/root/pico/pico-sdk/src/rp2_common/hardware_i2c/i2c.c.obj" "gcc" "freeWatch/CMakeFiles/freewatch.dir/root/pico/pico-sdk/src/rp2_common/hardware_i2c/i2c.c.obj.d"
  "/root/pico/pico-sdk/src/rp2_common/hardware_irq/irq.c" "freeWatch/CMakeFiles/freewatch.dir/root/pico/pico-sdk/src/rp2_common/hardware_irq/irq.c.obj" "gcc" "freeWatch/CMakeFiles/freewatch.dir/root/pico/pico-sdk/src/rp2_common/hardware_irq/irq.c.obj.d"
  "/root/pico/pico-sdk/src/rp2_common/hardware_pio/pio.c" "freeWatch/CMakeFiles/freewatch.dir/root/pico/pico-sdk/src/rp2_common/hardware_pio/pio.c.obj" "gcc" "freeWatch/CMakeFiles/freewatch.dir/root/pico/pico-sdk/src/rp2_common/hardware_pio/pio.c.obj.d"
  "/root/pico/pico-sdk/src/rp2_common/hardware_pll/pll.c" "freeWatch/CMakeFiles/freewatch.dir/root/pico/pico-sdk/src/rp2_common/hardware_pll/pll.c.obj" "gcc" "freeWatch/CMakeFiles/freewatch.dir/root/pico/pico-sdk/src/rp2_common/hardware_pll/pll.c.obj.d"
  "/root/pico/pico-sdk/src/rp2_common/hardware_rtc/rtc.c" "freeWatch/CMakeFiles/freewatch.dir/root/pico/pico-sdk/src/rp2_common/hardware_rtc/rtc.c.obj" "gcc" "freeWatch/CMakeFiles/freewatch.dir/root/pico/pico-sdk/src/rp2_common/hardware_rtc/rtc.c.obj.d"
  "/root/pico/pico-sdk/src/rp2_common/hardware_spi/spi.c" "freeWatch/CMakeFiles/freewatch.dir/root/pico/pico-sdk/src/rp2_common/hardware_spi/spi.c.obj" "gcc" "freeWatch/CMakeFiles/freewatch.dir/root/pico/pico-sdk/src/rp2_common/hardware_spi/spi.c.obj.d"
  "/root/pico/pico-sdk/src/rp2_common/hardware_sync/sync.c" "freeWatch/CMakeFiles/freewatch.dir/root/pico/pico-sdk/src/rp2_common/hardware_sync/sync.c.obj" "gcc" "freeWatch/CMakeFiles/freewatch.dir/root/pico/pico-sdk/src/rp2_common/hardware_sync/sync.c.obj.d"
  "/root/pico/pico-sdk/src/rp2_common/hardware_timer/timer.c" "freeWatch/CMakeFiles/freewatch.dir/root/pico/pico-sdk/src/rp2_common/hardware_timer/timer.c.obj" "gcc" "freeWatch/CMakeFiles/freewatch.dir/root/pico/pico-sdk/src/rp2_common/hardware_timer/timer.c.obj.d"
  "/root/pico/pico-sdk/src/rp2_common/hardware_uart/uart.c" "freeWatch/CMakeFiles/freewatch.dir/root/pico/pico-sdk/src/rp2_common/hardware_uart/uart.c.obj" "gcc" "freeWatch/CMakeFiles/freewatch.dir/root/pico/pico-sdk/src/rp2_common/hardware_uart/uart.c.obj.d"
  "/root/pico/pico-sdk/src/rp2_common/hardware_vreg/vreg.c" "freeWatch/CMakeFiles/freewatch.dir/root/pico/pico-sdk/src/rp2_common/hardware_vreg/vreg.c.obj" "gcc" "freeWatch/CMakeFiles/freewatch.dir/root/pico/pico-sdk/src/rp2_common/hardware_vreg/vreg.c.obj.d"
  "/root/pico/pico-sdk/src/rp2_common/hardware_watchdog/watchdog.c" "freeWatch/CMakeFiles/freewatch.dir/root/pico/pico-sdk/src/rp2_common/hardware_watchdog/watchdog.c.obj" "gcc" "freeWatch/CMakeFiles/freewatch.dir/root/pico/pico-sdk/src/rp2_common/hardware_watchdog/watchdog.c.obj.d"
  "/root/pico/pico-sdk/src/rp2_common/hardware_xosc/xosc.c" "freeWatch/CMakeFiles/freewatch.dir/root/pico/pico-sdk/src/rp2_common/hardware_xosc/xosc.c.obj" "gcc" "freeWatch/CMakeFiles/freewatch.dir/root/pico/pico-sdk/src/rp2_common/hardware_xosc/xosc.c.obj.d"
  "/root/pico/pico-sdk/src/rp2_common/pico_bootrom/bootrom.c" "freeWatch/CMakeFiles/freewatch.dir/root/pico/pico-sdk/src/rp2_common/pico_bootrom/bootrom.c.obj" "gcc" "freeWatch/CMakeFiles/freewatch.dir/root/pico/pico-sdk/src/rp2_common/pico_bootrom/bootrom.c.obj.d"
  "/root/pico/pico-sdk/src/rp2_common/pico_double/double_init_rom.c" "freeWatch/CMakeFiles/freewatch.dir/root/pico/pico-sdk/src/rp2_common/pico_double/double_init_rom.c.obj" "gcc" "freeWatch/CMakeFiles/freewatch.dir/root/pico/pico-sdk/src/rp2_common/pico_double/double_init_rom.c.obj.d"
  "/root/pico/pico-sdk/src/rp2_common/pico_double/double_math.c" "freeWatch/CMakeFiles/freewatch.dir/root/pico/pico-sdk/src/rp2_common/pico_double/double_math.c.obj" "gcc" "freeWatch/CMakeFiles/freewatch.dir/root/pico/pico-sdk/src/rp2_common/pico_double/double_math.c.obj.d"
  "/root/pico/pico-sdk/src/rp2_common/pico_float/float_init_rom.c" "freeWatch/CMakeFiles/freewatch.dir/root/pico/pico-sdk/src/rp2_common/pico_float/float_init_rom.c.obj" "gcc" "freeWatch/CMakeFiles/freewatch.dir/root/pico/pico-sdk/src/rp2_common/pico_float/float_init_rom.c.obj.d"
  "/root/pico/pico-sdk/src/rp2_common/pico_float/float_math.c" "freeWatch/CMakeFiles/freewatch.dir/root/pico/pico-sdk/src/rp2_common/pico_float/float_math.c.obj" "gcc" "freeWatch/CMakeFiles/freewatch.dir/root/pico/pico-sdk/src/rp2_common/pico_float/float_math.c.obj.d"
  "/root/pico/pico-sdk/src/rp2_common/pico_malloc/pico_malloc.c" "freeWatch/CMakeFiles/freewatch.dir/root/pico/pico-sdk/src/rp2_common/pico_malloc/pico_malloc.c.obj" "gcc" "freeWatch/CMakeFiles/freewatch.dir/root/pico/pico-sdk/src/rp2_common/pico_malloc/pico_malloc.c.obj.d"
  "/root/pico/pico-sdk/src/rp2_common/pico_platform/platform.c" "freeWatch/CMakeFiles/freewatch.dir/root/pico/pico-sdk/src/rp2_common/pico_platform/platform.c.obj" "gcc" "freeWatch/CMakeFiles/freewatch.dir/root/pico/pico-sdk/src/rp2_common/pico_platform/platform.c.obj.d"
  "/root/pico/pico-sdk/src/rp2_common/pico_printf/printf.c" "freeWatch/CMakeFiles/freewatch.dir/root/pico/pico-sdk/src/rp2_common/pico_printf/printf.c.obj" "gcc" "freeWatch/CMakeFiles/freewatch.dir/root/pico/pico-sdk/src/rp2_common/pico_printf/printf.c.obj.d"
  "/root/pico/pico-sdk/src/rp2_common/pico_runtime/runtime.c" "freeWatch/CMakeFiles/freewatch.dir/root/pico/pico-sdk/src/rp2_common/pico_runtime/runtime.c.obj" "gcc" "freeWatch/CMakeFiles/freewatch.dir/root/pico/pico-sdk/src/rp2_common/pico_runtime/runtime.c.obj.d"
  "/root/pico/pico-sdk/src/rp2_common/pico_standard_link/binary_info.c" "freeWatch/CMakeFiles/freewatch.dir/root/pico/pico-sdk/src/rp2_common/pico_standard_link/binary_info.c.obj" "gcc" "freeWatch/CMakeFiles/freewatch.dir/root/pico/pico-sdk/src/rp2_common/pico_standard_link/binary_info.c.obj.d"
  "/root/pico/pico-sdk/src/rp2_common/pico_stdio/stdio.c" "freeWatch/CMakeFiles/freewatch.dir/root/pico/pico-sdk/src/rp2_common/pico_stdio/stdio.c.obj" "gcc" "freeWatch/CMakeFiles/freewatch.dir/root/pico/pico-sdk/src/rp2_common/pico_stdio/stdio.c.obj.d"
  "/root/pico/pico-sdk/src/rp2_common/pico_stdio_uart/stdio_uart.c" "freeWatch/CMakeFiles/freewatch.dir/root/pico/pico-sdk/src/rp2_common/pico_stdio_uart/stdio_uart.c.obj" "gcc" "freeWatch/CMakeFiles/freewatch.dir/root/pico/pico-sdk/src/rp2_common/pico_stdio_uart/stdio_uart.c.obj.d"
  "/root/pico/pico-sdk/src/rp2_common/pico_stdlib/stdlib.c" "freeWatch/CMakeFiles/freewatch.dir/root/pico/pico-sdk/src/rp2_common/pico_stdlib/stdlib.c.obj" "gcc" "freeWatch/CMakeFiles/freewatch.dir/root/pico/pico-sdk/src/rp2_common/pico_stdlib/stdlib.c.obj.d"
  "/root/projects/FreeWatchSW/c-example/freeWatch/rtc.c" "freeWatch/CMakeFiles/freewatch.dir/rtc.c.obj" "gcc" "freeWatch/CMakeFiles/freewatch.dir/rtc.c.obj.d"
  "/root/projects/FreeWatchSW/c-example/freeWatch/screens.c" "freeWatch/CMakeFiles/freewatch.dir/screens.c.obj" "gcc" "freeWatch/CMakeFiles/freewatch.dir/screens.c.obj.d"
  "/root/pico/pico-sdk/src/rp2_common/pico_standard_link/new_delete.cpp" "freeWatch/CMakeFiles/freewatch.dir/root/pico/pico-sdk/src/rp2_common/pico_standard_link/new_delete.cpp.obj" "gcc" "freeWatch/CMakeFiles/freewatch.dir/root/pico/pico-sdk/src/rp2_common/pico_standard_link/new_delete.cpp.obj.d"
  )

# Targets to which this target links.
set(CMAKE_TARGET_LINKED_INFO_FILES
  "/root/projects/FreeWatchSW/c-example/bild/lib/Config/CMakeFiles/Config.dir/DependInfo.cmake"
  "/root/projects/FreeWatchSW/c-example/bild/lib/LCD/CMakeFiles/LCD.dir/DependInfo.cmake"
  "/root/projects/FreeWatchSW/c-example/bild/lib/Touch/CMakeFiles/Touch.dir/DependInfo.cmake"
  "/root/projects/FreeWatchSW/c-example/bild/lib/QMI8658/CMakeFiles/QMI8658.dir/DependInfo.cmake"
  )

# Fortran module output directory.
set(CMAKE_Fortran_TARGET_MODULE_DIR "")