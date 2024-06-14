import net.http.Server

import src.routes.Routes

Server(port=5001,routes=Routes())
    .serve();

