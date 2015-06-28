FILE(REMOVE_RECURSE
  "CMakeFiles/testFoo.dir/testFoo.cpp.o"
  "testFoo.pdb"
  "testFoo"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang CXX)
  INCLUDE(CMakeFiles/testFoo.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
