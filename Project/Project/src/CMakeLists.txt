# Все сортеры, которые мы планируем поддерживать
set(SORTERS_SRC
  BubbleSort.cxx
  InsertionSort.cxx
  QuickSort.cxx
  ShellSort.cxx
  HeapSort.cxx
  MergeSort.cxx
  RadixSort.cxx
  BucketSort.cxx
  CountingSort.cxx
  SelectionSort.cxx
)

# Библиотека сортеров
add_library(SorterLib
  Sorter.cxx
  ArrayGenerator.cxx
  Statistics.cxx
  SortManager.cxx
)

# Связываем библиотеку с необходимыми заголовками
target_include_directories(SorterLib
  PUBLIC ${PROJECT_SOURCE_DIR}/include)

# Исполняемый файл
add_executable(sorting_app main.cxx ${SORTERS_SRC})

target_link_libraries(sorting_app PRIVATE SorterLib)
