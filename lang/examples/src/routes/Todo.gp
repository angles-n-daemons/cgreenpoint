import Router, AppType from net.http
import GET, POST, DELETE from net.http.Methods
import net.http.Router

return class(controller: Controller): Router {
    init {
         super(prefix='/todo', appType=AppType.XML)
    }

    // magic setup this? or explicit?
    @GET('/')
    fn listPerson(req) {
        
    }

    @POST('/')
    fn createPerson(req) {
        return my.controller.get(req.body.id)
    }
}
