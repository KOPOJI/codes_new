#!/bin/bash
lupdate `find ./ \( -name '*.cpp' -o -name '*.h' -o -name '*.erb' \) -not \( -path './views/_src/*' -o -name '*moc*' \)` -locations absolute -ts ./en.ts -ts ./ru.ts
lrelease `find ./translations -name '*.ts'`
