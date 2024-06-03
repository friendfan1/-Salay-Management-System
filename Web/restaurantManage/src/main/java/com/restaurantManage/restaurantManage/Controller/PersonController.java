package com.restaurantManage.restaurantManage.Controller;

import com.restaurantManage.restaurantManage.Response;
import com.restaurantManage.restaurantManage.dto.PersonDTO;
import com.restaurantManage.restaurantManage.service.PersonService;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RestController;

@RestController
public class PersonController {

    private final PersonService personService;

    public PersonController(PersonService personService){
        this.personService = personService;
    }

    @GetMapping("/Person/{Id}")
    public Response<PersonDTO> GetPersonById(@PathVariable String Id){

        return Response.newSuccess(personService.getPersonByID(Id));
    }

}
