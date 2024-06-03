package com.restaurantManage.restaurantManage.service;

import com.restaurantManage.restaurantManage.DAO.Person;
import com.restaurantManage.restaurantManage.DAO.PersonRepository;
import com.restaurantManage.restaurantManage.converter.PersonConverter;
import com.restaurantManage.restaurantManage.dto.PersonDTO;
import org.springframework.stereotype.Service;

@Service
public class PersonServiceImpl implements PersonService{

    private final PersonRepository personRepository;

    public PersonServiceImpl(PersonRepository personRepository){
        this.personRepository = personRepository;
    }

    @Override
    public PersonDTO getPersonByID(String Id) {
        Person person = personRepository.findById(Id).orElseThrow(RuntimeException::new);
        return PersonConverter.converter(person);
    }
}
