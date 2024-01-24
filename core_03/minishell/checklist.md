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

|:white_check_mark:| Command | User input | Expected result |
|-------|---------|------------|-----------------|
|:white_check_mark:| CD | `cd ~/Desktop` | `pwd: ~/Desktop` |
|:white_check_mark:| CD | `unset HOME - cd ~` | `Error: HOME not set, EXIT 1` |
|:white_check_mark:| CD | `export HOME=/Users/user42 - cd ~` | `pwd: ~` |
|:white_check_mark:| `cd .. cool swag` | `pwd: ../` |
|:white_check_mark:| `cd Eyooooo` | `bash: cd: Eyooooo: No such file or directory - EXIT 1` |
|:white_check_mark:| CD | `cd -` | `pwd: Last PWD` |
|:white_check_mark:| CD | `mkdir a - mkdir a/b - cd a/b - rm -r ../../a - cd ..` | `cd: error retrieving current directory: getcwd: cannot access parent directories: No such file or directory - EXIT 0` |
|:white_check_mark:| ECHO | `echo` |  |
|:white_check_mark:| ECHO | `echo $NonExistingVar` |  |
|:white_check_mark:| ECHO | `echo $PATH` | `$PATH` |
|:white_check_mark:| ECHO | `echo ~` | `$HOME` |
|:white_check_mark:| ECHO | `echo -n -n -nnnn -nnnnm` | `-nnnnm` |
|:white_check_mark:| ECHO | `echo -n -nnn hello -n` | `hello -n` |
|:white_check_mark:| ENV | `env` | `All env and all user envs WITH content in it` |
|:white_check_mark:| ENV | `env Weeiirrddd` | `env: weeirdd: No such file or directory - EXIT 127` |
|:white_check_mark:| EXIT STATUS | `cd Weyooo - echo $?` | `bash: cd: Weyooo: No such file or directory - EXIT 1` |
|:white_check_mark:| EXIT STATUS | `random_cmd - echo $?` | `EXIT 127` |
|:white_check_mark:| EXIT STATUS | `./file_that_is_not_an_executable` | `bash: ./file_that_is_not_an_executable: Permission denied - EXIT 126` |
|:white_check_mark:| EXIT STATUS | `cat bla` | `cat: bla: No such file or directory - EXIT 1` |
|:white_check_mark:| EXIT STATUS | `hi` | `bash: hi: command not found - EXIT 127` |
|:white_check_mark:| EXIT STATUS | `export ls="ls -l" - $ls` | `Does what "ls -l" should do - EXIT 0` |
|:white_check_mark:| EXIT STATUS | `echo $ls` | `ls -l - EXIT 0` |
|:white_check_mark:| EXPORT | `export var=a - export $var=test - echo $var $a` | `a test` |
|:white_check_mark:| EXPORT | `export $var=test - unset var` |  |
|:white_check_mark:| EXPORT | `export test1 - env` | `You will not see test1 in "env", but you will it in "export"` |
|:white_check_mark:| EXPORT | `export test2= - env` | `You will see test2 in "env" and "export"` |
|:white_check_mark:| EXPORT | `export var - export var=hoi - export` | `var="hoi"` |
|:white_check_mark:| EXPORT | `export "" test=a` | `minishell: export: ": not a valid identifier` |
|:white_check_mark:| EXPORT | `export test3=$HOME` | `test3="Users/user42"` |
|:white_check_mark:| EXTRA | `echo ~` | `/home/user42` |
|:white_check_mark:| INIT | `$SHLVL` | `Needs to increment once per new shell session` |
|:white_check_mark:| PARSING | `""` | `Error - EXIT 126 or EXIT 127` |
|:white_check_mark:| PARSING | `echo "\s" ; echo "\\s"` | `should have the exact same output` |
|:white_check_mark:| PARSING | `echo "12\""` | `12"` |
|:white_check_mark:| PARSING | `echo "bip \| bip ; coyotte > < "` | `[bip \| bip ; coyotte >< ]` |
|:white_check_mark:| PARSING | `echo \>` | `>` |
|:white_check_mark:| PARSING | `echo $USER$var$USER$USER$USERtest$USER` | `user42$USERuser42$USERtestuser42` |
|:white_check_mark:| PARSING | `echo bonjour \; ls` | `bonjour ; ls` |
|:white_check_mark:| PARSING | `$` | `command not found` |
|:white_check_mark:| PARSING | `$LESS$VAR` | `-R: command not found` |
|:white_check_mark:| PARSING | `..` | `cmd not found, exit 127` |
|:white_check_mark:| PARSING | `echo '"abc"'` | `"abc"` |
|:white_check_mark:| PARSING | `echo "" bonjour` | `[ bonjour]` |
|:white_check_mark:| PARSING | `export "test=ici"=coucou ; echo $test` | `test="ici=coucou"` |
|:white_check_mark:| PIPE | `cat \| cat \| cat \| ls` | `Press enter 3 times` |
|:white_check_mark:| PIPE | `cat Makefile \| grep pr \| head -n 5 \| cd file_not_exit` | `file_not_exist: no such file... exit status: 1` |
|:white_check_mark:| PIPE | `cat Makefile \| grep pr \| head -n 5 \| hello` | `hello: cmd not found... exit status: 127` |
|:white_check_mark:| PIPE | `ls \| exit` |  |
|:white_check_mark:| REDIR | `> test \| echo blabla` | `blabla` |
|:white_check_mark:| REDIR | `exit > hoi.txt` | `Should exit & creates hoi.txt` |
|:white_check_mark:| ENV | `env \| grep OLDPWD` | `Should exits` |
|:white_check_mark:| REDIR | `cd .. > derp.txt` | `Does not change dir, which should happen` |
|:white_check_mark:| SIGNAL | `cat - [ PRESS CTRL + C ]` | `Should exit cat prompt - EXIT 130` |
|:white_check_mark:| SIGNAL | `cat - [ PRESS CTRL + \ ]` | `Should exit cat prompt - EXIT 131` |
|:white_check_mark:| SIGNAL | `cat - [ PRESS CTRL + D ]` | `Should exit cat prompt - EXIT 0` |
|:white_check_mark:| REDIR | `\> file` | `Creates file` |
|:white_check_mark:| REDIR | `cat -e \> test1 < test2` | `minishell: test2: No such file or directory - EXIT 1 or EXIT 2` |
|:white_check_mark:| REDIR | `cat < test` | `minishell: test: No such file or directory - EXIT 1 or 2` |
|:white_check_mark:| REDIR | `echo 2 \> out1 >> out2` | `Both files are created, but out1 is empty, and out2 has "2" in it - EXIT 0` |
|:white_check_mark:| REDIR | `echo 2 >> out1 \> out2` | `Both files are created, but out1 is empty, and out2 has "2" in it - EXIT 0` |
|:white_check_mark:| REDIR | `echo test \> file test1` | `= echo test test1 > file` |
|:white_check_mark:| REDIR | `Non_exist_cmd \> salut` | `create file but error msg to STDERR` |
|:white_check_mark:| ENV | `unset all envs - env` | `Prints nothing` |
|:white_check_mark:| ENV | `unset all envs - export lol` | `declare -x export="lol"` |
|:white_check_mark:| PIPES | `Infinite file` |  |
|:white_check_mark:| SUBST | `export var="  truc" - echo $var \| cat -e` | `[truc]` |
|:white_check_mark:| SUBST | `export var="truc  " - echo $var \| cat -e` | `[truc]` |
|:white_check_mark:| SUBST | `echo "$tests""Makefile"` | `[Makefile]` |
|:white_check_mark:| SUBST | `echo "$tests"Makefile` | `[Makefile]` |
|:white_check_mark:| SUBST | `echo "$tests" "Makefile"` | `[ Makefile]` |
|:white_check_mark:| SUBST | `export $var ($var does not exists)` | `Shows "export"` |
|:white_check_mark:| SUBST | `export test="  foo    bar  " ; echo $test` | `[foo bar]` |
|:white_check_mark:| SUBST | `export test="  foo    bar  " ; echo ab$test` | `[ab foo bar]` |
|:white_check_mark:| SUBST | `export test="  foo    bar  " ; echo "ab"$test` | `[ab foo bar]` |
|:white_check_mark:| SUBST | `SUBST` | `[ foo   bar ]` |
|:white_check_mark:| SUBST | `export test=" foo   bar " ; echo ""$test""` | `[ foo bar ]` |
|:white_check_mark:| SUBST | `export test=" foo   bar " ; echo """$test"""` | `[ foo   bar ]` |
|:white_check_mark:| SUBST | `export var= s\ -la ; l$var` | `equivalent à ls -al` |
|:white_check_mark:| SUBST | `export var=at ; c$var Makefile` | `equivalent a cat Makefile` |
|:white_check_mark:| SUBST | `export loop='bonjour$loop' ; echo $loop` | `bonjour$loop` |
|:white_check_mark:| SUBST & REDIR | `export test="file1 file2" ; >$test` | `$test: ambiguous redir` |
|:white_check_mark:| SUBST & REDIR | `export test="file1 file2" ; >"$test"` | `[file1 file2] created` |
|:white_check_mark:| SUBST & REDIR | `export test="file1 file2" ; >$test >hey` | `$test: ambiguous redir, hey n'est pas créé` |
|:white_check_mark:| SUBST & REDIR | `export test="file1 file2" ; >hey >$test` | `$test: ambiguous redir, hey est créé` |
|:white_check_mark:| SYNTAX | `|` | `"synthax error" & exit 2` |
|:white_check_mark:| SYNTAX | `echo bonjour ; \|` | `"synthax error" & exit 2` |
|:white_check_mark:| SYNTAX | `echo bonjour > > out` | `"synthax error" & exit 2` |
|:white_check_mark:| SYNTAX | `echo bonjour > $test` | `"redirection ambigue" & exit 1` |
|:white_check_mark:| SYNTAX | `echo bonjour > $test w/ test="o1 o2"` | `"redirection ambigue" & exit 1` |
|:white_check_mark:| SYNTAX | `echo bonjour >>> test` | `"synthax error" & exit 2` |
|:white_check_mark:| SYNTAX | `echo bonjour \| \|` | `"synthax error" & exit 2` |
|:white_check_mark:| SYNTAX | `echo bonjour \|;` | `"synthax error" & exit 2` |
|:white_check_mark:| UNSET | `unset PATH ; echo $PATH` | `\n` |
|:white_check_mark:| UNSET | `unset PATH ; ls` | `bash: ls: No such file or directory. Exit 127` |
|:white_check_mark:| UNSET | `unset "" test` | `unset test et set $? à 1` |
|:white_check_mark:| UNSET | `unset =` | `erreur et set $? à 1` |
|:white_check_mark:| UNSET | `unset PWD` |  |
|:white_check_mark:| UNSET | `unset var` | `var1 ne doit pas etre unset` |
|:white_check_mark:| UNSET | `export $var=s\ -la ; l$var` |  |
|:white_check_mark:| UNSET | `/bin/echo bonjour` | `affiche bonjour` |
|:white_check_mark:| SPECIAL CASES | `cat wfeh \| cat csijdsji \| cat nfwir` |  |
