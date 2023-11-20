Подредактировал setupUi в файле ui_mainwindow.h: добавил аргумент Qstring
Подредактировал название главного окна

Теперь меню админа появляется в зависимости от определенного ника "Admin"
Это избавило меня от надобности создавать отдельные формы, лайауты и прочее, лишь три кнопочки добавил

Отключение происходит здесь 

connect(&buBox, &QDialogButtonBox::accepted, [&]() {
        QString selectedUser = listWid.currentItem()->text();
        MainWindow *windowToClose = getListOfTheWindows(selectedUser.toStdString());
        if(windowToClose) {
            windowToClose->close(); // Закрыть окно, если оно найдено
        }
    });
    
Дописал функцию getListOfTheWindows

Добавил static std::vector<std::pair<MainWindow *, std::string>> listOfTheWindows; в mainwindowform
Чтобы хранило указатель на окно с привязкой к имени пользователя. Потом это имя используем для поиска указателя и через него закрываем(отключаем) окно

