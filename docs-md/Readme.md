PrefixDB - Префиксное key-value хранилище на базе RocksDB с JSON-RPC интерфейсом
=========

PrefixDB управляет несколькими key-value хранилищами которые определяются префиксами.
По сути префикс - это имя каталога файловой системы, где располагаются файлы 
хранилища для этого префикса. Префикс указывается в каждом запросе. Хранилища префикса 
создаются автоматически при любом запросе на запись. Настройки для всех префиксов едины и
задаются в конфигурации. При необходимости индивидуальных настроек для префикса его можно 
вынести в другой PrefixDB с нужными настройками. Т.к. каждый префикс располагается в отдельном 
подкаталоге, то это позволяет легко его переместить на другой сервер при необходимости.

RocksDB - это активно развивающийся проект facebook, изначально форк проекта LevelDB от google,
с существенными дополнениями и представляет собой С++ библиотеку. PrefixDB это демон, который 
предоставляет JSON-RPC интерфейс по TCP/UDP протоколам. Кроме того предоставляет инструменты для 
управления потоком запросов, настройки очередей и потоков для адаптации к различным профилям 
нагрузок, а также может обеспечивать репликацию и создание резервных копий.

* [Введение](docs-md/Readme.md)
* [JSON-API](docs-md/api.md)
* [Сборка](docs-md/build.md)
* [Деплой](docs-md/deploy.md)
* [Запуск/Перезапуск](docs-md/restart.md)
* [Конфигурация](docs-md/conf.md)
* [Репликация](docs-md/replication.md)
* [Переезд без даунтайма](docs-md/migration.md)
* [Компэкшн](docs-md/compact.md)
* [Бэкапы](docs-md/backup.md)
* [Востановление](docs-md/restore.md)