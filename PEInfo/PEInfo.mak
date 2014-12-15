# Microsoft Developer Studio Generated NMAKE File, Based on PEInfo.dsp
!IF "$(CFG)" == ""
CFG=PEInfo - Win32 Debug
!MESSAGE No configuration specified. Defaulting to PEInfo - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "PEInfo - Win32 Release" && "$(CFG)" != "PEInfo - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "PEInfo.mak" CFG="PEInfo - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "PEInfo - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "PEInfo - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "PEInfo - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\PEInfo.exe"


CLEAN :
	-@erase "$(INTDIR)\ConvertDlg.obj"
	-@erase "$(INTDIR)\DumpDlg.obj"
	-@erase "$(INTDIR)\InfoEdit.obj"
	-@erase "$(INTDIR)\LogView.obj"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\PE.OBJ"
	-@erase "$(INTDIR)\PEInfo.obj"
	-@erase "$(INTDIR)\PEInfo.pch"
	-@erase "$(INTDIR)\PEInfo.res"
	-@erase "$(INTDIR)\PEInfoDoc.obj"
	-@erase "$(INTDIR)\PEInfoView.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\TblInfoView.obj"
	-@erase "$(INTDIR)\TblTreeView.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\PEInfo.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\PEInfo.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x804 /fo"$(INTDIR)\PEInfo.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\PEInfo.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\PEInfo.pdb" /machine:I386 /out:"$(OUTDIR)\PEInfo.exe" 
LINK32_OBJS= \
	"$(INTDIR)\ConvertDlg.obj" \
	"$(INTDIR)\InfoEdit.obj" \
	"$(INTDIR)\LogView.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\PE.OBJ" \
	"$(INTDIR)\PEInfo.obj" \
	"$(INTDIR)\PEInfoDoc.obj" \
	"$(INTDIR)\PEInfoView.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\TblInfoView.obj" \
	"$(INTDIR)\TblTreeView.obj" \
	"$(INTDIR)\PEInfo.res" \
	"$(INTDIR)\DumpDlg.obj"

"$(OUTDIR)\PEInfo.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "PEInfo - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\PEInfo.exe" "$(OUTDIR)\PEInfo.bsc"


CLEAN :
	-@erase "$(INTDIR)\ConvertDlg.obj"
	-@erase "$(INTDIR)\ConvertDlg.sbr"
	-@erase "$(INTDIR)\DumpDlg.obj"
	-@erase "$(INTDIR)\DumpDlg.sbr"
	-@erase "$(INTDIR)\InfoEdit.obj"
	-@erase "$(INTDIR)\InfoEdit.sbr"
	-@erase "$(INTDIR)\LogView.obj"
	-@erase "$(INTDIR)\LogView.sbr"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\MainFrm.sbr"
	-@erase "$(INTDIR)\PE.OBJ"
	-@erase "$(INTDIR)\PE.SBR"
	-@erase "$(INTDIR)\PEInfo.obj"
	-@erase "$(INTDIR)\PEInfo.pch"
	-@erase "$(INTDIR)\PEInfo.res"
	-@erase "$(INTDIR)\PEInfo.sbr"
	-@erase "$(INTDIR)\PEInfoDoc.obj"
	-@erase "$(INTDIR)\PEInfoDoc.sbr"
	-@erase "$(INTDIR)\PEInfoView.obj"
	-@erase "$(INTDIR)\PEInfoView.sbr"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\StdAfx.sbr"
	-@erase "$(INTDIR)\TblInfoView.obj"
	-@erase "$(INTDIR)\TblInfoView.sbr"
	-@erase "$(INTDIR)\TblTreeView.obj"
	-@erase "$(INTDIR)\TblTreeView.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\PEInfo.bsc"
	-@erase "$(OUTDIR)\PEInfo.exe"
	-@erase "$(OUTDIR)\PEInfo.ilk"
	-@erase "$(OUTDIR)\PEInfo.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\PEInfo.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x804 /fo"$(INTDIR)\PEInfo.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\PEInfo.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\ConvertDlg.sbr" \
	"$(INTDIR)\InfoEdit.sbr" \
	"$(INTDIR)\LogView.sbr" \
	"$(INTDIR)\MainFrm.sbr" \
	"$(INTDIR)\PE.SBR" \
	"$(INTDIR)\PEInfo.sbr" \
	"$(INTDIR)\PEInfoDoc.sbr" \
	"$(INTDIR)\PEInfoView.sbr" \
	"$(INTDIR)\StdAfx.sbr" \
	"$(INTDIR)\TblInfoView.sbr" \
	"$(INTDIR)\TblTreeView.sbr" \
	"$(INTDIR)\DumpDlg.sbr"

"$(OUTDIR)\PEInfo.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\PEInfo.pdb" /debug /machine:I386 /out:"$(OUTDIR)\PEInfo.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\ConvertDlg.obj" \
	"$(INTDIR)\InfoEdit.obj" \
	"$(INTDIR)\LogView.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\PE.OBJ" \
	"$(INTDIR)\PEInfo.obj" \
	"$(INTDIR)\PEInfoDoc.obj" \
	"$(INTDIR)\PEInfoView.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\TblInfoView.obj" \
	"$(INTDIR)\TblTreeView.obj" \
	"$(INTDIR)\PEInfo.res" \
	"$(INTDIR)\DumpDlg.obj"

