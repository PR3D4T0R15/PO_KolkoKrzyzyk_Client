# CMakeList.txt: projekt CMake dla elementu PO_KolkoKrzyzyk_Client, dołącz źródło i zdefiniuj
# tutaj logikę specyficzną dla projektu.
#

# Dodaj źródło do pliku wykonywalnego tego projektu.
add_executable (PO_KolkoKrzyzyk_Client "PO_KolkoKrzyzyk_Client.cpp" "PO_KolkoKrzyzyk_Client.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET PO_KolkoKrzyzyk_Client PROPERTY CXX_STANDARD 20)
endif()

# TODO: Dodaj testy i zainstaluj elementy docelowe w razie potrzeby.
