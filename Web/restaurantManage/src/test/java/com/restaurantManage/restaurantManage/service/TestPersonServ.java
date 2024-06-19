package com.restaurantManage.restaurantManage.service;

import com.restaurantManage.restaurantManage.DAO.Person;
import com.restaurantManage.restaurantManage.DAO.PersonRepository;
import com.restaurantManage.restaurantManage.converter.PersonConverter;
import com.restaurantManage.restaurantManage.dto.PersonDTO;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.boot.test.mock.mockito.MockBean;

import java.util.Optional;

import static com.restaurantManage.restaurantManage.converter.PersonConverter.converter;
import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.mockito.ArgumentMatchers.anyString;
import static org.mockito.Mockito.when;

@SpringBootTest
public class TestPersonServ {

    @Autowired
    private PersonServiceImpl personService;

    @MockBean
    private PersonRepository personRepository;

    @MockBean
    private PersonConverter personConverter;

    @Test
    public void testGetPersonByID() {
        Person person = new Person();
        person.setId("Person1");

        when(personRepository.findById(anyString())).thenReturn(Optional.of(person));

        PersonDTO personDTO2 = personService.getPersonByID("ID1");

        assertEquals("Person1",personDTO2.getId());

    }
}
