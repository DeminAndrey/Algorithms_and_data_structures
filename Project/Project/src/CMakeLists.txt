# Все сортеры, которые мы планируем поддерживать
set(SORTERS_SRC
  ${PROJECT_SOURCE_DIR}/src/BubbleSort.cxx
  ${PROJECT_SOURCE_DIR}/src/InsertionSort.cxx
  ${PROJECT_SOURCE_DIR}/src/QuickSort.cxx
  # Остальные сортеры...
)

# Библиотека сортеров
add_library(SorterLib ${PROJECT_SOURCE_DIR}/src/Sorter.cxx
  ${PROJECT_SOURCE_DIR}/src/ArrayGenerator.cxx
  ${PROJECT_SOURCE_DIR}/src/Statistics.cxx
)

# Связываем библиотеку с необходимыми заголовками
target_include_directories(SorterLib PUBLIC ${PROJECT_SOURCE_DIR}/include)

# Исполняемый файл
add_executable(sorting_app main.cxx ${SORTERS_SRC})

target_link_libraries(sorting_app PRIVATE SorterLib)
