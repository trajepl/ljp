 " general
 set history=700
 set number
 set relativenumber 
 set autoread
 set mouse=i

 set backspace=eol,start,indent
 set whichwrap+=<,>,h,l

 " about search
 set ignorecase
 set smartcase
 set hlsearch
 set incsearch

 syntax enable

 " No annoying sound
 set noerrorbells
 set novisualbell

 " encoding,filetype
 set encoding=utf8
 set ffs=unix,dos,mac

 " files,backups,undo
 set nobackup
 set nowb
 set noswapfile

 " about tab
 set smarttab
 set shiftwidth=4
 set tabstop=4

 " linebreak on 500 characters
 set lbr 
 set tw=500
 set ai "Auto indent
 set si "Smart indent
 set wrap "Wrap lines
 " vim-Latex
 filetype plugin indent on
 set grepprg=grep\ -nH\ $*
 let g:tex_flavor = "latex"
 set shellslash 
