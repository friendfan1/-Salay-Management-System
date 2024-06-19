package com.restaurantManage.restaurantManage.service;

import com.restaurantManage.restaurantManage.DAO.Dish;
import com.restaurantManage.restaurantManage.DAO.theTable;
import com.restaurantManage.restaurantManage.DAO.theTableRepository;
import org.junit.jupiter.api.Test;
import org.mockito.internal.matchers.Null;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.boot.test.mock.mockito.MockBean;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Optional;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertThrows;
import static org.mockito.ArgumentMatchers.any;
import static org.mockito.ArgumentMatchers.anyString;
import static org.mockito.Mockito.*;

@SpringBootTest
public class TestTableServ {
    @Autowired
    private theTableServiceImpl tableService;

    @MockBean
    private theTableRepository tableRepository;

    @Test
    public void testGetAllTable(){
        theTable table1 = new theTable();
        table1.setTableId("ID1");
        theTable table2 = new theTable();
        table2.setTableId("ID2");
        when(tableRepository.findAll()).thenReturn(Arrays.asList(table1,table2));

        List<theTable> tables = tableService.getAllTable();

        assertEquals(2,tables.size());
        assertEquals("ID1",tables.get(0).getTableId());
        assertEquals("ID2",tables.get(1).getTableId());
    }

    @Test
    public void testGetTableById(){
        theTable table1 = new theTable();
        table1.setTableId("ID1");
        when(tableRepository.findById(anyString())).thenReturn(Optional.of(table1));

        theTable table = tableService.getTableById("ID");


        assertEquals("ID1",table.getTableId());
    }

    @Test
    public void testUpdateTable(){
        theTable table = new theTable();
        table.setTableId("ID");
        /*doThrow(new RuntimeException())
                .when(tableRepository).save(any(theTable.class));*/

        when(tableRepository.save(any(theTable.class))).thenReturn(table);

        //assertThrows(RuntimeException.class, () -> tableService.updateTable(table));
        theTable result = tableService.updateTable(table);

        //verify(tableRepository).save(table);
        assertEquals("ID",result.getTableId());
    }

    @Test
    void testSelectTable() {
        doNothing()
                .when(tableRepository).guestToTable(anyInt(),anyString());

        theTable table = new theTable();
        table.setTableId("table1");
        when(tableRepository.findById(anyString())).thenReturn(Optional.of(table));
        assertThrows(IllegalArgumentException.class, ()->tableService.selectTable(-1,"table1"));

        tableService.selectTable(1,"table1");
        verify(tableRepository).guestToTable(1,"table1");

        when(tableRepository.findById(anyString())).thenReturn(Optional.empty());
        assertThrows(IllegalArgumentException.class, ()->tableService.selectTable(1,"table1"));

    }
}
