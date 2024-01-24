# MiniShell

## To Do's
- [ ] Change expansion to leave the quotes in string

- [ ] Write pipe split function that only splits by pipes that are
not inbetween 2 quotes of the same kind

- [ ] Split bz space and detect redirection operators

- [ ] Implement pipes and add redirection possibility

- [ ] Unset path 

- [ ] Implement heredoc and append for << >>

- [ ] $? for exit status

## Checklist

| Check | Command | User input | Expected result |
|-------|---------|------------|-----------------|
|:white_check_mark:| CD | `cd ~/Desktop` | `pwd: ~/Desktop` |
|:white_check_mark:| CD | `unset HOME - cd ~` | `Error: HOME not set, EXIT 1` |
|:white_check_mark:| CD | `export HOME=/Users/user42 - cd ~` | `pwd: ~` |
|:x:| `cd .. cool swag` | `pwd: ../` |
| CD | `cd Eyooooo` | `bash: cd: Eyooooo: No such file or directory - EXIT 1` |
| CD | `cd -` | `pwd: Last PWD` |
| CD | `mkdir a - mkdir a/b - cd a/b - rm -r ../../a - cd ..` | `cd: error retrieving current directory: getcwd: cannot access parent directories: No such file or directory - EXIT 0` |
| ECHO | `echo` |  |
| ECHO | `echo $NonExistingVar` |  |
| ECHO | `echo $PATH` | `$PATH` |
| ECHO | `echo ~` | `$HOME` |
| ECHO | `echo -n -n -nnnn -nnnnm` | `-nnnnm` |
| ECHO | `echo -n -nnn hello -n` | `hello -n` |
| ENV | `env` | `All env and all user envs WITH content in it` |
| ENV | `env Weeiirrddd` | `env: weeirdd: No such file or directory - EXIT 127` |
| EXIT STATUS | `cd Weyooo - echo $?` | `bash: cd: Weyooo: No such file or directory - EXIT 1` |
| EXIT STATUS | `random_cmd - echo $?` | `EXIT 127` |
| EXIT STATUS | `./file_that_is_not_an_executable` | `bash: ./file_that_is_not_an_executable: Permission denied - EXIT 126` |
| EXIT STATUS | `cat bla` | `cat: bla: No such file or directory - EXIT 1` |
| EXIT STATUS | `hi` | `bash: hi: command not found - EXIT 127` |
| EXIT STATUS | `export ls="ls -l" - $ls` | `Does what "ls -l" should do - EXIT 0` |
| EXIT STATUS | `echo $ls` | `ls -l - EXIT 0` |
| EXPORT | `export var=a - export $var=test - echo $var $a` | `a test` |
| EXPORT | `export $var=test - unset var` |  |
| EXPORT | `export test1 - env` | `You will not see test1 in "env", but you will it in "export"` |
| EXPORT | `export test2= - env` | `You will see test2 in "env" and "export"` |
| EXPORT | `export var - export var=hoi - export` | `var="hoi"` |
| EXPORT | `export "" test=a` | `minishell: export: ": not a valid identifier` |
| EXPORT | `export test3=$HOME` | `test3="Users/user42"` |
| EXTRA | `echo ~` | `/home/user42` |
| INIT | `$SHLVL` | `Needs to increment once per new shell session` |
| PARSING | `""` | `Error - EXIT 126 or EXIT 127` |
| PARSING | `echo "\s" ; echo "\\s"` | `should have the exact same output` |
| PARSING | `echo "12\""` | `12"` |
| PARSING | `echo "bip \| bip ; coyotte > < "` | `[bip \| bip ; coyotte >< ]` |
| PARSING | `echo \>` | `>` |
| PARSING | `echo $USER$var$USER$USER$USERtest$USER` | `user42$USERuser42$USERtestuser42` |
| PARSING | `echo bonjour \; ls` | `bonjour ; ls` |
| PARSING | `$` | `command not found` |
| PARSING | `$LESS$VAR` | `-R: command not found` |
| PARSING | `..` | `cmd not found, exit 127` |
| PARSING | `echo '"abc"'` | `"abc"` |
| PARSING | `echo "" bonjour` | `[ bonjour]` |
| PARSING | `export "test=ici"=coucou ; echo $test` | `test="ici=coucou"` |
| PIPE | `cat \| cat \| cat \| ls` | `Press enter 3 times` |
| PIPE | `cat Makefile \| grep pr \| head -n 5 \| cd file_not_exit` | `file_not_exist: no such file... exit status: 1` |
| PIPE | `cat Makefile \| grep pr \| head -n 5 \| hello` | `hello: cmd not found... exit status: 127` |
| PIPE | `ls \| exit` |  |
| REDIR | `> test \| echo blabla` | `blabla` |
| REDIR | `exit > hoi.txt` | `Should exit & creates hoi.txt` |
| ENV | `env \| grep OLDPWD` | `Should exits` |
| REDIR | `cd .. > derp.txt` | `Does not change dir, which should happen` |
| SIGNAL | `cat - [ PRESS CTRL + C ]` | `Should exit cat prompt - EXIT 130` |
| SIGNAL | `cat - [ PRESS CTRL + \ ]` | `Should exit cat prompt - EXIT 131` |
| SIGNAL | `cat - [ PRESS CTRL + D ]` | `Should exit cat prompt - EXIT 0` |
| REDIR | `\> file` | `Creates file` |
| REDIR | `cat -e \> test1 < test2` | `minishell: test2: No such file or directory - EXIT 1 or EXIT 2` |
| REDIR | `cat < test` | `minishell: test: No such file or directory - EXIT 1 or 2` |
| REDIR | `echo 2 \> out1 >> out2` | `Both files are created, but out1 is empty, and out2 has "2" in it - EXIT 0` |
| REDIR | `echo 2 >> out1 \> out2` | `Both files are created, but out1 is empty, and out2 has "2" in it - EXIT 0` |
| REDIR | `echo test \> file test1` | `= echo test test1 > file` |
| REDIR | `Non_exist_cmd \> salut` | `create file but error msg to STDERR` |
| ENV | `unset all envs - env` | `Prints nothing` |
| ENV | `unset all envs - export lol` | `declare -x export="lol"` |
| PIPES | `Infinite file` |  |
| SUBST | `export var="  truc" - echo $var \| cat -e` | `[truc]` |
| SUBST | `export var="truc  " - echo $var \| cat -e` | `[truc]` |
| SUBST | `echo "$tests""Makefile"` | `[Makefile]` |
| SUBST | `echo "$tests"Makefile` | `[Makefile]` |
| SUBST | `echo "$tests" "Makefile"` | `[ Makefile]` |
| SUBST | `export $var ($var does not exists)` | `Shows "export"` |
| SUBST | `export test="  foo    bar  " ; echo $test` | `[foo bar]` |
| SUBST | `export test="  foo    bar  " ; echo ab$test` | `[ab foo bar]` |
| SUBST | `export test="  foo    bar  " ; echo "ab"$test` | `[ab foo bar]` |
| SUBST | `SUBST` | `[ foo   bar ]` |
| SUBST | `export test=" foo   bar " ; echo ""$test""` | `[ foo bar ]` |
| SUBST | `export test=" foo   bar " ; echo """$test"""` | `[ foo   bar ]` |
| SUBST | `export var= s\ -la ; l$var` | `equivalent à ls -al` |
| SUBST | `export var=at ; c$var Makefile` | `equivalent a cat Makefile` |
| SUBST | `export loop='bonjour$loop' ; echo $loop` | `bonjour$loop` |
| SUBST & REDIR | `export test="file1 file2" ; >$test` | `$test: ambiguous redir` |
| SUBST & REDIR | `export test="file1 file2" ; >"$test"` | `[file1 file2] created` |
| SUBST & REDIR | `export test="file1 file2" ; >$test >hey` | `$test: ambiguous redir, hey n'est pas créé` |
| SUBST & REDIR | `export test="file1 file2" ; >hey >$test` | `$test: ambiguous redir, hey est créé` |
| SYNTAX | `|` | `"synthax error" & exit 2` |
| SYNTAX | `echo bonjour ; \|` | `"synthax error" & exit 2` |
| SYNTAX | `echo bonjour > > out` | `"synthax error" & exit 2` |
| SYNTAX | `echo bonjour > $test` | `"redirection ambigue" & exit 1` |
| SYNTAX | `echo bonjour > $test w/ test="o1 o2"` | `"redirection ambigue" & exit 1` |
| SYNTAX | `echo bonjour >>> test` | `"synthax error" & exit 2` |
| SYNTAX | `echo bonjour \| \|` | `"synthax error" & exit 2` |
| SYNTAX | `echo bonjour \|;` | `"synthax error" & exit 2` |
| UNSET | `unset PATH ; echo $PATH` | `\n` |
| UNSET | `unset PATH ; ls` | `bash: ls: No such file or directory. Exit 127` |
| UNSET | `unset "" test` | `unset test et set $? à 1` |
| UNSET | `unset =` | `erreur et set $? à 1` |
| UNSET | `unset PWD` |  |
| UNSET | `unset var` | `var1 ne doit pas etre unset` |
| UNSET | `export $var=s\ -la ; l$var` |  |
| UNSET | `/bin/echo bonjour` | `affiche bonjour` |
| SPECIAL CASES | `cat wfeh \| cat csijdsji \| cat nfwir` |  |
