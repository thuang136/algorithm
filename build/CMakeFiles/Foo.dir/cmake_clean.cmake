FILE(REMOVE_RECURSE
  "CMakeFiles/Foo.dir/Foo.cpp.o"
  "Foo.pdb"
  "Foo"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang CXX)
  INCLUDE(CMakeFiles/Foo.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
