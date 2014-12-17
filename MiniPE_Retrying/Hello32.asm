;ml32 /c /coff
;linkasm32 /subsystem:windows 
.386
.model flat, stdcall
option casemap:none

include windows.inc
include user32.inc
includelib user32.lib

.code 
START:
	invoke MessageBoxA, NULL, NULL, NULL, MB_OK
	ret

end START
