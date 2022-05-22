set noerrorbells
set tabstop=4 softtabstop=4
set shiftwidth=4
set smartindent
set nu
set relativenumber
set smartcase
set incsearch
syntax on

" -- for syntax highlighting
set nocompatible
" --- EXTENSTIONS ---
call plug#begin()

Plug 'morhetz/gruvbox'
Plug 'gruvbox-community/gruvbox'
Plug 'arcticicestudio/nord-vim'
Plug 'sjl/badwolf'
Plug 'jnurmine/Zenburn'
Plug 'sainnhe/gruvbox-material'
Plug 'rafi/awesome-vim-colorschemes'
Plug 'cormacrelf/vim-colors-github'
Plug 'mcmartelle/vim-monokai-bold'
Plug 'junegunn/seoul256.vim'
Plug 'AlessandroYorba/Alduin'
Plug 'tomasiser/vim-code-dark'
Plug 'rakr/vim-one'
Plug 'drewtempelmeyer/palenight.vim'

"Syntax Highlighting
Plug 'sheerun/vim-polyglot'
"Plug 'jeaye/color_coded'

call plug#end()





set background=dark " for the dark version
set t_Co=256
set t_ut=
"colorscheme one
colorscheme gruvbox
"colorscheme zenburn "without syntax
"colorscheme codedark
"colorscheme rakr
"colorscheme palenight 
set termguicolors

"  ---=== COLORSCHEME SETTINGS ===---
"Credit joshdick
"Use 24-bit (true-color) mode in Vim/Neovim when outside tmux.
"If you're using tmux version 2.2 or later, you can remove the outermost $TMUX check and use tmux's 24-bit color support
"(see < http://sunaku.github.io/tmux-24bit-color.html#usage > for more information.)
"if (empty($TMUX))
"  if (has("nvim"))
"    "For Neovim 0.1.3 and 0.1.4 < https://github.com/neovim/neovim/pull/2198 >
"    let $NVIM_TUI_ENABLE_TRUE_COLOR=1
"  endif
  "For Neovim > 0.1.5 and Vim > patch 7.4.1799 < https://github.com/vim/vim/commit/61be73bb0f965a895bfb064ea3e55476ac175162 >
  "Based on Vim patch 7.4.1770 (`guicolors` option) < https://github.com/vim/vim/commit/8a633e3427b47286869aa4b96f2bfc1fe65b25cd >
  " < https://github.com/neovim/neovim/wiki/Following-HEAD#20160511 >
"  if (has("termguicolors"))
"    set termguicolors
"  endif
"endif
" --- transparent Background ---
"hi Normal guibg=NONE ctermbg=NONE
"highlight Comment cterm=bold

" --- Prettier Syntax Highlighing ---
"plugloadall

" Compile and run 
autocmd filetype python nnoremap <F4> :w <bar> exec '!python '.shellescape('%')<CR>
autocmd filetype c nnoremap <F4> :w <bar> exec '!gcc '.shellescape('%').' -o '.shellescape('%:r').' && ./'.shellescape('%:r')<CR>
autocmd filetype cpp nnoremap <F4> :w <bar> exec '!g++ '.shellescape('%').' -o '.shellescape('%:r').' && ./'.shellescape('%:r')<CR>


