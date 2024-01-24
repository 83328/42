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
|:x:| CD | `cd ~/Desktop` | `pwd: ~/Desktop` |
|:x:| CD | `unset HOME - cd ~` | `Error: HOME not set, EXIT 1` |
|:x:| CD | `export HOME=/Users/user42 - cd ~` | `pwd: ~` |
|:x:| `cd .. cool swag` | `pwd: ../` |
|:x:| `cd Eyooooo` | `bash: cd: Eyooooo: No such file or directory - EXIT 1` |
|:x:| CD | `cd -` | `pwd: Last PWD` |
|:x:| CD | `mkdir a - mkdir a/b - cd a/b - rm -r ../../a - cd ..` | `cd: error retrieving current directory: getcwd: cannot access parent directories: No such file or directory - EXIT 0` |
|:x:| ECHO | `echo` |  |
|:x:| ECHO | `echo $NonExistingVar` |  |
|:x:| ECHO | `echo $PATH` | `$PATH` |
|:x:| ECHO | `echo ~` | `$HOME` |
|:x:| ECHO | `echo -n -n -nnnn -nnnnm` | `-nnnnm` |
|:x:| ECHO | `echo -n -nnn hello -n` | `hello -n` |
|:x:| ENV | `env` | `All env and all user envs WITH content in it` |
|:x:| ENV | `env Weeiirrddd` | `env: weeirdd: No such file or directory - EXIT 127` |
|:x:| EXIT STATUS | `cd Weyooo - echo $?` | `bash: cd: Weyooo: No such file or directory - EXIT 1` |
|:x:| EXIT STATUS | `random_cmd - echo $?` | `EXIT 127` |
|:x:| EXIT STATUS | `./file_that_is_not_an_executable` | `bash: ./file_that_is_not_an_executable: Permission denied - EXIT 126` |
|:x:| EXIT STATUS | `cat bla` | `cat: bla: No such file or directory - EXIT 1` |
|:x:| EXIT STATUS | `hi` | `bash: hi: command not found - EXIT 127` |
|:x:| EXIT STATUS | `export ls="ls -l" - $ls` | `Does what "ls -l" should do - EXIT 0` |
|:x:| EXIT STATUS | `echo $ls` | `ls -l - EXIT 0` |
|:x:| EXPORT | `export var=a - export $var=test - echo $var $a` | `a test` |
|:x:| EXPORT | `export $var=test - unset var` |  |
|:x:| EXPORT | `export test1 - env` | `You will not see test1 in "env", but you will it in "export"` |
|:x:| EXPORT | `export test2= - env` | `You will see test2 in "env" and "export"` |
|:x:| EXPORT | `export var - export var=hoi - export` | `var="hoi"` |
|:x:| EXPORT | `export "" test=a` | `minishell: export: ": not a valid identifier` |
|:x:| EXPORT | `export test3=$HOME` | `test3="Users/user42"` |
|:x:| EXTRA | `echo ~` | `/home/user42` |
|:x:| INIT | `$SHLVL` | `Needs to increment once per new shell session` |
|:x:| PARSING | `""` | `Error - EXIT 126 or EXIT 127` |
|:x:| PARSING | `echo "\s" ; echo "\\s"` | `should have the exact same output` |
|:x:| PARSING | `echo "12\""` | `12"` |
|:x:| PARSING | `echo "bip \| bip ; coyotte > < "` | `[bip \| bip ; coyotte >< ]` |
|:x:| PARSING | `echo \>` | `>` |
|:x:| PARSING | `echo $USER$var$USER$USER$USERtest$USER` | `user42$USERuser42$USERtestuser42` |
|:x:| PARSING | `echo bonjour \; ls` | `bonjour ; ls` |
|:x:| PARSING | `$` | `command not found` |
|:x:| PARSING | `$LESS$VAR` | `-R: command not found` |
|:x:| PARSING | `..` | `cmd not found, exit 127` |
|:x:| PARSING | `echo '"abc"'` | `"abc"` |
|:x:| PARSING | `echo "" bonjour` | `[ bonjour]` |
|:x:| PARSING | `export "test=ici"=coucou ; echo $test` | `test="ici=coucou"` |
|:x:| PIPE | `cat \| cat \| cat \| ls` | `Press enter 3 times` |
|:x:| PIPE | `cat Makefile \| grep pr \| head -n 5 \| cd file_not_exit` | `file_not_exist: no such file... exit status: 1` |
|:x:| PIPE | `cat Makefile \| grep pr \| head -n 5 \| hello` | `hello: cmd not found... exit status: 127` |
|:x:| PIPE | `ls \| exit` |  |
|:x:| REDIR | `> test \| echo blabla` | `blabla` |
|:x:| REDIR | `exit > hoi.txt` | `Should exit & creates hoi.txt` |
|:x:| ENV | `env \| grep OLDPWD` | `Should exits` |
|:x:| REDIR | `cd .. > derp.txt` | `Does not change dir, which should happen` |
|:x:| SIGNAL | `cat - [ PRESS CTRL + C ]` | `Should exit cat prompt - EXIT 130` |
|:x:| SIGNAL | `cat - [ PRESS CTRL + \ ]` | `Should exit cat prompt - EXIT 131` |
|:x:| SIGNAL | `cat - [ PRESS CTRL + D ]` | `Should exit cat prompt - EXIT 0` |
|:x:| REDIR | `\> file` | `Creates file` |
|:x:| REDIR | `cat -e \> test1 < test2` | `minishell: test2: No such file or directory - EXIT 1 or EXIT 2` |
|:x:| REDIR | `cat < test` | `minishell: test: No such file or directory - EXIT 1 or 2` |
|:x:| REDIR | `echo 2 \> out1 >> out2` | `Both files are created, but out1 is empty, and out2 has "2" in it - EXIT 0` |
|:x:| REDIR | `echo 2 >> out1 \> out2` | `Both files are created, but out1 is empty, and out2 has "2" in it - EXIT 0` |
|:x:| REDIR | `echo test \> file test1` | `= echo test test1 > file` |
|:x:| REDIR | `Non_exist_cmd \> salut` | `create file but error msg to STDERR` |
|:x:| ENV | `unset all envs - env` | `Prints nothing` |
|:x:| ENV | `unset all envs - export lol` | `declare -x export="lol"` |
|:x:| PIPES | `Infinite file` |  |
|:x:| SUBST | `export var="  truc" - echo $var \| cat -e` | `[truc]` |
|:x:| SUBST | `export var="truc  " - echo $var \| cat -e` | `[truc]` |
|:x:| SUBST | `echo "$tests""Makefile"` | `[Makefile]` |
|:x:| SUBST | `echo "$tests"Makefile` | `[Makefile]` |
|:x:| SUBST | `echo "$tests" "Makefile"` | `[ Makefile]` |
|:x:| SUBST | `export $var ($var does not exists)` | `Shows "export"` |
|:x:| SUBST | `export test="  foo    bar  " ; echo $test` | `[foo bar]` |
|:x:| SUBST | `export test="  foo    bar  " ; echo ab$test` | `[ab foo bar]` |
|:x:| SUBST | `export test="  foo    bar  " ; echo "ab"$test` | `[ab foo bar]` |
|:x:| SUBST | `SUBST` | `[ foo   bar ]` |
|:x:| SUBST | `export test=" foo   bar " ; echo ""$test""` | `[ foo bar ]` |
|:x:| SUBST | `export test=" foo   bar " ; echo """$test"""` | `[ foo   bar ]` |
|:x:| SUBST | `export var= s\ -la ; l$var` | `equivalent à ls -al` |
|:x:| SUBST | `export var=at ; c$var Makefile` | `equivalent a cat Makefile` |
|:x:| SUBST | `export loop='bonjour$loop' ; echo $loop` | `bonjour$loop` |
|:x:| SUBST & REDIR | `export test="file1 file2" ; >$test` | `$test: ambiguous redir` |
|:x:| SUBST & REDIR | `export test="file1 file2" ; >"$test"` | `[file1 file2] created` |
|:x:| SUBST & REDIR | `export test="file1 file2" ; >$test >hey` | `$test: ambiguous redir, hey n'est pas créé` |
|:x:| SUBST & REDIR | `export test="file1 file2" ; >hey >$test` | `$test: ambiguous redir, hey est créé` |
|:x:| SYNTAX | `|` | `"synthax error" & exit 2` |
|:x:| SYNTAX | `echo bonjour ; \|` | `"synthax error" & exit 2` |
|:x:| SYNTAX | `echo bonjour > > out` | `"synthax error" & exit 2` |
|:x:| SYNTAX | `echo bonjour > $test` | `"redirection ambigue" & exit 1` |
|:x:| SYNTAX | `echo bonjour > $test w/ test="o1 o2"` | `"redirection ambigue" & exit 1` |
|:x:| SYNTAX | `echo bonjour >>> test` | `"synthax error" & exit 2` |
|:x:| SYNTAX | `echo bonjour \| \|` | `"synthax error" & exit 2` |
|:x:| SYNTAX | `echo bonjour \|;` | `"synthax error" & exit 2` |
|:x:| UNSET | `unset PATH ; echo $PATH` | `\n` |
|:x:| UNSET | `unset PATH ; ls` | `bash: ls: No such file or directory. Exit 127` |
|:x:| UNSET | `unset "" test` | `unset test et set $? à 1` |
|:x:| UNSET | `unset =` | `erreur et set $? à 1` |
|:x:| UNSET | `unset PWD` |  |
|:x:| UNSET | `unset var` | `var1 ne doit pas etre unset` |
|:x:| UNSET | `export $var=s\ -la ; l$var` |  |
|:x:| UNSET | `/bin/echo bonjour` | `affiche bonjour` |
|:x:| SPECIAL CASES | `cat wfeh \| cat csijdsji \| cat nfwir` |  |
