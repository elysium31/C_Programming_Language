set tabstop=4
set softtabstop=4
set shiftwidth=4
set noexpandtab

set colorcolumn=110
highlight ColorColumn ctermbg=darkgray

set autoindent
set number
set showmatch

augroup project
	autocmd!
	autocmd BufRead, BufNewFile *.h, *.c set filetype=c.doxygen
augroup END

