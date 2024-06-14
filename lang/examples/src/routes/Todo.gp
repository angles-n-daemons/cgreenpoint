import Router, AppType from net.http
import GET, POST, DELETE from net.http.Methods
import net.http.Router

return class TodoRouter: Router {
    init {
         super(prefix='/todo', appType=AppType.XML)
    }

    // magic setup this? or explicit?
    @GET('/')
    fn listPerson(req) {
        
    }

    @POST('/')
    fn createPerson(req) {
        name = req.body.name
        name = req.body.name
    }
}
