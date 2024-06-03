package com.restaurantManage.restaurantManage.converter;

import com.restaurantManage.restaurantManage.DAO.Person;
import com.restaurantManage.restaurantManage.dto.PersonDTO;

public class PersonConverter {
    public static PersonDTO converter(Person person){
        PersonDTO personDTO = new PersonDTO();
        personDTO.setId(person.getId());
        return personDTO;
    }
}
