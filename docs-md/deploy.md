## Зависимости 
* Для скриптов: git, rsync
* Для демона: snappy, zlib, bzip2, lz4, zstandard
* boost, rocksdb и прочее линкуется статически 

Сама RocksDB скомпилирована статически, но библиотеки сжатия которые она использует, динамически.
Краткая инструкция по установке зависимостей для Ubuntu:
* Install snappy. This is usually as easy as:
  * sudo apt-get install libsnappy-dev.
* Install zlib. Try: sudo apt-get install zlib1g-dev.
* Install bzip2: sudo apt-get install libbz2-dev.
* Install lz4: sudo apt-get install liblz4-dev.
* Install zstandard: sudo apt-get install libzstd-dev.

[Более подробная иструкция](https://gitlab.mamba.ru/cpp/rocksdb/-/blob/master/INSTALL.md)

## Деплой 

* Убедитесь что существуют каталоги с правами wwwrun
  * /logs
  * /monamour
  * /usr/monamour/prefixdb
* Есть права для запуска под wwwrun

Далее скачиваем скрипт деплоя в /usr/monamour/prefixdb

```bash
cd /usr/monamour/prefixdb
sudo -u wwwrun wget http://github.lan/cpp/cmake-ci/raw/master/scripts/deploy.sh
sudo -u wwwrun chmod +x deploy.sh
```

**Важно!** Скрипты деплоя и запуска корректно работают только в папке `/usr/monamour/prefixdb` (не prefixdbd или еще как)

Далее запускаем `./deploy.sh` с указанием проекта, типа сборки и конфигурации. 
* Имя проекта без суффикса `d`, т.е. **prefixdb**, а не prefixdb*d*
* Доступные сборки (всегда актуальные, собираться автоматически):
  * release - основной тип сборки для деплоя в продакшн из master ветки
  * pre-release - как release, но с отладочной информацией
  * devel - тоже что и pre-release, но из ветки devel
  * wip - Debug сборка из текущей ветки разработки 
  * Дополнительные сборки (формируются пушем в соответствующий бранч)
    * hotfix - для временного срочного вывода в прод критических исправлений, которые еще не попали в мастер
    * probe - релизная версия для тестирования 
    * draft - debug версия для тестирования 
* Доступные конфигурации размещаються в отдельном [репозитарии конфигураций](https://gitlab.mamba.ru/cpp-conf/prefixdbd)
и, как правило, соответствует имени хоста, для которого предназначена, но не обязательно. Там же могут находиться 
вспомогательные скрипты

Например для `master5-deb` нам подойдет конфигурация `master5`, тогда:
```bash
./deploy.sh prefixdb release master5
```
В результате в текущую папку будут скачены бинарник, конфигурации и скрипты запуска. Если нужной конфигурации для конкретного 
хоста нет, то будут скачены конфигурации по умолчанию. 

Срипт `./deploy.sh` забирает исполняемые файлы со сборочного хоста `repobuild3:/monamour/prefixdb/`, а конфигурацию из git 
репозитария `gitlab.mamba.ru/cpp-conf/prefixdbd` (сначала он забирает все файлы из корня, а потом заменяет их файлами из 
поддиректории master5 или другой указанной третьим параметром, если существует). В корне `cpp-conf/prefixdbd` лежат универсальные 
файлы конфигураций и дополнительные скрипты, а в поддиректориях специфичные для конкретной виртуалки версии конфигураций.

* `prefixdb.conf` - конфигурация демона prefixdb в формате JSON (без поддержки репликации)
* `prefixdb.ini` - конфигурация самой rocksdb в формате INI для prefixdb.conf. Путь к этому файлу, соответственно, указан в `prefixdb.conf`
* `prefixdb.sh` - скрипт запуска демона с конфигурацией `prefixdb.conf`
* `master.conf`,`master.ini`,`master.sh` - соответственно для мастера
* `slave.conf`, `slave.ini`, `slave.sh` - соответственно для слейва
* `master-slave.conf`, `master-slave.ini`, `master-slave.sh` - подключен как слейв, но может работать мастером

  
Для полного обновления уже работающего демона (смотрим в топе какая конфигурация запущена): 
```bash
./prefixdb.sh stop
# или ./master.sh stop
# или ./slave.sh stop
# или ./master-slave.sh stop
# или killall prefixdbd и ждем когда завершатся все процессы 

# ожидаем остановку prefixdbd

./deploy.sh prefixdb release master5
./prefixdb.sh start
# или ./master.sh start
# или ./slave.sh start
# или ./master-slave.sh start
```
**Внимание!** При обновлении файлы также обновятся файлы конфигураций!
Перед обновлением будет сделана резервная копия, например в:
```bash
/usr/monamour/.backups/prefixdb-20210302_182136
```

Для обновления только бинарников:
```bash
./deploy.sh --bin prefixdb release
```
Для обновления только конфигов:
```bash
# Внимание! Здесь резервная копия конфигов не делается
./deploy.sh --conf master5
```

## Деплой слейвов

**Важно!** master должен быть правильно настроен для поддержки репликации, т.е. должен быть запущен с конфигурацией
`master.conf` или `master-slave.conf`. Если демон, которому вы планируете подключить слейв запущен с конфигурацией 
`prefixdb.conf`, то вероятно для него убрали поддержку репликации из-за проблем с производительностью. Его можно
перезапустить в режиме мастера, но необходимо убедиться что он справляется с нагрузкой.

**Важно!** Старые инстансы могут не соответствовать описанному здесь регламенту, а также никто не запрещает 
внесение изменений в конфигурацию так, что она перестанет ему соответствовать (например отключить поддержу репликации
в файле `master.conf`). Это нужно учитывать и действовать по обстоятельствам. 
См. [конфигурация](docs-md/conf.md)

Для равертывания нового slave делаем все как в предыдущем разделе:

```bash
./deploy.sh prefixdb release slave5
```

**Важно!** После обновления конфигурации открываем на редактирование `slave.conf` и вносим изменения в поле `addr` 
в секции `client-tcp` (обычно он в самом конце файла):

```bash
  "client-tcp": [
    {
      "name": "client-tcp1",
      "startup_priority":-500,
      "addr": "",  /* <- здесь нужно указать имя хоста (или ip) мастера */
      "port": "23002",
      "connect_count":5,
      "threads":1
    }
  ]
```
**Важно!** Пока еще есть бардак со старыми инстансами в регламенте открытых портов. На данный момент инстансы работающие на виртуалках с суффиксом 'n' в имени (например mastern5) соответствует регламенту и для слейва открывает порт 23002. Для более древних виртуалок (например master1) порт для слейва нужно смотреть в конфиге и указать его в `client-tcp` конфига слейва.

Далее нужно залить актуальные данные с мастера. Более подробную информацию смотри в [как работает репликация](replication.md)