"$(OUTDIR)\PEInfo.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("PEInfo.dep")
!INCLUDE "PEInfo.dep"
!ELSE 
!MESSAGE Warning: cannot find "PEInfo.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "PEInfo - Win32 Release" || "$(CFG)" == "PEInfo - Win32 Debug"
SOURCE=.\ConvertDlg.cpp

!IF  "$(CFG)" == "PEInfo - Win32 Release"


"$(INTDIR)\ConvertDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\PEInfo.pch"


!ELSEIF  "$(CFG)" == "PEInfo - Win32 Debug"


"$(INTDIR)\ConvertDlg.obj"	"$(INTDIR)\ConvertDlg.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\PEInfo.pch"


!ENDIF 

SOURCE=.\DumpDlg.cpp

!IF  "$(CFG)" == "PEInfo - Win32 Release"


"$(INTDIR)\DumpDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\PEInfo.pch"


!ELSEIF  "$(CFG)" == "PEInfo - Win32 Debug"


"$(INTDIR)\DumpDlg.obj"	"$(INTDIR)\DumpDlg.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\PEInfo.pch"


!ENDIF 

SOURCE=.\InfoEdit.cpp

!IF  "$(CFG)" == "PEInfo - Win32 Release"


"$(INTDIR)\InfoEdit.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\PEInfo.pch"


!ELSEIF  "$(CFG)" == "PEInfo - Win32 Debug"


"$(INTDIR)\InfoEdit.obj"	"$(INTDIR)\InfoEdit.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\PEInfo.pch"


!ENDIF 

SOURCE=.\LogView.cpp

!IF  "$(CFG)" == "PEInfo - Win32 Release"


"$(INTDIR)\LogView.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\PEInfo.pch"


!ELSEIF  "$(CFG)" == "PEInfo - Win32 Debug"


"$(INTDIR)\LogView.obj"	"$(INTDIR)\LogView.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\PEInfo.pch"


!ENDIF 

SOURCE=.\MainFrm.cpp

!IF  "$(CFG)" == "PEInfo - Win32 Release"


"$(INTDIR)\MainFrm.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\PEInfo.pch"


!ELSEIF  "$(CFG)" == "PEInfo - Win32 Debug"


"$(INTDIR)\MainFrm.obj"	"$(INTDIR)\MainFrm.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\PEInfo.pch"


!ENDIF 

SOURCE=.\PE.CPP

!IF  "$(CFG)" == "PEInfo - Win32 Release"


"$(INTDIR)\PE.OBJ" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\PEInfo.pch"


!ELSEIF  "$(CFG)" == "PEInfo - Win32 Debug"


"$(INTDIR)\PE.OBJ"	"$(INTDIR)\PE.SBR" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\PEInfo.pch"


!ENDIF 

SOURCE=.\PEInfo.cpp

!IF  "$(CFG)" == "PEInfo - Win32 Release"


"$(INTDIR)\PEInfo.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\PEInfo.pch"


!ELSEIF  "$(CFG)" == "PEInfo - Win32 Debug"


"$(INTDIR)\PEInfo.obj"	"$(INTDIR)\PEInfo.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\PEInfo.pch"


!ENDIF 

SOURCE=.\PEInfo.rc

"$(INTDIR)\PEInfo.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\PEInfoDoc.cpp

!IF  "$(CFG)" == "PEInfo - Win32 Release"


"$(INTDIR)\PEInfoDoc.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\PEInfo.pch"


!ELSEIF  "$(CFG)" == "PEInfo - Win32 Debug"


"$(INTDIR)\PEInfoDoc.obj"	"$(INTDIR)\PEInfoDoc.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\PEInfo.pch"


!ENDIF 

SOURCE=.\PEInfoView.cpp

!IF  "$(CFG)" == "PEInfo - Win32 Release"


"$(INTDIR)\PEInfoView.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\PEInfo.pch"


!ELSEIF  "$(CFG)" == "PEInfo - Win32 Debug"


"$(INTDIR)\PEInfoView.obj"	"$(INTDIR)\PEInfoView.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\PEInfo.pch"


!ENDIF 

SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "PEInfo - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\PEInfo.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\PEInfo.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "PEInfo - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\PEInfo.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\StdAfx.sbr"	"$(INTDIR)\PEInfo.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\TblInfoView.cpp

!IF  "$(CFG)" == "PEInfo - Win32 Release"


"$(INTDIR)\TblInfoView.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\PEInfo.pch"


!ELSEIF  "$(CFG)" == "PEInfo - Win32 Debug"


"$(INTDIR)\TblInfoView.obj"	"$(INTDIR)\TblInfoView.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\PEInfo.pch"


!ENDIF 

SOURCE=.\TblTreeView.cpp

!IF  "$(CFG)" == "PEInfo - Win32 Release"


"$(INTDIR)\TblTreeView.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\PEInfo.pch"


!ELSEIF  "$(CFG)" == "PEInfo - Win32 Debug"


"$(INTDIR)\TblTreeView.obj"	"$(INTDIR)\TblTreeView.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\PEInfo.pch"


!ENDIF 


!ENDIF 

