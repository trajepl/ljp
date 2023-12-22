vim.cmd("set cursorline")
vim.cmd("set number")

vim.cmd("set tabstop=4")
vim.cmd("set shiftwidth=4")
vim.cmd("set expandtab")

vim.cmd("set incsearch")
vim.cmd("set hlsearch")
vim.cmd("set ignorecase")
vim.cmd("set smartcase")

vim.cmd("set nowritebackup")
vim.cmd("set noswapfile")
vim.cmd("set nobackup")

vim.cmd("set clipboard=unnamedplus")


vim.g.mapleader = " "
-- disable netrw at the very start of your init.lua
vim.g.loaded_netrw = 1
vim.g.loaded_netrwPlugin = 1

-- set termguicolors to enable highlight groups
vim.opt.termguicolors = true

local lazypath = vim.fn.stdpath("data") .. "/lazy/lazy.nvim"
if not vim.loop.fs_stat(lazypath) then
  vim.fn.system({
    "git",
    "clone",
    "--filter=blob:none",
    "https://github.com/folke/lazy.nvim.git",
    "--branch=stable", -- latest stable release
    lazypath,
  })
end
vim.opt.rtp:prepend(lazypath)

local plugins = {
    { "catppuccin/nvim", name = "catppuccin", priority = 1000 },
    { 'nvim-telescope/telescope.nvim', tag = '0.1.5', dependencies = { 'nvim-lua/plenary.nvim' } },
    { 'nvim-treesitter/nvim-treesitter', build = ':TSUpdate' },
    { 'github/copilot.vim', },
    { 'nvim-tree/nvim-tree.lua' },
    { 'nvim-tree/nvim-web-devicons' },
    { 'dense-analysis/ale' }
}
local opts = {
}

require("lazy").setup(plugins, opts)

local builtin = require("telescope.builtin")
vim.keymap.set('n', '<C-p>', builtin.find_files, {})
vim.keymap.set('n', '<leader>fg', builtin.live_grep, {})

local configs = require("nvim-treesitter.configs")
configs.setup({
    ensure_installed = { "c", "lua", "vim", "vimdoc", "python", "javascript", "html" },
    sync_install = false,
    highlight = { enable = true },
    indent = { enable = true },
})

require("catppuccin").setup()
vim.cmd.colorscheme "catppuccin"

local nvim_tree = require("nvim-tree")
nvim_tree.setup({
  sort = {
    sorter = "case_sensitive",
  },
  view = {
    width = 30,
  },
  renderer = {
    group_empty = true,
  },
  filters = {
    dotfiles = true,
  },
})

vim.keymap.set('n', '<leader>tb', vim.cmd.NvimTreeToggle, {})
