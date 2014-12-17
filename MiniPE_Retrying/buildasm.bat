ml32 /c /coff /nologo Hello32.asm
linkasm32 /RELEASE /subsystem:windows /align:4 /merge:.rdata=.data /merge:.text=.data /merge:.reloc=.data Hello32.obj
