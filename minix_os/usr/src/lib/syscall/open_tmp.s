.sect .text
.extern	__open_tmp
.define	_open_tmp
.align 2

_open_tmp:
	jmp	__open_tmp
