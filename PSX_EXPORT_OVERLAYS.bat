rem slink /psx /c /p /rmips=SPEC_PSX/PSXMAIN.REL @SPEC_PSX/PSXMAIN.LNK,SPEC_PSX/PSXMAIN.BIN
rem psylink /c /p /q /rmips=SPEC_PSX/PSXMAIN.REL @SPEC_PSX/PSXMAIN.LNK,SPEC_PSX/PSXMAIN.BIN

slink /psx /c /p /rmips=SPEC_PSX/SETUP.REL @SPEC_PSX/SETUP.LNK,SPEC_PSX/SETUP.BIN
rem psylink /c /p /q /rmips=SPEC_PSX/SETUP.REL @SPEC_PSX/SETUP.LNK,SPEC_PSX/SETUP.BIN
DEL2FAB /c+ SPEC_PSX/SETUP

rem slink /psx /c /p /rmips=SPEC_PSX/TITSEQ.REL @SPEC_PSX/TITSEQ.LNK,SPEC_PSX/TITSEQ.BIN
rem psylink /c /p /q /rmips=SPEC_PSX/TITSEQ.REL @SPEC_PSX/TITSEQ.LNK,SPEC_PSX/TITSEQ.BIN

rem slink /psx /c /p /rmips=GAME/LION.REL @GAME/LION.LNK,GAME/LION.BIN
rem psylink /c /p /q /rmips=GAME/LION.REL @GAME/LION.LNK,GAME/LION.BIN