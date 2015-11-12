# === Compilers ===


# Uncomment this line for new-style classdef support
# OOFLAG=-DR2008OO

# Uncomment this line for C99 complex support
TESTC99COMPLEX=test_c99_complex

CC=    cl
CXX=   cl
LINK=  link
MEX=   mex $(OOFLAG)

# Use the following for 64-bit MEX
# MEX=   mex -largeArrayDims $(OOFLAG)

# Use the following for GNU Octave.
MEX=   mkoctfile --mex

# Location of Win-Flex-Bison compiler (not needed unless you are planning to
# modify the grammar -- the default installation comes with the relevant
# files already in place
WINFLEXBISONPATH=X:\projekte\1510_MatLightTracer\mwrap\win_flex_bison
FLEX=$(WINFLEXBISONPATH)\win_flex
BISON=$(WINFLEXBISONPATH)\win_bison

#-------------------------------------------------------------------------
# Compiler-Flags
#-------------------------------------------------------------------------

# WIN32 DEBUG
# /GS /analyze- /W3 /Zc:wchar_t /ZI /Gm /Od /sdl /Fd"Debug\vc140.pdb" /Zc:inline /fp:precise /D "_CRT_SECURE_NO_DEPRECATE" /D "_CRT_NONSTDC_NO_DEPRECATE" /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_UNICODE" /D "UNICODE" /errorReport:prompt /WX- /Zc:forScope /RTC1 /Gd /Oy- /MDd /Fa"Debug\" /EHsc /nologo /Fo"Debug\" /Fp"Debug\mwrap.pch"
# WIN32 RELEASE
# /GS /GL /analyze- /W3 /Gy /Zc:wchar_t /Zi /Gm- /O2 /sdl /Fd"Release\vc140.pdb" /Zc:inline /fp:precise /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_UNICODE" /D "UNICODE" /errorReport:prompt /WX- /Zc:forScope /Gd /Oy- /Oi /MD /Fa"Release\" /EHsc /nologo /Fo"Release\" /Fp"Release\mwrap.pch"
# X64 DEBUG
# /GS /W3 /Zc:wchar_t /ZI /Gm /Od /sdl /Fd"x64\Debug\vc140.pdb" /Zc:inline /fp:precise /D "_DEBUG" /D "_CONSOLE" /D "_UNICODE" /D "UNICODE" /errorReport:prompt /WX- /Zc:forScope /RTC1 /Gd /MDd /Fa"x64\Debug\" /EHsc /nologo /Fo"x64\Debug\" /Fp"x64\Debug\mwrap.pch"
# X64 RELEASE
# /GS /GL /W3 /Gy /Zc:wchar_t /Zi /Gm- /O2 /sdl /Fd"x64\Release\vc140.pdb" /Zc:inline /fp:precise /D "NDEBUG" /D "_CONSOLE" /D "_UNICODE" /D "UNICODE" /errorReport:prompt /WX- /Zc:forScope /Gd /Oi /MD /Fa"x64\Release\" /EHsc /nologo /Fo"x64\Release\" /Fp"x64\Release\mwrap.pch"

CGFLAGS=/nologo /W4 /EHsc /D_CRT_SECURE_NO_DEPRECATE /D_CRT_NONSTDC_NO_DEPRECATE
CRFLAGS=/DNDEBUG /ML /Ox
CDFLAGS=

CFLAGS=$(CGFLAGS) $(CDFLAGS)

#-------------------------------------------------------------------------
# Linker-Flags
#-------------------------------------------------------------------------

# WIN32 DEBUG
# /OUT:"Debug\mwrap.exe" /MANIFEST /NXCOMPAT /PDB:"Debug\mwrap.pdb" /DYNAMICBASE "kernel32.lib" "user32.lib" "gdi32.lib" "winspool.lib" "comdlg32.lib" "advapi32.lib" "shell32.lib" "ole32.lib" "oleaut32.lib" "uuid.lib" "odbc32.lib" "odbccp32.lib" /MACHINE:X86 /INCREMENTAL /PGD:"Debug\mwrap.pgd" /SUBSYSTEM:CONSOLE /MANIFESTUAC:"level='asInvoker' uiAccess='false'" /ManifestFile:"Debug\mwrap_mvs.exe.intermediate.manifest" /ERRORREPORT:PROMPT /NOLOGO /TLBID:1
# WIN32 RELEASE
# /OUT:"Release\mwrap.exe" /MANIFEST /LTCG:incremental /NXCOMPAT /PDB:"Release\mwrap.pdb" /DYNAMICBASE "kernel32.lib" "user32.lib" "gdi32.lib" "winspool.lib" "comdlg32.lib" "advapi32.lib" "shell32.lib" "ole32.lib" "oleaut32.lib" "uuid.lib" "odbc32.lib" "odbccp32.lib" /MACHINE:X86 /OPT:REF /SAFESEH /INCREMENTAL:NO /PGD:"Release\mwrap.pgd" /SUBSYSTEM:CONSOLE /MANIFESTUAC:"level='asInvoker' uiAccess='false'" /ManifestFile:"Release\mwrap_mvs.exe.intermediate.manifest" /OPT:ICF /ERRORREPORT:PROMPT /NOLOGO /TLBID:1
# X64 DEBUG
# /OUT:"Debug\mwrap.exe" /MANIFEST /NXCOMPAT /PDB:"Debug\mwrap.pdb" /DYNAMICBASE "kernel32.lib" "user32.lib" "gdi32.lib" "winspool.lib" "comdlg32.lib" "advapi32.lib" "shell32.lib" "ole32.lib" "oleaut32.lib" "uuid.lib" "odbc32.lib" "odbccp32.lib" /MACHINE:X64 /INCREMENTAL /PGD:"Debug\mwrap.pgd" /SUBSYSTEM:CONSOLE /MANIFESTUAC:"level='asInvoker' uiAccess='false'" /ManifestFile:"Debug\mwrap_mvs.exe.intermediate.manifest" /ERRORREPORT:PROMPT /NOLOGO /TLBID:1
# X64 RELEASE
# /OUT:"Release\mwrap.exe" /MANIFEST /LTCG:incremental /NXCOMPAT /PDB:"Release\mwrap.pdb" /DYNAMICBASE "kernel32.lib" "user32.lib" "gdi32.lib" "winspool.lib" "comdlg32.lib" "advapi32.lib" "shell32.lib" "ole32.lib" "oleaut32.lib" "uuid.lib" "odbc32.lib" "odbccp32.lib" /MACHINE:X64 /OPT:REF /INCREMENTAL:NO /PGD:"Release\mwrap.pgd" /SUBSYSTEM:CONSOLE /MANIFESTUAC:"level='asInvoker' uiAccess='false'" /ManifestFile:"Release\mwrap_mvs.exe.intermediate.manifest" /OPT:ICF /ERRORREPORT:PROMPT /NOLOGO /TLBID:1

LIBS=
LGFLAGS=/NOLOGO
LRFLAGS=
LDFLAGS=/DEBUG

LFLAGS=$(LIBS) $(LGFLAGS) $(LDFLAGS)

