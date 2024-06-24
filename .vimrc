" Disable Vi compatibility mode
set nocompatible

" Enable line numbers and relative line numbers
set number
set relativenumber

" Set things
set path+=**
set wildmenu
command! MakeTags !ctags -R .
" Configure tab settings
set expandtab
set tabstop=2
set shiftwidth=2

" Allow backspace to delete characters over everything in insert mode
set backspace=indent,eol,start

" Initialize plugin system
call plug#begin('~/.vim/plugged')

" Plugin for snippets and snippet management
"Plug 'SirVer/ultisnips'
"Plug 'honza/vim-snippets'
Plug 'github/copilot.vim'
Plug 'tpope/vim-surround'
"Plug 'tpope/vim-commentary'
" Uncomment the following lines to enable LSP plugins
"Plug 'prabirshrestha/vim-lsp'
"Plug 'mattn/vim-lsp-settings'

call plug#end()

" Uncomment the following lines to configure LSP settings
"function! s:on_lsp_buffer_enabled() abort
"  setlocal omnifunc=lsp#complete
"endfunction

"augroup lsp_install
"  au!
"  autocmd User lsp_buffer_enabled call s:on_lsp_buffer_enabled()
"augroup END
filetype plugin indent on
" Enable spell check
"set spell

" Set the spell checking language to American English
set spelllang=en_gb

" Enable spell check for specific file types
autocmd FileType markdown setlocal spell
autocmd FileType text setlocal spell
let mapleader = " "

" Source the toggle_comment.vim script
source ~/.vim/toggle_comment.vim

"c snippets the vim way
inoremap ,i <ESC>:-1read /home/sbhad/.vim/snippets/include1<CR>10li
inoremap ,, <ESC>o
inoremap ,m <ESC>:-1read /home/sbhad/.vim/snippets/main<CR>9li
inoremap ,a int argc, int *argv[]
nnoremap <leader>q :q<CR>
nnoremap <leader>w :w<CR>
nnoremap <leader>e :e<CR>
nnoremap <leader>t :tab ter<CR>
