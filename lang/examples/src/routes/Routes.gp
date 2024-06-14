import net.http.RouterGroup

import src.routes.Todo

return RouterGroup('/api/', routers=[
    Todo(),
]);
