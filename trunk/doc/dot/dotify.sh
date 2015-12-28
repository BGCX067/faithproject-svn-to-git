#!/bin/sh

cat header.dot \
    server.dot \
    db.dot \
    tools.dot \
    webservice.dot \
    edges.dot \
    footer.dot \
    | dot -Tpng -oall.png

