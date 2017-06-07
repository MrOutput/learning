package server;

import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;
import org.springframework.web.bind.annotation.RequestMethod;

@RestController
public class UserController {
    @RequestMapping(path="/user", method=RequestMethod.GET)
    public String getUser(@RequestParam(value="name") String name) {
        return "hello, world! : " + name; 
    }
}
